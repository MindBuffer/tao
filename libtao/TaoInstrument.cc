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
#include "Tao.h"
#include "TaoCell.h"
#include "TaoAccessPoint.h"
//#include <sys/types.h>
#include <iostream>
#include <cmath>

float TaoInstrument::defaultMass=3.5;		// Set to optimum value for
                                                // frequency response of
                                                // material. Leave well alone!!
						
extern Tao tao;

TaoInstrument::TaoInstrument() {}

TaoInstrument::~TaoInstrument()
    {
    for (int j=0;j<=ymax;j++)
	{
	delete [] rows[j].cells;
	}
    delete [] rows;
    }

TaoInstrument::TaoInstrument(const TaoPitch &xpitch, const TaoPitch &ypitch,
			     float decay)
    {
    this->xpitch=xpitch;
    this->ypitch=ypitch;
    xfrequency=xpitch.asFrequency();
    yfrequency=ypitch.asFrequency();
    xmax=hertz2cells(xfrequency)-1;
    ymax=hertz2cells(yfrequency)-1;
    defaultDecay=decay;
    amplification=1.0;	// Only for graphics display, not sound;
    graphx=0;		// ditto
    graphy=0;		// ditto
    worldx=0;		// ditto
    worldy=0;		// ditto
    strcpy(name, "");
    next=NULL;

    tao.synthesisEngine.addInstrument(this);
    }

TaoInstrument::TaoInstrument(const char *name, const TaoPitch &xpitch, 
			     const TaoPitch &ypitch, float decay)
    {
    this->xpitch=xpitch;
    this->ypitch=ypitch;
    xfrequency=xpitch.asFrequency();
    yfrequency=ypitch.asFrequency();
    xmax=hertz2cells(xfrequency)-1;
    ymax=hertz2cells(yfrequency)-1;
    defaultDecay=decay;
    amplification=1.0;	// Only for graphics display, not sound;
    graphx=0;		// ditto
    graphy=0;		// ditto
    worldx=0;		// ditto
    worldy=0;		// ditto
    strcpy(this->name, name);
    next=NULL;

#ifdef INSTRUMENT_DEBUG    
    cout << "In TaoInstrument() tao.synthesisEngine.add(" << this << ")"
    << " name=" << name << endl;
#endif

    tao.synthesisEngine.addInstrument(this);
    }

///////////////////////////////////////////////////////////////////////////////////
// Whenever a point is accessed on an instrument using the notation instr(x,y)
// an access point is generated. Since the underlying physical model consists
// of discrete masses and springs arranged in a grid pattern, if x and y are real
// values some kind of interpolation is needed to apply forces or read off the
// physical attributes of the material at any point, not just the discrete
// positions occupied by the cells. Both overloaded operator()'s end up calling
// the point() member function which actually does the work of calculating the
// internal values for the access point. See just below.
//
// The only difference between a call instr(x,y) and instr.point(x,y) is that
// the former syntax is used to automatically mark the point accessed with a
// blue marker at the appropriate location on the instrument in the graphics
// window.

TaoAccessPoint &TaoInstrument::operator()(float x, float y)
    {
    TaoAccessPoint &p = currentAccess;

    point(x,y);
    tao.graphicsEngine.displayAccessPoint(p);
    
    return p;
    }

TaoAccessPoint &TaoInstrument::operator()(float x)
    {
    return (*this)(x,0.0);
    }           


//////////////////////////////////////////////////////////////////////////////////
// A TaoAccessPoint object maintains a set of information used in this
// interpolation process.
//
//           * cellc        |     * celld           X, Y, X_ and Y_ are in the
//                       Y                          range [0..1].
//                          |
//           - - - - - - - -o- - -                  cella, cellb, cellc and celld
//                  X_      |  X                    are of type (TaoCell *) and are
//                                                  the four nearest cells to the
//                          |                       specified point. Some or all
//                                                  of these four pointers may be
//                       Y_ |                       NULL if there are less than
//                                                  four cells nearby.
//                          |
//                           
//           * cella        |     * cellb


TaoAccessPoint &TaoInstrument::point(float x, float y)
    {
    TaoAccessPoint &p = currentAccess;

#ifdef INSTRUMENT_DEBUG
cout << "Entering " << name << "(" << x << "," << y << ")" << endl;
#endif
    if (x<0.0 || x>1.0) { currentAccess.clear(); return currentAccess; }
    if (y<0.0 || y>1.0) { currentAccess.clear(); return currentAccess; }

    p.x=x;
    p.y=y;   
    p.cellx=x*xmax;
    p.celly=y*ymax;
    p.X_=p.cellx-(int)p.cellx;
    p.Y_=p.celly-(int)p.celly;
    p.X=1-p.X_;
    p.Y=1-p.Y_;
	
    int i=(int)floorf(xmax*x);
    int j=(int)floorf(ymax*y);

#ifdef INSTRUMENT_DEBUG
int cellCount=0;    
#endif
    
    Row &row = rows[j];
    int offset = row.offset;
    int xmax = row.xmax;
    int done=0;
    
    if (j>=0 && j<=ymax)
	{
	if (i>=offset && i<=offset+xmax)		// is there a cella?
	    {

#ifdef INSTRUMENT_DEBUG
cout << "found cella" << endl;
#endif
	    p.cella=&row.cells[i-offset];
	    p.cellb=p.cella->east;
	    p.cellc=p.cella->north;
	    p.celld=p.cella->neast;
	    p.instrument=this;
	    done=1;
	    }

	else if (i>=offset-1 && i<offset+xmax)		// is there a cellb?
	    {
#ifdef INSTRUMENT_DEBUG
cout << "found cellb" << endl;
#endif
	    p.cellb=&row.cells[i+1-offset];
	    p.cella=p.cellb->west;
	    p.cellc=p.cellb->nwest;
	    p.celld=p.cellb->north;
	    p.instrument=this;
	    done=1;
	    }
	}
	
    if (j>=-1 && j<ymax && !done)
	{
	// try for a cellc or celld

	Row &rowAbove = rows[j+1];
	int offsetAbove = rowAbove.offset;
	int xmaxAbove = rowAbove.xmax;

	if (i>=offsetAbove && i<=offsetAbove+xmaxAbove)
	    {
#ifdef INSTRUMENT_DEBUG
cout << "found cellc" << endl;
#endif
	    p.cellc=&rowAbove.cells[i-offsetAbove];
	    p.cella=p.cellc->south;
	    p.cellb=p.cellc->seast;
	    p.celld=p.cellc->east;
	    p.instrument=this;
	    done=1;
	    }
	    
	else if (i>=offsetAbove-1 && i<offsetAbove+xmaxAbove)	
	    {
#ifdef INSTRUMENT_DEBUG
cout << "found celld" << endl;
#endif
	    p.celld=&rowAbove.cells[i+1-offsetAbove];
	    p.cella=p.celld->swest;
	    p.cellb=p.celld->south;
	    p.cellc=p.celld->west;
	    p.instrument=this;
	    done=1;
	    }
	}
	
    if (!done) 
	{
	p.cella=NULL;
	p.cellb=NULL;
	p.cellc=NULL;
	p.celld=NULL;
	p.instrument=NULL;
	}


#ifdef INSTRUMENT_DEBUG
cout << "i=" << i << " j=" << j << "       ";
cout << "X_=" << p.X_ << " Y_=" << p.Y_ << " X=" << p.X << " Y=" << p.Y << endl;

if (p.cella) {cout << "cella "; cellCount++;}
if (p.cellb) {cout << "cellb "; cellCount++;}
if (p.cellc) {cout << "cellc "; cellCount++;}
if (p.celld) {cout << "celld " << endl; cellCount++;}
#endif

    return p;
    }

