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
void generateCodeAsignationSimple(t_arbol *p);
char* getCodOp(char* token);
void generateCode(t_arbol *p);
void generateCodeOperation(t_arbol * p, char * operation);
int verifyIsCondition(char* value);

FILE *file;

void generarAssembler(t_arbol *p){

    file = fopen("Final.asm", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
   
    generarCodigoInicial();
    escribirDesdeArbol(p);
    generarCodigoFinal();
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

void generarCodigoFinal(){

    fprintf(file, "\n mov AX, 4C00h \n");
	fprintf(file, "int 21h ; Genera la interrupcion 21h \n ");
    fprintf(file, "END ; fin. \n");
}

void escribirDesdeArbol(t_arbol *p){

    //postorden hasta encontrar el nodo con dos hijos hoja
    if ( (*p)->izq != NULL ) {
        escribirDesdeArbol (&(*p)->izq);
    }

    if( (*p)->der != NULL ) {
        escribirDesdeArbol (&(*p)->der);
    }

    generateCode(p);
}

void generateCode(t_arbol *p){


    if((*p)->der != NULL && (*p)->izq  != NULL) {
        printf("\tLEFT=[%s]\t[%s]\tRIGHT[%s]\n", (*p)->izq->info, (*p)->info, (*p)->der->info);
        char operation[200];
        if (verifyIsCondition((*p)->info)) {
            generateCondition(p);
        }
         else if (strcmp((*p)->info,"+") == 0) {
            strcpy(operation, "ADD");
            generateCodeOperation(p, operation);
        } else if (strcmp((*p)->info,"*") == 0) {        
            strcpy(operation, "MUL");
            generateCodeOperation(p, operation);
        } else if (strcmp((*p)->info,"/") == 0) {        
            strcpy(operation, "DIV");
            generateCodeOperation(p, operation);
        } else if (strcmp((*p)->info,"-") == 0) {     
            strcpy(operation, "SUB"); 
            generateCodeOperation(p, operation);
        } else if (strcmp((*p)->info,":=") == 0) {       
            if (strcmp((*p)->der->info,"_SUM") == 0 || strcmp((*p)->der->info,"_SUB") == 0 || strcmp((*p)->der->info,"_MUL") == 0 || strcmp((*p)->der->info,"_DIV") == 0) {
                generateCodeAsignation(p);
            } else {
                generateCodeAsignationSimple(p);
            }
        }
    }
    
 

    if(strcmp((*p)->info , ":=") == 0){
        printf("\nENCONTRE UN := ");
        generateCodeAsignationSimple(p);
    }
    
}

void generateCodeAsignationSimple(t_arbol *p){

    if(strchr((*p)->der->info, '.') != NULL){
            char * aux = (*p)->der->info;
            while(*aux != '.'){
                aux ++;
            }
            *aux = '_';
        }
    fprintf(file, "\t; Simple Asignation\n");
    fprintf(file, "\tFILD _%s\n", &(*p)->der->info);
    fprintf(file, "\tFSTP %s\n", &(*p)->izq->info); 
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

void generateCodeOperation(t_arbol *p, char * operation) {

    if(strchr(root->left->value, '.') != NULL){
        char * aux = root->left->value;
        while(*aux != '.'){
            aux ++;
        }
        *aux = '_';
    }
    if(strchr(root->right->value, '.') != NULL){
        char * aux = root->right->value;
        while(*aux != '.'){
            aux ++;
        }
        *aux = '_';
    }

    if(strcmp(auxString,"*010101*") != 0) {
        fprintf(file, "%s", auxString);
        strcpy(auxString,"*010101*"); // Código para que no printee FSTP
    }

    fprintf(file, "\t; %s\n", operation);

    fprintf(file, "\tFLD %s\n", root->left->value);
    fprintf(file, "\tFLD %s\n", root->right->value);
    
    // Check if + - / * and print in .asm
    if(strcmp(operation,"ADD") == 0) {
        fprintf(file, "\tFADD\n", root->value);
        root->value = "_SUM";
    } else if (strcmp(operation,"SUB") == 0) {
        fprintf(file, "\tFSUB\n", root->value);
        root->value = "_SUB";
    } else if (strcmp(operation,"MUL") == 0) {
        fprintf(file, "\tFMUL\n", root->value);
        root->value = "_MUL";  
    } else if (strcmp(operation,"DIV") == 0) {
        fprintf(file, "\tFDIV\n", root->value);
        root->value = "_DIV";  
    }
    sprintf(auxString, "\tFSTP %s\n\n", root->value);
}

int verifyIsCondition(char* value) {
    if (
        strcmp(value,">=") == 0 ||
        strcmp(value,">") == 0 || 
        strcmp(value,"<=") == 0 || 
        strcmp(value,"<") == 0 ||
        strcmp(value,"!=") == 0 ||
        strcmp(value,"==") == 0) {
            return 1; // is an operand
    }
    return 0; // not an operand
}

char* getCodOp(char* token)
{
	if(!strcmp(token, "+"))
	{
		return "FADD";
	}
	else if(!strcmp(token, "="))
	{
		return "MOV";
	}
	else if(!strcmp(token, "-"))
	{
		return "FSUB";
	}
	else if(!strcmp(token, "*"))
	{
		return "FMUL";
	}
	else if(!strcmp(token, "/"))
	{
		return "FDIV";
	}
	else if(!strcmp(token, "BNE"))
	{
		return "JNE";
	}
	else if(!strcmp(token, "BEQ"))
	{
		return "JE";
	}
	else if(!strcmp(token, "BGE"))
	{
		return "JNA";
	}
	else if(!strcmp(token, "BGT"))
	{
		return "JNAE";
	}
	else if(!strcmp(token, "BLE"))
	{
		return "JNB";
	}
	else if(!strcmp(token, "BLT"))
	{
		return "JNBE";
	}
	else if (!strcmp(token, "BI")) {
		return "JMP";
	}
}