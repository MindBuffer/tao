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

#ifndef TAOGRAPHICSENGINE_H
#define TAOGRAPHICSENGINE_H

#ifndef HAVE_OSX
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#ifdef WIN32
#include <strstrea.h>
#else
#include <sstream>
#endif

#include <iomanip>

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class Tao;
class TaoInstrument;
class TaoAccessPoint;
class TaoBow;
class TaoHammer;
class TaoConnector;
class TaoStop;
class TaoOutput;

// The following functions are registered as OpenGL callback functions

void tao_mouse(int button, int state, int x, int y);
void tao_keyboard(unsigned int key, int x, int y);
void tao_motion(int x, int y);
void tao_display();
void tao_reshape(int w, int h);

class DLLEXPORT TaoGraphicsEngine
    {
    friend class Tao;
    friend class TaoInstrument;
    friend class TaoAccessPoint;
    friend class TaoBow;
    friend class TaoHammer;
    friend class TaoConnector;
    friend class TaoStop;
    friend class TaoOutput;
    friend void tao_visibility(int state);
    friend void tao_mouse(int button, int state, int x, int y);
    friend void tao_motion(int x, int y);
    friend void tao_display();
    friend void tao_reshape(int w, int h);
    friend void tao_keyboard(unsigned char key, int x, int y);
    friend void tao_special(int key, int x, int y);
   
public:
    TaoGraphicsEngine();

    void activate();
    void deactivate();
    void init(int argc, char *argv[]);
    void reshape(int w, int h);
    void mouse(int button, int state, int x, int y);
    void motion(int x, int y);
    void setInstrDisplayResolution();
    void calculateOriginForRotations();
    void clearBackBuffer();
    void pushModelViewMatrix();
    void popModelViewMatrix();
    void rotateAndTranslate();
    void display();
    void flushGraphics();
    void swapBuffers();
    void mainLoop();

    void setDrawColour(int colour);    
    void setClearColour(int colour);
    void displayCharString(GLfloat x, GLfloat y, GLfloat z, char *string);
    void displayCharString(GLfloat x, GLfloat y, GLfloat z, char *string,
		           GLfloat r, GLfloat g, GLfloat b);
    void displayPoint(GLfloat x, GLfloat y, int colour);
    void displayInstruments();
    void displayDevices();
    void displayInstrument(TaoInstrument &instr);
    float screenX(TaoInstrument &instr, float x, float y);
    float screenY(TaoInstrument &instr, float x, float y);
    float screenY(TaoInstrument &instr, float x, float y, float z);
    void displayPointInInstrumentSpace(TaoInstrument &instr, float instrx,
	float instry, float instrz);
    void label(TaoInstrument &instr, float x, float y,
	GLfloat labelXOffset, GLfloat labelYOffset,
	char *caption, GLfloat r, GLfloat g, GLfloat b);
    void label(TaoInstrument &instr, float x,
	GLfloat labelXOffset, GLfloat yOffset, char *caption, 
	GLfloat r, GLfloat g, GLfloat b);
    void label(TaoInstrument &instr, float x, float y, float z, 
	GLfloat labelXOffset, GLfloat labelYOffset, char *caption,
	GLfloat r, GLfloat g, GLfloat b);
    void displayAccessPoint(TaoInstrument &instr, int i, int j);
    void displayAccessPoint(TaoAccessPoint &p);
    
private:
    int active;
    int winId;
    int viewportWidth, viewportHeight;
    GLfloat xOffset, yOffset, zOffset, xAngle, yAngle, zAngle;
    int jstep;
    int refreshRate;
    int refreshRateToRestore;
    float globalMagnification;
    std::ostringstream timestream;	// used to create a string of characters
				// representing the elapsed time.    
    enum {TAO_PERSPECTIVE, TAO_ORTHO, TAO_ANTIALIAS, TAO_JAGGED};
    int projectionMode;
    int displayInstrumentNames, displayDeviceNames;
    int lineMode;
    int lastMouseX, lastMouseY, zoomInitialMouseY;
    int drag;
    int dolly;
    int rotate;
    GLfloat minWorldX, maxWorldX, minWorldY, maxWorldY;
    GLfloat translateX, translateY, translateZ, scaleBy;
    };

#endif
