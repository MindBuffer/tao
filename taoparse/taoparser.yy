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
#include <sstream>
#include <string>
#include "taoparserdefs.h"

int yyerror(char *s);

//#ifdef LINUX
int yylex(void);
//#endif

int yyparse(void);

extern int token;
extern char scriptname[];
extern int lineno;
extern int charno;
extern char current_line[];
extern char idname[];
extern int yyleng;
extern char *yytext;
extern FILE *yyin;
int streq(const char *str1, const char *str2);
void INDENT(void);
void UNINDENT(void);

char scriptname[256]="";
char scriptname_minus_suffix[256]="";
char what_I_expected_here[256]="";
char current_instr_class[20]="";
char current_device_class[20]="";
char current_id[256]="";
int audioRate;
int indentLevel=0;
char indent[256]="";
int indentCnt=0;
int is_array_of_outputs;
int output_array_size;
int instr_array_size;
int instr_array_size_given;
int instr_array_index;
int in_score_block=0;

#define parse_error(mesg) \
{ \
std::cerr << "\nError in line " << lineno << " of \"" << scriptname \
     << "\": " << mesg << std::endl << current_line << std::endl; \
for (int c=0;c<(int)strlen(current_line)-yyleng;c++) \
if (current_line[c]=='\t') std::cerr << "\t"; \
else std::cerr << " "; \
std::cerr << "^" << std::endl; \
std::cerr << "If this error message doesn't help, try checking\n" << \
	"for missing ;'s or ...'s on, or just before line " << lineno << std::endl; \
} 

#define YYERROR_VERBOSE

/*
 * This parser accepts valid Tao scripts and translates them into valid C++
 * programs which can be compiled and linked against the Tao synthesis library
 * libtao.so . At the moment the parser has very little knowledge of the semantics
 * of a Tao script and so will not catch semantic errors. The main stack value
 * used is simply a `char *' representation of the non-terminals and terminals.
 * Thus when a particular rule of the grammar is matched the components on the
 * right hand side of the rule are,  for the most part, just reassembled into
 * a string which passed as the semantic result of the rule up to the higher
 * level rules. For this purpose the following BUILD* macros are provided. There
 * is one BUILD macro for all rules with anywhere between 1 and 8 components on
 * the right hand side of the rule. When one of these macros is invoked it
 * simply writes the string representations of $1..$n into a ostrstream called
 * `obuffer' which is then frozen and copied into a dynamically allocated string
 * which is then pointed to by $$.s (the semantic value for the left hand
 * side of the rule). After this $1..$n are deleted.
 * 
 * There are many cases in which it is not appropriate to simplistically echo
 * the string representations through to the output,  instead some translation
 * is necessary. For example any occurrence of the token `String' must be
 * replaced with `TaoString' as that is the name of the actual C++ class.
 * Another example is that a pitch literal such as `50 Hz' is translated into
 * the following: `TaoPitch(50, TaoPitch::frq)' i.e. a new instance of class
 * `TaoPitch'. More complex examples involve compound statements such as `For'
 * statements,  `Print' statements and `If' statements,  as well as the score
 * control structures.
 * 
 * But in most cases no translation is necessary, just validation that the
 * syntax of script is correct and then reconstructing the output stream pretty
 * much the same as the input stream of tokens was. In these cases you will see
 * the BUILD* macros in use.
 * 
 * It might seem a little futile to parse the whole script properly only to
 * reassemble the fragments to form another text-file which then has to be parsed
 * and semantically checked by the C++ compiler, but eventually the need for a C++
 * compiler will be done away with and this parser will probably become the basis
 * for a completely interpreted Tao script language. Until that time though this
 * is the best way of strictly defining the syntax of a Tao script and knowing
 * that the translated output will always be a valid C++ code fragment.
 * 
 */
 
#define BUILD1(result,arg1) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s;

#define BUILD2(result,arg1,arg2) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s;

#define BUILD3(result,arg1,arg2,arg3) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << " " << arg3.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; 

#define BUILD4(result,arg1,arg2,arg3,arg4) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << " " << arg3.s << " " << arg4.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; \
    delete [] arg4.s;

#define BUILD5(result,arg1,arg2,arg3,arg4,arg5) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << " " << arg3.s << " " << arg4.s \
	   << " " << arg5.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; \
    delete [] arg4.s; \
    delete [] arg5.s;

#define BUILD6(result,arg1,arg2,arg3,arg4,arg5,arg6) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << " " << arg3.s << " " << arg4.s \
	   << " " << arg5.s << " " << arg6.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; \
    delete [] arg4.s; \
    delete [] arg5.s; \
    delete [] arg6.s;

#define BUILD7(result,arg1,arg2,arg3,arg4,arg5,arg6,arg7) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << " " << arg3.s << " " << arg4.s \
	   << " " << arg5.s << " " << arg6.s << " " << arg7.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; \
    delete [] arg4.s; \
    delete [] arg5.s; \
    delete [] arg6.s; \
    delete [] arg7.s;

#define BUILD8(result,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << " " << arg2.s << " " << arg3.s << " " << arg4.s \
	   << " " << arg5.s << " " << arg6.s << " " << arg7.s << " " << arg8.s \
	   << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; \
    delete [] arg4.s; \
    delete [] arg5.s; \
    delete [] arg6.s; \
    delete [] arg7.s; \
    delete [] arg8.s;

#define BUILD9(result,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9) \
    std::ostringstream obuffer; \
    obuffer << arg1.s << arg2.s << arg3.s << arg4.s \
	   << arg5.s << arg6.s << arg7.s << arg8.s << arg9.s << std::ends; \
    result.t=STR; \
    strallocpy(result.s, obuffer.str().c_str()); \
    delete [] arg1.s; \
    delete [] arg2.s; \
    delete [] arg3.s; \
    delete [] arg4.s; \
    delete [] arg5.s; \
    delete [] arg6.s; \
    delete [] arg7.s; \
    delete [] arg8.s; \
    delete [] arg9.s;

static void strallocpy(char *&s1, const char *s2)
{
    strcpy(s1 = new char[strlen(s2) + 1], s2);
}


%}

%token INTLIT FLOATLIT PITCH ACCESSPOINT PARAM INTEGER COUNTER LEFT RIGHT TOP
%token STRING RECTANGLE CIRCLE ELLIPSE TRIANGLE BOW HAMMER STOP BOTTOM CENTRE
%token CONNECTOR OUTPUT ID STRLIT AUDIO RATE MATHFUNC1 MATHFUNC2 STRENGTH SIGNAL
%token FLAG AT ATFOR ELLIPSIS SCORE FROM TO BEFORE AFTER EVERY CONTROLRATE
%token IF ELSE PRINT NEWLINEKWD OUTPUTCH FRACTION POSITIONKWD LINEAR EXPON
%token PLACEAT PLACEABOVE PLACEBELOW JOIN LABEL START END STEREO MONO QUAD
%token PLACELEFTOF PLACERIGHTOF REMOVE ACTIVATE DEACTIVATE SETMASS SETPOSITION
%token SETVELOCITY SETGRAVITY SETHEIGHT SETHARDNESS SETMAXIMPACTS RESET DROP
%token SETFORCE GETINSTRUMENT APPLYFORCE CLEAR TRUE FALSE INIT FOR INCDEC
%token GETMAGNIFICATION GETVELOCITY GETPOSITION GETMASS GETNAME GETGRAVITY
%token GETHEIGHT GETDAMPING GETHARDNESS GETMAXIMPACTS NUMBEROFIMPACTS GETFORCE
%token ASPITCH ASOCTAVE ASFREQUENCY ASNAME SETMAGNIFICATION SETDAMPING
%token RESETDAMPING SETDECAY RESETDECAY LOCKLEFT LOCKRIGHT LOCKTOP LOCKBOTTOM
%token LOCKPERIMETER LOCKCORNERS LOCKENDS LOCK IN ELSEIF TIME TICK
%token GETINITVELOCITY SETINITVELOCITY GETAMOUNT SETAMOUNT GETXFREQUENCY
%token GETYFREQUENCY

