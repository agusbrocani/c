#include "funciones.h"

void opciones()
{
    printf( "\nMenu:\n" );
    printf( "0-Salir\n" );
    printf( "1-Punto 1\n" );
    printf( "2-Punto 2\n" );
    printf( "3-Punto 3\n" );
    printf( "4-Punto 4\n" );
    printf( "5-Punto 5\n" );
    printf( "6-Punto 6\n" );
    printf( "7-Punto 7\n" );
    printf( "8-Punto 8\n" );
    printf( "9-Punto 9\n" );
    printf( "10-Punto 10\n" );
    printf( "11-Punto 11\n" );
    printf( "12-Punto 12\n" );
    printf( "13-Punto 13\n" );
    printf( "14-Punto 14\n\n" );
}

int ingresaOpcion()
{
    int opcion;

    do
    {
        printf( "\nIngrese opcion:\t" );
        scanf( "%d", &opcion );
        fflush( stdin );
    }while(         !( opcion >= LI && opcion <= LS )           );

    return opcion;
}



/**
1- Crear/cargar Pila1 por teclado con 5 elementos.
Poner los primeros tres elementos de la PilaAux1 y
los restantes a otra PilaAux2, ambas inicializadas en null/vacias.

*/

void ejercicio1()
{
    tPila pila1;
    tPila pilaAux1;
    tPila pilaAux2;
    int ingreso;
    int tam = sizeof( int );
    int i;

    crearPila( &pila1 );
    crearPila( &pilaAux1 );
    crearPila( &pilaAux2 );

    printf( "\nIngrese %d elementos:\n", CE_MAX_PILA );

    for( i = 0; i < CE_MAX_PILA; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );

        if(         i < ELEMENTOS_A_APILAR_PRIMERA_PILA           )
        {
            apilar( &pilaAux1, &ingreso, tam );
        }
        else
        {
            apilar( &pilaAux2, &ingreso, tam );
        }

        apilar( &pila1, &ingreso, tam );
    }

    printf( "\nDesapilando pilaAux1:\n" );
    while(          desapilar( &pilaAux1, &ingreso, tam )          )
    {
        printf( "Desapilando: %d\n", ingreso );
    }

    printf( "\nDesapilando pilaAux2:\n" );
    while(          desapilar( &pilaAux2, &ingreso, tam )          )
    {
        printf( "Desapilando: %d\n", ingreso );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaAux1 );
    vaciarPila( &pilaAux2 );

    printf( "\n***********FINALIZANDO EJERCICIO 1***********\n" );
    system( "pause" );
    system( "cls" );
}

/**
2- Cargar PilaOrigen por teclado e inicializar en vacio PilaDestino.
Pasar todos los elementos de PilaOrigen a la PilaDestino.
*/
void ejercicio2()
{
    tPila pilaOrigen;
    tPila pilaDestino;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;

    crearPila( &pilaOrigen );
    crearPila( &pilaDestino );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf( "\n" );
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaOrigen, &ingreso, tam );
    }

    while(          desapilar( &pilaOrigen, &ingreso, tam )            )
    {
        apilar( &pilaDestino, &ingreso, tam );
    }

    printf("\n");
    while(          desapilar( &pilaDestino, &ingreso, tam )           )
    {
        printf( "Desapilando pilaDestino: %d\n", ingreso );
    }

    vaciarPila( &pilaOrigen );
    vaciarPila( &pilaDestino );

    printf( "\n***********FINALIZANDO EJERCICIO 2***********\n" );
    system( "pause" );
    system( "cls" );
}
/**
3- Cargar desde teclado Pila1 y pasar a PilaDestino todos aquellos elementos distintos a 3(tres).
*/

void ejercicio3()
{
    tPila pilaOrigen;
    tPila pilaDestino;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;

    crearPila( &pilaOrigen );
    crearPila( &pilaDestino );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaOrigen, &ingreso, tam );
    }

    while(          desapilar( &pilaOrigen, &ingreso, tam )         )
    {
        if(         CLAVE_DE_EXCLUSION != ingreso         )
        {
            apilar( &pilaDestino, &ingreso, tam );
        }
    }

    printf("\n");
    i = 0;

    while(          desapilar( &pilaDestino, &ingreso, tam )           )
    {
        printf( "Desapilando pilaDestino: %d\n", ingreso );
        i++;
    }

    if(         !i          )
    {
        printf( "No hay elementos en la pilaDestino\n" );
    }

    vaciarPila( &pilaOrigen );
    vaciarPila( &pilaDestino );

    printf( "\n***********FINALIZANDO EJERCICIO 3***********\n" );
    system( "pause" );
    system( "cls" );
}

