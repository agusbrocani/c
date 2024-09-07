#include "./clase4.h"

//    int dato = 5;
//    free(&dato);  //NO PUEDO LIBERAR MEMORIA ESTATICA!!!

#define NO_PUDE_RESERVAR_MEMORIA -1

void mostrarEntero(const void* dato)
{
    printf("%d\t",*(int*)dato);
}

void mostrar(const void* dato, void(*mostrarDato)(const void* dato))
{
    mostrarDato(dato);
}

int main()
{
    t_cola cola;
    int coleccion[] = {0,1,2,3,4,5,6,7,8,9};
    int ce = sizeof(coleccion)/sizeof(coleccion[0]);
    int tam = sizeof(coleccion[0]);
    void* mostrarDato = mostrarEntero;
    void* dato;
    int i;

    dato = malloc(tam);
    if(NULL == dato)
    {
        return NO_PUDE_RESERVAR_MEMORIA;
    }

    crearCola(&cola);

    for(i = 0; i < ce; i++)
    {
        acolar(&cola, &coleccion[i], tam);
    }

    if(verPrimero(&cola, dato, tam))
    {
        mostrar(dato, mostrarDato);
        printf("\n");
    }

    while(desacolar(&cola, dato, tam))
    {
        mostrar(dato, mostrarDato);
    }

    free(dato);
    vaciarCola(&cola);

    return 0;
}