TaoAccessPoint &TaoInstrument::point(float x)
    {
    return this->point(x,0.0);
    }           

	       
//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	at(float x, float y)
//
// Functionality:
//	Exactly the same as for operator `(float x, float y)' in that it
//	selects and returns a reference to the cell specified by the
//	instrument coordinates x and y except it doesn't affect the graphics
//	at all.
//////////////////////////////////////////////////////////////////////////////

TaoCell &TaoInstrument::at(float x, float y)
    {
    if (x < 0.0 || x > 1.0 || y < 0.0 || y > 1.0)
	{
	std::cerr << "Tao error: instrument coordinates out of range:" << std::endl;
	std::cerr << this->name << ".at(" << x << "," << y << ")" << std::endl;
	exit(0);
	}
	
    int i=(int)(xmax*x);
    int j=(int)(ymax*y);
    int offset = rows[j].offset;
    TaoCell *c;

    c=&rows[j].cells[i-offset];

    return *c;
    }       
    
void TaoInstrument::placeAbove(TaoInstrument &ref)
    {
    worldx=ref.worldx;
    worldy=ref.worldy + ref.ymax + 5;
    }
    
void TaoInstrument::placeBelow(TaoInstrument &ref)
    {
    worldx=ref.worldx;
    worldy=ref.worldy - ymax - 5;
    }
    
void TaoInstrument::placeRightOf(TaoInstrument &ref)
    {
    worldx=ref.worldx + ref.xmax + 5;
    worldy=ref.worldy;
    }
    
void TaoInstrument::placeLeftOf(TaoInstrument &ref)
    {
    worldx=ref.worldx - xmax - 5;
    worldy=ref.worldy;
    }
    

void TaoInstrument::placeAbove(TaoInstrument &ref, int offsetInWorldCoords)
    {
    worldx=ref.worldx;
    worldy=ref.worldy + ref.ymax + 5 + offsetInWorldCoords;
    }

void TaoInstrument::placeBelow(TaoInstrument &ref, int offsetInWorldCoords)
    {
    worldx=ref.worldx;
    worldy=ref.worldy - ymax - 5 + offsetInWorldCoords;
    }
  
void TaoInstrument::placeRightOf(TaoInstrument &ref, int offsetInWorldCoords)
    {
    worldx=ref.worldx + ref.xmax + 5 + offsetInWorldCoords;
    worldy=ref.worldy;
    }
    
void TaoInstrument::placeLeftOf(TaoInstrument &ref, int offsetInWorldCoords)
    {
    worldx=ref.worldx - xmax - 5 + offsetInWorldCoords;
    worldy=ref.worldy;
    }
    
void TaoInstrument::copyWorldPosition(TaoInstrument &instr)
    {
    worldx=instr.worldx;worldy=instr.worldy;
    }

//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	linkCells()
//
// Functionality:
//	When an instrument is first created the data structures representing
//	the cells, rows and the instrument object are set up. The shape of
//	the instrument and hence the number of rows and number of cells in
//	each row are determined by the particular constructor function of
//	the class derived from the instrument base class. This function
//	sets up the neighbour pointers of all the cells in the instrument,
//	regardless of its shape. In other words it adds the springs,
//	automatically detecting boundaries and making sure that there are no
//	ragged edges. For a more detailed description of the algorithm used
//	see section \ref{linkCells}
//
// Local variables:
//	i, j:	     cell number and row number coordinates (see note at head
//		     of this file).
//	thisrow:     pointer to the current row.
//	northoffset: offset in cells of row above relative to `thisrow'.
//	southoffset: offset in cells of row below relative to `thisrow'.
//	northi:	     `i' always specifies the cell number in a particular row.
//		     Since different rows have different offsets, cell `i' in
//		     thisrow corresponds to cell `northi' in the row above.
//	southi:	     similar to northi.
//	thisxmax:    number of cells - 1 in thisrow.
//	northxmax:   number of cells - 1 in row above thisrow.
//	southxmax:   number of cells - 1 in row below thisrow.
//	c, north, south, east, west:
//		     pointers to current cell and four of its neighbours.
//
// TaoInstrument class member variables:
//	rows, ymax.
//
//////////////////////////////////////////////////////////////////////////////
    
void TaoInstrument::linkCells()
    {
    register int i, j;
    TaoCell *thisrow, *c;
    int northoffset, southoffset, northi, southi;
    int thisxmax, northxmax, southxmax;

    for(j=0;j<=ymax;j++)
	{
	if(j<ymax)
	    {
	    northoffset=rows[j].offset-rows[j+1].offset;
	    northxmax=rows[j+1].xmax;
	    }
	    
	if(j>0)
	    {
	    southoffset=rows[j].offset-rows[j-1].offset;
	    southxmax=rows[j-1].xmax;
	    }

	thisxmax=rows[j].xmax;
	thisrow=rows[j].cells;

	for(i=0;i<=thisxmax;i++)
	    {
	    if(i==0) thisrow[i].west=NULL;
	    else thisrow[i].west=&(thisrow[i-1]);
	    if(i==thisxmax) thisrow[i].east=NULL;
	    else thisrow[i].east=&(thisrow[i+1]);

	    northi=i+northoffset;
	    southi=i+southoffset;

	    if(j==0 || southi<0 || southi>southxmax)
		thisrow[i].south=NULL;
	    else
		thisrow[i].south=&rows[j-1].cells[southi];

	    if(j==ymax || northi<0 || northi>northxmax)
		thisrow[i].north=NULL;
	    else
		thisrow[i].north=&rows[j+1].cells[northi];
	    }
	}

    TaoCell *north, *south, *east, *west;

    for(j=0;j<=ymax;j++)
	{
	for(i=0, c=rows[j].cells;i<=rows[j].xmax;i++, c++)
	    {
	    if(north=c->north)	    c->neast=north->east;
	    else if(east=c->east)   c->neast=east->north;
	    else c->neast=NULL;

	    if(north)	    	    c->nwest=north->west;
	    else if(west=c->west)   c->nwest=west->north;
	    else c->nwest=NULL;
	    
	    if(south=c->south)	    c->seast=south->east;
	    else if(east=c->east)   c->seast=east->south;
	    else c->seast=NULL;

	    if(south)	            c->swest=south->west;
	    else if(west=c->west)   c->swest=west->south;
	    else c->swest=NULL;
/*	    
	    if (c->north) c->mode |= TAO_CELL_NORTH;
	    if (c->nwest) c->mode |= TAO_CELL_NWEST;
	    if (c->west)  c->mode |= TAO_CELL_WEST;
	    if (c->swest) c->mode |= TAO_CELL_SWEST;
	    if (c->south) c->mode |= TAO_CELL_SOUTH;
	    if (c->seast) c->mode |= TAO_CELL_SEAST;
	    if (c->east)  c->mode |= TAO_CELL_EAST;
	    if (c->neast) c->mode |= TAO_CELL_NEAST;
	    
	    if (c->north && c->south && c->east && c->west &&
		c->neast && c->seast && c->nwest && c->swest)
		c->mode |= TAO_CELL_HAS_8_NEIGHBOURS;
*/
	    }
	}
    }



