%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "pila-dinamica.h"
#include "ts.h"
#include "arbol.c"
#include "cola.c"

int yystopparser=0;
FILE  *yyin;
extern int yylineno;
int cont_1 = 0;
int cont_2 = 0;

t_arbol arbol;
char str_aux[50];
char str_aux2[50];
int c = 1; //Contador para nodos auxiliares

%}
%union{
	  char *strval;
	  //char a_e[2];
    float val;
    char  name[100];
}

%{
pila_s pilaDeclares;
t_cola colaLet;
%}


/*%token INI_DEFVAR
%token FIN_DEFVAR
%token <str_val> ID
%token PUNTOCOMA
%token DOSPUNTOS
%token DEF_INT
%token DEF_FLOAT
*/
//%token <a_e> ASIG_ESP
%token DEFVAR ENDDEF
%token INT FLOAT STRING

%token CONST_REAL CONST_INT CONST_STR
%token DISPLAY GET
%token IF ELSE WHILE
%token P_A P_C C_A C_C L_A L_C PUNTO_Y_COMA COMA DOSPUNTOS
%token CMP_MAY CMP_MEN CMP_MAYI CMP_MENI CMP_DIST CMP_IGUAL
%token OP_SUM OP_RES OP_DIV OP_MUL
%token AND OR NOT
//%type <strval> expresion
%token <strval> ID
%token OP_ASIG
%token LET_SIM
%token OP_IGUAL
%type <strval> expresion

%token AE_MAIG AE_MEIG AE_MUIG AE_DIIG


%%
/*
programa: program {
    arbol=*ProgPtr;
    printf("\nprogram - program\nCompilacion OK\n");};
program:
	sentencia 				{
                        sprintf(str_aux,"_Cuerpo_%d",c++);
                        ProgPtr=crearNodo(str_aux,*SentPtr,NULL);
                        printf("\nprogram - sentencia");
                                }
	| program sentencia 	{
                        sprintf(str_aux,"_Cuerpo_%d",c++);
						ProgPtr=crearNodo(str_aux,*ProgPtr,*SentPtr);
                        printf("\nprogram - program sentencia");
                        }
	;
*/
programa: program {
    arbol=*ProgPtr;
    printf("\nprogram - program\nCompilacion OK\n");};

program: bloq_declaracion sentencia {
                                    sprintf(str_aux,"_Cuerpo_%d",c++);
                                    ProgPtr=crearNodo(str_aux,*SentPtr,NULL);
                                    printf("\nprograma: bloq_declaracion sentencia");
                                    }
        ;

bloq_declaracion:
        DEFVAR {crearPilaS(&pilaDeclares); } declaraciones ENDDEF {printf("\nbloq_declaracion - DEFVAR declaraciones ENDDEF");}
        ;

declaraciones:
             declaracion					{ printf("\ndeclaraciones - declaracion");}
             | declaraciones declaracion	{printf("\ndeclaraciones - declaraciones declaracion");}
    	     ;

declaracion: INT DOSPUNTOS lista_ids {

                                        while(!pilaVaciaS(&pilaDeclares)){
                                            char *id = sacarDePilaS(&pilaDeclares);
                                            char *type = "INTEGER";
                                            modifyTypeTs(id, type);
                                        }
                                        printf("\ndeclaracion - INT DOSPUNTOS lista_ids");
                                    }
            |FLOAT DOSPUNTOS lista_ids {
                                            while(!pilaVaciaS(&pilaDeclares)){
                                                char *id = sacarDePilaS(&pilaDeclares);
                                                char *type = "FLOAT";
                                                modifyTypeTs(id, type);
                                            }
                                            printf("\ndeclaracion - FLOAT DOSPUNTOS lista_ids");
                                        }
            |STRING DOSPUNTOS lista_ids	{
                                             while(!pilaVaciaS(&pilaDeclares)){
                                                char *id = sacarDePilaS(&pilaDeclares);
                                                char *type = "STRING";

                                                modifyTypeTs(id, type);
                                            }
                                            printf("\ndeclaracion - STRING DOSPUNTOS lista_ids");
            };

lista_ids:  	ID 	{ ponerEnPilaS(&pilaDeclares, $1); printf("\nlista_ids - ID '%s'",yylval.strval);}
			| lista_ids PUNTO_Y_COMA ID	{ponerEnPilaS(&pilaDeclares, $3), printf("\nlista_ids - lista_ids PUNTO_Y_COMA ID '%s'",yylval.strval);}
			;

sentencia: 
			asignacion_especial 	{	
									SentPtr = AEPtr;
									printf("\nsentencia - asignacion_especial");
								}
            | asignacion PUNTO_Y_COMA {
                                        SentPtr = Aptr ;
                                        printf("\nsentencia - asignacion");
                                        }
            | decision              {
                                        SentPtr = Decptr ;
                                        printf("\nsentencia - decision");
                                    }
            | iteracion             {
                                        SentPtr = IteraPtr;
                                        printf("\nsentencia - iteracion");}
			| let					{
										SentPtr = LetPtr;
										printf("\nsentencia - let");
									}
            | entrada               {   SentPtr = getPtr ;
                                        printf("\nsentencia - entrada");}
            | salida                {  SentPtr = displayPtr;
							 			printf("\nsentencia - salida");}
	        ;



