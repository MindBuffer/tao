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

extern "C" 
{
#include <unistd.h>
}

#include "TaoGraphicsEngine.h"
#include "Tao.h"
#include "TaoCell.h"
#include "TaoInstrument.h"
#include "TaoAccessPoint.h"
#include "TaoDevice.h"
#include <string>
    
extern Tao tao;
extern void taoMasterTick();

// These variables are declared extern by the getopt() function, which
// is used to parse the command line arguments sent to the graphics
// engine. They therefore have to be defined here.

extern char *optarg;
extern int optind, opterr, optopt;

// The following global functions are registered callbacks for OpenGL.

void tao_visibility(int state)
    {
    if (state==GLUT_NOT_VISIBLE) tao.graphicsEngine.active=FALSE;
    if (state==GLUT_VISIBLE)
	{
	glutIdleFunc(taoMasterTick);
	tao.graphicsEngine.active=TRUE;
	}
    }
    
void tao_mouse(int button, int state, int x, int y)
    {
    tao.graphicsEngine.mouse(button, state, x, y);
    }

void tao_motion(int x, int y)
    {
    tao.graphicsEngine.motion(x, y);
    }

void tao_display()
    {
    tao.graphicsEngine.display();
    }
 
void tao_reshape(int w, int h)
    {
    tao.graphicsEngine.reshape(w, h);
    }
   
void tao_special(int key, int x, int y)
    {
    x, y; // referenced to get rid of compiler warning

    switch (key)
	{
	case GLUT_KEY_UP:
	    tao.graphicsEngine.globalMagnification *= 1.1f;
	    break;
	    
	case GLUT_KEY_DOWN:
	    tao.graphicsEngine.globalMagnification /= 1.1f;
	    break;
	    
	case GLUT_KEY_RIGHT:
	    if (tao.graphicsEngine.refreshRate==1 &&
	       !tao.synthesisEngine.isActive())
		{
		tao.synthesisEngine.unpause();
		glutIdleFunc(taoMasterTick);
		}
	    else
	        {
		if (tao.graphicsEngine.refreshRate<65536)
		    {
		    tao.graphicsEngine.refreshRate*=2;
		    }
		}
	    break;
	    
	case GLUT_KEY_LEFT:
	    if (tao.graphicsEngine.refreshRate!=1)
		 tao.graphicsEngine.refreshRate/=2;
	    else 
		{
		if (tao.synthesisEngine.isActive())
		    {
		    tao.synthesisEngine.pause();
		    }
		}
	    break;
	}
    }

void tao_keyboard(unsigned char key, int x, int y)
    {
    x, y; // referenced to get rid of compiler warning

    switch (key)
	{
	case 27:
	    exit(0);

	case 'i':
	    tao.graphicsEngine.displayInstrumentNames =
	        tao.graphicsEngine.displayInstrumentNames?0:1;
	    break;

	case 'd':
	    tao.graphicsEngine.displayDeviceNames =
	        tao.graphicsEngine.displayDeviceNames?0:1;
	    break;

	}
    }


TaoGraphicsEngine::TaoGraphicsEngine()
    {
    active=FALSE;
    viewportWidth=400;
    viewportHeight=300;
    xOffset=0.0;
    yOffset=0.0;
    zOffset=-400.0;
    xAngle=-136.0;
    yAngle=0.0;
    zAngle=-182.0;
    globalMagnification=1.0;
    refreshRate=1;    // refresh graphics window on every time step of
		      // synthesis engine
    drag=FALSE;
    dolly=FALSE;
    rotate=FALSE;
    displayInstrumentNames=1;
    displayDeviceNames=1;
    setInstrDisplayResolution();
    }

       
void TaoGraphicsEngine::activate()
    {
    active=1;
    };

void TaoGraphicsEngine::deactivate()
    {
    active=0;
    }


void TaoGraphicsEngine::init(int argc, char *argv[])
    {
    int option;

    while(1)
        {
	option=getopt(argc, argv, "l:");
	if (option==EOF) break;

	switch(option)
	    {
	    case 'l':
		if (*optarg=='s')
		    lineMode=TAO_ANTIALIAS;
		else lineMode=TAO_JAGGED;
		break;
	    }
	}

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 300);
    winId=glutCreateWindow(argv[0]);
    
    glutReshapeFunc(::tao_reshape);
    glutKeyboardFunc(::tao_keyboard);
    glutSpecialFunc(::tao_special);
    glutMouseFunc(::tao_mouse);
    glutMotionFunc(::tao_motion);
    glutDisplayFunc(::tao_display);
    glutVisibilityFunc(::tao_visibility);
     
    glClearColor(0.7,0.7,0.7,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT);

    if (lineMode==TAO_ANTIALIAS)
        {
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	}

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

