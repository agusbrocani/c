#include "unidad1VectoresGen.h"

/*
tam = tamaño del tipo de dato del dato
ce = cantidad de elementos del vector
pos = posicion de insercion del elemento en el vector
*/

char validaOpcion(char opcion)
{

    if(         !( 'I' == opcion || 'C' == opcion )        )
    {
       return 0;
    }

    return opcion;
}

size_t miStrlen(const char* cadena)
{
    size_t cantidadCaracteres = 0;

    while(          '\0' != *cadena         )
    {
        cantidadCaracteres++;
        cadena++;
    }

    return cantidadCaracteres;
}

void mostrarDatoEntero(void* vec)
{
    printf( "%d\t",*(int*)vec );
}

void mostrarDatoChar(void* vec)
{
    printf( "%c\t",*(char*)vec );
}

void mostrarVector(void* vec,unsigned tam,unsigned ce,void (*mostrar) (void* vec) )
{
    int i;

    printf("\n");
    for( i = 0; i < ce; i++)
    {
        mostrar(vec+(i*tam));
    }
    printf("\n");
}

void insertarEnPosicion(void* vec, void* dato,unsigned tam,unsigned ce, unsigned pos)
{
    if(         0 < pos && pos > (ce-1)          )
    {
        printf("\nNo se realizo ninguna insercion, posicion invalida.\n");
        return;
    }

    memcpy( ( vec + pos*tam ) , dato, tam );
}
