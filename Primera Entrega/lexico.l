%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <float.h>

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
"DEFVAR"|"defvar"		{ printf("PALABRA RESERVADA: DEFVAR "); }
"Integer"|"INTEGER"		{ printf("PALABRA RESERVADA: INTEGER "); }
"Float"|"FLOAT"			{ printf("PALABRA RESERVADA: FLOAT "); }
"ENDDEF"|"enddef"		{ printf("PALABRA RESERVADA: ENDDEF "); }
"display"|"DISPLAY"		{ printf("PALABRA RESERVADA: WRITE "); }
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
":"						{ printf("DOS PUNTOS ");}
"+"						{ printf("MAS ");}
"-"						{ printf("MENOS ");}
"*"						{ printf("POR ");}
"/"						{ printf("DIV ");}
"("						{ printf("P_A ");}
")"						{ printf("P_C ");}
"["						{ printf("C_A ");}
"]"						{ printf("C_C ");}
"{"						{ printf("LL_A ");}
"}"						{ printf("LL_C ");}
";"						{ printf("PUNTOYCOMA ");}
","						{ printf("COMA ");}
"and"|"AND"				{ printf("OP AND");}
"or"|"OR"				{ printf("OP OR");}
"not"|"NOT"				{ printf("OP NOT");}
{COMENTARIOS} 			{ printf("COMENTARIO");} 
{ID}					{ printf("ID ");}

%%
int main(int argc, char *argv[]){

if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yylex();
  }
  fclose(yyin);
  return 0;
	
}

int yyerror(void)
     {
       printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
     }