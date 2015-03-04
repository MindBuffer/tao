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

#include "TaoConnector.h"
#include "Tao.h"
#include "TaoInstrument.h"
#include "TaoAccessPoint.h"
#include "TaoCell.h"

extern Tao tao;

TaoConnector::TaoConnector(void) :
    TaoDevice()
    {
    deviceType=TaoDevice::CONNECTOR;
    anchorPoint1=0.0;
    anchorPoint2=0.0;
    strength=1.0;

    addToSynthesisEngine();
    }

TaoConnector::~TaoConnector() {}

TaoConnector::TaoConnector(const char *connectorName) :
    TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    anchorPoint1=0.0;
    anchorPoint2=0.0;
    strength=1.0;

    addToSynthesisEngine();
    }

// Constructors for case where both ends are connected to access points on
// instruments.

TaoConnector::TaoConnector(const char *connectorName,
    TaoAccessPoint &ap1, TaoAccessPoint &ap2 ) : TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    accessPoint1=ap1;
    accessPoint2=ap2;
    strength=1.0;
    
    addToSynthesisEngine();
    }

TaoConnector::TaoConnector(const char *connectorName, TaoAccessPoint &ap1,
    TaoAccessPoint &ap2, float connectionStrength ) : TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    accessPoint1=ap1;
    accessPoint2=ap2;
    strength=connectionStrength;
    
    addToSynthesisEngine();
    }


// Constructors for case where first end is connected to an access point on an
// instrument but the opposite end is connected to an anchor point, i.e. just a
// numerical value representing a position along the axis of vibration. This
// anchor point might be a constant or might be some time varying signal derived
// elsewhere in the script.

TaoConnector::TaoConnector(const char *connectorName, TaoAccessPoint &ap, 
    float anchor) : TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    accessPoint1=ap;
    anchorPoint2=anchor;
    strength=1.0;
    
    addToSynthesisEngine();
    }

TaoConnector::TaoConnector(const char *connectorName, TaoAccessPoint &ap, 
    float anchor, float connectionStrength) : TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    accessPoint1=ap;
    anchorPoint2=anchor;
    strength=connectionStrength;
    
    addToSynthesisEngine();
    }


// Constructors for case where second end is connected to an access point on an
// instrument but the first end is connected to an anchor point, i.e. just a
// numerical value representing a position along the axis of vibration. This
// anchor point might be a constant or might be some time varying signal derived
// elsewhere in the script.

TaoConnector::TaoConnector(const char *connectorName, float anchor, 
    TaoAccessPoint &ap) : TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    anchorPoint1=anchor;
    accessPoint2=ap;
    strength=1.0;
    
    addToSynthesisEngine();
    }

TaoConnector::TaoConnector(const char *connectorName, float anchor, 
    TaoAccessPoint &ap, float connectionStrength) : TaoDevice(connectorName)
    {
    deviceType=TaoDevice::CONNECTOR;
    anchorPoint1=anchor;
    accessPoint2=ap;
    strength=connectionStrength;
    
    addToSynthesisEngine();
    }


// The TaoConnector::operator() functions are used to adjust the access/anchor
// points of a connector during a performance. The arguments represent the newly
// calculate access points or anchor values. The first two functions represent
// the case where both ends of the connector are connected to access points on
// instruments.

void TaoConnector::operator()(TaoAccessPoint &a1, TaoAccessPoint &a2)
    {
    accessPoint1=a1;
    accessPoint2=a2;
    strength=1.0;
    }

void TaoConnector::operator()(TaoAccessPoint &a1, TaoAccessPoint &a2,
			    float connectionStrength)
    {
    accessPoint1=a1;
    accessPoint2=a2;
    strength=connectionStrength;
    }
 
    
// The next two functions represent the case where the first end of the connector
// is connected to an access point but the second end is connected to an anchor
// point (a numerical value rather than a position on an instrument).

void TaoConnector::operator()(TaoAccessPoint &ap, float anchor)
    {
    accessPoint1=ap;
    accessPoint2.clear();
    anchorPoint2=anchor;
    strength=1.0;
    }

void TaoConnector::operator()(TaoAccessPoint &ap, float anchor, 
    float connectionStrength)
    {
    accessPoint1=ap;
    accessPoint2.clear();
    anchorPoint2=anchor;
    strength=connectionStrength;
    }


// The next two functions represent the case where the first end of the connector
// is connected to an anchor point but the second end is connected to an access
// point.

void TaoConnector::operator()(float anchor, TaoAccessPoint &ap)
    {
    accessPoint1.clear();
    anchorPoint1=anchor;
    accessPoint2=ap;
    strength=1.0;
    }

void TaoConnector::operator()(float anchor, TaoAccessPoint &ap,
    float connectionStrength)
    {
    accessPoint1.clear();
    anchorPoint1=anchor;
    accessPoint2=ap;
    strength=connectionStrength;
    }
    
