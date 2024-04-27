#include "diaAntesDelParcial.h"

void mostrarInt( const void* data )
{
    printf("%d\t", *(int*)data );
}
void mostrarVector( const void* data, size_t tam, int ce, void (*mostrar)( const void* data ) )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        mostrar( data );
        data += tam;
    }
    printf("\n");
}

int comparaIntAB( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

int comparaIntBA( const void* a, const void* b )
{
    return *(int*)b - *(int*)a;
}

void desplazarColeccion( void* data, void* iniData, size_t tam, int ce )
{
    void* finData = iniData + ce*tam - tam;

    if(         !ce         )
    {
        return;
    }

    while(          finData >= data          )
    {
        memcpy( finData+tam, finData, tam );
        finData -= tam;
    }
}

int insertarOrdenado( void* data, const void* aInsertar, size_t tam, int* ce, int maxCe, int (*comparar)( const void* a, const void* b) )
{
    void* iniData = data;
    int indice = 0;

    if(         *ce < 0 || *ce >= maxCe          )
    {
        return 0;
    }

    while(          indice < *ce && comparar( data, aInsertar ) < 0          )
    {
        indice++;
        data += tam;
    }

    desplazarColeccion( data, iniData, tam, *ce );
    memcpy( data, aInsertar, tam );

    if(         *ce < maxCe         )
    {
            (*ce)++;
    }

    return 1;
}
