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

#include "Tao.h"
#include "TaoSynthEngine.h"
#include "TaoGraphicsEngine.h"
#include "TaoAccessPoint.h"
#include "TaoInstrument.h"
#include "TaoString.h"
#include "TaoRectangle.h"
#include "TaoCircle.h"
#include "TaoTriangle.h"
#include "TaoEllipse.h"
#include "TaoDevice.h"
#include "TaoOutput.h"
#include "TaoBow.h"
#include "TaoHammer.h"
#include "TaoConnector.h"
#include "TaoStop.h"
#include "TaoPitch.h"
#include "TaoCell.h"

// macros for units of measurement

#define Hz
#define secs
#define min *60.0
#define msecs /1000.0
#define samples /44100.0

#define FromTo(a, b) \
if(Tick<=(long)((tao.newEnd=(b))*tao.synthesisEngine.modelSampleRate) && \
   Tick>=(long)((tao.newStart=(a))*tao.synthesisEngine.modelSampleRate))

#define Before(a) \
if(Tick<(long)(tao.newStart=tao.start,\
(tao.newEnd=(a))*tao.synthesisEngine.modelSampleRate))

#define After(a) \
if(Tick>=(long)(tao.newEnd=tao.end,\
(tao.newStart=(a))*tao.synthesisEngine.modelSampleRate))

#define Every(INTERVAL) \
if(Tick%(long)(INTERVAL*tao.synthesisEngine.modelSampleRate)==0)

#define ControlRate(DIVIDEBY) if(Tick%(long)DIVIDEBY==0)
#define At(TIME) if(Tick==(long)(TIME*tao.synthesisEngine.modelSampleRate))
#define If(CONDITION) if(CONDITION)
#define ElseIf(CONDITION) else if(CONDITION)
#define Else else

#define linear(y1, y2) ((Time-tao.start)/(tao.end-tao.start)*(y2-y1)+y1)
#define expon(y1, y2) ((float)(y1)*exp(1.0/(tao.end-tao.start)*\
log((float)(y2)/(float)(y1))*(Time-tao.start)))

#define Param float

#define Print std::cout <<std::setw(0)<<std::setprecision(4)<<std::setiosflags(std::ios::fixed)<<
#define newline '\n'<<std::flush
#define sameline '\r'<<std::flush
#define Flag int
#define Position TaoCell &

#define Score(duration) \
float taoScoreDuration() \
{return duration;} \
void taoScore()

extern Tao tao;
extern float &Time;
extern long &Tick;

extern int randomi(int low, int high);
extern float randomf(float low, float high);
