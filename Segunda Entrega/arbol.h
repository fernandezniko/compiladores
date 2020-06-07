#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    char info[100];

    struct s_nodo *izq;
    struct s_nodo *der;
} t_nodo2;

typedef t_nodo2 *t_arbol;

t_arbol *Tptr;
t_arbol *Fptr;
t_arbol *Eptr;
t_arbol *E1ptr;
t_arbol *Aptr;
t_arbol *ProgPtr;
t_arbol *SentPtr;
t_arbol *CondPtr;
t_arbol *Decptr;
t_arbol *Auxptr;
t_arbol *ifPtr;
t_arbol *BloqPtr;
t_arbol *constNumPtr;

FILE *pf;

void grabar(const char *p);
void crear_arbol(t_nodo2 **);
t_arbol *crearHoja(char *);
t_arbol *crearNodo(char *, t_arbol, t_arbol);
t_arbol *hijoMasIzq(t_arbol *);

void enOrden(t_arbol *);
void postOrden(t_arbol *);
void verNodo(const char *);
void vaciarArbol(t_arbol *);

#endif // ARBOL_H_INCLUDED
