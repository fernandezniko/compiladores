#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "ts.h"
#include "arbol.h"


void generateCondition(t_arbol *p);
char *eliminar_comillas(char *cadena);
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
pila_s pilaSaltos;
int contadorSaltos = 0;
int escribirEtiquetaSalto = 0;
int escribirSaltoAFin = 0;
int vengoDeIf = 0;
char cuerpoAuxIf[1000];

void generarAssembler(t_arbol *p){

    file = fopen("Final.asm", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    crearPilaS(&pilaSaltos);

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

    fprintf(file, "\t_ADD\tdd\t?\n");
    fprintf(file, "\t_SUB\tdd\t?\n");
    fprintf(file, "\t_MUL\tdd\t?\n");
    fprintf(file, "\t_DIV\tdd\t?\n");

    fprintf(file, "\n\n.CODE");
    fprintf(file, "\nSTART:");
    fprintf(file, "\n\tmov AX,@DATA");
    fprintf(file, "\n\tmov DS,AX");
     fprintf(file, "\n\tmov es,ax\n");   


}

void generarCodigoFinal(){

    fprintf(file, "\n mov AX, 4C00h \n");
	fprintf(file, "int 21h ; Genera la interrupcion 21h \n ");
    fprintf(file, "END START ; fin. \n");
}

void escribirDesdeArbol(t_arbol *p){

    //Recorriendo el arbol me encuentro con un if?
    if(strcmp((*p)->info,"IF") == 0){
        contadorSaltos++;
        //ponerEnPilaS(&pilaSaltos,(*p)->der->info);
        strcpy(cuerpoAuxIf, (*p)->der->info);
    }else
    {
        if(escribirEtiquetaSalto = 1){
            escribirSaltoAFin = 1;
            escribirEtiquetaSalto = 0;
        }
    }

    //postorden hasta encontrar el nodo con dos hijos hoja
    if ( (*p)->izq != NULL ) {
        escribirDesdeArbol (&(*p)->izq);
    }

    //cuando veo la parte derecha , antes de escribir pregunto si es if y escribo salto condicional a else
    // HASTA ACA TODO BIEN, ESCRIBE EL CONDICIONAL DONDE TIENE QUE IR
    //EL TEMA ES CUANDO TENGO QUE IMPRIMIR LA ETIQUETA
    if(strcmp((*p)->info,"IF") == 0){

        if (strcmp((*p)->izq->info,">=") == 0) {    
            fprintf(file,"\tJB ELSE_%d\n", contadorSaltos);
        }else if (strcmp((*p)->izq->info,">") == 0) {      
            fprintf(file,"\tJBE ELSE_%d\n", contadorSaltos);
        }else if (strcmp((*p)->izq->info,"<=") == 0) {      
            fprintf(file,"\tJA ELSE_%d\n", contadorSaltos);
        }else if (strcmp((*p)->izq->info,"<") == 0) {      
            fprintf(file,"\tJAE ELSE_%d\n", contadorSaltos);
        }else if (strcmp((*p)->izq->info,"!=") == 0) {      
            fprintf(file,"\tJE ELSE_%d\n", contadorSaltos);
        }else if (strcmp((*p)->izq->info,"==") == 0) {      
            fprintf(file,"\tJNE ELSE_%d\n", contadorSaltos);
        }
        vengoDeIf = 1;
        escribirEtiquetaSalto = 1;
    }
    
    //char * aux;//sacarDePilaS(&pilaSaltos);
    
    // if(strcmp((*p)->info, aux) == 0){
    //     fprintf(file,"\tJMP FINIF_%d\n", contadorSaltos);
    //     escribirEtiquetaSalto = 0;
    //     escribirSaltoAFin = 0;
    // }
    // }else{
    //     //ponerEnPilaS(&pilaSaltos,aux);
    // }

    // if(escribirEtiquetaSalto == 1){
    //     fprintf(file,"\tJMP FINIF_%d\n", contadorSaltos);
    //     fprintf(file,"\tELSE_%d:\n", contadorSaltos);
    // }

    if( (*p)->der != NULL ) {
        escribirDesdeArbol (&(*p)->der);
    }


    //printf("asdasd %s", &cuerpoAuxIf);
     if(vengoDeIf == 1 & strcmp((*p)->info, cuerpoAuxIf) == 0 ){
        printf("ENTRO ACAAAA");
        fprintf(file,"\tELSE_%d:\n", contadorSaltos);
        escribirEtiquetaSalto = 0;
        escribirSaltoAFin = 0;
        vengoDeIf = 0;
    }

    generateCode(p);
}

void generateCode(t_arbol *p){

    char operation[200];
    if((*p)->der != NULL && (*p)->izq  != NULL) {
        printf("\tLEFT=[%s]\t[%s]\tRIGHT[%s]\n", (*p)->izq->info, (*p)->info, (*p)->der->info);
        
        if (verifyIsCondition((*p)->info)) {
            generateCondition(p);
        }else if (strcmp((*p)->info,"+") == 0) {
            strcpy(operation, "ADD");
            generateCodeOperation(p, operation);
            fprintf(file, "\tFSTP _%s\n", operation); 
        } else if (strcmp((*p)->info,"*") == 0) {        
            strcpy(operation, "MUL");
            generateCodeOperation(p, operation);
            fprintf(file, "\tFSTP _%s\n", operation); 
        } else if (strcmp((*p)->info,"/") == 0) {        
            strcpy(operation, "DIV");
            generateCodeOperation(p, operation);
            fprintf(file, "\tFSTP _%s\n", operation); 
        } else if (strcmp((*p)->info,"-") == 0) {     
            strcpy(operation, "SUB"); 
            generateCodeOperation(p, operation);
            fprintf(file, "\tFSTP _%s\n",operation); 
        } 
    }
    
    if (strcmp((*p)->info,"DISPLAY") == 0) {
        char* nodoizq = eliminar_comillas((*p)->izq->info);
        int type = getType(nodoizq);
        if(type == 3){
            fprintf(file,"\tDisplayString %s\n", nodoizq);
             fprintf(file,"\tnewLine 1\n");
        }else{
            fprintf(file,"\tDisplayFloat %s,2\n", nodoizq);
            fprintf(file,"\tnewLine 1\n");
        }

    }

    if (strcmp((*p)->info,"GET") == 0) {
		char* nodoizq = eliminar_comillas((*p)->izq->info);
		int type = getType(nodoizq);
		if(type == 1){
            fprintf(file,"\tGetInteger %s\n", nodoizq);
        }
	} 

    if(strcmp((*p)->info , ":=") == 0){
        printf("\nENCONTRE UN := ");
        generateCodeAsignationSimple(p);
    }
    
}

void generateCodeAsignationSimple(t_arbol *p){

    char* derecho =  eliminar_comillas((*p)->der->info);
    char* izquierdo =  eliminar_comillas((*p)->izq->info);

    if((*p)->der->info[0] == '"') {
        ////fprintf(file, "\tLEA SI, %s\n\tLEA DI,%s\n\tCALL COPY\n", root->right->value, root->left->value);
        fprintf(file, "\tLEA SI, _%s\n\tLEA DI,%s\n", derecho,izquierdo);
        fprintf(file,"cpy_nxt:mov bl, [si]\n\tmov [di], bl\n\tinc si\n\tinc di\n\tdec cx\n\tjnz cpy_nxt\n");
    }else{
        if(strchr((*p)->der->info, '.') != NULL){
                char * aux = (*p)->der->info;
                while(*aux != '.'){
                    aux ++;
                }
                *aux = '_';
            }
        fprintf(file, "\tFLD _%s\n", &(*p)->der->info);
        fprintf(file, "\tFSTP %s\n", &(*p)->izq->info); 
    }
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
                    char *wordSinComillas = eliminar_comillas(word);
                    fprintf(file, "\t%s\tdb\tMAXTEXTSIZE dup (?),'$'\n", wordSinComillas);
                }
                if(strcmp(type,TYPE_CONST_STRING_TS)==0){
                    char* wordSinComillas = eliminar_comillas(word);
                    char* valueSinComillas = eliminar_comillas(value);
                    fprintf(file, "\t%s\tdb\t'%s','$', %s dup (?)\n", wordSinComillas, valueSinComillas, length);
                }
            }
		}
	}
}

