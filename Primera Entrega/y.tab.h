
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     ASIG_ESP = 258,
     DEFVAR = 259,
     ENDDEF = 260,
     INT = 261,
     FLOAT = 262,
     STRING = 263,
     CONST_REAL = 264,
     CONST_INT = 265,
     CONST_STR = 266,
     DISPLAY = 267,
     GET = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     P_A = 272,
     P_C = 273,
     C_A = 274,
     C_C = 275,
     L_A = 276,
     L_C = 277,
     PUNTO_Y_COMA = 278,
     COMA = 279,
     DOSPUNTOS = 280,
     CMP_MAY = 281,
     CMP_MEN = 282,
     CMP_MAYI = 283,
     CMP_MENI = 284,
     CMP_DIST = 285,
     CMP_IGUAL = 286,
     OP_SUM = 287,
     OP_RES = 288,
     OP_DIV = 289,
     OP_MUL = 290,
     AND = 291,
     OR = 292,
     NOT = 293,
     ID = 294,
     OP_ASIG = 295,
     LET_SIM = 296,
     OP_IGUAL = 297
   };
#endif
/* Tokens.  */
#define ASIG_ESP 258
#define DEFVAR 259
#define ENDDEF 260
#define INT 261
#define FLOAT 262
#define STRING 263
#define CONST_REAL 264
#define CONST_INT 265
#define CONST_STR 266
#define DISPLAY 267
#define GET 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define P_A 272
#define P_C 273
#define C_A 274
#define C_C 275
#define L_A 276
#define L_C 277
#define PUNTO_Y_COMA 278
#define COMA 279
#define DOSPUNTOS 280
#define CMP_MAY 281
#define CMP_MEN 282
#define CMP_MAYI 283
#define CMP_MENI 284
#define CMP_DIST 285
#define CMP_IGUAL 286
#define OP_SUM 287
#define OP_RES 288
#define OP_DIV 289
#define OP_MUL 290
#define AND 291
#define OR 292
#define NOT 293
#define ID 294
#define OP_ASIG 295
#define LET_SIM 296
#define OP_IGUAL 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "sintactico.y"

	  char *strval;
	  char a_e[2];
    



/* Line 1676 of yacc.c  */
#line 144 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


