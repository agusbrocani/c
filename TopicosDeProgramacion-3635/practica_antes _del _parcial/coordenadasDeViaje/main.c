#include "coordenadasDeViaje.h"
/*
    Se pide desarrollar un sistema que procese un archivo de texto con el dominio y las posiciones (latitud y longitud) de una flota de vehiculos.
    El sistema debera informar de la distancia recorrida por cada vehiculo. No se sabe que vehiculos seran pero se asegura que no son mas de 30.
    El archivo sera de texto con campo de tamaño fijo y el dominio del vehiculo puede contener espacios.
    10 lugares para el dominio, 7 para la latitud y 7 para la longitud. Los registros estan ordenados por fecha de ocurrencia (No por dominio).
    Ej
    AA 000 AA-33.557 [latitud]- 54.554 [longitud]
*/

int main()
{
    tAuto autito;
    char buffer[TAM];
    int tam = sizeof(tAuto);

    FILE* autitos;

    crearLote();
    if(         !abrirArchivo( &autitos,"autitos.txt", "rt" )         )
    {
        return 1;
    }

    while(          fgets( buffer, sizeof(buffer), autitos )         )
    {
        trozar( &autito, buffer );
        mostrarAutito( &autito, tam, 1, mostrarAuto );
        printf("Distancia recorrida por el vehiculo %s: %.2lf KM\n\n\n", autito.patente, haversineDistance( autito.latitud, autito.longitud, 0, 0 ) );
    }

    fclose(autitos);

    return 0;
}
