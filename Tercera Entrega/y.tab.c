
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "pila-dinamica.h"
#include "ts.h"
#include "arbol.c"
#include "cola.c"
#include "assembler.h"

void verificarTipoDato(int tipo);
void reiniciarTipoDato();
int yystopparser=0;
FILE  *yyin;
extern int yylineno;
int cont_1 = 0;
int cont_2 = 0;
int tipoDatoActual = -1;

t_arbol arbol;
char str_aux[50];
char str_aux2[50];
int c = 1; //Contador para nodos auxiliares



/* Line 189 of yacc.c  */
#line 101 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 27 "sintactico.y"

	  char *strval;
	  //char a_e[2];
    float val;
    char  name[100];



/* Line 214 of yacc.c  */
#line 236 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 34 "sintactico.y"

pila_s pilaDeclares;
t_cola colaLet;


/* Line 264 of yacc.c  */
#line 254 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    16,    21,
      23,    26,    30,    34,    38,    40,    44,    46,    49,    51,
      53,    55,    57,    59,    60,    65,    66,    71,    75,    79,
      83,    91,    99,   100,   101,   115,   116,   121,   122,   127,
     128,   133,   134,   139,   140,   145,   146,   151,   152,   161,
     162,   168,   169,   175,   176,   182,   183,   189,   190,   196,
     197,   203,   207,   211,   213,   217,   221,   223,   227,   229,
     231,   233,   235,   237,   239,   240,   248,   252,   254,   258,
     260,   264,   268,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    50,    49,    -1,    49,    -1,
      55,    -1,    49,    55,    -1,    -1,     3,    51,    52,     4,
      -1,    53,    -1,    52,    53,    -1,     5,    24,    54,    -1,
       6,    24,    54,    -1,     7,    24,    54,    -1,    38,    -1,
      54,    22,    38,    -1,    89,    -1,    56,    22,    -1,    62,
      -1,    61,    -1,    85,    -1,    60,    -1,    59,    -1,    -1,
      38,    39,    57,    79,    -1,    -1,    38,    39,    58,    83,
      -1,    11,    38,    22,    -1,    11,    84,    22,    -1,    12,
      38,    22,    -1,    15,    16,    65,    17,    20,    55,    21,
      -1,    13,    16,    65,    17,    20,    55,    21,    -1,    -1,
      -1,    13,    16,    65,    17,    20,    55,    21,    63,    14,
      64,    20,    55,    21,    -1,    -1,    79,    66,    25,    79,
      -1,    -1,    79,    67,    26,    79,    -1,    -1,    79,    68,
      27,    79,    -1,    -1,    79,    69,    28,    79,    -1,    -1,
      79,    70,    29,    79,    -1,    -1,    79,    71,    30,    79,
      -1,    -1,    16,    65,    72,    17,    35,    16,    65,    17,
      -1,    -1,    37,    79,    73,    25,    79,    -1,    -1,    37,
      79,    74,    26,    79,    -1,    -1,    37,    79,    75,    27,
      79,    -1,    -1,    37,    79,    76,    28,    79,    -1,    -1,
      37,    79,    77,    29,    79,    -1,    -1,    37,    79,    78,
      30,    79,    -1,    79,    31,    80,    -1,    79,    32,    80,
      -1,    80,    -1,    80,    34,    81,    -1,    80,    33,    81,
      -1,    81,    -1,    16,    79,    17,    -1,    38,    -1,    82,
      -1,     9,    -1,     8,    -1,    10,    -1,    10,    -1,    -1,
      40,    86,    87,    41,    16,    88,    17,    -1,    87,    23,
      38,    -1,    38,    -1,    88,    22,    79,    -1,    79,    -1,
      38,    42,    38,    -1,    38,    43,    38,    -1,    38,    44,
      38,    -1,    38,    45,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    92,    93,    97,   102,   109,   109,   113,
     114,   117,   126,   134,   144,   145,   149,   153,   157,   161,
     164,   168,   170,   178,   178,   199,   199,   224,   230,   238,
     247,   253,   257,   259,   257,   273,   273,   277,   277,   281,
     281,   285,   285,   289,   289,   293,   293,   300,   300,   306,
     306,   314,   314,   319,   319,   324,   324,   329,   329,   334,
     334,   343,   347,   351,   357,   361,   365,   373,   375,   388,
     397,   404,   412,   420,   426,   426,   440,   444,   450,   454,
     460,   470,   480,   492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFVAR", "ENDDEF", "INT", "FLOAT",
  "STRING", "CONST_REAL", "CONST_INT", "CONST_STR", "DISPLAY", "GET", "IF",
  "ELSE", "WHILE", "P_A", "P_C", "C_A", "C_C", "L_A", "L_C",
  "PUNTO_Y_COMA", "COMA", "DOSPUNTOS", "CMP_MAY", "CMP_MEN", "CMP_MAYI",
  "CMP_MENI", "CMP_DIST", "CMP_IGUAL", "OP_SUM", "OP_RES", "OP_DIV",
  "OP_MUL", "AND", "OR", "NOT", "ID", "OP_ASIG", "LET_SIM", "OP_IGUAL",
  "AE_MAIG", "AE_MEIG", "AE_MUIG", "AE_DIIG", "$accept", "programa",
  "program", "sentencias", "bloq_declaracion", "$@1", "declaraciones",
  "declaracion", "lista_ids", "sentencia", "asignacion", "$@2", "$@3",
  "salida", "entrada", "iteracion", "decision", "$@4", "$@5", "condicion",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "expresion", "termino", "factor",
  "constanteNumerica", "constanteString", "constanteStringShow", "let",
  "$@19", "cont_ids", "cont_exp", "asignacion_especial", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    51,    50,    52,
      52,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    57,    56,    58,    56,    59,    59,    60,
      61,    62,    63,    64,    62,    66,    65,    67,    65,    68,
      65,    69,    65,    70,    65,    71,    65,    72,    65,    73,
      65,    74,    65,    75,    65,    76,    65,    77,    65,    78,
      65,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      82,    82,    83,    84,    86,    85,    87,    87,    88,    88,
      89,    89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     4,     1,
       2,     3,     3,     3,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     3,     3,     3,
       7,     7,     0,     0,    13,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     8,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     0,     7,     3,     1,     3,     1,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     0,     0,    74,     0,     2,
       4,     0,     5,     0,    22,    21,    19,    18,    20,    16,
       0,    73,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     1,     6,     3,    17,     0,     0,     0,
       0,     9,    27,    28,    29,    71,    70,     0,     0,    68,
       0,    35,    63,    66,    69,     0,     0,     0,    80,    81,
      82,    83,    77,     0,     0,     0,     0,     8,    10,    47,
      35,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    72,    26,     0,     0,
      14,    11,    12,    13,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,    65,    64,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    38,    40,    42,
      44,    46,     0,    79,     0,    15,     0,    50,    52,    54,
      56,    58,    60,    31,    30,    75,     0,     0,     0,    78,
       0,    33,    48,     0,     0,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    20,    40,    41,    91,    12,
      13,    56,    57,    14,    15,    16,    17,   148,   153,    50,
      76,    77,    78,    79,    80,    81,    94,    97,    98,    99,
     100,   101,   102,    51,    52,    53,    54,    87,    23,    18,
      32,    63,   134,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int16 yypact[] =
{
       1,   -46,    -5,   -15,     5,    22,     8,   -46,    34,   -46,
      17,    17,   -46,    26,   -46,   -46,   -46,   -46,   -46,   -46,
      37,   -46,    32,    38,    51,    -1,    -1,    46,    42,    50,
      64,    65,    74,   -46,   -46,    17,   -46,    89,    90,    91,
      63,   -46,   -46,   -46,   -46,   -46,   -46,    -1,    11,   -46,
      99,    68,   -24,   -46,   -46,   100,    11,   108,   -46,   -46,
     -46,   -46,   -46,   -17,    81,    81,    81,   -46,   -46,   -46,
      55,    11,    79,   101,    11,    11,    95,    97,    98,    96,
     102,   103,    11,    11,   106,   -14,   -46,   -46,    92,   111,
     -46,   107,   107,   107,   115,   -46,    14,   109,   110,   112,
     113,   114,   105,    17,   -24,   -24,    11,    11,    11,    11,
      11,    11,   -46,   -46,    17,   -46,    11,   104,    93,    11,
      11,    11,    11,    11,    11,   116,   -14,   -14,   -14,   -14,
     -14,   -14,   117,   -14,    18,   -46,   124,   -14,   -14,   -14,
     -14,   -14,   -14,   131,   -46,   -46,    11,    -1,   132,   -14,
     130,   -46,   -46,   128,    17,   129,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,   138,   -46,   -46,   -46,   118,    -7,   -10,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -25,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -45,    15,     9,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      34,    55,    70,    72,     1,    21,    88,    45,    46,    82,
      83,    85,     2,     3,     4,    47,     5,    74,    75,    45,
      46,    25,    69,    24,    89,    34,    96,    71,     2,     3,
       4,    95,     5,    22,    33,   145,    48,    49,    26,     6,
     146,     7,    37,    38,    39,    74,    75,    27,    36,    49,
      28,    29,    30,    31,    42,     6,   -25,     7,    92,    93,
      43,   126,   127,   128,   129,   130,   131,    67,    37,    38,
      39,   133,    95,    44,   137,   138,   139,   140,   141,   142,
      58,   -37,   -39,   -41,   -43,   -45,    74,    75,    59,   104,
     105,   112,   113,   125,   -37,   -39,   -41,   -43,   -45,    74,
      75,   149,    60,    61,   132,   -51,   -53,   -55,   -57,   -59,
      74,    75,    62,    64,    65,    66,    73,    84,    86,    90,
     106,   103,   150,   107,   109,   108,   114,   116,   136,   117,
     115,   110,   118,   111,   119,   124,   120,   143,   144,   121,
     147,   122,   135,   123,   155,   -32,   151,   152,   154,    35,
     156,     0,     0,     0,     0,     0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
      10,    26,    47,    48,     3,    10,    23,     8,     9,    33,
      34,    56,    11,    12,    13,    16,    15,    31,    32,     8,
       9,    16,    47,    38,    41,    35,    71,    16,    11,    12,
      13,    17,    15,    38,     0,    17,    37,    38,    16,    38,
      22,    40,     5,     6,     7,    31,    32,    39,    22,    38,
      42,    43,    44,    45,    22,    38,    10,    40,    65,    66,
      22,   106,   107,   108,   109,   110,   111,     4,     5,     6,
       7,   116,    17,    22,   119,   120,   121,   122,   123,   124,
      38,    26,    27,    28,    29,    30,    31,    32,    38,    74,
      75,    82,    83,   103,    26,    27,    28,    29,    30,    31,
      32,   146,    38,    38,   114,    26,    27,    28,    29,    30,
      31,    32,    38,    24,    24,    24,    17,    17,    10,    38,
      25,    20,   147,    26,    28,    27,    20,    16,    35,    22,
      38,    29,    17,    30,    25,    30,    26,    21,    21,    27,
      16,    28,    38,    29,   154,    14,    14,    17,    20,    11,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    11,    12,    13,    15,    38,    40,    47,    48,
      49,    50,    55,    56,    59,    60,    61,    62,    85,    89,
      51,    10,    38,    84,    38,    16,    16,    39,    42,    43,
      44,    45,    86,     0,    55,    49,    22,     5,     6,     7,
      52,    53,    22,    22,    22,     8,     9,    16,    37,    38,
      65,    79,    80,    81,    82,    65,    57,    58,    38,    38,
      38,    38,    38,    87,    24,    24,    24,     4,    53,    65,
      79,    16,    79,    17,    31,    32,    66,    67,    68,    69,
      70,    71,    33,    34,    17,    79,    10,    83,    23,    41,
      38,    54,    54,    54,    72,    17,    79,    73,    74,    75,
      76,    77,    78,    20,    80,    80,    25,    26,    27,    28,
      29,    30,    81,    81,    20,    38,    16,    22,    17,    25,
      26,    27,    28,    29,    30,    55,    79,    79,    79,    79,
      79,    79,    55,    79,    88,    38,    35,    79,    79,    79,
      79,    79,    79,    21,    21,    17,    22,    16,    63,    79,
      65,    14,    17,    64,    20,    55,    21
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 88 "sintactico.y"
    {
    arbol=*ProgPtr;
    printf("\nprogram - program\nCompilacion OK\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 97 "sintactico.y"
    {
                                   sprintf(str_aux,"_Cuerpo_%d",c++);
                                    ProgPtr=crearNodo(str_aux,*SentPtr,NULL);
                                    printf("\nprograma: sentencia");
                    }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 102 "sintactico.y"
    {
                                    sprintf(str_aux,"_Cuerpo_%d",c++);
                                    ProgPtr=crearNodo(str_aux, *ProgPtr,*SentPtr);
                                    printf("\nprograma: sentencias sentencia");
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "sintactico.y"
    {crearPilaS(&pilaDeclares); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 109 "sintactico.y"
    {printf("\nbloq_declaracion - DEFVAR declaraciones ENDDEF");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 113 "sintactico.y"
    { printf("\ndeclaraciones - declaracion");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 114 "sintactico.y"
    {printf("\ndeclaraciones - declaraciones declaracion");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 117 "sintactico.y"
    {

                                        while(!pilaVaciaS(&pilaDeclares)){
                                            char *id = sacarDePilaS(&pilaDeclares);
                                            char *type = "INT";
                                            modifyTypeTs(id, type);
                                        }
                                        printf("\ndeclaracion - INT DOSPUNTOS lista_ids");
                                    }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 126 "sintactico.y"
    {
                                            while(!pilaVaciaS(&pilaDeclares)){
                                                char *id = sacarDePilaS(&pilaDeclares);
                                                char *type = "FLOAT";
                                                modifyTypeTs(id, type);
                                            }
                                            printf("\ndeclaracion - FLOAT DOSPUNTOS lista_ids");
                                        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 134 "sintactico.y"
    {
                                             while(!pilaVaciaS(&pilaDeclares)){
                                                char *id = sacarDePilaS(&pilaDeclares);
                                                char *type = "STRING";

                                                modifyTypeTs(id, type);
                                            }
                                            printf("\ndeclaracion - STRING DOSPUNTOS lista_ids");
            }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 144 "sintactico.y"
    { ponerEnPilaS(&pilaDeclares, (yyvsp[(1) - (1)].strval)); printf("\nlista_ids - ID '%s'",yylval.strval);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 145 "sintactico.y"
    {ponerEnPilaS(&pilaDeclares, (yyvsp[(3) - (3)].strval)), printf("\nlista_ids - lista_ids PUNTO_Y_COMA ID '%s'",yylval.strval);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 149 "sintactico.y"
    {	
									SentPtr = AEPtr;
									printf("\nsentencia - asignacion_especial");
								}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 153 "sintactico.y"
    {
                                        SentPtr = Aptr ;
                                        printf("\nsentencia - asignacion");
                                        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 157 "sintactico.y"
    {
                                        SentPtr = Decptr ;
                                        printf("\nsentencia - decision");
                                    }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 161 "sintactico.y"
    {
                                        SentPtr = IteraPtr;
                                        printf("\nsentencia - iteracion");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 164 "sintactico.y"
    {
										SentPtr = LetPtr;
										printf("\nsentencia - let");
									}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 168 "sintactico.y"
    {   SentPtr = getPtr ;
                                        printf("\nsentencia - entrada");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 170 "sintactico.y"
    {  SentPtr = displayPtr;
							 			printf("\nsentencia - salida");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 178 "sintactico.y"
    {
                    if(getType((yyvsp[(1) - (2)].strval)) == 0)
                    {
                            yyerror("La variable no fue declarada");
                            exit(2);
                    }

                    reiniciarTipoDato();
                }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 188 "sintactico.y"
    {                             
                           if(getType((yyvsp[(1) - (4)].strval)) != tipoDatoActual){
                            yyerror("No se pueden asignar variables de distintos tipos");
                            exit(0);
                           }
                          sprintf(str_aux, "%s",(yyvsp[(1) - (4)].strval));
                          Auxptr=crearHoja(str_aux);
                          Aptr = crearNodo(":=",*Auxptr,*Eptr) ;
                          printf("\nasignacion ID - OP_ASIG - expresion");
                          }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 199 "sintactico.y"
    {
                    if(getType((yyvsp[(1) - (2)].strval)) == 0)
                    {
                            yyerror("La variable no fue declarada");
                            exit(2);
                    }

                    reiniciarTipoDato();
                }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 209 "sintactico.y"
    {
                            
                            if(getType((yyvsp[(1) - (4)].strval)) != tipoDatoActual){
                            yyerror("No se pueden asignar variables de distintos tipos");
                            exit(0);
                            }
                            sprintf(str_aux, "%s",(yyvsp[(1) - (4)].strval));
                            Auxptr=crearHoja(str_aux);
                            Aptr = crearNodo(":=",*Auxptr,*cteStringptr) ;
                            printf("\nasignacion ID - OP_ASIG - CTE_STRING");
                            }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 224 "sintactico.y"
    { 			sprintf(str_aux, "%s",(yyvsp[(2) - (3)].strval));
												hojaIOPtr = crearHoja(str_aux);
												displayPtr = crearNodo("DISPLAY",*hojaIOPtr,NULL);
                                                printf("\nentrada DISPLAY - CONST_STR");
                                                }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 230 "sintactico.y"
    {
												displayPtr = crearNodo("DISPLAY",*cteStringptr,NULL) ;
												printf("\nentrada DISPLAY - CONST_STR");
												}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 238 "sintactico.y"
    { 
                          sprintf(str_aux, "%s",(yyvsp[(2) - (3)].strval));
                          AuxGetPtr = crearHoja(str_aux);
                          getPtr = crearNodo("GET", *AuxGetPtr, NULL); 
                          printf("\nsalida GET - ID"); 
    }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 247 "sintactico.y"
    {
                                                IteraPtr = crearNodo("WHILE", *CondPtr, *SentPtr);
                                                printf("\niteracion - WHILE P_A condicion P_C L_A sentencia L_C");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 253 "sintactico.y"
    {
                                                printf("\ndecision - IF P_A condicion P_C L_A sentencia L_C");
                                                Decptr = crearNodo("IF",*CondPtr,*SentPtr);
                                                 }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 257 "sintactico.y"
    {  printf("\ndecision - IF P_A condicion P_C L_A sentencia L_C");
                                                 }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 259 "sintactico.y"
    {
                                                SentVPtr = SentPtr;
                                                printf("\nInicio del else");
                                                   }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 263 "sintactico.y"
    {   printf("\nFin del else");
                                                sprintf(str_aux,"_Cuerpo_%d",c++);

                                                Decptr = crearNodo("IF",*CondPtr,*crearNodo(str_aux,*SentVPtr,*SentPtr));

                                                }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 273 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 273 "sintactico.y"
    {
                                        CondPtr = crearNodo(">",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MAY expresion");
                                         }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 277 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 277 "sintactico.y"
    {
                                        CondPtr = crearNodo("<",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MEN expresion");
                                          }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 281 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 281 "sintactico.y"
    {
                                        CondPtr = crearNodo(">=",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MAYI expresion");
                                          }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 285 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 285 "sintactico.y"
    {
                                        CondPtr = crearNodo("<=",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MENI expresion");
                                         }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 289 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 289 "sintactico.y"
    {
                                        CondPtr = crearNodo("!=",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_DIST expresion");
                                        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 293 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 293 "sintactico.y"
    {
                                        CondPtr = crearNodo("==",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_IGUAL expresion");

                                           }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 300 "sintactico.y"
    {CondIzqPtr = CondPtr;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 300 "sintactico.y"
    {
                                        CondPtr = crearNodo("AND", *CondIzqPtr, *CondPtr);
                                        printf("\ncondicion - AND");

                                        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 306 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 306 "sintactico.y"
    {

                                        CondPtr = crearNodo("<=",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MAY expresion");



                                         }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 314 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 314 "sintactico.y"
    {
                                        CondPtr = crearNodo(">=",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MEN expresion");

                                          }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 319 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 319 "sintactico.y"
    {
                                        CondPtr = crearNodo("<",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MAYI expresion");

                                          }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 324 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 324 "sintactico.y"
    {
                                        CondPtr = crearNodo(">",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MENI expresion");

                                          }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 329 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 329 "sintactico.y"
    {
                                        CondPtr = crearNodo("==",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_DIST expresion");

                                        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 334 "sintactico.y"
    {E1ptr = Eptr;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 334 "sintactico.y"
    {
                                         CondPtr = crearNodo("!=",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_IGUAL expresion");

                                        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 343 "sintactico.y"
    {
                                        Eptr = crearNodo("+", *Eptr, *Tptr);
                                        printf("\nexpresion - expresion OP_SUM termino");
                                         }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 347 "sintactico.y"
    {
                                        Eptr = crearNodo("-", *Eptr, *Tptr);
                                        printf("\nexpresion - expresion OP_RES termino");
                                         }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 351 "sintactico.y"
    {
                                        Eptr = Tptr;
                                        printf("\nexpresion - termino");   }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 357 "sintactico.y"
    {
                                    Tptr = crearNodo("*", *Tptr, *Fptr);
                                    printf("\ntermino - termino OP_MUL factor");
                                    }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 361 "sintactico.y"
    {
                                    Tptr = crearNodo("/", *Tptr, *Fptr);
                                    printf("\ntermino - termino OP_DIV factor");
                                   }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 365 "sintactico.y"
    {
                                    Tptr = Fptr;
                                    printf("\ntermino - factor");

                                       }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 373 "sintactico.y"
    {   printf("\nfactor - P_A expresion P_C");
                                    }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 375 "sintactico.y"
    {
                                    if(getType((yyvsp[(1) - (1)].strval)) == 0)
                                    {
                                        yyerror("La variable no fue declarada");
                                        exit(0);
                                    }
                                    verificarTipoDato(getType((yyvsp[(1) - (1)].strval)));
                                    sprintf(str_aux, "%s", yylval.strval);
                                    Fptr = crearHoja(str_aux);
                                    printf("\nfactor - ID", *str_aux);
                                    

                                    }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 388 "sintactico.y"
    {
                                    Fptr = constNumPtr;
                                    printf("\nfactor - constanteNumerica");

                                     }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 397 "sintactico.y"
    {
                                sprintf(str_aux, "%s", yylval.strval);
                                constNumPtr = crearHoja(str_aux);
                                printf("\nconstante - ENTERO: %s", yylval.strval);
                                verificarTipoDato(1);
                            }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 404 "sintactico.y"
    {
                                sprintf(str_aux, "%s", yylval.strval);
                                constNumPtr = crearHoja(str_aux);
                                printf("\nconstante - REAL: %s" , yylval.strval);
                                verificarTipoDato(2);

                            }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 412 "sintactico.y"
    {      sprintf(str_aux, "%s", yylval.strval);
                            cteStringptr = crearHoja(str_aux);
                            printf("\nconstante - STRING %s" , yylval.strval);
                            verificarTipoDato(3);
                        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 420 "sintactico.y"
    {      sprintf(str_aux, "%s", yylval.strval);
                            cteStringptr = crearHoja(str_aux);
                            printf("\nconstanteShow - STRING %s" , yylval.strval);
                        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 426 "sintactico.y"
    {crearCola(&colaLet);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 426 "sintactico.y"
    {
				if(cont_1==cont_2){
					printf("\nsentencia - LET_SIM cont_ids OP_IGUAL P_A cont_exp P_C");
					/*printf("\nvalores cont_1: %d cont_2: %d",cont_1,cont_2);*/
					cont_1 = 0;
					cont_2 = 0;
				}else{
					yyerror();
				}

				LetPtr = Let_cont_id;
			}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 440 "sintactico.y"
    {
								ponerEnCola(&colaLet, (yyvsp[(3) - (3)].strval));
								cont_1++;printf("\ncont_ids - cont_ids COMA ID");
							}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 444 "sintactico.y"
    {
								ponerEnCola(&colaLet, (yyvsp[(1) - (1)].strval));
								cont_1++; printf("\ncont_ids - ID");
							}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 450 "sintactico.y"
    {
								Let_cont_id = crearNodo(";",*Let_cont_id,*crearNodo("=",*crearHoja(sacarDeCola(&colaLet)),*Eptr));
								cont_2++;printf("\ncont_exp - cont_exp PUNTO_Y_COMA expresion");
								}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 454 "sintactico.y"
    {
								Let_cont_id = crearNodo("=",*crearHoja(sacarDeCola(&colaLet)),*Eptr);
								cont_2++;printf("\ncont_exp - expresion");
								}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 460 "sintactico.y"
    {	
										sprintf(str_aux, "%s",(yyvsp[(1) - (3)].strval));
										sprintf(str_aux2, "%s",(yyvsp[(3) - (3)].strval));
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("+",*Auxptr2,*Auxptr3));
										printf("\nasignacion_especial - ID MAIG ID");
									}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 470 "sintactico.y"
    {
										sprintf(str_aux, "%s",(yyvsp[(1) - (3)].strval));
										sprintf(str_aux2, "%s",(yyvsp[(3) - (3)].strval));
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("-",*Auxptr2,*Auxptr3));
										printf("\nasignacion_especial - ID MAIG ID");
									}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 480 "sintactico.y"
    {
										sprintf(str_aux, "%s",(yyvsp[(1) - (3)].strval));
										sprintf(str_aux2, "%s",(yyvsp[(3) - (3)].strval));
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("*",*Auxptr2,*Auxptr3));
										
										
										printf("\nasignacion_especial - ID MAIG ID");
									}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 492 "sintactico.y"
    {
										sprintf(str_aux, "%s",(yyvsp[(1) - (3)].strval));
										sprintf(str_aux2, "%s",(yyvsp[(3) - (3)].strval));
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("/",*Auxptr2,*Auxptr3));
										printf("\nasignacion_especial - ID MAIG ID");
									}
    break;



/* Line 1455 of yacc.c  */
#line 2428 "y.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 504 "sintactico.y"


int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
    crear_arbol(&arbol);
	yyparse();
  }

  fclose(yyin);
  printf("\n\n Recorrido inorder: \n");

  if ((pf = fopen("intermedia.txt", "w+")) == NULL)
	{
		printf("\nNo se puede abrir el archivo intermedia.txt\n");
	}
	else
	{
		enOrden(&arbol); //recorre en orden y lo graba en el archivo intermedia.txt
        //printf("EN POST-ORDEN\n\n");
        //postOrden(&arbol);
        generarAssembler(&arbol);
	}
  return 0;
}

int yyerror(char *errMessage)
{
   printf("\n(!)ERROR en la linea %d: \n%s\n",yylineno,errMessage);
   fprintf(stderr, "Fin de ejecucion.\n");
   system ("Pause");
   exit (1);
}

void verificarTipoDato(int tipo) {

	if(tipoDatoActual == -1) {
		tipoDatoActual = tipo;
	}
	
	if(tipoDatoActual != tipo) {
		yyerror("No se admiten operaciones aritmeticas con tipo de datos distintos");
		
        exit(0);
	}
	
}

void reiniciarTipoDato() {
	tipoDatoActual = -1;
}
