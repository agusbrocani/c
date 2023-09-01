#include "unidad0Repaso.h"
#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    int i;
    int resultado = 1;

    for ( i = 2 ; i <= n ; i++ )
    {
        resultado*=i;
    }

    return resultado;
}

int combinatoria(int m,int n)
{
    return factorial(m)/(factorial(n)*factorial(m-n)) ;
}

double eElevadoX(int x,double TOL)
{
    double resultado = 1.0;  // Primer término de la serie (n=0)
    double termino = 1.0;    // Término actual
    int n = 1;               // Índice del término actual

    while (         fabs(termino) > TOL         )
    {
        termino *= x / (double)n;
        resultado += termino;
        n++;
    }

    return resultado;
}

double raizCuadrada(double x, double TOL)
{
    double estimacionAnterior = x;  // Valor inicial de estimación
    double estimacionActual = (estimacionAnterior + x / estimacionAnterior) / 2.0;  // Primer término de la iteración

    while (          (estimacionActual - estimacionAnterior) > TOL           )
    {
        estimacionAnterior = estimacionActual;
        estimacionActual = (estimacionAnterior + x / estimacionAnterior) / 2.0;
    }

    return estimacionActual;
}

int perteneceAFibonacci(int x)
{
    int anterior=1;
    int posterior=1;
    int aux;

    if(1==x)
    {
        return x;
    }

    do
    {
        aux=posterior;
        posterior=anterior+posterior;
        anterior=aux;
        if(         x == anterior || x == posterior           )
        {
            return x;
        }
    }while(x>posterior);

    return 0;
}

double seno(double x, double TOL)   ///x en radianes
{
    double resultado = x;  // Primer término de la serie (n=0)
    double termino = x;    // Término actual
    int n = 1;             // Índice del término actual

    while (fabs(termino) > TOL)
    {
        termino *= -x * x / (double)((2 * n) * (2 * n + 1));
        resultado += termino;
        n++;
    }

    return resultado;
}

int perfectoDeficienteAbundante(int x)
{
    int suma=0;
    int i;

    printf("X=%d\n",x);

    for(i=1;i<x;i++)
    {
        if(     (0==(x%i))      )
        {
           suma+=i;
        }
    }

    return (x==suma)? 0 : (     (x<suma)?   1: -1   ) ;   //0-Perfecto 1-Abundante -1-Deficiente
}

int productoPorSumasSucesivas(int a, int b)
{
    int resultado=0;

    while(b)
    {
        resultado+=a;
        b--;
    }


    return resultado;
}

void cocienteYResto(int a,int b)
{
    printf("Cociente: %d\n",a/b);
    printf("Resto: %d\n",a%b);
}

int sumaDeLosNNrosNaturales10(int x)
{
    int suma = 0;
    int i;
    for (i = 1; i <= x; i++)
    {
        suma += i;
    }
    return suma;
}

int sumaDeLosNNrosNaturales11(int x)
{
    int suma = 0;
    int i;
    for (i = 2; i <= x * 2; i += 2)
    {
        suma += i;
    }

    return suma;
}

int sumaDeLosNNrosNaturales12(int x)
{
    int suma = 0;
    int i;
    for (i = 2; i < x; i += 2)
    {
        suma += i;
    }

    return suma;
}

int esPrimo(int x)
{
    int i;
    int contador=1;


    for(i=x-1;i>1;i--)
    {
        if(         0==x%i          )
        {
            contador++;
        }
    }

    if(1==contador)
    {
        return contador;    //es primo
    }
    else
    {
        return 0;           //no es primo
    }
}
