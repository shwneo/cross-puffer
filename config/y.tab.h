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
     AND = 258,
     AT = 259,
     ATTACH = 260,
     BUILD = 261,
     COMPILE_WITH = 262,
     LINT_WITH = 263,
     CONFIG = 264,
     DEFINE = 265,
     DEFOPT = 266,
     DEVICE = 267,
     DISABLE = 268,
     DUMPS = 269,
     ENDFILE = 270,
     XFILE = 271,
     XOBJECT = 272,
     FLAGS = 273,
     INCLUDE = 274,
     XMACHINE = 275,
     MAJOR = 276,
     MAKEOPTIONS = 277,
     MAXUSERS = 278,
     MAXPARTITIONS = 279,
     MINOR = 280,
     ON = 281,
     OPTIONS = 282,
     PSEUDO_DEVICE = 283,
     ROOT = 284,
     SOURCE = 285,
     SWAP = 286,
     WITH = 287,
     NEEDS_COUNT = 288,
     NEEDS_FLAG = 289,
     RMOPTIONS = 290,
     ENABLE = 291,
     NUMBER = 292,
     PATHNAME = 293,
     WORD = 294,
     EMPTY = 295
   };
#endif
/* Tokens.  */
#define AND 258
#define AT 259
#define ATTACH 260
#define BUILD 261
#define COMPILE_WITH 262
#define LINT_WITH 263
#define CONFIG 264
#define DEFINE 265
#define DEFOPT 266
#define DEVICE 267
#define DISABLE 268
#define DUMPS 269
#define ENDFILE 270
#define XFILE 271
#define XOBJECT 272
#define FLAGS 273
#define INCLUDE 274
#define XMACHINE 275
#define MAJOR 276
#define MAKEOPTIONS 277
#define MAXUSERS 278
#define MAXPARTITIONS 279
#define MINOR 280
#define ON 281
#define OPTIONS 282
#define PSEUDO_DEVICE 283
#define ROOT 284
#define SOURCE 285
#define SWAP 286
#define WITH 287
#define NEEDS_COUNT 288
#define NEEDS_FLAG 289
#define RMOPTIONS 290
#define ENABLE 291
#define NUMBER 292
#define PATHNAME 293
#define WORD 294
#define EMPTY 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 94 "gram.y"
{
	struct	attr *attr;
	struct	devbase *devb;
	struct	deva *deva;
	struct	nvlist *list;
	const char *str;
	int	val;
}
/* Line 1489 of yacc.c.  */
#line 138 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

