#include "coordenadasDeViaje.h"

void mostrarAuto( const void* data )
{
    printf("Patente: %s\n", ((tAuto*)data)->patente );
    printf("Latitud: %.2f\n", ((tAuto*)data)->latitud );
    printf("Longitud %.2f\n", ((tAuto*)data)->longitud );
}

void mostrarAutito( const void* data, size_t tam, int ce, void(*mostrar)( const void* data ) )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        mostrar( data );
    }
    printf("\n");
}

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        perror("No pude abrir/crear el archivo");
        return 0;
    }
    return 1;
}

void crearLote()
{
    FILE* pf;
    tAuto autos[] =
    {
        { "AB 123 CD", 34.567, 56.789 },
        { "BC 456 DE", 35.678, 57.890 },
        { "CD 789 EF", 36.789, 58.901 },
        { "DE 012 FG", 37.890, 59.012 },
        { "EF 345 GH", 38.901, 60.123 },
        { "FG 678 HI", 39.012, 61.234 },
        { "HI 901 IJ", 40.123, 62.345 },
        { "IJ 234 JK", 41.234, 63.456 },
        { "KL 567 LM", 42.345, 64.567 },
        { "LM 890 MN", 43.456, 65.678 },
        { "MN 123 NO", 44.567, 66.789 },
        { "NO 456 OP", 45.678, 67.890 },
        { "OP 789 PQ", 46.789, 68.901 },
        { "QR 012 RS", 47.890, 69.012 },
        { "RS 345 ST", 48.901, 70.123 },
        { "ST 678 TU", 49.012, 71.234 },
        { "TU 901 UV", 50.123, 72.345 },
        { "UV 234 VW", 51.234, 73.456 },
        { "WX 567 XY", 52.345, 74.567 },
        { "XY 890 YZ", 53.456, 75.678 },
        { "YZ 123 AB", 54.567, 76.789 },
        { "AB 456 BC", 55.678, 77.890 },
        { "BC 789 CD", 56.789, 78.901 },
        { "CD 012 DE", 57.890, 79.012 },
        { "DE 345 EF", 58.901, 80.123 },
        { "EF 678 FG", 59.012, 81.234 },
        { "FG 901 HI", 60.123, 82.345 },
        { "HI 234 IJ", 61.234, 83.456 },
        { "IJ 567 JK", 62.345, 84.567 },
        { "KL 890 LM", 63.456, 85.678 }
    };
    int ce = sizeof(autos)/sizeof(tAuto);
    int i;

    pf = fopen( "autitos.txt", "wt" );

    if(         !pf         )
    {
        return;
    }

    for( i = 0; i < ce; i++ )
    {
        fprintf( pf ,"%-10s%7.2f%7.2f\n", autos[i].patente, autos[i].latitud, autos[i].longitud );
    }
    fclose(pf);
}

void trozar( tAuto* autito, char* buffer )
{
    char* recorrido = strrchr( buffer, '\n');
    *recorrido = '\0';
    recorrido -= 7;
    autito->latitud = atof( recorrido );
    *recorrido = '\0';
    recorrido -= 7;
    autito->longitud = atof( recorrido );
    *recorrido = '\0';
    strcpy( autito->patente, buffer );
}

double degreesToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}

// Función para calcular la distancia haversine
double haversineDistance( double lat1, double lon1, double lat2, double lon2 )
{
    // Convertir latitudes y longitudes de grados a radianes
    lat1 = degreesToRadians(lat1);
    lon1 = degreesToRadians(lon1);
    lat2 = degreesToRadians(lat2);
    lon2 = degreesToRadians(lon2);

    // Diferencias entre las latitudes y longitudes
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Fórmula haversine
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}












