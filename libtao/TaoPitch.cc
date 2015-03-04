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

extern "C" 
{
#include <stdlib.h>
}

#ifdef WIN32
#include <strstrea.h>
#else
#include <sstream>
#endif

#include "TaoPitch.h"
#include <iostream>
#include <cmath>

// This class allows pitches and frequencies to be specified in a number of
// different formats including the following:
//
//  . Pitch names such as C6, C#8, Bb5, G#7+1/2, Ab10-1/5 where the number
//    represents the octave (C8 <=> middle C). The + and - notation allows
//    fractions of a semitone to be added or subtracted.
//
//          C8	    -> 261.6 Hz or middle C.
//          C#8	    -> frequency of C sharp above middle C.
//          A8	    -> 440 Hz or A above middle C.
//          Eb6	    -> frequency of E flat in second octave below
//                          middle C.
//          F#8+1/3 -> frequency of F sharp + 1/3 of a semitone
//                          in middle C octave.
//
//  . Numerical pitch notation of the form <octave>.<semitone>. For example:
//
//	    8.00    -> 261.6 Hz or middle C.
//	    8.09    -> 440 Hz or A above middle C. 
//	    7.09    -> 220 Hz.
//
//  . Octave notation, which
//
//	    8.00    -> 261.6 Hz or middle C.
//	    8.5	    ->
//////////////////////////////////////////////////////////////////////////////


TaoPitch::TaoPitch() {}

TaoPitch::TaoPitch(const char *pitchName)
    {
    int nameLength=strlen(pitchName);
    double octave, semitone, frequency, value;
    int isFlat=0, isSharp=0;
    int charno=0;
    
    switch(pitchName[charno++])
	{
	case 'C' : semitone=0.00;break;
	case 'D' : semitone=0.02;break;
	case 'E' : semitone=0.04;break;
	case 'F' : semitone=0.05;break;
	case 'G' : semitone=0.07;break;
	case 'A' : semitone=0.09;break;
	case 'B' : semitone=0.11;break;
	default:
	    std::cerr << "Pitch error: invalid pitch name: " << pitchName << std::endl;
	    exit(1);
	    
	}
	
    if(pitchName[charno]=='b')
	{
	isFlat=1;
	semitone-=0.01;
	charno++;
	}
    else if(pitchName[charno]=='#')
	{
	isSharp=1;
	semitone+=0.01;
	charno++;
	}

    octave=1.0*(pitchName[charno++]-'0');
    if(pitchName[charno]>='0' && pitchName[charno]<='9')
	octave=octave*10.0+1.0*(pitchName[charno++]-'0');
    
    int plus=0, minus=0;

    if(pitchName[charno]=='+' || pitchName[charno]=='-')
	{
	float dividend=0.0;
	
	if(pitchName[charno]=='+') plus=1;
	if(pitchName[charno]=='-') minus=1;
	charno++;
	
	while(pitchName[charno]>='0' && pitchName[charno]<='9')
	    {
	    dividend*=10.0;
	    dividend+=(float)(pitchName[charno]-'0');
	    charno++;
	    }
	    
	if(pitchName[charno++]!='/')
	    {
	    std::cerr << "Pitch error: / expected in pitch name: " << pitchName << std::endl;
	    exit(1);
	    }
	    
	float divisor=0.0;
	    		
	while(pitchName[charno]>='0' && pitchName[charno]<='9')
	    {
	    divisor*=10.0;
	    divisor+=(float)(pitchName[charno]-'0');
	    charno++;
	    }
	    
	if(plus) semitone+=dividend/(divisor*100.0);
	if(minus) semitone-=dividend/(divisor*100.0);
	}

    value = octave + semitone * 100.0 / 12.0;

    frequency = pow(2, value - 8.0) * 261.6;

    this->name=new char[nameLength];
    strcpy(this->name, pitchName);
    this->frequencyVersion=frequency;
    this->pitchVersion=octave+semitone;
    this->octaveVersion=octave+semitone*100.0/12.0;
    }