void generateCodeOperation(t_arbol *p, char * operation) {
	
	int auxx = getType((*p)->izq->info);
	
	if(auxx==1 || auxx==2 || auxx==3 ){
		printf("\tFLD %s\n .... es tipo 3 el getType", (*p)->izq->info);
		fprintf(file, "\tFLD %s\n", (*p)->izq->info);
		fprintf(file, "\tFLD %s\n", (*p)->der->info);
	}else{
		printf("\tFLD %s\n .... NO es tipo 3 el getType", (*p)->izq->info);
		fprintf(file, "\tFLD _%s\n", (*p)->izq->info);
		fprintf(file, "\tFLD _%s\n", (*p)->der->info);
	}

     if(strcmp(operation,"ADD") == 0) {
        fprintf(file, "\tFADD\n",  (*p)->info);
        strcpy((*p)->info, "ADD"); 
    } else if (strcmp(operation,"SUB") == 0) {
        fprintf(file, "\tFSUB\n",  (*p)->info);
        strcpy((*p)->info, "SUB"); 
    } else if (strcmp(operation,"MUL") == 0) {
        fprintf(file, "\tFMUL\n", (*p)->info);
        strcpy((*p)->info, "MUL"); 
    } else if (strcmp(operation,"DIV") == 0) {
        fprintf(file, "\tFDIV\n",  (*p)->info);
        strcpy((*p)->info, "DIV"); 
    }

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


char *eliminar_comillas(char *cadena) {
    char *cadena_temporal = malloc(strlen(cadena)+1);
    int j = 0;
	int i;
        for (i=0; i<strlen(cadena); i++) {
            switch (cadena[i]) {
                case '"': break;
                default:
                cadena_temporal[j] = cadena[i];
                j++;
            }
        }
    
    cadena_temporal[j] = '\0';
    return cadena_temporal;
}



void generateCondition(t_arbol *p) {    
    if (contadorSaltos > 0) {
        fprintf(file, "\t; Condition\n\tFLD %s\n\tFCOMP %s\n\tFSTSW AX\n\tSAHF\n",  (*p)->izq->info,  (*p)->der->info);
    } 
}