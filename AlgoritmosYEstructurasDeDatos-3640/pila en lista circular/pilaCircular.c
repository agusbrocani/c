#include"pilaCircular.h"

void crearPila(tPila* p)
{
    *p = NULL;
}

int pilaVacia(const tPila* p)
{
    return *p ==NULL;
}

int pilaLlena(const tPila* p, unsigned tam)
{
    tNodo* nodo = (tNodo*)malloc(sizeof(tNodo));
    void* d = malloc(tam);
    free(nodo);
    free(d);
    return !nodo || !d;
}

int verTope(const tPila* p,void * d,unsigned tam)
{
    if(!(*p))
    {
        return 0;
    }
    memcpy(d,(*p)->sig->d,minimo(tam,(*p)->sig->tam));
    return 1;
}

int apilar(tPila* p, const void* d, unsigned tam)
{
    tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevoNodo)
    {
        return 0;
    }
    nuevoNodo->d = malloc(tam);
    if(!(nuevoNodo->d))
    {
        return 0;
    }
    memcpy(nuevoNodo->d,d,tam);
    nuevoNodo->tam = tam;

    if(!(*p))
    {
        *p = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = (*p)->sig;
    }
    (*p)->sig = nuevoNodo;
    return 1;
}

int desapilar(tPila* p, void* d, unsigned tam)
{
    tNodo* elim;

    if(!(*p))
    {
        return 0;
    }

    elim = (*p)->sig;
    memcpy(d,(*p)->sig->d,minimo(tam,(*p)->sig->tam));

    if(*p == (*p)->sig)
    {
        *p = NULL;
    }
    else
    {
        (*p)->sig = elim->sig;
    }
    free(elim->d);
    free(elim);


    return 1;
}

void vaciarPila(tPila*p)
{
    tNodo* elim;
    while(*p)
    {
        elim = (*p)->sig;
        if(*p == elim->sig)
        {
            *p = NULL;
        }
        else
        {
            (*p)->sig = elim->sig;
        }
        free(elim->d);
        free(elim);
    }
}



