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

#include "TaoDevice.h"
#include "Tao.h"
#include "TaoAccessPoint.h"
#include "TaoInstrument.h"

TaoDevice::TaoDevice()
    {
    strcpy(name, "anon");
    targetInstrument = NULL;
    interfacePoint.clear();
    active = 0;
    next = NULL;
    x=0.0;y=0.0;
    }

TaoDevice::~TaoDevice() {}

TaoDevice::TaoDevice(const char *deviceName)
    {
    strcpy(name, deviceName);
    targetInstrument = NULL;
    active = 0;
    next = NULL;
    }

char *TaoDevice::getName()
    {
    return name;
    }

float TaoDevice::getX()
    {
    return interfacePoint.x;
    }
    
float TaoDevice::getY()
    {
    return interfacePoint.y;
    }
        
void TaoDevice::apply(TaoAccessPoint &point)
    {
    targetInstrument = &point.getInstrument();
    interfacePoint = point;
    activate();
    }

void TaoDevice::remove()
    {
    targetInstrument = NULL;
    interfacePoint.clear();
    deactivate();
    }
    
void TaoDevice::activate()
    {
    active=TRUE;
    }

void TaoDevice::deactivate()
    {
    active=FALSE;
    }

extern Tao tao;

void TaoDevice::addToSynthesisEngine()
    {
    tao.synthesisEngine.addDevice(this);
    }

void TaoDevice::removeFromSynthesisEngine()
    {
    tao.synthesisEngine.removeDevice(this);   
    }
