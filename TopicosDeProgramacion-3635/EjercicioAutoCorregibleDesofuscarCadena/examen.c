#include <stdlib.h>
#include <string.h>
#include "examen.h"

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

void verificaYCambiaGrupo(char* palabra, int pos)
{
    char grupo[] = "abcdghijkoqtuv";
    char* ini = grupo;
    char* fin = grupo + strlen(grupo) - 1;  //estoy parado en el \0 de grupo, pero con el -1 me paro en la v
    char* letraEnGrupo = strchr(grupo,*palabra);
    int desplazamiento;

    if(         !letraEnGrupo           )
    {
        return;
    }

    pos += 1;   //paso de indice a posicion
    letraEnGrupo = letraEnGrupo + pos;

    while(          letraEnGrupo > fin         )
    {
        desplazamiento = letraEnGrupo - fin;
        letraEnGrupo = ini + desplazamiento - 1;
    }

    *palabra = *letraEnGrupo;
}

void cambiaLetra(char* palabra, int tamPalabra)
{
    int pos;

    for( pos = 0; pos < tamPalabra; pos++)
    {
        verificaYCambiaGrupo(palabra+pos,pos);
    }
}

char* desofuscar(char* linea)
{
    char* siguientePalabra = linea;
    char* palabra;
    int tamPalabra;

    while(         ( tamPalabra = miProximaPalabra(&siguientePalabra, &palabra) )           )
    {
        cambiaLetra(palabra,tamPalabra);
    }


    return NULL;
}

