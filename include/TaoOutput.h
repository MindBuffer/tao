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

#ifndef OUTPUT_H
#define OUTPUT_H

#include <fstream>
#include <sstream>
#include "TaoDevice.h"

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class TaoSynthEngine;

#define stereo 2
#define mono 1

class TaoDevice;

class DLLEXPORT TaoOutput : public TaoDevice
    {
    friend class TaoSynthEngine;
    
public:
    TaoOutput();
    ~TaoOutput();
    TaoOutput(const char *filename, int channels);
    TaoOutput(const char *outputName, const char *filename, int channels);
    inline void ch1(float value) {samples[0]=value;}
    inline void ch2(float value) {samples[1]=value;}
    inline void ch3(float value) {samples[2]=value;}
    inline void ch4(float value) {samples[3]=value;}
    inline void chL(float value) {samples[0]=value;} 
    inline void chR(float value) {samples[1]=value;}
    void update();
    void display();
    
private:
    static const int buffersize;
    int first_write;
    int index, numChannels;
    float *buffer;
    char *fullfilename;
    std::ofstream *outputfile;
    float *samples;
    float maxSample;
    char *displayString;
    std::ostringstream *displayStream;
    static float displayPosition;
    float myDisplayPosition;
    };

#endif
