#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miStringH.h"
#define TAM 100


int main()
{
    char cadena[] = "Hola mundo";
    char cadena1[TAM] = "Electro";
    char cadena2[TAM] = "";
    char cadena3[TAM] = "Hola ";
    char cadena4[TAM] = "amigos";
    char cadena5[TAM] = "Zoom";
    char letra = 'o';
    char cadena6[TAM] = "Hola a todos";
    char cadena7[TAM] = "la";
    char cadena8[TAM] = "Hola Fede, como estas?";
    char cadena9[TAM] = "";
    char cadenaRecorrida[] = "Hola mundo, estoy recorriendo la cadena";
    char* quedoParado = cadenaRecorrida;
    char* guardaPalabra;
    int i;
    int tamPalabra;

    //char cadena[] = {'H','o','l','a'}; esto funciona pero es malo, porque si no tengo en cuenta la cantidad, me paso de largo por no tener  \0
    //char cadena[] = {'H','o','l','a','\0'};
    //char cadena[] = {72,111,108,97,0};

    printf("Cantidad de caracteres: %u\n", miStrlen(cadena));
    printf("Cadena cpy: %s\n",miStrcpy(cadena2,cadena1));
    printf("Cadena cat: %s\n",miStrcat(cadena3,cadena4));
    printf("STRCHR -> Direccion %p\tContenido: %c\n",miStrchr(cadena5,letra), (NULL != miStrchr(cadena5,letra))? *(miStrchr(cadena5,letra)): '-' ); //Este ternario diabolico no hace falta hacerlo, es solo para ver lo que hicimos
    printf("STRRCHR-> Direccion %p\tContenido: %c\n",miStrrchr(cadena5,letra), (NULL != miStrrchr(cadena5,letra))? *(miStrrchr(cadena5,letra)): '-' );
    printf("STRSTR : %s\n",(NULL != miStrstr(cadena6,cadena7))? miStrstr(cadena6,cadena7) : "NULL"     );
    printf("STRnCPY: %s\n",miStrncpy(cadena9,cadena8,sizeof(cadena8))   );


    printf("\n\nFuncion proximaPalabra:\n\n");
    printf("Cadena recorrida: %s\n\n",cadenaRecorrida);
    while(          (tamPalabra = proximaPalabra(&quedoParado, &guardaPalabra))            )    //Cuando encuentre el \0 va a devolver 0 y ahi termino
    {
        printf("TamPalabra = %d\nPalabra: ",tamPalabra);
        for(i=0;i<tamPalabra;i++)
        {
            printf("%c",*(guardaPalabra+i));
        }
        printf("\n");
    }

    return 0;
}