//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	initialiseCells()
//
// Functionality:
//	Since the material is discrete in nature but a continuous range
//	of frequencies is needed, once the width and height of an instrument
//	in cells have been determined, the masses of the cells have to be
//	adjusted slightly away from the default mass in order to adjust the
//	frequency to the originally specified value. This compensation is
//	calculated from the given x frequency since the compensation must
//	work for strings and most 2D instruments are inharmonic in nature, so 
//	the error in yfrequency will not be noticable. Also sets the 
//	velocities, positions and forces of all cells to zero, and 
//	initialises a few other variables.
//
// Local variables:
//	i, j:	    usual use, j=row number and i=cell number in chosen row.
//	intended_freq: xfrequency specified in the instrument decalaration.
//	actual_freq: xfrequency which would result if the cells were given
//		    the default_mass, having decided how many cells wide
//		    and high the instrument is.
//	c:	    pointer to current cell.
//
// TaoInstrument class member variables:
//	rows, ymax.
//////////////////////////////////////////////////////////////////////////////
    
void TaoInstrument::initialiseCells()
    {
    TaoCell *c;
    register int i, j;
    float intendedFreq, actualFreq, compensationFactor;

    defaultVelocityMultiplier = decay2velocityMultiplier(defaultDecay);

#ifdef INSTRUMENT_DEBUG
std::cout << "defaultVelocityMultiplier=" << defaultVelocityMultiplier << std::endl;
#endif
    
    intendedFreq=xfrequency;
    actualFreq=tao.synthesisEngine.Hz2CellConst/(xmax+1);
    compensationFactor=powf(4.0, log10f(actualFreq/intendedFreq)/log10f(2.0));

    for (j=0;j<=ymax;j++)
	{
	for (i=0, c=rows[j].cells;i<=rows[j].xmax;i++, c++)
	    {
	    c->mode=0x0000;		// was TAO_CELL_BOW_STICK_MODE
	    c->companion=NULL;
	    c->mass=TaoInstrument::defaultMass*compensationFactor;
		if(c->mass == 0.0f)
			c->inverseMass = 0.0f;
		else
			c->inverseMass = 1.0f/c->mass;
	    c->position=0.0;
	    c->velocity=0.0;
	    c->force=0.0;
	    c->velocityMultiplier=defaultVelocityMultiplier;
	    }
	}
    }



//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	calculateForces(int startRow, int endRow)
//
// Functionality:
//	Starts at bottom left of instrument and works its way across each
//	row and then up to the next row until it reaches the top right.
//	For each cell the total force due to the springs connecting it to
//	its neighbours is calculated. If the cell is a master cell it
//	treats the slave cell's neighbours as its own in order to calculate
//	the combined force acting on both cells. If it is a slave cell then
//	no calculations are made as these will either already have been
//	performed for the master cell or will be due to be performed for the
//	master cell.
//
// Local variables:
//	i, j:	    j=row number and i=cell number in chosen row.
//	c, north, south, east, west, neast, seast, nwest, swest:
//		    pointers to current cell and its neighbouring cells and
//		    also pointers to slave companion cell's neighours if this
//		    cell has one.
//	companion:  if this cell is glued to another and is acting as the
//		    master cell then `companion' points to the companion
//                  slave cell.
//	myposition: position of the current cell.
//	dp, count:  the force exerted on cell c by a neighbouring cell is
//		    given simply by the neighbouring cell's position minus
//		    c's position, since the coefficient of elasticity is
//		    set to unity. Therefore the total force acting on c
//		    due to all the neighbouring cells is given by the
//		    sum of the positions of the neighbouring cells minus
//		    (number of neighbours * c's position). The variable dp
//		    keeps track of this sum and count keeps track of the
//		    number of neighbours.
//
// TaoInstrument class member variables:
//	rows, ymax.
//////////////////////////////////////////////////////////////////////////////   

/*
void TaoInstrument::calculateForces(int startRow, int endRow)
    {
    register i, j, count;
    register TaoCell *c, *slave, *north, *south, *east, *west;
    register TaoCell *neast, *nwest, *seast, *swest;
    static float myposition,  dp;

#ifdef INSTRUMENT_DEBUG
std::cout << name << ".calculateForces()" << " rows=" << rows << " this=" << this << std::endl;
#endif

    for (j=startRow;j<=endRow;j++)
	for (i=0, c=rows[j].cells;i<=rows[j].xmax;i++, c++)
	    {
	    dp=0.0;myposition=c->position;count=0;

	    if (! (c->mode & TAO_CELL_SLAVE_MODE))
		{
		dp+=
		    ((north=c->north)?(count++,north->position):0.0) +
		    ((south=c->south)?(count++,south->position):0.0) +
		    ((east=c->east)?(count++,east->position):0.0) +
		    ((west=c->west)?(count++,west->position):0.0) +
		    ((neast=c->neast)?(count++,neast->position):0.0) +
		    ((seast=c->seast)?(count++,seast->position):0.0) +
		    ((nwest=c->nwest)?(count++,nwest->position):0.0) +
		    ((swest=c->swest)?(count++,swest->position):0.0);

		if (c->mode & TAO_CELL_MASTER_MODE)
		    {
		    slave=c->companion;
		    dp+=
		    ((north=slave->north)?(count++,north->position):0.0) +
		    ((south=slave->south)?(count++,south->position):0.0) +
		    ((east=slave->east)?(count++,east->position):0.0) +
		    ((west=slave->west)?(count++,west->position):0.0) +
		    ((neast=slave->neast)?(count++,neast->position):0.0) +
		    ((seast=slave->seast)?(count++,seast->position):0.0) +
		    ((nwest=slave->nwest)?(count++,nwest->position):0.0) +
		    ((swest=slave->swest)?(count++,swest->position):0.0);
		    }
		}
	    c->force=dp - count * myposition;
	    }
   }
*/


void TaoInstrument::calculateForces(int startRow, int endRow)
    {
    register int i, j, count;
    register TaoCell *c, *north, *south, *east, *west;
    register TaoCell *neast, *nwest, *seast, *swest;
    static float dp;

    for (j=startRow;j<=endRow;j++)
	for (i=0, c=rows[j].cells;i<=rows[j].xmax;i++, c++)
	    {
	    if (c->mode & TAO_CELL_HAS_8_NEIGHBOURS)
		{
		c->force=
		    (c->north->position+c->south->position+
		    c->east->position+c->west->position+
		    c->neast->position+c->seast->position+
		    c->nwest->position+c->swest->position) - 8.0 * c->position;
		}
		
	    else
		{
		dp=0.0;count=0;
		
		if (north=c->north) {count++; dp+=north->position;}
		if (south=c->south) {count++; dp+=south->position;}
		if (east=c->east)   {count++; dp+=east->position;}
		if (west=c->west)   {count++; dp+=west->position;}
		if (neast=c->neast) {count++; dp+=neast->position;}
		if (seast=c->seast) {count++; dp+=seast->position;}
		if (nwest=c->nwest) {count++; dp+=nwest->position;}
		if (swest=c->swest) {count++; dp+=swest->position;}
		
		c->force=dp - count * c->position;
		}
	    }
   }

