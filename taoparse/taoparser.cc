/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTLIT = 258,
     FLOATLIT = 259,
     PITCH = 260,
     ACCESSPOINT = 261,
     PARAM = 262,
     INTEGER = 263,
     COUNTER = 264,
     LEFT = 265,
     RIGHT = 266,
     TOP = 267,
     STRING = 268,
     RECTANGLE = 269,
     CIRCLE = 270,
     ELLIPSE = 271,
     TRIANGLE = 272,
     BOW = 273,
     HAMMER = 274,
     STOP = 275,
     BOTTOM = 276,
     CENTRE = 277,
     CONNECTOR = 278,
     OUTPUT = 279,
     ID = 280,
     STRLIT = 281,
     AUDIO = 282,
     RATE = 283,
     MATHFUNC1 = 284,
     MATHFUNC2 = 285,
     STRENGTH = 286,
     SIGNAL = 287,
     FLAG = 288,
     AT = 289,
     ATFOR = 290,
     ELLIPSIS = 291,
     SCORE = 292,
     FROM = 293,
     TO = 294,
     BEFORE = 295,
     AFTER = 296,
     EVERY = 297,
     CONTROLRATE = 298,
     IF = 299,
     ELSE = 300,
     PRINT = 301,
     NEWLINEKWD = 302,
     OUTPUTCH = 303,
     FRACTION = 304,
     POSITIONKWD = 305,
     LINEAR = 306,
     EXPON = 307,
     PLACEAT = 308,
     PLACEABOVE = 309,
     PLACEBELOW = 310,
     JOIN = 311,
     LABEL = 312,
     START = 313,
     END = 314,
     STEREO = 315,
     MONO = 316,
     QUAD = 317,
     PLACELEFTOF = 318,
     PLACERIGHTOF = 319,
     REMOVE = 320,
     ACTIVATE = 321,
     DEACTIVATE = 322,
     SETMASS = 323,
     SETPOSITION = 324,
     SETVELOCITY = 325,
     SETGRAVITY = 326,
     SETHEIGHT = 327,
     SETHARDNESS = 328,
     SETMAXIMPACTS = 329,
     RESET = 330,
     DROP = 331,
     SETFORCE = 332,
     GETINSTRUMENT = 333,
     APPLYFORCE = 334,
     CLEAR = 335,
     TRUE = 336,
     FALSE = 337,
     INIT = 338,
     FOR = 339,
     INCDEC = 340,
     GETMAGNIFICATION = 341,
     GETVELOCITY = 342,
     GETPOSITION = 343,
     GETMASS = 344,
     GETNAME = 345,
     GETGRAVITY = 346,
     GETHEIGHT = 347,
     GETDAMPING = 348,
     GETHARDNESS = 349,
     GETMAXIMPACTS = 350,
     NUMBEROFIMPACTS = 351,
     GETFORCE = 352,
     ASPITCH = 353,
     ASOCTAVE = 354,
     ASFREQUENCY = 355,
     ASNAME = 356,
     SETMAGNIFICATION = 357,
     SETDAMPING = 358,
     RESETDAMPING = 359,
     SETDECAY = 360,
     RESETDECAY = 361,
     LOCKLEFT = 362,
     LOCKRIGHT = 363,
     LOCKTOP = 364,
     LOCKBOTTOM = 365,
     LOCKPERIMETER = 366,
     LOCKCORNERS = 367,
     LOCKENDS = 368,
     LOCK = 369,
     IN = 370,
     ELSEIF = 371,
     TIME = 372,
     TICK = 373,
     GETINITVELOCITY = 374,
     SETINITVELOCITY = 375,
     GETAMOUNT = 376,
     SETAMOUNT = 377,
     GETXFREQUENCY = 378,
     GETYFREQUENCY = 379,
     ASSIGNOP = 380,
     OR = 381,
     AND = 382,
     EQUALITY = 383,
     RELOP = 384,
     SHIFTOP = 385,
     PITCHUNITS = 386,
     TIMEUNITS = 387,
     UPERCENT = 388,
     UMINUS = 389,
     NOT = 390
   };
#endif
/* Tokens.  */
#define INTLIT 258
#define FLOATLIT 259
#define PITCH 260
#define ACCESSPOINT 261
#define PARAM 262
#define INTEGER 263
#define COUNTER 264
#define LEFT 265
#define RIGHT 266
#define TOP 267
#define STRING 268
#define RECTANGLE 269
#define CIRCLE 270
#define ELLIPSE 271
#define TRIANGLE 272
#define BOW 273
#define HAMMER 274
#define STOP 275
#define BOTTOM 276
#define CENTRE 277
#define CONNECTOR 278
#define OUTPUT 279
#define ID 280
#define STRLIT 281
#define AUDIO 282
#define RATE 283
#define MATHFUNC1 284
#define MATHFUNC2 285
#define STRENGTH 286
#define SIGNAL 287
#define FLAG 288
#define AT 289
#define ATFOR 290
#define ELLIPSIS 291
#define SCORE 292
#define FROM 293
#define TO 294
#define BEFORE 295
#define AFTER 296
#define EVERY 297
#define CONTROLRATE 298
#define IF 299
#define ELSE 300
#define PRINT 301
#define NEWLINEKWD 302
#define OUTPUTCH 303
#define FRACTION 304
#define POSITIONKWD 305
#define LINEAR 306
#define EXPON 307
#define PLACEAT 308
#define PLACEABOVE 309
#define PLACEBELOW 310
#define JOIN 311
#define LABEL 312
#define START 313
#define END 314
#define STEREO 315
#define MONO 316
#define QUAD 317
#define PLACELEFTOF 318
#define PLACERIGHTOF 319
#define REMOVE 320
#define ACTIVATE 321
#define DEACTIVATE 322
#define SETMASS 323
#define SETPOSITION 324
#define SETVELOCITY 325
#define SETGRAVITY 326
#define SETHEIGHT 327
#define SETHARDNESS 328
#define SETMAXIMPACTS 329
#define RESET 330
#define DROP 331
#define SETFORCE 332
#define GETINSTRUMENT 333
#define APPLYFORCE 334
#define CLEAR 335
#define TRUE 336
#define FALSE 337
#define INIT 338
#define FOR 339
#define INCDEC 340
#define GETMAGNIFICATION 341
#define GETVELOCITY 342
#define GETPOSITION 343
#define GETMASS 344
#define GETNAME 345
#define GETGRAVITY 346
#define GETHEIGHT 347
#define GETDAMPING 348
#define GETHARDNESS 349
#define GETMAXIMPACTS 350
#define NUMBEROFIMPACTS 351
#define GETFORCE 352
#define ASPITCH 353
#define ASOCTAVE 354
#define ASFREQUENCY 355
#define ASNAME 356
#define SETMAGNIFICATION 357
#define SETDAMPING 358
#define RESETDAMPING 359
#define SETDECAY 360
#define RESETDECAY 361
#define LOCKLEFT 362
#define LOCKRIGHT 363
#define LOCKTOP 364
#define LOCKBOTTOM 365
#define LOCKPERIMETER 366
#define LOCKCORNERS 367
#define LOCKENDS 368
#define LOCK 369
#define IN 370
#define ELSEIF 371
#define TIME 372
#define TICK 373
#define GETINITVELOCITY 374
#define SETINITVELOCITY 375
#define GETAMOUNT 376
#define SETAMOUNT 377
#define GETXFREQUENCY 378
#define GETYFREQUENCY 379
#define ASSIGNOP 380
#define OR 381
#define AND 382
#define EQUALITY 383
#define RELOP 384
#define SHIFTOP 385
#define PITCHUNITS 386
#define TIMEUNITS 387
#define UPERCENT 388
#define UMINUS 389
#define NOT 390




