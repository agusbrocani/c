#include "unidad0.h"

int main()
{
    tPersona coleccion[] =
    {
        {5,"Pablo M",'M',5000},
        {4,"Karen B",'F',7500},
        {1,"Agustin Brocani",'M',8900},
        {3,"Franco Ruggieri",'M',6000},
        {2,"Federico Martucci",'M',8900}
    };

    int ce = sizeof( coleccion ) / sizeof( coleccion[0] );
    int tam = sizeof( coleccion[0] );

    ///EJERCICIO 1: IMPLEMENTAR TDA VECTOR[posee su propio proyecto]
    printf( "********************PUNTO 1********************\n" );
    printf( "TDA Vector: IMPLEMENTADO\n" );
    printf( "********************PUNTO 2********************\n" );
    ejercicio2( 2, 0 );
    printf( "\n\n********************PUNTO 3********************\n" );
    ejercicio3();
    printf( "\n\n********************PUNTO 4********************\n" );
    ejercicio4();
    printf( "\n\n********************PUNTO 5********************\n" );
    ejercicio5( coleccion, tam, ce, comparaPersonasPorID, grabarPersona );
    printf( "\n\n********************PUNTO 6********************\n" );
    ejercicio6( coleccion, tam, ce, comparaPersonasPorID, grabarPersona );
    printf( "\n\n********************PUNTO 7********************\n" );
    ejercicio7();

    return 0;
}
