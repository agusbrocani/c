#include "parcial.h"

void mostrarMatriz( int mat[][MAX_COLUMNA], int cf, int cc )
{
    int f;
    int c;

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            printf( "%d\t", mat[f][c] );
        }
        printf("\n");
    }
    printf("\n\n");
}

void trasponerMatriz( int mat[][MAX_COLUMNA], int cf, int cc )
{
    int resultado[MAX_FILA][MAX_COLUMNA];
    int f;
    int c;

    if(         cf < 1 || cc < 1 || cf > MAX_FILA || cc > MAX_COLUMNA           )
    {
        return;
    }

    for( f = 0; f < cf; f++ )
    {
        for( c = 0; c < cc; c++ )
        {
            resultado[c][f] = mat[f][c];
        }
    }

    printf("Matriz traspuesta:\n");
    mostrarMatriz( resultado, cc, cf );
}

void mostrarEntero( const void* data )
{
    printf("%d\t", *(int*)data );
}

void mostrarVector( const void* data, int tam, int ce, void (*mostrar)(const void* data) )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        mostrar( data );
        data += tam;
    }
    printf("\n");
}

int comparaEnteros( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

//void* miBsearch( const void* clave, const void* data, size_t ce, size_t tam, int (*comparar)(const void *, const void *))//ESTO ES SECUENCIAL, NO ES LO QUE PIDE
//{
//    if(         ce <= 0          )
//    {
//        return NULL;
//    }
//
//    if(         !comparar( clave, data )         )
//    {
//        return (void*)data;
//    }
//
//    return miBsearch( clave, data + tam, ce - 1, tam, comparar );
//}

void* miBsearch( const void* clave, const void* data, size_t ce, size_t tam, int (*comparar)(const void *, const void *) )
{
    const void* fin = data + (ce - 1) * tam; //ESTOY PARADO EN EL ULTIMO ELEMENTO
    const void* pivot = data +  ( ce % 2 ? ce/2 : ce/2 - 1 )  * tam;
    int cmp;

    if(         ce < 1         )
    {
        return NULL;
    }

    cmp = comparar( clave, pivot );

    if(         !cmp            )
    {
        return (void*)pivot;
    }

    if(         cmp > 0         )
    {
        return miBsearch( clave, pivot + tam , ce - 1 - ( pivot - data )/tam, tam, comparar );
    }

    if(         cmp < 0         )
    {
        return miBsearch( clave, data + tam, ce - ( fin - pivot )/tam, tam, comparar );
    }
    return NULL;
}