/* Copy the first part of user declarations.  */
#line 1 "taoparser.yy"

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




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 607 "taoparser.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1616

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  156
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  297
/* YYNRULES -- Number of states.  */
#define YYNSTATES  699

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   390

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   142,   131,     2,
     150,   151,   140,   138,   149,   139,   146,   141,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   147,   148,
       2,   125,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   152,     2,   153,   130,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   154,   129,   155,   145,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     126,   127,   128,   132,   133,   134,   135,   136,   137,   143,
     144
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    10,    16,    17,    19,    21,    24,
      27,    30,    33,    36,    39,    42,    45,    48,    51,    54,
      56,    60,    62,    66,    69,    72,    75,    78,    79,    81,
      83,    85,    92,   101,   103,   107,   113,   115,   117,   126,
     135,   137,   141,   149,   152,   155,   158,   161,   164,   166,
     170,   172,   177,   179,   183,   189,   190,   194,   196,   198,
     200,   202,   205,   208,   211,   214,   217,   219,   223,   225,
     227,   229,   233,   239,   240,   243,   247,   249,   253,   256,
     258,   262,   264,   266,   268,   272,   278,   279,   282,   286,
     288,   292,   295,   297,   301,   303,   305,   307,   311,   317,
     318,   321,   325,   327,   331,   336,   338,   342,   343,   344,
     351,   352,   354,   355,   362,   364,   367,   368,   371,   373,
     378,   383,   390,   394,   398,   402,   405,   406,   410,   411,
     413,   414,   416,   420,   424,   428,   432,   436,   439,   443,
     447,   451,   455,   459,   463,   466,   470,   474,   477,   481,
     483,   486,   489,   491,   493,   498,   505,   512,   519,   521,
     523,   525,   527,   529,   531,   533,   535,   538,   540,   543,
     547,   549,   551,   553,   555,   557,   559,   563,   567,   571,
     575,   579,   583,   587,   591,   595,   599,   603,   607,   611,
     615,   619,   623,   627,   631,   635,   639,   643,   646,   649,
     651,   653,   655,   658,   661,   664,   667,   670,   677,   684,
     691,   698,   705,   712,   713,   716,   720,   726,   731,   735,
     739,   741,   745,   747,   749,   751,   753,   755,   760,   764,
     768,   772,   776,   780,   784,   788,   792,   796,   800,   804,
     808,   813,   818,   823,   828,   833,   838,   843,   848,   853,
     857,   861,   866,   870,   875,   879,   886,   893,   898,   905,
     910,   917,   922,   929,   934,   939,   944,   949,   954,   959,
     961,   965,   969,   971,   973,   978,   985,   990,   996,   999,
    1005,  1010,  1013,  1015,  1017,  1020,  1021,  1024,  1026,  1029,
    1031,  1035,  1037,  1039,  1041,  1043,  1047,  1067
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     157,     0,    -1,    -1,   158,   159,   160,   212,   216,    -1,
      27,    28,   147,     3,   148,    -1,    -1,   161,    -1,   162,
      -1,   162,   161,    -1,   163,   148,    -1,   179,   148,    -1,
     186,   148,    -1,   194,   148,    -1,   202,   148,    -1,    13,
     164,    -1,    15,   164,    -1,    14,   165,    -1,    16,   165,
      -1,    17,   165,    -1,   169,    -1,   169,   149,   164,    -1,
     174,    -1,   174,   149,   165,    -1,     4,   135,    -1,     3,
     135,    -1,     4,   136,    -1,     3,   136,    -1,    -1,     3,
      -1,   170,    -1,   171,    -1,    25,   150,   166,   149,   167,
     151,    -1,    25,   152,   168,   153,   125,   154,   172,   155,
      -1,   173,    -1,   173,   149,   172,    -1,   150,   166,   149,
     167,   151,    -1,   175,    -1,   176,    -1,    25,   150,   166,
     149,   166,   149,   167,   151,    -1,    25,   152,   168,   153,
     125,   154,   177,   155,    -1,   178,    -1,   178,   149,   177,
      -1,   150,   166,   149,   166,   149,   167,   151,    -1,    18,
     180,    -1,    19,   180,    -1,    23,   180,    -1,    24,   182,
      -1,    20,   180,    -1,   181,    -1,   181,   149,   180,    -1,
      25,    -1,    25,   152,     3,   153,    -1,   183,    -1,   183,
     149,   182,    -1,    25,   150,   185,   151,   184,    -1,    -1,
     152,     3,   153,    -1,     3,    -1,    60,    -1,    61,    -1,
      62,    -1,     7,   187,    -1,    32,   187,    -1,     8,   187,
      -1,     9,   187,    -1,    33,   187,    -1,   188,    -1,   188,
     149,   187,    -1,   189,    -1,   190,    -1,    25,    -1,    25,
     125,   226,    -1,    25,   152,   168,   153,   191,    -1,    -1,
     125,   192,    -1,   154,   193,   155,    -1,   226,    -1,   226,
     149,   193,    -1,     5,   195,    -1,   196,    -1,   196,   149,
     195,    -1,   197,    -1,   198,    -1,    25,    -1,    25,   125,
     166,    -1,    25,   152,   168,   153,   199,    -1,    -1,   125,
     200,    -1,   154,   201,   155,    -1,   166,    -1,   166,   149,
     201,    -1,     6,   203,    -1,   204,    -1,   204,   149,   203,
      -1,   205,    -1,   206,    -1,    25,    -1,    25,   125,   210,
      -1,    25,   152,   168,   153,   207,    -1,    -1,   125,   208,
      -1,   154,   209,   155,    -1,   210,    -1,   210,   149,   209,
      -1,   231,   150,   211,   151,    -1,   226,    -1,   226,   149,
     226,    -1,    -1,    -1,    83,   213,   147,   214,   215,    36,
      -1,    -1,   259,    -1,    -1,    37,   167,   147,   217,   224,
      36,    -1,   219,    -1,   219,   218,    -1,    -1,   220,   235,
      -1,   221,    -1,   222,   147,   224,    36,    -1,    34,   226,
     225,   223,    -1,    38,   226,   225,    39,   226,   225,    -1,
      40,   226,   225,    -1,    41,   226,   225,    -1,    42,   226,
     225,    -1,    43,     3,    -1,    -1,    35,   226,   225,    -1,
      -1,   218,    -1,    -1,   136,    -1,   226,   138,   226,    -1,
     226,   139,   226,    -1,   226,   140,   226,    -1,   226,   141,
     226,    -1,   226,   142,   226,    -1,   139,   226,    -1,   226,
     133,   226,    -1,   226,   134,   226,    -1,   226,   132,   226,
      -1,   226,   131,   226,    -1,   226,   129,   226,    -1,   226,
     130,   226,    -1,   145,   226,    -1,   226,   128,   226,    -1,
     226,   127,   226,    -1,   144,   226,    -1,   150,   226,   151,
      -1,   227,    -1,    85,    25,    -1,    25,    85,    -1,    25,
      -1,   232,    -1,    29,   150,   226,   151,    -1,    30,   150,
     226,   149,   226,   151,    -1,    51,   150,   226,   149,   226,
     151,    -1,    52,   150,   226,   149,   226,   151,    -1,     4,
      -1,     3,    -1,   230,    -1,   210,    -1,    81,    -1,    82,
      -1,    49,    -1,    50,    -1,    25,   228,    -1,   229,    -1,
     229,   228,    -1,   152,   226,   153,    -1,    58,    -1,    59,
      -1,   117,    -1,   118,    -1,    25,    -1,   227,    -1,   231,
     146,   233,    -1,    86,   150,   151,    -1,   123,   150,   151,
      -1,   124,   150,   151,    -1,    87,   150,   151,    -1,   119,
     150,   151,    -1,    88,   150,   151,    -1,    89,   150,   151,
      -1,    91,   150,   151,    -1,    92,   150,   151,    -1,    93,
     150,   151,    -1,    94,   150,   151,    -1,    95,   150,   151,
      -1,   121,   150,   151,    -1,    96,   150,   151,    -1,    97,
     150,   151,    -1,    98,   150,   151,    -1,    99,   150,   151,
      -1,   100,   150,   151,    -1,   101,   150,   151,    -1,    90,
     150,   151,    -1,   250,   148,    -1,   262,   148,    -1,   252,
      -1,   254,    -1,   266,    -1,   241,   148,    -1,   236,   148,
      -1,   239,   148,    -1,   240,   148,    -1,   238,   148,    -1,
     210,    85,   231,    85,   210,   237,    -1,   210,    85,   231,
      85,     4,   237,    -1,     4,    85,   231,    85,   210,   237,
      -1,   231,    85,   231,    85,   210,   237,    -1,   210,    85,
     231,    85,   231,   237,    -1,   231,    85,   231,    85,   231,
     237,    -1,    -1,    31,   226,    -1,   210,    85,   231,    -1,
     231,   146,    48,   147,   226,    -1,    56,   210,    39,   210,
      -1,   231,   146,   242,    -1,   210,   146,   242,    -1,   243,
      -1,   243,   146,   242,    -1,   244,    -1,   245,    -1,   246,
      -1,   247,    -1,   248,    -1,   102,   150,   226,   151,    -1,
     107,   150,   151,    -1,   108,   150,   151,    -1,   109,   150,
     151,    -1,   110,   150,   151,    -1,   111,   150,   151,    -1,
     112,   150,   151,    -1,   113,   150,   151,    -1,   104,   150,
     151,    -1,   106,   150,   151,    -1,    65,   150,   151,    -1,
      66,   150,   151,    -1,    67,   150,   151,    -1,    68,   150,
     226,   151,    -1,    69,   150,   226,   151,    -1,    70,   150,
     226,   151,    -1,   120,   150,   226,   151,    -1,    71,   150,
     226,   151,    -1,    72,   150,   226,   151,    -1,    73,   150,
     226,   151,    -1,    74,   150,   226,   151,    -1,   122,   150,
     226,   151,    -1,    75,   150,   151,    -1,    76,   150,   151,
      -1,    77,   150,   226,   151,    -1,    78,   150,   151,    -1,
      79,   150,   226,   151,    -1,    80,   150,   151,    -1,    53,
     150,   226,   149,   226,   151,    -1,    54,   150,   231,   149,
     226,   151,    -1,    54,   150,   231,   151,    -1,    55,   150,
     231,   149,   226,   151,    -1,    55,   150,   231,   151,    -1,
      63,   150,   231,   149,   226,   151,    -1,    63,   150,   231,
     151,    -1,    64,   150,   231,   149,   226,   151,    -1,    64,
     150,   231,   151,    -1,   103,   150,   249,   151,    -1,   104,
     150,   249,   151,    -1,   105,   150,   249,   151,    -1,   106,
     150,   249,   151,    -1,   114,   150,   249,   151,    -1,   226,
      -1,   226,   149,   249,    -1,   231,   251,   226,    -1,   126,
      -1,   125,    -1,   253,   147,   259,    36,    -1,    84,   231,
     125,   226,    39,   226,    -1,   255,   147,   259,    36,    -1,
     255,   147,   259,    36,   256,    -1,    44,   226,    -1,   257,
     147,   259,    36,   256,    -1,   258,   147,   259,    36,    -1,
     116,   226,    -1,    45,    -1,   260,    -1,   260,   259,    -1,
      -1,   261,   235,    -1,   221,    -1,    46,   263,    -1,   264,
      -1,   264,   149,   263,    -1,   226,    -1,    26,    -1,    47,
      -1,   265,    -1,   231,   146,   234,    -1,    57,   150,   231,
     149,   226,   149,   226,   149,   226,   149,    26,   149,   226,
     149,   226,   149,   226,   151,   148,    -1,    57,   150,   231,
     149,   226,   149,   226,   149,   226,   149,   226,   149,    26,
     149,   226,   149,   226,   149,   226,   151,   148,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   271,   271,   271,   328,   343,   347,   352,   353,   356,
     357,   358,   359,   360,   365,   375,   385,   395,   405,   418,
     422,   428,   432,   438,   459,   482,   498,   517,   522,   540,
     544,   550,   573,   598,   610,   626,   652,   656,   662,   686,
     711,   723,   740,   767,   776,   785,   794,   803,   814,   818,
     824,   836,   887,   891,   898,   961,   966,   974,   983,   992,
    1001,  1016,  1029,  1042,  1055,  1068,  1083,  1087,  1100,  1104,
    1110,  1114,  1120,  1127,  1131,  1138,  1144,  1148,  1156,  1167,
    1171,  1177,  1181,  1187,  1191,  1197,  1204,  1208,  1214,  1220,
    1224,  1230,  1241,  1245,  1251,  1255,  1261,  1265,  1271,  1278,
    1283,  1289,  1295,  1299,  1305,  1311,  1315,  1322,  1331,  1321,
    1351,  1352,  1360,  1359,  1389,  1390,  1393,  1393,  1399,  1402,
    1414,  1503,  1578,  1625,  1672,  1718,  1739,  1744,  1775,  1776,
    1780,  1784,  1790,  1828,  1866,  1904,  1942,  1943,  1944,  1945,
    1946,  1947,  1948,  1949,  1950,  1951,  1961,  1971,  1980,  2018,
    2019,  2020,  2021,  2022,  2023,  2024,  2026,  2077,  2136,  2146,
    2155,  2159,  2163,  2173,  2183,  2192,  2204,  2210,  2214,  2220,
    2226,  2234,  2242,  2250,  2260,  2264,  2270,  2276,  2280,  2284,
    2288,  2292,  2296,  2300,  2304,  2308,  2312,  2316,  2320,  2324,
    2328,  2332,  2336,  2340,  2344,  2350,  2354,  2360,  2364,  2365,
    2366,  2367,  2368,  2372,  2376,  2380,  2384,  2390,  2409,  2429,
    2449,  2469,  2489,  2512,  2516,  2527,  2539,  2557,  2574,  2578,
    2584,  2588,  2594,  2595,  2596,  2597,  2598,  2599,  2600,  2601,
    2602,  2603,  2604,  2605,  2606,  2607,  2608,  2609,  2610,  2611,
    2612,  2613,  2614,  2615,  2616,  2617,  2618,  2619,  2620,  2621,
    2622,  2623,  2624,  2625,  2626,  2627,  2629,  2631,  2633,  2635,
    2637,  2639,  2641,  2643,  2648,  2651,  2654,  2657,  2660,  2663,
    2664,  2667,  2670,  2671,  2674,  2684,  2703,  2712,  2715,  2730,
    2731,  2742,  2758,  2773,  2774,  2778,  2778,  2784,  2791,  2804,
    2816,  2832,  2833,  2834,  2842,  2845,  2849,  2881
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTLIT", "FLOATLIT", "PITCH",
  "ACCESSPOINT", "PARAM", "INTEGER", "COUNTER", "LEFT", "RIGHT", "TOP",
  "STRING", "RECTANGLE", "CIRCLE", "ELLIPSE", "TRIANGLE", "BOW", "HAMMER",
  "STOP", "BOTTOM", "CENTRE", "CONNECTOR", "OUTPUT", "ID", "STRLIT",
  "AUDIO", "RATE", "MATHFUNC1", "MATHFUNC2", "STRENGTH", "SIGNAL", "FLAG",
  "AT", "ATFOR", "ELLIPSIS", "SCORE", "FROM", "TO", "BEFORE", "AFTER",
  "EVERY", "CONTROLRATE", "IF", "ELSE", "PRINT", "NEWLINEKWD", "OUTPUTCH",
  "FRACTION", "POSITIONKWD", "LINEAR", "EXPON", "PLACEAT", "PLACEABOVE",
  "PLACEBELOW", "JOIN", "LABEL", "START", "END", "STEREO", "MONO", "QUAD",
  "PLACELEFTOF", "PLACERIGHTOF", "REMOVE", "ACTIVATE", "DEACTIVATE",
  "SETMASS", "SETPOSITION", "SETVELOCITY", "SETGRAVITY", "SETHEIGHT",
  "SETHARDNESS", "SETMAXIMPACTS", "RESET", "DROP", "SETFORCE",
  "GETINSTRUMENT", "APPLYFORCE", "CLEAR", "TRUE", "FALSE", "INIT", "FOR",
  "INCDEC", "GETMAGNIFICATION", "GETVELOCITY", "GETPOSITION", "GETMASS",
  "GETNAME", "GETGRAVITY", "GETHEIGHT", "GETDAMPING", "GETHARDNESS",
  "GETMAXIMPACTS", "NUMBEROFIMPACTS", "GETFORCE", "ASPITCH", "ASOCTAVE",
  "ASFREQUENCY", "ASNAME", "SETMAGNIFICATION", "SETDAMPING",
  "RESETDAMPING", "SETDECAY", "RESETDECAY", "LOCKLEFT", "LOCKRIGHT",
  "LOCKTOP", "LOCKBOTTOM", "LOCKPERIMETER", "LOCKCORNERS", "LOCKENDS",
  "LOCK", "IN", "ELSEIF", "TIME", "TICK", "GETINITVELOCITY",
  "SETINITVELOCITY", "GETAMOUNT", "SETAMOUNT", "GETXFREQUENCY",
  "GETYFREQUENCY", "'='", "ASSIGNOP", "OR", "AND", "'|'", "'^'", "'&'",
  "EQUALITY", "RELOP", "SHIFTOP", "PITCHUNITS", "TIMEUNITS", "UPERCENT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "NOT", "'~'", "'.'", "':'",
  "';'", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "$accept",
  "tao_script", "@1", "audio_rate_decl", "decl_section", "declarations",
  "declaration", "instr_decl", "x_instr_decl_list", "xy_instr_decl_list",
  "pitch_literal", "duration_literal", "array_size", "x_instr_decl_item",
  "x_instr_var_decl", "x_instr_array_decl", "x_instr_array_list",
  "x_instr_initialiser", "xy_instr_decl_item", "xy_instr_var_decl",
  "xy_instr_array_decl", "xy_instr_array_list", "xy_instr_initialiser",
  "device_decl", "device_decl_list", "device_decl_item",
  "output_decl_list", "output_decl_item", "output_array_part",
  "num_channels", "var_decl", "var_decl_list", "var_decl_item",
  "var_var_decl", "var_array_decl", "var_arr_init_part", "var_array_init",
  "var_array_list", "pitch_decl", "pitch_decl_list", "pitch_decl_item",
  "pitch_var_decl", "pitch_array_decl", "pch_arr_init_part",
  "pitch_array_init", "pitch_array_list", "access_decl",
  "access_decl_list", "access_decl_item", "access_var_decl",
  "access_array_decl", "acc_arr_init_part", "access_array_init",
  "access_array_list", "access_point", "instr_coords", "init_block", "@2",
  "@3", "init_body", "score_block", "@4", "score_statements",
  "score_statement", "@5", "control_structure", "head", "at_for_part",
  "body", "timeunits", "expr", "array_expr", "array_indeces",
  "array_index", "system_variable", "variable", "num_method_expr",
  "num_method", "str_method", "statement", "connection", "strength_part",
  "apply_device", "output_statement", "join_statement", "void_method_call",
  "void_methods", "void_method", "setdamping", "resetdamping", "setdecay",
  "resetdecay", "lock", "arglist", "assignment", "assignop",
  "for_statement", "for_head", "if_statement", "if_head", "else_part",
  "elseif_head", "else_head", "statements", "context_dep_statement", "@6",
  "print", "items", "item", "str_method_expr", "label_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,    61,   380,   381,   382,   124,
      94,    38,   383,   384,   385,   386,   387,   388,    43,    45,
      42,    47,    37,   389,   390,   126,    46,    58,    59,    44,
      40,    41,    91,    93,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   156,   158,   157,   159,   160,   160,   161,   161,   162,
     162,   162,   162,   162,   163,   163,   163,   163,   163,   164,
     164,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   171,   172,   172,   173,   174,   174,   175,   176,
     177,   177,   178,   179,   179,   179,   179,   179,   180,   180,
     181,   181,   182,   182,   183,   184,   184,   185,   185,   185,
     185,   186,   186,   186,   186,   186,   187,   187,   188,   188,
     189,   189,   190,   191,   191,   192,   193,   193,   194,   195,
     195,   196,   196,   197,   197,   198,   199,   199,   200,   201,
     201,   202,   203,   203,   204,   204,   205,   205,   206,   207,
     207,   208,   209,   209,   210,   211,   211,   213,   214,   212,
     215,   215,   217,   216,   218,   218,   220,   219,   219,   221,
     222,   222,   222,   222,   222,   222,   223,   223,   224,   224,
     225,   225,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   227,   228,   228,   229,
     230,   230,   230,   230,   231,   231,   232,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   234,   234,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   236,   236,   236,
     236,   236,   236,   237,   237,   238,   239,   240,   241,   241,
     242,   242,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   244,   245,   246,   247,   248,   249,
     249,   250,   251,   251,   252,   253,   254,   254,   255,   256,
     256,   257,   258,   259,   259,   261,   260,   260,   262,   263,
     263,   264,   264,   264,   264,   265,   266,   266
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     5,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     3,     2,     2,     2,     2,     0,     1,     1,
       1,     6,     8,     1,     3,     5,     1,     1,     8,     8,
       1,     3,     7,     2,     2,     2,     2,     2,     1,     3,
       1,     4,     1,     3,     5,     0,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     5,     0,     2,     3,     1,     3,     2,     1,
       3,     1,     1,     1,     3,     5,     0,     2,     3,     1,
       3,     2,     1,     3,     1,     1,     1,     3,     5,     0,
       2,     3,     1,     3,     4,     1,     3,     0,     0,     6,
       0,     1,     0,     6,     1,     2,     0,     2,     1,     4,
       4,     6,     3,     3,     3,     2,     0,     3,     0,     1,
       0,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     3,     1,
       2,     2,     1,     1,     4,     6,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     2,     2,     2,     2,     2,     6,     6,     6,
       6,     6,     6,     0,     2,     3,     5,     4,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       3,     4,     3,     4,     3,     6,     6,     4,     6,     4,
       6,     4,     6,     4,     4,     4,     4,     4,     4,     1,
       3,     3,     1,     1,     4,     6,     4,     5,     2,     5,
       4,     2,     1,     1,     2,     0,     2,     1,     2,     1,
       3,     1,     1,     1,     1,     3,    19,    21
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     0,
       0,     0,     0,    83,    78,    79,    81,    82,    96,    91,
      92,    94,    95,    70,    61,    66,    68,    69,    63,    64,
       0,    14,    19,    29,    30,     0,    16,    21,    36,    37,
      15,    17,    18,    50,    43,    48,    44,    47,    45,     0,
      46,    52,    62,    65,   107,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    27,     0,     0,    27,     0,     0,
      27,     0,     0,    27,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     0,    84,    28,
       0,    80,   174,    97,   175,     0,     0,    93,   159,   158,
     152,     0,     0,   164,   165,     0,     0,   170,   171,   162,
     163,     0,   172,   173,     0,     0,     0,     0,   161,    71,
     149,   160,     0,   153,     0,    67,     0,     0,    20,     0,
       0,    22,     0,    49,    57,    58,    59,    60,     0,    53,
     108,     0,     0,     0,    24,    23,    86,     0,   166,   167,
       0,    99,   151,     0,     0,     0,     0,   150,   137,   147,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,    51,    55,   285,    26,    25,   112,     0,    85,     0,
     168,     0,   105,     0,    98,     0,     0,     0,     0,   148,
     146,   145,   142,   143,   141,   140,   138,   139,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,    72,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,   287,     0,   111,
     285,     0,   116,     0,    87,   169,   104,     0,     0,   100,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    31,     0,     0,     0,     0,   130,
     130,   130,   130,   130,   125,   109,   116,   284,     0,     0,
       0,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,     0,     0,   199,     0,   200,     0,     0,   201,   129,
     116,     0,   118,     0,    89,     0,   106,     0,   102,     0,
       0,     0,   177,   180,   182,   183,   184,   185,   186,   187,
     188,   190,   191,   192,   193,   194,   181,   189,   178,   179,
       0,    76,     0,     0,    33,     0,     0,     0,    40,    56,
     131,   126,     0,   122,   123,   124,     0,     0,   278,   292,
     293,   291,     0,   288,   289,   294,     0,     0,     0,     0,
       0,     0,   273,   272,     0,     0,   203,   206,   204,   205,
     202,   197,   285,   285,   198,   115,   117,   113,     0,    88,
     101,     0,   155,   156,   157,    75,     0,     0,    32,     0,
      38,     0,    39,     0,     0,   120,     0,   119,     0,     0,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   220,   222,   223,   224,   225,   226,     0,     0,
     218,   271,     0,     0,    90,   103,    77,     0,    34,     0,
      41,   130,   130,     0,     0,     0,   295,   290,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,   276,     0,     0,   127,   121,   213,     0,     0,
       0,     0,   213,   213,   213,     0,     0,     0,     0,     0,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
     249,   250,     0,   252,     0,   254,     0,   269,     0,   235,
       0,     0,   236,     0,   228,   229,   230,   231,   232,   233,
     234,     0,     0,     0,   221,   213,   213,   216,   282,     0,
     277,     0,     0,    35,     0,     0,   209,   196,   195,     0,
     275,   208,   207,   211,     0,     0,   257,     0,   259,     0,
     261,     0,   263,   240,   241,   242,   244,   245,   246,   247,
     251,   253,   227,     0,   264,   265,   266,   267,   268,   243,
     248,   210,   212,   281,   285,   285,     0,   214,     0,     0,
       0,     0,     0,     0,   270,     0,     0,    42,     0,   255,
     256,   258,   260,   262,     0,   280,     0,   279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,     0,     0,   297
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    24,    25,    26,    27,    51,    56,
     344,   163,   110,    52,    53,    54,   373,   374,    57,    58,
      59,   377,   378,    28,    64,    65,    70,    71,   259,   158,
      29,    44,    45,    46,    47,   253,   303,   370,    30,    34,
      35,    36,    37,   208,   274,   345,    31,    39,    40,    41,
      42,   214,   279,   347,   138,   211,    75,   102,   203,   266,
     104,   272,   339,   340,   341,   267,   268,   435,   343,   381,
     587,   140,   168,   169,   141,   142,   143,   251,   506,   326,
     327,   616,   328,   329,   330,   331,   481,   482,   483,   484,
     485,   486,   487,   588,   332,   405,   333,   334,   335,   336,
     610,   611,   612,   269,   270,   271,   337,   393,   394,   395,
     338
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -542
static const yytype_int16 yypact[] =
{
    -542,    16,    25,  -542,    -2,   477,   -98,    63,    67,    82,
      82,    82,    87,    96,    87,    96,    96,   104,   104,   104,
     104,   111,    82,    82,   -42,  -542,   477,   -65,     0,     4,
      17,    31,   188,   -97,  -542,    -4,  -542,  -542,   -96,  -542,
      49,  -542,  -542,   -86,  -542,    52,  -542,  -542,  -542,  -542,
      -8,  -542,    53,  -542,  -542,     1,  -542,    62,  -542,  -542,
    -542,  -542,  -542,    60,  -542,    79,  -542,  -542,  -542,    83,
    -542,    80,  -542,  -542,  -542,   195,  -542,  -542,  -542,  -542,
    -542,  -542,    77,    58,   231,    63,   210,   231,    67,   623,
     231,    82,    58,   231,    87,    58,   231,    96,   235,   104,
      10,   111,    90,    64,  -542,  -542,   106,   107,  -542,  -542,
      92,  -542,    88,  -542,  -542,    97,    93,  -542,  -542,  -542,
     -32,    98,   101,  -542,  -542,   102,   103,  -542,  -542,  -542,
    -542,   229,  -542,  -542,   623,   623,   623,   623,  -542,   727,
    -106,  -542,   -77,  -542,   108,  -542,   114,   115,  -542,   122,
     124,  -542,   125,  -542,  -542,  -542,  -542,  -542,   128,  -542,
    -542,   121,   149,   140,  -542,  -542,   164,   623,  -542,    88,
     623,   169,  -542,   623,   623,   623,   623,  -542,  -542,  -542,
    -542,   432,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   810,   177,    64,   178,    58,
     179,  -542,   156,   224,  -542,  -542,  -542,   161,  -542,   269,
    -542,   159,   604,   163,  -542,   784,  1161,  1184,  1207,  -542,
     243,  1474,    28,   142,    -1,    43,   377,   202,   -14,   -14,
    -542,  -542,  -542,   168,   199,   206,   211,   213,   215,   217,
     218,   219,   228,   230,   237,   238,   244,   245,   254,   255,
     262,  -542,   165,  -542,   187,   225,   264,   239,   357,  -542,
     623,   623,   623,   623,   623,   411,   379,  -542,   270,  -542,
     257,    33,   271,    58,  -542,  -542,  -542,   623,   210,  -542,
    -542,   623,   623,   623,   265,   273,   274,   275,   276,   277,
     279,   287,   298,   299,   300,   302,   303,   304,   305,   308,
     315,   318,   623,  -542,  -542,   320,    64,   321,   322,   665,
     665,   665,   665,   665,  -542,  -542,   271,  -542,   388,   623,
     573,   210,   324,   210,   -71,    -3,  -542,   329,   339,   340,
     341,   351,   356,  -542,   358,  -542,   359,   360,  -542,  -542,
     405,    33,  -542,   471,   363,   366,   727,   367,   364,   809,
     825,   841,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,
     368,  1230,    58,   370,   378,   380,    58,   384,   383,  -542,
    -542,   498,   495,  -542,  -542,  -542,   511,   210,   727,  -542,
    -542,   727,   -70,  -542,   403,  -542,   514,   210,   429,   210,
     773,   210,  -542,  -542,   711,   623,  -542,  -542,  -542,  -542,
    -542,  -542,   503,   503,  -542,  -542,  -542,  -542,    58,  -542,
    -542,   210,  -542,  -542,  -542,  -542,   623,   406,  -542,   320,
    -542,   407,  -542,   321,   623,  -542,   623,  -542,   482,   234,
     573,   210,   419,   623,   484,   425,   428,   435,   436,   437,
     438,   440,   441,   443,   444,   445,   454,   456,   457,   458,
     459,   460,   461,   462,   463,   468,   469,   478,   479,   480,
     483,   485,   489,   492,   496,   497,   501,   506,   507,   509,
     515,  -542,   475,  -542,  -542,  -542,  -542,  -542,   549,   517,
    -542,   727,   546,   609,  -542,  -542,  -542,    64,  -542,    58,
    -542,   665,   665,   210,   516,   518,  -542,  -542,  -542,   623,
      76,    34,   623,   210,   210,   210,   210,   520,   525,   526,
     623,   623,   623,   623,   623,   623,   623,   527,   528,   623,
     529,   623,   532,   623,   623,   105,   623,   499,   533,   534,
     535,   536,   537,   538,   543,   623,   623,   623,   773,   210,
     623,  -542,   -25,   544,   548,  -542,  -542,   636,   547,   550,
    1253,   623,   636,   636,   -26,  1276,    29,    46,    70,    75,
    -542,  -542,  -542,   857,   873,   889,   905,   921,   937,   953,
    -542,  -542,   969,  -542,   985,  -542,  1001,  1299,   551,  -542,
     552,   555,  -542,   556,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,   558,  1017,  1033,  -542,   636,   -26,   727,  -542,   623,
    -542,   553,   563,  -542,    64,   623,  -542,  -542,  -542,   623,
     727,  -542,  -542,  -542,   623,   623,  -542,   623,  -542,   623,
    -542,   623,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,   623,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,   727,   503,   503,   560,   727,  1322,  1049,
    1065,  1081,  1097,  1113,  -542,   663,   677,  -542,   623,  -542,
    -542,  -542,  -542,  -542,   -25,  -542,  1345,  -542,   611,   565,
    1368,   623,   689,  1391,   567,   623,   623,  1414,  1437,   623,
     623,  1129,  1460,   571,   623,  -542,  1145,   572,  -542
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -542,  -542,  -542,  -542,  -542,   695,  -542,  -542,    22,     9,
     -80,  -196,   -33,  -542,  -542,  -542,   293,  -542,  -542,  -542,
    -542,   291,  -542,  -542,    14,  -542,   624,  -542,  -542,  -542,
    -542,    20,  -542,  -542,  -542,  -542,  -542,   301,  -542,   641,
    -542,  -542,  -542,  -542,  -542,   312,  -542,   651,  -542,  -542,
    -542,  -542,  -542,   326,   -82,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,   408,  -542,  -542,  -266,  -542,  -542,   433,  -302,
     -89,   -35,   582,  -542,  -542,   -51,  -542,  -542,  -542,   413,
    -542,  -541,  -542,  -542,  -542,  -542,  -402,  -542,  -542,  -542,
    -542,  -542,  -542,  -518,  -542,  -542,  -542,  -542,  -542,  -542,
      78,  -542,  -542,  -263,  -542,  -542,  -542,   317,  -542,  -542,
    -542
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -284
static const yytype_int16 yytable[] =
{
     139,   254,   490,   108,   113,   615,   342,   317,   382,   383,
     384,   385,   146,   154,   399,   149,     3,   590,   591,   593,
     608,   621,   622,   623,    61,    62,     6,   601,    83,    86,
      48,    49,    66,    67,    68,   115,    60,   318,   562,    89,
    -175,    74,    72,    73,  -175,   178,   179,   180,   181,    32,
     342,   114,     4,   172,   116,    84,    87,   144,   112,   112,
     147,   106,   107,   150,   651,   652,    90,   161,   162,   195,
     155,   156,   157,   170,   342,   400,   439,   319,   209,   320,
     170,   212,   401,    77,   215,   216,   217,   218,    33,   321,
     322,   609,    38,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   151,    43,   118,   119,
     375,   145,    50,   153,  -174,   561,   148,   323,  -174,   256,
     167,    55,   402,   403,   170,   664,   192,   193,   194,    63,
     120,   187,   188,   189,   121,   122,    69,   190,   191,   192,
     193,   194,    92,   404,    93,    85,   604,   170,    78,   492,
     493,    95,    79,    96,   123,   124,   125,   126,   185,   186,
     187,   188,   189,   127,   128,    80,   190,   191,   192,   193,
     194,   309,   310,   311,   312,   313,   188,   189,   625,    81,
     626,   190,   191,   192,   193,   194,   129,   130,   346,   324,
     131,    82,   349,   350,   351,   627,   348,   628,    88,   555,
     556,    91,    94,   182,   183,   184,   185,   186,   187,   188,
     189,    97,    98,   371,   190,   191,   192,   193,   194,   629,
     325,   630,   132,   133,   631,   105,   632,   115,    99,   101,
     388,   391,   103,   100,   109,   112,   114,   160,   152,   396,
     167,   164,   165,   114,   134,   166,   171,   170,   173,   135,
     136,   174,   175,   176,   177,   137,   589,   204,   260,   324,
    -110,   196,   261,   197,   262,   263,   264,   265,   198,   392,
     115,   199,   398,   186,   187,   188,   189,   200,   201,   202,
     190,   191,   192,   193,   194,   205,   114,   206,   114,   207,
     325,   260,   427,  -283,   213,   261,   431,   262,   263,   264,
     265,   553,   252,   255,   257,   260,   114,  -128,   258,   261,
     276,   262,   263,   264,   265,   273,   491,   278,   284,   302,
     233,   234,   235,   236,   504,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   505,   438,   371,   304,   348,
     190,   191,   192,   193,   194,   501,   442,   502,   444,   285,
     488,   391,   114,   247,   510,   248,   286,   249,   250,   508,
     308,   287,   114,   288,   114,   289,   114,   290,   291,   292,
     115,   183,   184,   185,   186,   187,   188,   189,   293,   305,
     294,   190,   191,   192,   193,   194,   114,   295,   296,   392,
     115,   665,   666,   307,   297,   298,   182,   183,   184,   185,
     186,   187,   188,   189,   299,   300,   114,   190,   191,   192,
     193,   194,   301,   306,   314,   315,   352,   316,   656,   554,
     560,   557,   275,   565,   353,   354,   355,   356,   357,   563,
     358,   573,   574,   575,   576,   577,   578,   579,   359,   260,
     582,  -114,   584,   261,   586,   262,   263,   264,   265,   360,
     361,   362,   115,   363,   364,   365,   366,   602,   603,   367,
     564,   607,   566,   567,   568,   569,   368,   605,   114,   369,
     372,   376,   620,   387,   397,   379,   114,   406,   114,   114,
     114,   114,     7,     8,     9,    10,    11,   407,   408,   409,
      12,    13,    14,    15,    16,    17,    18,    19,   606,   410,
      20,    21,   118,   119,   411,   412,   413,   417,   414,    22,
      23,   189,   418,   421,   114,   190,   191,   192,   193,   194,
     653,   419,   420,   425,   120,   428,   657,   429,   121,   122,
     658,   430,   433,   434,   436,   659,   660,   260,   661,   432,
     662,   261,   663,   262,   263,   264,   265,   437,   123,   124,
     125,   126,   440,   441,   443,   497,   499,   127,   128,   182,
     183,   184,   185,   186,   187,   188,   189,   503,   509,   511,
     190,   191,   192,   193,   194,   512,   118,   119,   513,   676,
     129,   130,   551,   219,   131,   514,   515,   516,   517,   680,
     518,   519,   683,   520,   521,   522,   687,   688,   120,   389,
     691,   692,   121,   122,   523,   696,   524,   525,   526,   527,
     528,   529,   530,   531,   118,   119,   132,   133,   532,   533,
     390,   548,   123,   124,   125,   126,   118,   119,   534,   535,
     536,   127,   128,   537,   549,   538,   120,   679,   134,   539,
     121,   122,   540,   135,   136,   552,   541,   542,   120,   137,
     592,   543,   121,   122,   129,   130,   544,   545,   131,   546,
     123,   124,   125,   126,   550,   547,   558,   615,   559,   127,
     128,   570,   123,   124,   125,   126,   571,   572,   580,   581,
     583,   127,   128,   585,   594,   595,   596,   597,   598,   599,
     132,   133,   129,   130,   600,   613,   131,   614,   617,   674,
     654,   618,   644,   645,   129,   130,   646,   647,   131,   648,
     655,   667,   134,   675,   681,   684,   686,   135,   136,   695,
     698,    76,   498,   137,   500,   159,   111,   496,   132,   133,
     494,   182,   183,   184,   185,   186,   187,   188,   189,   117,
     132,   133,   190,   191,   192,   193,   194,   495,   415,   386,
     134,   210,   677,   277,   416,   135,   136,   507,     0,   489,
       0,   137,   134,     0,   445,   446,   447,   135,   136,     0,
       0,     0,     0,   137,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   380,     0,   190,   191,   192,   193,   194,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   445,   446,   447,     0,
       0,   479,     0,   480,     0,     0,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   182,   183,   184,   185,   186,   187,
     188,   189,     0,     0,     0,   190,   191,   192,   193,   194,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,     0,   479,     0,   480,   233,   234,   235,   236,
       0,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   182,   183,   184,   185,   186,   187,   188,   189,     0,
       0,     0,   190,   191,   192,   193,   194,     0,     0,   247,
       0,   248,     0,   249,   250,   280,   182,   183,   184,   185,
     186,   187,   188,   189,     0,     0,     0,   190,   191,   192,
     193,   194,   182,   183,   184,   185,   186,   187,   188,   189,
     422,     0,     0,   190,   191,   192,   193,   194,   182,   183,
     184,   185,   186,   187,   188,   189,   423,     0,     0,   190,
     191,   192,   193,   194,   182,   183,   184,   185,   186,   187,
     188,   189,   424,     0,     0,   190,   191,   192,   193,   194,
     182,   183,   184,   185,   186,   187,   188,   189,   633,     0,
       0,   190,   191,   192,   193,   194,   182,   183,   184,   185,
     186,   187,   188,   189,   634,     0,     0,   190,   191,   192,
     193,   194,   182,   183,   184,   185,   186,   187,   188,   189,
     635,     0,     0,   190,   191,   192,   193,   194,   182,   183,
     184,   185,   186,   187,   188,   189,   636,     0,     0,   190,
     191,   192,   193,   194,   182,   183,   184,   185,   186,   187,
     188,   189,   637,     0,     0,   190,   191,   192,   193,   194,
     182,   183,   184,   185,   186,   187,   188,   189,   638,     0,
       0,   190,   191,   192,   193,   194,   182,   183,   184,   185,
     186,   187,   188,   189,   639,     0,     0,   190,   191,   192,
     193,   194,   182,   183,   184,   185,   186,   187,   188,   189,
     640,     0,     0,   190,   191,   192,   193,   194,   182,   183,
     184,   185,   186,   187,   188,   189,   641,     0,     0,   190,
     191,   192,   193,   194,   182,   183,   184,   185,   186,   187,
     188,   189,   642,     0,     0,   190,   191,   192,   193,   194,
     182,   183,   184,   185,   186,   187,   188,   189,   649,     0,
       0,   190,   191,   192,   193,   194,   182,   183,   184,   185,
     186,   187,   188,   189,   650,     0,     0,   190,   191,   192,
     193,   194,   182,   183,   184,   185,   186,   187,   188,   189,
     669,     0,     0,   190,   191,   192,   193,   194,   182,   183,
     184,   185,   186,   187,   188,   189,   670,     0,     0,   190,
     191,   192,   193,   194,   182,   183,   184,   185,   186,   187,
     188,   189,   671,     0,     0,   190,   191,   192,   193,   194,
     182,   183,   184,   185,   186,   187,   188,   189,   672,     0,
       0,   190,   191,   192,   193,   194,   182,   183,   184,   185,
     186,   187,   188,   189,   673,     0,     0,   190,   191,   192,
     193,   194,   182,   183,   184,   185,   186,   187,   188,   189,
     693,     0,     0,   190,   191,   192,   193,   194,   182,   183,
     184,   185,   186,   187,   188,   189,   697,     0,     0,   190,
     191,   192,   193,   194,     0,     0,     0,     0,     0,     0,
     281,   182,   183,   184,   185,   186,   187,   188,   189,     0,
       0,     0,   190,   191,   192,   193,   194,     0,     0,     0,
       0,     0,     0,   282,   182,   183,   184,   185,   186,   187,
     188,   189,     0,     0,     0,   190,   191,   192,   193,   194,
       0,     0,     0,     0,     0,     0,   283,   182,   183,   184,
     185,   186,   187,   188,   189,     0,     0,     0,   190,   191,
     192,   193,   194,     0,     0,     0,     0,     0,     0,   426,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,   190,   191,   192,   193,   194,     0,     0,     0,     0,
       0,     0,   619,   182,   183,   184,   185,   186,   187,   188,
     189,     0,     0,     0,   190,   191,   192,   193,   194,     0,
       0,     0,     0,     0,     0,   624,   182,   183,   184,   185,
     186,   187,   188,   189,     0,     0,     0,   190,   191,   192,
     193,   194,     0,     0,     0,     0,     0,     0,   643,   182,
     183,   184,   185,   186,   187,   188,   189,     0,     0,     0,
     190,   191,   192,   193,   194,     0,     0,     0,     0,     0,
       0,   668,   182,   183,   184,   185,   186,   187,   188,   189,
       0,     0,     0,   190,   191,   192,   193,   194,     0,     0,
       0,     0,     0,     0,   678,   182,   183,   184,   185,   186,
     187,   188,   189,     0,     0,     0,   190,   191,   192,   193,
     194,     0,     0,     0,     0,     0,     0,   682,   182,   183,
     184,   185,   186,   187,   188,   189,     0,     0,     0,   190,
     191,   192,   193,   194,     0,     0,     0,     0,     0,     0,
     685,   182,   183,   184,   185,   186,   187,   188,   189,     0,
       0,     0,   190,   191,   192,   193,   194,     0,     0,     0,
       0,     0,     0,   689,   182,   183,   184,   185,   186,   187,
     188,   189,     0,     0,     0,   190,   191,   192,   193,   194,
       0,     0,     0,     0,     0,     0,   690,   182,   183,   184,
     185,   186,   187,   188,   189,     0,     0,     0,   190,   191,
     192,   193,   194,   184,   185,   186,   187,   188,   189,   694,
       0,     0,   190,   191,   192,   193,   194
};

static const yytype_int16 yycheck[] =
{
      89,   197,   404,    83,    86,    31,   272,   270,   310,   311,
     312,   313,    92,     3,    85,    95,     0,   535,   536,   537,
      45,   562,   563,   564,    15,    16,    28,   545,   125,   125,
      10,    11,    18,    19,    20,    86,    14,     4,     4,   125,
     146,    83,    22,    23,   150,   134,   135,   136,   137,   147,
     316,    86,    27,    85,    87,   152,   152,    90,    25,    25,
      93,     3,     4,    96,   605,   606,   152,     3,     4,   146,
      60,    61,    62,   150,   340,   146,   146,    44,   167,    46,
     150,   170,    85,   148,   173,   174,   175,   176,    25,    56,
      57,   116,    25,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    97,    25,     3,     4,
     306,    91,    25,    99,   146,    39,    94,    84,   150,   199,
     152,    25,   125,   126,   150,   643,   140,   141,   142,    25,
      25,   132,   133,   134,    29,    30,    25,   138,   139,   140,
     141,   142,   150,   146,   152,   149,   548,   150,   148,   412,
     413,   150,   148,   152,    49,    50,    51,    52,   130,   131,
     132,   133,   134,    58,    59,   148,   138,   139,   140,   141,
     142,   260,   261,   262,   263,   264,   133,   134,   149,   148,
     151,   138,   139,   140,   141,   142,    81,    82,   277,   271,
      85,     3,   281,   282,   283,   149,   278,   151,   149,   501,
     502,   149,   149,   127,   128,   129,   130,   131,   132,   133,
     134,   149,   152,   302,   138,   139,   140,   141,   142,   149,
     271,   151,   117,   118,   149,   148,   151,   278,   149,   149,
     319,   320,    37,   150,     3,    25,   271,   147,     3,   321,
     152,   135,   135,   278,   139,   153,   153,   150,   150,   144,
     145,   150,   150,   150,    25,   150,   151,   136,    34,   341,
      36,   153,    38,   149,    40,    41,    42,    43,   153,   320,
     321,   149,   323,   131,   132,   133,   134,   153,   153,   151,
     138,   139,   140,   141,   142,   136,   321,   147,   323,   125,
     341,    34,   372,    36,   125,    38,   376,    40,    41,    42,
      43,   497,   125,   125,   125,    34,   341,    36,   152,    38,
     151,    40,    41,    42,    43,   154,   405,   154,   150,   154,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   387,   426,   151,   421,
     138,   139,   140,   141,   142,   434,   397,   436,   399,   150,
     401,   440,   387,   119,   443,   121,   150,   123,   124,   441,
       3,   150,   397,   150,   399,   150,   401,   150,   150,   150,
     421,   128,   129,   130,   131,   132,   133,   134,   150,   154,
     150,   138,   139,   140,   141,   142,   421,   150,   150,   440,
     441,   654,   655,   154,   150,   150,   127,   128,   129,   130,
     131,   132,   133,   134,   150,   150,   441,   138,   139,   140,
     141,   142,   150,   149,     3,    36,   151,   147,   614,   499,
     509,   503,   153,   512,   151,   151,   151,   151,   151,   511,
     151,   520,   521,   522,   523,   524,   525,   526,   151,    34,
     529,    36,   531,    38,   533,    40,    41,    42,    43,   151,
     151,   151,   503,   151,   151,   151,   151,   546,   547,   151,
     511,   550,   513,   514,   515,   516,   151,   549,   503,   151,
     150,   150,   561,    85,   150,   153,   511,   148,   513,   514,
     515,   516,     5,     6,     7,     8,     9,   148,   148,   148,
      13,    14,    15,    16,    17,    18,    19,    20,   549,   148,
      23,    24,     3,     4,   148,   147,   147,    36,   148,    32,
      33,   134,   149,   149,   549,   138,   139,   140,   141,   142,
     609,   155,   155,   155,    25,   155,   615,   149,    29,    30,
     619,   151,   149,    35,    39,   624,   625,    34,   627,   155,
     629,    38,   631,    40,    41,    42,    43,    36,    49,    50,
      51,    52,   149,    39,   125,   149,   149,    58,    59,   127,
     128,   129,   130,   131,   132,   133,   134,    85,   149,    85,
     138,   139,   140,   141,   142,   150,     3,     4,   150,   668,
      81,    82,    36,   151,    85,   150,   150,   150,   150,   678,
     150,   150,   681,   150,   150,   150,   685,   686,    25,    26,
     689,   690,    29,    30,   150,   694,   150,   150,   150,   150,
     150,   150,   150,   150,     3,     4,   117,   118,   150,   150,
      47,   146,    49,    50,    51,    52,     3,     4,   150,   150,
     150,    58,    59,   150,    85,   150,    25,    26,   139,   150,
      29,    30,   150,   144,   145,    36,   150,   150,    25,   150,
     151,   150,    29,    30,    81,    82,   150,   150,    85,   150,
      49,    50,    51,    52,   147,   150,   150,    31,   150,    58,
      59,   151,    49,    50,    51,    52,   151,   151,   151,   151,
     151,    58,    59,   151,   151,   151,   151,   151,   151,   151,
     117,   118,    81,    82,   151,   151,    85,   149,   151,    36,
     147,   151,   151,   151,    81,    82,   151,   151,    85,   151,
     147,   151,   139,    36,   149,    26,   149,   144,   145,   148,
     148,    26,   429,   150,   433,   101,    85,   426,   117,   118,
     418,   127,   128,   129,   130,   131,   132,   133,   134,    88,
     117,   118,   138,   139,   140,   141,   142,   421,   340,   316,
     139,   169,   674,   149,   341,   144,   145,   440,    -1,    48,
      -1,   150,   139,    -1,    53,    54,    55,   144,   145,    -1,
      -1,    -1,    -1,   150,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,   136,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    53,    54,    55,    -1,
      -1,   120,    -1,   122,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,   120,    -1,   122,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,   119,
      -1,   121,    -1,   123,   124,   151,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   127,   128,   129,   130,   131,   132,   133,   134,
     151,    -1,    -1,   138,   139,   140,   141,   142,   127,   128,
     129,   130,   131,   132,   133,   134,   151,    -1,    -1,   138,
     139,   140,   141,   142,   127,   128,   129,   130,   131,   132,
     133,   134,   151,    -1,    -1,   138,   139,   140,   141,   142,
     127,   128,   129,   130,   131,   132,   133,   134,   151,    -1,
      -1,   138,   139,   140,   141,   142,   127,   128,   129,   130,
     131,   132,   133,   134,   151,    -1,    -1,   138,   139,   140,
     141,   142,   127,   128,   129,   130,   131,   132,   133,   134,
     151,    -1,    -1,   138,   139,   140,   141,   142,   127,   128,
     129,   130,   131,   132,   133,   134,   151,    -1,    -1,   138,
     139,   140,   141,   142,   127,   128,   129,   130,   131,   132,
     133,   134,   151,    -1,    -1,   138,   139,   140,   141,   142,
     127,   128,   129,   130,   131,   132,   133,   134,   151,    -1,
      -1,   138,   139,   140,   141,   142,   127,   128,   129,   130,
     131,   132,   133,   134,   151,    -1,    -1,   138,   139,   140,
     141,   142,   127,   128,   129,   130,   131,   132,   133,   134,
     151,    -1,    -1,   138,   139,   140,   141,   142,   127,   128,
     129,   130,   131,   132,   133,   134,   151,    -1,    -1,   138,
     139,   140,   141,   142,   127,   128,   129,   130,   131,   132,
     133,   134,   151,    -1,    -1,   138,   139,   140,   141,   142,
     127,   128,   129,   130,   131,   132,   133,   134,   151,    -1,
      -1,   138,   139,   140,   141,   142,   127,   128,   129,   130,
     131,   132,   133,   134,   151,    -1,    -1,   138,   139,   140,
     141,   142,   127,   128,   129,   130,   131,   132,   133,   134,
     151,    -1,    -1,   138,   139,   140,   141,   142,   127,   128,
     129,   130,   131,   132,   133,   134,   151,    -1,    -1,   138,
     139,   140,   141,   142,   127,   128,   129,   130,   131,   132,
     133,   134,   151,    -1,    -1,   138,   139,   140,   141,   142,
     127,   128,   129,   130,   131,   132,   133,   134,   151,    -1,
      -1,   138,   139,   140,   141,   142,   127,   128,   129,   130,
     131,   132,   133,   134,   151,    -1,    -1,   138,   139,   140,
     141,   142,   127,   128,   129,   130,   131,   132,   133,   134,
     151,    -1,    -1,   138,   139,   140,   141,   142,   127,   128,
     129,   130,   131,   132,   133,   134,   151,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   127,   128,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   127,
     128,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   127,   128,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   127,   128,   129,   130,   131,
     132,   133,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   127,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   129,   130,   131,   132,   133,   134,   149,
      -1,    -1,   138,   139,   140,   141,   142
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   157,   158,     0,    27,   159,    28,     5,     6,     7,
       8,     9,    13,    14,    15,    16,    17,    18,    19,    20,
      23,    24,    32,    33,   160,   161,   162,   163,   179,   186,
     194,   202,   147,    25,   195,   196,   197,   198,    25,   203,
     204,   205,   206,    25,   187,   188,   189,   190,   187,   187,
      25,   164,   169,   170,   171,    25,   165,   174,   175,   176,
     164,   165,   165,    25,   180,   181,   180,   180,   180,    25,
     182,   183,   187,   187,    83,   212,   161,   148,   148,   148,
     148,   148,     3,   125,   152,   149,   125,   152,   149,   125,
     152,   149,   150,   152,   149,   150,   152,   149,   152,   149,
     150,   149,   213,    37,   216,   148,     3,     4,   166,     3,
     168,   195,    25,   210,   227,   231,   168,   203,     3,     4,
      25,    29,    30,    49,    50,    51,    52,    58,    59,    81,
      82,    85,   117,   118,   139,   144,   145,   150,   210,   226,
     227,   230,   231,   232,   168,   187,   166,   168,   164,   166,
     168,   165,     3,   180,     3,    60,    61,    62,   185,   182,
     147,     3,     4,   167,   135,   135,   153,   152,   228,   229,
     150,   153,    85,   150,   150,   150,   150,    25,   226,   226,
     226,   226,   127,   128,   129,   130,   131,   132,   133,   134,
     138,   139,   140,   141,   142,   146,   153,   149,   153,   149,
     153,   153,   151,   214,   136,   136,   147,   125,   199,   226,
     228,   211,   226,   125,   207,   226,   226,   226,   226,   151,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,    86,    87,    88,    89,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   119,   121,   123,
     124,   233,   125,   191,   167,   125,   166,   125,   152,   184,
      34,    38,    40,    41,    42,    43,   215,   221,   222,   259,
     260,   261,   217,   154,   200,   153,   151,   149,   154,   208,
     151,   149,   149,   149,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   154,   192,   151,   154,   149,   154,     3,   226,
     226,   226,   226,   226,     3,    36,   147,   259,     4,    44,
      46,    56,    57,    84,   210,   231,   235,   236,   238,   239,
     240,   241,   250,   252,   253,   254,   255,   262,   266,   218,
     219,   220,   221,   224,   166,   201,   226,   209,   210,   226,
     226,   226,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     193,   226,   150,   172,   173,   167,   150,   177,   178,   153,
     136,   225,   225,   225,   225,   225,   224,    85,   226,    26,
      47,   226,   231,   263,   264,   265,   210,   150,   231,    85,
     146,    85,   125,   126,   146,   251,   148,   148,   148,   148,
     148,   148,   147,   147,   148,   218,   235,    36,   149,   155,
     155,   149,   151,   151,   151,   155,   149,   166,   155,   149,
     151,   166,   155,   149,    35,   223,    39,    36,   231,   146,
     149,    39,   231,   125,   231,    53,    54,    55,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   120,
     122,   242,   243,   244,   245,   246,   247,   248,   231,    48,
     242,   226,   259,   259,   201,   209,   193,   149,   172,   149,
     177,   226,   226,    85,    90,   101,   234,   263,   210,   149,
     226,    85,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   146,    85,
     147,    36,    36,   167,   166,   225,   225,   210,   150,   150,
     226,    39,     4,   210,   231,   226,   231,   231,   231,   231,
     151,   151,   151,   226,   226,   226,   226,   226,   226,   226,
     151,   151,   226,   151,   226,   151,   226,   226,   249,   151,
     249,   249,   151,   249,   151,   151,   151,   151,   151,   151,
     151,   249,   226,   226,   242,   210,   231,   226,    45,   116,
     256,   257,   258,   151,   149,    31,   237,   151,   151,   149,
     226,   237,   237,   237,   149,   149,   151,   149,   151,   149,
     151,   149,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   149,   151,   151,   151,   151,   151,   151,
     151,   237,   237,   226,   147,   147,   167,   226,   226,   226,
     226,   226,   226,   226,   249,   259,   259,   151,   149,   151,
     151,   151,   151,   151,    36,    36,   226,   256,   149,    26,
     226,   149,   149,   226,    26,   149,   149,   226,   226,   149,
     149,   226,   226,   151,   149,   148,   226,   151,   148
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 271 "taoparser.yy"
    {

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
    break;

  case 3:
#line 312 "taoparser.yy"
    {
std::cout <<
"\n\nint main(int argc, char *argv[])\n"
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
    break;

  case 4:
#line 329 "taoparser.yy"
    {
std::cout << "\n// Audio rate: <sample_rate> ;"
	"\n\nint taoAudioRate() {return " << (yyvsp[(4) - (5)]).i << ";}\n\n"
	"\n\n// Declarations\n";
	
			delete [] (yyvsp[(1) - (5)]).s;
			delete [] (yyvsp[(2) - (5)]).s;
			delete [] (yyvsp[(3) - (5)]).s;
			delete [] (yyvsp[(4) - (5)]).s;
			audioRate=(yyvsp[(4) - (5)]).i;
			}
    break;

  case 5:
#line 343 "taoparser.yy"
    {
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 6:
#line 348 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 9:
#line 356 "taoparser.yy"
    {std::cout << "\n" << (yyvsp[(1) - (2)]).s << ";\n";}
    break;

  case 10:
#line 357 "taoparser.yy"
    {std::cout << "\n" << (yyvsp[(1) - (2)]).s << ";\n";}
    break;

  case 11:
#line 358 "taoparser.yy"
    {std::cout << "#line " << lineno << " \"" << scriptname << "\"\n" << (yyvsp[(1) - (2)]).s << ";\n";}
    break;

  case 12:
#line 359 "taoparser.yy"
    {std::cout << "\n" << (yyvsp[(1) - (2)]).s << ";\n";}
    break;

  case 13:
#line 360 "taoparser.yy"
    {std::cout << "\n" << (yyvsp[(1) - (2)]).s << ";\n";}
    break;

  case 14:
#line 366 "taoparser.yy"
    {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoString" << (yyvsp[(2) - (2)]).s << std::ends;
			//$$.s=obuffer.str().c_str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 15:
#line 376 "taoparser.yy"
    {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoCircle" << (yyvsp[(2) - (2)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 16:
#line 386 "taoparser.yy"
    {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoRectangle" << (yyvsp[(2) - (2)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 17:
#line 396 "taoparser.yy"
    {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoEllipse" << (yyvsp[(2) - (2)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 18:
#line 406 "taoparser.yy"
    {
			//ostrstream obuffer;
			std::ostringstream obuffer;
			obuffer << "TaoTriangle" << (yyvsp[(2) - (2)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 19:
#line 419 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 20:
#line 423 "taoparser.yy"
    {
			 BUILD3((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
			 }
    break;

  case 21:
#line 429 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 22:
#line 433 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 23:
#line 439 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			if (streq((yyvsp[(2) - (2)]).s, "pch"))

obuffer << "TaoPitch(" << (yyvsp[(1) - (2)]).f << "f, TaoPitch::pch)" << std::ends;

			else if (streq((yyvsp[(2) - (2)]).s, "oct"))

obuffer << "TaoPitch(" << (yyvsp[(1) - (2)]).f << "f, TaoPitch::oct)" << std::ends;

			else if (streq((yyvsp[(2) - (2)]).s, "Hz"))

obuffer << "TaoPitch(" << (yyvsp[(1) - (2)]).f << "f, TaoPitch::frq)" << std::ends;

			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;			
			}
    break;

  case 24:
#line 460 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			if (streq((yyvsp[(2) - (2)]).s, "pch"))

obuffer << "TaoPitch(" << (yyvsp[(1) - (2)]).f << "f, TaoPitch::pch)" << std::ends;

			else if (streq((yyvsp[(2) - (2)]).s, "oct"))

obuffer << "TaoPitch(" << (yyvsp[(1) - (2)]).f << "f, TaoPitch::oct)" << std::ends;

			else if (streq((yyvsp[(2) - (2)]).s, "Hz"))

obuffer << "TaoPitch(" << (yyvsp[(1) - (2)]).f << "f, TaoPitch::frq)" << std::ends;

		        //$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 25:
#line 483 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			float timeFactor=1.0;
			if (streq((yyvsp[(2) - (2)]).s, "secs"))	    timeFactor=1.0;
			else if (streq((yyvsp[(2) - (2)]).s, "sec"))	    timeFactor=1.0;
			else if (streq((yyvsp[(2) - (2)]).s, "mins"))	    timeFactor=60.0;
			else if (streq((yyvsp[(2) - (2)]).s, "min"))	    timeFactor=60.0;
			else if (streq((yyvsp[(2) - (2)]).s, "msecs"))	    timeFactor=0.001;
			obuffer << (yyvsp[(1) - (2)]).f * timeFactor << "f" << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 26:
#line 499 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer.setf(std::ios::showpoint);
			float timeFactor=1.0;
			if (streq((yyvsp[(2) - (2)]).s, "secs"))	    timeFactor=1.0;
			else if (streq((yyvsp[(2) - (2)]).s, "sec"))	    timeFactor=1.0;
			else if (streq((yyvsp[(2) - (2)]).s, "mins"))	    timeFactor=60.0;
			else if (streq((yyvsp[(2) - (2)]).s, "min"))	    timeFactor=60.0;
			else if (streq((yyvsp[(2) - (2)]).s, "msecs"))	    timeFactor=0.001;
			obuffer << (yyvsp[(1) - (2)]).f * timeFactor << "f" << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 27:
#line 517 "taoparser.yy"
    {
			instr_array_size_given=0;
			(yyval).s=new char[1];
			(yyval).s[0]='\0';
			}
    break;

  case 28:
#line 523 "taoparser.yy"
    {
			std::ostringstream obuffer;
			instr_array_size_given=1;
			instr_array_size=(yyvsp[(1) - (1)]).i;
			obuffer << (yyvsp[(1) - (1)]).i << std::ends;
			(yyval).t=STR;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (1)]).s;
			}
    break;

  case 29:
#line 541 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 30:
#line 545 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 31:
#line 551 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 INDENT();

/*********************************************************************************/
obuffer << "\n" << indent << (yyvsp[(1) - (6)]).s << "(\"" << (yyvsp[(1) - (6)]).s << "\", "
	<< (yyvsp[(3) - (6)]).s << ", " << (yyvsp[(5) - (6)]).s << ")" << std::ends;
/*********************************************************************************/

			 UNINDENT();
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 32:
#line 574 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 
/*********************************************************************************/
obuffer << "\n    " << (yyvsp[(1) - (8)]).s << "[" << (yyvsp[(3) - (8)]).s << "]=";
obuffer << "\n        {"
	<< (yyvsp[(7) - (8)]).s
	<< "\n        }" << std::ends;
/*********************************************************************************/

			 instr_array_index=0;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (8)]).s;
			 delete [] (yyvsp[(2) - (8)]).s;
			 delete [] (yyvsp[(3) - (8)]).s;
			 delete [] (yyvsp[(4) - (8)]).s;
			 delete [] (yyvsp[(5) - (8)]).s;
			 delete [] (yyvsp[(6) - (8)]).s;
			 delete [] (yyvsp[(7) - (8)]).s;
			 delete [] (yyvsp[(8) - (8)]).s;
			 }
    break;

  case 33:
#line 599 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n        " << current_instr_class << (yyvsp[(1) - (1)]).s << std::ends;
/*********************************************************************************/
			
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 34:
#line 611 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n        " << current_instr_class << (yyvsp[(1) - (3)]).s << "," << (yyvsp[(3) - (3)]).s << std::ends;
/*********************************************************************************/
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 }
    break;

  case 35:
#line 627 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "(\"" << current_id << "[" << instr_array_index << "]\"" <<
", " << (yyvsp[(2) - (5)]).s << ", " << (yyvsp[(4) - (5)]).s << ")" << std::ends;
/*********************************************************************************/

			 instr_array_index++;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (5)]).s;			 
			 delete [] (yyvsp[(2) - (5)]).s;			 
			 delete [] (yyvsp[(3) - (5)]).s;			 
			 delete [] (yyvsp[(4) - (5)]).s;			 
			 delete [] (yyvsp[(5) - (5)]).s;			 
			 }
    break;

  case 36:
#line 653 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 37:
#line 657 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 38:
#line 664 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n    " << (yyvsp[(1) - (8)]).s << "(\"" << (yyvsp[(1) - (8)]).s << "\", "
	<< (yyvsp[(3) - (8)]).s << ", " << (yyvsp[(5) - (8)]).s << ", " << (yyvsp[(7) - (8)]).s << ")" << std::ends;
/*********************************************************************************/

			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (8)]).s;
			 delete [] (yyvsp[(2) - (8)]).s;
			 delete [] (yyvsp[(3) - (8)]).s;
			 delete [] (yyvsp[(4) - (8)]).s;
			 delete [] (yyvsp[(5) - (8)]).s;
			 delete [] (yyvsp[(6) - (8)]).s;
			 delete [] (yyvsp[(7) - (8)]).s;
			 delete [] (yyvsp[(8) - (8)]).s;
			 }
    break;

  case 39:
#line 687 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n    " << (yyvsp[(1) - (8)]).s << "[" << (yyvsp[(3) - (8)]).s << "]=";
obuffer << "\n        {"
	<<            (yyvsp[(7) - (8)]).s
	<< "\n        }" << std::ends;
/*********************************************************************************/

			 instr_array_index=0;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (8)]).s;
			 delete [] (yyvsp[(2) - (8)]).s;
			 delete [] (yyvsp[(3) - (8)]).s;
			 delete [] (yyvsp[(4) - (8)]).s;
			 delete [] (yyvsp[(5) - (8)]).s;
			 delete [] (yyvsp[(6) - (8)]).s;
			 delete [] (yyvsp[(7) - (8)]).s;
			 delete [] (yyvsp[(8) - (8)]).s;
			 }
    break;

  case 40:
#line 712 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 
/*********************************************************************************/
obuffer << "\n        " << indent << current_instr_class << (yyvsp[(1) - (1)]).s << std::ends;
/*********************************************************************************/
			
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 41:
#line 724 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "\n        " << indent << current_instr_class << (yyvsp[(1) - (3)]).s
	<< "," << (yyvsp[(3) - (3)]).s << std::ends;
/*********************************************************************************/
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 }
    break;

  case 42:
#line 741 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << "(\"" << current_id << "[" << instr_array_index << "]\"" <<
", " << (yyvsp[(2) - (7)]).s << ", " << (yyvsp[(4) - (7)]).s << ", " << (yyvsp[(6) - (7)]).s << ")" << std::ends;
/*********************************************************************************/

			 instr_array_index++;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (7)]).s;			 
			 delete [] (yyvsp[(2) - (7)]).s;			 
			 delete [] (yyvsp[(3) - (7)]).s;			 
			 delete [] (yyvsp[(4) - (7)]).s;			 
			 delete [] (yyvsp[(5) - (7)]).s;			 
			 delete [] (yyvsp[(6) - (7)]).s;			 
			 delete [] (yyvsp[(7) - (7)]).s;			 
			 }
    break;

  case 43:
#line 768 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoBow " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 44:
#line 777 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoHammer " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 45:
#line 786 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoConnector " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 46:
#line 795 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoOutput " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 47:
#line 804 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "\nTaoStop " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 48:
#line 815 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 49:
#line 819 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 50:
#line 825 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*********************************************************************************/
obuffer << (yyvsp[(1) - (1)]).s << "(\"" << (yyvsp[(1) - (1)]).s << "\")" << std::ends;
/*********************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 51:
#line 837 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 int counter;

			 INDENT();
			    
/*********************************************************************************/
obuffer << "\n" << indent << (yyvsp[(1) - (4)]).s << "[" << (yyvsp[(3) - (4)]).s << "]=";
/*********************************************************************************/

			 INDENT();