void TaoConnector::update()
    {
    if (accessPoint1.instrument && accessPoint2.instrument)
	this->updateAccessToAccess();
    else if (accessPoint1.instrument && !accessPoint2.instrument)
	this->updateAccessToAnchor();
    else if (!accessPoint1.instrument && accessPoint2.instrument)
	this->updateAnchorToAccess();
    }

void TaoConnector::updateAccessToAccess()
    {
    static float eaa, eab, eac, ead;
    static float eba, ebb, ebc, ebd;
    static float eca, ecb, ecc, ecd;
    static float eda, edb, edc, edd;

    static float faa, fab, fac, fad;
    static float fba, fbb, fbc, fbd;
    static float fca, fcb, fcc, fcd;
    static float fda, fdb, fdc, fdd;

    eaa=accessPoint1.X * accessPoint1.Y * accessPoint2.X * accessPoint2.Y;
    eab=accessPoint1.X * accessPoint1.Y * accessPoint2.X_* accessPoint2.Y;
    eac=accessPoint1.X * accessPoint1.Y * accessPoint2.X * accessPoint2.Y_;
    ead=accessPoint1.X * accessPoint1.Y * accessPoint2.X_* accessPoint2.Y_;

    eba=accessPoint1.X_* accessPoint1.Y * accessPoint2.X * accessPoint2.Y;
    ebb=accessPoint1.X_* accessPoint1.Y * accessPoint2.X_* accessPoint2.Y;
    ebc=accessPoint1.X_* accessPoint1.Y * accessPoint2.X * accessPoint2.Y_;
    ebd=accessPoint1.X_* accessPoint1.Y * accessPoint2.Y_* accessPoint2.X_;
    
    eca=accessPoint1.X * accessPoint1.Y_* accessPoint2.X * accessPoint2.Y;
    ecb=accessPoint1.X * accessPoint1.Y_* accessPoint2.X_* accessPoint2.Y;
    ecc=accessPoint1.X * accessPoint1.Y_* accessPoint2.X * accessPoint2.Y_;
    ecd=accessPoint1.X * accessPoint1.Y_* accessPoint2.X_* accessPoint2.Y_;
        
    eda=accessPoint1.X_* accessPoint1.Y_* accessPoint2.X * accessPoint2.Y;
    edb=accessPoint1.X_* accessPoint1.Y_* accessPoint2.X_* accessPoint2.Y;
    edc=accessPoint1.X_* accessPoint1.Y_* accessPoint2.X * accessPoint2.Y_;
    edd=accessPoint1.X_* accessPoint1.Y_* accessPoint2.X_* accessPoint2.Y_;
 
    
    if (accessPoint1.cella)
	{
	if (accessPoint2.cella)
	    faa=(accessPoint2.cella->position - accessPoint1.cella->position) * eaa;
	if (accessPoint2.cellb)
	    fab=(accessPoint2.cellb->position - accessPoint1.cella->position) * eab;
	if (accessPoint2.cellc)
	    fac=(accessPoint2.cellc->position - accessPoint1.cella->position) * eac;
	if (accessPoint2.celld)
	    fad=(accessPoint2.celld->position - accessPoint1.cella->position) * ead;
	}

    if (accessPoint1.cellb)
	{
	if (accessPoint2.cella)
	    fba=(accessPoint2.cella->position - accessPoint1.cellb->position) * eba;
	if (accessPoint2.cellb)
	    fbb=(accessPoint2.cellb->position - accessPoint1.cellb->position) * ebb;
	if (accessPoint2.cellc)
	    fbc=(accessPoint2.cellc->position - accessPoint1.cellb->position) * ebc;
	if (accessPoint2.celld)
	    fbd=(accessPoint2.celld->position - accessPoint1.cellb->position) * ebd;
	}
    
    if (accessPoint1.cellc)
	{
	if (accessPoint2.cella)
	    fca=(accessPoint2.cella->position - accessPoint1.cellc->position) * eca;
	if (accessPoint2.cellb)
	    fcb=(accessPoint2.cellb->position - accessPoint1.cellc->position) * ecb;
	if (accessPoint2.cellc)
	    fcc=(accessPoint2.cellc->position - accessPoint1.cellc->position) * ecc;
	if (accessPoint2.celld)
	    fcd=(accessPoint2.celld->position - accessPoint1.cellc->position) * ecd;
	}

    if (accessPoint1.celld)
	{
	if (accessPoint2.cella)
	    fda=(accessPoint2.cella->position - accessPoint1.celld->position) * eda;
	if (accessPoint2.cellb)
	    fdb=(accessPoint2.cellb->position - accessPoint1.celld->position) * edb;
	if (accessPoint2.cellc)
	    fdc=(accessPoint2.cellc->position - accessPoint1.celld->position) * edc;
	if (accessPoint2.celld)
	    fdd=(accessPoint2.celld->position - accessPoint1.celld->position) * edd;
	}
	
    if (accessPoint1.cella)
	accessPoint1.cella->force+=( faa + fab + fac + fad)*strength;
    if (accessPoint1.cellb)
	accessPoint1.cellb->force+=( fba + fbb + fbc + fbd)*strength;
    if (accessPoint1.cellc)
	accessPoint1.cellc->force+=( fca + fcb + fcc + fcd)*strength;
    if (accessPoint1.celld)
	accessPoint1.celld->force+=( fda + fdb + fdc + fdd)*strength;

    if (accessPoint2.cella)
	accessPoint2.cella->force+=(-faa - fba - fca - fda)*strength;
    if (accessPoint2.cellb)
	accessPoint2.cellb->force+=(-fab - fbb - fcb - fdb)*strength;
    if (accessPoint2.cellc)
	accessPoint2.cellc->force+=(-fac - fbc - fcc - fdc)*strength;
    if (accessPoint2.celld)
	accessPoint2.celld->force+=(-fad - fbd - fcd - fdd)*strength;
    }


