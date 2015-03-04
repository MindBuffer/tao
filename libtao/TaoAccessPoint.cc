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

#include "Tao.h"
#include "TaoAccessPoint.h"
#include "TaoCell.h"

extern Tao tao;

TaoAccessPoint::TaoAccessPoint()
    {
    instrument=NULL;
    x=0.0; 
    y=0.0;
    cellx=0.0; 
    celly=0.0;
    X_=0.0;
    X=1.0;
    Y_=0.0;
    Y=1.0;
    cella=cellb=cellc=celld=NULL;
    }
    
float TaoAccessPoint::getForce()
    {
    unsigned short cellFlags=0;
    float a, b, c, d;

    if (cella) cellFlags|=TAOCELLA;
    if (cellb) cellFlags|=TAOCELLB;
    if (cellc) cellFlags|=TAOCELLC;
    if (celld) cellFlags|=TAOCELLD;

    switch(cellFlags)
	{
	case TAO____:	a=b=c=d=0.0;		    break;
	case TAO___D:	a=b=c=d=celld->force;       break;
	case TAO__C_:	a=b=c=d=cellc->force;       break;
	case TAO__CD:
	    a=c=cellc->velocity;
	    b=d=celld->velocity;
	    break;
	case TAO_B__:	a=b=c=d=cellb->force;       break;	
	case TAO_B_D:
	    a=b=cellb->force;
	    c=d=celld->force;
	    break;
	case TAO_BC_:
	    b=cellb->force;
	    c=cellc->force;
	    a=d=(b+c)/2.0f;
	    break;
	case TAO_BCD:
	    b=cellb->force;
	    c=cellc->force;
	    d=celld->force;
	    a=(b+c)/2.0f;
	    break;
	case TAOA___: a=b=c=d=cella->force;	    break;
	case TAOA__D:
	    a=cella->force;
	    d=celld->force;
	    b=c=(a+d)/2.0f;
	    break;
	case TAOA_C_:
	    b=a=cella->force;
	    d=c=cellc->force;
	    break; 
	case TAOA_CD:
	    a=cella->force;
	    c=cellc->force;
	    d=celld->force;
	    b=(a+d)/2.0f;
	    break;
	case TAOAB__:
	    c=a=cella->force;
	    d=b=cellb->force;
	    break;
	case TAOAB_D:
	    a=cella->force;
	    b=cellb->force;
	    d=celld->force;
	    c=(a+d)/2.0f;
	    break;
	case TAOABC_:
	    a=cella->force;
	    b=cellb->force;
	    c=cellc->force;
	    d=(b+c)/2.0f;
	    break;
	case TAOABCD:
	    a=cella->force;
	    b=cellb->force;
	    c=cellc->force;
	    d=celld->force;
	    break;
	}

    if (tao.graphicsEngine.active)
        tao.graphicsEngine.displayAccessPoint(*this);

    return a*X*Y + b*X_*Y + c*X*Y_ + d*X_*Y_;	
    }

float TaoAccessPoint::getVelocity()
    {
    unsigned short cellFlags=0;
    float a, b, c, d;

    if (cella) cellFlags|=TAOCELLA;
    if (cellb) cellFlags|=TAOCELLB;
    if (cellc) cellFlags|=TAOCELLC;
    if (celld) cellFlags|=TAOCELLD;

    switch(cellFlags)
	{
	case TAO____:	a=b=c=d=0.0;		    break;
	case TAO___D:	a=b=c=d=celld->velocity;    break;
	case TAO__C_:	a=b=c=d=cellc->velocity;    break;
	case TAO__CD:
	    a=c=cellc->velocity;
	    b=d=celld->velocity;
	    break;
	case TAO_B__:	a=b=c=d=cellb->velocity;    break;	
	case TAO_B_D:
	    a=b=cellb->velocity;
	    c=d=celld->velocity;
	    break;
	case TAO_BC_:
	    b=cellb->velocity;
	    c=cellc->velocity;
	    a=d=(b+c)/2.0f;
	    break;
	case TAO_BCD:
	    b=cellb->velocity;
	    c=cellc->velocity;
	    d=celld->velocity;
	    a=(b+c)/2.0f;
	    break;
	case TAOA___: a=b=c=d=cella->velocity;	    break;
	case TAOA__D:
	    a=cella->velocity;
	    d=celld->velocity;
	    b=c=(a+d)/2.0f;
	    break;
	case TAOA_C_:
	    b=a=cella->velocity;
	    d=c=cellc->velocity;
	    break; 
	case TAOA_CD:
	    a=cella->velocity;
	    c=cellc->velocity;
	    d=celld->velocity;
	    b=(a+d)/2.0f;
	    break;
        case TAOAB__:
            c=a=cella->velocity;
            d=b=cellb->velocity;
            break;
        case TAOAB_D:
            a=cella->velocity;
            b=cellb->velocity;
            d=celld->velocity;
            c=(a+d)/2.0;
            break;
        case TAOABC_:
            a=cella->velocity;
            b=cellb->velocity;
            c=cellc->velocity;
            d=(b+c)/2.0;
            break;
        case TAOABCD:
            a=cella->velocity;
            b=cellb->velocity;
            c=cellc->velocity;
            d=celld->velocity;
            break;
  	}

    if (tao.graphicsEngine.active)
        tao.graphicsEngine.displayAccessPoint(*this);

    return a*X*Y + b*X_*Y + c*X*Y_ + d*X_*Y_;	
    }

