/* Tao - A software package for sound synthesis with physical models
 * Copyright (C) 1993-1999 Mark Pearson
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "TaoHammer.h"
#include "Tao.h"
#include "TaoInstrument.h"
#include "TaoAccessPoint.h"
#include "TaoCell.h"

extern Tao tao;

TaoHammer::TaoHammer()
    : TaoDevice("")
    {
    deviceType=TaoDevice::HAMMER;
    mode=nocontact;
    mass=10.0;
    height=20.0;
    gravity=1.0;
    damping=1.0;
    
    position=height;
    velocity=0.0;
    initVelocity=0.0;
    force=0.0;
    numImpacts=0;
    
    addToSynthesisEngine();
    }

TaoHammer::TaoHammer(const char *hammerName)
    : TaoDevice(hammerName)
    {
    deviceType=TaoDevice::HAMMER;
    mode=nocontact;
    mass=10.0;
    height=20.0;
    gravity=1.0;
    damping=1.0;
    hardness=1.0;

    position=height;
    velocity=0.0;
    initVelocity=0.0;
    force=0.0;
    numImpacts=0;
    maxImpacts=9999999;
    
    addToSynthesisEngine();
    }

void TaoHammer::reset()
    {
    position = height;
    velocity = initVelocity;
    force = 0.0;
    numImpacts=0;
    }

void TaoHammer::drop()
    {
    reset();
    activate();
    }

void TaoHammer::operator()(TaoAccessPoint &a)
    {
    apply(a);
    }
    
void TaoHammer::operator()(TaoInstrument &instr, float x)
    {
    apply(instr(x));
    }
    
void TaoHammer::operator()(TaoInstrument &instr, float x, float y)
    {
    apply(instr(x, y));
    }

    
void TaoHammer::update()
    {
    if (!active) return;
    if (!targetInstrument) return;
    
    force = -mass*gravity;

    if (mode==nocontact && position < interfacePoint.getPosition())
	{
	mode=contact;
	}

    if (mode==contact && position > interfacePoint.getPosition())
	{
	mode=nocontact;
	numImpacts++;
	if (numImpacts>=maxImpacts) 
	    {
	    deactivate();
	    }
	}

    if (mode==contact)
	{	
	collisionForce=(this->position - interfacePoint.getPosition())*hardness;
	interfacePoint.applyForce(collisionForce);
	this->force -= collisionForce;
        }

    velocity += force/mass;
    velocity *= damping;
    position += velocity;
    }

TaoHammer &TaoHammer::setHeight(float h)	{height=h; return *this;}
TaoHammer &TaoHammer::setMass(float m)		{mass=m; return *this;}
TaoHammer &TaoHammer::setPosition(float p)	{position=p; return *this;}
TaoHammer &TaoHammer::setInitVelocity(float v)	{initVelocity=v; return *this;}
TaoHammer &TaoHammer::setGravity(float g)	{gravity=g; return *this;}
TaoHammer &TaoHammer::setDamping(float d)	{damping=d; return *this;}
TaoHammer &TaoHammer::setHardness(float h)	{hardness=h; return *this;}
TaoHammer &TaoHammer::setMaxImpacts(int m)	{maxImpacts=m; return *this;}

float TaoHammer::getHeight()			{return height;}
float TaoHammer::getMass()			{return mass;}
float TaoHammer::getPosition()			{return position;}
float TaoHammer::getVelocity()			{return velocity;}
float TaoHammer::getInitVelocity()		{return initVelocity;}
float TaoHammer::getGravity()			{return gravity;}
float TaoHammer::getDamping()			{return damping;}
float TaoHammer::getHardness()			{return hardness;}
int TaoHammer::numberOfImpacts()		{return numImpacts;}
int TaoHammer::getMaxImpacts()			{return maxImpacts;}

void TaoHammer::display()
    {
    if (!tao.graphicsEngine.active || !active || !targetInstrument) return;
    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0) return;

    TaoInstrument &instr=interfacePoint.getInstrument();
    GLfloat x;
    GLfloat y;
    GLfloat z;

    tao.graphicsEngine.displayAccessPoint(interfacePoint);
    tao.graphicsEngine.displayPointInInstrumentSpace(
	*targetInstrument, interfacePoint.x, interfacePoint.y, this->position);

    if (tao.graphicsEngine.displayDeviceNames)
        {
	x=(GLfloat)(instr.getWorldX() + interfacePoint.cellx);
	z=(GLfloat)(this->position*instr.getMagnification()*
	    tao.graphicsEngine.globalMagnification + 2.0);
	y=(GLfloat)(instr.getWorldY() + interfacePoint.celly);

        tao.graphicsEngine.displayCharString(x,y,z,this->name,1.0,1.0,1.0);
	}
    }