/*
    static float fog_color[] = {0.7, 0.75, 0.78, 1.0};
    static float fogDensity = 1.0;

    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 30.0);
    glFogf(GL_FOG_END, 1000.0);
    glFogf(GL_FOG_DENSITY, fogDensity);
    glFogfv(GL_FOG_COLOR, fog_color);
*/

    active=TRUE;
    
    flushGraphics();
    }

void TaoGraphicsEngine::reshape(int w, int h)
    {
    viewportWidth=w;
    viewportHeight=h;
    setInstrDisplayResolution();
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (projectionMode==TAO_PERSPECTIVE)
        {
	gluPerspective(15.0,(GLdouble)w/(GLdouble)h,10.0,2000.0);
	}
    else
        {
	glOrtho(-80.0, 80.0, 
	    -80.0*(GLdouble)h/(GLdouble)w, 80.0*(GLdouble)h/(GLdouble)w,
	    -200.0, 1000.0);
	}
    }

void TaoGraphicsEngine::clearBackBuffer()
    {
    glColor3f(1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

void TaoGraphicsEngine::pushModelViewMatrix()
    {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    }

void TaoGraphicsEngine::popModelViewMatrix()
    {
    glPopMatrix();
    }

void TaoGraphicsEngine::rotateAndTranslate()
    {
    glTranslatef(xOffset/5.0, yOffset/5.0, zOffset);
    glRotatef(xAngle/4.0,1.0,0.0,0.0);
    glRotatef(yAngle/4.0,0.0,1.0,0.0);
    glRotatef(zAngle/4.0,0.0,0.0,1.0);
    glTranslatef(-translateX, -translateY, 0.0);    
    }

void TaoGraphicsEngine::display()
    {
    int len, i;
    char *string;
    extern float &Time;

    displayInstruments();
    displayDevices();

    timestream << std::setw(0) << std::setprecision(4) << std::setiosflags(std::ios::fixed);
    timestream << "Time=" << Time << " seconds";

/*  THIS DOESN'T WORK AND NEVER HAS!!

    glColor3f(0.0,0.0,0.0);
    glRasterPos2f(9.0, 9.0);

    string=timestream.str();
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}

    timestream.seekp(0, ostream::beg);
*/
    }
    
void TaoGraphicsEngine::flushGraphics()
    {
    glFlush();
    }
    
void TaoGraphicsEngine::swapBuffers()
    {
      //cout << "Swapping buffers\n";

    glutSwapBuffers();
    }

void TaoGraphicsEngine::mouse(int button, int state, int x, int y)
    {
    if (state==GLUT_DOWN)
        {
        switch (button)
	    {
	    case GLUT_LEFT_BUTTON:
	        drag=TRUE;
		break;
	    case GLUT_MIDDLE_BUTTON:
		dolly=TRUE;
		break;
	    case GLUT_RIGHT_BUTTON:
		rotate=TRUE;
		break;
	    }
	
	//refreshRateToRestore=refreshRate;
	//refreshRate=1;
	lastMouseX=x;
	lastMouseY=y;
	}
    else
        {
        drag=FALSE;
	dolly=FALSE;
	rotate=FALSE;
	//refreshRate=refreshRateToRestore;
        }
    }

void TaoGraphicsEngine::setInstrDisplayResolution()
    {
    if (zOffset <= -viewportWidth*3)		jstep=8;
    else if (zOffset <= -viewportWidth*3/2)	jstep=4;
    else if (zOffset <= -viewportWidth*3/4)	jstep=2;
    else					jstep=1; 
    }

void TaoGraphicsEngine::motion(int x, int y)
    {
    if (drag==TRUE)
	{
	xOffset+=x-lastMouseX;
	yOffset-=y-lastMouseY;
	lastMouseX=x;
	lastMouseY=y;
	}

    if (dolly==TRUE)
        {
	zOffset+=y-lastMouseY;
	setInstrDisplayResolution();
	lastMouseX=x;
	lastMouseY=y;
	}

    if (rotate==TRUE)
        {
	xAngle+=y-lastMouseY;
	zAngle+=x-lastMouseX;
	lastMouseX=x;
	lastMouseY=y;
	}
    }

void TaoGraphicsEngine::calculateOriginForRotations()
    {
    for (TaoInstrument *i=tao.synthesisEngine.instrumentList; i; i=i->next)
	{
	if (i->worldx < minWorldX) minWorldX = i->worldx;
	if (i->worldy < minWorldY) minWorldY = i->worldy;
	if (i->worldx + i->xmax > maxWorldX) maxWorldX = i->worldx + i->xmax;
	if (i->worldy + i->ymax > maxWorldY) maxWorldY = i->worldy + i->ymax;
	};

    translateX=minWorldX+(maxWorldX-minWorldX)/2.0;
    translateY=minWorldY+(maxWorldY-minWorldY)/2.0;
    scaleBy=20.0/(maxWorldX-minWorldX);    
    }

void TaoGraphicsEngine::mainLoop()
    {
    glutMainLoop();
    }

void
TaoGraphicsEngine::displayCharString(GLfloat x, GLfloat y, GLfloat z,
				     char *string)
    {
    int len, i;

    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0)
        return;
    if (!this->active) return;

    glColor3f(0.0,0.0,0.0);
    glRasterPos3f(x, y, z);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
    }

void
TaoGraphicsEngine::displayCharString(GLfloat x, GLfloat y, GLfloat z, 
				    char *string, GLfloat r, GLfloat g, GLfloat b)
    {
    int len, i;

    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0)
        return;
    if (!this->active) return;

    glColor3f(r,g,b);
    glRasterPos3f(x, y, z);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
    }

