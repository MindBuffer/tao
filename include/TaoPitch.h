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

#ifndef TAOPITCH_H
#define TAOPITCH_H

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class DLLEXPORT TaoPitch
    {
public:
    TaoPitch();
    ~TaoPitch();
    TaoPitch(const char *name);
    TaoPitch(float pitch);
    enum TaoPitchFormat {oct, frq, pch};
    TaoPitch(float value, TaoPitchFormat format); 
    TaoPitch(const TaoPitch&);
    TaoPitch &operator=(const TaoPitch&); 
    float asPitch() const;
    const char *asName() const;
    float asOctave() const;
    float asFrequency() const;
    
private:
    void createName();
    char *name;
    double pitchVersion;
    double octaveVersion;
    double frequencyVersion;
    };

#endif
