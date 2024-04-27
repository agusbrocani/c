#include "parcialMartes.h"

int main()
{
    ///PUNTO 1
    int vec[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int clave = 0;
    int tam = sizeof(int);
    int ce = sizeof(vec)/sizeof(int);
    int* resultado;
    ///PUNTO 2
    FILE* lote;
    ///PUNTO 3
    int mat[MAX_FILAS][MAX_COLUMNAS];
    int cf = MAX_FILAS;
    int cc = MAX_COLUMNAS;
    tRetorno retorno = { "", 0 };

    ///PUNTO 1
    if(         ! ( resultado = _bbinaria( &clave, vec, ce, tam, cmpInt ) )            )
    {
        printf("Resultado no encontrado\n");
        return 0;
    }

    printf( "Resultado de la busqueda: %d\n", *resultado );

    ///PUNTO 2
    crearLote();
    if(         !abrirArchivo( &lote ,"lote.txt", "rt" )         )
    {
        return 1;
    }

    printf( "Cantidad de palabras en el archivo de texto: %d\n", _contarPalabras( lote, &retorno ) );
    printf("Palabra mas larga: %s\n", retorno.palabra );
    printf("Cantidad de apariciones: %d\n", retorno.cantidadDeOcurrencias );

    fclose( lote );

    ///PUNTO 3

    inicializarMatriz( mat );
    printf("Resultado de la suma del Triangulo inferior entre diagonales: %d\n", sumTrianInfEntreDiag( mat, cf, cc ) );
    printf("Resultado de la suma del Triangulo derecho entre diagonales: %d\n", sumTrianDerEntreDiag( mat, cf, cc ) );

    mostrarMatriz( mat, tam, cf, cc, mostrarInt );
    elRelojCucu( mat, cf, cc );

//    int mat2[10][10];
//
//    for( int f = 0; f < 10; f++ )
//    {
//        for( int c = 0; c < 10; c++ )
//        {
//            mat2[f][c] = f*10 + c;
//        }
//    }
//    mostrarMatriz( mat2, tam, 10, 10, mostrarInt );


    return 0;
}


//#define ELEMENTOS 100
///* Prototipo de la función de comparar */
//int comparar(const void *arg1, const void *arg2)
//{
// if(*(int *)arg1 < *(int *)arg2) return -1;
// else if(*(int *)arg1 > *(int *)arg2) return 1;
// else return 0;
//}
//int main()
//{
// int i, num;
// int lista[ELEMENTOS];
// int *elementoPtr;
//
// /* Contenido aleatorio */
// for(i = 0; i < ELEMENTOS; i++) lista[i] = rand() % 100 + 1;
// /* Quick-Sort */
// qsort(lista, ELEMENTOS, sizeof(lista[0]), comparar);
// /* Mostramos la lista ordenada */
// for(i = 0; i < ELEMENTOS; i++) printf("%d ", lista[i]);
// printf("\n");
// /* Ahora busquemos algunos elementos en la lista */
// puts( "Especifique un numero a encontrar dentro de la lista ordenada\n(un numero negativo para salir):" );
// scanf( "%d", &num );
//
//     while( num >= 0 )
//     {
//         if( (elementoPtr = bsearch( &num, lista, ELEMENTOS, sizeof(lista[0]), comparar)) != NULL )
//            printf( "Encontrado: %d\n", *elementoPtr );
//         else
//            printf( "No encontrado: %d\n", num );
//         scanf( "%d", &num );
//    }
//
// return 0;
//}
///* FIN DE EJEMPLO */
