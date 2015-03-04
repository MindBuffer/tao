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

#ifndef TAO_CELL_H
#define TAO_CELL_H

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#define TAO_CELL_LOCK_MODE		0x0001
#define TAO_CELL_SLAVE_MODE 		0x0002
#define TAO_CELL_MASTER_MODE		0x0004
#define TAO_CELL_BOW_STICK_MODE		0x0008

#define TAO_CELL_HAS_8_NEIGHBOURS	0x0010

#define TAO_CELL_NORTH			0x0100
#define TAO_CELL_NWEST			0x0200
#define TAO_CELL_WEST			0x0400
#define TAO_CELL_SWEST			0x0800
#define TAO_CELL_SOUTH			0x1000
#define TAO_CELL_SEAST			0x2000
#define TAO_CELL_EAST			0x4000
#define TAO_CELL_NEAST			0x8000

class TaoInstrument;
class TaoAccessPoint;
class TaoConnector;
class TaoGraphicsEngine;

class DLLEXPORT TaoCell
    {
    friend class TaoInstrument;
    friend class TaoAccessPoint;
    friend class TaoConnector;
    friend class TaoGraphicsEngine;

private:
    int mode;
    TaoCell *north, *south, *east, *west;
    TaoCell *neast, *nwest, *seast, *swest;
    TaoCell *companion;
    float mass, velocityMultiplier;  // simulates losses
	float inverseMass;
    float position, velocity, force;
    void applyForce(float F);
    void bow(float f_bow, float v_bow);
    void lock() {mode |= TAO_CELL_LOCK_MODE;}
    operator float() {return position;}
    };

#endif
