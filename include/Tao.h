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
 
#ifndef TAO_H
#define TAO_H

extern "C" 
{
#include <stdlib.h>
#include <unistd.h>
}

#include "TaoSynthEngine.h"
#include "TaoGraphicsEngine.h"

extern char *optarg;
extern int optind, opterr, optopt;

class Tao
    {
    friend class TaoOutput; // necessary because a TaoOutput object must
			    // be able to find out the audio sample rate
public:
    Tao();
    void seedRandomNumGen();
    void audioRateFunc(int (*functionPtr)(void));
    void initFunc(void (*functionPtr)(void));
    void scoreDurationFunc(float (*functionPtr)(void));
    void scoreFunc(void (*functionPtr)(void));
    void setAudioSampleRate();
    void setAudioSampleRate(int sr);
    void initInstrumentsAndDevices();
    void setScoreDuration();
    void setScoreDuration(float duration);
    void executeScore();
    void masterTick();
    void main(int argc, char *argv[]);
    inline void initStartAndEnd()
	{
	stackPointer++;
	startStack[stackPointer]=start;
	endStack[stackPointer]=end;
	start=startStack[0];
	end=endStack[0];
	}

    inline void pushStartAndEnd1()
	{
	stackPointer++;
	startStack[stackPointer]=start;
	endStack[stackPointer]=end;
	start=newStart;
	end=newEnd;
	}
	
    inline void pushStartAndEnd2()
	{
	stackPointer++;
	startStack[stackPointer]=start;
	endStack[stackPointer]=end;
	}
	
    inline void popStartAndEnd()
	{
	start=startStack[stackPointer];
	end=endStack[stackPointer];
	stackPointer--;
	}
    
    float start, end;
    float newStart, newEnd; 

    TaoSynthEngine synthesisEngine;
    TaoGraphicsEngine graphicsEngine;

private:
    void (*scoreFunctionPtr)(void);    // User supplied functions
    void (*initFunctionPtr)(void);
    float (*durationFunctionPtr)(void);
    int (*audioRateFunctionPtr)(void);
    int audioRate;
    float scoreDuration;
    float startStack[30];
    float endStack[30];
    int stackPointer;
    };

void taoMasterTick();

#endif
