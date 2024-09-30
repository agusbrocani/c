#include "../../include/listaCircular/listaCircular.h"

void crearListaCircular(t_lista* pl)
{
    *pl = NULL;
}

int insertarSegundoEnListaCircular(t_lista* pl, const void* dato, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(t_nodo));
    if(NULL == nuevoNodo)
    {
        return NO_PUDE_INSERTAR;
    }
    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
    {
        free(nuevoNodo);
        return NO_PUDE_INSERTAR;
    }
    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;

    if(NULL == *pl)
    {
        *pl = nuevoNodo;
        nuevoNodo->sig = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = (*pl)->sig;
        (*pl)->sig = nuevoNodo;
    }

    return OK;
}

int sacarSiguienteDelPrimeroListaCircular(t_lista* pl, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar;

    if(NULL == *pl)
    {
        return NO_HAY_ELEMENTOS;
    }

    nodoAEliminar = (*pl)->sig;
    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));
    if(*pl == nodoAEliminar)
    {
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
        *pl = NULL;
        return OK;
    }

    (*pl)->sig = nodoAEliminar->sig;
    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}

void vaciarListaCircular(t_lista *pl)
{
    t_nodo** nodoInicial = pl;
    t_nodo* nodoAEliminar;

    if(NULL == *nodoInicial)
    {
        return;
    }

    while(*nodoInicial != (*pl)->sig)
    {
        nodoAEliminar = (*pl)->sig;
        (*pl)->sig = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
    }
    free((*nodoInicial)->dato);
    free(*nodoInicial);
    *nodoInicial = NULL;
}

int listaCircularVacia(const t_lista *pl)
{
    return NULL == *pl;
}

void mostrarListaCircular(const t_lista* pl, void (*mostrar)(const void* dato))
{
    t_nodo* nodoInicial = *pl;

    if(NULL == nodoInicial)
    {
        return;
    }

    mostrar((*pl)->dato);
    printf("\n");
    pl = &((*pl)->sig);
    while(nodoInicial != *pl)
    {
        mostrar((*pl)->dato);
        printf("\n");
        pl = &((*pl)->sig);
    }
}

int cambiarNodosDeLugarEnListaCircular(t_lista* pl)
{
    t_nodo* aux;

    if(NULL == *pl || *pl == (*pl)->sig)
    {
        return NO_HIZO_CAMBIO;
    }

    if(*pl == (*pl)->sig->sig)
    {
        *pl = (*pl)->sig;
        return OK;
    }

    aux = (*pl)->sig;
    (*pl)->sig = aux->sig;
    aux->sig = (*pl)->sig->sig;
    (*pl)->sig->sig = aux;

    return OK;
}
