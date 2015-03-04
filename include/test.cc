//////////////////////////////////////////////////////////////////////////////////
// This is the translated version of script "examples/test.tao".
//
// It contains automatically generated definitions for the following functions
// which are required by the Tao library in order to produce a complete
// executable:
//
//   int    taoAudioRate()	- returns the audio sampling rate in Hz.
//   float  taoScoreDuration()	- returns the duration of the score
//				  in seconds.
//   void   taoInit()		- this function is called just before execution
//				  of the score and contains user specified code
//				  for initialising variable values, devices,
//				  instruments and connections.
//   void   taoScore()		- this function is called once on every tick of
//				  the synthesis engine and contains all the code
//				  representing the user's time-domain inter-
//				  actions with the instruments and devices.
//
// The `main()' function defined at the end of this generated file registers
// the functions described above with the top level object `tao' (an instance
// of class `Tao'), and then invokes the member function `tao.main()'. This
// function enters the main synthesis engine loop which calculates the number
// of ticks specified by the score duration, and updates the graphics window
// (if graphics mode is on). It only exits if the graphics window is closed, if
// the ESC key is pressed whilst the graphics window has the mouse focus, if
// CTRL-C is pressed in the shell window from which Tao was invoked, or the
// `performance' reaches its natural conclusion.
//////////////////////////////////////////////////////////////////////////////////

#include "taodefs.h" 
#include <cmath>
#include <iostream>

Tao tao;


// Audio rate: <sample_rate> ;

int taoAudioRate() {return 44100;}



// Declarations

TaoCircle
    c("c", TaoPitch(800.000f, TaoPitch::frq), 20.0000f);

TaoString
    strings[4]=
        {
        TaoString("strings[0]", TaoPitch(800.000f, TaoPitch::frq), 20.0000f),
        TaoString("strings[1]", TaoPitch(810.000f, TaoPitch::frq), 20.0000f),
        TaoString("strings[2]", TaoPitch(820.000f, TaoPitch::frq), 20.0000f),
        TaoString("strings[3]", TaoPitch(830.000f, TaoPitch::frq), 20.0000f)
        };

TaoRectangle
    r("r", TaoPitch(800.000f, TaoPitch::frq), TaoPitch(900.000f, TaoPitch::frq), 20.0000f);

TaoTriangle
    t("t", TaoPitch(800.000f, TaoPitch::frq), TaoPitch(900.000f, TaoPitch::frq), 20.0000f);


TaoConnector conn1("conn1") , conn2("conn2") , conn3("conn3") , conn4("conn4");
#line 14 "examples/test.tao"
int s;

// Init: <statements> ...

void taoInit()
    {
#line 17 "examples/test.tao"
    for(s=0;s<=3;s++)
        {
#line 18 "examples/test.tao"
        strings [ s ] . lockEnds ( );
        }

#line 21 "examples/test.tao"
    c . lockPerimeter ( );
#line 22 "examples/test.tao"
    r . lockCorners ( );
#line 23 "examples/test.tao"
    t . lockLeft ( ) . lockRight ( );
#line 25 "examples/test.tao"
    conn1(strings [ 0 ] ( 0.100000f ), strings [ 1 ] ( 0.100000f ));
#line 26 "examples/test.tao"
    conn2(strings [ 1 ] ( 0.900000f ), strings [ 2 ] ( 0.900000f ));
#line 27 "examples/test.tao"
    conn3(strings [ 2 ] ( 0.100000f ), strings [ 3 ] ( 0.100000f ));
#line 29 "examples/test.tao"
    conn4(r ( 0.600000f , 0.200000f ), 0.00000f);
#line 31 "examples/test.tao"
    r . placeRightOf ( c , 20 );
#line 32 "examples/test.tao"
    t . placeAbove ( r );
    }

// Score <duration> : <statements> ...

float taoScoreDuration() {return 20.0000f;}

void taoScore()
    {
    tao.initStartAndEnd();

    if(Tick<=(long)((tao.newEnd=tao.start*
1.00000+0.000100000f)*
     tao.synthesisEngine.modelSampleRate) &&
     Tick>=(long)((tao.newStart=tao.start)*
     tao.synthesisEngine.modelSampleRate))
        {
        tao.pushStartAndEnd1();
#line 37 "examples/test.tao"
        strings [ 0 ] ( 0.100000f ) . applyForce ( 1.00000f );
#line 38 "examples/test.tao"
        strings [ 1 ] ( 0.100000f ) . applyForce ( 1.00000f );
#line 39 "examples/test.tao"
        strings [ 2 ] ( 0.100000f ) . applyForce ( 1.00000f );
#line 40 "examples/test.tao"
        strings [ 3 ] ( 0.100000f ) . applyForce ( 1.00000f );
#line 42 "examples/test.tao"
        c ( 0.100000f , 0.500000f ) . applyForce ( 10.0000f );
#line 43 "examples/test.tao"
        r ( 0.700000f , 0.800000f ) . applyForce ( 10.0000f );
#line 44 "examples/test.tao"
        t ( 0.800000f , 0.600000f ) . applyForce ( 10.0000f );
        tao.popStartAndEnd();
        }


    tao.popStartAndEnd();
    }

int main(int argc, char *argv[])
    {
    tao.initStartAndEnd();
    tao.audioRateFunc(taoAudioRate);
    tao.initFunc(taoInit);
    tao.scoreDurationFunc(taoScoreDuration);
    tao.scoreFunc(taoScore);
    tao.main(argc, argv);
    }


// End of C++ program generated from script "examples/test.tao"
