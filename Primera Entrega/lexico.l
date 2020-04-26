%{

#include <string.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
FILE  *yyin;


%}

%option noyywrap 
%option yylineno
DIGITO					[0-9]
LETRA					[a-zA-Z]
COMA                    [","]
CONST_STR               \"({LETRA}|{DIGITO}|.)+\"
COMENTARIOS             (\*\*\*\/).*(\/\*\*\*)
CONST_REAL              {DIGITO}+"."{DIGITO}+
CONST_INT               {DIGITO}+
ID						{LETRA}({LETRA}|{DIGITO})*
ASIG_ESP				["+="|"-="|"*="|"/="]
OP_COMPARACION          ["<"|"=="|">"|"<="|">="|"!="]
OP_SURES                ["+"|"-"]
OP_MULTDIV              ["*"|"/"]
OP_AS   				[":"]
OP_LOG 					["and"|"or"|"not"]
C_A                     ["["]
C_C                     ["]"]
P_A                     ["("]
P_C                     [")"]
PyC						[";"]
L_A						["{"]
L_C						["}"]
ESPACIO					" "


%%
"DEFVAR"|"defvar"		{ /*printf("defvar detectado flex\n");*/ return INI_DEFVAR; }
"int"|"INT"				{return DEF_INT; }
"float"|"FLOAT"			{ /*printf("FLOAT detectado flex\n");*/ return DEF_FLOAT; }
"ENDDEF"|"enddef"		{ return FIN_DEFVAR; }
"display"|"DISPLAY"		{ printf("PALABRA RESERVADA: DISPLAY "); }
"while"|"WHILE"			{ printf("PALABRA RESERVADA: WHILE "); }
"if"|"IF"				{ printf("PALABRA RESERVADA: IF "); }
"else"|"ELSE"			{ printf("PALABRA RESERVADA: ELSE "); }
{CONST_INT}				{ 
							
							int casteado = atoi(yytext);
							if( casteado > 32767) {
								
								printf("ERROR Lexico - Entero \'%d\' fuera de rango. Debe estar entre [0; 32767]", casteado);
								
							}
							
						 }
{CONST_REAL}			{ 	
							double casteado = atof(yytext);
							if(casteado > FLT_MAX) {
								
								printf("ERROR Lexico - Float \'%f\' fuera de rango. Debe estar entre [0; %e]", casteado, FLT_MAX);
								
							}
						}
{CONST_STR}				{
							int longitud = strlen(yytext);
							//en lugar de 30 verifica con 32 porque el string viene entre comillas
							if(longitud > 32){
								char msg[150];
								printf("ERROR Lexico - Cadena \'%s\' demasiado larga. Maximo de 30 caracteres y contiene: %d", yytext, longitud-2);
								
							}
								
						}
">"                     { printf("OP > ");}
">="                    { printf("OP >= ");}
"<"                     { printf("OP < " );}
"<="                    { printf("OP <= ");}
"!="                    { printf("OP != ");}
"=="                    { printf("OP == ");}
":"						{ return DOSPUNTOS;}
"+"						{ ;}
"-"						{ ;}
"*"						{ ;}
"/"						{ ;}
"("						{ printf("P_A ");}
")"						{ printf("P_C ");}
"["						{ printf("C_A ");}
"]"						{ printf("C_C ");}
"{"						{ printf("LL_A ");}
"}"						{ printf("LL_C ");}
";"						{ return PUNTOCOMA;}
","						{ ;}
"and"|"AND"				{ printf("OP AND");}
"or"|"OR"				{ printf("OP OR");}
"not"|"NOT"				{ printf("OP NOT");}
{COMENTARIOS} 			{ ;} 
{ID}					{ yylval.str_val = strdup(yytext); return ID;}
{ASIG_ESP}				{ return ASIG_ESP;}

\n
\r
\n
\t
" "						/*estos ultimos 5 son para borrar los tabs, expacios, etc*/


%%