void TaoConnector::updateAccessToAnchor()
    {
    static float elasticities[2][2];

    elasticities[0][0]=accessPoint1.X * accessPoint1.Y;
    elasticities[0][1]=accessPoint1.X_* accessPoint1.Y;
    elasticities[1][0]=accessPoint1.X * accessPoint1.Y_;
    elasticities[1][1]=accessPoint1.X_* accessPoint1.Y_;
    
    if (accessPoint1.cella) accessPoint1.cella->force-=
	(accessPoint1.cella->position-anchorPoint2)*elasticities[0][0]*strength;
    if (accessPoint1.cellb) accessPoint1.cellb->force-=
	(accessPoint1.cellb->position-anchorPoint2)*elasticities[0][1]*strength;
    if (accessPoint1.cellc) accessPoint1.cellc->force-=
	(accessPoint1.cellc->position-anchorPoint2)*elasticities[1][0]*strength;
    if (accessPoint1.celld) accessPoint1.celld->force-=
	(accessPoint1.celld->position-anchorPoint2)*elasticities[1][1]*strength;
    }

void TaoConnector::updateAnchorToAccess()
    {
    static float elasticities[2][2];

    elasticities[0][0]=accessPoint2.X * accessPoint2.Y;
    elasticities[0][1]=accessPoint2.X_* accessPoint2.Y;
    elasticities[1][0]=accessPoint2.X * accessPoint2.Y_;
    elasticities[1][1]=accessPoint2.X_* accessPoint2.Y_;
    
    if (accessPoint2.cella) accessPoint2.cella->force-=
	(accessPoint2.cella->position-anchorPoint1)*elasticities[0][0]*strength;
    if (accessPoint2.cellb) accessPoint2.cellb->force-=
	(accessPoint2.cellb->position-anchorPoint1)*elasticities[0][1]*strength;
    if (accessPoint2.cellc) accessPoint2.cellc->force-=
	(accessPoint2.cellc->position-anchorPoint1)*elasticities[1][0]*strength;
    if (accessPoint2.celld) accessPoint2.celld->force-=
	(accessPoint2.celld->position-anchorPoint1)*elasticities[1][1]*strength;
    }

void TaoConnector::display()
    {
    if (!tao.graphicsEngine.active) return;
    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0) return;

    TaoInstrument &instr1=accessPoint1.getInstrument();
    GLfloat x1;
    GLfloat y1;
    GLfloat z1;
    TaoInstrument &instr2=accessPoint2.getInstrument();
    GLfloat x2;
    GLfloat y2;
    GLfloat z2;

    if (accessPoint1.instrument)
	{
	if (tao.graphicsEngine.displayDeviceNames)
	    {
	    x1=(GLfloat)(instr1.getWorldX() + accessPoint1.cellx);
	    z1=(GLfloat)(accessPoint1.getPosition()*instr1.getMagnification()*
		tao.graphicsEngine.globalMagnification + 2.0);
	    y1=(GLfloat)(instr1.getWorldY() + accessPoint1.celly);

	    tao.graphicsEngine.displayCharString(x1,y1,z1,this->name,1.0,1.0,1.0);
	    }
	tao.graphicsEngine.displayAccessPoint(accessPoint1);
	}

    if (accessPoint2.instrument)
	{
	if (tao.graphicsEngine.displayDeviceNames)
	    {
	    x2=(GLfloat)(instr2.getWorldX() + accessPoint2.cellx);
	    z2=(GLfloat)(accessPoint2.getPosition()*instr2.getMagnification()*
		tao.graphicsEngine.globalMagnification + 2.0);
	    y2=(GLfloat)(instr2.getWorldY() + accessPoint2.celly);

	    tao.graphicsEngine.displayCharString(x2,y2,z2,this->name,1.0,1.0,1.0);
	    }
	tao.graphicsEngine.displayAccessPoint(accessPoint2);
	}
    }
