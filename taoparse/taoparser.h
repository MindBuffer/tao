/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

