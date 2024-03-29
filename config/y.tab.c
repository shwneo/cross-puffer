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




/* Copy the first part of user declarations.  */
#line 1 "gram.y"

/*	$OpenBSD: gram.y,v 1.22 2008/03/24 21:35:03 maja Exp $	*/
/*	$NetBSD: gram.y,v 1.14 1997/02/02 21:12:32 thorpej Exp $	*/

/*
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This software was developed by the Computer Systems Engineering group
 * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and
 * contributed to Berkeley.
 *
 * All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Lawrence Berkeley Laboratories.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)gram.y	8.1 (Berkeley) 6/6/93
 */

#include <sys/types.h>
#ifdef __linux__
#include "param.h"
#else
#include <sys/param.h>
#endif
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "config.h"
#include "sem.h"

#define	FORMAT(n) ((n) > -10 && (n) < 10 ? "%d" : "0x%x")

#define	stop(s)	error(s), exit(1)

int	include(const char *, int);
void	yyerror(const char *);
int	yylex(void);

static	struct	config conf;	/* at most one active at a time */

/* the following is used to recover nvlist space after errors */
static	struct	nvlist *alloc[1000];
static	int	adepth;
#define	new0(n,s,p,i,x)	(alloc[adepth++] = newnv(n, s, p, i, x))
#define	new_n(n)	new0(n, NULL, NULL, 0, NULL)
#define	new_nx(n, x)	new0(n, NULL, NULL, 0, x)
#define	new_ns(n, s)	new0(n, s, NULL, 0, NULL)
#define	new_si(s, i)	new0(NULL, s, NULL, i, NULL)
#define	new_nsi(n,s,i)	new0(n, s, NULL, i, NULL)
#define	new_np(n, p)	new0(n, NULL, p, 0, NULL)
#define	new_s(s)	new0(NULL, s, NULL, 0, NULL)
#define	new_p(p)	new0(NULL, NULL, p, 0, NULL)
#define	new_px(p, x)	new0(NULL, NULL, p, 0, x)

#define	fx_atom(s)	new0(s, NULL, NULL, FX_ATOM, NULL)
#define	fx_not(e)	new0(NULL, NULL, NULL, FX_NOT, e)
#define	fx_and(e1, e2)	new0(NULL, NULL, e1, FX_AND, e2)
#define	fx_or(e1, e2)	new0(NULL, NULL, e1, FX_OR, e2)

