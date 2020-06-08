#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct c_nodo
{
    char* info;
    struct c_nodo *sig ;

}c_nodo ;

typedef struct
{
    c_nodo *pri,
           *ult ;

}t_cola ;

void crearCola(t_cola *p) ;
void vaciarCola(t_cola *p) ;
int colaLlena(const t_cola *p) ;
int colaVacia(const t_cola *p) ;
int ponerEnCola(t_cola *p , char* i) ;
char* sacarDeCola(t_cola *p) ;
int verPrimeroCola(const t_cola *p , char* i) ;

#endif // COLA_H_INCLUDED
