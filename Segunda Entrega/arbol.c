#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include <string.h>
#define CLAVE_DUP 0
#define SIN_MEMO 0
#define TODO_OK 1

void crear_arbol(t_nodo2 **r)
{
    *r = NULL;
}

t_arbol *crearHoja(char *d)
{
    t_arbol *p;
    p = (t_nodo2 **)malloc(sizeof(t_nodo2 *));
    *p = (t_nodo2 *)malloc(sizeof(t_nodo2));
    if (p == NULL)
    {
        printf("sin memeoria");
        return 0;
    }
    strcpy((*p)->info, d);

    (*p)->izq = NULL;
    (*p)->der = NULL;
    return p;
}

t_arbol *crearNodo(char *d, t_arbol izqptr, t_arbol derptr)
{
    t_arbol *p;
    p = (t_nodo2 **)malloc(sizeof(t_nodo2 *));
    *p = (t_nodo2 *)malloc(sizeof(t_nodo2));
    if (p == NULL)
    {
        printf("sin memeoria");
        return 0;
    }
    fflush(stdin);
    strcpy((*p)->info, d);
    fflush(stdin);

    if (izqptr)
    {
        (*p)->izq = izqptr;
    }
    else
    {
        (*p)->izq = NULL;
    }
    if (derptr)
    {
        (*p)->der = derptr;
    }
    else
    {
        (*p)->der = NULL;
    }
    return p;
}

void enOrden(t_arbol *p)
{
    if (*p)
    {
        enOrden(&(*p)->izq);

        verNodo((*p)->info);
        grabar((*p)->info);
        enOrden(&(*p)->der);
    }
}

void postOrden(t_arbol *p)
{
    if (*p)
    {
        postOrden(&(*p)->izq);
        postOrden(&(*p)->der);
        grabar((*p)->info);
        verNodo((*p)->info);
    }
}

void grabar(const char *p)
{
    fprintf(pf, "%s ", p);
}

void verNodo(const char *p)
{
    printf("%s ", p);
}

void vaciarArbol(t_arbol *p)
{
    if (*p)
    {
        vaciarArbol(&(*p)->izq);
        vaciarArbol(&(*p)->der);
        free(*p);
        free(p);
        *p = NULL;
        p = NULL;
    }
}

t_arbol *hijoMasIzq(t_arbol *p)
{
    if (*p)
    {
        if ((*p)->izq)
            return hijoMasIzq(&(*p)->izq);
        else
            return p;
    }
    return NULL;
}
