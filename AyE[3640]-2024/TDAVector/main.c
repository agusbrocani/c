#include "./bibliotecaGeneralDeTDAVector.h"

int comparaEnteros( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

int main()
{
    tVector vec;
    int lote[5000] = {0,1,2,3,4,5,6,7,8,9};
    int ce = sizeof(lote)/sizeof(lote[0]);
    int tam = sizeof(lote[0]);
    int ultimoIndice;
    int dato;
    int i;
    unsigned ceInsertados = 0;

    crearVector( &vec, tam );

    for( i = 10; i < 5000; i++ )
    {
        lote[i] = i;
    }

    for( i = 0; i < ce; i++ )
    {
        insertarOrdenado( &vec, &lote[i], &ceInsertados, comparaEnteros );
    }

    eliminarElementoEnPosicion( &vec, &dato, 10, &ceInsertados );

    printf("\nVer elemento en posicion:\n");
    for( i = 0; i < ceInsertados; i++ )
    {
        verElementoEnPosicionDada( &vec, &dato, i );
        printf("%d\t", dato);
    }

///**************************************************************
    printf("\nEliminando en posicion:\n");
    ultimoIndice = ceInsertados - 1;
    while(          eliminarElementoEnPosicion( &vec, &dato, ultimoIndice, &ceInsertados )         )
    {
        printf("%d\n", dato);
        ultimoIndice--;
    }

    if(         vectorVacio( &vec )           )
    {
        printf("\nVector vacio\n");
    }
///**************************************************************
    destruirVector( &vec );

    return 0;
}
