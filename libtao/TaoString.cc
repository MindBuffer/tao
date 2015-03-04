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
#include "TaoString.h"
#include <cassert>

TaoString::TaoString(const TaoPitch &pitch, float decay)
    : TaoInstrument(pitch, TaoPitch(0.0), decay)
    {
    createTheMaterial();
    }

TaoString::TaoString(const char *name, const TaoPitch &pitch, float decay)
    : TaoInstrument(name, pitch, TaoPitch(0.0), decay)
    {
    createTheMaterial();
    }
        
void TaoString::createTheMaterial()
    {
    int xsize=xmax+1, ysize=ymax+1;

    rows=new Row[ysize];

    rows[0].xmax=xsize-1;
    rows[0].offset=0;
    rows[0].cells=new TaoCell[xsize];
    
    assert(rows[0].cells != 0);

    initialiseCells();
    linkCells();
    }
