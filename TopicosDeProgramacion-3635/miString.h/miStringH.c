#include "miStringH.h"
#include <stdlib.h>

//Si recorro una cadena de IZQUIERDA A DERECHA -> corto con el \0
//Si recorro una cadena de DERECHA A IZQUIERDA  -> guardo el inicio y paro cuando lo encuentro
//                                              -> uso la longitud de la cadena y paro cuanto itere esa cantidad de veces

unsigned miStrlen(const char* cadena)
{
    unsigned cantidadCaracteres = 0;

    while(          '\0' != *cadena         )
    {
        cantidadCaracteres++;   //me cuenta los caracteres
        cadena++;               //me mueve en la cadena
    }

    return cantidadCaracteres;  //0 si nunca entro al while o sino la cantidad de caracteres de la cadena
}

char* miStrcpy(char* destino, const char* origen)
{
    char* ini = destino;

    while(          '\0' != *origen && destino != origen            )
    {
        *destino = *origen;
        destino++;
        origen++;
    }

    *destino = *origen;    //copia el \0

    return ini;
}

char* miStrcat(char* cadena1, const char* cadena2)
{
    char* ini = cadena1;

    while(          '\0' != *cadena1            )
    {
        cadena1++;
    }
    //salgo parado en el \0 de cadena1

    while(          '\0' != *cadena2            )
    {
        *cadena1 = *cadena2;
        cadena1++;
        cadena2++;
    }
    *cadena1 = '\0';    //copio el \0 de cadena 2 en cadena 1

    return ini;
}

char *miStrchr(char* cadena, int caracterBuscado)
{
    while(          '\0' != *cadena && caracterBuscado != *cadena        )
    {
        cadena++;
    }

    if(         '\0' == *cadena         )    //pregunto que encontré, si el \0 o el caracterBuscado
    {
        return NULL;
    }

    return cadena;
}

char *miStrrchr(char* cadena, int caracterBuscado)
{
    char* ini = cadena;
    while(          '\0' != *cadena)
    {
        cadena++;
    }
    //RECORRO LA CADENA DE DERECHA A IZQUIERDA y busco la coincidencia del caracter, si no lo encuentro, salgo cuando cadena<ini y retorno NULL, si lo encuentro, devuelvo la direccion donde encontre el caracter
    while(          ini <= cadena && caracterBuscado != *cadena           )
    {
        cadena--;
    }

    if(         ini>cadena         )    //si cadena es mas chico que ini, significa que recorri todo y no encontre el caracter
    {
        return NULL;
    }

    return cadena;
}

char* miStrstr(const char* cadena, const char* cadenaABuscar)
{
    //Hola a todos (cadena en la que busco)
    //la (cadena a buscar)
    const char* recorrido = cadena;
    const char* buscando;
    const char* inicioRetorno;

    while(          '\0' != *recorrido         )
    {
        buscando = cadenaABuscar;
        inicioRetorno = recorrido;
        while(          '\0' != *recorrido && *recorrido == *buscando         )
        {
            buscando++;
            recorrido++;
        }

        if(         '\0' == *buscando           )   // !(*buscando)
        {
            return (char*)inicioRetorno;
        }

        recorrido++;
    }

    return NULL;
}

char* miStrncpy(char* destino, const char* origen, unsigned cantidadACopiar)
{
    char* iniDestino = destino;
    int tamOrigen = miStrlen(origen);
    int cantidadRealCopiada = cantidadACopiar;

    if(         tamOrigen<cantidadACopiar           )
    {
        cantidadRealCopiada = tamOrigen;
    }

    while(          '\0' != *origen && cantidadRealCopiada      )
    {
        *destino = *origen;
        origen++;
        destino++;
        cantidadRealCopiada--;
    }
    *destino = '\0';

    return iniDestino;
}

int proximaPalabra(char** cadena,char** palabra)
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