/*********************************************************************************/
obuffer << "\n" << indent << "{";
/*********************************************************************************/
			    
			 for (counter=0;counter<(yyvsp[(3) - (4)]).i-1;counter++)
			     {
				
/*********************************************************************************/
obuffer << "\n" << indent << current_device_class <<
"(\"" << (yyvsp[(1) - (4)]).s << counter << "\"),";
/*********************************************************************************/

			     }

/*********************************************************************************/
obuffer << "\n" << indent << current_device_class << 
"(\"" << (yyvsp[(1) - (4)]).s << counter << "\")";
obuffer << "\n" << indent << "}" << std::ends;
/*********************************************************************************/

			 UNINDENT();
			 UNINDENT();
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (4)]).s;
			 delete [] (yyvsp[(2) - (4)]).s;
			 delete [] (yyvsp[(3) - (4)]).s;
			 delete [] (yyvsp[(4) - (4)]).s;
			 }
    break;

  case 52:
#line 888 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 53:
#line 892 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 54:
#line 899 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 int counter;
			 if (is_array_of_outputs)
			    {
			    INDENT();
			    
/*********************************************************************************/
obuffer << "\n" << indent << (yyvsp[(1) - (5)]).s << (yyvsp[(5) - (5)]).s << "=";
/*********************************************************************************/

			    INDENT();

/*********************************************************************************/
obuffer << "\n" << indent << "{";
/*********************************************************************************/
			    
			    for (counter=0;counter<output_array_size-1;counter++)
				{
				
/*********************************************************************************/
obuffer << "\n" << indent <<
    "TaoOutput(\"" << (yyvsp[(1) - (5)]).s << "_" << counter << "\", " << 
    "\"" << scriptname_minus_suffix << "_" << (yyvsp[(1) - (5)]).s << "_" << counter << "\", " <<
    (yyvsp[(3) - (5)]).s << "),";
/*********************************************************************************/

				}

/*********************************************************************************/
obuffer << "\n" << indent <<
    "TaoOutput(\"" << (yyvsp[(1) - (5)]).s << "_" << counter << "\", " << 
    "\"" << scriptname_minus_suffix << "_" << (yyvsp[(1) - (5)]).s << "_" << counter << "\", " <<
    (yyvsp[(3) - (5)]).s << ")";
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
    (yyvsp[(1) - (5)]).s << "(\"" << (yyvsp[(1) - (5)]).s << "\", \"" << scriptname_minus_suffix << "_" << (yyvsp[(1) - (5)]).s <<
    "\", " << (yyvsp[(3) - (5)]).s << ")" << std::ends;
/*********************************************************************************/

			    UNINDENT();
			    }
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (5)]).s;
			 delete [] (yyvsp[(2) - (5)]).s;
			 delete [] (yyvsp[(3) - (5)]).s;
			 delete [] (yyvsp[(4) - (5)]).s;
			 delete [] (yyvsp[(5) - (5)]).s;
			 }
    break;

  case 55:
#line 961 "taoparser.yy"
    {
			 is_array_of_outputs=0;
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 56:
#line 967 "taoparser.yy"
    {
			 is_array_of_outputs=1;
			 output_array_size=(yyvsp[(2) - (3)]).i;
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 57:
#line 975 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << (yyvsp[(1) - (1)]).i << std::ends;
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 58:
#line 984 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << 2 << std::ends;
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 59:
#line 993 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << 1 << std::ends;
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 60:
#line 1002 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << 4 << std::ends;
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 61:
#line 1017 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "float " << (yyvsp[(2) - (2)]).s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 62:
#line 1030 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "float " << (yyvsp[(2) - (2)]).s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 63:
#line 1043 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "int " << (yyvsp[(2) - (2)]).s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 64:
#line 1056 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "int " << (yyvsp[(2) - (2)]).s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 65:
#line 1069 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "int " << (yyvsp[(2) - (2)]).s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 66:
#line 1084 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 67:
#line 1088 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << (yyvsp[(1) - (3)]).s << " " << (yyvsp[(2) - (3)]).s << " " << (yyvsp[(3) - (3)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 }
    break;

  case 68:
#line 1101 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 69:
#line 1105 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 70:
#line 1111 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 71:
#line 1115 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 72:
#line 1121 "taoparser.yy"
    {
			 BUILD5((yyval),(yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));
			 }
    break;

  case 73:
#line 1127 "taoparser.yy"
    {
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 74:
#line 1132 "taoparser.yy"
    {
			 BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));
			 }
    break;

  case 75:
#line 1139 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 76:
#line 1145 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 77:
#line 1149 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 78:
#line 1157 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "TaoPitch " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 79:
#line 1168 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 80:
#line 1172 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 81:
#line 1178 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 82:
#line 1182 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 83:
#line 1188 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 84:
#line 1192 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 85:
#line 1198 "taoparser.yy"
    {
			 BUILD5((yyval),(yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));
			 }
    break;

  case 86:
#line 1204 "taoparser.yy"
    {
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 87:
#line 1209 "taoparser.yy"
    {
			 BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));
			 }
    break;

  case 88:
