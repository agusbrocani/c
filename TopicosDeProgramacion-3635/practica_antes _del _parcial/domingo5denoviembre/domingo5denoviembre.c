#include "domingo5denoviembre.h"

void mostrarInt( const void* data )
{
    printf("%02d\t", *(int*)data );
}

void mostrarMatriz( const void* data, size_t tam, int cf, int cc, void (*mostrar)( const void* data ) )
{
    int f;
    int c;

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            mostrar( data );
            data += tam;
        }
        printf("\n");
    }

}

void cargarMatriz( int mat[][MAX_COLUMNAS], size_t tam, int cf, int cc )
{
    int f;
    int c;

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            mat[f][c] = f * 10 + c;
        }
    }
}
