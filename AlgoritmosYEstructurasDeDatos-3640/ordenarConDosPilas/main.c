#include "ordenarConDosPilas.h"

int cmpInt( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int lotePrueba[] = {2,5,3,1,4};
    //int lotePrueba[] = {1};
    tPila entrada;
    int i;

    srand(time(NULL));
    generarArchivoProductos("productos.txt","TEXTO");


    crearPila(&entrada);
    for( i = 0; i < sizeof(lotePrueba)/sizeof(int); i++ )
    {
        apilar( &entrada, &lotePrueba[i], sizeof(int) );
    }

    ordenarConDosPilasAscendente( &entrada, sizeof(int), cmpInt );

    vaciarPila( &entrada );

    return 0;
}