/**
4- Cargar desde teclado PilaOrigen e inicializar (null) la PilaDestino.
Pasar los elementos de PilaOrigen a PilaDestino pero deben quedar en el mismo orden.
*/

void ejercicio4()
{
    tPila pilaOrigen;
    tPila pilaDestino;
    tPila pilaAux;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;

    crearPila( &pilaOrigen );
    crearPila( &pilaDestino );
    crearPila( &pilaAux );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaOrigen, &ingreso, tam );
    }

    while(          desapilar( &pilaOrigen, &ingreso, tam )            )
    {
        apilar( &pilaAux, &ingreso, tam );
    }

    while(          desapilar( &pilaAux, &ingreso, tam )            )
    {
        apilar( &pilaDestino, &ingreso, tam );
    }

    printf("\n");
    while(          desapilar( &pilaDestino, &ingreso, tam )           )
    {
        printf( "Desapilando pilaDestino: %d\n", ingreso );
    }

    vaciarPila( &pilaOrigen );
    vaciarPila( &pilaDestino );
    vaciarPila( &pilaAux );

    printf( "\n***********FINALIZANDO EJERCICIO 4***********\n" );
    system( "pause" );
    system( "cls" );
}

void ejercicio5()
{
    tPila pila1;
    tPila pilaAux1;
    tPila pilaAux2;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;

    crearPila( &pila1 );
    crearPila( &pilaAux1 );
    crearPila( &pilaAux2 );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    while(          desapilar( &pila1, &ingreso, tam )         )
    {
        apilar( &pilaAux1, &ingreso, tam );
    }

    while(          desapilar( &pilaAux1, &ingreso, tam )         )
    {
        apilar( &pilaAux2, &ingreso, tam );
    }

    while(          desapilar( &pilaAux2, &ingreso, tam )          )
    {
        apilar( &pila1, &ingreso, tam );
    }

    printf( "\n" );
    while(          desapilar( &pila1, &ingreso, tam )         )
    {
        printf( "Desapilando pila1 Inversa: %d\n", ingreso );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaAux1 );
    vaciarPila( &pilaAux2 );

    printf( "\n***********FINALIZANDO EJERCICIO 5***********\n" );
    system( "pause" );
    system( "cls" );
}

/**
 6- Pasar el primer elemento de la Pila1 a su última posición, dejando los restantes en el mismo orden
*/
void ejercicio6()
{
    tPila pila1;
    tPila pilaAux;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;
    int buffer;

    crearPila( &pila1 );
    crearPila( &pilaAux );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf( "\n" );
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    if(         ce > 1          )
    {
        while(          desapilar( &pila1, &ingreso, tam )         )
        {
            apilar( &pilaAux, &ingreso, tam );
        }

        desapilar( &pilaAux, &buffer, tam );

        while(          desapilar( &pilaAux, &ingreso, tam )         )
        {
            apilar( &pila1, &ingreso, tam );
        }

        apilar( &pila1, &buffer, tam );
    }

    printf( "\n" );
    while(          desapilar( &pila1, &ingreso, tam )         )
    {
        printf( "Desapilando: %d\n", ingreso );
    }

    if(         ce <= 0         )
    {
        printf( "No hay elementos para desapilar\n" );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaAux );

    printf( "\n***********FINALIZANDO EJERCICIO 6***********\n" );
    system( "pause" );
    system( "cls" );
}

/**
7- Pasar el último elemento de la Pila1 a su primera posición,
dejando los restantes en el mismo orden.
*/
void ejercicio7()
{
    tPila pila1;
    tPila pilaAux;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;
    int buffer;

    crearPila( &pila1 );
    crearPila( &pilaAux );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    if(         ce > 1          )
    {
        desapilar( &pila1, &buffer, tam );

        while(          desapilar( &pila1, &ingreso, tam )         )
        {
            apilar( &pilaAux, &ingreso, tam );
        }

        apilar( &pila1, &buffer, tam );

        while(          desapilar( &pilaAux, &ingreso, tam )         )
        {
            apilar( &pila1, &ingreso, tam );
        }
    }

    printf( "\n" );
    while(          desapilar( &pila1, &ingreso, tam )         )
    {
        printf( "Desapilando: %d\n", ingreso );
    }

    if(         ce <= 0         )
    {
        printf( "No hay elementos para desapilar\n" );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaAux );

    printf( "\n***********FINALIZANDO EJERCICIO 7***********\n" );
    system( "pause" );
    system( "cls" );
}
/**
8- Repartir los elementos de la PilaMazo en la PilaJugador1 y PilaJugador2 en forma alternada
*/

