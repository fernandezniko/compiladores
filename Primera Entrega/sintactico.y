%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;
extern int yylineno;
int cont_1 = 0;
int cont_2 = 0;

%}
%union{
	  char *strval;
	  char a_e[2];
    
}
/*%token INI_DEFVAR
%token FIN_DEFVAR
%token <str_val> ID
%token PUNTOCOMA
%token DOSPUNTOS
%token DEF_INT
%token DEF_FLOAT
*/
%token <a_e> ASIG_ESP
%token DEFVAR ENDDEF 
%token INT FLOAT STRING
%token CONST_REAL CONST_INT CONST_STR
%token DISPLAY GET
%token IF ELSE WHILE         
%token P_A P_C C_A C_C L_A L_C PUNTO_Y_COMA COMA DOSPUNTOS
%token CMP_MAY CMP_MEN CMP_MAYI CMP_MENI CMP_DIST CMP_IGUAL
%token OP_SUM OP_RES OP_DIV OP_MUL
%token AND OR NOT
%type <strval> expresion
%token <strval> ID
%token OP_ASIG
%token LET_SIM
%token OP_IGUAL


%%

programa: program {printf("\nprogram - program\nCompilacion OK\n");};
program:
	sentencia 				{printf("\nprogram - sentencia");}
	| program sentencia 	{printf("\nprogram - program sentencia");}
	;
	
sentencia: DEFVAR declaraciones ENDDEF {printf("\nsentencia - DEFVAR declaraciones ENDDEF");}
			| ID ASIG_ESP ID 	{printf("\nsentencia - ID ASIG_ESP ID");}
            | asignacion PUNTO_Y_COMA { printf("\nsentencia - asignacion");}
            | decision              {   printf("\nsentencia - decision");}
            | iteracion             { printf("\nsentencia - iteracion");}
			| let					{ printf("\nsentencia - let");}
            | entrada               {printf("\nsentencia - entrada");}
            | salida                {printf("\nsentencia - salida");}
	        ;
	
declaraciones:         	        	
             declaracion					{printf("\ndeclaraciones - declaracion");}
             | declaraciones declaracion	{printf("\ndeclaraciones - declaraciones declaracion");}
    	     ;

declaracion: INT DOSPUNTOS lista_ids 				{printf("\ndeclaracion - INT DOSPUNTOS lista_ids");}
	|FLOAT DOSPUNTOS lista_ids 						{printf("\ndeclaracion - FLOAT DOSPUNTOS lista_ids");}
	|STRING DOSPUNTOS lista_ids						{printf("\ndeclaracion - STRING DOSPUNTOS lista_ids");
		/*printf("declarado FLOAT con nombre %s", yylval.str_val);*/
		/*printf("declarado INT con nombre ");*/
	}
	;
	
lista_ids:  	ID				{printf("\nlista_ids - ID '%s'",yylval.strval);}
			| lista_ids PUNTO_Y_COMA ID	{printf("\nlista_ids - lista_ids PUNTO_Y_COMA ID");}
			;
   	
asignacion:
    ID OP_ASIG expresion { printf("\nasignacion ID - OP_ASIG - expresion");}
    | ID OP_ASIG constanteString { printf("\nasignacion ID - OP_ASIG - CTE_STRING");}
;

entrada:
    DISPLAY ID  PUNTO_Y_COMA        {printf("\nentrada DISPLAY - ID"); }
    | DISPLAY constanteString PUNTO_Y_COMA {printf("\nentrada DISPLAY - CONST_STR"); }
    ;
    
salida:
    GET ID  PUNTO_Y_COMA {printf("\nsalida GET - ID"); }
    ;

iteracion:
     WHILE P_A condicion P_C L_A sentencia L_C { printf("\niteracion - WHILE P_A condicion P_C L_A sentencia L_C");}
    ;

decision: 
    IF P_A condicion P_C L_A sentencia L_C {   printf("\ndecision - IF P_A condicion P_C L_A sentencia L_C");
 
                                                 }
   | IF P_A condicion P_C L_A sentencia L_C {  printf("\ndecision - IF P_A condicion P_C L_A sentencia L_C");
                                                
                                               
                                                 }
    ELSE                                    {   printf("\nInicio del else");
                                                   }
    L_A sentencia L_C                      {   printf("\nFin del else");
                                                
                                            
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
    | ID                        {   printf("\nfactor - ID ");
                                    
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

let: LET_SIM cont_ids OP_IGUAL P_A cont_exp P_C {
				if(cont_1==cont_2){
					printf("\nsentencia - LET_SIM cont_ids OP_IGUAL P_A cont_exp P_C");
					/*printf("\nvalores cont_1: %d cont_2: %d",cont_1,cont_2);*/
					cont_1 = 0;
					cont_2 = 0;
				}else{
					yyerror();
				}
				}
	;
	
cont_ids: cont_ids COMA ID {cont_1++;printf("\ncont_ids - cont_ids COMA ID");}
			| ID {cont_1++; printf("\ncont_ids - ID");}
			;

cont_exp: cont_exp PUNTO_Y_COMA expresion {cont_2++;printf("\ncont_exp - cont_exp PUNTO_Y_COMA expresion");}
			| expresion {cont_2++;printf("\ncont_exp - expresion");}
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
       printf("Syntax Error en la linea: %d\n", yylineno);
	 system ("Pause");
	 exit (1);
     }