static	void	cleanup(void);
static	void	setmachine(const char *, const char *);
static	void	check_maxpart(void);



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
/* Line 187 of yacc.c.  */
#line 278 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 291 "y.tab.c"

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
# if YYENABLE_NLS
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
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  225

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,     2,    42,     2,
      45,    46,    55,     2,    49,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
       2,    52,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    41,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    15,    18,    19,    23,    27,    30,
      32,    36,    41,    43,    45,    47,    51,    58,    63,    65,
      66,    68,    71,    75,    79,    83,    85,    88,    89,    91,
      93,    96,    97,    99,   102,   103,   106,   107,   110,   113,
     114,   117,   119,   122,   124,   126,   128,   132,   135,   140,
     147,   152,   155,   159,   164,   166,   167,   171,   173,   175,
     177,   179,   182,   183,   187,   188,   190,   191,   195,   197,
     200,   202,   207,   210,   212,   214,   216,   218,   221,   224,
     225,   229,   231,   233,   237,   239,   243,   246,   247,   250,
     252,   255,   257,   259,   261,   264,   267,   270,   273,   277,
     282,   287,   294,   298,   300,   304,   308,   310,   314,   316,
     318,   322,   324,   327,   329,   333,   337,   341,   345,   347,
     349,   351,   356,   358,   359,   361,   362,   365,   367,   369,
     372,   374,   377,   378,   381,   384,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,    60,    62,    77,    63,    77,    63,
      77,    63,    59,    97,    -1,    60,    61,    -1,    -1,    30,
      38,    43,    -1,     6,    38,    43,    -1,    76,    43,    -1,
      43,    -1,    20,    39,    43,    -1,    20,    39,    39,    43,
      -1,     1,    -1,    15,    -1,    38,    -1,    64,    41,    38,
      -1,    16,    64,    67,    70,    74,    75,    -1,    17,    38,
      67,    72,    -1,    68,    -1,    -1,    69,    -1,    44,    69,
      -1,    68,    42,    68,    -1,    68,    41,    68,    -1,    45,
      68,    46,    -1,    39,    -1,    70,    71,    -1,    -1,    33,
      -1,    34,    -1,    72,    73,    -1,    -1,    34,    -1,     7,
      39,    -1,    -1,     8,    39,    -1,    -1,    19,    39,    -1,
      77,    78,    -1,    -1,    79,    43,    -1,    43,    -1,     1,
      43,    -1,    65,    -1,    66,    -1,    76,    -1,    10,    39,
      85,    -1,    11,    39,    -1,    12,    83,    85,    92,    -1,
       5,    83,     4,    81,    84,    92,    -1,    23,    37,    37,
      37,    -1,    24,    37,    -1,    28,    83,    92,    -1,    21,
      47,    95,    48,    -1,    13,    -1,    -1,    81,    49,    82,
      -1,    82,    -1,    39,    -1,    29,    -1,    39,    -1,    32,
      39,    -1,    -1,    47,    86,    48,    -1,    -1,    87,    -1,
      -1,    88,    49,    87,    -1,    88,    -1,    39,    89,    -1,
      39,    -1,    50,    39,    89,    51,    -1,    52,    90,    -1,
      39,    -1,    40,    -1,    91,    -1,    37,    -1,    53,    37,
      -1,    54,    93,    -1,    -1,    93,    49,    94,    -1,    94,
      -1,    39,    -1,    95,    49,    96,    -1,    96,    -1,    83,
      52,    37,    -1,    97,    98,    -1,    -1,    99,    43,    -1,
      43,    -1,     1,    43,    -1,    65,    -1,    66,    -1,    76,
      -1,    27,   102,    -1,    35,   103,    -1,    22,   100,    -1,
      23,    37,    -1,     9,   105,   106,    -1,    28,    39,   112,
      80,    -1,   113,     4,   114,    36,    -1,   113,     4,   114,
      80,   115,   117,    -1,   100,    49,   101,    -1,   101,    -1,
      39,    52,    90,    -1,   102,    49,   104,    -1,   104,    -1,
     103,    49,    39,    -1,    39,    -1,    39,    -1,    39,    52,
      90,    -1,    39,    -1,   106,   107,    -1,   107,    -1,    29,
     111,   109,    -1,    31,   111,   108,    -1,    14,   111,   109,
      -1,   109,     3,   108,    -1,   109,    -1,    39,    -1,   110,
      -1,    21,    37,    25,    37,    -1,    26,    -1,    -1,    37,
      -1,    -1,    39,    55,    -1,    39,    -1,    29,    -1,    39,
      56,    -1,    39,    -1,   115,   116,    -1,    -1,    39,    90,
      -1,    39,    56,    -1,    18,    37,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   153,   153,   148,   157,   157,   161,   162,   163,   164,
     167,   168,   169,   172,   175,   176,   182,   185,   189,   190,
     193,   194,   195,   196,   197,   200,   203,   204,   207,   208,
     211,   212,   215,   218,   219,   222,   223,   226,   233,   233,
     237,   238,   239,   242,   243,   244,   245,   246,   247,   249,
     251,   252,   253,   254,   257,   258,   261,   262,   265,   266,
     269,   272,   273,   276,   277,   280,   281,   285,   286,   290,
     291,   292,   295,   298,   299,   300,   309,   310,   313,   314,
     317,   318,   321,   324,   325,   328,   336,   336,   340,   341,
     342,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   359,   360,   363,   366,   367,   370,   371,   374,
     375,   378,   385,   386,   389,   390,   391,   394,   395,   398,
     399,   402,   405,   405,   408,   409,   412,   413,   416,   417,
     418,   421,   422,   425,   426,   429,   430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "AT", "ATTACH", "BUILD",
  "COMPILE_WITH", "LINT_WITH", "CONFIG", "DEFINE", "DEFOPT", "DEVICE",
  "DISABLE", "DUMPS", "ENDFILE", "XFILE", "XOBJECT", "FLAGS", "INCLUDE",
  "XMACHINE", "MAJOR", "MAKEOPTIONS", "MAXUSERS", "MAXPARTITIONS", "MINOR",
  "ON", "OPTIONS", "PSEUDO_DEVICE", "ROOT", "SOURCE", "SWAP", "WITH",
  "NEEDS_COUNT", "NEEDS_FLAG", "RMOPTIONS", "ENABLE", "NUMBER", "PATHNAME",
  "WORD", "EMPTY", "'|'", "'&'", "'\\n'", "'!'", "'('", "')'", "'{'",
  "'}'", "','", "'['", "']'", "'='", "'-'", "':'", "'*'", "'?'", "$accept",
  "Configuration", "@1", "topthings", "topthing", "machine_spec",
  "dev_eof", "pathnames", "file", "object", "fopts", "fexpr", "fatom",
  "fflgs", "fflag", "oflgs", "oflag", "rule", "lintrule", "include",
  "dev_defs", "dev_def", "one_def", "disable", "atlist", "atname",
  "devbase", "devattach_opt", "interface_opt", "loclist_opt", "loclist",
  "locdef", "locdefault", "value", "signed_number", "attrs_opt", "attrs",
  "attr", "majorlist", "majordef", "specs", "spec", "config_spec",
  "mkopt_list", "mkoption", "opt_list", "ropt_list", "option", "conf",
  "sysparam_list", "sysparam", "swapdev_list", "dev_spec", "major_minor",
  "on_opt", "npseudo", "device_instance", "attachment", "locators",
  "locator", "flags_opt", 0
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
     295,   124,    38,    10,    33,    40,    41,   123,   125,    44,
      91,    93,    61,    45,    58,    42,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    59,    58,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    63,    64,    64,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    69,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    77,    77,
      78,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    90,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    95,    95,    96,    97,    97,    98,    98,
      98,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   102,   102,   103,   103,   104,
     104,   105,   106,   106,   107,   107,   107,   108,   108,   109,
     109,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   115,   115,   116,   116,   117,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    10,     2,     0,     3,     3,     2,     1,
       3,     4,     1,     1,     1,     3,     6,     4,     1,     0,
       1,     2,     3,     3,     3,     1,     2,     0,     1,     1,
       2,     0,     1,     2,     0,     2,     0,     2,     2,     0,
       2,     1,     2,     1,     1,     1,     3,     2,     4,     6,
       4,     2,     3,     4,     1,     0,     3,     1,     1,     1,
       1,     2,     0,     3,     0,     1,     0,     3,     1,     2,
       1,     4,     2,     1,     1,     1,     1,     2,     2,     0,
       3,     1,     1,     3,     1,     3,     2,     0,     2,     1,
       2,     1,     1,     1,     2,     2,     2,     2,     3,     4,
       4,     6,     3,     1,     3,     3,     1,     3,     1,     1,
       3,     1,     2,     1,     3,     3,     3,     3,     1,     1,
       1,     4,     1,     0,     1,     0,     2,     1,     1,     2,
       1,     2,     0,     2,     2,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,    12,     0,     0,     0,     0,     9,
       4,    39,     0,     0,    37,     0,     0,     0,     8,     7,
       0,    10,     6,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,    41,    39,    43,    44,    45,
      38,     0,    11,    42,    60,     0,    64,    47,    64,    14,
      19,    19,     0,     0,    51,    79,     0,    40,     0,    66,
      46,    79,    25,     0,     0,     0,    27,    18,    20,    31,
       0,     0,    84,     0,     0,    52,    39,    59,    58,    62,
      57,    70,     0,     0,    65,    68,    48,    15,    21,     0,
      34,     0,     0,    17,     0,    53,     0,    50,    82,    78,
      81,     0,     0,     0,    79,     0,    69,     0,    63,     0,
      24,     0,    28,    29,    26,    36,    23,    22,    32,    30,
      85,    83,     0,     2,    61,    56,    49,    76,    73,    74,
       0,    72,    75,     0,    67,    33,     0,    16,    80,    87,
      77,    71,    35,     0,     0,     0,     0,     0,     0,     0,
       0,   127,    89,    91,    92,    93,    86,     0,     0,    90,
     111,     0,     0,    96,   103,    97,   109,    94,   106,   125,
     108,    95,   126,    88,     0,   123,   123,   123,    98,   113,
       0,     0,     0,     0,   124,    55,     0,   128,   130,    55,
     122,     0,     0,     0,   112,   104,   102,   110,   105,    54,
      99,   107,   129,   100,   132,     0,   119,   116,   120,   114,
     115,   118,   136,     0,     0,     0,     0,   131,   101,     0,
     117,   135,   134,   133,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   139,     2,    10,    11,    36,    50,    37,    38,
      66,    67,    68,    90,   114,    93,   119,   115,   137,    39,
      17,    40,    41,   200,    79,    80,    70,   104,    60,    83,
      84,    85,   106,   131,   132,    75,    99,   100,    71,    72,
     143,   156,   157,   163,   164,   167,   171,   168,   161,   178,
     179,   210,   211,   208,   191,   185,   158,   189,   212,   217,
     218
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -175
static const yytype_int16 yypact[] =
{
    -175,    16,     8,  -175,  -175,    25,    -4,    41,    27,  -175,
    -175,  -175,    55,    61,  -175,    21,    62,    38,  -175,  -175,
      63,  -175,  -175,    64,    69,    70,    71,    69,  -175,    73,
      74,    66,    77,    78,    69,  -175,  -175,  -175,  -175,  -175,
    -175,    75,  -175,  -175,  -175,   112,    72,  -175,    72,  -175,
      48,    52,    69,    80,  -175,    67,    38,  -175,    43,    29,
    -175,    67,  -175,    82,    83,    52,  -175,   -19,  -175,  -175,
      76,    36,  -175,    86,    85,  -175,  -175,  -175,  -175,    26,
    -175,    79,    87,    81,  -175,    84,  -175,  -175,  -175,    53,
       0,    52,    52,    91,    90,  -175,    69,  -175,  -175,    88,
    -175,    38,    93,    43,    67,    37,  -175,    79,  -175,    29,
    -175,    95,  -175,  -175,  -175,   122,    94,  -175,  -175,  -175,
    -175,  -175,    85,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
      98,  -175,  -175,    89,  -175,  -175,    99,  -175,  -175,  -175,
    -175,  -175,  -175,     2,    96,   103,   104,   107,   106,   108,
     109,    97,  -175,  -175,  -175,  -175,  -175,   110,   142,  -175,
    -175,    42,   102,   100,  -175,  -175,   105,   101,  -175,   114,
    -175,   111,  -175,  -175,    49,   129,   129,   129,    42,  -175,
      37,   104,    37,   106,  -175,   143,   119,  -175,   113,     4,
    -175,     5,     5,     5,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   124,  -175,  -175,  -175,  -175,
    -175,   156,    -3,   137,     5,   126,    30,  -175,  -175,   127,
    -175,  -175,  -175,  -175,  -175
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,  -175,  -175,  -175,   -55,  -175,    22,    23,
     116,   -60,   115,  -175,  -175,  -175,  -175,  -175,  -175,    -2,
     -24,  -175,  -175,   -21,  -175,    68,   -14,  -175,   125,  -175,
      65,  -175,    92,  -174,  -175,   -57,  -175,    50,  -175,   117,
    -175,  -175,  -175,  -175,   -11,  -175,  -175,    -8,  -175,  -175,
      -1,   -38,   -91,  -175,   -74,  -175,  -175,  -175,  -175,  -175,
    -175
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -4
static const yytype_int16 yytable[] =
{
      12,    76,    -3,   144,    86,    89,   195,   111,   197,     4,
      45,   145,    56,    48,     5,   215,     3,   199,    29,    30,
      55,     6,    91,    92,   146,   147,   205,     6,     7,   148,
     149,   116,   117,   112,   113,    14,   216,   150,     8,    23,
     203,   151,   223,    24,   206,   152,   123,   126,    25,    26,
      27,     9,   101,    28,    29,    30,   175,     6,   102,    31,
      20,    32,    33,    13,    21,    16,    34,   127,    81,   128,
     129,   176,    77,   177,   127,   103,   128,   129,   187,    82,
      15,    35,    78,   130,    95,    96,   222,    62,   188,    63,
     130,    62,    64,    65,    91,    92,    64,    65,    18,   110,
     207,   209,   192,   193,    19,    22,    42,    43,    44,    46,
      47,    49,    51,    52,    53,    54,    58,    73,    57,    59,
      87,    74,    62,    97,    98,   118,   107,   120,    94,   108,
     136,   105,   124,   109,   135,   140,    92,   122,   142,   159,
     141,   155,   160,   162,   165,   166,   174,   169,   170,   181,
     183,   184,   172,   173,   180,   190,   199,   182,   201,   214,
     186,   213,   219,   221,   224,   153,   154,    69,   204,   202,
     196,   125,   138,    61,   134,   198,   220,   194,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
       2,    56,     0,     1,    61,    65,   180,     7,   182,     1,
      24,     9,    36,    27,     6,    18,     0,    13,    16,    17,
      34,    19,    41,    42,    22,    23,    21,    19,    20,    27,
      28,    91,    92,    33,    34,    39,    39,    35,    30,     1,
      36,    39,   216,     5,    39,    43,   101,   104,    10,    11,
      12,    43,    76,    15,    16,    17,    14,    19,    32,    21,
      39,    23,    24,    38,    43,    38,    28,    37,    39,    39,
      40,    29,    29,    31,    37,    49,    39,    40,    29,    50,
      39,    43,    39,    53,    48,    49,    56,    39,    39,    41,
      53,    39,    44,    45,    41,    42,    44,    45,    43,    46,
     191,   192,   176,   177,    43,    43,    43,    43,    39,    39,
      39,    38,    38,    47,    37,    37,     4,    37,    43,    47,
      38,    54,    39,    37,    39,    34,    39,    37,    52,    48,
       8,    52,    39,    49,    39,    37,    42,    49,    39,    43,
      51,   143,    39,    39,    37,    39,     4,    39,    39,    49,
      49,    37,    55,    43,    52,    26,    13,    52,    39,     3,
      49,    37,    25,    37,    37,   143,   143,    51,   189,    56,
     181,   103,   122,    48,   109,   183,   214,   178,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    60,     0,     1,     6,    19,    20,    30,    43,
      61,    62,    76,    38,    39,    39,    38,    77,    43,    43,
      39,    43,    43,     1,     5,    10,    11,    12,    15,    16,
      17,    21,    23,    24,    28,    43,    63,    65,    66,    76,
      78,    79,    43,    43,    39,    83,    39,    39,    83,    38,
      64,    38,    47,    37,    37,    83,    77,    43,     4,    47,
      85,    85,    39,    41,    44,    45,    67,    68,    69,    67,
      83,    95,    96,    37,    54,    92,    63,    29,    39,    81,
      82,    39,    50,    86,    87,    88,    92,    38,    69,    68,
      70,    41,    42,    72,    52,    48,    49,    37,    39,    93,
      94,    77,    32,    49,    84,    52,    89,    39,    48,    49,
      46,     7,    33,    34,    71,    74,    68,    68,    34,    73,
      37,    96,    49,    63,    39,    82,    92,    37,    39,    40,
      53,    90,    91,    89,    87,    39,     8,    75,    94,    59,
      37,    51,    39,    97,     1,     9,    22,    23,    27,    28,
      35,    39,    43,    65,    66,    76,    98,    99,   113,    43,
      39,   105,    39,   100,   101,    37,    39,   102,   104,    39,
      39,   103,    55,    43,     4,    14,    29,    31,   106,   107,
      52,    49,    52,    49,    37,   112,    49,    29,    39,   114,
      26,   111,   111,   111,   107,    90,   101,    90,   104,    13,
      80,    39,    56,    36,    80,    21,    39,   109,   110,   109,
     108,   109,   115,    37,     3,    18,    39,   116,   117,    25,
     108,    37,    56,    90,    37
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
# if YYLTYPE_IS_TRIVIAL
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
#line 153 "gram.y"
    { check_maxpart(); }
    break;

  case 6:
#line 161 "gram.y"
    { if (!srcdir) srcdir = (yyvsp[(2) - (3)].str); }
    break;

  case 7:
#line 162 "gram.y"
    { if (!builddir) builddir = (yyvsp[(2) - (3)].str); }
    break;

  case 10:
#line 167 "gram.y"
    { setmachine((yyvsp[(2) - (3)].str),NULL); }
    break;

  case 11:
#line 168 "gram.y"
    { setmachine((yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str)); }
    break;

  case 12:
#line 169 "gram.y"
    { stop("cannot proceed without machine specifier"); }
    break;

  case 13:
#line 172 "gram.y"
    { enddefs(); checkfiles(); }
    break;

  case 14:
#line 175 "gram.y"
    { (yyval.list) = new_nsi((yyvsp[(1) - (1)].str), NULL, 0); }
    break;

  case 15:
#line 176 "gram.y"
    { ((yyval.list) = (yyvsp[(1) - (3)].list))->nv_next = new_nsi((yyvsp[(3) - (3)].str), NULL, 0); }
    break;

  case 16:
#line 182 "gram.y"
    { addfile((yyvsp[(2) - (6)].list), (yyvsp[(3) - (6)].list), (yyvsp[(4) - (6)].val), (yyvsp[(5) - (6)].str), (yyvsp[(6) - (6)].str)); }
    break;

  case 17:
#line 185 "gram.y"
    { addobject((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].list), (yyvsp[(4) - (4)].val)); }
    break;

  case 18:
#line 189 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); }
    break;

  case 19:
#line 190 "gram.y"
    { (yyval.list) = NULL; }
    break;

  case 20:
#line 193 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); }
    break;

  case 21:
#line 194 "gram.y"
    { (yyval.list) = fx_not((yyvsp[(2) - (2)].list)); }
    break;

  case 22:
#line 195 "gram.y"
    { (yyval.list) = fx_and((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list)); }
    break;

  case 23:
#line 196 "gram.y"
    { (yyval.list) = fx_or((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list)); }
    break;

  case 24:
#line 197 "gram.y"
    { (yyval.list) = (yyvsp[(2) - (3)].list); }
    break;

  case 25:
#line 200 "gram.y"
    { (yyval.list) = fx_atom((yyvsp[(1) - (1)].str)); }
    break;

  case 26:
#line 203 "gram.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val) | (yyvsp[(2) - (2)].val); }
    break;

  case 27:
#line 204 "gram.y"
    { (yyval.val) = 0; }
    break;

  case 28:
#line 207 "gram.y"
    { (yyval.val) = FI_NEEDSCOUNT; }
    break;

  case 29:
#line 208 "gram.y"
    { (yyval.val) = FI_NEEDSFLAG; }
    break;

  case 30:
#line 211 "gram.y"
    { (yyval.val) = (yyvsp[(1) - (2)].val) | (yyvsp[(2) - (2)].val); }
    break;

  case 31:
#line 212 "gram.y"
    { (yyval.val) = 0; }
    break;

  case 32:
#line 215 "gram.y"
    { (yyval.val) = OI_NEEDSFLAG; }
    break;

  case 33:
#line 218 "gram.y"
    { (yyval.str) = (yyvsp[(2) - (2)].str); }
    break;

  case 34:
#line 219 "gram.y"
    { (yyval.str) = NULL; }
    break;

  case 35:
#line 222 "gram.y"
    { (yyval.str) = (yyvsp[(2) - (2)].str); }
    break;

  case 36:
#line 223 "gram.y"
    { (yyval.str) = NULL; }
    break;

  case 37:
#line 226 "gram.y"
    { include((yyvsp[(2) - (2)].str), 0); }
    break;

  case 40:
#line 237 "gram.y"
    { adepth = 0; }
    break;

  case 42:
#line 239 "gram.y"
    { cleanup(); }
    break;

  case 46:
#line 245 "gram.y"
    { (void)defattr((yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].list)); }
    break;

  case 47:
#line 246 "gram.y"
    { defoption((yyvsp[(2) - (2)].str)); }
    break;

  case 48:
#line 248 "gram.y"
    { defdev((yyvsp[(2) - (4)].devb), 0, (yyvsp[(3) - (4)].list), (yyvsp[(4) - (4)].list)); }
    break;

  case 49:
#line 250 "gram.y"
    { defdevattach((yyvsp[(5) - (6)].deva), (yyvsp[(2) - (6)].devb), (yyvsp[(4) - (6)].list), (yyvsp[(6) - (6)].list)); }
    break;

  case 50:
#line 251 "gram.y"
    { setdefmaxusers((yyvsp[(2) - (4)].val), (yyvsp[(3) - (4)].val), (yyvsp[(4) - (4)].val)); }
    break;

  case 51:
#line 252 "gram.y"
    { maxpartitions = (yyvsp[(2) - (2)].val); }
    break;

  case 52:
#line 253 "gram.y"
    { defdev((yyvsp[(2) - (3)].devb),1,NULL,(yyvsp[(3) - (3)].list)); }
    break;

  case 54:
#line 257 "gram.y"
    { (yyval.val) = 1; }
    break;

  case 55:
#line 258 "gram.y"
    { (yyval.val) = 0; }
    break;

  case 56:
#line 261 "gram.y"
    { (yyval.list) = new_nx((yyvsp[(3) - (3)].str), (yyvsp[(1) - (3)].list)); }
    break;

  case 57:
#line 262 "gram.y"
    { (yyval.list) = new_n((yyvsp[(1) - (1)].str)); }
    break;

  case 58:
#line 265 "gram.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 59:
#line 266 "gram.y"
    { (yyval.str) = NULL; }
    break;

  case 60:
#line 269 "gram.y"
    { (yyval.devb) = getdevbase((char *)(yyvsp[(1) - (1)].str)); }
    break;

  case 61:
#line 272 "gram.y"
    { (yyval.deva) = getdevattach((yyvsp[(2) - (2)].str)); }
    break;

  case 62:
#line 273 "gram.y"
    { (yyval.deva) = NULL; }
    break;

  case 63:
#line 276 "gram.y"
    { (yyval.list) = new_nx("", (yyvsp[(2) - (3)].list)); }
    break;

  case 64:
#line 277 "gram.y"
    { (yyval.list) = NULL; }
    break;

  case 65:
#line 280 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); }
    break;

  case 66:
#line 281 "gram.y"
    { (yyval.list) = NULL; }
    break;

  case 67:
#line 285 "gram.y"
    { ((yyval.list) = (yyvsp[(1) - (3)].list))->nv_next = (yyvsp[(3) - (3)].list); }
    break;

  case 68:
#line 286 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); }
    break;

  case 69:
#line 290 "gram.y"
    { (yyval.list) = new_nsi((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str), 0); }
    break;

  case 70:
#line 291 "gram.y"
    { (yyval.list) = new_nsi((yyvsp[(1) - (1)].str), NULL, 0); }
    break;

  case 71:
#line 292 "gram.y"
    { (yyval.list) = new_nsi((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), 1); }
    break;

  case 72:
#line 295 "gram.y"
    { (yyval.str) = (yyvsp[(2) - (2)].str); }
    break;

  case 73:
#line 298 "gram.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 74:
#line 299 "gram.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 75:
#line 300 "gram.y"
    {
						char bf[40];

						(void)snprintf(bf, sizeof bf,
						    FORMAT((yyvsp[(1) - (1)].val)), (yyvsp[(1) - (1)].val));
						(yyval.str) = intern(bf);
					}
    break;

  case 76:
#line 309 "gram.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 77:
#line 310 "gram.y"
    { (yyval.val) = -(yyvsp[(2) - (2)].val); }
    break;

  case 78:
#line 313 "gram.y"
    { (yyval.list) = (yyvsp[(2) - (2)].list); }
    break;

  case 79:
#line 314 "gram.y"
    { (yyval.list) = NULL; }
    break;

  case 80:
