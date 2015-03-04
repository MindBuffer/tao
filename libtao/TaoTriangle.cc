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
#include "TaoTriangle.h"

TaoTriangle::TaoTriangle(
    const TaoPitch &xpitch, 
    const TaoPitch &ypitch, 
    float decay) : TaoInstrument(xpitch, ypitch, decay)
    {
    createTheMaterial();
    }

TaoTriangle::TaoTriangle(
    const char *name, 
    const TaoPitch &xpitch, 
    const TaoPitch &ypitch, 
    float decay)
    : TaoInstrument(name, xpitch, ypitch, decay)
    {
    createTheMaterial();
    }

void TaoTriangle::createTheMaterial()
    {
    register int j;
    float x;
    int local_xsize, local_xmax, offset;

    int xsize=xmax+1, ysize=ymax+1;

    rows=new Row[ysize];
    
    for (j=0;j<ysize;j++)
	{
	if(j<ysize/2) x=xsize*2.0f*(j+1)/ysize;
	if(j>=ysize/2) x=xsize*2.0f*(ysize/2.0f-(j-ysize/2.0f))/ysize;	
	local_xsize=(int)(x+0.5);
	local_xmax=local_xsize-1;
	offset=xsize-local_xmax;
	rows[j].xmax=local_xmax;
	rows[j].offset=offset;
	if(xmax < local_xmax+offset) xmax=local_xmax+offset;
	rows[j].cells=new TaoCell[local_xsize];
	}        

    initialiseCells();
    linkCells();	
    }
