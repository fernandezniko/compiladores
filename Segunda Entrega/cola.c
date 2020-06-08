#include "cola.h"

void crearCola(t_cola *p)
{
    p->pri = NULL ;
    p->ult = NULL ;
}

void vaciarCola(t_cola *p)
{
    c_nodo *aux ;

    while(p->pri)
    {   aux = p->pri ;
        p->pri = aux->sig ;
        free(aux) ;
    }
    p->ult = NULL ;

}

int colaLlena(const t_cola *p)
{
    c_nodo *aux = (c_nodo *)malloc(sizeof(c_nodo)) ;
    free(aux) ;
    return aux == NULL ;
}

int colaVacia(const t_cola *p)
{
    return p->pri == NULL ;
}

int ponerEnCola(t_cola *p , char* i)
{
    c_nodo *nue = (c_nodo *)malloc(sizeof(c_nodo)) ;
    if(nue == NULL)
        return 0 ;

    nue->info = i;
    nue->sig = NULL ;
    if(p->pri == NULL)
        p->pri = nue ;
    else
        p->ult->sig = nue ;
    p->ult = nue ;

    return 1 ;
}

char* sacarDeCola(t_cola *p)
{
	char* str1;
    c_nodo *aux ;
    if(p->pri == NULL)
        return 0 ;

    aux = p->pri ;
    str1 = strdup(aux->info);
    p->pri = aux->sig ;
    free(aux) ;
    if(p->pri == NULL)
        p->ult = NULL ;

    return str1 ;
}

int verPrimeroCola(const t_cola *p , char* i)
{
    if(p->pri == NULL)
        return 0 ;
    
	i = p->pri->info ;

    return 1 ;
}




















/*
void crearCola(t_cola *p)
{
    p->pri = NULL ;
    p->ult = NULL ;
}

void vaciarCola(t_cola *p)
{
    c_nodo *aux ;
    while( p->pri )
    {
        aux = p->pri ;
        p->pri = aux->sig ;
        free(aux) ;
    }
    p->ult = NULL ;
}

int colaLlena(const t_cola *p)
{
    c_nodo *aux = (c_nodo *)malloc(sizeof(c_nodo)) ;
    free(aux) ;
    return aux == NULL ;
}

int colaVacia(const t_cola *p)
{
    return p->pri == NULL ;
}

int verPrimeroCola(const t_cola *p , t_info *d)
{
    if(p->pri == NULL)
        return 0 ;
    *d = p->pri->info ;

    return 1 ;
}

int ponerEnCola(t_cola *p , const t_info *d)
{
    c_nodo *nue = (c_nodo *)malloc(sizeof(c_nodo)) ;
    if(nue == NULL)
        return 0 ;

    nue->info = *d ;
    nue->sig = NULL ;

    if(p->pri == NULL)
        p->pri = nue ;
    else
        p->ult->sig = nue ;

    p->ult = nue ;

    return 1 ;
}

int sacarDeCola(t_cola *p , t_info *d)
{
    c_nodo *aux ;
    if(p->pri == NULL)
        return 0 ;

    aux = p->pri ;
    *d = aux->info ;
    p->pri = aux->sig ;
    if(p->pri == NULL)
        p->ult = NULL ;
    return 1 ;
}
*/