%right ASSIGNOP '='  /* += -= *= /= <<= >>= &= |= */
%left  OR	     /* logical or */
%left  AND	     /* logical and */
%left  '|'	     /* bitwise or */
%left  '^'	     /* bitwise xor */
%left  '&'	     /* bitwise and */
%left  EQUALITY	     /* == != */
%left  RELOP	     /* < > <= >= */
%left  SHIFTOP      /* << >> */
%nonassoc UPERCENT TIMEUNITS PITCHUNITS /* 50%, 10 secs, 8.03 pch etc. */
%left  '+' '-'	     /* arithmetic operators */
%left  '*' '/' '%'   /* multiplicative operators */
%right UMINUS	     /* unary plus or minus */
%right NOT	     /* logical not */
%right '~'	     /* bitwise not */
%right INCDEC	     /* increment, decrement */
%left  '.'	     /* member selector */

%start tao_script

%%

tao_script	    :	 {

std::cout <<
"//////////////////////////////////////////////////////////////////////////////////\n"
"// This is the translated version of script \"" << scriptname << "\".\n"
"//\n"
"// It contains automatically generated definitions for the following functions\n"
"// which are required by the Tao library in order to produce a complete\n"
"// executable:\n"
"//\n"
"//   int    taoAudioRate()	- returns the audio sampling rate in Hz.\n"
"//   float  taoScoreDuration()	- returns the duration of the score\n"
"//				  in seconds.\n"
"//   void   taoInit()		- this function is called just before execution\n"
"//				  of the score and contains user specified code\n"
"//				  for initialising variable values, devices,\n"
"//				  instruments and connections.\n"
"//   void   taoScore()		- this function is called once on every tick of\n"
"//				  the synthesis engine and contains all the code\n"
"//				  representing the user's time-domain inter-\n"
"//				  actions with the instruments and devices.\n"
"//\n"
"// The `main()' function defined at the end of this generated file registers\n"
"// the functions described above with the top level object `tao' (an instance\n"
"// of class `Tao'), and then invokes the member function `tao.main()'. This\n"
"// function enters the main synthesis engine loop which calculates the number\n"
"// of ticks specified by the score duration, and updates the graphics window\n"
"// (if graphics mode is on). It only exits if the graphics window is closed, if\n"
"// the ESC key is pressed whilst the graphics window has the mouse focus, if\n"
"// CTRL-C is pressed in the shell window from which Tao was invoked, or the\n"
"// `performance' reaches its natural conclusion.\n"
"//////////////////////////////////////////////////////////////////////////////////\n"
"\n"
"#include \"taodefs.h\" \n"
"#include <cmath>\n"
"#include <iostream>\n"
"\n"
"Tao tao;\n\n"
;
			}
        		audio_rate_decl decl_section init_block score_block
			{
std::cout <<
"\n\nmain(int argc, char *argv[])\n"
"    {\n"
"    tao.initStartAndEnd();\n"
"    tao.audioRateFunc(taoAudioRate);\n"
"    tao.initFunc(taoInit);\n"
"    tao.scoreDurationFunc(taoScoreDuration);\n"
"    tao.scoreFunc(taoScore);\n"
"    tao.main(argc, argv);\n"
"    }\n"
"\n\n// End of C++ program generated from script \"" << scriptname << "\"\n";

			}
			;

audio_rate_decl	    : AUDIO RATE ':' INTLIT ';'
			{
std::cout << "\n// Audio rate: <sample_rate> ;"
	"\n\nint taoAudioRate() {return " << $4.i << ";}\n\n"
	"\n\n// Declarations\n";
	
			delete [] $1.s;
			delete [] $2.s;
			delete [] $3.s;
			delete [] $4.s;
			audioRate=$4.i;
			}
			;
		    
decl_section	    :
		         {
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }
		    | declarations
		         {BUILD1($$,$1);
			 }
		    ;
 
declarations	    : declaration
		    | declaration declarations
		    ;

declaration	    : instr_decl ';'	{std::cout << "\n" << $1.s << ";\n";}
		    | device_decl ';'	{std::cout << "\n" << $1.s << ";\n";}
		    | var_decl ';'	{std::cout << "#line " << lineno << " \"" << scriptname << "\"\n" << $1.s << ";\n";}
		    | pitch_decl ';'	{std::cout << "\n" << $1.s << ";\n";}
		    | access_decl ';'	{std::cout << "\n" << $1.s << ";\n";}
		    ;

/* Rules for instrument declarations */

