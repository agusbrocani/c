#include "cola.h"

void crearCola(tCola *c) //igualo todo a null
{
    c->pri = NULL;
    c->ult = NULL;
}

int acolar(tCola* c,const void* d, size_t tam)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0;
    }

    nue->info = malloc(tam);

    if(!(nue->info))
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    nue->sig = NULL;
    memcpy(nue->info,d,tam);

    if(c->pri == NULL) //caso especial para cuando la cola rsta vacia
    {
        c->pri = nue;
    }
    else
    {
        c->ult->sig = nue;
    }

    c->ult = nue;

    return 1;
}

int desacolar(tCola* c, void* d,size_t tam)
{
    tNodo *aux = c->pri;
    if(!aux)
    {
        return 0;
    }

    memcpy(d,aux->info,minimo(tam,aux->tam));

    c->pri = aux->sig;
    free(aux->info);
    free(aux);

    if(!(c->pri)) //esto es para no dejar basura en el ult pero no es realmente necesario
    {
        c->ult = NULL;
    }

    return 1;
}

int colaVacia(const tCola*c)
{
    return c->pri == NULL;
}

int verPrimero(const tCola *c,void *d, size_t tam)
{
    if(!(c->pri))
    {
        return 0;
    }
    memcpy(d,c->pri->info,minimo(tam,c->pri->tam));
    return 1;
}

void vaciarCola(tCola *c)
{
    tNodo *aux;

    while(c->pri)
    {
        aux = c->pri;
        c->pri = aux->sig;
        free(aux->info);
        free(aux);

    }
}

int colaLlena(const tCola* c, size_t tam)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    void* info = malloc(tam);
    free(info);
    free(nue);
    return !(nue || info);
}
