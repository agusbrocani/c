#ifndef COORDENADASDEVIAJE_H_INCLUDED
#define COORDENADASDEVIAJE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define MAX_CANT_AUTOS 30
#include <math.h>

// Radio de la Tierra en kilómetros
#define EARTH_RADIUS 6371.0

typedef struct
{
    char patente[TAM];
    float latitud;
    float longitud;
}tAuto;

void mostrarAuto( const void* data );
void mostrarAutito( const void* data, size_t tam, int ce, void(*mostrar)( const void* data ) );

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );
void crearLote();
void trozar( tAuto* autito, char* buffer );

double degreesToRadians( double degrees );
double haversineDistance( double lat1, double lon1, double lat2, double lon2 );

#endif // COORDENADASDEVIAJE_H_INCLUDED