void TaoGraphicsEngine::displayPoint(GLfloat x, GLfloat y, int colour)
    {
    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0)
        return;
    if (!this->active) return;
    setDrawColour(colour);
    glPointSize(5.0);
    glBegin(GL_POINTS);
	glVertex2f(x, y);
    glEnd();
    }
    
void TaoGraphicsEngine::displayInstruments()
    {
    if (!this->active) return;
    for (TaoInstrument *i=tao.synthesisEngine.instrumentList; i; i=i->next)
	displayInstrument(*i);
    }

void TaoGraphicsEngine::displayDevices()
    {
    if (!this->active) return;
    for (TaoDevice *d=tao.synthesisEngine.deviceList; d; d=d->next)
	d->display();
    }

void TaoGraphicsEngine::displayInstrument(TaoInstrument &instr)
    {
    static GLdouble textClipPlane[] = {0.0, 0.0, 1.0, 50.0};
    register short i, j;
    TaoCell *c;
    float cellPosition;
    float magnification=globalMagnification*instr.getMagnification();
    GLfloat x, y, z;
    int step;

    if (!this->active) return;

    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);

    for(j=instr.ymax;j>=0;j-=jstep) // draw horizontal lines through rows of cells
	{
	glBegin(GL_LINE_STRIP);
	for(i=0, c=instr.rows[j].cells; i<=instr.rows[j].xmax; i++, c++)
	    {
	    cellPosition=c->position;
	    if (c->velocityMultiplier < instr.defaultVelocityMultiplier)
	        glColor3f(0.2,0.2,0.2);
	    else glColor3f(0.0,0.0,0.0);
	    x=instr.worldx+instr.rows[j].offset+i;
	    z=cellPosition*magnification;
	    y=j+instr.worldy;
	    glVertex3f(x,y,z);
	    }
	glEnd();
	}

    glColor3f(0.0,0.0,0.0);
    
    if (instr.ymax>0)		// if instrument is 2D, draw line round perimeter
	{			// if perimeter is locked make line thicker
	if (instr.perimeterLocked) glLineWidth(2.0);
	else glLineWidth(1.0);

	glBegin(GL_LINE_STRIP);

	j=0;

	for(i=0, c=instr.rows[0].cells; i<=instr.rows[0].xmax; i++, c++) 
							       // across bottom
	    {
	    cellPosition=c->position;
	    x=instr.worldx+instr.rows[j].offset+i;
	    z=cellPosition*magnification;
	    y=j+instr.worldy;

	    glVertex3f(x,y,z);
	    }
	
	for(j=0;j<=instr.ymax;j++)			       // up right
	    {
	    c=&instr.rows[j].cells[instr.rows[j].xmax];
	    cellPosition=c->position;
	    x=instr.worldx+instr.rows[j].offset+instr.rows[j].xmax;
	    z=cellPosition*magnification;
	    y=j+instr.worldy;

	    glVertex3f(x,y,z);
	    }

	j=instr.ymax;

	for(i=instr.rows[instr.ymax].xmax;i>=0;i--)	       // across top
	    {
	    c=&instr.rows[instr.ymax].cells[i];
	    cellPosition=c->position;
	    x=instr.worldx+instr.rows[j].offset+i;
	    z=cellPosition*magnification;
	    y=j+instr.worldy;

	    glVertex3f(x,y,z);
	    }
	
	for(j=instr.ymax;j>=0;j--)			       // down left
	    {
	    c=&instr.rows[j].cells[0];
	    cellPosition=c->position;
	    x=instr.worldx+instr.rows[j].offset;
	    z=cellPosition*magnification;
	    y=j+instr.worldy;

	    glVertex3f(x,y,z);
	    }

	glEnd();
	}
    
    glPointSize(3.0);
    glBegin(GL_POINTS);

    for(j=0;j<=instr.ymax;j++)	    // scan cells again to mark any
	{			    // locked or glued ones
	
	for(i=0, c=instr.rows[j].cells;i<=instr.rows[j].xmax;i++, c++)
	    {
	    cellPosition=c->position;
	    if(c->mode & TAO_CELL_LOCK_MODE)
		{
		if ((i==0 || i==instr.rows[j].xmax || j==0 || j==instr.ymax)
		&& instr.perimeterLocked)    // if we're at the instrument's
		    {			     // perimeter and it is locked then
		    continue;		     // don't mark individual locked
		    }			     // points as the locked perimeter
					     // has already been displayed as a
					     // thicker line.	
		glColor3f(0.0f,0.0f,0.0f);   
		x=instr.worldx+instr.rows[j].offset+i;
		z=cellPosition*magnification;
		y=j+instr.worldy;
		glVertex3f(x,y,z);
		}
	    }
	}

    glEnd();

    j=instr.ymax/2;
    c=&instr.rows[j].cells[instr.xmax];
    cellPosition=c->position;
    x=(GLfloat)(instr.worldx + instr.xmax + 3.0);
    z=(GLfloat)(cellPosition*magnification);
    y=(GLfloat)(j+instr.worldy);