#line 1215 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 89:
#line 1221 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 90:
#line 1225 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 91:
#line 1231 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "TaoAccessPoint " << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 92:
#line 1242 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 93:
#line 1246 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 94:
#line 1252 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 95:
#line 1256 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 96:
#line 1262 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 97:
#line 1266 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 98:
#line 1272 "taoparser.yy"
    {
			 BUILD5((yyval),(yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)]));
			 }
    break;

  case 99:
#line 1278 "taoparser.yy"
    {
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 (yyval).t=STR;
			 }
    break;

  case 100:
#line 1284 "taoparser.yy"
    {
			 BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));
			 }
    break;

  case 101:
#line 1290 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 102:
#line 1296 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 103:
#line 1300 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 104:
#line 1306 "taoparser.yy"
    {
			 BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));
			 }
    break;

  case 105:
#line 1312 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 106:
#line 1316 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 107:
#line 1322 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n// Init: <statements> ..."
	"\n\nvoid taoInit()";
/*******************************************************************************/

			 }
    break;

  case 108:
#line 1331 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n    {";
/*******************************************************************************/

			 INDENT();
			 }
    break;

  case 109:
#line 1342 "taoparser.yy"
    {
			 UNINDENT();
			 
/*******************************************************************************/
std::cout << "\n    }\n";
/*******************************************************************************/
			 }
    break;

  case 112:
#line 1360 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n// Score <duration> : <statements> ..."
	"\n\nfloat taoScoreDuration() {return " << (yyvsp[(2) - (3)]).f << "f;}"
	"\n\nvoid taoScore()\n"
	"    {\n"
	"    tao.initStartAndEnd();\n";
/*******************************************************************************/

			 INDENT();
			 in_score_block=1;
			 }
    break;

  case 113:
#line 1374 "taoparser.yy"
    {
			 UNINDENT();
			 
/*******************************************************************************/
std::cout << "\n\n" << indent << "    tao.popStartAndEnd();";
std::cout << "\n" << indent << "    }";
/*******************************************************************************/

			 delete [] (yyvsp[(1) - (6)]).s;			 
			 delete [] (yyvsp[(2) - (6)]).s;			 
			 delete [] (yyvsp[(3) - (6)]).s;			 
			 delete [] (yyvsp[(5) - (6)]).s;			 
			 }
    break;

  case 116:
#line 1393 "taoparser.yy"
    {
/*******************************************************************************/
std::cout << "\n#line " << lineno << " \"" << scriptname << "\"";
/*******************************************************************************/
                      	}
    break;

  case 119:
#line 1403 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n" << indent << "tao.popStartAndEnd();";
std::cout << "\n" << indent << "}\n";
/*******************************************************************************/

			 UNINDENT();
			 }
    break;

  case 120:
#line 1415 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 if ((yyvsp[(4) - (4)]).s[0]=='\0')   // no for part
			     {
			     float timeFactor=1.0;
			     float target;

			     if (streq((yyvsp[(3) - (4)]).s,"min") || streq((yyvsp[(3) - (4)]).s,"mins"))
				 timeFactor*=60.0;
			     else if (streq((yyvsp[(3) - (4)]).s,"msecs"))
				 timeFactor/=1000.0;
			     
			     if ((yyvsp[(2) - (4)]).t&NUM)
				 {
				 target=(yyvsp[(2) - (4)]).f*timeFactor;

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
		"if (Tick==(long)(" << (yyvsp[(2) - (4)]).s << "*" << timeFactor << "f*"
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

			     if (streq((yyvsp[(3) - (4)]).s,"min") || streq((yyvsp[(3) - (4)]).s,"mins"))
			         timeFactor=60.0;
			     else if (streq((yyvsp[(3) - (4)]).s,"msecs"))
				 timeFactor=0.001;

			     if ((yyvsp[(2) - (4)]).t&NUM && (yyvsp[(4) - (4)]).t&NUM)
				  {
				  start=(yyvsp[(2) - (4)]).f*timeFactor;
				  end=start+(yyvsp[(4) - (4)]).f;
				
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
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << (yyvsp[(2) - (4)]).s << "*"
        << "\n" << timeFactor << "+" << (yyvsp[(4) - (4)]).s << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&"
        << "\n" << indent << " Tick>=(long)((tao.newStart=" << (yyvsp[(2) - (4)]).s << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();" << std::ends;
/*******************************************************************************/

				  }
			     }

			 INDENT();

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (4)]).s;
			 delete [] (yyvsp[(2) - (4)]).s;
			 delete [] (yyvsp[(3) - (4)]).s;
			 delete [] (yyvsp[(4) - (4)]).s;
			 std::cout << (yyval).s;
			 }
    break;

  case 121:
#line 1504 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float start, end;

			 if (streq((yyvsp[(6) - (6)]).s,"min") || streq((yyvsp[(6) - (6)]).s,"mins"))
			     timeFactor=60.0;
			 else if (streq((yyvsp[(6) - (6)]).s,"msecs"))
			     timeFactor=0.001;

			 if ((yyvsp[(5) - (6)]).t&NUM)
			     {
			     end=(yyvsp[(5) - (6)]).f*timeFactor;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << end << "f)*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&";
/*******************************************************************************/

			     }
			 else
			     {

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick<=(long)((tao.newEnd=" << (yyvsp[(5) - (6)]).s << "*" << 
						timeFactor << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate) &&";
/*******************************************************************************/

                             }

			 if (streq((yyvsp[(3) - (6)]).s,"min") || streq((yyvsp[(3) - (6)]).s,"mins"))
			     timeFactor=60.0;
			 else if (streq((yyvsp[(3) - (6)]).s,"msecs"))
			     timeFactor=0.001;

			 if ((yyvsp[(2) - (6)]).t&NUM)
			     {
			     start=(yyvsp[(2) - (6)]).f*timeFactor;

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
obuffer << "\n" << indent << " Tick>=(long)((tao.newStart=" << (yyvsp[(2) - (6)]).s << "*" <<
							timeFactor << ")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

			     }

			 INDENT();
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 std::cout << (yyval).s;
			 }
    break;

  case 122:
#line 1579 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float start, end;

			 if (streq((yyvsp[(3) - (3)]).s,"min") || streq((yyvsp[(3) - (3)]).s,"mins"))
			     timeFactor=60.0;
			 else if (streq((yyvsp[(3) - (3)]).s,"msecs"))
			     timeFactor=0.001;

			 if ((yyvsp[(2) - (3)]).t&NUM)
			     {
			     end=(yyvsp[(2) - (3)]).f*timeFactor;

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
		    "(tao.newEnd="<<(yyvsp[(2) - (3)]).s<<"*"<<timeFactor<<")*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

                             }

			 INDENT();
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 std::cout << (yyval).s;
			 }
    break;

  case 123:
