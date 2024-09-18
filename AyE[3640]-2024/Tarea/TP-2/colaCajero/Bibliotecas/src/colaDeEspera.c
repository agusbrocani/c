///AGUSTIN BROCANI-EZEQUIEL MUÑOZ-LAUTARO VEGA-LUCA ARCE
#include "../include/colaDeEspera.h"
/**
    Biblioteca <stdlib.h>:
        int rand(void);
        return: numero entero aleatorio no negativo entre 0 a RAND_MAX(32767) -> (2^15)= 32.768 valores

        void srand(unsigned int seed);
            seed modifica un estado interno que utiliza la funcion rand() para generar su retorno.

    Bibliocateca <time.h>:
        time_t time(time_t* tloc); //time_t es un long long int internamente -> 8 BYTES
            tloc: es un puntero a una variable de tipo time_t.
            Sirve para cargar la cantidad de segundos desde epoch en la direccion de memoria enviada por parametro.
            También la funcion retorna ese mismo valor.

        return: numero de segundos transcurridos desde el epoch como un valor de tipo time_t.
        En caso de error: -1(no puede obtener el tiempo actual del S.O. por alguna razon)
            epoch(tambien conocido como Unix epoch): es un punto de referencia desde el cual los sistemas de tiempo en
            muchas computadoras cuentan los segundos.
                Es una fecha y hora específica, definida como:
                    1 de enero de 1970 a las 00:00:00 UTC(Tiempo Universal Coordinado).
            CURIOSIDADES:
            -los sistemas que usan el epoch pueden manejar fechas anteriores a 1970 usando valores negativos.
            -los sistemas no basados en Unix, como Windows, también suelen manejar el tiempo de manera similar,
                aunque algunos tienen otros puntos de referencia (por ejemplo, Windows epoch empieza el 1 de enero de 1601).
                Sin embargo, muchos lenguajes de programacion siguen la convención del Unix epoch.

    ¿Porque usar srand(time(NULL))?
        Porque si uso solo rand() obtendria la misma secuencia de números aleatorios en cada ejecución del programa
        debido a que el generador de números pseudoaleatorios se inicializa con el estado predeterminado.
        Al usar time(NULL) como seed(cant de segundos desde 1-1-1970) me aseguro que siempre tenga un ingreso de datos diferente.
        De esta forma logro el resultado que quiero.

    CONCLUSIÓN: cada llamando de rand() usa el estado interno modificado por srand()
    para generar un valor entre 0 y 32767. Usando como semilla time(NULL) hago que
    siempre utilice como base de generacion un valor diferente, dandome retornos diferentes.
    Para inicializar semilla tengo que utilizar la funcion srand.

    CONTEXTO DEL PROBLEMA: le doy sentido a los valores random que me devuelve rand() acotando los resultados posibles retornados utilizando operador resto.
    rand() % MAX_RANGO_DESEADO -> fuerzo a que el valor generado por rand() este en el rango de 0 a (MAX_RANGO_DESEADO - 1)
*/

//PROBLEMA A RESOLVER: COLA de espera en un cajero automatico.
//
//-INTERVALO DE ACOLAR: aleatorio de 1, 3 o 5 minutos con igual probabilidad de ocurrencia,
//-INTERVALO DE ACOLAR: aleatorio de 1, 5 o 9 minutos con igual probabilidad de ocurrencia.
//
//FIN SIMULACIÓN: 5 veces Cola Vacia.
//[IMPORTANTE: los clientes LLEGAN DE A UNO.]

void simulacroColaDeEspera(const int* intervalosDeAcolado, const int* intervalosDeDesacolado)
{
    t_cola colaDeEspera;
    int tiempo;
    int tiempoNodo;
    int i;
    unsigned tam = sizeof(int);

    crearCola(&colaDeEspera);
    srand(time(NULL));
    for(i = 0; i < MAX_CANTIDAD_DE_SIMULACIONES; i++)
    {
        tiempo = 0;
        tiempoNodo = intervalosDeDesacolado[rand() % CANTIDAD_INTERVALOS_ALEATORIOS];
        printf("LLEGA CLIENTE\n");
        acolar(&colaDeEspera, &tiempoNodo, tam);

        while(!colaVacia(&colaDeEspera))
        {
            tiempo += intervalosDeAcolado[rand() % CANTIDAD_INTERVALOS_ALEATORIOS];

            while(verPrimero(&colaDeEspera, &tiempoNodo, tam) && tiempo >= tiempoNodo)
            {
                tiempo -= tiempoNodo;
                printf("SE VA CLIENTE\n");
                desacolar(&colaDeEspera, &tiempoNodo, tam);
            }

            if(!colaVacia(&colaDeEspera))
            {
                printf("LLEGA CLIENTE\n");
                tiempoNodo = intervalosDeDesacolado[rand() % CANTIDAD_INTERVALOS_ALEATORIOS];
                acolar(&colaDeEspera, &tiempoNodo, tam);
            }
        }
        printf("\n**********FIN DE SIMULACION: %d**********\n", i + 1);
        system("pause");
        system("cls");
    }
    vaciarCola(&colaDeEspera);
}
