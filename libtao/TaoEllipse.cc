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
#include "TaoEllipse.h"
#include <cmath>

TaoEllipse::TaoEllipse(
    const TaoPitch &xpitch,
    const TaoPitch &ypitch,
    float decay) : TaoInstrument(xpitch, ypitch, decay)
    {
    createTheMaterial();
    }

TaoEllipse::TaoEllipse(
    const char *name, 
    const TaoPitch &xpitch, 
    const TaoPitch &ypitch, 
    float decay) : TaoInstrument(name, xpitch, ypitch, decay)
    {
    createTheMaterial();
    }

void TaoEllipse::createTheMaterial()
    {
    register int j;
    float x, y, xradius, yradius;
    float a, b;
    int local_xmax, local_xsize, offset;
    int xsize=xmax+1, ysize=ymax+1;

    rows=new Row[ysize];
    
    xradius=xsize/2.0f;a=xradius*xradius;
    yradius=ysize/2.0f;b=yradius*yradius;

    for (j=0;j<ysize;j++)
	{
	y=j-(ysize-1.0f)/2.0f;
	x=(float)sqrt(a*(1.0f-y*y/b));
	local_xsize=((int)(x+0.5))*2;
	local_xmax=local_xsize-1;
	if (local_xmax>xmax) xmax=local_xmax;
	offset=(xsize-local_xsize)/2;
	rows[j].xmax=local_xmax;
	rows[j].offset=offset;
	if(xmax < local_xmax+offset) xmax=local_xmax+offset;
	rows[j].cells=new TaoCell[xsize];
	}        

    initialiseCells();
    linkCells();    
    }
