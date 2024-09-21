#include "unidad4.h"

int compararEnteros(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void mostrarEntero(const void* dato)
{
    printf("%d\t", *(int*)dato);
}

int main()
{
    t_lista lista;
//    int coleccion[] = {0,1,2,3,4,5,6,7,8,9};
    int coleccion[] = {5,4,1,3,2};
    int tam = sizeof(coleccion[0]);
    int ce = sizeof(coleccion) / sizeof(coleccion[0]);
    int i;
    int dato;

    crearLista(&lista);
    for(i = 0; i < ce; i++)
    {
        insertarAlFinal(&lista, &coleccion[i], tam);
//        insertarOrdenado(&lista, &coleccion[i], tam, compararEnteros);
    }

    ordenarLista(&lista, compararEnteros);

    mostrarListaEnOrden(&lista, mostrarEntero);

//    while(sacarUltimo(&lista, &dato, tam))
//    {
//        mostrarEntero(&dato);
//    }

    vaciarLista(&lista);

    return 0;
}