//TODO: implementar version RANDOM -> mando pilaMazo a una funcion que lo mezcle y lo devuelva mezclado, despues es todo igual

void ejercicio8()
{
    tPila pilaMazo;
    tPila pilaJugador1;
    tPila pilaJugador2;
    int ingreso;
    int tam = sizeof( int );
    int ce;
    int i;

    crearPila( &pilaMazo );
    crearPila( &pilaJugador1 );
    crearPila( &pilaJugador2 );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaMazo, &ingreso, tam );
    }

    i = 0;
    while(          desapilar( &pilaMazo, &ingreso, tam )         )
    {
        if(         0 == ( i % 2 )          )
        {
            apilar( &pilaJugador1, &ingreso, tam );
        }
        else
        {
            apilar( &pilaJugador2, &ingreso, tam );
        }

        i++;
    }

    printf( "\n" );
    while(          desapilar( &pilaJugador1, &ingreso, tam )          )
    {
        printf( "Carta del jugador 1:\t%d\n", ingreso );
    }

    printf( "\n" );
    while(          desapilar( &pilaJugador2, &ingreso, tam )          )
    {
        printf( "Carta del jugador 2:\t%d\n", ingreso );
    }

    vaciarPila( &pilaMazo );
    vaciarPila( &pilaJugador1 );
    vaciarPila( &pilaJugador2 );

    printf( "\n***********FINALIZANDO EJERCICIO 8***********\n" );
    system( "pause" );
    system( "cls" );
}

/**
9- Comparar la cantidad de elementos de la PilaA y PilaB. Mostrar por pantalla el resultado.
*/

void ejercicio9()
{
    tPila pilaA;
    tPila pilaB;
    int ingreso;
    int tam = sizeof( int );
    int ce;
    int i;
    int contarA = 0;
    int contarB = 0;

    crearPila( &pilaA );
    crearPila( &pilaB );

    printf( "\nIngrese cuantos elementos quiere apilar en pilaA:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaA, &ingreso, tam );
    }

    printf( "\nIngrese cuantos elementos quiere apilar en pilaB:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaB, &ingreso, tam );
    }

    while(          desapilar( &pilaA, &ingreso, tam )         )
    {
        contarA++;
    }

    while(          desapilar( &pilaB, &ingreso, tam )          )
    {
        contarB++;
    }

    printf( "\nLa pilaA tiene: %d elementos\nLa pilaB tiene: %d elementos\n", contarA, contarB );

    vaciarPila( &pilaA );
    vaciarPila( &pilaB );

    printf( "\n***********FINALIZANDO EJERCICIO 9***********\n" );
    system( "pause" );
    system( "cls" );
}

/**
10- Comparar la cantidad de elementos de la PilaA y PilaB,
evaluando si son complemente iguales (en cant de elementos, valores y posiciones).
Mostrar por pantalla el resultado.
*/

