%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;
extern int yylineno;

%}
%union{
	  char *str_val;
	  char a_e[2];
    
}

%token INI_DEFVAR
%token FIN_DEFVAR
%token <str_val> ID
%token PUNTOCOMA
%token DOSPUNTOS
%token DEF_INT
%token DEF_FLOAT
%token <a_e> ASIG_ESP
%token CONST_REAL CONST_INT CONST_STR
%token IF ELSE WHILE         
%token P_A P_C C_A C_C L_A L_C PUNTO_Y_COMA COMA
%token CMP_MAY CMP_MEN CMP_MAYI CMP_MENI CMP_DIST CMP_IGUAL
%token OP_SUM OP_RES OP_DIV OP_MUL
%token AND OR NOT
%type <strval> expresion
%union{
	  char *strval;
    
}
%token DEFVAR ENDDEF
%token <strval> ID
%token OP_ASIG
%token INT FLOAT

%%

programa : program {printf("program - program\nCompilacion OK\n");}
program:
	sentencia 				{printf("program - sentencia\n");}
	| program sentencia 	{printf("program - program sentencia\n");}
	;
	
sentencia	: INI_DEFVAR declaraciones FIN_DEFVAR {printf("sentencia - INI_DEFVAR declaraciones FIN_DEFVAR\n");}
			| ID ASIG_ESP ID 	{printf("sentencia - ID ASIG_ESP ID\n");}
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

sentencias: 
    sentencias sentencia    {   printf("\nsentencias - sentencias sentencia");   
                                 }
    | sentencia             {   printf("\nsentencias - sentencia"); 
                                 }
    ;

sentencia:
    asignacion PUNTO_Y_COMA { printf("\nsentencia - asignacion");}
    | decision              {   printf("\nsentencia - decision");};   
   	

asignacion:
    ID OP_ASIG expresion { printf("\nasignacion ID - OP_ASIG - expresion");}
    | ID OP_ASIG constanteString { printf("\nasignacion ID - OP_ASIG - CTE_STRING");}
;

decision: 
    IF P_A condicion P_C L_A sentencias L_C {   printf("\ndecision - IF P_A condicion P_C L_A sentencias L_C");
 
                                                 }
   | IF P_A condicion P_C L_A sentencias L_C {  printf("\ndecision - IF P_A condicion P_C L_A sentencias L_C");
                                                
                                               
                                                 }
    ELSE                                    {   printf("\nInicio del else");
                                                   }
    L_A sentencias L_C                      {   printf("\nFin del else");
                                                
                                            
                                                }
 
   ;

condicion: 
    expresion CMP_MAY expresion     {   printf("\ncondicion - expresion CMP_MAY expresion");
                                        
                                         }
    | expresion CMP_MEN expresion   {   printf("\ncondicion - expresion CMP_MEN expresion");
                                        
                                          }
    | expresion CMP_MAYI expresion   {  printf("\ncondicion - expresion CMP_MAYI expresion");
                                        
                                          }
    | expresion CMP_MENI expresion  {   printf("\ncondicion - expresion CMP_MENI expresion");
                                        
                                         }
    | expresion CMP_DIST expresion  {   printf("\ncondicion - expresion CMP_DIST expresion");
                                        
                                        }
    | expresion CMP_IGUAL expresion {   printf("\ncondicion - expresion CMP_IGUAL expresion");
                                        
                                           }


    | P_A condicion P_C AND P_A condicion P_C   {   printf("\ncondicion - AND");

    }

    | P_A condicion P_C OR P_A condicion P_C    {   printf("\ncondicion - OR"); 
    }

    
    |NOT expresion CMP_MAY expresion     {   printf("\ncondicion - NOT expresion CMP_MAY expresion");
                                        
                                         }
    |NOT expresion CMP_MEN expresion   {   printf("\ncondicion - NOT expresion CMP_MEN expresion");
                                        
                                          }
    |NOT expresion CMP_MAYI expresion   {  printf("\ncondicion - NOT expresion CMP_MAYI expresion");
                                        
                                          }
    |NOT expresion CMP_MENI expresion  {   printf("\ncondicion - NOT expresion CMP_MENI expresion");
                                        
                                          }
    |NOT expresion CMP_DIST expresion  {   printf("\ncondicion - NOT expresion CMP_DIST expresion");
                                        
                                        }
    |NOT expresion CMP_IGUAL expresion {   printf("\ncondicion - NOT expresion CMP_IGUAL expresion");
                                        
                                        }
    ;


    
expresion:
    expresion OP_SUM termino        {   printf("\nexpresion - expresion OP_SUM termino"); 
                                        
                                         }
    | expresion OP_RES termino      {   printf("\nexpresion - expresion OP_RES termino");
                                         }
    | termino                       {   printf("\nexpresion - termino");   }
    ;

termino: 
    termino OP_MUL factor       {   printf("\ntermino - termino OP_MUL factor"); 
                                    
                                   
                                    }
    | termino OP_DIV factor     {   printf("\ntermino - termino OP_DIV factor"); 
                                    
                                   
                                   }
    | factor                    {   printf("\ntermino - factor");
                                       }
    ;

factor: 
    P_A expresion P_C           {   printf("\nfactor - P_A expresion P_C");
                                    }
    | ID                        {   printf("\nfactor - ID (insertando tipo)");
                                    
                                    }
    | constanteNumerica         {   printf("\nfactor - constanteNumerica");
                                     }                    
    ;

constanteNumerica: 
    CONST_INT               {   
                            printf("\nconstante - ENTERO: %s", yylval.strval);
                            
                            }
    | CONST_REAL            {   
                            printf("\nconstante - REAL: %s" , yylval.strval);
                                                       
                            };

constanteString: 
    CONST_STR        {  
                            printf("\nconstante - STRING %s" , yylval.strval);
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
       printf("Syntax Error at line: %d\n", yylineno);
	 system ("Pause");
	 exit (1);
     }
