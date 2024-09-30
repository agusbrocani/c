#include "ordenarListaSimple.h"

void mostrarProducto(const void* dato)
{
    printf("Codigo: %d\nCantidad: %d\nPrecio: %.2f\n\n",
           ((tProducto*)dato)->codigo,
           ((tProducto*)dato)->cantidad,
           ((tProducto*)dato)->precio
          );
}

int comparaProductos(const void* a, const void* b)
{
    return ((tProducto*)a)->codigo - ((tProducto*)b)->codigo;
}

t_nodo** buscarMenor (t_lista *pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo** menor = pl;

    while(*pl)
    {
        pl = &((*pl)->sig);

        if((*pl) && comparar((*pl)->dato,(*menor)->dato)<0)
        {
            menor = pl;
        }
    }
    return menor;
}

void ordenarLista (t_lista *pl, int (*comparar)(const void* a, const void* b))
{
    t_nodo** menor;
    t_nodo* aux;

    while(*pl)
    {
        menor = buscarMenor(pl,comparar);
        if(comparar((*menor)->dato,(*pl)->dato) != 0)
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
