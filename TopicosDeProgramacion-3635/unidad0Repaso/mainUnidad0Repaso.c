#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "unidad0Repaso.h"
#define SALIDA 0
#define ULTIMA_OPCION 13

int validaOpcion(int LI,int LS);

int main()
{
    //EJ 1,2
    int n;
    int m;
    //EJ 3,4,5
    int x;
    double xs;
    double TOL;
    //EJ 7
    int clasificacion;

    printf("0-Salir\n");
    printf("1-Calculo de factorial(n)\n");
    printf("2-Calculo de combinatoria(m n)\n");
    printf("3-Calculo de e^x\n");
    printf("4-Calculo de raiz cuadrada\n");
    printf("5-Pertenencia a serie de Fibonacci\n");
    printf("6-Calculo de seno(x)\n");
    printf("7-Clasificacion de un numero\n");
    printf("8-Producto por sumas sucesivas de dos numeros\n");
    printf("9-Cociente y resto\n");
    printf("10-Calcular la suma de los primeros N numeros naturales\n");
    printf("11-Calcular la suma de los primeros N numeros pares (menores o iguales a N)\n");
    printf("12-Calcular la suma de los numeros pares menores que N\n");
    printf("13-Determinar si un numero es primo\n");


    while(1)
    {
        switch(validaOpcion(SALIDA,ULTIMA_OPCION))
        {
            case 1:
                do
                {
                    printf("Ingrese un numero mayor o igual a 0 entero:\t");
                    scanf("%d",&n);
                }while(n<0);
                printf("\n");
                printf("Resultado:\t %d\n",factorial(n));
                break;
            case 2:
                do
                {
                    printf("Ingrese valor de n(un numero mayor o igual a 0 entero):\t");
                    scanf("%d",&n);
                }while(n<0);
                printf("\n");

                fflush(stdin);  ///PREGUNTAR: SI NO TENGO ESTA LINEA me va a tirar el resultado de una[algun tema con el buffer de entrada por el scanf]
                do
                {
                    printf("Ingrese valor de m(un numero mayor o igual a %d entero):\t",n);
                    scanf("%d",&m);
                }while(n>m);
                printf("\n");
                printf("Resultado:\t %d\n",combinatoria(m,n));
                break;
            case 3:

                printf("Ingrese valor de x(un numero entero)\t");
                scanf("%d",&x);
                printf("Ingrese valor de TOL:\t");
                scanf("%lf",&TOL);
                printf("\n");
                printf("Resultado:\t %.10lf\n",eElevadoX(x,TOL));
                break;
            case 4:
                do
                {
                    printf("Ingrese valor de x(un numero positivo entero)\t");
                    scanf("%d",&x);
                }while(x<0);
                printf("\n");
                printf("Ingrese valor de TOL:\t");
                scanf("%lf",&TOL);
                printf("\n");
                printf("Resultado:\t %.10lf\n",raizCuadrada(x,TOL));
                break;
            case 5:
                do
                {
                    printf("Ingrese valor de x(un numero positivo entero)\t");
                    scanf("%d",&x);
                }while(x<0);
                printf("\n");
                if(!perteneceAFibonacci(x))
                {
                    printf("El valor ingresado NO pertenece a la serie de Fibonacci\n");
                }
                else
                {
                    printf("El valor ingresado pertenece a la serie de Fibonacci\n");
                }
                break;
            case 6:
                printf("Ingrese valor de x(en RADIANES):\t");
                scanf("%lf",&xs);
                printf("Ingrese valor de TOL:\t");
                scanf("%lf",&TOL);
                printf("\n");

                printf("Resultado:\t %.10lf\n",seno(xs,TOL));
                break;
            case 7:
                do
                {
                    printf("Ingrese valor de x(un numero positivo entero mayor que 0)\t");
                    scanf("%d",&x);
                }while(x<=0);
                clasificacion=perfectoDeficienteAbundante(x);
                if(!clasificacion)
                {
                    printf("x es un numero PERFECTO\n");
                }

                if(1==clasificacion)
                {
                    printf("x es un numero ABUNDANTE\n");
                }

                if( (-1)==clasificacion)
                {
                    printf("x es un numero DEFICIENTE\n");
                }

                break;
            case 8:
                do
                {
                    printf("Ingrese valor 1(entero mayor o igual a 0):\t");
                    scanf("%d",&m);
                }while(m<0);

                do
                {
                    printf("Ingrese valor 2(entero mayor o igual a 0):\t");
                    scanf("%d",&n);
                }while(n<0);

                printf("Resultado:\t %d\n",productoPorSumasSucesivas(m,n));
                break;
            case 9:
                do
                {
                    printf("Ingrese valor 1(entero):\t");
                    scanf("%d",&m);
                }while(m<0);

                do
                {
                    printf("Ingrese valor 2(entero mayor a 0):\t");
                    scanf("%d",&n);
                }while(n<0);

                cocienteYResto(m,n);
                break;
            case 10:
                do
                {
                    printf("Ingrese valor de x(un numero mayor o igual a 0 entero):\t");
                    scanf("%d",&x);
                }while(x<0);

                printf("Resultado:\t %d\n",sumaDeLosNNrosNaturales10(x));
                break;
            case 11:
                do
                {
                    printf("Ingrese valor de x(un numero mayor o igual a 0 entero):\t");
                    scanf("%d",&x);
                }while(x<0);

                printf("Resultado:\t %d\n",sumaDeLosNNrosNaturales11(x));
                break;
            case 12:
                do
                {
                    printf("Ingrese valor de x(un numero mayor o igual a 0 entero):\t");
                    scanf("%d",&x);
                }while(x<0);

                printf("Resultado:\t %d\n",sumaDeLosNNrosNaturales12(x));
                break;
            case 13:
                do
                {
                    printf("Ingrese valor de x(un numero mayor a 0 entero):\t");
                    scanf("%d",&x);
                }while(x<=0);

                if(!esPrimo(x))
                {
                    printf("El numero ingresado NO es primo\n");
                }
                else
                {
                    printf("El numero ingresado es primo\n");
                }

                break;
            case SALIDA:
                system("pause");
                return 0;
        }
    }
}

int validaOpcion(int LI,int LS)
{
    int n;

    do
    {
        printf("Ingrese la opcion[valor de %d a %d]:\t",LI,LS);
        scanf("%d",&n);
    }while(n<LI||n>LS);

    printf("\n");

    return n;
}