#line 1626 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float start, end;

			 if (streq((yyvsp[(3) - (3)]).s,"min") || streq((yyvsp[(3) - (3)]).s,"mins"))
			     timeFactor=60.0;
			 else if (streq((yyvsp[(3) - (3)]).s,"msecs"))
			     timeFactor=0.001;

			 if ((yyvsp[(2) - (3)]).t&NUM)
			     {
			     start=(yyvsp[(2) - (3)]).f*timeFactor;

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
		    "(tao.newStart=" << (yyvsp[(2) - (3)]).s << "*" << timeFactor << ")*"
	<< "\n" << indent << "tao.synthesisEngine.modelSampleRate))"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd1();\n" << std::ends;
/*******************************************************************************/

                             }

			 INDENT();
	
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 std::cout << (yyval).s;
			 }
    break;

  case 124:
#line 1673 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float interval;

			 if (streq((yyvsp[(3) - (3)]).s,"min") || streq((yyvsp[(3) - (3)]).s,"mins"))
			     timeFactor=60.0;
			 else if (streq((yyvsp[(3) - (3)]).s,"msecs"))
			     timeFactor=0.001;

			 if ((yyvsp[(2) - (3)]).t&NUM)
			     {
			     interval=(yyvsp[(2) - (3)]).f*timeFactor;

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
obuffer  << "\n" << indent << "if(Tick%(long)(" << (yyvsp[(2) - (3)]).s << "*"
						<< timeFactor << "*"
        << "\n" << indent << " tao.synthesisEngine.modelSampleRate)==0)"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd2();" << std::ends;
/*******************************************************************************/

			     }

			 INDENT();

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 std::cout << (yyval).s;
			 }
    break;

  case 125:
#line 1719 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "\n" << indent << "if(Tick%" << (yyvsp[(2) - (2)]).i << "L==0)"
        << "\n" << indent << "    {"
        << "\n" << indent << "    tao.pushStartAndEnd2();" << std::ends;
/*******************************************************************************/

			 INDENT();

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 std::cout << (yyval).s;
			 }
    break;

  case 126:
#line 1739 "taoparser.yy"
    {
			 (yyval).t=STR;
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 127:
#line 1745 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 float timeFactor=1.0;
			 float targetTime;
			 if (streq((yyvsp[(3) - (3)]).s,"min") || streq((yyvsp[(3) - (3)]).s,"mins"))
			     {
			     timeFactor=60.0;
			     }
			 else if (streq((yyvsp[(3) - (3)]).s,"msecs"))
			     {
			     timeFactor=0.001;
			     }
			 if ((yyvsp[(2) - (3)]).t&NUM) {
			     obuffer << (yyvsp[(2) - (3)]).f * timeFactor << "f" << std::ends;
			     (yyval).f=(yyvsp[(2) - (3)]).f*timeFactor;
			     (yyval).t=FLT;
			     }
			 else {
			     obuffer << (yyvsp[(2) - (3)]).s << "*" << timeFactor << std::ends;
			     (yyval).t=STR;
			     }
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 }
    break;

  case 130:
