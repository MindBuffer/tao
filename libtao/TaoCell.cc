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

#include "TaoCell.h"
#include <cmath>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

void TaoCell::applyForce(float F)
    {
    force+=F;
    
    if (north) north->force+=F/2.0f;
    if (south) south->force+=F/2.0f;
    if (east) east->force+=F/2.0f;
    if (west) west->force+=F/2.0f;
    if (neast) neast->force+=F/2.82f;
    if (seast) seast->force+=F/2.82f;
    if (nwest) nwest->force+=F/2.82f;
    if (swest) swest->force+=F/2.82f;
    }

void TaoCell::bow(float f_bow, float v_bow)
    {
    static float f_stick, f_slip, force_exerted=0.0;
    static float v_relative, a_cell;
    
    v_relative=a_cell=v_bow-velocity;                  // a=dv/dt but dt=1 so a=dv.

    if (mode & TAO_CELL_BOW_STICK_MODE)			// if in `stick' mode.
	{
	f_stick=mass*a_cell-force;
	if (f_stick>f_bow) mode&=!TAO_CELL_BOW_STICK_MODE; // if static frictional
        else force_exerted=f_stick;                    // force required is too
	}                                              // great, change to
                                                       // `slip' mode.

    else                                               // if in `slip' mode.
	{
	f_slip=(float)(f_bow/(1.0f+fabs(v_relative)));
	if (velocity>=0.0) mode|=TAO_CELL_BOW_STICK_MODE;  // if the cell starts
        else force_exerted=f_slip;                     // travelling in the same
	}                                              // (positive) direction
                                                       // `stick' mode.
    applyForce(force_exerted);                         // apply the approriate
    }                                                  // frictional force.
