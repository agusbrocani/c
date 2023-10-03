#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    int numero = 5;
    tCola colaDeNumeros;
    crearCola(&colaDeNumeros);
    acolar(&colaDeNumeros,&numero,sizeof(int));
    numero--;
    acolar(&colaDeNumeros,&numero,sizeof(int));
    numero--;
    acolar(&colaDeNumeros,&numero,sizeof(int));
    numero--;
    acolar(&colaDeNumeros,&numero,sizeof(int));
    numero--;
    acolar(&colaDeNumeros,&numero,sizeof(int));
    numero--;
    verPrimero(&colaDeNumeros,&numero,sizeof(int));
    printf("el primero es: %d\n ",numero);


    while(desacolar(&colaDeNumeros,&numero,sizeof(int)))
    {
        printf("%d ",numero);
    }

    if(colaVacia(&colaDeNumeros))
        printf("\nLa cola esta vacia!");
    if(colaLlena(&colaDeNumeros,sizeof(int)))
        printf("\nLa cola esta llena");
    else
        printf("\nTodavia se puede ingresar elementos a la cola");
    printf("\n\n");
    system("pause");
    return 0;
}