float TaoAccessPoint::getPosition()
    {
    unsigned short cellFlags=0;
    float a, b, c, d;

    if (cella) cellFlags|=TAOCELLA;
    if (cellb) cellFlags|=TAOCELLB;
    if (cellc) cellFlags|=TAOCELLC;
    if (celld) cellFlags|=TAOCELLD;

    switch(cellFlags)
	{
	case TAO____:	a=b=c=d=0.0;		    break;
	case TAO___D:	a=b=c=d=celld->position;    break;
	case TAO__C_:	a=b=c=d=cellc->position;    break;
	case TAO__CD:
	    a=c=cellc->position;
	    b=d=celld->position;
	    break;
	case TAO_B__:	a=b=c=d=cellb->position;    break;	
	case TAO_B_D:
	    a=b=cellb->position;
	    c=d=celld->position;
	    break;
	case TAO_BC_:
	    b=cellb->position;
	    c=cellc->position;
	    a=d=(b+c)/2.0f;
	    break;
	case TAO_BCD:
	    b=cellb->position;
	    c=cellc->position;
	    d=celld->position;
	    a=(b+c)/2.0f;
	    break;
	case TAOA___: a=b=c=d=cella->position;	    break;
	case TAOA__D:
	    a=cella->position;
	    d=celld->position;
	    b=c=(a+d)/2.0f;
	    break;
	case TAOA_C_:
	    b=a=cella->position;
	    d=c=cellc->position;
	    break; 
	case TAOA_CD:
	    a=cella->position;
	    c=cellc->position;
	    d=celld->position;
	    b=(a+d)/2.0f;
	    break;
	case TAOAB__:
	    c=a=cella->position;
	    d=b=cellb->position;
	    break;
	case TAOAB_D:
	    a=cella->position;
	    b=cellb->position;
	    d=celld->position;
	    c=(a+d)/2.0f;
	    break;
	case TAOABC_:
	    a=cella->position;
	    b=cellb->position;
	    c=cellc->position;
	    d=(b+c)/2.0f;
	    break;
	case TAOABCD:
	    a=cella->position;
	    b=cellb->position;
	    c=cellc->position;
	    d=celld->position;
	    break;
	}

    return a*X*Y + b*X_*Y + c*X*Y_ + d*X_*Y_;	
    }

    
TaoInstrument &TaoAccessPoint::getInstrument()
    {
    return *instrument;
    }
   
void TaoAccessPoint::applyForce(float f)
    {
    if (cella) cella->applyForce(f*X*Y);
    if (cellb) cellb->applyForce(f*X_*Y);
    if (cellc) cellc->applyForce(f*X*Y_);
    if (celld) celld->applyForce(f*X_*Y_);

//    std::cout << "cellc=" << f*X*Y_ << " celld=" << f*X_*Y_ << std::endl;
//    std::cout << "cella=" << f*X*Y  << " cellb=" << f*X_*Y << std::endl << std::endl;
    }

void TaoAccessPoint::clear()
    {
    instrument=NULL;
    x=0.0; 
    y=0.0;
    cellx=0.0;
    celly=0.0;
    X_=0.0;
    X=1.0;
    Y_=0.0;
    Y=1.0;
    cella=cellb=cellc=celld=NULL;
    }

TaoAccessPoint::operator float()
    {
    return getPosition();
    }

//////////////////////////////////////////////////////////////////////////////
// Static member function names:
//	connect():	    connect two continuously variable and interpolated
//                          points on two intruments via springs whose
//                          coefficients of elasticity are derived from the
//                          instrument coordinates specifying the two points.
//
//	collide():	    similar to connect but implements a conditional
//                          connection which applies only when z1<z2 where
//			    z1 is the interpolated vertical position of the
//			    point specified on the first instrument and z2
//			    is the interpolated vertical position of the
//			    specified point on the second instrument.
//
//	ground():	    similar to connect but simply connects the
//			    specified point to ground (z=0) via springs. This
//			    technique is less restrictive than locking a point
//			    at the z=0 position and could be used as the
//			    basis for simulating the effect of stopping
//			    notes on stringed instruments.

