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
#include "TaoRectangle.h"

TaoRectangle::TaoRectangle(
    const TaoPitch &xpitch, 
    const TaoPitch &ypitch, 
    float decay) : TaoInstrument(xpitch, ypitch, decay) 
    {
    createTheMaterial();
    }

TaoRectangle::TaoRectangle(
    const char *name, 
    const TaoPitch &xpitch, 
    const TaoPitch &ypitch,
    float decay) : TaoInstrument(name, xpitch, ypitch, decay)
    {
    createTheMaterial();
    }

void TaoRectangle::createTheMaterial()
    {
    register int j;

    int xsize=xmax+1, ysize=ymax+1;

    rows=new Row[ysize];

    for (j=0;j<ysize;j++)
	{
	rows[j].xmax=xmax;
	rows[j].offset=0;
	rows[j].cells=new TaoCell[xsize];
	}        

    initialiseCells();
    linkCells();
    }