/*
void TaoInstrument::calculateForces(int startRow, int endRow)
    {
    register int i, j;
    static TaoCell *c, *slave, *north, *south, *east, *west;
    static TaoCell *neast, *nwest, *seast, *swest;
    
    static float cellPosition,  distance;
    static float *cellForce;
    
    for (j=startRow;j<=endRow;j++)
	for (i=0, c=rows[j].cells; i<=rows[j].xmax; i++, c++)
	    {
	    cellPosition=c->position;
	    cellForce=&c->force;
	    
	    if (north=c->north)
		{
		distance=north->position-cellPosition;
		*cellForce+=distance;
		north->force-=distance;
		}
		
	    if (neast=c->neast)
		{
		distance=neast->position-cellPosition;
		*cellForce+=distance;
		neast->force-=distance;
		}

	    if (nwest=c->nwest)
		{
		distance=nwest->position-cellPosition;
		*cellForce+=distance;
		nwest->force-=distance;
		}

	    if (east=c->east)
		{
		distance=east->position-cellPosition;
		*cellForce+=distance;
		east->force-=distance;
		}

	    if (c->mode & TAO_CELL_MASTER_MODE)
		{
		slave=c->companion;
		if (north=slave->north)
		    *cellForce+=north->position-cellPosition;

		if (south=slave->south)
		    *cellForce+=south->position-cellPosition;

		if (east=slave->east)
		    *cellForce+=east->position-cellPosition;

		if (west=slave->west)
		    *cellForce+=west->position-cellPosition;

		if (neast=slave->neast)
		    *cellForce+=neast->position-cellPosition;

		if (nwest=slave->nwest)
		    *cellForce+=nwest->position-cellPosition;

		if (seast=slave->seast)
		    *cellForce+=seast->position-cellPosition;

		if (swest=slave->swest)
		    *cellForce+=swest->position-cellPosition;
		}
	    }
    }
*/

//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	calculatePositions(int startRow, int endRow)
//
// Functionality:
//	Starts at bottom left of instrument and works its way across each
//	row and then up to the next row until it reaches the top right.
//	The force acting upon each cell is used to calculate the cells
//	acceleration, new velocity and new position. Also multiplies the
//	new velocity by the velocityMultiplier value (between 0 and 1). This value is
//	converted from the percentage value given in a TAO script. 100% -> 0
//	and 0% -> 1.
//
// Local variables:
//	i, j:	    j=row number and i=cell number in chosen row.
//	c:	    pointer to current cell.
//
// TaoInstrument class member variable:
//	rows.
//////////////////////////////////////////////////////////////////////////////

/*
void TaoInstrument::calculatePositions(int startRow, int endRow)
    {
    static int i, j;
    static TaoCell *c;

    for (j=startRow;j<=endRow;j++)
	for (i=0, c=rows[j].cells;i<=rows[j].xmax; i++, c++)
	    {
	    if(!(c->mode & TAO_CELL_LOCK_MODE || c->mode & TAO_CELL_SLAVE_MODE))
		{
		c->velocity+=c->force/c->mass;
		c->velocity*=c->velocityMultiplier;
	    	c->position+=c->velocity;
		}
	    if(c->mode & TAO_CELL_MASTER_MODE)
		{
		c->companion->force=c->force;
		c->companion->velocity=c->velocity;
		c->companion->position=c->position;
		}
	    }
    }
*/


void TaoInstrument::calculatePositions(int startRow, int endRow)
    {
    static int i, j;
    static TaoCell *c;

    for (j=startRow;j<=endRow;j++)
	for (i=0, c=rows[j].cells;i<=rows[j].xmax; i++, c++)
	    {
	    if(!(c->mode & TAO_CELL_LOCK_MODE))
		{
			//This speeds up the pitches example by about 3 seconds.
			//(it takes ~10s as opposed to ~13s - still not up to realtime though;
			//the score in pitches is 5s long)
			c->velocity+=c->force*c->inverseMass;
			//c->velocity+=c->force/c->mass;
			c->velocity*=c->velocityMultiplier;
	    	c->position+=c->velocity;
		}
	    }
    }


TaoInstrument &
TaoInstrument::setMagnification(float m)
    {amplification=m; return *this;}

float 
TaoInstrument::getMagnification()
    {return amplification;}

TaoInstrument &
TaoInstrument::setDamping(float x1,float x2,float y1,float y2,float damping)
    {
    float tmp;
    int i1, i2, j1, j2, imin, imax;
    register int i, j;

    if (x1>x2) {tmp=x1;x1=x2;x2=tmp;}
    if (y1>y2) {tmp=y1;y1=y2;y2=tmp;}
    
    i1=(int)(x1*xmax);
    i2=(int)(x2*xmax);
    j1=(int)(y1*ymax);
    j2=(int)(y2*ymax);
    
    for (j=j1;j<=j2;j++)
	{
	imin=rows[j].offset;
	imax=rows[j].offset+rows[j].xmax;
	
	for (i=i1;i<=i2;i++)
	    {
	    if (i>=imin && i<=imax)
		{
		rows[j].cells[i-imin].velocityMultiplier=
		    1-((float)pow(10000.0f,damping)/10000.0);
		}
	    }
	}
    return *this;
    }

TaoInstrument &
TaoInstrument::setDamping(float left, float right, float damping)
    {
    float tmp;
    int i1, i2, imin, imax;
    register int i;
    
    if (left>right) {tmp=left;left=right;right=tmp;}

    i1=(int)(left*xmax);
    i2=(int)(right*xmax);
    
    imin=rows[0].offset;
    imax=rows[0].offset+rows[0].xmax;
	
    for (i=i1;i<=i2;i++)
	{
	if (i>=imin && i<=imax)
	    {
	    rows[0].cells[i-imin].velocityMultiplier=
		1-((float)pow(10000.0f,damping)/10000.0);
	    }
	}
    return *this;
    }



TaoInstrument &
TaoInstrument::setDamping(float position, float damping)
    {
    int i;
    
    i=(int)(position*rows[0].xmax);
    rows[0].cells[i].velocityMultiplier=1-((float)pow(10000.0f,damping)/10000.0);

    return *this;    
    }
     
TaoInstrument &
TaoInstrument::setDamping(float damping)
    {
    setDamping(0.0, 1.0, 0.0, 1.0, damping);
    return *this;
    }    

TaoInstrument &
TaoInstrument::resetDamping(float x1,float x2,float y1,float y2)
    {
    float tmp;
    int i1, i2, j1, j2, imin, imax;
    register int i, j;

    if (x1>x2) {tmp=x1;x1=x2;x2=tmp;}
    if (y1>y2) {tmp=y1;y1=y2;y2=tmp;}
    
    i1=(int)(x1*xmax);
    i2=(int)(x2*xmax);
    j1=(int)(y1*ymax);
    j2=(int)(y2*ymax);
    
    for (j=j1;j<=j2;j++)
	{
	imin=rows[j].offset;
	imax=rows[j].offset+rows[j].xmax;
	
	for (i=i1;i<=i2;i++)
	    {
	    if (i>=imin && i<=imax)
		{
		rows[j].cells[i-imin].velocityMultiplier=
		    defaultVelocityMultiplier;
		}
	    }
	}
    return *this;
    }

