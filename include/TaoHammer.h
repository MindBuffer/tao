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

#ifndef HAMMER_H
#define HAMMER_H

#include "TaoDevice.h"

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class DLLEXPORT TaoHammer : public TaoDevice
    {
public:
    TaoHammer();
    TaoHammer(const char *hammerName);
    void update();
    void display();
    void reset();
    void drop();
    void operator()(TaoAccessPoint &a);
    void operator()(TaoInstrument &instr, float x);
    void operator()(TaoInstrument &instr, float x, float y);
    TaoHammer &setMass(float m);
    TaoHammer &setPosition(float p);
    TaoHammer &setInitVelocity(float v);
    TaoHammer &setGravity(float g);
    TaoHammer &setHeight(float h);
    TaoHammer &setDamping(float d);
    TaoHammer &setHardness(float h);
    TaoHammer &setMaxImpacts(int maxImpacts);    
    float getMass();
    float getPosition();
    float getVelocity();
    float getInitVelocity();
    float getGravity();
    float getHeight();
    float getDamping();
    float getHardness();
    int numberOfImpacts();
    int getMaxImpacts();    
        
private:
    enum TaoHammerMode {contact, nocontact};
    TaoHammerMode mode;
    float height;
    float position;
    float initVelocity;
    float velocity;
    float mass;
    float force;
    float damping;
    float size;
    float gravity;
    float hardness;
    float collisionForce;
    int numImpacts;
    int maxImpacts;
    };

#endif