#line 1780 "taoparser.yy"
    {
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 131:
#line 1785 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 132:
#line 1791 "taoparser.yy"
    {
			 std::ostringstream obuffer;

			 if ((yyvsp[(1) - (3)]).t&INT && (yyvsp[(3) - (3)]).t&INT)
			     {
			     (yyval).t=INT;
			     (yyval).i=(yyvsp[(1) - (3)]).i + (yyvsp[(3) - (3)]).i;
			     obuffer << (yyval).i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else if ((yyvsp[(1) - (3)]).t&NUM && (yyvsp[(3) - (3)]).t&NUM)
			     {
			     (yyval).t=FLT;
			     (yyval).f=(yyvsp[(1) - (3)]).f + (yyvsp[(3) - (3)]).f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << (yyval).f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else
			     {
			     obuffer << (yyvsp[(1) - (3)]).s << (yyvsp[(2) - (3)]).s << (yyvsp[(3) - (3)]).s << std::ends;
			     (yyval).t=STR;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 }
    break;

  case 133:
#line 1829 "taoparser.yy"
    {
			 std::ostringstream obuffer;

			 if ((yyvsp[(1) - (3)]).t&INT && (yyvsp[(3) - (3)]).t&INT)
			     {
			     (yyval).t=INT;
			     (yyval).i=(yyvsp[(1) - (3)]).i - (yyvsp[(3) - (3)]).i;
			     obuffer << (yyval).i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else if ((yyvsp[(1) - (3)]).t&NUM && (yyvsp[(3) - (3)]).t&NUM)
			     {
			     (yyval).t=FLT;
			     (yyval).f=(yyvsp[(1) - (3)]).f - (yyvsp[(3) - (3)]).f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << (yyval).f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else
			     {
			     obuffer << (yyvsp[(1) - (3)]).s << (yyvsp[(2) - (3)]).s << (yyvsp[(3) - (3)]).s << std::ends;
			     (yyval).t=STR;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 }
    break;

  case 134:
#line 1867 "taoparser.yy"
    {
			 std::ostringstream obuffer;

			 if ((yyvsp[(1) - (3)]).t&INT && (yyvsp[(3) - (3)]).t&INT)
			     {
			     (yyval).t=INT;
			     (yyval).i=(yyvsp[(1) - (3)]).i * (yyvsp[(3) - (3)]).i;
			     obuffer << (yyval).i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else if ((yyvsp[(1) - (3)]).t&NUM && (yyvsp[(3) - (3)]).t&NUM)
			     {
			     (yyval).t=FLT;
			     (yyval).f=(yyvsp[(1) - (3)]).f * (yyvsp[(3) - (3)]).f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << (yyval).f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else
			     {
			     obuffer << (yyvsp[(1) - (3)]).s << (yyvsp[(2) - (3)]).s << (yyvsp[(3) - (3)]).s << std::ends;
			     (yyval).t=STR;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 }
    break;

  case 135:
#line 1905 "taoparser.yy"
    {
			 std::ostringstream obuffer;

			 if ((yyvsp[(1) - (3)]).t&INT && (yyvsp[(3) - (3)]).t&INT)
			     {
			     (yyval).t=INT;
			     (yyval).i=(yyvsp[(1) - (3)]).i / (yyvsp[(3) - (3)]).i;
			     obuffer << (yyval).i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else if ((yyvsp[(1) - (3)]).t&NUM && (yyvsp[(3) - (3)]).t&NUM)
			     {
			     (yyval).t=FLT;
			     (yyval).f=(yyvsp[(1) - (3)]).f / (yyvsp[(3) - (3)]).f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << (yyval).f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else
			     {
			     obuffer << (yyvsp[(1) - (3)]).s << (yyvsp[(2) - (3)]).s << (yyvsp[(3) - (3)]).s << std::ends;
			     (yyval).t=STR;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 }
    break;

  case 136:
#line 1942 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 137:
#line 1943 "taoparser.yy"
    {BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 138:
#line 1944 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 139:
#line 1945 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 140:
#line 1946 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 141:
#line 1947 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 142:
#line 1948 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 143:
#line 1949 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 144:
#line 1950 "taoparser.yy"
    {BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 145:
#line 1952 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer << (yyvsp[(1) - (3)]).s << " && " << (yyvsp[(3) - (3)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (3)]).s;
			delete [] (yyvsp[(2) - (3)]).s;
			delete [] (yyvsp[(3) - (3)]).s;
			}
    break;

  case 146:
#line 1962 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer << (yyvsp[(1) - (3)]).s << " || " << (yyvsp[(3) - (3)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (3)]).s;
			delete [] (yyvsp[(2) - (3)]).s;
			delete [] (yyvsp[(3) - (3)]).s;
			}
    break;

  case 147:
#line 1972 "taoparser.yy"
    {
			std::ostringstream obuffer;
			obuffer << "!" << (yyvsp[(2) - (2)]).s << std::ends;
			//$$.s=obuffer.str();
			strallocpy((yyval).s, obuffer.str().c_str());
			delete [] (yyvsp[(1) - (2)]).s;
			delete [] (yyvsp[(2) - (2)]).s;
			}
    break;

  case 148:
#line 1981 "taoparser.yy"
    {
			 std::ostringstream obuffer;

			 if ((yyvsp[(2) - (3)]).t&INT)
			     {
			     (yyval).t=INT;
			     (yyval).i=(yyvsp[(2) - (3)]).i;
			     obuffer << (yyval).i << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else if ((yyvsp[(2) - (3)]).t&NUM)
			     {
			     (yyval).t=FLT;
			     (yyval).f=(yyvsp[(2) - (3)]).f;
			     obuffer.setf(std::ios::showpoint);
			     obuffer << (yyval).f << "f" << std::ends;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 else
			     {
			     obuffer << (yyvsp[(1) - (3)]).s << (yyvsp[(2) - (3)]).s << (yyvsp[(3) - (3)]).s << std::ends;
			     (yyval).t=STR;
			     //$$.s=obuffer.str();
			     strallocpy((yyval).s, obuffer.str().c_str());
			     delete [] (yyvsp[(1) - (3)]).s;
			     delete [] (yyvsp[(2) - (3)]).s;
			     delete [] (yyvsp[(3) - (3)]).s;
			     }
			 }
    break;

  case 149:
#line 2018 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 150:
#line 2019 "taoparser.yy"
    {BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 151:
#line 2020 "taoparser.yy"
    {BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 152:
#line 2021 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 153:
#line 2022 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 154:
#line 2023 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 155:
#line 2025 "taoparser.yy"
    {BUILD6((yyval),(yyvsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));}
    break;

  case 156:
#line 2027 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);

			 if ((yyvsp[(3) - (6)]).t&STR && (yyvsp[(5) - (6)]).t&STR)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< (yyvsp[(5) - (6)]).s << "-" << (yyvsp[(3) - (6)]).s << ")+" << (yyvsp[(3) - (6)]).s << ")" << std::ends;
/*******************************************************************************/

			     }
			 else if ((yyvsp[(3) - (6)]).t&NUM && (yyvsp[(5) - (6)]).t&STR)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< (yyvsp[(5) - (6)]).s << "-" << (yyvsp[(3) - (6)]).f << "f)+" << (yyvsp[(3) - (6)]).f << "f)" << std::ends;
/*******************************************************************************/
			     
			     }
			 else if ((yyvsp[(3) - (6)]).t&STR && (yyvsp[(5) - (6)]).t&NUM)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< (yyvsp[(5) - (6)]).f << "f-" << (yyvsp[(3) - (6)]).s << ")+" << (yyvsp[(3) - (6)]).s << ")" << std::ends;
/*******************************************************************************/

			     }
			 else if ((yyvsp[(3) - (6)]).t&NUM && (yyvsp[(5) - (6)]).t&NUM)
			     {

/*******************************************************************************/
obuffer << "((Time-tao.start)/(tao.end-tao.start)*("
<< (yyvsp[(5) - (6)]).f << "f-" << (yyvsp[(3) - (6)]).f << "f)+" << (yyvsp[(3) - (6)]).f << "f)" << std::ends;
/*******************************************************************************/

			     }			

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 157:
#line 2078 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);

			 if ((yyvsp[(3) - (6)]).t&STR && (yyvsp[(5) - (6)]).t&STR)
			     {

/*******************************************************************************/
obuffer << "((float)(" << (yyvsp[(3) - (6)]).s <<
	")*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << (yyvsp[(5) - (6)]).s << ")/(float)("
	<< (yyvsp[(3) - (6)]).s << "))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/

			     }
			 else if ((yyvsp[(3) - (6)]).t&NUM && (yyvsp[(5) - (6)]).t&STR)
			     {

/*******************************************************************************/
obuffer << "((float)(" << (yyvsp[(3) - (6)]).f <<
	"f)*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << (yyvsp[(5) - (6)]).s << ")/(float)("
	<< (yyvsp[(3) - (6)]).f << "f))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/
			     
			     }
			 else if ((yyvsp[(3) - (6)]).t&STR && (yyvsp[(5) - (6)]).t&NUM)
			     {

/*******************************************************************************/
obuffer << "((float)(" << (yyvsp[(3) - (6)]).s <<
	")*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << (yyvsp[(5) - (6)]).f << "f)/(float)("
	<< (yyvsp[(3) - (6)]).s << "))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/

			     }
			 else if ((yyvsp[(3) - (6)]).t&NUM && (yyvsp[(5) - (6)]).t&NUM)
			     {

/*******************************************************************************/
obuffer << "((float)(" << (yyvsp[(3) - (6)]).f <<
	"f)*exp(1.0/(tao.end-tao.start)*"
	"log((float)(" << (yyvsp[(5) - (6)]).f << "f)/(float)("
	<< (yyvsp[(3) - (6)]).f << "f))*(Time-tao.start)))" << std::ends;
/*******************************************************************************/

			     }			
		 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 158:
#line 2137 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer << (yyvsp[(1) - (1)]).f << "f" << std::ends;
			 (yyval).t=FLT;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 159:
#line 2147 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << (yyvsp[(1) - (1)]).i << std::ends;
			 (yyval).t=INT;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 160:
#line 2156 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 161:
#line 2160 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 162:
#line 2164 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << 1 << std::ends;
			 (yyval).i=1;
			 (yyval).t=INT;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 163:
#line 2174 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << 0 << std::ends;
			 (yyval).i=0;
			 (yyval).t=INT;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 164:
#line 2184 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << (yyvsp[(1) - (1)]).s << ".0" << std::ends;
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 165:
#line 2193 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer << (yyvsp[(1) - (1)]).f << "f" << std::ends;
			 (yyval).t=STR;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 166:
#line 2205 "taoparser.yy"
    {
			 BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));
			 }
    break;

  case 167:
#line 2211 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 168:
#line 2215 "taoparser.yy"
    {
			 BUILD2((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));
			 }
    break;

  case 169:
#line 2221 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 170:
#line 2227 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "tao.start" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 171:
#line 2235 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "tao.end" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 172:
#line 2243 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "tao.synthesisEngine.time" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 173:
#line 2251 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "tao.synthesisEngine.tick" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 174:
#line 2261 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 175:
#line 2265 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 176:
#line 2271 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 177:
#line 2277 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 178:
#line 2281 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 179:
#line 2285 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 180:
#line 2289 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 181:
#line 2293 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 182:
#line 2297 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 183:
#line 2301 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 184:
#line 2305 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 185:
#line 2309 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 186:
#line 2313 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 187:
#line 2317 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 188:
#line 2321 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 189:
#line 2325 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 190:
#line 2329 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 191:
#line 2333 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 192:
#line 2337 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 193:
#line 2341 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 194:
#line 2345 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 195:
#line 2351 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 196:
#line 2355 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 197:
#line 2361 "taoparser.yy"
    {
			 std::cout << "\n" << indent << (yyvsp[(1) - (2)]).s << ";";
			 }
    break;

  case 202:
#line 2369 "taoparser.yy"
    {
			 std::cout << "\n" << indent << (yyvsp[(1) - (2)]).s << ";";
			 }
    break;

  case 203:
#line 2373 "taoparser.yy"
    {
			 std::cout << "\n" << indent << (yyvsp[(1) - (2)]).s << ";";
			 }
    break;

  case 204:
#line 2377 "taoparser.yy"
    {
			 std::cout << "\n" << indent << (yyvsp[(1) - (2)]).s << ";";
			 }
    break;

  case 205:
#line 2381 "taoparser.yy"
    {
			 std::cout << "\n" << indent << (yyvsp[(1) - (2)]).s << ";";
			 }
    break;

  case 206:
#line 2385 "taoparser.yy"
    {
			 std::cout << "\n" << indent << (yyvsp[(1) - (2)]).s << ";";
			 }
    break;

  case 207:
#line 2391 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer <<(yyvsp[(3) - (6)]).s<<"("<<(yyvsp[(1) - (6)]).s<<", "<<(yyvsp[(5) - (6)]).s;
			 if ((yyvsp[(6) - (6)]).s[0]!='\0')
			     {
			     obuffer << ", " << (yyvsp[(6) - (6)]).s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 208:
#line 2410 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<(yyvsp[(3) - (6)]).s<<"("<<(yyvsp[(1) - (6)]).s<<", "<<(yyvsp[(5) - (6)]).f << "f";
			 if ((yyvsp[(6) - (6)]).s[0]!='\0')
			     {
			     obuffer << ", " << (yyvsp[(6) - (6)]).s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 209:
#line 2430 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<(yyvsp[(3) - (6)]).s<<"("<<(yyvsp[(1) - (6)]).f<<"f, "<<(yyvsp[(5) - (6)]).s;
			 if ((yyvsp[(6) - (6)]).s[0]!='\0')
			     {
			     obuffer << ", " << (yyvsp[(6) - (6)]).s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 210:
#line 2450 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<(yyvsp[(3) - (6)]).s<<"("<<(yyvsp[(1) - (6)]).s<<", "<<(yyvsp[(5) - (6)]).s;
			 if ((yyvsp[(6) - (6)]).s[0]!='\0')
			     {
			     obuffer << ", " << (yyvsp[(6) - (6)]).s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 211:
#line 2470 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<(yyvsp[(3) - (6)]).s<<"("<<(yyvsp[(1) - (6)]).s<<", "<<(yyvsp[(5) - (6)]).s;
			 if ((yyvsp[(6) - (6)]).s[0]!='\0')
			     {
			     obuffer << ", " << (yyvsp[(6) - (6)]).s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 212:
#line 2490 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer.setf(std::ios::showpoint);
			 obuffer <<(yyvsp[(3) - (6)]).s<<"("<<(yyvsp[(1) - (6)]).s<<", "<<(yyvsp[(5) - (6)]).s;
			 if ((yyvsp[(6) - (6)]).s[0]!='\0')
			     {
			     obuffer << ", " << (yyvsp[(6) - (6)]).s;
			     }
			 obuffer << ")" << std::ends;
			 
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 delete [] (yyvsp[(6) - (6)]).s;
			 }
    break;

  case 213:
#line 2512 "taoparser.yy"
    {
			 (yyval).s=new char[1];
			 (yyval).s[0]='\0';
			 }
    break;

  case 214:
#line 2517 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << (yyvsp[(2) - (2)]).s << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 215:
#line 2528 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << (yyvsp[(3) - (3)]).s << "(" << (yyvsp[(1) - (3)]).s << ")" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 }
    break;

  case 216:
#line 2540 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << (yyvsp[(1) - (5)]).s << "." << (yyvsp[(3) - (5)]).s << "(" << (yyvsp[(5) - (5)]).s << ")" << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (5)]).s;
			 delete [] (yyvsp[(2) - (5)]).s;			 
			 delete [] (yyvsp[(3) - (5)]).s;			 
			 delete [] (yyvsp[(4) - (5)]).s;			 
			 delete [] (yyvsp[(5) - (5)]).s;			 
			 }
    break;

  case 217:
#line 2558 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "TaoInstrument::join(" << (yyvsp[(2) - (4)]).s << "," << (yyvsp[(4) - (4)]).s << ")" << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (4)]).s;
			 delete [] (yyvsp[(2) - (4)]).s;			 
			 delete [] (yyvsp[(3) - (4)]).s;			 
			 delete [] (yyvsp[(4) - (4)]).s;			 
			 }
    break;

  case 218:
#line 2575 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 219:
#line 2579 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 220:
#line 2585 "taoparser.yy"
    {
			 BUILD1((yyval),(yyvsp[(1) - (1)]));
			 }
    break;

  case 221:
#line 2589 "taoparser.yy"
    {
			 BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
			 }
    break;

  case 222:
#line 2594 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 223:
#line 2595 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 224:
#line 2596 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 225:
#line 2597 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 226:
#line 2598 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 227:
#line 2599 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 228:
#line 2600 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 229:
#line 2601 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 230:
#line 2602 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 231:
#line 2603 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 232:
#line 2604 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 233:
#line 2605 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 234:
#line 2606 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 235:
#line 2607 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 236:
#line 2608 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 237:
#line 2609 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 238:
#line 2610 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 239:
#line 2611 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 240:
#line 2612 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 241:
#line 2613 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 242:
#line 2614 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 243:
#line 2615 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 244:
#line 2616 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 245:
#line 2617 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 246:
#line 2618 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 247:
#line 2619 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 248:
#line 2620 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 249:
#line 2621 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 250:
#line 2622 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 251:
#line 2623 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 252:
#line 2624 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 253:
#line 2625 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 254:
#line 2626 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 255:
#line 2628 "taoparser.yy"
    {BUILD6((yyval),(yyvsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));}
    break;

  case 256:
#line 2630 "taoparser.yy"
    {BUILD6((yyval),(yyvsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));}
    break;

  case 257:
#line 2632 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 258:
#line 2634 "taoparser.yy"
    {BUILD6((yyval),(yyvsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));}
    break;

  case 259:
#line 2636 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 260:
#line 2638 "taoparser.yy"
    {BUILD6((yyval),(yyvsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));}
    break;

  case 261:
#line 2640 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 262:
#line 2642 "taoparser.yy"
    {BUILD6((yyval),(yyvsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));}
    break;

  case 263:
#line 2644 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 264:
#line 2648 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 265:
#line 2651 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 266:
#line 2654 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 267:
#line 2657 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 268:
#line 2660 "taoparser.yy"
    {BUILD4((yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 269:
#line 2663 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 270:
#line 2664 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 271:
#line 2667 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 272:
#line 2670 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 273:
#line 2671 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 274:
#line 2675 "taoparser.yy"
    {
		         UNINDENT();

/*******************************************************************************/
std::cout << "\n" << indent << "    }\n";
/*******************************************************************************/

			 }
    break;

  case 275:
#line 2685 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
std::cout << "\n" << indent << "for(" << (yyvsp[(2) - (6)]).s << "=" << (yyvsp[(4) - (6)]).s << ";"
				 << (yyvsp[(2) - (6)]).s << "<=" << (yyvsp[(6) - (6)]).s << ";"
				 << (yyvsp[(2) - (6)]).s << "++)"
        "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();
			 delete [] (yyvsp[(1) - (6)]).s;
			 delete [] (yyvsp[(2) - (6)]).s;
			 delete [] (yyvsp[(3) - (6)]).s;
			 delete [] (yyvsp[(4) - (6)]).s;
			 delete [] (yyvsp[(5) - (6)]).s;
			 }
    break;

  case 276:
#line 2704 "taoparser.yy"
    {
			 UNINDENT();
			 
/*******************************************************************************/
std::cout << "\n" << indent << "    }\n";
/*******************************************************************************/

			 }
    break;

  case 278:
#line 2716 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n" << indent << "if (" << (yyvsp[(2) - (2)]).s << ")";
std::cout << "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();

			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 280:
#line 2732 "taoparser.yy"
    {
			 UNINDENT();
		 
/*******************************************************************************/
std::cout << "\n" << indent << "    }\n";
/*******************************************************************************/

			 }
    break;

  case 281:
#line 2743 "taoparser.yy"
    {
			 UNINDENT();

/*******************************************************************************/
std::cout << "\n" << indent << "    }";
std::cout << "\n" << indent << "else if (" << (yyvsp[(2) - (2)]).s << ")";
std::cout << "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();
			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 282:
#line 2759 "taoparser.yy"
    {
			 UNINDENT();

/*******************************************************************************/
std::cout << "\n" << indent << "    }";
std::cout << "\n" << indent << "else";
std::cout << "\n" << indent << "    {";
/*******************************************************************************/

			 INDENT();
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 285:
#line 2778 "taoparser.yy"
    {
/*******************************************************************************/
std::cout << "\n#line " << lineno << " \"" << scriptname << "\"";
/*******************************************************************************/
			 }
    break;

  case 287:
#line 2785 "taoparser.yy"
    {
			 if (!in_score_block)
			    yyerror("Control structure not allowed here");
			 }
    break;

  case 288:
#line 2792 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n" << indent << "std::cout <<";
std::cout << (yyvsp[(2) - (2)]).s;
/*******************************************************************************/

			 delete [] (yyvsp[(1) - (2)]).s;
			 delete [] (yyvsp[(2) - (2)]).s;
			 }
    break;

  case 289:
#line 2805 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "\n" << indent << "    " << (yyvsp[(1) - (1)]).s << ";\n" << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 290:
#line 2817 "taoparser.yy"
    {
			 std::ostringstream obuffer;

/*******************************************************************************/
obuffer << "\n" << indent << "    " << (yyvsp[(1) - (3)]).s << "<<" << (yyvsp[(3) - (3)]).s << std::ends;
/*******************************************************************************/

			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (3)]).s;
			 delete [] (yyvsp[(2) - (3)]).s;
			 delete [] (yyvsp[(3) - (3)]).s;
			 }
    break;

  case 291:
#line 2832 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 292:
#line 2833 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 293:
#line 2835 "taoparser.yy"
    {
			 std::ostringstream obuffer;
			 obuffer << "std::endl" << std::ends;
			 //$$.s=obuffer.str();
			 strallocpy((yyval).s, obuffer.str().c_str());
			 delete [] (yyvsp[(1) - (1)]).s;
			 }
    break;

  case 294:
#line 2842 "taoparser.yy"
    {BUILD1((yyval),(yyvsp[(1) - (1)]));}
    break;

  case 295:
#line 2845 "taoparser.yy"
    {BUILD3((yyval),(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 296:
#line 2851 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n" << indent << "tao.graphicsEngine.label("
     << "\n" << indent << "    " << (yyvsp[(3) - (19)]).s << "," << (yyvsp[(5) - (19)]).s
     << "," << (yyvsp[(7) - (19)]).s << "," << (yyvsp[(9) - (19)]).s << "," << (yyvsp[(11) - (19)]).s << "," << (yyvsp[(13) - (19)]).s 
     << "," << (yyvsp[(15) - (19)]).s << "," << (yyvsp[(17) - (19)]).s << ");"
     << std::endl;
/*******************************************************************************/

			 delete [] (yyvsp[(1) - (19)]).s;
			 delete [] (yyvsp[(2) - (19)]).s;			 
			 delete [] (yyvsp[(3) - (19)]).s;			 
			 delete [] (yyvsp[(4) - (19)]).s;			 
			 delete [] (yyvsp[(5) - (19)]).s;
			 delete [] (yyvsp[(6) - (19)]).s;			 
			 delete [] (yyvsp[(7) - (19)]).s;			 
			 delete [] (yyvsp[(8) - (19)]).s;			 
			 delete [] (yyvsp[(9) - (19)]).s;
			 delete [] (yyvsp[(10) - (19)]).s;			 
			 delete [] (yyvsp[(11) - (19)]).s;		 
			 delete [] (yyvsp[(12) - (19)]).s;			 
			 delete [] (yyvsp[(13) - (19)]).s;		 
			 delete [] (yyvsp[(14) - (19)]).s;			 
			 delete [] (yyvsp[(15) - (19)]).s;		 
			 delete [] (yyvsp[(16) - (19)]).s;			 
			 delete [] (yyvsp[(17) - (19)]).s;		 
			 delete [] (yyvsp[(18) - (19)]).s;			 
			 delete [] (yyvsp[(19) - (19)]).s;		 
			 }
    break;

  case 297:
#line 2883 "taoparser.yy"
    {

/*******************************************************************************/
std::cout << "\n" << indent << "tao.graphicsEngine.label("
     << "\n" << indent << "    " << (yyvsp[(3) - (21)]).s << "," << (yyvsp[(5) - (21)]).s
     << "," << (yyvsp[(7) - (21)]).s << "," << (yyvsp[(9) - (21)]).s << "," << (yyvsp[(11) - (21)]).s << "," << (yyvsp[(13) - (21)]).s 
     << "," << (yyvsp[(15) - (21)]).s << "," << (yyvsp[(17) - (21)]).s << "," << (yyvsp[(19) - (21)]).s << ");"
     << std::endl;
/*******************************************************************************/

			 delete [] (yyvsp[(1) - (21)]).s;
			 delete [] (yyvsp[(2) - (21)]).s;			 
			 delete [] (yyvsp[(3) - (21)]).s;			 
			 delete [] (yyvsp[(4) - (21)]).s;			 
			 delete [] (yyvsp[(5) - (21)]).s;
			 delete [] (yyvsp[(6) - (21)]).s;			 
			 delete [] (yyvsp[(7) - (21)]).s;			 
			 delete [] (yyvsp[(8) - (21)]).s;			 
			 delete [] (yyvsp[(9) - (21)]).s;
			 delete [] (yyvsp[(10) - (21)]).s;			 
			 delete [] (yyvsp[(11) - (21)]).s;		 
			 delete [] (yyvsp[(12) - (21)]).s;			 
			 delete [] (yyvsp[(13) - (21)]).s;		 
			 delete [] (yyvsp[(14) - (21)]).s;			 
			 delete [] (yyvsp[(15) - (21)]).s;		 
			 delete [] (yyvsp[(16) - (21)]).s;			 
			 delete [] (yyvsp[(17) - (21)]).s;		 
			 delete [] (yyvsp[(18) - (21)]).s;			 
			 delete [] (yyvsp[(19) - (21)]).s;		 
			 delete [] (yyvsp[(20) - (21)]).s;			 
			 delete [] (yyvsp[(21) - (21)]).s;		 
			 }
    break;


/* Line 1267 of yacc.c.  */
#line 5917 "taoparser.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 2917 "taoparser.yy"



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