void ejercicio10()
{
    tPila pilaA;
    tPila pilaB;
    int ingreso;
    int tam = sizeof( int );
    int ce;
    int i;
    int datoA;
    int datoB;
    int cantElementosA = 0;
    int cantElementosB = 0;
    int remanenteA = 0;
    int remanenteB = 0;
    int pilasIguales = 1;

    crearPila( &pilaA );
    crearPila( &pilaB );

    printf( "\nIngrese cuantos elementos quiere apilar en pilaA:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaA, &ingreso, tam );
    }

    printf( "\nIngrese cuantos elementos quiere apilar en pilaB:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaB, &ingreso, tam );
    }

    while(          ( remanenteA = desapilar( &pilaA, &datoA, tam ) ) && ( remanenteB = desapilar( &pilaB, &datoB, tam ) )            )
    {
        if(         datoA != datoB          )
        {
            printf( "nroElemento: %d\tdatoA[%d] != datoB[%d]\n", cantElementosA,datoA, datoB );
            pilasIguales = 0;
        }
        else
        {
            printf( "nroElemento: %d\tdatoA[%d] == datoB[%d]\n", cantElementosA, datoA, datoB );
        }
        cantElementosA++;
        cantElementosB++;
        remanenteA = 0;
        remanenteB = 0;
    }

    if(         remanenteA && !remanenteB           )
    {
        printf( "Elementos remanentes en A: %d\n", datoA );
        cantElementosA++;
    }

    while(          desapilar( &pilaA, &datoA, tam )            )
    {
        printf( "Elementos remanentes en A: %d\n", datoA );
        cantElementosA++;
    }

    while(          desapilar( &pilaB, &datoB, tam )            )
    {
        printf( "Elementos remanentes en B: %d\n", datoB );
        cantElementosB++;
    }

    printf( "\nInforme:\n" );
    printf( "Cantidad de elementos de A: %d\n", cantElementosA );
    printf( "Cantidad de elementos de B: %d\n", cantElementosB );

    if(         !( pilasIguales && cantElementosA == cantElementosB )         )
    {
        printf( "\nLas pilas NO son iguales\n" );
    }
    else if(            !( !cantElementosA && !cantElementosB )          )
    {
        printf( "\nLas pilas son iguales\n" );
    }
    else
    {
        printf( "\nLas pilas estan vacias\n" );
    }
    vaciarPila( &pilaA );
    vaciarPila( &pilaB );

    printf( "\n***********FINALIZANDO EJERCICIO 10**********\n" );
    system( "pause" );
    system( "cls" );
}
/**
11- Suponiendo la existencia de PilaModelo no vacia,
eliminar de la Pila1 todos los elementos que sean iguales al tope de la PilaModelo.
*/

void ejercicio11()
{
    tPila pila1;
    tPila pilaModelo;
    tPila resultado;
    int ingreso;
    int tam = sizeof( int );
    int ce;
    int i;
    int aComparar;

    crearPila( &pila1 );
    crearPila( &pilaModelo );
    crearPila( &resultado );

    printf( "\nIngrese cuantos elementos quiere apilar en pila1:\t" );
    scanf( "%d", &ce );

    printf( "\n" );
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    printf( "\nIngrese cuantos elementos quiere apilar en pilaModelo:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaModelo, &ingreso, tam );
    }

    if(         verTope( &pilaModelo, &aComparar, tam )           )
    {
        while(          desapilar( &pila1, &ingreso, tam )         )
        {
            if(         ingreso != aComparar            )
            {
                apilar( &resultado, &ingreso, tam );
            }
        }

        while(          desapilar( &resultado, &ingreso, tam )         )
        {
            apilar( &pila1, &ingreso, tam );
        }
    }

    printf( "\nPila resultado:\n" );
    while(          desapilar( &pila1, &ingreso, tam )          )
    {
        printf( "Elementos resultado: %d\n", ingreso );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaModelo );
    vaciarPila( &resultado );

    printf( "\n***********FINALIZANDO EJERCICIO 11**********\n" );
    system( "pause" );
    system( "cls" );
}

/**
12- Suponiendo la existencia de PilaModelo vacia o no,
eliminar de la Pila1 todos los elementos que existan en PilaModelo.
*/
void ejercicio12()
{
    tPila pila1;
    tPila pilaModelo;
    tPila aux;
    tPila resultado;
    int ingreso;
    int tam = sizeof( int );
    int ce;
    int i;
    int aComparar;
    int loCuento;

    crearPila( &pila1 );
    crearPila( &pilaModelo );
    crearPila( &aux );
    crearPila( &resultado );

    printf("\nIngrese cuantos elementos quiere apilar en pila1:\t");
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    printf( "\nIngrese cuantos elementos quiere apilar en pilaModelo:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaModelo, &ingreso, tam );
    }

    printf( "\nPila resultado:\n" );
    if(         verTope( &pilaModelo, &ingreso, tam )           )
    {
        while(          desapilar( &pila1, &ingreso, tam )         )
        {
            loCuento = 1;
            while(          desapilar( &pilaModelo, &aComparar, tam )         )
            {
                apilar( &aux, &aComparar, tam );

                if(         ingreso == aComparar            )
                {
                    loCuento = 0;
                    break;
                }
            }

            while(          desapilar( &aux, &aComparar, tam )         )
            {
                apilar( &pilaModelo, &aComparar, tam );
            }

            if(         loCuento            )
            {
                apilar( &resultado, &ingreso, tam );
            }
        }

        while(          desapilar( &resultado, &ingreso, tam )          )
        {
            printf( "Elementos resultado: %d\n", ingreso );
        }

    }
    else
    {
        while(          desapilar( &pila1, &ingreso, tam )          )
        {
            printf( "Elementos resultado: %d\n", ingreso );
        }
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaModelo );
    vaciarPila( &aux);
    vaciarPila( &resultado );

    printf( "\n***********FINALIZANDO EJERCICIO 12**********\n" );
    system( "pause" );
    system( "cls" );
}
/**
13- Suponiendo la existencia de PilaLimite, pasar los elementos de la Pila1 que sean >= que el tope
de PilaLimite a la PilaMayores y los menores a la pilaMenores.
*/