void TaoAccessPoint::connect(TaoAccessPoint &p1, TaoAccessPoint &p2, float connectionStrength)
    {
    static float eaa, eab, eac, ead;
    static float eba, ebb, ebc, ebd;
    static float eca, ecb, ecc, ecd;
    static float eda, edb, edc, edd;

    static float faa, fab, fac, fad;
    static float fba, fbb, fbc, fbd;
    static float fca, fcb, fcc, fcd;
    static float fda, fdb, fdc, fdd;

    eaa=p1.X * p1.Y * p2.X * p2.Y;
    eab=p1.X * p1.Y * p2.X_* p2.Y;
    eac=p1.X * p1.Y * p2.X * p2.Y_;
    ead=p1.X * p1.Y * p2.X_* p2.Y_;

    eba=p1.X_* p1.Y * p2.X * p2.Y;
    ebb=p1.X_* p1.Y * p2.X_* p2.Y;
    ebc=p1.X_* p1.Y * p2.X * p2.Y_;
    ebd=p1.X_* p1.Y * p2.Y_* p2.X_;
    
    eca=p1.X * p1.Y_* p2.X * p2.Y;
    ecb=p1.X * p1.Y_* p2.X_* p2.Y;
    ecc=p1.X * p1.Y_* p2.X * p2.Y_;
    ecd=p1.X * p1.Y_* p2.X_* p2.Y_;
        
    eda=p1.X_* p1.Y_* p2.X * p2.Y;
    edb=p1.X_* p1.Y_* p2.X_* p2.Y;
    edc=p1.X_* p1.Y_* p2.X * p2.Y_;
    edd=p1.X_* p1.Y_* p2.X_* p2.Y_;
 
    
    if (p1.cella)
	{
	if (p2.cella) faa=(p2.cella->position - p1.cella->position) * eaa;
	if (p2.cellb) fab=(p2.cellb->position - p1.cella->position) * eab;
	if (p2.cellc) fac=(p2.cellc->position - p1.cella->position) * eac;
	if (p2.celld) fad=(p2.celld->position - p1.cella->position) * ead;
	}

    if (p1.cellb)
	{
	if (p2.cella) fba=(p2.cella->position - p1.cellb->position) * eba;
	if (p2.cellb) fbb=(p2.cellb->position - p1.cellb->position) * ebb;
	if (p2.cellc) fbc=(p2.cellc->position - p1.cellb->position) * ebc;
	if (p2.celld) fbd=(p2.celld->position - p1.cellb->position) * ebd;
	}
    
    if (p1.cellc)
	{
	if (p2.cella) fca=(p2.cella->position - p1.cellc->position) * eca;
	if (p2.cellb) fcb=(p2.cellb->position - p1.cellc->position) * ecb;
	if (p2.cellc) fcc=(p2.cellc->position - p1.cellc->position) * ecc;
	if (p2.celld) fcd=(p2.celld->position - p1.cellc->position) * ecd;
	}

    if (p1.celld)
	{
	if (p2.cella) fda=(p2.cella->position - p1.celld->position) * eda;
	if (p2.cellb) fdb=(p2.cellb->position - p1.celld->position) * edb;
	if (p2.cellc) fdc=(p2.cellc->position - p1.celld->position) * edc;
	if (p2.celld) fdd=(p2.celld->position - p1.celld->position) * edd;
	}
	
    if (p1.cella) p1.cella->force+=( faa + fab + fac + fad)*connectionStrength;
    if (p1.cellb) p1.cellb->force+=( fba + fbb + fbc + fbd)*connectionStrength;
    if (p1.cellc) p1.cellc->force+=( fca + fcb + fcc + fcd)*connectionStrength;
    if (p1.celld) p1.celld->force+=( fda + fdb + fdc + fdd)*connectionStrength;

    if (p2.cella) p2.cella->force+=(-faa - fba - fca - fda)*connectionStrength;
    if (p2.cellb) p2.cellb->force+=(-fab - fbb - fcb - fdb)*connectionStrength;
    if (p2.cellc) p2.cellc->force+=(-fac - fbc - fcc - fdc)*connectionStrength;
    if (p2.celld) p2.celld->force+=(-fad - fbd - fcd - fdd)*connectionStrength;
    }


