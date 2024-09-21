#include "listaSimple.h"

void crearLista(t_lista* pl)
{
    *pl = NULL;
}
int insertarAlFinal(t_lista* pl, const void* dato, unsigned tam)
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


int sacarUltimo(t_lista* pl, void* dato, unsigned tam)
{
    if(NULL == *pl)
    {
        return NO_HAY_ELEMENTOS;
    }

    while((*pl)->sig)
    {
        pl = &((*pl)->sig);
    }

    memcpy(dato, (*pl)->dato, MENOR(tam, (*pl)->tam));

    free((*pl)->dato);
    free(*pl);
    *pl = NULL;

    return OK;
}

void vaciarLista(t_lista* pl)
{
    t_nodo* nodoAEliminar = *pl;

    while(nodoAEliminar)
    {
        *pl = nodoAEliminar->sig;
        free(nodoAEliminar->dato);
        free(nodoAEliminar);
        nodoAEliminar = *pl;
    }
}

//int insertarOrdenadoSinDuplicados(t_lista* pl, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b))
//{
//    t_nodo* nuevoNodo;
//
//    while(*pl && comparar(dato, (*pl)->dato) > 0)
//    {
//        pl = &((*pl)->sig);
//    }
//
//    if(!*pl || comparar(dato, (*pl)->dato) < 0)
//    {
//        nuevoNodo = malloc(sizeof(t_nodo));
//        if(NULL == nuevoNodo)
//        {
//            return NO_PUDE_INSERTAR;
//        }
//
//        nuevoNodo->dato = malloc(tam);
//        if(NULL == nuevoNodo->dato)
//        {
//            free(nuevoNodo);
//            return NO_PUDE_INSERTAR;
//        }
//
//        memcpy(nuevoNodo->dato, dato, tam);
//        nuevoNodo->tam = tam;
//        nuevoNodo->sig = *pl;
//        *pl = nuevoNodo;
//    }
//
//    return OK;
//}

int insertarOrdenado(t_lista *pl, const void *dato, unsigned tam, int (*cmp)(const void *, const void *))
{
    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
        return 0;

    nue->dato = malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    // cargo el nuevo nodo con los datos
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;

    // si la lista está vacía o el dato es menor que mi tope, inserto al inicio
    if(!(*pl) || cmp(dato, (*pl)->dato) < 0)
    {
        nue->sig = *pl;
        *pl = nue;
        return 1;
    }

    // sino, recorro la lista hasta encontrar donde insertar mi nodo
    while((*pl)->sig && cmp(dato, (*pl)->sig->dato) > 0)
    {
        pl = &(*pl)->sig;
    }

    //inserto el nodo. Qué pasa si es el ultimo nodo de la lista? nue->sig va a quedar con (*pl)->sig que es = NULL.
    nue->sig = (*pl)->sig;
    (*pl)->sig = nue;

    return 1;
}

void mostrarListaEnOrden(const t_lista* pl, void (*mostrar)(const void* dato))
{
    while(*pl)
    {
        mostrar((*pl)->dato);
        pl = &((*pl)->sig);
    }
}

t_nodo** buscarMenor(t_lista* pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo** menor = pl;

    if(NULL == *menor)
    {
        return NULL;
    }

    pl = &((*pl)->sig);
    while(*pl)
    {
        if(comparar((*menor)->dato,(*pl)->dato) > 0)
        {
            menor = pl;
        }

        pl = &((*pl)->sig);
    }

    return menor;
}

//printf("MENOR = %d\n\n", *(int*)((*buscarMenor(pl, comparar))->dato));
void ordenarLista(t_lista* pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo** menor;
    t_nodo* aux;

    if(NULL == *pl)
    {
        return;
    }

    while((*pl)->sig)
    {
        menor = buscarMenor(pl, comparar);
        if(menor && comparar((*menor)->dato, (*pl)->dato) < 0)
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