#line 317 "gram.y"
    { (yyval.list) = new_px((yyvsp[(3) - (3)].attr), (yyvsp[(1) - (3)].list)); }
    break;

  case 81:
#line 318 "gram.y"
    { (yyval.list) = new_p((yyvsp[(1) - (1)].attr)); }
    break;

  case 82:
#line 321 "gram.y"
    { (yyval.attr) = getattr((yyvsp[(1) - (1)].str)); }
    break;

  case 85:
#line 328 "gram.y"
    { setmajor((yyvsp[(1) - (3)].devb), (yyvsp[(3) - (3)].val)); }
    break;

  case 88:
#line 340 "gram.y"
    { adepth = 0; }
    break;

  case 90:
#line 342 "gram.y"
    { cleanup(); }
    break;

  case 97:
#line 351 "gram.y"
    { setmaxusers((yyvsp[(2) - (2)].val)); }
    break;

  case 98:
#line 352 "gram.y"
    { addconf(&conf); }
    break;

  case 99:
#line 353 "gram.y"
    { addpseudo((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].val), (yyvsp[(4) - (4)].val)); }
    break;

  case 100:
#line 354 "gram.y"
    { enabledev((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str)); }
    break;

  case 101:
#line 356 "gram.y"
    { adddev((yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].list), (yyvsp[(6) - (6)].val), (yyvsp[(4) - (6)].val)); }
    break;

  case 104:
#line 363 "gram.y"
    { addmkoption((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)); }
    break;

  case 107:
#line 370 "gram.y"
    { removeoption((yyvsp[(3) - (3)].str)); }
    break;

  case 108:
#line 371 "gram.y"
    { removeoption((yyvsp[(1) - (1)].str)); }
    break;

  case 109:
#line 374 "gram.y"
    { addoption((yyvsp[(1) - (1)].str), NULL); }
    break;

  case 110:
#line 375 "gram.y"
    { addoption((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)); }
    break;

  case 111:
#line 378 "gram.y"
    { conf.cf_name = (yyvsp[(1) - (1)].str);
					    conf.cf_lineno = currentline();
					    conf.cf_root = NULL;
					    conf.cf_swap = NULL;
					    conf.cf_dump = NULL; }
    break;

  case 114:
#line 389 "gram.y"
    { setconf(&conf.cf_root, "root", (yyvsp[(3) - (3)].list)); }
    break;

  case 115:
#line 390 "gram.y"
    { setconf(&conf.cf_swap, "swap", (yyvsp[(3) - (3)].list)); }
    break;

  case 116:
#line 391 "gram.y"
    { setconf(&conf.cf_dump, "dumps", (yyvsp[(3) - (3)].list)); }
    break;

  case 117:
