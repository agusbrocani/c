///Fariello Ramiro, Monges Omar, Quiroga Piegari Lucila,  Odriozola Ignacio,  Sierra Jazmín y Brocani Agustín.
#include "clase5.h"

void mostrarCaracter(const void* dato)
{
    printf("%c\n", *(char*)dato);
}

int main()
{
    t_lista lista;
    char coleccion[] = {'A','B','C','D','E','F'};
//    char coleccion[] = {'A','B'};
//    char coleccion[] = {'A'};
//    char coleccion[] = {};
    unsigned tam = sizeof(coleccion[0]);
    unsigned ce = sizeof(coleccion) / sizeof(coleccion[0]);
    int i;

    crearLista(&lista);

    for(i = 0; i < ce; i++)
    {
        insertarAlFinal(&lista, &coleccion[i], tam);
    }

    printf("Mostrar Lista Simple en Orden Inverso Recursiva:\n");
    mostrarListaEnOrdenInversoR(&lista, mostrarCaracter);
    printf("\nMostrar Lista Simple en Orden Inverso Iterativa:\n");
    mostrarListaEnOrdenInverso(&lista, mostrarCaracter);

    vaciarLista(&lista);

    return 0;
}
