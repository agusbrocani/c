#include "../include/lote.h"

void grabarEmpleado( FILE* pf, const void* dato )
{
    fprintf( pf, "\nID: %d\nNya: %s\nSexo: %c\nSalario: %.02f\n\n",
               ((tEmpleado*)dato)->id,
               ((tEmpleado*)dato)->nya,
               ((tEmpleado*)dato)->sexo,
               ((tEmpleado*)dato)->salario
            );
}

void grabarEntero( FILE* pf, const void* dato )
{
    fprintf( stdout, "%02d\n", *(int*)dato );
}

void grabar( FILE* pf, const void* dato, int opcion )
{
    switch( opcion )
    {
        case T_ENTERO:
            grabarEntero( stdout, dato );
        break;
        case T_EMPLEADO:
            grabarEmpleado( stdout, dato );
        break;
    }
}

void mostrarColeccion( const void* coleccion, unsigned tam, unsigned ce, void (*mostrar)( const void* dato ) )
{
    int i;

    printf( "\nMostrando coleccion:\n\n" );
    for( i = 0; i < ce; i++ )
    {
        mostrar( coleccion );
        coleccion += tam;
    }
}
