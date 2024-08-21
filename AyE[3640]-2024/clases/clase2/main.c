#include "./Biblioteca/include/Dinamica/pila.h"
//#include "./Biblioteca/include/Estatica/pila.h"
#include "./Biblioteca/include/lote.h"

#define NO_PUDE_CARGAR_PILA -1
#define NO_PUDE_RESERVAR_MEMORIA_PARA_DATO 1

int cargarLoteAPila( tPila* pila, const void* coleccion, unsigned tam, unsigned ce )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        if( !apilar( pila, coleccion, tam ) )
        {
            return NO_PUDE_CARGAR_PILA;
        }
        coleccion += tam;
    }

    return OK;
}

int main()
{
    tEmpleado coleccion[] =
    {
        { 5, "Pablo M", 'M', 5000 },
        { 4, "Karen B", 'F', 7500.5 },
        { 1, "Agustin Brocani", 'M', 8900.75 },
        { 3, "Franco Ruggieri", 'M', 15000.2 },
        { 2, "Federico Martucci", 'M', 10000 }
    };
    unsigned opcionAGrabar = T_EMPLEADO;

//    int coleccion[] = {0,1,2,3,4,5,6,7,8,9};
//    unsigned opcionAGrabar = T_ENTERO;

    tPila pila;
    void* dato;
    unsigned ce = sizeof( coleccion ) / sizeof( coleccion[0] );
    unsigned tam = sizeof( coleccion[0] );

    dato = malloc( tam );
    if( !dato )
    {
        return NO_PUDE_RESERVAR_MEMORIA_PARA_DATO;
    }

    crearPila( &pila );

    if( NO_PUDE_CARGAR_PILA == cargarLoteAPila( &pila, coleccion, tam, ce ) )
    {
        vaciarPila( &pila );
        free( dato );
        return NO_PUDE_CARGAR_PILA;
    }

    if( verTope( &pila, dato, tam ) )
    {
        printf( "Viendo tope:\n" );
        grabar( stdout, dato, opcionAGrabar );
        printf( "*****************************" );
    }

    while( desapilar( &pila, dato, tam ) )
    {
        grabar( stdout, dato, opcionAGrabar );
    }

    printf( "\nTESTEANDO pilaVacia:" );
    if( pilaVacia( &pila ) )
    {
        printf( "\n*****************************" );
        printf( "\n\tPILA VACIA\n");
        printf( "*****************************\n" );
    }
    else
    {
        printf( "\n*****************************" );
        printf( "\n\tHAY LUGAR\n");
        printf( "*****************************\n" );
    }

    printf( "\nTESTEANDO pilaLlena:" );
    if( !pilaLlena( &pila, tam ) )
    {
        printf( "\n*****************************" );
        printf( "\n\tHAY LUGAR\n");
        printf( "*****************************\n" );
    }
    else
    {
        printf( "\n*****************************" );
        printf( "\n\tPILA LLENA\n");
        printf( "*****************************\n" );
    }

    vaciarPila( &pila );
    free( dato );

    return 0;
}
