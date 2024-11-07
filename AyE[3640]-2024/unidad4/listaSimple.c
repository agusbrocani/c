#include "listaSimple.h"

void crearListaSimple(t_lista* pl)
{
    *pl = NULL;
}

int listaSimpleVacia(const t_lista* pl)
{
    return NULL == *pl;
}

int listaSimpleLlena(const t_lista* pl)
{
    return HAY_LUGAR;
}

void vaciarListaSimple(t_lista* pl)
{
    t_nodo* nodoAEliminar;

    while(*pl)
    {
        nodoAEliminar = *pl;
        *pl = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
    }
}

int insertarAlFinalEnListaSimple(t_lista* pl, const void* dato, unsigned tam)
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

    while(*pl)
    {
        pl = &((*pl)->sig);
    }

    memcpy(nuevoNodo->dato, dato, tam);
    nuevoNodo->tam = tam;
    nuevoNodo->sig = *pl;

    *pl = nuevoNodo;

    return OK;
}

int insertarPrimeroEnListaSimple(t_lista* pl, const void* dato, unsigned tam)
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
    nuevoNodo->sig = *pl;

    *pl = nuevoNodo;

    return OK;
}

int sacarPrimeroEnListaSimple(t_lista* pl, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar;

    if(!*pl)
    {
        return LISTA_VACIA;
    }
    nodoAEliminar = *pl;
    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));

    *pl = nodoAEliminar->sig;

    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}

int sacarUltimoEnListaSimple(t_lista* pl, void* dato, unsigned tam)
{
    t_nodo* nodoAEliminar;

    if(!*pl)
    {
        return LISTA_VACIA;
    }

    while((*pl)->sig)
    {
        pl = &((*pl)->sig);
    }

    nodoAEliminar = *pl;

    memcpy(dato, nodoAEliminar->dato, MENOR(nodoAEliminar->tam, tam));

    *pl = nodoAEliminar->sig;

    free(nodoAEliminar->dato);
    free(nodoAEliminar);

    return OK;
}

void mostrarListaSimpleEnOrden(const t_lista* pl, void (*mostrar)(const void* dato))
{
    while(*pl)
    {
        mostrar((*pl)->dato);
        pl = &((*pl)->sig);
    }
}

void mostrarListaSimpleEnOrdenInversoRecursivo(const t_lista* pl, void (*mostrar)(const void* dato))
{
    if(*pl)
    {
        mostrarListaSimpleEnOrdenInversoRecursivo(&((*pl)->sig), mostrar);
        mostrar((*pl)->dato);
    }
}

void mapEnListaSimple(const t_lista* pl, void* recursos, void (*accion)(void* dato, void* recursos))
{
    while(*pl)
    {
        accion((*pl)->dato, recursos);
        pl = &((*pl)->sig);
    }
}

void filter(const t_lista* pl, const void* clave, void* recursos, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* recursos))
{
    while(*pl)
    {
        if(!comparar((*pl)->dato, clave))
        {
            accion((*pl)->dato, recursos);
        }
        pl = &((*pl)->sig);
    }
}

int insertarOrdenadoEnListaSimpleSinDuplicados(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* datoDuplicado))
{
    t_nodo* nuevoNodo;

    while(*pl && comparar((*pl)->dato, dato) < 0)
    {
        pl = &((*pl)->sig);
    }

    if(!*pl || comparar((*pl)->dato, dato))
    {
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
        nuevoNodo->sig = *pl;

        *pl = nuevoNodo;
    }
    else
    {
        accion((*pl)->dato, (void*)dato);
    }

    return OK;
}

t_nodo** buscarMenor(t_lista* pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo** menor;

    if(!*pl)
    {
        return NULL;
    }

    menor = pl;
    while((*pl)->sig)
    {
        pl = &((*pl)->sig);
        if(comparar((*menor)->dato, (*pl)->dato) > 0)
        {
            menor = pl;
        }
    }

    return menor;
}

void ordenarListaSimple(t_lista* pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo** menor;
    t_nodo* aux;

    while(*pl)
    {
        menor = buscarMenor(pl, comparar);
        if(comparar((*menor)->dato, (*pl)->dato) < 0)
        {
            aux = *pl;
            *pl = *menor;
            *menor = aux;

            aux = (*pl)->sig;
            (*pl)->sig = (*menor)->sig;
            (*menor)->sig = aux;
        }

        pl = &((*pl)->sig);
    }
}

void eliminarDuplicadosEnListaSimpleConAccion(t_lista* pl, void* recursos, int (*comparar)(const void* a, const void* b), void (*accion)(void* dato, void* recursos))
{
    t_nodo* actual = *pl;
    t_nodo* nodoAEliminar;
    t_nodo* anterior;
    t_nodo* siguiente;

    while (actual && actual->sig)
    {
        anterior = actual;
        siguiente = actual->sig;

        while (siguiente)
        {
            if (!comparar(actual->dato, siguiente->dato))
            {
                nodoAEliminar = siguiente;
                anterior->sig = siguiente->sig; // Saltar el nodo duplicado
                accion(nodoAEliminar->dato, recursos);
                free(nodoAEliminar->dato);
                free(nodoAEliminar);

                // Continuar con el siguiente nodo
                siguiente = anterior->sig;
            }
            else
            {
                // Avanzar solo si no se eliminó el nodo
                anterior = siguiente;
                siguiente = siguiente->sig;
            }
        }
        actual = actual->sig; // Pasar al siguiente nodo base para comparar
    }
}











