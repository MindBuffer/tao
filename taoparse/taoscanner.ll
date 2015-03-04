%{
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

#include <iostream>
#include <cstdlib>
#include <string>
#include "taoparserdefs.h"
#include "taoparser.h"

int token;
int lineno=1;
int charno=0;
char current_line[256]="";
char idname[256]="";

#define ADDTOLINE \
strcat(current_line,yytext);charno+=strlen(yytext);

#define SAVETOKEN \
yylval.s=new char[strlen(yytext)+1]; \
strcpy(yylval.s, yytext);

extern char current_instr_class[];
extern char current_device_class[];
extern char current_id[];

extern YYSTYPE yylval;

extern int streq(const char *s1, const char *s2);

%}

PARAM		Param
SIGNAL		Signal
ACOMMENT	"//".*$
INTLIT		[0-9]+
FLOATLIT	[0-9]+\.[0-9]*
FRACTION	[0-9]+"/"[0-9]+
STRLIT		\"[^"]*\"
ELLIPSIS	\.\.\.
AUDIO		Audio		    
RATE            rate
PITCH		Pitch
ACCESSPOINT	AccessPoint
COUNTER		Counter
INTEGER		Integer
FLAG		Flag
STRING		String
RECTANGLE	Rectangle
ELLIPSE		Ellipse
CIRCLE		Circle
TRIANGLE	Triangle
BOW		Bow
HAMMER		Hammer
CONNECTOR	Connector
STRENGTH	strength
STOP		Stop
OUTPUT		Output
STEREO		stereo
MONO		mono
QUAD		quad
PRINT		Print
LABEL		Label
POSITIONKWD		left|right|top|bottom|centre|center
GETMAGNIFICATION	getMagnification
GETXFREQUENCY		getXFrequency	
GETYFREQUENCY		getYFrequency
SETMAGNIFICATION	setMagnification
SETDAMPING		setDamping
SETDECAY		setDecay
RESETDAMPING		resetDamping
RESETDECAY		resetDecay
LOCK			lock
LOCKLEFT		lockLeft
LOCKRIGHT		lockRight
LOCKTOP			lockTop
LOCKBOTTOM		lockBottom
LOCKPERIMETER		lockPerimeter
LOCKCORNERS		lockCorners
LOCKENDS		lockEnds
PLACEAT			placeAt
PLACEABOVE		placeAbove
PLACEBELOW		placeBelow
PLACELEFTOF		placeLeftOf
PLACERIGHTOF		placeRightOf
JOIN			Join
REMOVE		    	remove
ACTIVATE		activate
DEACTIVATE		deactivate
GETVELOCITY		getVelocity
GETINITVELOCITY		getInitVelocity
GETPOSITION		getPosition
GETMASS			getMass
GETNAME			getName
GETGRAVITY		getGravity
GETHEIGHT		getHeight
GETDAMPING		getDamping
GETHARDNESS		getHardness
GETMAXIMPACTS   	getMaxImpacts
GETAMOUNT		getAmount
NUMBEROFIMPACTS		numberOfImpacts
SETMASS			setMass
SETPOSITION		setPosition
SETVELOCITY		setVelocity
SETINITVELOCITY		setInitVelocity
SETGRAVITY		setGravity
SETHEIGHT		setHeight
SETHARDNESS		setHardness
SETMAXIMPACTS		setMaxImpacts
SETAMOUNT		setAmount
RESET			reset
DROP			drop
SETFORCE		setForce
GETFORCE		getForce
OUTPUTCH		ch(1|2|3|4|L|R)
GETINSTRUMENT		getInstrument
APPLYFORCE		applyForce
CLEAR			clear
CONNECT			Connect
COLLIDE			Collide
GROUND			Ground
ASPITCH			asPitch
ASOCTAVE		asOctave
ASFREQUENCY		asFrequency
ASNAME			asName
INIT			Init
TIME			Time
TICK			Tick
SCORE			Score
START			start
END			end
AT			At
FROM			From
BEFORE			Before
AFTER			After
EVERY			Every
CONTROLRATE		ControlRate
IF			If
ELSE			Else
ELSEIF			ElseIf
FOR			For
TO			to
ATFOR			for
IN			in
TRUE			true
FALSE			false
MATH1			acos|acosh|asin|atan|atanh|cbrt|cos|cosh|exp|expm1|fabs|ceil|floor|cos|cosh|exp|expm1|log|log10|log1p|rint|sin|sinh|sqrt|tan|tanh
MATH2			atan2|pow|hypot|drem
LINEAR			linear
EXPON			expon
ID			[a-zA-Z_][a-zA-Z0-9_]*
INCDEC			"++"|"--"
RELOP			"<"|">"|"<="|">="
EQUALITY		"=="|"!="
AND			and
OR			or
NOT			not
SHIFTOP			"<<"|">>"
ASSIGNOP		"+="|"-="|"*="|"/="|"%="|"<<="|">>="|"&="|"^="|"|="
PITCHUNITS		pch|oct|Hz
TIMEUNITS		secs|sec|msecs|min|mins
WHITESPACE		[ \t]+
NEWLINE			[\n]
NEWLINEKWD		newline