//std::cout << "x=" << x << " y=" << y << " z=" << z 
//     << " name=" << instr.name << std::endl;

    if (displayInstrumentNames)
        displayCharString(x,y,z,instr.name,0.0,0.0,0.0);
    }

void TaoGraphicsEngine::displayAccessPoint(TaoInstrument &instr, int i, int j)
    {
    TaoCell *c;
    float cellPosition;
    GLfloat x, y, z;
    GLfloat screenx, screeny;
    
    if (!this->active) return;

    glPointSize(4.0);
    glColor3f(1.0,0.0,0.0);
    if(tao.synthesisEngine.tick%this->refreshRate==0)
	{
	c=&instr.rows[j].cells[0];
	cellPosition=c->position;
	x=instr.worldx+instr.rows[j].offset+i;
	z=cellPosition*instr.amplification*globalMagnification;
	y=j+instr.worldy;
	glBegin(GL_POINTS);
	    glVertex3f(x,y,z);
	glEnd();
	}
    }

class TaoAccessPoint;

void TaoGraphicsEngine::displayAccessPoint(TaoAccessPoint &p)
    {
    int i, j;
    TaoCell *c;
    GLfloat x, y, z;
    GLfloat screenx, screeny;
    
    if (!this->active) return;
    if (p.instrument==NULL) return;
    TaoInstrument &instr=*(p.instrument);

    if(tao.synthesisEngine.tick%this->refreshRate==0)
	{
	j=(int)p.celly;
	x=instr.worldx+instr.rows[j].offset+p.cellx;
	z=(GLfloat)(p.getPosition()*instr.amplification*globalMagnification);
	y=(GLfloat)(p.celly+instr.worldy);

	glColor3f(1.0,0.0,0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	    glVertex3f(x,y,z);
	glEnd();
	}
    }


float TaoGraphicsEngine::screenX(TaoInstrument &instr, float x, float y)
    {
    return 0.0;
    }


float TaoGraphicsEngine::screenY(TaoInstrument &instr, float x, float y)
    {
    return 0.0;
    }


float TaoGraphicsEngine::screenY(TaoInstrument &instr, float x, float y, float z)
    {
    return 0.0;
    }


void TaoGraphicsEngine::displayPointInInstrumentSpace(TaoInstrument &instr,
	float instrx, float instry, float instrz)
    {
    GLfloat x,y,z;

    if (!this->active) return;

    TaoAccessPoint p=instr.point(instrx, instry);

    x=(GLfloat)(instr.getWorldX()+p.cellx);
    z=(GLfloat)(instrz*instr.getMagnification()*globalMagnification);
    y=(GLfloat)(instr.getWorldY()+p.celly);

    glPointSize(4.0);
    glBegin(GL_POINTS);
	glVertex3f(x,y,z);	
    glEnd();
    }    

void
TaoGraphicsEngine::label(TaoInstrument &instr, float x, float y,
			 float labelXOffset, float labelYOffset,
			 char *caption, GLfloat r, GLfloat g, GLfloat b)
    {
    GLfloat worldx, worldy, worldz;
    TaoAccessPoint &p=instr.point(x,y);

    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0)
        return;

    if (active)
	{
        worldx=(GLfloat)(instr.getWorldX()+p.cellx);
        worldz=(GLfloat)(p.getPosition()*instr.getMagnification()*
	    globalMagnification);
        worldy=(GLfloat)(instr.getWorldY()+p.celly);
	displayCharString(worldx, worldy, worldz, caption, r, g, b);
	}
    }
  
