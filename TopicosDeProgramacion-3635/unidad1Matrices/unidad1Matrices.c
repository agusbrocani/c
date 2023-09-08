#include "unidad1Matrices.h"
#include <stdio.h>
#include <stdlib.h>

void cargaLoteMatriz(float matriz[][N],int cf,int cc, int opcion)
{
    int f;
    int c;

    switch(opcion)
    {
        case 0:
            for( f = 0 ; f < N; f++ )
            {
                for( c = 0; c < N; c++ )
                {
                    matriz[f][c] = f*10 + c;  //Si modifico esto, debo modificar el %05.2f de mostrarMatrizCuadrada, ya que solamente me muestra 5 digitos[contando el punto]
                }
            }
        break;
        case 1:
            for( f = 0; f < N; f++ )
            {
                for( c = 0; c < N; c++ )
                {
                    if( f != c )
                    {
                        matriz[f][c] = 0;
                    }
                    if( f == c )
                    {
                        matriz[f][c] = 1;
                    }
                }
            }
        break;
        case 2:
            for( f = 0; f < cf; f++ )
            {
                for( c = 0; c < cc; c++ )
                {
                    matriz[f][c] = f*10 + c;
                }
            }
        break;
    }

}

void mostrarMatriz(float matriz[][N],int cf,int cc)
{
    int f;
    int c;

    printf("\nMatriz:\n");

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            printf("%05.2f\t", matriz[f][c] );
        }
        printf("\n");
    }
    printf("\n");

}
void mostrarMatrizEnteros(int matriz[][N],int cf,int cc)
{
    int f;
    int c;

    printf("\nMatriz:\n");

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            printf("%d\t", matriz[f][c] );
        }
        printf("\n");
    }
    printf("\n");

}
double unoPuntoDoceSumaTrianguloSuperiorSinDP(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for( f = 0; f < N-1; f++ )
    {
        for( c = f+1 ; c < N; c++ )
        {
            resultado += matriz[f][c];
        }
    }

    return resultado;
}
double unoPuntoDoceSumaTrianguloInferiorSinDP(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for( f = 0; f < N; f++ )
    {
        for( c = 0; c < f; c++ )
        {
            resultado += matriz[f][c];
        }
    }

    return resultado;
}

double unoPuntoDoceSumaTrianguloSuperiorDP(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for(f = 0; f < N; f++)
    {
        for(c = f ; c < N; c++)
        {
            resultado += matriz[f][c];
        }
    }

    return resultado;
}
double unoPuntoDoceSumaTrianguloInferiorDP(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for( f = 0; f < N; f++ )
    {
        for( c = 0; c <= f; c++ )
        {
            resultado += matriz[f][c];
        }
    }

    return resultado;
}

double unoPuntoDoceSumaTrianguloSuperiorSinDS(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;
    /*SOLUCIÓN FÁCIL
    for(f = 0; f < N ; f++)
    {
        for(c = 0; c < N ; c++)
        {
            if(         (f+c) < N-1           )
            {
                resultado+= matriz[f][c];
            }
        }
    }*/

    //SOLUCIÓN OPTIMIZADA
    for( f = 0; f < N-1; f++ )    //la ultima fila nunca la considero
    {
        for( c = 0; c < N - f -1; c++ )
        {
            resultado+= matriz[f][c];
        }
    }

    return resultado;
}

//es útil pararse al final y restarle desde donde necesite iniciar hasta menor a tamaño de la columna
double unoPuntoDoceSumaTrianguloInferiorSinDS(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for( f = 1; f < N; f++ )    //la primer fila nunca la considero
    {
        for( c = N-f; c < N; c++ )
        {
            resultado+= matriz[f][c];
        }
    }

    return resultado;
}

double unoPuntoDoceSumaTrianguloSuperiorDS(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for( f = 0; f < N; f++ )
    {
        for( c = 0; c < N - f; c++ )
        {
            resultado+= matriz[f][c];
        }
    }

    return resultado;
}
double unoPuntoDoceSumaTrianguloInferiorDS(float matriz[][N])
{
    double resultado = 0;
    int f;
    int c;

    for( f = 0; f < N; f++ )
    {
        for( c = N-f-1; c < N; c++ )
        {
            resultado+= matriz[f][c];
        }
    }

    return resultado;
}

double unoPuntoTreceTrazaDP(float matriz[][N])
{
    double resultado = 0;
    int f = N? N-1: 0;

    while(          f           )
    {
        resultado += matriz[f][f];
        f--;
    }

    return resultado;
}

double unoPuntoTreceTrazaDS(float matriz[][N])
{
    double resultado = 0;
    int f = 0;
    int c = N-1;

    while(          (c+1)          )    //+1 asi suma la posicion f = (N-1) c = 0
    {
        resultado += matriz[f][c];
        f++;
        c--;
    }

    return resultado;
}

int unoPuntoCatorceEsDiagonal(float matriz[][N])
{
    int f;
    int c;

    for( f = 0; f<N; f++ )
    {
        for( c = 0; c<N; c++)
        {
            if(         f != c && matriz[f][c]            ) //no es un elemento de la diagonal principal, y tenia un valor que no era 0
            {
                return 0;   //No es diagonal
            }
        }
    }

    return 1;
}

int unoPuntoQuinceEsDiagonal(float matriz[][N])
{
    int f;
    int c;

    for( f = 0; f<N; f++ )
    {
        for( c = 0; c<N; c++)
        {
            if(         f != c && matriz[f][c]            )
            {
                return 0;
            }

            if(         f == c && 1 != matriz[f][c]       )
            {
                return 0;
            }
        }
    }

    return 1;
}

int unoPuntoDieciseisEsSimetrica(float matriz[][N])
{
    int f;
    int c;

    for( f = 0; f<N; f++ )
    {
        for( c = 0; c<N; c++)
        {
            if(         f != c && matriz[f][c] != matriz[c][f]            )
            {
                return 0;
            }
        }
    }

    return 1;
}

void unoPuntoDiecisieteTrasponer(float matriz[][N])
{
    float aux;
    int f;
    int c;

    for( f = 0; f < N; f++ )
    {
        for( c = 0; c < f; c++ )
        {
            aux = matriz[f][c];
            matriz[f][c] = matriz[c][f];
            matriz[c][f] = aux;
        }
    }
}

void unoPuntoDieciochoDarTraspuesta(float matriz[][N],int cf,int cc)    //2x5 => 5X2
{
    float matrizResultante[N][N];   //5X5
    int f;
    int c;
    int fr;
    int cr;

    for( f = 0, cr = 0; f < cf; f++, cr++ )
    {
        for( c = 0, fr = 0; c < cc; c++, fr++ )
        {
            matrizResultante[fr][cr] = matriz[f][c];
        }
    }

    mostrarMatriz(matrizResultante,cc,cf);
}

void unoPuntoDiecinueveProducto(int matriz1[][N], int matriz2[][N], int cf1, int cc1, int cf2, int cc2) {

    int resultado[cf1][cc2];
    int f, c, k;

    if (cc1 != cf2)
    {
        printf("No se pueden multiplicar las matrices %d != %d. \n",cc1,cf2);
        return;
    }

    for (f = 0; f < cf1; f++)
    {
        for (c = 0; c < cc2; c++)
        {
            resultado[f][c] = 0;

            for (k = 0; k < cc1; k++)
            {
                resultado[f][c] += matriz1[f][k] * matriz2[k][c];
            }
        }
    }

    mostrarMatrizEnteros(resultado,cf1,cc2);
}


