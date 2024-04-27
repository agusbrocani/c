#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    tCola colaDePrueba;

    crearCola(&colaDePrueba);

/*
    tCola colaDeNumeros;
    crearCola(&colaDeNumeros);
    int numero = 5;
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
*/

    char letra = 'a';
    char cadena[] = "xbcd";

    acolar( &colaDePrueba, &letra, sizeof(letra)+ 1 );  //+1 para \0
    letra = 'o';
    acolar( &colaDePrueba, &letra, sizeof(letra)+ 1 );

    desacolar( &colaDePrueba, &letra, sizeof(letra)+ 1 );
    desacolar( &colaDePrueba, &letra, sizeof(letra)+ 1 );

    acolar( &colaDePrueba, cadena, sizeof(cadena) );
    acolar( &colaDePrueba, &letra, sizeof(letra)+ 1 );

    desacolar( &colaDePrueba, &letra, 1 );

    acolar( &colaDePrueba, cadena, sizeof(cadena) );
    desacolar( &colaDePrueba, cadena, 1 );
    printf("%c\n", letra);

    system("pause");
    return 0;
}
