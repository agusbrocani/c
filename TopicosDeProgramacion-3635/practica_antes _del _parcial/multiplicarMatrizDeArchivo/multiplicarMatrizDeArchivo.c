#include "multiplicarMatrizDeArchivo.h"

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        perror("No pude abrir/crear el archivo");
        return 0;
    }
    return 1;
}

void crearLote()
{
    FILE* pf;

    int mat[MAX_FILAS][MAX_COLUMNAS] =
    {
        { 1, 2, 3, 4, 5},
        { 6, 0, 7, 8, 9},
        {10,11,12,13,14},
        {15,16,17,18,19}
    };

    int mat2[MAX_FILAS][MAX_COLUMNAS] =
    {
        { 1, 2, 3, 4},
        { 6, 0, 7, 8},
        {10,11,12,13},
        {15,16,17,18},
        {15,16,17,18}
    };
    int cf = 4;
    int cc = 5;
    int f;
    int c;

    pf = fopen("matriz1.txt","wt");

    if(         !pf         )
    {
        return;
    }

    fprintf( pf,"%d|%d\n", cf, cc );
    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            if(         0 != mat[f][c]           )
            {
                fprintf( pf,"%d|%d|%d\n",f, c, mat[f][c] );
            }
        }
    }
    fclose(pf);

    cf = 5;
    cc = 4;

    pf = fopen("matriz2.txt","wt");

    if(         !pf         )
    {
        return;
    }

    fprintf( pf,"%d|%d\n", cf, cc );
    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            if(         0 != mat2[f][c]           )
            {
                fprintf( pf,"%d|%d|%d\n",f, c, mat2[f][c] );
            }
        }
    }
    fclose(pf);
}

void mostrarMatriz( int mat[][MAX_COLUMNAS], int cantFilas, int cantColumnas )
{
    int f;
    int c;

    printf("\n");
    for( f = 0; f < cantFilas; f++ )
    {
        for( c = 0; c < cantColumnas; c++ )
        {
            printf("%02d\t", mat[f][c]);
        }
        printf("\n");
    }
}

void productoDeMatriz( int matriz1[][MAX_COLUMNAS], int matriz2[][MAX_COLUMNAS], int matResultados[][MAX_COLUMNAS], int cantFilas, int cantColumnas, int cantFilas2, int cantColumnas2 )
{
    int f;
    int c;
    int k;

    if (            cantColumnas != cantFilas2          )
    {
        printf("No se pueden multiplicar las matrices %d != %d. \n", cantColumnas, cantFilas2);
        return;
    }

    for ( f = 0; f < cantFilas; f++ )
    {
        for ( c = 0; c < cantColumnas2; c++ )
        {
            matResultados[f][c] = 0;

            for (k = 0; k < cantColumnas; k++)
            {
                matResultados[f][c] += matriz1[f][k] * matriz2[k][c];
            }
        }
    }
}
