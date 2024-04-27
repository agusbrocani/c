#include "examen.h"

int buscarIndice( const char* grupo, char letra )
{
    int index = 0;

    while(         '\0' != *grupo          )
    {
        if(         letra == *grupo         )
        {
            return index;
        }
        index++;
        grupo++;
    }

    return -1;
}

void validoYCambioLetra( char* letra, int offset )
{
    char grupo[] = "abcdghijkoqtuv";
    int longitudDeGrupo = strlen( grupo );  //14
    int indiceEnGrupo;
    int realOffset;

    if(         -1 == ( indiceEnGrupo = buscarIndice( grupo, *letra ) )          )
    {
        return;
    }

    realOffset = indiceEnGrupo + offset;

    while(          realOffset >= longitudDeGrupo           )
    {
        realOffset = ( realOffset % longitudDeGrupo);
    }

    *letra = *( grupo + realOffset );
}

char* desofuscar( char* linea )
{
    char* cadena = linea;
    char* palabra;
    int longitudPalabra;
    int i;

    while(          ( longitudPalabra = miProximaPalabra( &cadena, &palabra ) )         )   ///HOLA MUNDO
    {
        for( i = 0; i < longitudPalabra; i++ )
        {
            validoYCambioLetra( (palabra + i), (i+1) );  ///LE MANDO UNA LETRA
        }
    }

    return linea;
}

int miProximaPalabra(char** cadena,char** palabra)
{
    int cantidadCaracteres = 0;

    while(          '\0' != *(*cadena) && !ES_LETRA(    *(*cadena)   )           )
    {
        (*cadena)++;
    }
    *palabra = (*cadena);   //donde inicia la palabra o \0 si no hay nada
    while(          ES_LETRA(   *(*cadena)  )          )
    {
        cantidadCaracteres++;
        (*cadena)++;
    }

    return cantidadCaracteres;
}