void ejercicio13()
{
    tPila pilaLimite;
    tPila pila1;
    tPila pilaMayores;
    tPila pilaMenores;
    int ingreso;
    int ce;
    int i;
    int tam = sizeof( int );
    int aComparar;

    crearPila( &pilaLimite );
    crearPila( &pila1 );
    crearPila( &pilaMayores );
    crearPila( &pilaMenores );

    printf( "\nIngrese cuantos elementos quiere apilar en pila1:\t" );
    scanf( "%d", &ce );

    printf("\n");
    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    printf( "\nIngrese cuantos elementos quiere apilar en pilaLimite:\t" );
    scanf( "%d", &ce );

    printf("\n");

    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pilaLimite, &ingreso, tam );
    }

    if(         verTope( &pilaLimite, &aComparar, tam )           )
    {
        while(          desapilar( &pila1, &ingreso, tam )         )
        {
            if(         ingreso >= aComparar            )
            {
                apilar( &pilaMayores, &ingreso, tam );
            }
            else
            {
                apilar( &pilaMenores, &ingreso, tam );
            }
        }
    }

    printf( "\nPila de mayores:\n" );
    while(          desapilar( &pilaMayores, &ingreso, tam )           )
    {
        printf( "Elemento de pilaMayores: %d\n", ingreso );
    }

    printf("\nPila de menores:\n");
    while(          desapilar( &pilaMenores, &ingreso, tam )           )
    {
        printf( "Elemento de pilaMenores: %d\n", ingreso );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaLimite );
    vaciarPila( &pilaMayores );
    vaciarPila( &pilaMenores );

    printf( "\n***********FINALIZANDO EJERCICIO 13**********\n" );
    system( "pause" );
    system( "cls" );
}

//VARIANTE DEL 6 INTERMCAIBANDO TOPE Y BASE
void ejercicio14()
{
    tPila pila1;
    tPila pilaAux;
    int ce;
    int ingreso;
    int tam = sizeof( int );
    int i;
    int buffer;

    crearPila( &pila1 );
    crearPila( &pilaAux );

    printf( "Ingrese cuantos elementos quiere apilar:\t" );
    scanf( "%d", &ce );

    printf("\n");

    for( i = 0; i < ce; i++ )
    {
        printf( "Ingrese elemento %d:\t", i + 1 );
        scanf( "%d", &ingreso );
        fflush( stdin );
        apilar( &pila1, &ingreso, tam );
    }

    if(         ce > 1          )
    {
        desapilar( &pila1, &buffer, tam );

        while(          desapilar( &pila1, &ingreso, tam )         )
        {
            apilar( &pilaAux, &ingreso, tam );
        }

        apilar( &pila1, &buffer, tam );
        desapilar( &pilaAux, &buffer, tam );

        while(          desapilar( &pilaAux, &ingreso, tam )         )
        {
            apilar( &pila1, &ingreso, tam );
        }
        apilar( &pila1, &buffer, tam );
    }

    printf( "\n" );
    while(          desapilar( &pila1, &ingreso, tam )         )
    {
        printf( "Desapilando: %d\n", ingreso );
    }

    if(         ce <= 0         )
    {
        printf( "No hay elementos para desapilar\n" );
    }

    vaciarPila( &pila1 );
    vaciarPila( &pilaAux );

    printf( "\n***********FINALIZANDO EJERCICIO 14**********\n" );
    system( "pause" );
    system( "cls" );
}