void TaoAccessPoint::collide(TaoAccessPoint &p1, TaoAccessPoint &p2, float connectionStrength)
    {
    static float eaa, eab, eac, ead;
    static float eba, ebb, ebc, ebd;
    static float eca, ecb, ecc, ecd;
    static float eda, edb, edc, edd;

    static float faa, fab, fac, fad;
    static float fba, fbb, fbc, fbd;
    static float fca, fcb, fcc, fcd;
    static float fda, fdb, fdc, fdd;

    static float z1, z2;

    z1=p1.getPosition();
    z2=p2.getPosition();
    
    if (z1<z2)
	{
	eaa=p1.X * p1.Y * p2.X * p2.Y;
	eab=p1.X * p1.Y * p2.X_* p2.Y;
	eac=p1.X * p1.Y * p2.X * p2.Y_;
	ead=p1.X * p1.Y * p2.X_* p2.Y_;

	eba=p1.X_* p1.Y * p2.X * p2.Y;
	ebb=p1.X_* p1.Y * p2.X_* p2.Y;
	ebc=p1.X_* p1.Y * p2.X * p2.Y_;
	ebd=p1.X_* p1.Y * p2.Y_* p2.X_;
    
	eca=p1.X * p1.Y_* p2.X * p2.Y;
	ecb=p1.X * p1.Y_* p2.X_* p2.Y;
	ecc=p1.X * p1.Y_* p2.X * p2.Y_;
	ecd=p1.X * p1.Y_* p2.X_* p2.Y_;
        
	eda=p1.X_* p1.Y_* p2.X * p2.Y;
	edb=p1.X_* p1.Y_* p2.X_* p2.Y;
	edc=p1.X_* p1.Y_* p2.X * p2.Y_;
	edd=p1.X_* p1.Y_* p2.X_* p2.Y_;
 
	if (p1.cella)
	    {
	    if (p2.cella) faa=(p2.cella->position - p1.cella->position) * eaa;
	    if (p2.cellb) fab=(p2.cellb->position - p1.cella->position) * eab;
	    if (p2.cellc) fac=(p2.cellc->position - p1.cella->position) * eac;
	    if (p2.celld) fad=(p2.celld->position - p1.cella->position) * ead;
	    }

	if (p1.cellb)
	    {
	    if (p2.cella) fba=(p2.cella->position - p1.cellb->position) * eba;
	    if (p2.cellb) fbb=(p2.cellb->position - p1.cellb->position) * ebb;
	    if (p2.cellc) fbc=(p2.cellc->position - p1.cellb->position) * ebc;
	    if (p2.celld) fbd=(p2.celld->position - p1.cellb->position) * ebd;
	    }
    
	if (p1.cellc)
	    {
	    if (p2.cella) fca=(p2.cella->position - p1.cellc->position) * eca;
	    if (p2.cellb) fcb=(p2.cellb->position - p1.cellc->position) * ecb;
	    if (p2.cellc) fcc=(p2.cellc->position - p1.cellc->position) * ecc;
	    if (p2.celld) fcd=(p2.celld->position - p1.cellc->position) * ecd;
	    }

	if (p1.celld)
	    {
	    if (p2.cella) fda=(p2.cella->position - p1.celld->position) * eda;
	    if (p2.cellb) fdb=(p2.cellb->position - p1.celld->position) * edb;
	    if (p2.cellc) fdc=(p2.cellc->position - p1.celld->position) * edc;
	    if (p2.celld) fdd=(p2.celld->position - p1.celld->position) * edd;
	    }
	        
        if (p1.cella) p1.cella->force+=( faa + fab + fac + fad)*connectionStrength;
	if (p1.cellb) p1.cellb->force+=( fba + fbb + fbc + fbd)*connectionStrength;
	if (p1.cellc) p1.cellc->force+=( fca + fcb + fcc + fcd)*connectionStrength;
	if (p1.celld) p1.celld->force+=( fda + fdb + fdc + fdd)*connectionStrength;

	if (p2.cella) p2.cella->force+=(-faa - fba - fca - fda)*connectionStrength;
	if (p2.cellb) p2.cellb->force+=(-fab - fbb - fcb - fdb)*connectionStrength;
	if (p2.cellc) p2.cellc->force+=(-fac - fbc - fcc - fdc)*connectionStrength;
	if (p2.celld) p2.celld->force+=(-fad - fbd - fcd - fdd)*connectionStrength;
        }
    }


void TaoAccessPoint::ground(TaoAccessPoint &p, float connectionStrength)
    {
    static float elasticities[2][2];

// calculate reciprocal forces due to temporary spring connections

    elasticities[0][0]=p.X * p.Y;
    elasticities[0][1]=p.X_* p.Y;
    elasticities[1][0]=p.X * p.Y_;
    elasticities[1][1]=p.X_* p.Y_;
    
    if (p.cella) p.cella->force-=
	p.cella->position*elasticities[0][0]*connectionStrength;
    if (p.cellb) p.cellb->force-=
	p.cellb->position*elasticities[0][1]*connectionStrength;
    if (p.cellc) p.cellc->force-=
	p.cellc->position*elasticities[1][0]*connectionStrength;
    if (p.celld) p.celld->force-=
	p.celld->position*elasticities[1][1]*connectionStrength;
    }
