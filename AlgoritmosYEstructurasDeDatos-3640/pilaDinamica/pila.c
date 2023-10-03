#include "pila.h"

void crearPila(tPila *p)
{
    *p = NULL;
}
int pilaLlena(const tPila *p,unsigned tam)
{
    tNodo *aux = (tNodo*) malloc(sizeof(tNodo));
    void *info = malloc(tam);
    free(aux);
    free(info);
    return (aux ==NULL || info ==NULL);
}
int apilar(tPila* p, const void* d, unsigned tam)
{
    tNodo* nue;
    if((nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info,d,tam);
    nue->tamInfo=tam;
    nue->sig = *p;
    *p = nue;
    return 1;

}

int verTope(const tPila *p, void* d, unsigned tam)
{
    if(*p == NULL)
        return 0;
    memcpy(d,(*p)->info,minimo(tam,(*p)->tamInfo));
    return 1;
}
int pilaVacia(const tPila* p)
{
    return *p ==NULL;
}
int desapilar(tPila*p, void*d, unsigned tam)
{
    tNodo* aux = *p; // usamos nodo auxiliar por que de otra forma no puedo liberar la memoria
    if(*p == NULL)
        return 0;
    *p = aux->sig;

    memcpy(d,aux->info,minimo(aux->tamInfo,tam));
    free(aux->info);
    free(aux);

    return 1;
}
void vaciarPila(tPila* p)
{
    tNodo *aux;
    while(*p)
    {
        aux= *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}