%%
{AUDIO}     {
            ADDTOLINE;
            yylval.t=STR;
            SAVETOKEN;
            return AUDIO;
            }
{RATE}		{
            ADDTOLINE;
            yylval.t=STR;
            SAVETOKEN;
            return RATE;
            }

{STRING}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_instr_class, "TaoString");
		SAVETOKEN;return STRING;
		}

{RECTANGLE}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_instr_class, "TaoRectangle");
		SAVETOKEN;return RECTANGLE;}

{ELLIPSE}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_instr_class, "TaoEllipse");
		SAVETOKEN;return ELLIPSE;
		}

{CIRCLE}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_instr_class, "TaoCircle");
		SAVETOKEN;return CIRCLE;
		}

{TRIANGLE}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_instr_class, "TaoTriangle");
		SAVETOKEN;return TRIANGLE;
		}

{BOW}		{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_device_class, "TaoBow");
		SAVETOKEN;return BOW;
		}

{HAMMER}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_device_class, "TaoHammer");
		SAVETOKEN;return HAMMER;
		}

{CONNECTOR}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_device_class, "TaoConnector");
		SAVETOKEN;return CONNECTOR;
		}

{STOP}		{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_device_class, "TaoStop");
		SAVETOKEN;return STOP;
		}

{OUTPUT}	{
		ADDTOLINE;yylval.t=STR;
		strcpy(current_device_class, "TaoOutput");
		SAVETOKEN;return OUTPUT;
		}

