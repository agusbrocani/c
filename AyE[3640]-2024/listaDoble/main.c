#include "listaDoble.h"

typedef struct
{
    int numero;
    int suma;
}tEnteros;

int compararEnteros(const void* a, const void* b)
{
    return ((tEnteros*)a)->numero - ((tEnteros*)b)->numero;
}

void mostrarEntero(const void* dato)
{
    printf("Numero: %d\nAcumulado: %d\n",
           ((tEnteros*)dato)->numero,
           ((tEnteros*)dato)->suma
           );
}

void acumularEnteros(void* dato, const void* datoAAcumular)
{
    ((tEnteros*)dato)->suma += (((tEnteros*)datoAAcumular)->numero);
}

int main()
{
    tEnteros coleccion[] =
    {
        {1,1}
    };
//    tEnteros coleccion[] =
//    {
//        {1,1},
//        {4,4},
//        {3,3},
//        {7,7},
//        {5,5},
//        {6,6},
//        {1,1},
//        {1,1},
//        {1,1},
//        {1,1},
//        {8,1},
//        {9,9},
//        {2,2},
//        {1,1},
//        {1,1},
//        {1,1},
//        {0,0}
//    };
//    tEnteros coleccion[] =
//    {
//        {1,1},
//        {1,1},
//        {1,1},
//        {1,1},
//        {1,1},
//        {1,1},
//        {1,1},
//        {1,1}
//    };
    unsigned tam = sizeof(coleccion[0]);
    unsigned ce = sizeof(coleccion) / sizeof(coleccion[0]);
    int i;
    t_listaDoble lista;
//    tEnteros dato;
    tEnteros clave = {1,0};

    crearListaDoble(&lista);

    for(i = 0; i < ce; i++)
    {
        insertarOrdenadoConAccionEnRepetidosEnListaDoble(&lista, &coleccion[i], tam, compararEnteros, acumularEnteros);
    }

    if(!eliminarDeListaDoble(&lista, tam, &clave, compararEnteros))
    {
        printf("\nNO PUDE ELIMINAR.\n");
    }
    mostrarListaDobleIzqDer(&lista, mostrarEntero);

    vaciarListaDoble(&lista);

    return 0;
}