asignacion:

    ID OP_ASIG expresion {
                          sprintf(str_aux, "%s",$1);
                          if(!searchTs(str_aux))
                            printf("ERROR el id : %s no se encuentra declarado", str_aux);
                          Auxptr=crearHoja(str_aux);
                          Aptr = crearNodo(":=",*Auxptr,*Eptr) ;
                          printf("\nasignacion ID - OP_ASIG - expresion");
                          }
    | ID OP_ASIG constanteString {

                            sprintf(str_aux, "%s",$1);
                            Auxptr=crearHoja(str_aux);
                            Aptr = crearNodo(":=",*Auxptr,*cteStringptr) ;
                            printf("\nasignacion ID - OP_ASIG - CTE_STRING");}

;

salida:
    DISPLAY ID PUNTO_Y_COMA        { 			sprintf(str_aux, "%s",$2);
												hojaIOPtr = crearHoja(str_aux);
												displayPtr = crearNodo("DISPLAY",*hojaIOPtr,NULL);
                                                printf("\nentrada DISPLAY - CONST_STR");
                                                }
    |
		DISPLAY constanteString PUNTO_Y_COMA {
												displayPtr = crearNodo("DISPLAY",*cteStringptr,NULL) ;
												printf("\nentrada DISPLAY - CONST_STR");
												}
    ;


entrada:
    GET ID  PUNTO_Y_COMA { 
                          sprintf(str_aux, "%s",$2);
                          AuxGetPtr = crearHoja(str_aux);
                          getPtr = crearNodo("GET", *AuxGetPtr, NULL); 
                          printf("\nsalida GET - ID"); 
    }
    ;

iteracion:
     WHILE P_A condicion P_C L_A sentencia L_C {
                                                IteraPtr = crearNodo("WHILE", *CondPtr, *SentPtr);
                                                printf("\niteracion - WHILE P_A condicion P_C L_A sentencia L_C");}
    ;

decision:
    IF P_A condicion P_C L_A sentencia L_C {
                                                printf("\ndecision - IF P_A condicion P_C L_A sentencia L_C");
                                                Decptr = crearNodo("IF",*CondPtr,*SentPtr);
                                                 }
   | IF P_A condicion P_C L_A sentencia L_C {  printf("\ndecision - IF P_A condicion P_C L_A sentencia L_C");
                                                 }
    ELSE                                    {
                                                SentVPtr = SentPtr;
                                                printf("\nInicio del else");
                                                   }
    L_A sentencia L_C                      {   printf("\nFin del else");
                                                sprintf(str_aux,"_Cuerpo_%d",c++);

                                                Decptr = crearNodo("IF",*CondPtr,*crearNodo(str_aux,*SentVPtr,*SentPtr));

                                                }

   ;

