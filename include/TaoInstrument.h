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

#ifndef INSTRUMENT_H
#define INSTRUMENT_H

extern "C"
{
#include <stdlib.h>
}

#include "TaoAccessPoint.h"
#include "TaoPitch.h"

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

struct DLLEXPORT Row
    {
    int xmax;
    int offset;
    TaoCell *cells;
    };

class TaoCell;
class TaoSynthEngine;
class TaoGraphicsEngine;

class DLLEXPORT TaoInstrument
    {
    friend class TaoSynthEngine;
    friend class TaoGraphicsEngine;
    friend int main(int argc, char *argv[]);        

public:
    TaoInstrument();
    ~TaoInstrument();
    TaoInstrument(const TaoPitch &xpitch, const TaoPitch &ypitch, float decay);
    TaoInstrument(const char *name, const TaoPitch &xpitch, 
			const TaoPitch &ypitch, float decay);
    void calculateForces(int startRow, int endRow);
    void calculatePositions(int startRow, int endRow);
    char *getName() {return name;}
    float getMagnification();
    TaoInstrument &setMagnification(float m);
    TaoInstrument &setDecay(float x1, float x2, float y1, float y2, float decay);
    TaoInstrument &setDecay(float left, float right, float decay);
    TaoInstrument &setDecay(float decay);
    TaoInstrument &resetDecay(float x1, float x2, float y1, float y2);
    TaoInstrument &resetDecay(float left, float right);
    TaoInstrument &resetDecay();
    TaoInstrument &setDamping(float x1, float x2, float y1, float y2, float damping);
    TaoInstrument &setDamping(float left, float right, float damping);
    TaoInstrument &setDamping(float position, float damping);
    TaoInstrument &setDamping(float damping);
    TaoInstrument &resetDamping(float x1, float x2, float y1, float y2);
    TaoInstrument &resetDamping(float left, float right);
    TaoInstrument &resetDamping(float position);
    TaoInstrument &resetDamping();
    TaoInstrument &lock(float x1, float x2, float y1, float y2);
    TaoInstrument &lock(float x, float y);
    TaoInstrument &lockLeft();
    TaoInstrument &lockRight();
    TaoInstrument &lockTop();
    TaoInstrument &lockBottom();
    TaoInstrument &lockPerimeter();
    TaoInstrument &lockCorners();
    TaoInstrument &lockEnds();
    TaoAccessPoint &operator()(float x, float y);
    TaoAccessPoint &operator()(float x);
    TaoCell &at(float x, float y);
    TaoAccessPoint &point(float x, float y);	// The only difference between these
    TaoAccessPoint &point(float x);		// two func's and the operator() ones
						// above is that these two don't
						// affect the graphics display whereas
						// the operator() ones mark the point
						// accessed with a blue point.
    
    void displayAt(int x, int y) {graphx=x;graphy=y;}
    void placeAt(int x, int y) {worldx=x;worldy=y;}
    void placeAbove(TaoInstrument &ref);
    void placeBelow(TaoInstrument &ref);
    void placeRightOf(TaoInstrument &ref);
    void placeLeftOf(TaoInstrument &ref);
    void placeAbove(TaoInstrument &ref, int distanceInWorldCoords);
    void placeBelow(TaoInstrument &ref, int distanceInWorldCoords);
    void placeRightOf(TaoInstrument &ref, int distanceInWorldCoords);
    void placeLeftOf(TaoInstrument &ref, int distanceInWorldCoords);
    void copyWorldPosition(TaoInstrument &instr);

    inline int getWorldX() {return worldx;}
    inline int getWorldY() {return worldy;}
    inline int getXMax() {return xmax;}
    inline int getYMax() {return ymax;}
    inline float getXFrequency() {return xfrequency;}
    inline float getYFrequency() {return yfrequency;}

    static float decay2velocityMultiplier(float decay);
    static int hertz2cells(float freq);

    static void glue(TaoInstrument &i1, float x1, float y1,
		     TaoInstrument &i2, float x2, float y2);
    static void glue(TaoInstrument &i1, float x1, float y1,
		     TaoInstrument &i2, float x2);
    static void glue(TaoInstrument &i1, float x1,
		     TaoInstrument &i2, float x2, float y2);
    static void glue(TaoInstrument &i1, float x1,
		     TaoInstrument &i2, float x2);

    static void join(TaoAccessPoint &a1, TaoAccessPoint &a2);

// old prototype
//
//    static void join(TaoInstrument &i1, float x1, float y1,
//		     TaoInstrument &i2, float x2, float y2);


    TaoPitch xpitch, ypitch;
    
protected:
    char name[30];
    float defaultDecay, defaultVelocityMultiplier;
    float amplification;
    TaoInstrument *next;
    Row *rows;
    
    int xmax, ymax;
    int graphx, graphy;
    int worldx, worldy;
    float xfrequency, yfrequency;
    int perimeterLocked;
    TaoAccessPoint currentAccess;
    
// these variables are used to implement access points on an instrument with
// real x and y coordinates.

    virtual void createTheMaterial()=0;    
    void initialiseCells();
    void linkCells();

    static float defaultMass;
    static void glueCells(TaoCell *c1, TaoCell *c2);
    static void joinLeftToLeft(TaoCell &cell1, TaoCell &cell2);
    static void joinLeftToRight(TaoCell &cell1, TaoCell &cell2);
    static void joinRightToLeft(TaoCell &cell1, TaoCell &cell2);
    static void joinRightToRight(TaoCell &cell1, TaoCell &cell2);
    static void joinBottomToBottom(TaoCell &cell1, TaoCell &cell2);
    static void joinBottomToTop(TaoCell &cell1, TaoCell &cell2);
    static void joinTopToBottom(TaoCell &cell1, TaoCell &cell2);
    static void joinTopToTop(TaoCell &cell1, TaoCell &cell2);
    
    };


#endif