TaoInstrument &
TaoInstrument::resetDamping(float left, float right)
    {
    float tmp;
    int i1, i2, imin, imax;
    register int i;
    
    if (left>right) {tmp=left;left=right;right=tmp;}

    i1=(int)(left*xmax);
    i2=(int)(right*xmax);
    
    imin=rows[0].offset;
    imax=rows[0].offset+rows[0].xmax;
	
    for (i=i1;i<=i2;i++)
	{
	if (i>=imin && i<=imax)
	    {
	    rows[0].cells[i-imin].velocityMultiplier=
		defaultVelocityMultiplier;
	    }
	}
    return *this;
    }

TaoInstrument &
TaoInstrument::resetDamping(float position)
    {
    int i;
    
    i=(int)(position*rows[0].xmax);
    rows[0].cells[i].velocityMultiplier=defaultVelocityMultiplier;

    return *this;    
    }


TaoInstrument &
TaoInstrument::resetDamping()
    {
    resetDamping(0.0,1.0,0.0,1.0);
    }    



//////////////////////////////////////////////////////////////////////////////
// Member function names:
//	setDecay(float x1, float x2, float y1, float y2, float decay)
//	setDecay(float left, float right, float decay)
//	setDecay(float decay)
//
// Functionality:
//	Equivalent to the setDamping family of functions above, but set the
//	damping value in terms of a decay time measured in seconds. At the
//	moment the results of setting a particular decay time for a particular
//	region are not fully understood and these functions need to be updated
//	to provide more predictable results for any shape of size of
//	instrument and any region of damping.
//
// Returns:
//	A reference to the cell for whom the function was invoked.
//
// TaoInstrument class member functions:
//	setDamping(float x1, float x2, float y1, float y2, damping),
//	decay2velocityMultiplier(float decay).
//////////////////////////////////////////////////////////////////////////////

TaoInstrument &
TaoInstrument::setDecay(float x1,float x2,float y1,float y2,float decay)
    {
    setDamping(x1, x2, y1, y2, decay2velocityMultiplier(decay));
    return *this;
    }


TaoInstrument &
TaoInstrument::setDecay(float left, float right, float decay)
    {
    setDamping(left, right, 0.0, 0.0, decay2velocityMultiplier(decay));
    return *this;
    }

TaoInstrument &
TaoInstrument::setDecay(float decay)
    {
    setDamping(0.0, 1.0, 0.0, 1.0, decay2velocityMultiplier(decay));
    return *this;
    }    



//////////////////////////////////////////////////////////////////////////////
// Member function names:
//	resetDecay(float x1, float x2, float y1, float y2)
//	resetDecay(float left, float right)
//	resetDecay()
//
// Functionality:
//	Equivalent to the resetDamping family of functions above, included
//	only for consistency and compatibility.
//
// Returns:
//	A reference to the cell for whom the function was invoked.
//
// TaoInstrument class member variable:
//	defaultVelocityMultiplier.
//
// TaoInstrument class member function:
//	setDamping(float x1, float x2, float y1, float y2, damping).
//////////////////////////////////////////////////////////////////////////////

TaoInstrument &TaoInstrument::resetDecay(float x1,float x2,float y1,float y2)
    {
    resetDamping(x1, x2, y1, y2);
    return *this;
    }


TaoInstrument &
TaoInstrument::resetDecay(float left, float right)
    {
    resetDamping(left, right);
    return *this;
    }
    
TaoInstrument &
TaoInstrument::resetDecay()
    {
    resetDamping(0.0, 1.0, 0.0, 1.0);
    return *this;
    }



//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	lock(float x, float y)
//
// Functionality:
//	Locks a single point at (x,y) on an instrument.
//
// Returns:
//	A reference to the cell for whom the function was invoked.
//
// Local variables:
//	i, j:	    j=row number, i=cell number in that row.
//
// TaoInstrument class member variables:
//	rows.	
//////////////////////////////////////////////////////////////////////////////

TaoInstrument &
TaoInstrument::lock(float x, float y)
    {
    int i, j;
            
    j=(int)(y*ymax);
    i=(int)(x*rows[j].xmax);

    rows[j].cells[i].mode |= TAO_CELL_LOCK_MODE;

    return *this;
    }



//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	lock(float x1, float x2, float y1, float y2)
//
// Functionality:
//	Locks a rectangular region. Similar to setDamping(x1, x2, y1, y2, ...)
//	in the coordinate system used to specify the region.
//
// Returns:
//	A reference to the cell for whom the function was invoked.
//
// Local variables:
//	i1, i2, j1, j2:	    j1=bottom row number, j2=top row number,
//			    i1=left cell number, i2=right cell number.
//	imin, imax:	    minimum and maximum values of i respectively
//			    for the instrument in question.
//	i, j:		    j=row number, i=cell number.
//
// TaoInstrument class member variables:
//	rows.	
//////////////////////////////////////////////////////////////////////////////

TaoInstrument &
TaoInstrument::lock(float x1, float x2, float y1, float y2)
    {
    int i1, i2, j1, j2, imin, imax;
    register int i, j;
    
    i1=(int)(x1*xmax);
    i2=(int)(x2*xmax);
    j1=(int)(y1*ymax);
    j2=(int)(y2*ymax);
    
    for (j=j1;j<=j2;j++)
	{
	imin=rows[j].offset;
	imax=rows[j].offset+rows[j].xmax;
	
	for (i=i1;i<=i2;i++)
	    {
	    if (i>=imin && i<=imax)
		{
		rows[j].cells[i-imin].mode |= TAO_CELL_LOCK_MODE;
		}
	    }
	}
    return *this;
    }



//////////////////////////////////////////////////////////////////////////////
// Member function names:
//	lockLeft():	    locks the leftmost cells in an instrument
//	lockRight():	    locks the rightmost cells in an instrument
//	lockTop():	    locks the topmost cells in an instrument
//	lockBottom():	    locks the bottommost cells in an instrument
//	lockCorners():	    only meaningful for rectangular and triangular
//			    instruments.
//	lockPerimeter():    self-explanatory
//	lockEnds():	    designed for 1D instruments.
//
// Functionality:
//	Lock various specific regions of an instrument.
//
// Return:
//	A reference to the cell for whom the function was invoked.
//
// Local variables:
//	i, j:		    j=row number, i=cell number.
//
// TaoInstrument class member variables:
//	rows.	
//////////////////////////////////////////////////////////////////////////////

TaoInstrument &
TaoInstrument::lockLeft()
    {
    register int j;
    
    for(j=0;j<=ymax;j++)
	if(rows[j].offset==0)
	    rows[j].cells[0].mode |= TAO_CELL_LOCK_MODE;
    
    return *this;
    }   

TaoInstrument &
TaoInstrument::lockRight()
    {
    register int j;
    
    for(j=0;j<=ymax;j++)
	if(rows[j].offset+rows[j].xmax==xmax)
	    rows[j].cells[rows[j].xmax].mode |= TAO_CELL_LOCK_MODE;

    return *this;
    }

