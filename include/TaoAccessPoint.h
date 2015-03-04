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

#ifndef ACCESSPOINT_H
#define ACCESSPOINT_H

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class TaoCell;
class TaoInstrument;
class TaoGraphicsEngine;
class TaoDevice;
class TaoBow;
class TaoOutput;

#ifndef NULL
#define NULL 0
#endif

#define TAOCELLA 8
#define TAOCELLB 4
#define TAOCELLC 2
#define TAOCELLD 1

#define TAO____  0
#define TAO___D  1
#define TAO__C_  2
#define TAO__CD  3
#define TAO_B__  4
#define TAO_B_D  5
#define TAO_BC_  6
#define TAO_BCD  7
#define TAOA___  8
#define TAOA__D  9
#define TAOA_C_  10
#define TAOA_CD  11
#define TAOAB__  12
#define TAOAB_D  13
#define TAOABC_  14
#define TAOABCD  15

class DLLEXPORT TaoAccessPoint
    {
    friend class TaoInstrument;
    friend class TaoGraphicsEngine;
    friend class TaoDevice;
    friend class TaoBow;
    friend class TaoHammer;
    friend class TaoMicrophone;
    friend class TaoConnector;
    friend class TaoStop;
    friend int main(int argc, char *argv[]);
    
public:
    TaoAccessPoint();
    float getForce();
    void setForce(float f);
    float getVelocity();
    float getPosition();
    float getMass();
    TaoInstrument &getInstrument();
    void applyForce(float f);
    void clear();
    operator float();
    static void connect(TaoAccessPoint &p1, TaoAccessPoint &p2, float connectionStrength);
    static void collide(TaoAccessPoint &p1, TaoAccessPoint &p2, float connectionStrength);
    static void ground(TaoAccessPoint &p, float connectionStrength);
       
private:
    TaoInstrument *instrument;			// target instrument
    float x, y;					// normalised instrument coordinates
    float cellx, celly;				// real x and y coords in terms of
						// cell positions (i.e. 0..xmax and
						// 0..ymax).
    float X, X_, Y, Y_;				// fractional parts of cellx and celly
						// X_ = cellx - (int)cellx
						// Y_ = celly - (int)celly
						// X = 1-X_     Y=1-Y_
    TaoCell *cella, *cellb, *cellc, *celld;	// four cells nearest (*this).at(x,y)
						// a=bottom left, b=bottom right
						// c=top left, d=top right
    };

#endif