TaoPitch::TaoPitch(float pitch)
    {
    double octave, semitone;

    if (pitch==0.0)
	{
	this->name=new char[4];
	strcpy(this->name, "N/A");
	this->pitchVersion=0.0;
	this->octaveVersion=0.0;
	this->frequencyVersion=0.0;
	}
    else
	{
	this->pitchVersion=pitch;
	octave=(float)(int)pitch;
	semitone=pitch-octave;
	this->octaveVersion=octave+semitone*100.0/12.0;
	this->frequencyVersion=pow(2, this->octaveVersion-8.0)*261.6;
	}
	
    createName();
    }
    

TaoPitch::TaoPitch(float value, TaoPitchFormat format)
    {
    double octave, semitone, frequency, fraction;

    if (format==pch)
	{    
	this->pitchVersion=value;
	octave=(float)(int)value;
	semitone=value-octave;
	this->octaveVersion=octave+semitone*100.0/12.0;
	this->frequencyVersion=pow(2, this->octaveVersion-8.0)*261.6;
	}
    else if (format==oct)
	{
	octave=(double)(int)value;
	fraction=value-octave;
	semitone=fraction*12.0/100.0;
	frequency=pow(2,value-8.0)*261.6;
	
	this->frequencyVersion=frequency;
	this->pitchVersion=octave+semitone;
	this->octaveVersion=value;
	}
    else if (format==frq)
	{
	this->octaveVersion = log10(value/261.6)/log10(2.0)+8.0;
	octave=(double)(int)(this->octaveVersion);
	fraction=this->octaveVersion-octave;
	semitone=fraction/100.0*12.0;
	frequency=pow(2, this->octaveVersion-8.0)*261.6;
	
	this->frequencyVersion=frequency;
	this->pitchVersion=octave+semitone;
	}
	
    createName();
    }

TaoPitch::TaoPitch(const TaoPitch &p)
    {
    name = new char[strlen(p.name)+1];
    
    strcpy(name, p.name);
    pitchVersion=p.pitchVersion;
    octaveVersion=p.octaveVersion;
    frequencyVersion=p.frequencyVersion;
    }

TaoPitch::~TaoPitch()
    {
    delete [] name;
    }

TaoPitch &TaoPitch::operator=(const TaoPitch &p)
    {
    name = new char[strlen(p.name)+1];
    
    strcpy(name, p.name);
    pitchVersion=p.pitchVersion;
    octaveVersion=p.octaveVersion;
    frequencyVersion=p.frequencyVersion;

    return *this;
    }
       
float TaoPitch::asPitch()	const {return (float)pitchVersion;}
float TaoPitch::asOctave()	const {return (float)octaveVersion;}
float TaoPitch::asFrequency()	const {return (float)frequencyVersion;}
const char *TaoPitch::asName()	const {return name;}

void TaoPitch::createName()
    {
    double octave, semitone, fraction;
    int wholesemi;
    int fractsemi;
    
    octave=(double)(int)(octaveVersion);
    fraction=octaveVersion-octave;
    semitone=fraction*12.0/100.0;
    
    wholesemi=(int)(semitone*100.0+0.5);
    fractsemi=(int)((semitone-(wholesemi/100.0))*10000.0);
    
    name=new char[12];
    
    //ostrstream nameStream(name, 12);
    std::ostringstream nameStream(name, std::ostringstream::out);
    
    switch(wholesemi)
	{
	case  0: nameStream << "C"  ; break;
	case  1: nameStream << "C#" ; break;
	case  2: nameStream << "D"  ; break;
	case  3: nameStream << "D#" ; break;
	case  4: nameStream << "E"  ; break;
	case  5: nameStream << "F"  ; break;
	case  6: nameStream << "F#" ; break;
	case  7: nameStream << "G"  ; break;
	case  8: nameStream << "G#" ; break;
	case  9: nameStream << "A"  ; break;
	case 10: nameStream << "A#" ; break;
	case 11: nameStream << "B"  ; break;
	}

    nameStream << octave;
    if (fractsemi>0) nameStream << "+" << fractsemi << "/100";
    nameStream << std::ends;
    }