#line 394 "gram.y"
    { ((yyval.list) = (yyvsp[(1) - (3)].list))->nv_next = (yyvsp[(3) - (3)].list); }
    break;

  case 118:
#line 395 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); }
    break;

  case 119:
#line 398 "gram.y"
    { (yyval.list) = new_si((yyvsp[(1) - (1)].str), NODEV); }
    break;

  case 120:
#line 399 "gram.y"
    { (yyval.list) = new_si(NULL, (yyvsp[(1) - (1)].val)); }
    break;

  case 121:
#line 402 "gram.y"
    { (yyval.val) = makedev((yyvsp[(2) - (4)].val), (yyvsp[(4) - (4)].val)); }
    break;

  case 124:
#line 408 "gram.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 125:
#line 409 "gram.y"
    { (yyval.val) = 1; }
    break;

  case 126:
#line 412 "gram.y"
    { (yyval.str) = starref((yyvsp[(1) - (2)].str)); }
    break;

  case 127:
#line 413 "gram.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 128:
#line 416 "gram.y"
    { (yyval.str) = NULL; }
    break;

  case 129:
#line 417 "gram.y"
    { (yyval.str) = wildref((yyvsp[(1) - (2)].str)); }
    break;

  case 130:
#line 418 "gram.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 131:
#line 421 "gram.y"
    { ((yyval.list) = (yyvsp[(2) - (2)].list))->nv_next = (yyvsp[(1) - (2)].list); }
    break;

  case 132:
#line 422 "gram.y"
    { (yyval.list) = NULL; }
    break;

  case 133:
#line 425 "gram.y"
    { (yyval.list) = new_ns((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str)); }
    break;

  case 134:
#line 426 "gram.y"
    { (yyval.list) = new_ns((yyvsp[(1) - (2)].str), NULL); }
    break;

  case 135:
#line 429 "gram.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); }
    break;

  case 136:
#line 430 "gram.y"
    { (yyval.val) = 0; }
    break;


/* Line 1267 of yacc.c.  */
#line 2236 "y.tab.c"
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


#line 432 "gram.y"


void
yyerror(const char *s)
{

	error("%s", s);
}

/*
 * Cleanup procedure after syntax error: release any nvlists
 * allocated during parsing the current line.
 */
static void
cleanup(void)
{
	struct nvlist **np;
	int i;

	for (np = alloc, i = adepth; --i >= 0; np++)
		nvfree(*np);
	adepth = 0;
}

static void
setmachine(const char *mch, const char *mcharch)
{
	char buf[MAXPATHLEN];

	machine = mch;
	machinearch = mcharch;

	(void)snprintf(buf, sizeof buf, "arch/%s/conf/files.%s", machine, machine);
	if (include(buf, ENDFILE) != 0)
		exit(1);

	if (machinearch != NULL)
		(void)snprintf(buf, sizeof buf, "arch/%s/conf/files.%s",
		    machinearch, machinearch);
	else
		strncpy(buf, _PATH_DEVNULL, sizeof buf);
	if (include(buf, ENDFILE) != 0)
		exit(1);

	if (include("conf/files", ENDFILE) != 0)
		exit(1);
}

static void
check_maxpart(void)
{
	if (maxpartitions <= 0) {
		stop("cannot proceed without maxpartitions specifier");
	}
}

