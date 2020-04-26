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
%token <strval> ID
%token PUNTOCOMA
%token DOSPUNTOS
%token DEF_INT
%token DEF_FLOAT

%%

programa : program {printf("program - program\nCompilacion OK\n");}
program:
	sentencia 				{printf("program - sentencia\n");}
	| program sentencia 	{printf("program - program sentencia\n");}
	;
sentencia: INI_DEFVAR declaraciones FIN_DEFVAR {printf("sentencia - INI_DEFVAR declaraciones FIN_DEFVAR\n");}
	;
	
declaraciones:         	        	
             declaracion					{printf("declaraciones - declaracion\n");}
             | declaraciones declaracion	{printf("declaraciones - declaraciones declaracion\n");}
    	     ;

declaracion : DEF_INT DOSPUNTOS lista_ids 				{printf("declaracion - DEF_INT DOSPUNTOS lista_ids\n");}
	|DEF_FLOAT DOSPUNTOS lista_ids 						{printf("declaracion - DEF_FLOAT DOSPUNTOS lista_ids\n");
		/*printf("declarado FLOAT con nombre %s", yylval.str_val);*/
		/*printf("declarado INT con nombre ");*/
	}
	;
	
lista_ids 	:  	ID				{printf("lista_ids - ID '%s'\n",yylval.str_val);}
			| lista_ids PUNTOCOMA ID	{printf("lista_ids - lista_ids PUNTOCOMA ID\n");}
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
