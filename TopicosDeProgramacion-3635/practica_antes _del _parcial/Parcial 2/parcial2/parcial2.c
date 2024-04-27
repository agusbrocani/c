#include "parcial2.h"

int comparaInt( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

void mostrarInt( const void* data )
{
    printf("%d\t", *(int*)data );
}

void mostrarVector( const void* data, size_t tam, int ce, void (*mostrar) ( const void* data ) )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        mostrar( data );
        data += tam;
    }
    printf("\n");
}

void mostrarMatriz( const void* data, size_t tam, int cf, int cc, void (*mostrar)( const void* data ) )
{
    int f;
    int c;

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            mostrar( data );
            data += tam;
        }
        printf("\n");
    }
}

void* buscarMenor( void* data, size_t tam, size_t ce, int (*comparar)( const void* a, const void* b ) )
{
    void* menor = data;
    int i;

    if(         ce < 0          )
    {
        return NULL;
    }

    data += tam;
    for( i = 1; i < ce; i++)
    {
        if(         comparar( menor, data) > 0          )
        {
            menor = data;
        }
        data += tam;
    }
    return menor;
}

void fSwap( void* a, void* b, size_t tam )
{
    char aux;
    int i;

    for( i = 0; i < tam; i++ )
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }
}

void _ordenarSeleccion( void* data, size_t ce, size_t tam, int (*comparar)( const void* a, const void* b ) )
{
    void* menor;
    int i;

    if(         ce < 1          )   //ya esta ordenado
    {
        return;
    }

    for( i = 0; i < ce; i++ )
    {
        menor = buscarMenor( data, tam, ce - i, comparar );
        if(         comparar( menor, data ) < 0          )
        {
            fSwap( menor, data, tam );
        }
        data += tam;
    }
}

int miStrlen( const char* cadena )
{
    int cantidadDeCaracteres = 0;

    while(          *cadena         )
    {
        cantidadDeCaracteres++;
        cadena++;
    }

    return cantidadDeCaracteres;
}

int miStrncmp( const char* cadena1, const char* cadena2, int cantidad )
{
    int i;

    for( i = 0; i < cantidad; i++ )
    {
        if(         *cadena1 != *cadena2            )
        {
            return *cadena1 - *cadena2;
        }
        cadena1++;
        cadena2++;
    }
    return 0;
}

char* miStrstr( const char* cadena1, const char *cadena2 )
{
    int tamPalabra = miStrlen( cadena1 );

    if(         !tamPalabra         )
    {
        return (char*)cadena1;
    }

    while(          *cadena2            )
    {
        if(         (*cadena2 == *cadena1) && !miStrncmp( cadena1, cadena2, tamPalabra)          )
        {
            return (char*)cadena2;
        }

        cadena2++;
    }

    return NULL;
}

int _contarCelulasVivasEnVecindario( int mat[][MAX_COLUMNAS], int cf, int cc, int indiceF, int indiceC, int (*comparar)( const void* a, const void* b ) )
{
    int f;
    int c;
    int cantidadDeCelulas = 0 ;

    for( f = indiceF; f < indiceF + 3; f++ )
    {
        for( c = indiceC ; c < indiceC + 3; c++ )
        {
            if(         1 == mat[f][c]          )    ///( (posF - 1) != f && (posC - 1) != c )
            {
                cantidadDeCelulas++;
            }
        }
    }

    if(         1 == mat[indiceF][indiceC]         )
    {
        cantidadDeCelulas--;
    }


    return cantidadDeCelulas;
}
