void
TaoGraphicsEngine::label(TaoInstrument &instr, float x, float labelXOffset,
			 float labelYOffset, char *caption,
		         GLfloat r, GLfloat g, GLfloat b)
    {
    GLfloat worldx, worldy, worldz;
    TaoAccessPoint &p=instr.point(x);

    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0)
        return;

    if (active)
	{
        worldx=(GLfloat)(instr.getWorldX()+p.cellx);
        worldz=(GLfloat)(p.getPosition()*instr.getMagnification()*
	    globalMagnification);
        worldy=(GLfloat)(instr.getWorldY()+p.celly);
	displayCharString(worldx, worldy, worldz, caption, r, g, b);
	}
    }  

void
TaoGraphicsEngine::label(TaoInstrument &instr, float x, float y, float z, 
			 float labelXOffset, float labelYOffset, char *caption,
			 GLfloat r, GLfloat g, GLfloat b)
    {
    GLfloat worldx, worldy, worldz;
    TaoAccessPoint &p=instr.point(x,y);

    if (tao.synthesisEngine.tick%tao.graphicsEngine.refreshRate!=0)
        return;

    if (active)
	{
        worldx=(GLfloat)(instr.getWorldX()+p.cellx);
        worldz=(GLfloat)(z*instr.getMagnification()*
	    globalMagnification);
        worldy=(GLfloat)(instr.getWorldY()+p.celly);
	displayCharString(worldx, worldy, worldz, caption, r, g, b);
	}
    }
  
void TaoGraphicsEngine::setDrawColour(int c)
    {
    if (!this->active) return;
    switch(c)
	{
	case 0: glColor3f(0.0, 0.0, 0.0); break;	// BLACK
	case 1: glColor3f(0.0, 0.0, 1.0); break;	// BLUE
	case 2: glColor3f(0.0, 1.0, 0.0); break;	// GREEN
	case 3: glColor3f(0.0, 1.0, 1.0); break;	// CYAN
	case 4: glColor3f(1.0, 0.0, 0.0); break;	// RED
	case 5: glColor3f(1.0, 0.0, 1.0); break;	// MAGENTA
	case 6: glColor3f(1.0, 1.0, 0.0); break;	// YELLOW
	case 7: glColor3f(1.0, 1.0, 1.0); break;	// WHITE
	}
    }

void TaoGraphicsEngine::setClearColour(int c)
    {
    if (!this->active) return;
    switch(c)
	{
	case 0: glClearColor(0.0, 0.0, 0.0, 0.0); break;    // BLACK
	case 1: glClearColor(0.0, 0.0, 1.0, 1.0); break;    // BLUE
	case 2: glClearColor(0.0, 1.0, 0.0, 1.0); break;    // GREEN
	case 3: glClearColor(0.0, 1.0, 1.0, 1.0); break;    //
	case 4: glClearColor(1.0, 0.0, 0.0, 1.0); break;    // RED
	case 5: glClearColor(1.0, 0.0, 1.0, 1.0); break;    //
	case 6: glClearColor(1.0, 1.0, 0.0, 1.0); break;    //
	case 7: glClearColor(1.0, 1.0, 1.0, 1.0); break;    // WHITE
	default: break;	
	}
    }
