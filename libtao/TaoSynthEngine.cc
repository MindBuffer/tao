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

#include "TaoSynthEngine.h"
#include "TaoInstrument.h"
#include "TaoDevice.h"

#ifdef LINUX
extern int random();
#endif

#ifdef IRIX
extern long random();
#endif

extern TaoSynthEngine taoSynthesisEngine;
extern float &Time;
extern long &Tick;

TaoSynthEngine::TaoSynthEngine()
    : throwAway(2)
    {
    active=TRUE;
    instrumentList = NULL;
    deviceList = NULL;
    time=0.0;
    tick=0;
    setAudioRate(44100);
    }

void TaoSynthEngine::pause()
    {
    active=FALSE;
    }
    
void TaoSynthEngine::unpause()
    {
    active=TRUE;
    }
    
int TaoSynthEngine::isActive()
    {
    return active;
    }

int TaoSynthEngine::done()
    {
    return (tick>numSamples);
    }

void TaoSynthEngine::Tick()
    {
    if (!active) return;
    
    tick++;
    time=(float)tick/(float)modelSampleRate;
    }

unsigned int TaoSynthEngine::getTime()
    {
    return 0u;
    }

void TaoSynthEngine::seedRandomNumGen()
    { 
    srand(getTime());
    }
    
void TaoSynthEngine::setAudioRate(int audioRate)
    {
    audioSampleRate=audioRate;
    modelSampleRate=audioRate*throwAway;
    Decay2VelocityMultiplierConst=(float)(.00012*44100.0)/(float)audioRate;
    Hz2CellConst=24000.0f*(float)audioRate/44100.0f;
    }

void TaoSynthEngine::makeTheInstruments()
    {
    TaoInstrument *i = instrumentList;
    
    while(i)
	{
	i->createTheMaterial();
	i=i->next;
	}
    }

void TaoSynthEngine::addInstrument(TaoInstrument &instr)
    {
    if (instrumentList==NULL) instrumentList=&instr; 
    else
	{
	currentInstrument->next=&instr;
	instr.placeAbove(*currentInstrument);
	}
    currentInstrument=&instr;
    }

void TaoSynthEngine::removeInstrument(TaoInstrument &instr)
    {
    if (instrumentList && instrumentList==&instr)
	{
	instrumentList = instrumentList->next;
	return;
	}
	
    for (TaoInstrument *i=instrumentList; (i && i->next); i=i->next)
	if (i->next == &instr) i->next=i->next->next;
    }
    
void TaoSynthEngine::addInstrument(TaoInstrument *instr)
    {
#ifdef SYNTHENGINE_DEBUG
std::cout << "before addInstrument, current=" << currentInstrument << " new=" << instr << std::endl;
#endif

    if (instrumentList==NULL) instrumentList=instr; 
    else
	{
	currentInstrument->next=instr;
	instr->placeAbove(*currentInstrument);
	}
    currentInstrument=instr;

#ifdef SYNTHENGINE_DEBUG
std::cout << "after addInstrument, current=" << currentInstrument << " new=" << instr << std::endl;
#endif
    }

void TaoSynthEngine::removeInstrument(TaoInstrument *instr)
    {
    if (instrumentList && instrumentList==instr)
	{
	instrumentList = instrumentList->next;
	return;
	}
	
    for (TaoInstrument *i=instrumentList; (i && i->next); i=i->next)
	if (i->next == instr) i->next=i->next->next;
   }
    
void TaoSynthEngine::addDevice(TaoDevice &device)
    {
    if (deviceList==NULL) deviceList=&device; 
    else currentDevice->next=&device;
    currentDevice=&device;
   }

void TaoSynthEngine::removeDevice(TaoDevice &device)
    {
    if (deviceList && deviceList==&device)
	{
	deviceList = deviceList->next;
	return;
	}
	
    for (TaoDevice *d=deviceList; (d && d->next); d=d->next)
	if (d->next == &device) d->next=d->next->next;
   }
    

void TaoSynthEngine::addDevice(TaoDevice *device)
    {
    if (deviceList==NULL) deviceList=device; 
    else currentDevice->next=device;
    currentDevice=device;
    }

void TaoSynthEngine::removeDevice(TaoDevice *device)
    {
    if (deviceList && deviceList==device)
	{
	deviceList = deviceList->next;
	return;
	}
	
    for (TaoDevice *d=deviceList; (d && d->next); d=d->next)
	if (d->next == device) d->next=d->next->next;
    }
    

//////////////////////////////////////////////////////////////////////////////
// Member function names:
//	calculateTaoInstrumentForces(),
//	updateTaoInstrumentPositions(),
//
// Functionality:
//	Cause all instruments to be updated by scanning the linked list
//	and calling the appropriate member functions for each instrument.
//
// Local variable:
//	i: current instrument.
//////////////////////////////////////////////////////////////////////////////

void TaoSynthEngine::calculateInstrumentForces()
    {
    if (!active) return;
     
    for (TaoInstrument *i=instrumentList;i;i=i->next)
	i->calculateForces(0,i->ymax);
    }
    

void TaoSynthEngine::calculateInstrumentPositions()
    {
    if (!active) return;
    
    for (TaoInstrument *i=instrumentList;i;i=i->next)
	i->calculatePositions(0,i->ymax);
    }

void TaoSynthEngine::updateDevices()
    {
    if (!active) return;
    
    for (TaoDevice *d=deviceList;d;d=d->next)
	{
	d->update();
	}
    }

//////////////////////////////////////////////////////////////////////////////
// Global function name:
//	randomi(int low, int high)
//
// Functionality:
//	Returns a random integer between low and high inclusive.
//////////////////////////////////////////////////////////////////////////////

int randomi(int low, int high)
    {
    return (low+(rand()%(high-low+1)));
    }


//////////////////////////////////////////////////////////////////////////////
// Global function name:
//	randomf(float low, float high)
//
// Functionality:
//	Returns a random floating point number between low and high inclusive.
//////////////////////////////////////////////////////////////////////////////

float randomf(float low, float high)
    {
    return (float)randomi((int)(low*100000),(int)(high*100000))/100000.0f;
    }
