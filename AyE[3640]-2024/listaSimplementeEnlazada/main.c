#include "../Bibliotecas/include/listaSimplementeEnlazada/listaSimplementeEnlazada.h"

int comparaEnteros( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

void mostrarEntero( const void* dato )
{
    printf( "%d\t", *(int*)dato );
}

void acumulaProductos( void* dato, const void* aAcumular )
{
    strcpy( ( (tProducto*)dato )->proveedor , "NULL" );
}


int main()
{
    tLista lista;
//    int coleccion[] = {0,1,2,3,4,5,6,7,8,9};
    tProducto coleccion[CE_PRODUCTOS_A_INSERTAR + 1];
    tProducto dato =
    {
        "9999",
        "NULL",
        "NULL",
        {1, 1, 2024},
        {2, 1, 2024},
        50.0,
        100.0
    };

    int ce = sizeof( coleccion ) / sizeof( coleccion[0] );
    int tam = sizeof( coleccion[0] );
    int i;

    crearLista( &lista );

    cargarProductos( coleccion, CE_PRODUCTOS_A_INSERTAR );

    for( i = 0; i < ce - 1; i++ )
    {
        insertarOrdenado( &lista, &coleccion[i], tam, comparaProductosPorCodProd );
    }

    insertarEnPosicion( &lista, &dato, tam, 2 );

    //insertarColeccionEnListaAlFinal( &lista, coleccion, tam, ce );

    mostrarLista( &lista, mostrarProducto );

    verPrimero( &lista, &dato, tam );
    printf( "\nViendo primero:\n" );
    mostrarProducto( &dato );
    verUltimo( &lista, &dato, tam );
    printf( "\nViendo ultimo:\n" );
    mostrarProducto( &dato );

    printf( "Sacando primero:\n");
    sacarPrimero( &lista, &dato, tam );
    mostrarProducto( &dato );

    printf( "Sacando ultimo:\n");
    sacarUltimo( &lista, &dato, tam );
    mostrarProducto( &dato );

    vaciarLista( &lista );

    return 0;
}
