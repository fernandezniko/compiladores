%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;

%}

%union{
	  char *str_val;
    
}

%token INI_DEFVAR
%token FIN_DEFVAR
%token <strval> STRI
%token PUNTOCOMA
%token DOSPUNTOS
%token DEF_INT
%token DEF_FLOAT

%%

programa	: 
	dec_variables
	;

dec_variables:	
	INI_DEFVAR {printf("defvar bison");} declaro_variables FIN_DEFVAR {printf("ENDEF bison");}
	;
	
declaro_variables: 
	STRI DOSPUNTOS DEF_INT PUNTOCOMA {
		printf("declarado INT con nombre %s", yylval.str_val);
	}
	|STRI DOSPUNTOS DEF_FLOAT PUNTOCOMA {
		printf("declarado FLOAT con nombre %s", yylval.str_val);
	}
	;

%%

int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
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