TaoInstrument &TaoInstrument::lockTop()
    {
    register int i;
    
    for(i=0;i<=rows[ymax].xmax;i++)
	rows[ymax].cells[i].mode |= TAO_CELL_LOCK_MODE;
    
    return *this;
    }   

TaoInstrument &
TaoInstrument::lockBottom()
    {
    register int i;
    
    for(i=0;i<=rows[0].xmax;i++)
	rows[0].cells[i].mode |= TAO_CELL_LOCK_MODE;

    return *this;
    }


TaoInstrument &
TaoInstrument::lockPerimeter()
    {
    register int j;
    
    lockTop();
    lockBottom();

    perimeterLocked=1;    // This is only used by TaoGraphicsEngine to decide
			  // the most aesthetically pleasing way to render the
			  // locked cells. Having little black blobs all the way
			  // around the edge of an instrument looks ugly.  
    for(j=0;j<=ymax;j++)
	rows[j].cells[0].mode |= TAO_CELL_LOCK_MODE;

    for(j=0;j<=ymax;j++)
	rows[j].cells[rows[j].xmax].mode |= TAO_CELL_LOCK_MODE;
    
    return *this;
    }

TaoInstrument &
TaoInstrument::lockCorners()
    {
    lock(0.0, 0.0);
    lock(1.0, 0.0);
    lock(0.0, 1.0);
    lock(1.0, 1.0);
    return *this;
    }
    
TaoInstrument &
TaoInstrument::lockEnds()
    {
    lockLeft();
    lockRight();
    return *this;
    }


//////////////////////////////////////////////////////////////////////////////
// Member function names:
//	glue(TaoInstrument &i1, float x1, float y1,	// glue 2D to 2D	
//		TaoInstrument &i2, float x2, float y2)
//	glue(TaoInstrument &i1, float x1, float y1,	// glue 2D to 1D
//		TaoInstrument &i2, float x2)
//	glue(TaoInstrument &i1, float x1,			// glue 1D to 2D
//		TaoInstrument &i2, float x2, float y2)
//	glue(TaoInstrument &i1, float x1,			// glue 1D to 1D
//		TaoInstrument &i2, float x2)
//
// Functionality:
//	Given two instruments and sets of coordinates for selecting two
//	cells, glues them and their corresponding neighbours together. 
//
// Return:
//	A reference to the cell for whom the function was invoked.
//
// TaoInstrument class member function:
//	glueCells(TaoCell *c1, TaoCell *c2).
//////////////////////////////////////////////////////////////////////////////

void
TaoInstrument::glue(TaoInstrument &i1, float x1, float y1,
                      TaoInstrument &i2, float x2, float y2)
    {
    static TaoCell *c1, *c2;
    
    c1=&i1.at(x1, y1);
    c2=&i2.at(x2, y2);
    
    TaoInstrument::glueCells(c1, c2);
    TaoInstrument::glueCells(c1->east, c2->east);
    TaoInstrument::glueCells(c1->west, c2->west);
    TaoInstrument::glueCells(c1->north, c2->north);
    TaoInstrument::glueCells(c1->south, c2->south);
    TaoInstrument::glueCells(c1->neast, c2->neast);
    TaoInstrument::glueCells(c1->nwest, c2->nwest);
    TaoInstrument::glueCells(c1->seast, c2->seast);
    TaoInstrument::glueCells(c1->swest, c2->swest);
    } 

void
TaoInstrument::glue(TaoInstrument &i1, float x1, float y1,
                      TaoInstrument &i2, float x2)
    {
    static TaoCell *c1, *c2;
    
    c1=&i1.at(x1, y1);
    c2=&i2.at(x2, 0.0);
    
    TaoInstrument::glueCells(c1, c2);
    TaoInstrument::glueCells(c1->east, c2->east);
    TaoInstrument::glueCells(c1->west, c2->west);
    } 

void TaoInstrument::glue(TaoInstrument &i1, float x1,
                      TaoInstrument &i2, float x2, float y2)
    {
    static TaoCell *c1, *c2;
    
    c1=&i1.at(x1, 0.0);
    c2=&i2.at(x2, y2);

    TaoInstrument::glueCells(c1, c2);
    TaoInstrument::glueCells(c1->east, c2->east);
    TaoInstrument::glueCells(c1->west, c2->west);
    if (x1<0.5) 
	i1.placeAt(i2.worldx+i2.xmax+10, (int)(i2.worldy+i2.ymax*y2));
    else
	i1.placeAt(i2.worldx-i1.xmax-10, (int)(i2.worldy+i2.ymax*y2));
    } 

void TaoInstrument::glue(TaoInstrument &i1, float x1,
                      TaoInstrument &i2, float x2)
    {
    static TaoCell *c1, *c2;
    
    c1=&i1.at(x1, 0.0);
    c2=&i2.at(x2, 0.0);

    TaoInstrument::glueCells(c1, c2);
    TaoInstrument::glueCells(c1->east, c2->east);
    TaoInstrument::glueCells(c1->west, c2->west);
    } 



//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	glueCells(TaoCell *c1, TaoCell *c2)
//
// Functionality:
//	Given pointers to two cells, glues the cells together. 
//////////////////////////////////////////////////////////////////////////////

void TaoInstrument::glueCells(TaoCell *c1, TaoCell *c2)
    {
    if (!c1 || !c2) return;
    
    c1->companion=c2;
    c2->companion=c1;
    c1->mode |= TAO_CELL_MASTER_MODE;
    c2->mode |= TAO_CELL_SLAVE_MODE;
    }



//////////////////////////////////////////////////////////////////////////////
// Member function name:
//	join(TaoInstrument &i1, float x1, float y1,	
//	     TaoInstrument &i2, float x2, float y2)
//
// Functionality:
//	Joins two pieces of material with straight edges by effectively
//	installing a new set of springs to sew the two instruments together
//	so that they act as one. There are eight different cases:-
//
//	(1) if x1=0: if x2=0: join the left of i1 to the left of i2
//		     if x2=1: join the left of i1 to the right of i2
//	(2) if x1=1: if x2=0: join the right of i1 to the left of i2
//		     if x2=1: join the right of i1 to the right of i2
//	(3) if y1=0: if y2=0: join the bottom of i1 to the bottom of i2
//		     if y2=1: join the bottom of i1 to the top of i2
//	(2) if y1=1: if y2=0: join the top of i1 to the bottom of i2
//		     if y2=1: join the top of i1 to the top of i2
//
//	If we are joining horizontally then y1 and y2 serve to specify a
//	centre line at which the joining should begin and conversely if we
//	are joining vertically x1 and x2 specify a centre line. Once again
//	x1, x2, y1 and y2 are all specified as instrument coordinates.
//	For an explanation of the join parameters see section \ref{join_impl}.
//	Note that i1 and i2 can refer to the same instrument making it
//	possible to construct cylindrical and toroidal instruments from a
//	rectangular sheet.
//
// TaoInstrument class member function:
//	joinLeftToLeft(TaoCell &cell1, TaoCell &cell2),
//	joinLeftToRight(TaoCell &cell1, TaoCell &cell2),
//	joinRightToLeft(TaoCell &cell1, TaoCell &cell2),
//	joinRightToRight(TaoCell &cell1, TaoCell &cell2),
//	joinBottomToBottom(TaoCell &cell1, TaoCell &cell2),
//	joinBottomToTop(TaoCell &cell1, TaoCell &cell2),
//	joinTopToBottom(TaoCell &cell1, TaoCell &cell2),
//	joinTopToTop(TaoCell &cell1, TaoCell &cell2),
//////////////////////////////////////////////////////////////////////////////

