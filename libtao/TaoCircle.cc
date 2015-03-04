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

#include "TaoInstrument.h"
#include "TaoCircle.h"
#include <cmath>

TaoCircle::TaoCircle(const TaoPitch &pitch, float decay)
    : TaoInstrument(pitch, pitch, decay)
    {
    createTheMaterial();
    }


TaoCircle::TaoCircle(const char *name, const TaoPitch &pitch, float decay)
    : TaoInstrument(name, pitch, pitch, decay)
    {
    createTheMaterial();
    }

void TaoCircle::createTheMaterial()
    {
    register int j;
    float x, y, radius;
    int local_xmax, offset;
    
    int xsize, ysize=ymax+1; 

    rows=new Row[ysize];             	// create the right number of rows
    
    radius=ysize/2.0f;

    for (j=0;j<ysize;j++)            	// create one row at a time starting
	{                               // from bottom.
	y=j-(ysize-1.0f)/2.0f;         	// as j goes from 0 to ymax calculate
	x=(float)sqrt(radius*radius-y*y);      // y for circle equation. Then x
	xsize=((int)(x+0.5f))*2;         // round x up/down to nearest integer
	local_xmax=xsize-1;             
	offset=(ysize-xsize)/2;      	// the row is the correct length but
	rows[j].xmax=local_xmax;        // must be offset relative to the
	rows[j].offset=offset;          // bounding box.
	if(xmax < local_xmax+offset) xmax=local_xmax+offset;
	                                // keep track of longest row
	rows[j].cells=new TaoCell[xsize];  // create `xsize' new cells
	}        

    initialiseCells(); 		// from base class TaoInstrument
    linkCells();
    }
