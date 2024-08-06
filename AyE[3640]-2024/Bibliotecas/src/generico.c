#include "../include/generico.h"

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        perror("No pude abrir/crear archivo");
        return 0;
    }

    return 1;
}


void mostrarColeccion( const void* dato, int tam, int ce, void (*mostrar)( const void* dato ) )
{
    int i;

    printf("Mostrando coleccion:\n");
    for( i = 0; i < ce; i++ )
    {
        mostrar( dato );
        printf("\n");
        dato += tam;
    }
}