condicion:
    expresion {E1ptr = Eptr;} CMP_MAY expresion     {
                                        CondPtr = crearNodo(">",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MAY expresion");
                                         }
    | expresion {E1ptr = Eptr;} CMP_MEN expresion   {
                                        CondPtr = crearNodo("<",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MEN expresion");
                                          }
    | expresion {E1ptr = Eptr;} CMP_MAYI expresion   {
                                        CondPtr = crearNodo(">=",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MAYI expresion");
                                          }
    | expresion {E1ptr = Eptr;}  CMP_MENI expresion  {
                                        CondPtr = crearNodo("<=",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_MENI expresion");
                                         }
    | expresion {E1ptr = Eptr;} CMP_DIST expresion  {
                                        CondPtr = crearNodo("!=",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_DIST expresion");
                                        }
    | expresion {E1ptr = Eptr;} CMP_IGUAL expresion {
                                        CondPtr = crearNodo("==",*E1ptr,*Eptr);
                                        printf("\ncondicion - expresion CMP_IGUAL expresion");

                                           }


    | P_A condicion {CondIzqPtr = CondPtr;} P_C AND P_A condicion P_C   {
                                        CondPtr = crearNodo("AND", *CondIzqPtr, *CondPtr);
                                        printf("\ncondicion - AND");

                                        }

    | NOT expresion {E1ptr = Eptr;} CMP_MAY expresion     {

                                        CondPtr = crearNodo("<=",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MAY expresion");



                                         }
    |NOT expresion  {E1ptr = Eptr;} CMP_MEN expresion   {
                                        CondPtr = crearNodo(">=",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MEN expresion");

                                          }
    |NOT expresion  {E1ptr = Eptr;} CMP_MAYI expresion   {
                                        CondPtr = crearNodo("<",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MAYI expresion");

                                          }
    |NOT expresion  {E1ptr = Eptr;} CMP_MENI expresion  {
                                        CondPtr = crearNodo(">",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_MENI expresion");

                                          }
    |NOT expresion  {E1ptr = Eptr;} CMP_DIST expresion  {
                                        CondPtr = crearNodo("==",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_DIST expresion");

                                        }
    |NOT expresion  {E1ptr = Eptr;} CMP_IGUAL expresion {
                                         CondPtr = crearNodo("!=",*E1ptr,*Eptr);
                                        printf("\ncondicion - NOT expresion CMP_IGUAL expresion");

                                        }
    ;


expresion:
    expresion OP_SUM termino        {
                                        Eptr = crearNodo("+", *Eptr, *Tptr);
                                        printf("\nexpresion - expresion OP_SUM termino");
                                         }
    | expresion OP_RES termino      {
                                        Eptr = crearNodo("-", *Eptr, *Tptr);
                                        printf("\nexpresion - expresion OP_RES termino");
                                         }
    | termino                       {
                                        Eptr = Tptr;
                                        printf("\nexpresion - termino");   }
    ;

termino:
    termino OP_MUL factor       {
                                    Tptr = crearNodo("*", *Tptr, *Fptr);
                                    printf("\ntermino - termino OP_MUL factor");
                                    }
    | termino OP_DIV factor     {
                                    Tptr = crearNodo("/", *Tptr, *Fptr);
                                    printf("\ntermino - termino OP_DIV factor");
                                   }
    | factor                    {
                                    Tptr = Fptr;
                                    printf("\ntermino - factor");

                                       }
    ;

factor:
    P_A expresion P_C           {   printf("\nfactor - P_A expresion P_C");
                                    }
    | ID                        {
                                    sprintf(str_aux, "%s", yylval.strval);
                                    Fptr = crearHoja(str_aux);
                                    printf("\nfactor - ID", *str_aux);

                                    }
    | constanteNumerica         {
                                    Fptr = constNumPtr;
                                    printf("\nfactor - constanteNumerica");

                                     }
    ;

constanteNumerica:

    CONST_INT               {
                                sprintf(str_aux, "%s", yylval.strval);
                                constNumPtr = crearHoja(str_aux);
                                printf("\nconstante - ENTERO: %s", yylval.strval);

                            }
    | CONST_REAL            {
                                sprintf(str_aux, "%s", yylval.strval);
                                constNumPtr = crearHoja(str_aux);
                                printf("\nconstante - REAL: %s" , yylval.strval);

                            };

constanteString:
    CONST_STR        {      sprintf(str_aux, "%s", yylval.strval);
                            cteStringptr = crearHoja(str_aux);
                            printf("\nconstante - STRING %s" , yylval.strval);
                        }
    ;

let: LET_SIM {crearCola(&colaLet);}cont_ids OP_IGUAL P_A cont_exp P_C {
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
	;

cont_ids: cont_ids COMA ID {
								ponerEnCola(&colaLet, $3);
								cont_1++;printf("\ncont_ids - cont_ids COMA ID");
							}
			| ID 			{
								ponerEnCola(&colaLet, $1);
								cont_1++; printf("\ncont_ids - ID");
							}
			;

cont_exp: cont_exp PUNTO_Y_COMA expresion {
								Let_cont_id = crearNodo(";",*Let_cont_id,*crearNodo("=",*crearHoja(sacarDeCola(&colaLet)),*Eptr));
								cont_2++;printf("\ncont_exp - cont_exp PUNTO_Y_COMA expresion");
								}
			| expresion {
								Let_cont_id = crearNodo("=",*crearHoja(sacarDeCola(&colaLet)),*Eptr);
								cont_2++;printf("\ncont_exp - expresion");
								}
			;

asignacion_especial: ID AE_MAIG ID 	{	
										sprintf(str_aux, "%s",$1);
										sprintf(str_aux2, "%s",$3);
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("+",*Auxptr2,*Auxptr3));
										printf("\nasignacion_especial - ID MAIG ID");
									}
					|ID AE_MEIG ID 	{
										sprintf(str_aux, "%s",$1);
										sprintf(str_aux2, "%s",$3);
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("-",*Auxptr2,*Auxptr3));
										printf("\nasignacion_especial - ID MAIG ID");
									}
					|ID AE_MUIG ID 	{
										sprintf(str_aux, "%s",$1);
										sprintf(str_aux2, "%s",$3);
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("*",*Auxptr2,*Auxptr3));
										
										
										printf("\nasignacion_especial - ID MAIG ID");
									}
					|ID AE_DIIG ID 	{
										sprintf(str_aux, "%s",$1);
										sprintf(str_aux2, "%s",$3);
										Auxptr = crearHoja(str_aux);
										Auxptr2 = crearHoja(str_aux);
										Auxptr3 = crearHoja(str_aux2);
										
										AEPtr = crearNodo("=",*Auxptr,*crearNodo("/",*Auxptr2,*Auxptr3));
										printf("\nasignacion_especial - ID MAIG ID");
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
