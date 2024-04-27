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

int proximaPalabra(char** cadena,char** palabra);
int cmpTuplas( const void* a, const void* b);

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

    while(          proximaPalabra( &quedoParado, &guardaPalabra )          )
    {
        ( abecedario[ (toupper( *guardaPalabra ) - 'A') ].cantidad ) += 1;
    }

    qsort( abecedario, CANT_ABC, sizeof(tTupla), cmpTuplas );

    for( int i = 0; i < 5; i++ )
    {
        printf("Letra %c = %d\n", abecedario[i].letra, abecedario[i].cantidad );
    }

    return 0;
}

int proximaPalabra(char** cadena,char** palabra)
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
