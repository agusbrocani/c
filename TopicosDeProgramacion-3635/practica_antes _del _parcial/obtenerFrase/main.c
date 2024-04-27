#include "examen.h"

/*
Obtenga de la funcion "obtenerFrase" una frase distinta en cada invocacion. La funcion retorna
NULL cuando ya no tiene frases. Muestre por pantalla las 5 frases mas largas del total otorgado por
la funcion. Se asegura que ninguna frase supera los 1024 caracteres.


NOTA:
1.No asuma que existe una cantidad de frases, pueden ser menos, igual a 5 o cientos de miles
las devueltas por la funcion, solo muestre las 5 mas largas. Piense que en un sistema real la informacion
obtenida (en este caso simulada por la funcion) puede ser enorme y no existir capacidad de almacenamiento.
Piense la solucion en esos terminos. Se valora posivamente la genericidad en partes de la solucion.

2.El programa corre unicamente sobre compilador MINGW 64 bits, configure su entorno para poder correrlo.
*/
/*
int main()
{
    //La funcion obtenerFrase le dara una frase en cada invocacion y finalmente NULL cuando
    //no tenga mas frases para entregar. Analice el prototipo para evaluar como llamarla.

    char buffer[MAX_COLUMN];
    char mat[MAX_ROWS][MAX_COLUMN];
    int numberOfElements = 0;


    while(          obtenerFrase( buffer )          )
    {
            insertOrdered( mat, buffer, MAX_COLUMN, &numberOfElements, MAX_ROWS, comparePhrases );
            printf("%s\n", buffer );
    }

    printf("TOP 5:\n");
    for( int i = 0; i < MAX_ROWS; i++ )
    {
        printf( "%s\n", mat[i] );
    }


    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT_ABC 26
#define ES_LETRA(X)     (           (X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z')           )

typedef struct
{
    char letra;
    int cantidad;
}tTupla;

int miProximaPalabra(char** cadena,char** palabra );
int cmpTuplas( const void* a, const void* b );

int main()
{
    char frase[] = "Hola mundo, todo esta bien";
    char* quedoParado = frase;
    char* guardaPalabra;
    tTupla abecedario []=
    {
        { 'A', 0 },
        { 'B', 0 },
        { 'C', 0 },
        { 'D', 0 },
        { 'E', 0 },
        { 'F', 0 },
        { 'G', 0 },
        { 'H', 0 },
        { 'I', 0 },
        { 'J', 0 },
        { 'K', 0 },
        { 'L', 0 },
        { 'M', 0 },
        { 'N', 0 },
        { 'O', 0 },
        { 'P', 0 },
        { 'Q', 0 },
        { 'R', 0 },
        { 'S', 0 },
        { 'T', 0 },
        { 'U', 0 },
        { 'V', 0 },
        { 'W', 0 },
        { 'X', 0 },
        { 'Y', 0 },
        { 'Z', 0 }
    };

    printf("Frases: \n");
    while(          obtenerFrase( frase )          )
    {
        quedoParado = frase;
        printf("%s\n", frase );
        while(          miProximaPalabra( &quedoParado, &guardaPalabra )          )
        {
            ( abecedario[ (toupper( *guardaPalabra ) - 'A') ].cantidad ) += 1;
        }
    }
    qsort( abecedario, CANT_ABC, sizeof(tTupla), cmpTuplas );

    printf("\n");
    for( int i = 0; i < 5; i++ )
    {
        printf("Letra %c = %d\n", abecedario[i].letra, abecedario[i].cantidad );
    }

    return 0;
}

int miProximaPalabra(char** cadena,char** palabra)
{
    int cantidadCaracteres = 0;

    while(          '\0' != *(*cadena) && !ES_LETRA(    *(*cadena)   )           )
    {
        (*cadena)++;
    }
    *palabra = (*cadena);
    while(          ES_LETRA(   *(*cadena)  )          )
    {
        cantidadCaracteres++;
        (*cadena)++;
    }

    return cantidadCaracteres;
}
int cmpTuplas( const void* a, const void* b)
{
    return ((tTupla*)b)-> cantidad - ((tTupla*)a) -> cantidad;
}
