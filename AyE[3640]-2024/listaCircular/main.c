#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    void* dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crear(t_lista* pl)
{
    *pl = NULL;
}
#define NO_PUDE_RESERVAR_MEMORIA 0
#define OK 1
int insertarSegundoEnListaCircular(t_lista* pl, const void* dato, unsigned tam)
{
    t_nodo* nuevoNodo;

    nuevoNodo = malloc(sizeof(t_nodo));
    if(!nuevoNodo)
    {
        fprintf(stderr, "No pude reservar memoria.\n");
        return NO_PUDE_RESERVAR_MEMORIA;
    }

    nuevoNodo->dato = malloc(tam);
    if(!nuevoNodo->dato)
    {
        fprintf(stderr, "No pude reservar memoria.\n");
        free(nuevoNodo);
        return NO_PUDE_RESERVAR_MEMORIA;
    }
    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;

    if(!*pl)
    {
        nuevoNodo->sig = nuevoNodo;
        *pl = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = (*pl)->sig;
        (*pl)->sig = nuevoNodo;
    }

    return OK;
}

#define LISTA_VACIA 0
#define MENOR(X,Y) (((X) < (Y)) ? (X) : (Y))
int sacarSiguienteDelPrimeroListaCircular(t_lista* pl, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar;

    if(!*pl)
    {
        return LISTA_VACIA;
    }

    if((*pl)->sig != *pl)
    {
        nodoAEliminar = (*pl)->sig;
        (*pl)->sig = nodoAEliminar->sig;
    }
    else
    {
        nodoAEliminar = *pl;
        *pl = NULL;
    }

    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));
    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}
void vaciarListaCircular(t_lista *pl)
{
    t_nodo* nodoAEliminar;

    if(!*pl)
    {
        return;
    }

    while(*pl != (*pl)->sig)
    {
        nodoAEliminar = (*pl)->sig;
        (*pl)->sig = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
    }

    free((*pl)->dato);
    free((*pl));
    *pl = NULL;
}
int listaCircularVacia(const t_lista *pl)
{
    return 0;
}
void mostrarListaCircular(const t_lista* pl, void (*mostrar)(const void* dato))
{

}

void mostrarEntero(const void* dato)
{
    printf("%d ", *(int*)dato);
}

int main()
{
    t_lista listaCircular;
    int coleccion[] = {1,2,3,4,5};
    int tam = sizeof(coleccion[0]);
    int ce = sizeof(coleccion)/sizeof(coleccion[0]);
    int i;
    int dato;

    crear(&listaCircular);

    for(i = 0; i < ce; i++)
    {
        insertarSegundoEnListaCircular(&listaCircular, &coleccion[i], tam);
    }

    while(sacarSiguienteDelPrimeroListaCircular(&listaCircular, &dato, tam))
    {
        mostrarEntero(&dato);
    }

    vaciarListaCircular(&listaCircular);

    return 0;
}
