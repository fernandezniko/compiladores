%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "pila-dinamica.h"
#include "ts.h"
#include "arbol.c"
#define YYDEBUG 1

int yystopparser=0;
FILE  *yyin;
extern int yylineno;
int cont_1 = 0;
int cont_2 = 0;

t_arbol arbol;

char str_aux[50];

int c = 1; //Contador para nodos auxiliares

%}
%union{
	  char *strval;
	  char a_e[2];
    float val;
    char    name[100];
}

%{
pila_s pilaDeclares;
%}


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
%token CONST_STR CONST_REAL CONST_INT
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
//%type<name> ID
%type<val> CONST_REAL
%type<val> CONST_INT



%%
programa: program { 
                    printf("\nREGLA 00 program - program Compilacion OK\n");
                    arbol=*ProgPtr;
                    }                   
;

program: 
        sentencia {printf("\nREGLA 1 program - sentencia");
        
						//Nodos auxiliares para anidar sentencias 
						//sprintf(str_aux,"_Cuerpo_%d",c++); 
						ProgPtr=crearNodo(str_aux,*SentPtr,NULL); 
					
        }
        ;
        /*| program sentencia {printf("\nREGLA 2 program - program sentencia");
        
        
						//Nodos auxiliares para anidar sentencias 
						sprintf(str_aux,"_Cuerpo_%d",c++); 
						ProgPtr=crearNodo(str_aux,*ProgPtr,*SentPtr); 
					}
          
        
        ;*/

sentencia:
          asignacion PUNTO_Y_COMA { 
                                    printf("\nREGLA 3 sentencia - asignacion");
                                    SentPtr = Aptr ;
                                    //arbol=*ProgPtr;
          }
          /*| decision {
                  printf("\nREGLA 4 sentencia - decision")
                  SentPtr = Decptr ;
          }*/
          
;

asignacion:
    ID OP_ASIG expresion {sprintf(str_aux, "%s",$1);
                          Auxptr=crearHoja(str_aux);
                          Aptr = crearNodo(":=",*Auxptr,*Eptr) ;
                          printf("\nREGLA 5 asignacion ID - OP_ASIG - expresion");
                          
                          }
    | ID OP_ASIG constanteString {  sprintf(str_aux, "%s",$1);
                                    Auxptr=crearHoja(str_aux);
                                    Aptr = crearNodo(":=",*Auxptr,*cteStringptr) ;
                                    printf("\nREGLA 6 asignacion ID - OP_ASIG - CTE_STRING");
                                    }
;

    
expresion:
    expresion OP_SUM termino        { Eptr = crearNodo("+", *Eptr, *Tptr)  ;
                                      printf("\nREGLA 7 expresion - expresion OP_SUM termino"); 
                                        
                                         }

    | expresion OP_RES termino      {  Eptr = crearNodo("-", *Eptr, *Tptr)  ; 
                                      printf("\nREGLA 8 expresion - expresion OP_RES termino");
                                         }                                     
    | termino                       { Eptr = Tptr ;  
                                      printf("\nREGLA 9 expresion - termino");   }
    ;

termino: 
    termino OP_MUL factor       { Tptr = crearNodo("*", *Tptr, *Fptr)   ;
                                  printf("\nREGLA 10 termino - termino OP_MUL factor"); 
                                    
                                   
                                    }

    | termino OP_DIV factor     { Tptr = crearNodo("/", *Tptr, *Fptr)   ;  
                                  printf("\nREGLA 11 termino - termino OP_DIV factor"); 
                                                                      
                                   }
                                   
    | factor                    { Tptr = Fptr ;  
                                  printf("\nREGLA 12 termino - factor");
                                       }
    ;

factor: 
     ID                        {  sprintf(str_aux, "%s",$1);
                                  Fptr = crearHoja(str_aux);   
                                  printf("\nREGLA 13 factor - ID ");
                                   
                                    }

    | constanteNumerica         { Fptr = constNumPtr ; 
                                  printf("\nREGLA 14 factor - constanteNumerica");
                                  
                                     }                    
    ;


constanteNumerica: 
    CONST_INT               { sprintf(str_aux, "%s", yylval.strval);
                              
                              constNumPtr = crearHoja(str_aux);
                              printf("\nREGLA 15 constanteNumerica - ENTERO");
                            
                            }

    | CONST_REAL            {sprintf(str_aux, "%s", yylval.strval); 
                             constNumPtr = crearHoja(str_aux);
                             
                             printf("\nREGLA 16 constanteNumerica - REAL");
                                                       
                            }
    ;
 
constanteString: 
    CONST_STR        {  sprintf(str_aux, "%s", yylval.strval); 
                             cteStringptr = crearHoja(str_aux);
                            printf("\nREGLA 17 constante - STRING %s" , yylval.strval);
                        }
    ;

/*
decision: 
    IF P_A condicion P_C L_A sentencia L_C {   printf("\nREGLA 18 decision - IF P_A condicion P_C L_A sentencia L_C");
                                               Decptr = crearNodo("IF",*CondPtr,*SentPtr);
    }
    ;

condicion: 
    expresion {E1ptr = Eptr} CMP_MAY expresion     {   printf("\nREGLA 19 condicion - expresion CMP_MAY expresion");
                                        CondPtr = crearNodo(">",*E1ptr,*Eptr);
                                        
                                         }
    | expresion {E1ptr = Eptr} CMP_MEN expresion   {   printf("\ncondicion - expresion CMP_MEN expresion");
                                        CondPtr = crearNodo("<",*E1ptr,*Eptr);
                                          }
    | expresion {E1ptr = Eptr} CMP_MAYI expresion   {  printf("\ncondicion - expresion CMP_MAYI expresion");
                                        CondPtr = crearNodo(">=",*E1ptr,*Eptr);
                                          }
    | expresion {E1ptr = Eptr} CMP_MENI expresion  {   printf("\ncondicion - expresion CMP_MENI expresion");
                                        CondPtr = crearNodo("<=",*E1ptr,*Eptr);
                                         }
    | expresion {E1ptr = Eptr} CMP_DIST expresion  {   printf("\ncondicion - expresion CMP_DIST expresion");
                                        CondPtr = crearNodo("!=",*E1ptr,*Eptr);
                                        }
    | expresion {E1ptr = Eptr} CMP_IGUAL expresion {   printf("\ncondicion - expresion CMP_IGUAL expresion");
                                        CondPtr = crearNodo("==",*E1ptr,*Eptr);
                                           }
    ;*/
%%

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
	}

  return 0;
}

int yyerror(void)
     {
       printf("Syntax Error en la linea: %d\n", yylineno);
	 system ("Pause");
	 exit (1);
     }
