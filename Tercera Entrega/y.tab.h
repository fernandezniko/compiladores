
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
     DEFVAR = 258,
     ENDDEF = 259,
     INT = 260,
     FLOAT = 261,
     STRING = 262,
     CONST_REAL = 263,
     CONST_INT = 264,
     CONST_STR = 265,
     DISPLAY = 266,
     GET = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     P_A = 271,
     P_C = 272,
     C_A = 273,
     C_C = 274,
     L_A = 275,
     L_C = 276,
     PUNTO_Y_COMA = 277,
     COMA = 278,
     DOSPUNTOS = 279,
     CMP_MAY = 280,
     CMP_MEN = 281,
     CMP_MAYI = 282,
     CMP_MENI = 283,
     CMP_DIST = 284,
     CMP_IGUAL = 285,
     OP_SUM = 286,
     OP_RES = 287,
     OP_DIV = 288,
     OP_MUL = 289,
     AND = 290,
     OR = 291,
     NOT = 292,
     ID = 293,
     OP_ASIG = 294,
     LET_SIM = 295,
     OP_IGUAL = 296,
     AE_MAIG = 297,
     AE_MEIG = 298,
     AE_MUIG = 299,
     AE_DIIG = 300
   };
#endif
/* Tokens.  */
#define DEFVAR 258
#define ENDDEF 259
#define INT 260
#define FLOAT 261
#define STRING 262
#define CONST_REAL 263
#define CONST_INT 264
#define CONST_STR 265
#define DISPLAY 266
#define GET 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define P_A 271
#define P_C 272
#define C_A 273
#define C_C 274
#define L_A 275
#define L_C 276
#define PUNTO_Y_COMA 277
#define COMA 278
#define DOSPUNTOS 279
#define CMP_MAY 280
#define CMP_MEN 281
#define CMP_MAYI 282
#define CMP_MENI 283
#define CMP_DIST 284
#define CMP_IGUAL 285
#define OP_SUM 286
#define OP_RES 287
#define OP_DIV 288
#define OP_MUL 289
#define AND 290
#define OR 291
#define NOT 292
#define ID 293
#define OP_ASIG 294
#define LET_SIM 295
#define OP_IGUAL 296
#define AE_MAIG 297
#define AE_MEIG 298
#define AE_MUIG 299
#define AE_DIIG 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 27 "sintactico.y"

	  char *strval;
	  //char a_e[2];
    float val;
    char  name[100];



/* Line 1676 of yacc.c  */
#line 151 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


