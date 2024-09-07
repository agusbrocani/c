#include "./clase3.h"

#define NO_PUDE_RESERVAR_MEMORIA -1

void mostrarEntero(const void* dato)
{
    printf("%d\t",*(int*)dato);
}

void mostrar(const void* coleccion, unsigned tam, unsigned ce, void (*mostrarDato)(const void* dato))
{
    int i;

    for(i = 0; i < ce; i++)
    {
        mostrarDato(coleccion);
        coleccion += tam;
    }
}

int main()
{
    t_pila pila;
    int coleccion[] = {0,1,2,3,4,5,6,7,8,9};
    int ce = sizeof(coleccion)/sizeof(coleccion[0]);
    int tam = sizeof(int);
    int i;
    void* dato;

    dato = malloc(tam);

    if(!dato)
    {
        return NO_PUDE_RESERVAR_MEMORIA;
    }


    crearPila(&pila);

    for(i = 0; i < ce; i++)
    {
        apilar(&pila, &coleccion[i], tam);
    }

    if(verTope(&pila, &coleccion[i], tam))
    {
        mostrarEntero(dato);
    }

//    while(desapilar(&pila, dato, tam))
//    {
//        mostrarEntero(dato);
//        printf("\n");
//    }


    vaciarPila(&pila);
    free(dato);

    return 0;
}
