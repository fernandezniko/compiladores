#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "ts.h"
#include "arbol.h"


void generarAssembler(t_arbol * p);
void generarCodigoInicial();
void generarCodigoFinal();
void escribirDesdeArbol(t_arbol *p);
void escribirDatosDeTS();
FILE *file;

void generarAssembler(t_arbol *p){

    file = fopen("Final.asm", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
   
    generarCodigoInicial();
    //escribirDesdeArbol(p);
    //generarCodigoFinal();
    fclose(file);
}


void generarCodigoInicial(){

    fprintf(file,"include macros2.asm \n");
    fprintf(file,"include number.asm \n\n\n");
    fprintf(file,".MODEL LARGE\n");
    fprintf(file,".386\n");
    fprintf(file,".STACK 200h\n\n");
    fprintf(file,"MAXTEXTSIZE equ 50\n\n");
    fprintf(file,".DATA\n");

    escribirDatosDeTS();

    fprintf(file, "\n\n.CODE\n");


}

void escribirDatosDeTS(){

    FILE *fp = fopen("ts.txt", READ_FILE);
    char linea[1000],word[100], type[100],value[100],length[100];
    int esLineaEncabezado = 0;
    if(fp!= NULL) 
	{	

		while(fgets(linea,sizeof(linea),fp))
		{
            if(esLineaEncabezado == 0) {
				esLineaEncabezado = 1;
            }
            else{
                strcpy(type,"");
                strcpy(word,"");
                sscanf(linea, "%s %s %s %s", word, type, value, length);
                
                if(strcmp(type,TYPE_INTEGER_TS)==0){ 
                    fprintf(file, "\t%s\tdd\t?\n", word);
                }
                if(strcmp(type,TYPE_CONST_INT_TS)==0){
                    fprintf(file, "\t%s\tdd\t%s.0\n", word, value);
                }
                if(strcmp(type,TYPE_FLOAT_TS)==0){ 
                    fprintf(file, "\t%s\tdd\t?\n", word);
                }
                if(strcmp(type,TYPE_CONST_FLOAT_TS)==0){
                     fprintf(file, "\t%s\tdd\t%s\n", word, value);   
                }
                if(strcmp(type,TYPE_STRING_TS)==0){ 
                    fprintf(file, "\t%s\tdb\tMAXTEXTSIZE dup (?),'$'\n", word);
                }
                if(strcmp(type,TYPE_CONST_STRING_TS)==0){
                    fprintf(file, "\t%s\tdb\t'%s','$', %s dup (?)\n", word, value, length);
                }
            }
		}
	}
}
