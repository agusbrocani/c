#include "parcial.h"

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

int proximaPalabra( char** cadena, char** palabra )
{
    int cantidadDeCaracteres = 0;

    while(          '\0' != *(*cadena) && !ES_LETRA( *(*cadena) )          )
    {
        (*cadena)++;
    }
    *palabra = *cadena;

    while(          ES_LETRA( *(*cadena) )          )
    {
        cantidadDeCaracteres++;
        (*cadena)++;
    }

    return cantidadDeCaracteres;
}

size_t miStrlen( const char *cadena )
{
    size_t cantidadDeCaracteres = 0;

    while(          '\0' != *cadena         )
    {
        cantidadDeCaracteres++;
        cadena++;
    }

    return cantidadDeCaracteres;
}

void cambiaLetra( char* letra )
{
    switch(         *letra          )
    {
        case 'f':
            *letra = 'a';
        break;
        case 'e':
            *letra = 'b';
        break;
        case 'd':
            *letra = 'c';
        break;
        case 'c':
            *letra = 'd';
        break;
        case 'b':
            *letra = 'e';
        break;
        case 'a':
            *letra = 'f';
        break;
    }
    //si la letra no era ninguna, se va
}

void darVueltaPalabra( char* palabra, int tamPalabra )
{
    char* iniPalabra = palabra;
    char* finPalabra = palabra + tamPalabra - 1;
    char aux;

    while(          iniPalabra < finPalabra         )
    {
        aux = *iniPalabra;
        *iniPalabra = *finPalabra;
        *finPalabra = aux;
        iniPalabra++;
        finPalabra--;
    }
}

void desofuscarRegistro( char* buffer )
{
    char* cadena = buffer;
    char* palabra;
    char* iniPalabra;
    int tamPalabra;
    int i;

    while(          ( tamPalabra = proximaPalabra( &cadena, &palabra ) )           )
    {
        iniPalabra = palabra;
        for( i = 0; i < tamPalabra; i++ )
        {
            cambiaLetra( palabra );
            palabra++;
        }

        darVueltaPalabra( iniPalabra, tamPalabra );
    }
}
