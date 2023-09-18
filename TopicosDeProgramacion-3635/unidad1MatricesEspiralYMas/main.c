#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 50

void recorrido1(int mat[][MAX_COL],unsigned cf,unsigned cc);
void recorrido1I(int mat[][MAX_COL],unsigned cf,unsigned cc);
void recorridoHorarioEspiral(int mat[][MAX_COL],unsigned cf,unsigned cc);

int main()
{
    int matriz3x3[][MAX_COL] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriz4x4[][MAX_COL] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int matriz5x3[][MAX_COL] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    };
//    int mat10x10[][MAX_COL] =
//    {
//        { 1, 2, 3, 4, 5, 6, 7, 8, 9,10},
//        {11,12,13,14,15,16,17,18,19,20},
//        {21,22,23,24,25,26,27,28,29,30},
//        {31,32,33,34,35,36,37,38,39,40},
//        {41,42,43,44,45,46,47,48,49,50},
//        {51,52,53,54,55,56,57,58,59,60},
//        {61,62,63,64,65,66,67,68,69,70},
//        {71,72,73,74,75,76,77,78,79,80},
//        {81,82,83,84,85,86,87,88,89,90},
//        {91,92,93,94,95,96,97,98,99,100}
//    };


    printf("Matriz 1:\n");
    recorridoHorarioEspiral(matriz3x3, 3, 3);

    printf("\nMatriz 2:\n");
    recorridoHorarioEspiral(matriz4x4, 4, 4);

    printf("\nMatriz 3:\n");
    recorridoHorarioEspiral(matriz5x3, 5, 3);

    return 0;
}


void recorrido1(int mat[][MAX_COL],unsigned cf,unsigned cc)
{
    int f;
    int cp;
    int ci;

    printf("\n");

    for( f = 0; f < cf; f++)
    {
        if(0 == (f % 2))    //hago la pregunta 1 vez por fila
        {
           for( cp = 0; cp < cc; cp++ )
            {
                printf("%d\t",mat[f][cp]);
            }
        }
        else
        {
            for( ci = (cc - 1); ci >= 0; ci--)
            {
                printf("%d\t",mat[f][ci]);
            }
        }
        printf("\n");
    }
}

void recorrido1I(int mat[][MAX_COL],unsigned cf,unsigned cc)
{
    int f;
    int cp;
    int ci;

    printf("\n");

    for( f = 0; f < cf; f++)
    {
        if(0 != (f % 2))    //hago la pregunta 1 vez por fila
        {
           for( cp = 0; cp < cc; cp++ )
            {
                printf("%d\t",mat[f][cp]);
            }
        }
        else
        {
            for( ci = (cc - 1); ci >= 0; ci--)
            {
                printf("%d\t",mat[f][ci]);
            }
        }
        printf("\n");
    }
}

void recorridoHorarioEspiral(int mat[][MAX_COL],unsigned cf,unsigned cc)
{
    int f;
    int c;
    int inicioFila = 0;
    int inicioColumna = 0;
    int finFila = cf - 1;
    int finColumna = cc - 1;

    while(          inicioFila <= finFila && inicioColumna <= finColumna            )
    {
        for( c = inicioColumna; c <= finColumna; c++ )
        {
            printf("%d ",mat[inicioFila][c]);
        }

        inicioFila++;

        for( f = inicioFila; f <= finFila; f++ )
        {
            printf("%d ",mat[f][finColumna]);
        }

        finColumna--;

        if ( inicioFila <= finFila )
        {
            for (c = finColumna; c >= inicioColumna; c--)
            {
                printf("%d ", mat[finFila][c]);
            }
            finFila--;
        }

        if ( inicioColumna <= finColumna )
        {
            for ( f = finFila; f >= inicioFila; f--)
            {
                printf("%d ", mat[f][inicioColumna]);
            }
            inicioColumna++;
        }

    }

}

