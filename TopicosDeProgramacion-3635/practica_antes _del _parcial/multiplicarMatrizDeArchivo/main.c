#include "multiplicarMatrizDeArchivo.h"

int main()
{
    FILE* matriz;
    int cantFilas;
    int cantColumnas;
    int cantFilas2;
    int cantColumnas2;
    int contenido;
    int f;
    int c;
    char buffer[TAM];
    int mat[MAX_FILAS][MAX_COLUMNAS] = {{0}};
    int mat2[MAX_FILAS][MAX_COLUMNAS] = {{0}};
    int matResultados[MAX_FILAS][MAX_COLUMNAS] = {{0}};

    crearLote();

    if(         !abrirArchivo( &matriz,"matriz1.txt", "rt" )         )
    {
        return 1;
    }

    fgets( buffer, sizeof(buffer), matriz);
    sscanf( buffer , "%d|%d", &cantFilas, &cantColumnas );

    while(          fgets( buffer, sizeof(buffer), matriz)           )
    {
        sscanf( buffer , "%d|%d|%d", &f, &c, &contenido );
        mat[f][c] = contenido;
    }

    fclose( matriz );

    if(         !abrirArchivo( &matriz,"matriz2.txt", "rt" )         )
    {
        return 1;
    }

    fgets( buffer, sizeof(buffer), matriz);
    sscanf( buffer , "%d|%d", &cantFilas2, &cantColumnas2 );

    while(          fgets( buffer, sizeof(buffer), matriz)           )
    {
        sscanf( buffer , "%d|%d|%d", &f, &c, &contenido );
        mat2[f][c] = contenido;
    }

    fclose( matriz );

    mostrarMatriz( mat, cantFilas, cantColumnas);
    mostrarMatriz( mat2, cantFilas2, cantColumnas2);

    productoDeMatriz( mat, mat2, matResultados, cantFilas, cantColumnas, cantFilas2, cantColumnas2 );

    if(         !abrirArchivo( &matriz,"resultados.txt", "wt")         )
    {
        return 1;
    }

    fprintf( matriz,"%d|%d\n", cantFilas, cantColumnas2 );
    for( f = 0; f < cantFilas; f++ )
    {
        for( c = 0; c < cantColumnas2; c++ )
        {
            if(         0 != matResultados[f][c]           )
            {
                fprintf( matriz,"%d|%d|%d\n",f, c, matResultados[f][c] );
            }
        }
    }
    printf("\nResultado:");
    mostrarMatriz( matResultados, cantFilas, cantColumnas2 );
    fclose( matriz );

    return 0;
}