{STRENGTH}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return STRENGTH;}
{STEREO}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return STEREO;}
{MONO}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return MONO;}
{QUAD}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return QUAD;}
{PARAM}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PARAM;}
{SIGNAL}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SIGNAL;}
{COUNTER}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return COUNTER;}
{INTEGER}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return INTEGER;}
{FLAG}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return FLAG;}
{PRINT}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PRINT;}
{NEWLINEKWD}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return NEWLINEKWD;}
{GETMAGNIFICATION}      {ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETMAGNIFICATION;}
{GETXFREQUENCY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETXFREQUENCY;}
{GETYFREQUENCY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETYFREQUENCY;}
{SETMAGNIFICATION}	{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETMAGNIFICATION;}
{SETDAMPING}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETDAMPING;}
{SETDECAY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETDECAY;}
{RESETDECAY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return RESETDECAY;}
{RESETDAMPING}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return RESETDAMPING;}
{LOCK}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCK;}
{LOCKLEFT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKLEFT;}
{LOCKRIGHT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKRIGHT;}
{LOCKTOP}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKTOP;}
{LOCKBOTTOM}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKBOTTOM;}
{LOCKPERIMETER}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKPERIMETER;}
{LOCKCORNERS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKCORNERS;}
{LOCKENDS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LOCKENDS;}
{PLACEAT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PLACEAT;}
{PLACEABOVE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PLACEABOVE;}
{PLACEBELOW}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PLACEBELOW;}
{PLACELEFTOF}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PLACELEFTOF;}
{PLACERIGHTOF}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PLACERIGHTOF;}
{JOIN}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return JOIN;}
{LABEL}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LABEL;}
{REMOVE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return REMOVE;}
{ACTIVATE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ACTIVATE;}
{DEACTIVATE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return DEACTIVATE;}
{GETNAME}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETNAME;}
{GETVELOCITY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETVELOCITY;}
{GETINITVELOCITY}	{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETINITVELOCITY;}
{GETPOSITION}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETPOSITION;}
{GETMASS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETMASS;}
{GETGRAVITY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETGRAVITY;}
{GETHEIGHT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETHEIGHT;}
{GETDAMPING}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETDAMPING;}
{GETHARDNESS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETHARDNESS;}
{GETMAXIMPACTS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETMAXIMPACTS;}
{GETAMOUNT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETAMOUNT;}
{NUMBEROFIMPACTS}	{ADDTOLINE;yylval.t=STR;SAVETOKEN;return NUMBEROFIMPACTS;}
{SETMASS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETMASS;}
{SETPOSITION}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETPOSITION;}
{SETVELOCITY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETVELOCITY;}
{SETINITVELOCITY}	{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETINITVELOCITY;}
{SETGRAVITY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETGRAVITY;}
{SETHEIGHT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETHEIGHT;}
{SETHARDNESS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETHARDNESS;}
{SETMAXIMPACTS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETMAXIMPACTS;}
{SETAMOUNT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETAMOUNT;}
{RESET}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return RESET;}
{DROP}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return DROP;}
{SETFORCE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SETFORCE;}
{GETFORCE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETFORCE;}
{OUTPUTCH}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return OUTPUTCH;}
{GETINSTRUMENT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return GETINSTRUMENT;}
{APPLYFORCE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return APPLYFORCE;}
{CLEAR}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return CLEAR;}
{ASPITCH}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ASPITCH;}
{ASOCTAVE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ASOCTAVE;}
{ASFREQUENCY}	        {ADDTOLINE;yylval.t=STR;SAVETOKEN;return ASFREQUENCY;}
{ASNAME}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ASNAME;}
{AND}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return AND;}
{OR}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return OR;}
{NOT}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return NOT;}
{INTLIT}		{
			ADDTOLINE;
			yylval.i=atoi(yytext);
			yylval.t=INT;
			yylval.f=(float)yylval.i;
			SAVETOKEN;
			return INTLIT;
			}
{FLOATLIT}		{
			ADDTOLINE;
			yylval.f=atof(yytext);
			yylval.t=FLT;
			SAVETOKEN;
			return FLOATLIT;
			}
{POSITIONKWD}		{
			ADDTOLINE;
			if	(streq(yytext,"left"))	    yylval.f=0.0;
			else if	(streq(yytext,"right"))	    yylval.f=1.0;
			else if	(streq(yytext,"bottom"))    yylval.f=0.0;
			else if	(streq(yytext,"top"))	    yylval.f=1.0;
			else if	(streq(yytext,"centre"))    yylval.f=0.5;
			else if	(streq(yytext,"center"))    yylval.f=0.5;
			yylval.t=FLT;

			SAVETOKEN;
			return POSITIONKWD;
			}
{FRACTION}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return FRACTION;}
{MATH1}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return MATHFUNC1;}
{MATH2}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return MATHFUNC2;}
{LINEAR}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return LINEAR;}
{EXPON}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return EXPON;}
{INIT}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return INIT;}
{TIME}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return TIME;}
{TICK}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return TICK;}
{SCORE}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SCORE;}
{START}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return START;}
{END}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return END;}
{AT}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return AT;}
{ATFOR}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ATFOR;}
{FROM}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return FROM;}
{BEFORE}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return BEFORE;}
{AFTER}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return AFTER;}
{EVERY}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return EVERY;}
{CONTROLRATE}	        {ADDTOLINE;yylval.t=STR;SAVETOKEN;return CONTROLRATE;}
{IF}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return IF;}
{ELSE}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ELSE;}
{ELSEIF}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ELSEIF;}
{FOR}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return FOR;}
{TO}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return TO;}
{IN}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return IN;}
{PITCH}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PITCH;}
{ACCESSPOINT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ACCESSPOINT;}
{PITCHUNITS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return PITCHUNITS;}
{TIMEUNITS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return TIMEUNITS;}
{TRUE}			{
			ADDTOLINE;
			yylval.s=new char[2];
			yylval.i=1;
			strcpy(yylval.s,"1");
			yylval.t=STR;
			return TRUE;
			}
{FALSE}			{
			ADDTOLINE;
			yylval.s=new char[2];
			yylval.i=0;
			strcpy(yylval.s,"0");
			yylval.t=STR;
			return FALSE;
			}
{ID}			{
			ADDTOLINE;yylval.t=STR;
			strcpy(current_id, yytext);
			SAVETOKEN;return ID;
			}
{STRLIT}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return STRLIT;}
{INCDEC}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return INCDEC;}
{SHIFTOP}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return SHIFTOP;}
{RELOP}			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return RELOP;}
{EQUALITY}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return EQUALITY;}
{ASSIGNOP}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ASSIGNOP;}
{WHITESPACE}    	{
			    ADDTOLINE;
			}
{NEWLINE}		{
			ADDTOLINE;
			lineno++;
			current_line[0]='\0';
			charno=0;
			}
{ACOMMENT}		{
			ADDTOLINE;
			}
","			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ',';}
";"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ';';}
"{"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '{';}
"}"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '}';}
"("			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '(';}
")"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ')';}
"["			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '[';}
"]"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ']';}
":"                     {ADDTOLINE;yylval.t=STR;SAVETOKEN;return ':';}
"."			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '.';}
"="			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '=';}
"+"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '+';}
"-"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '-';}
"*"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '*';}
"/"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '/';}
"%"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '%';}
"&"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '&';}
"|"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '|';}
"~"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '~';}
"^"			{ADDTOLINE;yylval.t=STR;SAVETOKEN;return '^';}
{ELLIPSIS}		{ADDTOLINE;yylval.t=STR;SAVETOKEN;return ELLIPSIS;}	

%%

int yywrap()
    {
    return 1;
    }


/*
main()
    {
    int token;

    do
        {
        token=yylex();
            std::cout << "token is " << token << " text is " << yytext << std::endl;
        } while(token!=EOF);
    }
*/