/* this is the old version

void TaoInstrument::join(TaoInstrument &i1, float x1, float y1,
                      TaoInstrument &i2, float x2, float y2)
    {
    if (x1==0.0f)
	{
	if (x2==0.0f)
	    {
	    TaoInstrument::joinLeftToLeft(i1.at(x1, y1), i2.at(x2, y2));
	    }
	else if (x2==1.0f)
	    {
	    TaoInstrument::joinLeftToRight(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=i1.worldx-(i2.xmax+1);
	    i2.worldy=(int)(i1.worldy+i1.ymax*y1-i2.ymax*y2);
	    }
	}
    else if (x1==1.0f)
	{
	if (x2==0.0f)
	    {
	    TaoInstrument::joinRightToLeft(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=i1.worldx+(i1.xmax+1);
	    i2.worldy=(int)(i1.worldy+i1.ymax*y1-i2.ymax*y2);
	    }
	else if (x2==1.0f)
	    {
	    TaoInstrument::joinRightToRight(i1.at(x1, y1), i2.at(x2, y2));
	    }
	}
    else if (y1==0.0f)
	{
	if (y2==0.0f)
	    {
	    TaoInstrument::joinBottomToBottom(i1.at(x1, y1), i2.at(x2, y2));
	    }
	else if (y2==1.0f)
	    {
	    TaoInstrument::joinBottomToTop(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=(int)(i1.worldx+i1.xmax*x1-i2.xmax*x2);
	    i2.worldy=i1.worldy-(i2.ymax+1);
	    }
	}
    else if (y1==1.0f)
	{
	if (y2==0.0f)
	    {
	    TaoInstrument::joinTopToBottom(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=(int)(i1.worldx+i1.xmax*x1-i2.xmax*x2);
	    i2.worldy=i1.worldy+(i1.ymax+1);
	    }
	else if (y2==1.0f)
	    {
	    TaoInstrument::joinTopToTop(i1.at(x1, y1), i2.at(x2, y2));
	    }
	}
    }
*/


