#include <stdio.h>
#include <stdlib.h>
#include "unidad1Matrices.h"

int main()
{                                                       //opcion de inicializacion
    float matriz [N][N];               //0
    float esDiagonal [N][N] = {{0}};
    float esIdentidad [N][N];          //1
    float rectangular[TAM_FILA][N];    //2
    int matEnteros1[TAM_FILA][N] = {{1,2,3,4,5},{6,7,8,9,10}};
    int matEnteros2[N][N] = {{1,2,3,4,5},{7,8,9,10,11},{13,14,15,16,17},{19,20,21,22,23},{25,26,27,28,29}};
    int matCorrecta[][N] =
    {
        { 0, 4, 1},
        { 1, 0, 6},
        { 4, 0, 0},
    };
    int matIncorrecta[][N] =
    {
        { 0, 0, 2},
        { 0, 0, 0},
        { 0, 0, 0},
    };

    cargaLoteMatriz(matriz,N,N,0);
    cargaLoteMatriz(esIdentidad,N,N,1);
    cargaLoteMatriz(rectangular,TAM_FILA,N,2);
    mostrarMatriz(matriz,N,N);
    printf("\nDIAGONAL PRINCIPAL:\n");
    printf("RESULTADO TRIANGULO SUPERIOR[para DIAGONAL PRINCIPAL (sin incluir)] = %.2f\n" ,unoPuntoDoceSumaTrianguloSuperiorSinDP(matriz)    );
    printf("RESULTADO TRIANGULO INFERIOR[para DIAGONAL PRINCIPAL (sin incluir)] = %.2f\n" ,unoPuntoDoceSumaTrianguloInferiorSinDP(matriz)    );
    printf("RESULTADO TRIANGULO SUPERIOR[para DIAGONAL PRINCIPAL (incluida)] = %.2f\n" ,unoPuntoDoceSumaTrianguloSuperiorDP(matriz)    );
    printf("RESULTADO TRIANGULO INFERIOR[para DIAGONAL PRINCIPAL (incluida)] = %.2f\n" ,unoPuntoDoceSumaTrianguloInferiorDP(matriz)    );

    printf("\nDIAGONAL SECUNDARIA:\n");
    printf("RESULTADO SUMA TRIANGULO SUPERIOR[para DIAGONAL SECUNDARIA (sin incluir)] = %.2f\n" ,unoPuntoDoceSumaTrianguloSuperiorSinDS(matriz)    );
    printf("RESULTADO SUMA TRIANGULO INFERIOR[para DIAGONAL SECUNDARIA (sin incluir)] = %.2f\n" ,unoPuntoDoceSumaTrianguloInferiorSinDS(matriz)    );
    printf("RESULTADO TRIANGULO SUPERIOR[para DIAGONAL SECUNDARIA (incluida)] = %.2f\n" ,unoPuntoDoceSumaTrianguloSuperiorDS(matriz)    );
    printf("RESULTADO TRIANGULO INFERIOR[para DIAGONAL SECUNDARIA (incluida)] = %.2f\n" ,unoPuntoDoceSumaTrianguloInferiorDS(matriz)    );

    printf("\nTrazas:\n");
    printf("RESULTADO SUMA DIAGONAL PRINCIPAL[Traza DP] = %.2f\n",unoPuntoTreceTrazaDP(matriz)    );
    printf("RESULTADO SUMA DIAGONAL SECUNDARIA[Traza DS] = %.2f\n",unoPuntoTreceTrazaDS(matriz)    );


    printf("\nEs diagonal?:\n");
    if(         !unoPuntoCatorceEsDiagonal(esDiagonal)          )
    {
        printf("La matriz NO es diagonal.\n");
    }
    else
    {
        printf("La matriz es diagonal.\n");
    }

    printf("\nEs identidad?:\n");
    mostrarMatriz(esIdentidad,N,N);

    if(         !unoPuntoQuinceEsDiagonal(esIdentidad)         )
    {
        printf("La matriz NO es identidad.\n");
    }
    else
    {
        printf("La matriz es identidad.\n");
    }

    printf("\nEs simetrica?\n");

    if(         !unoPuntoDieciseisEsSimetrica(esIdentidad)          )
    {
        printf("La matriz NO es simetrica.\n");
    }
    else
    {
        printf("La matriz es simetrica.\n");
    }

    printf("\nAntes Traspuesta:");
    mostrarMatriz(matriz,N,N);
    unoPuntoDiecisieteTrasponer(matriz);
    printf("Traspuesta:");
    mostrarMatriz(matriz,N,N);

    mostrarMatriz(rectangular,TAM_FILA,N);
    printf("Dar traspuesta de una matriz:");
    unoPuntoDieciochoDarTraspuesta(rectangular,TAM_FILA,N);

    mostrarMatrizEnteros(matEnteros1,TAM_FILA,N);
    mostrarMatrizEnteros(matEnteros2,N,N);
    unoPuntoDiecinueveProducto(matEnteros1,matEnteros2,TAM_FILA,N,N,N);

    mostrarMatrizEnteros(matCorrecta,ORDEN,ORDEN);

    if(         !unoPuntoVeinteEquipos(matCorrecta,ORDEN)            )
    {
        printf("Matriz generada incorrectamente.\n");
    }
    else
    {
        printf("Matriz generada correctamente.\n");
        puntosPorEquipo(matCorrecta);
    }

    mostrarMatrizEnteros(matIncorrecta,ORDEN,ORDEN);

    if(         !unoPuntoVeinteEquipos(matIncorrecta,ORDEN)            )
    {
        printf("Matriz generada incorrectamente.\n");
    }
    else
    {
        printf("Matriz generada correctamente.\n");
        puntosPorEquipo(matIncorrecta);
    }

    return 0;
}
