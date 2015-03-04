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

#ifndef TAODEVICE_H
#define TAODEVICE_H

#ifndef NULL
#define NULL 0
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#include "TaoAccessPoint.h"

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class TaoSynthEngine;
class Instrument;

class DLLEXPORT TaoDevice
    {
    friend class TaoSynthEngine;
    friend class TaoGraphicsEngine;

public:
    TaoDevice();
    ~TaoDevice();
    TaoDevice(const char *deviceName);
    char *getName();
    float getX();
    float getY();
    virtual void apply(TaoAccessPoint &a);
    void remove();
    float x, y;
    
protected:
    void addToSynthesisEngine();
    void removeFromSynthesisEngine();
    void activate();
    void deactivate();
    virtual void update()=0;
    virtual void display()=0;

    enum
	{
	BOW,
	HAMMER,
	CONNECTOR,
	STOP,
	OUTPUT
	};

    int deviceType;
    int active;
    char name[30];
    TaoInstrument *targetInstrument;
    TaoAccessPoint interfacePoint;
    TaoDevice *next;
    };

#endif
