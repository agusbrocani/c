#include"cola.h"

void crearCola(tCola* c)
{
    *c = NULL;
}

int colaVacia(const tCola* c)
{
    return *c ==NULL;
}

int colaLlena(const tCola* c, unsigned tam)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    void* d = malloc(tam);
    free(nue);
    free(d);
    return (!nue || !d);
}

int acolar(tCola* c,const void*d, unsigned tam)
{
    tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevoNodo)
    {
        return 0;
    }
    nuevoNodo->d = malloc(tam);

    if(!(nuevoNodo->d))
    {
        free(nuevoNodo);
        return 0;
    }
    memcpy(nuevoNodo->d,d,tam);
    nuevoNodo->tam = tam;

    //ahora viene lo interesante, que le asignamos al siguiente??

    if(*c == NULL)
    {
        nuevoNodo->sig = nuevoNodo; // el primero es igual al ultimo pues hay un solo elemento
    }
    else
    {
        nuevoNodo->sig = (*c)->sig; //el siguiente del nuevo ultimo sera el primero, esta bien
        (*c)->sig = nuevoNodo; // el siguiente del viejo ultimo sera el nuevo ultimo, esta bien
    }
    (*c) = nuevoNodo; // nuevoNodo sera el ultimo
    return 1;
}

int desacolar(tCola* c,void *d, unsigned tam)
{
    tNodo* elim;
    if(*c == NULL)
    {
        return 0;
    }
    elim = (*c)->sig; // queremos eliminar el primero
    memcpy(d,elim->d,minimo(elim->tam,tam));
    if(*c == elim) // el ultimo es igual al primero hay un solo elemento
    {
        *c = NULL;
    }
    else//actualizamos el nuevo primero
    {
        (*c)->sig = elim->sig;
    }



    free(elim->d);
    free(elim);
    return 1;
}

int verPrimero(const tCola*c , void*d , unsigned tam)
{
    if(*c == NULL)
    {
        return 0;
    }
    memcpy(d,(*c)->sig->d,minimo(tam,(*c)->sig->tam)); //el primero es el (*c)->sig entonces (*c) es el ultimo
    return 1;
}

void vaciarCola(tCola* c)
{
    tNodo* elim;
    while(*c)
    {
        elim = (*c)->sig; //vaciamos desde el primero
        if(*c == elim)
        {
            *c = NULL;
        }
        else
        {
            (*c)->sig = elim->sig;
        }
        free(elim->d);
        free(elim);
    }
}

void vaciarColaRecursivo(tCola* c)
{
    tNodo* elim;
    if(*c)
    {
        elim = (*c)->sig; //vaciamos desde el primero
        if(*c == elim)
        {
            *c = NULL;
        }
        else
        {
            (*c)->sig = elim->sig;
        }
        free(elim->d);
        free(elim);
        vaciarCola(c);
    }
}


