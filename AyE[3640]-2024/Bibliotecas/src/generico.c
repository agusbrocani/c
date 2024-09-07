#include "../include/generico.h"

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        fprintf(stderr,"No pude abrir/crear el archivo: %s\n", nombreArchivo);
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

void grabar( FILE* pf, const void* dato, void (*grabarSegunEstrategia)( FILE* pf, const void* dato ) )
{
    grabarSegunEstrategia( pf, dato );
}
