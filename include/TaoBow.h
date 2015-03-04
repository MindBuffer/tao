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

#ifndef BOW_H
#define BOW_H

#include "TaoDevice.h"
#include "TaoAccessPoint.h"

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class TaoInstrument;

class DLLEXPORT TaoBow : public TaoDevice
    {
public:
    TaoBow();
    TaoBow(const char *bowName);
    TaoBow &setForce(float force);
    TaoBow &setVelocity(float velocity);
    float getForce();
    float getVelocity();
    void operator()(TaoAccessPoint &a);
    void operator()(TaoInstrument &instr, float x);
    void operator()(TaoInstrument &instr, float x, float y);
    void update();
    void display();

private:
    enum BowMode {stick, slip};
    BowMode mode;
    float maxVelocity;
    float bowVelocity, downwardForce;
    float stickingForce, slippingForce, forceExerted;
    float relativeVelocity, instrAcceleration;
    float instrForce, instrVelocity;
    float bowPointPosition;
    };

#endif