void TaoInstrument::join(TaoAccessPoint &a1, TaoAccessPoint &a2)
    {
    float &x1=a1.x, &y1=a1.y, &x2=a2.x, &y2=a2.y;
    TaoInstrument &i1=*a1.instrument;
    TaoInstrument &i2=*a2.instrument;    

    if (x1==0.0f)
	{
	if (x2==0.0f)
	    {
	    TaoInstrument::joinLeftToLeft(i1.at(x1, y1), i2.at(x2, y2));
	    }
	else if (x2==1.0f)
	    {
	    TaoInstrument::joinLeftToRight(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=i1.worldx-(i2.xmax+1);
	    i2.worldy=(int)(i1.worldy+i1.ymax*y1-i2.ymax*y2);
	    }
	}
    else if (x1==1.0f)
	{
	if (x2==0.0f)
	    {
	    TaoInstrument::joinRightToLeft(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=i1.worldx+(i1.xmax+1);
	    i2.worldy=(int)(i1.worldy+i1.ymax*y1-i2.ymax*y2);
	    }
	else if (x2==1.0f)
	    {
	    TaoInstrument::joinRightToRight(i1.at(x1, y1), i2.at(x2, y2));
	    }
	}
    else if (y1==0.0f)
	{
	if (y2==0.0f)
	    {
	    TaoInstrument::joinBottomToBottom(i1.at(x1, y1), i2.at(x2, y2));
	    }
	else if (y2==1.0f)
	    {
	    TaoInstrument::joinBottomToTop(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=(int)(i1.worldx+i1.xmax*x1-i2.xmax*x2);
	    i2.worldy=i1.worldy-(i2.ymax+1);
	    }
	}
    else if (y1==1.0f)
	{
	if (y2==0.0f)
	    {
	    TaoInstrument::joinTopToBottom(i1.at(x1, y1), i2.at(x2, y2));
	    i2.worldx=(int)(i1.worldx+i1.xmax*x1-i2.xmax*x2);
	    i2.worldy=i1.worldy+(i1.ymax+1);
	    }
	else if (y2==1.0f)
	    {
	    TaoInstrument::joinTopToTop(i1.at(x1, y1), i2.at(x2, y2));
	    }
	}
    }

//////////////////////////////////////////////////////////////////////////////
// Member function names:
//	joinLeftToLeft(TaoCell &cell1, TaoCell &cell2)
//	joinLeftToRight(TaoCell &cell1, TaoCell &cell2)
//	joinRightToLeft(TaoCell &cell1, TaoCell &cell2)
//	joinRightToRight(TaoCell &cell1, TaoCell &cell2)
//	joinBottomToBottom(TaoCell &cell1, TaoCell &cell2)
//	joinBottomToTop(TaoCell &cell1, TaoCell &cell2)
//	joinTopToBottom(TaoCell &cell1, TaoCell &cell2)
//	joinTopToTop(TaoCell &cell1, TaoCell &cell2)
//
// Functionality:
//	Join two pieces of material with straight edges by effectively
//	installing a new set of springs to sew the two instruments together
//	so that they act as one. Joining starts at the two cells specified
//	and migrates along the edges of the two pieces of material in one
//	direction until a boundary is reached. Then back to the starting
//	cells to migrate in the opposite direction.
//////////////////////////////////////////////////////////////////////////////

void TaoInstrument::joinLeftToLeft(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate northwards until a boundary is reached.
    
    while (c1 && c2)
	{
	c1->west=c2;
	c1->nwest=c2->north;
	c1->swest=c2->south;
	c2->west=c1;
	c2->nwest=c1->north;
	c2->swest=c1->south;
	
	c1=c1->north; if (c1==&cell1) break;
	c2=c2->north; if (c2==&cell2) break;
	}
    
    if (c1) c1->swest=c1->south->west;
    if (c2) c2->swest=c2->south->west;

    c1=&cell1; c2=&cell2;

// back to starting position and migrate southwards
    
    while (c1 && c2)
	{
	c1->west=c2;
	c1->nwest=c2->north;
	c1->swest=c2->south;
	c2->west=c1;
	c2->nwest=c1->north;
	c2->swest=c1->south;
	
	c1=c1->south; if (c1==&cell1) break;
	c2=c2->south; if (c2==&cell2) break;
	}      

    if (c1) c1->nwest=c1->north->west;
    if (c2) c2->nwest=c2->north->west;
    }


void TaoInstrument::joinLeftToRight(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate northwards until a boundary is reached.
    
    while (c1 && c2)
	{
	c1->west=c2;
	c1->nwest=c2->north;
	c1->swest=c2->south;
	c2->east=c1;
	c2->neast=c1->north;
	c2->seast=c1->south;
	
	c1=c1->north; if (c1==&cell1) break;
	c2=c2->north; if (c2==&cell2) break;
	}   

    if (c1) c1->swest=c1->south->west;
    if (c2) c2->seast=c2->south->east;
    
    c1=&cell1; c2=&cell2;
    
// back to starting position and migrate southwards
    
    while (c1 && c2)
	{
	c1->west=c2;
	c1->nwest=c2->north;
	c1->swest=c2->south;
	c2->east=c1;
	c2->neast=c1->north;
	c2->seast=c1->south;
	
	c1=c1->south; if (c1==&cell1) break;
	c2=c2->south; if (c2==&cell2) break;
	}   

    if (c1) c1->nwest=c1->north->west;
    if (c2) c2->neast=c2->north->east;
    }


void TaoInstrument::joinRightToLeft(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate northwards until a boundary is reached.
    
    while (c1 && c2)
	{
	c1->east=c2;
	c1->neast=c2->north;
	c1->seast=c2->south;
	c2->west=c1;
	c2->nwest=c1->north;
	c2->swest=c1->south;
	
	c1=c1->north; if (c1==&cell1) break;
	c2=c2->north; if (c2==&cell2) break;
	}   

    if (c1) c1->seast=c1->south->east;
    if (c2) c2->swest=c2->south->west;

    c1=&cell1; c2=&cell2;
    
// back to starting position and migrate southwards
    
    while (c1 && c2)
	{
	c1->east=c2;
	c1->neast=c2->north;
	c1->seast=c2->south;
	c2->west=c1;
	c2->nwest=c1->north;
	c2->swest=c1->south;
	
	c1=c1->south; if (c1==&cell1) break;
	c2=c2->south; if (c2==&cell2) break;
	}
    
    if (c1) c1->neast=c1->north->east;
    if (c2) c2->nwest=c2->north->west;
    }
    

void TaoInstrument::joinRightToRight(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate northwards until a boundary is reached.
    
    while (c1 && c2)
	{
	c1->east=c2;
	c1->neast=c2->north;
	c1->seast=c2->south;
	c2->east=c1;
	c2->neast=c1->north;
	c2->seast=c1->south;
	
	c1=c1->north; if (c1==&cell1) break;
	c2=c2->north; if (c2==&cell2) break;
	}   

    if (c1) c1->seast=c1->south->east;
    if (c2) c2->seast=c2->south->east;

    c1=&cell1; c2=&cell2;
    
// back to starting position and migrate southwards
    
    while (c1 && c2)
	{
	c1->east=c2;
	c1->neast=c2->north;
	c1->seast=c2->south;
	c2->east=c1;
	c2->neast=c1->north;
	c2->seast=c1->south;
	
	c1=c1->south; if (c1==&cell1) break;
	c2=c2->south; if (c2==&cell2) break;
	}   
    
    if (c1) c1->neast=c1->north->east;
    if (c2) c2->neast=c2->north->east;
    }


void TaoInstrument::joinBottomToBottom(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate eastwards until a boundary is reached

    while (c1 && c2)
	{
	c1->south=c2;
	c1->seast=c2->east;
	c1->swest=c2->west;
	c2->south=c1;
	c2->seast=c1->east;
	c2->swest=c1->west;
	
	c1=c1->east; if (c1==&cell1) break;
	c2=c2->east; if (c2==&cell2) break;
	}   

    if (c1) c1->swest=c1->west->south;
    if (c2) c2->swest=c2->west->south;

// back to starting position and migrate westwards

    c1=&cell1; c2=&cell2;
    
    while (c1 && c2)
	{
	c1->south=c2;
	c1->seast=c2->east;
	c1->swest=c2->west;
	c2->south=c1;
	c2->seast=c1->east;
	c2->swest=c1->west;
	
	c1=c1->west; if (c1==&cell1) break;
	c2=c2->west; if (c2==&cell2) break;
	}   

    if (c1) c1->seast=c1->east->south;
    if (c2) c2->seast=c2->east->south;
    }


void TaoInstrument::joinBottomToTop(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate eastwards until a boundary is reached

    while (c1 && c2)
	{
	c1->south=c2;
	c1->seast=c2->east;
	c1->swest=c2->west;
	c2->north=c1;
	c2->neast=c1->east;
	c2->nwest=c1->west;
	
	c1=c1->east; if (c1==&cell1) break;
	c2=c2->east; if (c2==&cell2) break;
	}   
    
    if (c1) c1->swest=c1->west->south;
    if (c2) c2->nwest=c2->west->north;

    c1=&cell1; c2=&cell2;
    
// back to starting position and migrate westwards

    while (c1 && c2)
	{
	c1->south=c2;
	c1->seast=c2->east;
	c1->swest=c2->west;
	c2->north=c1;
	c2->neast=c1->east;
	c2->nwest=c1->west;
	
	c1=c1->west; if (c1==&cell1) break;
	c2=c2->west; if (c2==&cell2) break;
	}   

    if (c1) c1->seast=c1->east->south;
    if (c2) c2->neast=c2->east->north;
    }


void TaoInstrument::joinTopToBottom(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate eastwards until a boundary is reached

    while (c1 && c2)
	{
	c1->north=c2;
	c1->neast=c2->east;
	c1->nwest=c2->west;
	c2->south=c1;
	c2->seast=c1->east;
	c2->swest=c1->west;
	
	c1=c1->east; if (c1==&cell1) break;
	c2=c2->east; if (c2==&cell2) break;
	}   

    if (c1) c1->nwest=c1->west->north;
    if (c2) c2->swest=c2->west->south;

    c1=&cell1; c2=&cell2;
    
// back to starting position and migrate westwards

    while (c1 && c2)
	{
	c1->north=c2;
	c1->neast=c2->east;
	c1->nwest=c2->west;
	c2->south=c1;
	c2->seast=c1->east;
	c2->swest=c1->west;
	
	c1=c1->west; if (c1==&cell1) break;
	c2=c2->west; if (c2==&cell2) break;
	}   

    if (c1) c1->neast=c1->east->north;
    if (c2) c2->seast=c2->east->south;
    }


void TaoInstrument::joinTopToTop(TaoCell &cell1, TaoCell &cell2)
    {
    TaoCell *c1=&cell1, *c2=&cell2;

// migrate eastwards until a boundary is reached

    while (c1 && c2)
	{
	c1->north=c2;
	c1->neast=c2->east;
	c1->nwest=c2->west;
	c2->north=c1;
	c2->neast=c1->east;
	c2->nwest=c1->west;
	
	c1=c1->east; if (c1==&cell1) break;
	c2=c2->east; if (c2==&cell2) break;
	}   

    if (c1) c1->neast=c1->east->north;
    if (c2) c2->neast=c2->east->north;

    c1=&cell1; c2=&cell2;
    
// back to starting position and migrate westwards

    while (c1 && c2)
	{
	c1->north=c2;
	c1->neast=c2->east;
	c1->nwest=c2->west;
	c2->north=c1;
	c2->neast=c1->east;
	c2->nwest=c1->west;
	
	c1=c1->west; if (c1==&cell1) break;
	c2=c2->west; if (c2==&cell2) break;
	}   

    if (c1) c1->nwest=c1->west->north;
    if (c2) c2->nwest=c2->west->north;
    }


float TaoInstrument::decay2velocityMultiplier(float decay)
    {
    return (1.0-(tao.synthesisEngine.Decay2VelocityMultiplierConst/decay));
    }


int TaoInstrument::hertz2cells(float freq)
    {
    if(freq==0.0) return 1;
    return (int)(tao.synthesisEngine.Hz2CellConst/freq);
    }
