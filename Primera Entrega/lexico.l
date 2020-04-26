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
OP_ASIG   				[":="]
ASIG_ESP				(\+=)|(\-=)|(\*=)|(\/=)
C_A                     ["["]
C_C                     ["]"]
ESPACIO					" "


%%
"DEFVAR"|"defvar"		{ return DEFVAR; }
"int"|"INT"				{ return INT; }
"float"|"FLOAT"			{ return FLOAT; }
"ENDDEF"|"enddef"		{ return ENDDEF; }
"display"|"DISPLAY"		{ printf("PALABRA RESERVADA: DISPLAY "); }
"while"|"WHILE"			{ return WHILE; }
"if"|"IF"				{ return IF; }
"else"|"ELSE"			{ return ELSE; }
"LET"|"let"				{ return LET_SIM;}
{CONST_INT}				{ 
							strcpy(yylval.strval, yytext);
							int casteado = atoi(yytext);
							if( casteado > 32767) {
								
								printf("ERROR Lexico - Entero \'%d\' fuera de rango. Debe estar entre [0; 32767]", casteado);
								
							}
							return CONST_INT;
						 }
{CONST_REAL}			{ 	
							strcpy(yylval.strval, yytext);
							double casteado = atof(yytext);
							if(casteado > FLT_MAX) {
								
								printf("ERROR Lexico - Float \'%f\' fuera de rango. Debe estar entre [0; %e]", casteado, FLT_MAX);
								
							}
							return CONST_REAL;
						}
{CONST_STR}				{	strcpy(yylval.strval, yytext);
							int longitud = strlen(yytext);
							//en lugar de 30 verifica con 32 porque el string viene entre comillas
							if(longitud > 32){
								char msg[150];
								printf("ERROR Lexico - Cadena \'%s\' demasiado larga. Maximo de 30 caracteres y contiene: %d", yytext, longitud-2);
								
							}
							return CONST_STR;	
						}
">"                     { return CMP_MAY;}
">="                    { return CMP_MAYI;}
"<"                     { return CMP_MEN;}
"<="                    { return CMP_MENI;}
"!="                    { return CMP_DIST;}
"=="                    { return CMP_IGUAL;}
":="					{ return OP_ASIG;}
"+"						{ return OP_SUM;}
"-"						{ return OP_RES;}
"*"						{ return OP_MUL;}
"/"						{ return OP_DIV;}
"("						{ return P_A;}
")"						{ return P_C;}
"["						{ printf("C_A ");}
"]"						{ printf("C_C ");}
"{"						{ return L_A;}
"}"						{ return L_C;}
";"						{ return PUNTO_Y_COMA;}
":"						{return DOSPUNTOS;}
","						{ return COMA;}
"="						{ return OP_IGUAL;}
"and"|"AND"				{ return AND;}
"or"|"OR"				{ return OR;}
"not"|"NOT"				{ return NOT;}
{COMENTARIOS} 			{ ;} 
{ID}					{ yylval.strval = strdup(yytext); return ID;}
{ASIG_ESP}				{ return ASIG_ESP;}
\n\r
\n
\t
{ESPACIO}
" "						/*estos ultimos 5 son para borrar los tabs, expacios, etc*/


%%