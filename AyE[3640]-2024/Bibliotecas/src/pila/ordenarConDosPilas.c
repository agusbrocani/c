#include "../../include/pila/ordenarConDosPilas.h"

void ordenarConDosPilas( FILE* archivo, tPila* pilaEntrada, int tam, int(*comparar)( const void* a, const void* b ), void (*grabarArchivo)( FILE* archivo, const void* dato ) )
{
    tPila pilaMayores;
    tPila pilaMenores;
    int cmp;
    void* bufferEntrada;
    void* buffer;

    crearPila( &pilaMayores);
    crearPila( &pilaMenores );

    bufferEntrada = malloc( tam );

    if(         !bufferEntrada         )
    {
        printf( "No pude ordenar archivo\n" );
        return;
    }

    buffer = malloc( tam );

    if(         !buffer            )
    {
        free( bufferEntrada );
        printf( "No pude ordenar archivo\n" );
        return;
    }

    ///grabo en pila mayores tope de la pila de entrada

    if(         desapilar( pilaEntrada, bufferEntrada, tam )           )
    {
        apilar( &pilaMayores, bufferEntrada, tam );
    }

    while(          desapilar( pilaEntrada, bufferEntrada, tam )         )
    {
        verTope( &pilaMayores, buffer, tam );
        cmp = comparar( buffer, bufferEntrada );
        if(         cmp < 0         )
        {
            while(          desapilar( &pilaMayores, buffer, tam )         )
            {
                apilar( &pilaMenores, buffer, tam );
            }
            apilar( &pilaMayores, bufferEntrada, tam );
        }
        else if(            cmp > 0          )
            {
                while(          desapilar( &pilaMenores, buffer, tam )         )
                {
                    apilar( &pilaMayores, buffer, tam );
                }
                apilar( &pilaMenores, bufferEntrada, tam );
            }
            else
            {
                //acumular
                //Desapilar, acumular, apilar
            }
    }

    while(          desapilar( &pilaMenores, buffer, tam )         )
    {
        apilar( &pilaMayores, buffer, tam );
    }

    while(          desapilar( &pilaMayores, buffer, tam )         )
    {
        grabarArchivo( archivo, buffer );
    }

    free( bufferEntrada );
    free( buffer );
    vaciarPila( pilaEntrada );
    vaciarPila( &pilaMayores );
    vaciarPila( &pilaMenores );
}
