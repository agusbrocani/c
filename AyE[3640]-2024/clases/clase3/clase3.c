#include "./clase3.h"

void crearPila(t_pila* p)//p es un tNodo**
{
    *p = NULL;
}

int pilaVacia(const t_pila* p)
{
    return NULL == *p;
}

//Programo esto para mantener la compatibilidad, porque casi siempre voy a tener memoria
//int pilaLlena(const t_pila* p, unsigned tam)
//{
//    return HAY_LUGAR;
//}

int pilaLlena(const t_pila* p, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = (t_nodo*)malloc(sizeof(t_nodo));
    if(NULL == nuevoNodo)
    {
        return PILA_LLENA;
    }

    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
    {
        free(nuevoNodo);
        return PILA_LLENA;
    }

    free(nuevoNodo->dato);
    free(nuevoNodo);

    return HAY_LUGAR;
}

int apilar(t_pila* p, const void* dato, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(t_nodo));
    if(NULL == nuevoNodo)
    {
        return NO_HAY_LUGAR;
    }
    nuevoNodo->dato = malloc(tam);
    if(NULL == nuevoNodo->dato)
    {
        free(nuevoNodo);
        return NO_HAY_LUGAR;
    }

    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *p;
    *p = nuevoNodo;

    return OK;
}

int desapilar(t_pila* p, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar = *p;

    if(NULL == nodoAEliminar)
    {
        return PILA_VACIA;
    }

    memcpy(dato, nodoAEliminar->dato, MINIMO(nodoAEliminar->tam, tam));

    *p = nodoAEliminar->sig;

    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}

int verTope(const t_pila* p, void* dato, unsigned tam)
{
    if(NULL == *p)
    {
        return PILA_VACIA;
    }

    memcpy(dato, (*p)->dato, MINIMO((*p)->tam,tam));

    return OK;
}

void vaciarPila(t_pila* p)
{
    t_nodo* nodoAEliminar = *p;

    while(NULL != nodoAEliminar)
    {
        *p = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
        nodoAEliminar = *p;
    }
}