instr_decl	    : STRING x_instr_decl_list
		        {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoString" << $2.s << std::ends;
			//$$.s=obuffer.str().c_str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    | CIRCLE x_instr_decl_list
		        {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoCircle" << $2.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    | RECTANGLE xy_instr_decl_list
		        {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoRectangle" << $2.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    | ELLIPSE xy_instr_decl_list
		        {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoEllipse" << $2.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    | TRIANGLE xy_instr_decl_list
		        {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoTriangle" << $2.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    ;


x_instr_decl_list   : x_instr_decl_item
		         {
			 BUILD1($$,$1);
			 }
		    | x_instr_decl_item ',' x_instr_decl_list
		         {
			 BUILD3($$, $1, $2, $3);
			 }
	            ;

xy_instr_decl_list  : xy_instr_decl_item
		         {
			 BUILD1($$,$1);
			 }
		    | xy_instr_decl_item ',' xy_instr_decl_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

pitch_literal	    : FLOATLIT PITCHUNITS
			{
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			if (streq($2.s, "pch"))

obuffer << "TaoPitch(" << $1.f << "f, TaoPitch::pch)" << std::ends;

			else if (streq($2.s, "oct"))

obuffer << "TaoPitch(" << $1.f << "f, TaoPitch::oct)" << std::ends;

			else if (streq($2.s, "Hz"))

obuffer << "TaoPitch(" << $1.f << "f, TaoPitch::frq)" << std::ends;

			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;			
			}
		    | INTLIT PITCHUNITS
			{
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			if (streq($2.s, "pch"))

obuffer << "TaoPitch(" << $1.f << "f, TaoPitch::pch)" << std::ends;

			else if (streq($2.s, "oct"))

obuffer << "TaoPitch(" << $1.f << "f, TaoPitch::oct)" << std::ends;

			else if (streq($2.s, "Hz"))

obuffer << "TaoPitch(" << $1.f << "f, TaoPitch::frq)" << std::ends;

		        //$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    ;

duration_literal    : FLOATLIT TIMEUNITS
			{
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			float timeFactor=1.0;
			if (streq($2.s, "secs"))	    timeFactor=1.0;
			else if (streq($2.s, "sec"))	    timeFactor=1.0;
			else if (streq($2.s, "mins"))	    timeFactor=60.0;
			else if (streq($2.s, "min"))	    timeFactor=60.0;
			else if (streq($2.s, "msecs"))	    timeFactor=0.001;
			obuffer << $1.f * timeFactor << "f" << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    | INTLIT TIMEUNITS
			{
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			float timeFactor=1.0;
			if (streq($2.s, "secs"))	    timeFactor=1.0;
			else if (streq($2.s, "sec"))	    timeFactor=1.0;
			else if (streq($2.s, "mins"))	    timeFactor=60.0;
			else if (streq($2.s, "min"))	    timeFactor=60.0;
			else if (streq($2.s, "msecs"))	    timeFactor=0.001;
			obuffer << $1.f * timeFactor << "f" << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    ;

array_size	    : 
		        {
			instr_array_size_given=0;
			$$.s=new char[1];
			$$.s[0]='\0';
			}
		    | INTLIT
			{
			std::ostringstream obuffer;
			instr_array_size_given=1;
			instr_array_size=$1.i;
			obuffer << $1.i << std::ends;
			$$.t=STR;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			}
		    ;			

/***********************************************************************************
 * Rules for instrument declarations requiring only one frequency,  i.e. strings and
 * circular sheets.
 */

x_instr_decl_item   : x_instr_var_decl
		         {
			 BUILD1($$,$1);
			 }
		    | x_instr_array_decl
		         {
			 BUILD1($$,$1);
			 }
		    ;
		    
x_instr_var_decl    : ID '(' pitch_literal ',' duration_literal ')'
		         {
			 std::ostringstream obuffer;
			 INDENT();

/*********************************************************************************/
obuffer << "\n" << indent << $1.s << "(\"" << $1.s << "\", "
	<< $3.s << ", " << $5.s << ")" << std::ends;
/*********************************************************************************/

			 UNINDENT();
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    ;
		    
x_instr_array_decl  : ID '[' array_size ']' '=' '{' x_instr_array_list '}'
		         {
			 std::ostringstream obuffer;
			 
/*********************************************************************************/
obuffer << "\n    " << $1.s << "[" << $3.s << "]=";
obuffer << "\n        {"
	<< $7.s
	<< "\n        }" << std::ends;
/*********************************************************************************/

			 instr_array_index=0;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 delete [] $7.s;
			 delete [] $8.s;
			 }
		    ;
		    
x_instr_array_list  : x_instr_initialiser
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n        " << current_instr_class << $1.s << std::ends;
/*********************************************************************************/
			
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | x_instr_initialiser ',' x_instr_array_list
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n        " << current_instr_class << $1.s << "," << $3.s << std::ends;
/*********************************************************************************/
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 }
		    ;

x_instr_initialiser : '(' pitch_literal ',' duration_literal ')'
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "(\"" << current_id << "[" << instr_array_index << "]\"" <<
", " << $2.s << ", " << $4.s << ")" << std::ends;
/*********************************************************************************/

			 instr_array_index++;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;			 
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $4.s;			 
			 delete [] $5.s;			 
			 }
		    ;
	
		    
/*********************************************************************************
 * Rules for instrument declarations requiring two frequencies,  i.e. rectangular
 * elliptical and triangular sheets.
 */

xy_instr_decl_item  : xy_instr_var_decl
		         {
			 BUILD1($$,$1);
			 }
		    | xy_instr_array_decl
		         {
			 BUILD1($$,$1);
			 }
		    ;
		    
xy_instr_var_decl   : ID '(' pitch_literal ',' pitch_literal ','
		      duration_literal ')'
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n    " << $1.s << "(\"" << $1.s << "\", "
	<< $3.s << ", " << $5.s << ", " << $7.s << ")" << std::ends;
/*********************************************************************************/

			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 delete [] $7.s;
			 delete [] $8.s;
			 }
		    ;
		    
xy_instr_array_decl : ID '[' array_size ']' '=' '{' xy_instr_array_list '}'
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n    " << $1.s << "[" << $3.s << "]=";
obuffer << "\n        {"
	<<            $7.s
	<< "\n        }" << std::ends;
/*********************************************************************************/

			 instr_array_index=0;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 delete [] $7.s;
			 delete [] $8.s;
			 }
		    ;
		    
xy_instr_array_list : xy_instr_initialiser
		         {
			 std::ostringstream obuffer;
			 
/*********************************************************************************/
obuffer << "\n        " << indent << current_instr_class << $1.s << std::ends;
/*********************************************************************************/
			
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | xy_instr_initialiser ',' xy_instr_array_list
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n        " << indent << current_instr_class << $1.s
	<< "," << $3.s << std::ends;
/*********************************************************************************/
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 }
		    ;

xy_instr_initialiser: '(' pitch_literal ',' pitch_literal ',' duration_literal ')'
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "(\"" << current_id << "[" << instr_array_index << "]\"" <<
", " << $2.s << ", " << $4.s << ", " << $6.s << ")" << std::ends;
/*********************************************************************************/

			 instr_array_index++;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;			 
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $4.s;			 
			 delete [] $5.s;			 
			 delete [] $6.s;			 
			 delete [] $7.s;			 
			 }
		    ;
	

/*********************************************************************************
 * Rules for device declarations.
 */

device_decl	    : BOW device_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoBow " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | HAMMER device_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoHammer " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | CONNECTOR device_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoConnector " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | OUTPUT output_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoOutput " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | STOP device_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoStop " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

device_decl_list    : device_decl_item
		         {
			 BUILD1($$,$1);
			 }
		    | device_decl_item ',' device_decl_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

device_decl_item    : ID
		         {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << $1.s << "(\"" << $1.s << "\")" << std::ends;
/*********************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | ID '[' INTLIT ']'
		         {
			 std::ostringstream obuffer;
			 int counter;

			 INDENT();
			    
/*********************************************************************************/
obuffer << "\n" << indent << $1.s << "[" << $3.s << "]=";
/*********************************************************************************/

			 INDENT();

/*********************************************************************************/
obuffer << "\n" << indent << "{";
/*********************************************************************************/
			    
			 for (counter=0;counter<$3.i-1;counter++)
			     {
				
/*********************************************************************************/
obuffer << "\n" << indent << current_device_class <<
"(\"" << $1.s << counter << "\"),";
/*********************************************************************************/

			     }

/*********************************************************************************/
obuffer << "\n" << indent << current_device_class << 
"(\"" << $1.s << counter << "\")";
obuffer << "\n" << indent << "}" << std::ends;
/*********************************************************************************/

			 UNINDENT();
			 UNINDENT();
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 }
		    ;


/*********************************************************************************
 * Syntax is different for Output device. The number of channels is always given
 * as in name(2), name(stereo) and is then optionally followed by an array part
 * which says how many outputs with that specification to create.
 */

output_decl_list    : output_decl_item
		         {
			 BUILD1($$,$1);
			 }
		    | output_decl_item  ',' output_decl_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }

		    ;

output_decl_item    : ID '(' num_channels ')' output_array_part
		         {
			 std::ostringstream obuffer;
			 int counter;
			 if (is_array_of_outputs)
			    {
			    INDENT();
			    
/*********************************************************************************/
obuffer << "\n" << indent << $1.s << $5.s << "=";
/*********************************************************************************/

			    INDENT();

/*********************************************************************************/
obuffer << "\n" << indent << "{";
/*********************************************************************************/
			    
			    for (counter=0;counter<output_array_size-1;counter++)
				{
				
/*********************************************************************************/
obuffer << "\n" << indent <<
    "TaoOutput(\"" << $1.s << "_" << counter << "\", " << 
    "\"" << scriptname_minus_suffix << "_" << $1.s << "_" << counter << "\", " <<
    $3.s << "),";
/*********************************************************************************/

				}

/*********************************************************************************/
obuffer << "\n" << indent <<
    "TaoOutput(\"" << $1.s << "_" << counter << "\", " << 
    "\"" << scriptname_minus_suffix << "_" << $1.s << "_" << counter << "\", " <<
    $3.s << ")";
obuffer << "\n" << indent << "}" << std::ends;
/*********************************************************************************/

			    UNINDENT();
			    UNINDENT();
			    }
			 else
			    {
			    INDENT();
			    
/*********************************************************************************/
obuffer << "\n" << indent <<
    $1.s << "(\"" << $1.s << "\", \"" << scriptname_minus_suffix << "_" << $1.s <<
    "\", " << $3.s << ")" << std::ends;
/*********************************************************************************/

			    UNINDENT();
			    }
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 }
		    ;
		    
output_array_part   :	 {
			 is_array_of_outputs=0;
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }
		    | '[' INTLIT ']'
			 {
			 is_array_of_outputs=1;
			 output_array_size=$2.i;
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

num_channels	    : INTLIT
			 {
			 std::ostringstream obuffer;
			 obuffer << $1.i << std::ends;
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | STEREO
			 {
			 std::ostringstream obuffer;
			 obuffer << 2 << std::ends;
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | MONO
			 {
			 std::ostringstream obuffer;
			 obuffer << 1 << std::ends;
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | QUAD
			 {
			 std::ostringstream obuffer;
			 obuffer << 4 << std::ends;
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    ;

/*********************************************************************************
 * Rules for parameter declarations.
 */

var_decl	    : PARAM var_decl_list
			 {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "float " << $2.s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | SIGNAL var_decl_list
			 {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "float " << $2.s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | INTEGER var_decl_list
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "int " << $2.s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | COUNTER var_decl_list
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "int " << $2.s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    | FLAG var_decl_list
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "int " << $2.s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

var_decl_list	    : var_decl_item
		         {
			 BUILD1($$,$1);
			 }
		    | var_decl_item ',' var_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << $1.s << " " << $2.s << " " << $3.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 }
		    ;

var_decl_item	    : var_var_decl
		         {
			 BUILD1($$,$1);
			 }
		    | var_array_decl
		         {
			 BUILD1($$,$1);
			 }
		    ;

var_var_decl	    : ID
		         {
			 BUILD1($$,$1);
			 }
		    | ID '=' expr
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;
		    		    
var_array_decl	    : ID '[' array_size ']' var_arr_init_part
		         {
			 BUILD5($$,$1,$2,$3,$4,$5);
			 }
		    ;
		    
var_arr_init_part   :
			 {
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }
		    | '=' var_array_init
			 {
			 BUILD2($$,$1,$2);
			 }
		    ;
		    

var_array_init	    : '{' var_array_list '}'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

var_array_list	    : expr
		         {
			 BUILD1($$,$1);
			 }
		    | expr ',' var_array_list
			 {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

/* Rules for pitch declaration */

pitch_decl	    : PITCH pitch_decl_list
			 {
			 std::ostringstream obuffer;
			 obuffer << "TaoPitch " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

pitch_decl_list	    : pitch_decl_item
			 {
			 BUILD1($$,$1);
			 }
		    | pitch_decl_item ',' pitch_decl_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

pitch_decl_item	    : pitch_var_decl
		         {
			 BUILD1($$,$1);
			 }
		    | pitch_array_decl
		         {
			 BUILD1($$,$1);
			 }
		    ;
		   		   
pitch_var_decl	    : ID
		         {
			 BUILD1($$,$1);
			 }
		    | ID '=' pitch_literal
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;
		    
pitch_array_decl    : ID '[' array_size ']' pch_arr_init_part
		         {
			 BUILD5($$,$1,$2,$3,$4,$5);
			 }
		    ;
		    
pch_arr_init_part   :
			 {
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }
		    | '=' pitch_array_init
		         {
			 BUILD2($$,$1,$2);
			 }
		    ;

pitch_array_init    : '{' pitch_array_list '}'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

pitch_array_list    : pitch_literal
		         {
			 BUILD1($$,$1);
			 }
		    | pitch_literal ',' pitch_array_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

access_decl	    : ACCESSPOINT access_decl_list
		         {
			 std::ostringstream obuffer;
			 obuffer << "TaoAccessPoint " << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

access_decl_list    : access_decl_item
		         {
			 BUILD1($$,$1);
			 }
		    | access_decl_item ',' access_decl_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

access_decl_item    : access_var_decl
		         {
			 BUILD1($$,$1);
			 }
		    | access_array_decl
		         {
			 BUILD1($$,$1);
			 }
		    ;
		    
access_var_decl	    : ID
		         {
			 BUILD1($$,$1);
			 }
		    | ID '=' access_point
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;
		    
access_array_decl   : ID '[' array_size ']' acc_arr_init_part
		         {
			 BUILD5($$,$1,$2,$3,$4,$5);
			 }
		    ;

acc_arr_init_part   : 
		         {
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 $$.t=STR;
			 }
		    | '=' access_array_init 
		         {
			 BUILD2($$,$1,$2);
			 }
		    ;

access_array_init   : '{' access_array_list '}'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

access_array_list   : access_point
		         {
			 BUILD1($$,$1);
			 }
		    | access_point ',' access_array_list
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

access_point	    : variable '(' instr_coords ')'
		         {
			 BUILD4($$,$1,$2,$3,$4);
			 }
		    ;

instr_coords	    : expr
		         {
			 BUILD1($$,$1);
			 }
		    | expr ',' expr
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

init_block	    : INIT 
			 {

/*******************************************************************************/
std::cout << "\n// Init: <statements> ..."
	"\n\nvoid taoInit()";
/*******************************************************************************/

			 }
			 ':' 
			 {

/*******************************************************************************/
std::cout << "\n    {";
/*******************************************************************************/

			 INDENT();
			 }
			 
		      init_body ELLIPSIS
		      
		         {
			 UNINDENT();
			 
/*******************************************************************************/
std::cout << "\n    }\n";
/*******************************************************************************/
			 }
		    ;

init_body	    :
		    | statements
		    ;




		    
score_block	    : SCORE duration_literal ':'
		         {

/*******************************************************************************/
std::cout << "\n// Score <duration> : <statements> ..."
	"\n\nfloat taoScoreDuration() {return " << $2.f << "f;}"
	"\n\nvoid taoScore()\n"
	"    {\n"
	"    tao.initStartAndEnd();\n";
/*******************************************************************************/

			 INDENT();
			 in_score_block=1;
			 }
		      body ELLIPSIS
		         {
			 UNINDENT();
			 
/*******************************************************************************/
std::cout << "\n\n" << indent << "    tao.popStartAndEnd();";
std::cout << "\n" << indent << "    }";
/*******************************************************************************/

			 delete [] $1.s;			 
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $5.s;			 
			 }
		    ;

score_statements    : score_statement
		    | score_statement score_statements
		    ;

score_statement	    : 	{
/*******************************************************************************/
std::cout << "\n#line " << lineno << " \"" << scriptname << "\"";
/*******************************************************************************/
                      	}
		      statement
		    | control_structure
		    ;

control_structure   : head ':' body ELLIPSIS
		         {

/*******************************************************************************/
std::cout << "\n" << indent << "tao.popStartAndEnd();";
std::cout << "\n" << indent << "}\n";
/*******************************************************************************/

			 UNINDENT();
			 }
		    ;

head		    : AT expr timeunits at_for_part
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 if ($4.s[0]=='\0')   // no for part
			     {
			     float timeFactor=1.0;
			     float target;

			     if (streq($3.s,"min") || streq($3.s,"mins"))
				 timeFactor*=60.0;
			     else if (streq($3.s,"msecs"))
				 timeFactor/=1000.0;
			     
			     if ($2.t&NUM)
				 {
				 target=$2.f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << "if (Tick==(long)(" << target << "f*"
	<< "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
	<< "\n" << indent << "    {"
	<< "\n" << indent << "    tao.pushStartAndEnd2();" << std::ends;
/*******************************************************************************/

				 }
			     else 
			         {

/*******************************************************************************/
obuffer << "\n" << indent <<
		"if (Tick==(long)(" << $2.s << "*" << timeFactor << "f*"
	<< "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd2();" << std::ends;
/*******************************************************************************/

			         }
			     }
			 else
			     {
			     float timeFactor=1.0;
			     float start, end;

			     if (streq($3.s,"min") || streq($3.s,"mins"))
			         timeFactor=60.0;
			     else if (streq($3.s,"msecs"))
				 timeFactor=0.001;

			     if ($2.t&NUM && $4.t&NUM)
				  {
				  start=$2.f*timeFactor;
				  end=start+$4.f;
				
/*******************************************************************************/ 
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << end << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&"
        << "\n" << indent << " Tick>=(long)((tao.newStart=" << start << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();" << std::ends;
/*******************************************************************************/

			          }
			     else {

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << $2.s << "*"
        << "\n" << timeFactor << "+" << $4.s << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&"
        << "\n" << indent << " Tick>=(long)((tao.newStart=" << $2.s << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();" << std::ends;
/*******************************************************************************/

				  }
			     }

			 INDENT();

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 std::cout << $$.s;
			 }
		    | FROM expr timeunits TO expr timeunits
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float start, end;

			 if (streq($6.s,"min") || streq($6.s,"mins"))
			     timeFactor=60.0;
			 else if (streq($6.s,"msecs"))
			     timeFactor=0.001;

			 if ($5.t&NUM)
			     {
			     end=$5.f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << end << "f)*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&";
/*******************************************************************************/

			     }
			 else
			     {

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << $5.s << "*" << 
						timeFactor << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&";
/*******************************************************************************/

                             }

			 if (streq($3.s,"min") || streq($3.s,"mins"))
			     timeFactor=60.0;
			 else if (streq($3.s,"msecs"))
			     timeFactor=0.001;

			 if ($2.t&NUM)
			     {
			     start=$2.f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << " Tick>=(long)((tao.newStart=" << start << "f)*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();" << std::ends;
/*******************************************************************************/

			     }
			 else
			     {

/*******************************************************************************/
obuffer << "\n" << indent << " Tick>=(long)((tao.newStart=" << $2.s << "*" <<
							timeFactor << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

			     }

			 INDENT();
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 std::cout << $$.s;
			 }
		    | BEFORE expr timeunits
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float start, end;

			 if (streq($3.s,"min") || streq($3.s,"mins"))
			     timeFactor=60.0;
			 else if (streq($3.s,"msecs"))
			     timeFactor=0.001;

			 if ($2.t&NUM)
			     {
			     end=$2.f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<(long)(tao.newStart=tao.start,"
		        "(tao.newEnd=" << end << "f)*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

			     }
			 else
			     {

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<(long)(tao.newStart=tao.start,"
		    "(tao.newEnd="<<$2.s<<"*"<<timeFactor<<")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

                             }

			 INDENT();
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 std::cout << $$.s;
			 }
		    | AFTER expr timeunits
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float start, end;

			 if (streq($3.s,"min") || streq($3.s,"mins"))
			     timeFactor=60.0;
			 else if (streq($3.s,"msecs"))
			     timeFactor=0.001;

			 if ($2.t&NUM)
			     {
			     start=$2.f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<(long)(tao.newEnd=tao.end,"
		    "(tao.newStart=" << start << "f)*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();" << std::ends;
/*******************************************************************************/

			     }
			 else
			     {

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<(long)(tao.newEnd=tao.end,"
		    "(tao.newStart=" << $2.s << "*" << timeFactor << ")*"
	<< "\n" << indent << "tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

                             }

			 INDENT();
	
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 std::cout << $$.s;
			 }
		    | EVERY expr timeunits
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float interval;

			 if (streq($3.s,"min") || streq($3.s,"mins"))
			     timeFactor=60.0;
			 else if (streq($3.s,"msecs"))
			     timeFactor=0.001;

			 if ($2.t&NUM)
			     {
			     interval=$2.f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick%(long)(" << interval << "f*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate)==0)"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd2();\n" << std::ends;
/*******************************************************************************/

			     }
			 else
			     {

/*******************************************************************************/
obuffer  << "\n" << indent << "if(Tick%(long)(" << $2.s << "*"
						<< timeFactor << "*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate)==0)"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd2();" << std::ends;
/*******************************************************************************/

			     }

			 INDENT();

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 std::cout << $$.s;
			 }
		    | CONTROLRATE INTLIT
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick%" << $2.i << "L==0)"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd2();" << std::ends;
/*******************************************************************************/

			 INDENT();

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 std::cout << $$.s;
			 }
		    ;

at_for_part	    :
			 {
			 $$.t=STR;
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }			 
		    | ATFOR expr timeunits
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float targetTime;
			 if (streq($3.s,"min") || streq($3.s,"mins"))
			     {
			     timeFactor=60.0;
			     }
			 else if (streq($3.s,"msecs"))
			     {
			     timeFactor=0.001;
			     }
			 if ($2.t&NUM) {
			     obuffer << $2.f * timeFactor << "f" << std::ends;
			     $$.f=$2.f*timeFactor;
			     $$.t=FLT;
			     }
			 else {
			     obuffer << $2.s << "*" << timeFactor << std::ends;
			     $$.t=STR;
			     }
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 }		    
		    ;
		    
body		    :
		    | score_statements
		    ;
		    
timeunits	    :
			 {
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }
		    | TIMEUNITS
		         {
			 BUILD1($$,$1);
			 }
		    ;

expr		    : expr '+' expr
		         {
			 std::ostringstream obuffer;

			 if ($1.t&INT && $3.t&INT)
			     {
			     $$.t=INT;
			     $$.i=$1.i + $3.i;
			     obuffer << $$.i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else if ($1.t&NUM && $3.t&NUM)
			     {
			     $$.t=FLT;
			     $$.f=$1.f + $3.f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << $$.f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else
			     {
			     obuffer << $1.s << $2.s << $3.s << std::ends;
			     $$.t=STR;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 }
		    | expr '-' expr
		         {
			 std::ostringstream obuffer;

			 if ($1.t&INT && $3.t&INT)
			     {
			     $$.t=INT;
			     $$.i=$1.i - $3.i;
			     obuffer << $$.i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else if ($1.t&NUM && $3.t&NUM)
			     {
			     $$.t=FLT;
			     $$.f=$1.f - $3.f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << $$.f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else
			     {
			     obuffer << $1.s << $2.s << $3.s << std::ends;
			     $$.t=STR;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 }
		    | expr '*' expr
			 {
			 std::ostringstream obuffer;

			 if ($1.t&INT && $3.t&INT)
			     {
			     $$.t=INT;
			     $$.i=$1.i * $3.i;
			     obuffer << $$.i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else if ($1.t&NUM && $3.t&NUM)
			     {
			     $$.t=FLT;
			     $$.f=$1.f * $3.f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << $$.f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else
			     {
			     obuffer << $1.s << $2.s << $3.s << std::ends;
			     $$.t=STR;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 }
		    | expr '/' expr
		         {
			 std::ostringstream obuffer;

			 if ($1.t&INT && $3.t&INT)
			     {
			     $$.t=INT;
			     $$.i=$1.i / $3.i;
			     obuffer << $$.i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else if ($1.t&NUM && $3.t&NUM)
			     {
			     $$.t=FLT;
			     $$.f=$1.f / $3.f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << $$.f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else
			     {
			     obuffer << $1.s << $2.s << $3.s << std::ends;
			     $$.t=STR;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 }
		    | expr '%' expr		{BUILD3($$,$1,$2,$3);}
		    | '-' expr %prec UMINUS	{BUILD2($$,$1,$2);}
		    | expr RELOP expr		{BUILD3($$,$1,$2,$3);}
		    | expr SHIFTOP expr		{BUILD3($$,$1,$2,$3);}
		    | expr EQUALITY expr	{BUILD3($$,$1,$2,$3);}
		    | expr '&' expr		{BUILD3($$,$1,$2,$3);}
		    | expr '|' expr		{BUILD3($$,$1,$2,$3);}
		    | expr '^' expr		{BUILD3($$,$1,$2,$3);}
                    | '~' expr			{BUILD2($$,$1,$2);}
		    | expr AND expr
			{
			std::ostringstream obuffer;
			obuffer << $1.s << " && " << $3.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			delete [] $3.s;
			}
		    | expr OR expr
			{
			std::ostringstream obuffer;
			obuffer << $1.s << " || " << $3.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			delete [] $3.s;
			}
		    | NOT expr
			{
			std::ostringstream obuffer;
			obuffer << "!" << $2.s << std::ends;
			//$$.s=obuffer.str();
			strallocpy($$.s, obuffer.str().c_str());
			delete [] $1.s;
			delete [] $2.s;
			}
		    | '(' expr ')'
		         {
			 std::ostringstream obuffer;

			 if ($2.t&INT)
			     {
			     $$.t=INT;
			     $$.i=$2.i;
			     obuffer << $$.i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else if ($2.t&NUM)
			     {
			     $$.t=FLT;
			     $$.f=$2.f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << $$.f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 else
			     {
			     obuffer << $1.s << $2.s << $3.s << std::ends;
			     $$.t=STR;
			     //$$.s=obuffer.str();
			     strallocpy($$.s, obuffer.str().c_str());
			     delete [] $1.s;
			     delete [] $2.s;
			     delete [] $3.s;
			     }
			 }
		    | array_expr		{BUILD1($$,$1);}
		    | INCDEC ID			{BUILD2($$,$1,$2);}
		    | ID INCDEC			{BUILD2($$,$1,$2);}
		    | ID			{BUILD1($$,$1);}
		    | num_method_expr		{BUILD1($$,$1);}
		    | MATHFUNC1 '(' expr ')'	{BUILD4($$,$1,$2,$3,$4);}
		    | MATHFUNC2 '(' expr ',' expr ')'
						{BUILD6($$,$1,$2,$3,$4,$5,$6);}
		    | LINEAR '(' expr ',' expr ')'
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);

			 if ($3.t&STR && $5.t&STR)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< $5.s << "-" << $3.s << ")+" << $3.s << ")" << std::ends;
/*******************************************************************************/

			     }
			 else if ($3.t&NUM && $5.t&STR)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< $5.s << "-" << $3.f << "f)+" << $3.f << "f)" << std::ends;
/*******************************************************************************/
			     
			     }
			 else if ($3.t&STR && $5.t&NUM)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< $5.f << "f-" << $3.s << ")+" << $3.s << ")" << std::ends;
/*******************************************************************************/

			     }
			 else if ($3.t&NUM && $5.t&NUM)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< $5.f << "f-" << $3.f << "f)+" << $3.f << "f)" << std::ends;
/*******************************************************************************/

			     }			

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | EXPON '(' expr ',' expr ')'
			 {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);

			 if ($3.t&STR && $5.t&STR)
			     {

/*******************************************************************************/
obuffer << "((float)(" << $3.s <<
	")*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << $5.s << ")/(float)("
	<< $3.s << "))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/

			     }
			 else if ($3.t&NUM && $5.t&STR)
			     {

/*******************************************************************************/
obuffer << "((float)(" << $3.f <<
	"f)*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << $5.s << ")/(float)("
	<< $3.f << "f))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/
			     
			     }
			 else if ($3.t&STR && $5.t&NUM)
			     {

/*******************************************************************************/
obuffer << "((float)(" << $3.s <<
	")*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << $5.f << "f)/(float)("
	<< $3.s << "))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/

			     }
			 else if ($3.t&NUM && $5.t&NUM)
			     {

/*******************************************************************************/
obuffer << "((float)(" << $3.f <<
	"f)*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << $5.f << "f)/(float)("
	<< $3.f << "f))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/

			     }			
		 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | FLOATLIT
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer << $1.f << "f" << std::ends;
			 $$.t=FLT;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }			 
		    | INTLIT
		         {
			 std::ostringstream obuffer;
			 obuffer << $1.i << std::ends;
			 $$.t=INT;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | system_variable
		         {
			 BUILD1($$,$1);
			 }
		    | access_point
		         {
			 BUILD1($$,$1);
			 }
		    | TRUE
		         {
			 std::ostringstream obuffer;
			 obuffer << 1 << std::ends;
			 $$.i=1;
			 $$.t=INT;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | FALSE
		         {
			 std::ostringstream obuffer;
			 obuffer << 0 << std::ends;
			 $$.i=0;
			 $$.t=INT;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | FRACTION
		         {
			 std::ostringstream obuffer;
			 obuffer << $1.s << ".0" << std::ends;
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | POSITIONKWD
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer << $1.f << "f" << std::ends;
			 $$.t=STR;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    ;

array_expr	    : ID array_indeces
		         {
			 BUILD2($$,$1,$2);
			 }
		    ;
		    
array_indeces	    : array_index
		         {
			 BUILD1($$,$1);
			 }
		    | array_index array_indeces
		         {
			 BUILD2($$,$1,$2);
			 }
		    ;
		    
array_index	    : '[' expr ']'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

system_variable	    : START
		         {
			 std::ostringstream obuffer;
			 obuffer << "tao.start" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | END
		         {
			 std::ostringstream obuffer;
			 obuffer << "tao.end" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | TIME
		         {
			 std::ostringstream obuffer;
			 obuffer << "tao.synthesisEngine.time" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | TICK
		         {
			 std::ostringstream obuffer;
			 obuffer << "tao.synthesisEngine.tick" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    ;
		    
variable	    : ID
		         {
			 BUILD1($$,$1);
			 }
		    | array_expr
		         {
			 BUILD1($$,$1);
			 }
		    ;
		    
num_method_expr	    : variable '.' num_method
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

num_method	    : GETMAGNIFICATION '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETXFREQUENCY '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }	
		    | GETYFREQUENCY '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }	
		    | GETVELOCITY '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETINITVELOCITY '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETPOSITION '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETMASS '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETGRAVITY '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETHEIGHT '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETDAMPING '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETHARDNESS '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETMAXIMPACTS '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETAMOUNT '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | NUMBEROFIMPACTS '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETFORCE '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | ASPITCH '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | ASOCTAVE '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | ASFREQUENCY '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

str_method	    : ASNAME '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | GETNAME '(' ')'
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

statement	    : assignment ';'
		         {
			 std::cout << "\n" << indent << $1.s << ";";
			 }
		    | print ';'
		    | for_statement
		    | if_statement
		    | label_statement
		    | void_method_call ';'
		         {
			 std::cout << "\n" << indent << $1.s << ";";
			 }
		    | connection ';'
		         {
			 std::cout << "\n" << indent << $1.s << ";";
			 }
		    | output_statement ';'
		         {
			 std::cout << "\n" << indent << $1.s << ";";
			 }
		    | join_statement ';'
		         {
			 std::cout << "\n" << indent << $1.s << ";";
			 }
		    | apply_device ';'
			 {
			 std::cout << "\n" << indent << $1.s << ";";
			 }
		    ;

connection	    : access_point INCDEC variable INCDEC access_point strength_part
		         {
			 std::ostringstream obuffer;
			 obuffer <<$3.s<<"("<<$1.s<<", "<<$5.s;
			 if ($6.s[0]!='\0')
			     {
			     obuffer << ", " << $6.s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | access_point INCDEC variable INCDEC FLOATLIT strength_part
		         {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<$3.s<<"("<<$1.s<<", "<<$5.f << "f";
			 if ($6.s[0]!='\0')
			     {
			     obuffer << ", " << $6.s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | FLOATLIT INCDEC variable INCDEC access_point strength_part
			 {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<$3.s<<"("<<$1.f<<"f, "<<$5.s;
			 if ($6.s[0]!='\0')
			     {
			     obuffer << ", " << $6.s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | variable INCDEC variable INCDEC access_point strength_part
			 {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<$3.s<<"("<<$1.s<<", "<<$5.s;
			 if ($6.s[0]!='\0')
			     {
			     obuffer << ", " << $6.s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | access_point INCDEC variable INCDEC variable strength_part
			 {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<$3.s<<"("<<$1.s<<", "<<$5.s;
			 if ($6.s[0]!='\0')
			     {
			     obuffer << ", " << $6.s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
		    | variable INCDEC variable INCDEC variable strength_part
			 {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<$3.s<<"("<<$1.s<<", "<<$5.s;
			 if ($6.s[0]!='\0')
			     {
			     obuffer << ", " << $6.s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 delete [] $6.s;
			 }
	            ;

strength_part	    :
		         {
			 $$.s=new char[1];
			 $$.s[0]='\0';
			 }
		    | STRENGTH expr
			 {
			 std::ostringstream obuffer;
			 obuffer << $2.s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

apply_device	    : access_point INCDEC variable
		         {
			 std::ostringstream obuffer;
			 obuffer << $3.s << "(" << $1.s << ")" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 }

		    
output_statement    : variable '.' OUTPUTCH ':' expr
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << $1.s << "." << $3.s << "(" << $5.s << ")" << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $4.s;			 
			 delete [] $5.s;			 
			 }
		    ;

join_statement	    : JOIN access_point TO access_point
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "TaoInstrument::join(" << $2.s << "," << $4.s << ")" << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $4.s;			 
			 }
		    ;

void_method_call    : variable '.' void_methods
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    | access_point '.' void_methods
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

void_methods	    : void_method
		         {
			 BUILD1($$,$1);
			 }
		    | void_method '.' void_methods
		         {
			 BUILD3($$,$1,$2,$3);
			 }
		    ;

void_method	    : setdamping			{BUILD1($$,$1);}
		    | resetdamping			{BUILD1($$,$1);}
		    | setdecay				{BUILD1($$,$1);}
		    | resetdecay			{BUILD1($$,$1);}
		    | lock				{BUILD1($$,$1);}
		    | SETMAGNIFICATION '(' expr ')'	{BUILD4($$,$1,$2,$3,$4);}
		    | LOCKLEFT '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | LOCKRIGHT '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | LOCKTOP '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | LOCKBOTTOM '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | LOCKPERIMETER '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | LOCKCORNERS '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | LOCKENDS '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | RESETDAMPING '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | RESETDECAY '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | REMOVE '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | ACTIVATE '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | DEACTIVATE '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | SETMASS '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | SETPOSITION '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | SETVELOCITY '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | SETINITVELOCITY '(' expr ')'	{BUILD4($$,$1,$2,$3,$4);}
		    | SETGRAVITY '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | SETHEIGHT '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | SETHARDNESS '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | SETMAXIMPACTS '(' expr ')'	{BUILD4($$,$1,$2,$3,$4);}
		    | SETAMOUNT '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | RESET '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | DROP '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | SETFORCE '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | GETINSTRUMENT '(' ')'		{BUILD3($$,$1,$2,$3);}
		    | APPLYFORCE '(' expr ')'		{BUILD4($$,$1,$2,$3,$4);}
		    | CLEAR '(' ')'			{BUILD3($$,$1,$2,$3);}
		    | PLACEAT '(' expr ',' expr ')'
		         {BUILD6($$,$1,$2,$3,$4,$5,$6);}
		    | PLACEABOVE '(' variable ',' expr ')'
		         {BUILD6($$,$1,$2,$3,$4,$5,$6);}
		    | PLACEABOVE '(' variable ')'
		         {BUILD4($$,$1,$2,$3,$4);}
		    | PLACEBELOW '(' variable ',' expr ')'
		         {BUILD6($$,$1,$2,$3,$4,$5,$6);}
		    | PLACEBELOW '(' variable ')'
		         {BUILD4($$,$1,$2,$3,$4);}
		    | PLACELEFTOF '(' variable ',' expr ')'
		         {BUILD6($$,$1,$2,$3,$4,$5,$6);}
		    | PLACELEFTOF '(' variable ')'
		         {BUILD4($$,$1,$2,$3,$4);}
		    | PLACERIGHTOF '(' variable ',' expr ')'
		         {BUILD6($$,$1,$2,$3,$4,$5,$6);}
		    | PLACERIGHTOF '(' variable ')'
		         {BUILD4($$,$1,$2,$3,$4);}
		    ;


setdamping	    : SETDAMPING '(' arglist ')'	{BUILD4($$,$1,$2,$3,$4);}
		    ;
		    
resetdamping	    : RESETDAMPING '(' arglist ')'	{BUILD4($$,$1,$2,$3,$4);}
		    ;
		    
setdecay	    : SETDECAY '(' arglist ')'		{BUILD4($$,$1,$2,$3,$4);}
		    ;
		    
resetdecay	    : RESETDECAY '(' arglist ')'	{BUILD4($$,$1,$2,$3,$4);}
		    ;
		    
lock		    : LOCK '(' arglist ')'		{BUILD4($$,$1,$2,$3,$4);}
		    ;
		    
arglist		    : expr				{BUILD1($$,$1);}
		    | expr ',' arglist			{BUILD3($$,$1,$2,$3);}
		    ;

assignment	    : variable assignop expr		{BUILD3($$,$1,$2,$3);}
		    ;

assignop	    : ASSIGNOP				{BUILD1($$,$1);}
		    | '='				{BUILD1($$,$1);}
		    ;

for_statement	    : for_head ':' statements ELLIPSIS
		         {
		         UNINDENT();

/*******************************************************************************/
std::cout << "\n" << indent << "    }\n";
/*******************************************************************************/

			 }

for_head	    : FOR variable '=' expr TO expr
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
std::cout << "\n" << indent << "for(" << $2.s << "=" << $4.s << ";"
				 << $2.s << "<=" << $6.s << ";"
				 << $2.s << "++)"
        "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 delete [] $4.s;
			 delete [] $5.s;
			 }
			
if_statement	    : if_head ':' statements ELLIPSIS
		         {
			 UNINDENT();
			 
/*******************************************************************************/
std::cout << "\n" << indent << "    }\n";
/*******************************************************************************/

			 }
		    | if_head ':' statements ELLIPSIS else_part
		    ;

if_head		    : IF expr
		         {

/*******************************************************************************/
std::cout << "\n" << indent << "if (" << $2.s << ")";
std::cout << "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();

			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

else_part	    : elseif_head ':' statements ELLIPSIS else_part
		    | else_head ':' statements ELLIPSIS
			 {
			 UNINDENT();
		 
/*******************************************************************************/
std::cout << "\n" << indent << "    }\n";
/*******************************************************************************/

			 }
		    ;

elseif_head	    : ELSEIF expr
		         {
			 UNINDENT();

/*******************************************************************************/
std::cout << "\n" << indent << "    }";
std::cout << "\n" << indent << "else if (" << $2.s << ")";
std::cout << "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();
			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;
		    
else_head	    : ELSE
		         {
			 UNINDENT();

/*******************************************************************************/
std::cout << "\n" << indent << "    }";
std::cout << "\n" << indent << "else";
std::cout << "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();
			 delete [] $1.s;
			 }
		    ;

statements	    : context_dep_statement
		    | context_dep_statement statements
		    ;

context_dep_statement
		    : 	 {
/*******************************************************************************/
std::cout << "\n#line " << lineno << " \"" << scriptname << "\"";
/*******************************************************************************/
			 }
		      statement
		    | control_structure
			 {
			 if (!in_score_block)
			    yyerror("Control structure not allowed here");
			 }
		    ;

print		    : PRINT items
			 {

/*******************************************************************************/
std::cout << "\n" << indent << "std::cout <<";
std::cout << $2.s;
/*******************************************************************************/

			 delete [] $1.s;
			 delete [] $2.s;
			 }
		    ;

items		    : item
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "\n" << indent << "    " << $1.s << ";\n" << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | item ',' items
		         {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "\n" << indent << "    " << $1.s << "<<" << $3.s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 delete [] $2.s;
			 delete [] $3.s;
			 }
		    ;

item		    : expr				{BUILD1($$,$1);}
		    | STRLIT				{BUILD1($$,$1);}
		    | NEWLINEKWD
		         {
			 std::ostringstream obuffer;
			 obuffer << "std::endl" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy($$.s, obuffer.str().c_str());
			 delete [] $1.s;
			 }
		    | str_method_expr			{BUILD1($$,$1);}
		    ;

str_method_expr	    : variable '.' str_method		{BUILD3($$,$1,$2,$3);}
		    ;


label_statement	    : LABEL '(' variable ',' expr ',' expr ',' expr ','
		                STRLIT ',' expr ',' expr ',' expr ')' ';'
			 {

/*******************************************************************************/
std::cout << "\n" << indent << "tao.graphicsEngine.label("
     << "\n" << indent << "    " << $3.s << "," << $5.s
     << "," << $7.s << "," << $9.s << "," << $11.s << "," << $13.s 
     << "," << $15.s << "," << $17.s << ");"
     << std::endl;
/*******************************************************************************/

			 delete [] $1.s;
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $4.s;			 
			 delete [] $5.s;
			 delete [] $6.s;			 
			 delete [] $7.s;			 
			 delete [] $8.s;			 
			 delete [] $9.s;
			 delete [] $10.s;			 
			 delete [] $11.s;		 
			 delete [] $12.s;			 
			 delete [] $13.s;		 
			 delete [] $14.s;			 
			 delete [] $15.s;		 
			 delete [] $16.s;			 
			 delete [] $17.s;		 
			 delete [] $18.s;			 
			 delete [] $19.s;		 
			 }
                    | LABEL '(' variable ',' expr ',' expr ',' expr ',' expr ','
		                STRLIT ',' expr ',' expr ',' expr ')' ';'
			 {

/*******************************************************************************/
std::cout << "\n" << indent << "tao.graphicsEngine.label("
     << "\n" << indent << "    " << $3.s << "," << $5.s
     << "," << $7.s << "," << $9.s << "," << $11.s << "," << $13.s 
     << "," << $15.s << "," << $17.s << "," << $19.s << ");"
     << std::endl;
/*******************************************************************************/

			 delete [] $1.s;
			 delete [] $2.s;			 
			 delete [] $3.s;			 
			 delete [] $4.s;			 
			 delete [] $5.s;
			 delete [] $6.s;			 
			 delete [] $7.s;			 
			 delete [] $8.s;			 
			 delete [] $9.s;
			 delete [] $10.s;			 
			 delete [] $11.s;		 
			 delete [] $12.s;			 
			 delete [] $13.s;		 
			 delete [] $14.s;			 
			 delete [] $15.s;		 
			 delete [] $16.s;			 
			 delete [] $17.s;		 
			 delete [] $18.s;			 
			 delete [] $19.s;		 
			 delete [] $20.s;			 
			 delete [] $21.s;		 
			 }
	             ;

%%


int streq(const char *str1, const char *str2)
    {
    return (strcmp(str1, str2)==0);
    } 


int yyerror (char *s)
    {
    parse_error(what_I_expected_here);
    std::cout << "PARSE_FAILED";
    return 0;
    }

void INDENT(void)
    {
    indentLevel++;
    indent[0]='\0';
    for (indentCnt=0; indentCnt<indentLevel; indentCnt++)
	{
	strcat(indent,"    ");
	}
    }

void UNINDENT(void)
    {
    indentLevel--;
    indent[indentLevel*4]='\0';
    }
    
int main(int argc, char **argv)
    {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
    else
        {
	std::cerr << "usage: taoparse <tao_script_file>" << std::endl;
	exit(1);
        }

    strcpy(scriptname,*argv);
    strcpy(scriptname_minus_suffix, *argv);
    strtok(scriptname_minus_suffix, ".");
    std::cout.setf(std::ios::showpoint);
    
    yyparse();
    }
