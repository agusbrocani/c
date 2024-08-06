#include "bibliotecaGeneralDeCola.h"

int main()
{
    tCola cola;
    //int coleccion[] = {0,1,2,3,4,5,6,7,8,9};
    tProducto coleccion[] =
    {
      {"5","9","3",{1,1,2000},{26,7,2024},50,100},
      {"4","9","3",{1,1,2000},{26,7,2024},50,100},
      {"1","9","3",{1,1,2000},{26,7,2024},50,100},
      {"3","9","3",{1,1,2000},{26,7,2024},50,100},
      {"2","9","3",{1,1,2000},{26,7,2024},50,100}
    };

    int ce = sizeof(coleccion)/sizeof( coleccion[0] );
    int tam = sizeof( coleccion[0] );
    int i;
    tProducto dato;
    //int dato;

    crearCola( &cola );

    for( i = 0; i < ce; i++ )
    {
        acolar( &cola, &coleccion[i], tam );
    }

    if(         verPrimero( &cola, &dato, tam )         )
    {
        printf("Viendo primero:\n");
        grabarProductos( stdout, &dato );
    }


    printf( "Desacolando:\n" );
    while(          desacolar( &cola, &dato, tam )         )
    {
        grabarProductos( stdout, &dato );
    }

    if(         colaVacia( &cola )            )
    {
        printf("\nLa cola esta vacia\n");
    }

    vaciarCola( &cola );

    return 0;
}
