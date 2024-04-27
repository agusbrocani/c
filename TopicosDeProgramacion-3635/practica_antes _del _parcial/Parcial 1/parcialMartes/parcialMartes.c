#include "parcialMartes.h"

int cmpInt( const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void crearLote()
{
    FILE* pf;
    int i;
    char lote[][ TAM ] =
    {
//        "Hola mundo mundo mundo",
//        "Como esta",
//        "todo bien"
//        "Alli va Ramon y no maravillaaaaaaaa",
//        "Amad a la dama",
//        "Amo la pacifica paloma",
//        "No lo cases a Colon",
//        "Oi lo de mama: me dolio.",
//        "Roma ni se conoce sin oro, ni se conoce sin amor",
//        "Ojo rojo maravillaaaaaaaar maravillaaaaaaaar",
//        "Isaac no ronca asi",
//        "Dabale arroz a la zorra el abad",
//        "Arriba la birra maravillaaaaaaaar",
//        "Amor a Roma maravillaaaaaaaar",
//        "A Mercedes, ese de crema",
//        "A luna ese anula maravillaaaaaaaar",
//        "Atar a la rata",
//        "Ateo poco poeta maravillaaaaaaaar",
//        "Ateo por Arabia, iba raro poeta",
//        "Di clases al Cid",
//        "El bar es iman o zona miserable"
    "Hay solo dos clases de lenguajes de programacion: aquellos de los que la gente esta siempre quejandose y aquellos que nadie usa -- Bjarne Stroustrup",
    "La programacion en bajo nivel es buena para el alma del programador --John Carmack, cofundador de id Software y creado del DOOM)",
    "La informatica tiene que ver con los ordenadores lo mismo que la astronomia con los telescopios--Edsger W. Dijkstra",
    "No temo a los ordenadores; lo que temo es quedarme sin ellos --Isaac Asimov",
    "Algunos desarrolladores cuando se enfrentan a un problema piensan que la solucion es usar expresiones regulares. En este momento, ya tienen dos problemas -- Jamie Zawinski"
    };
    int ce = sizeof(lote) / TAM;

    pf = fopen( "lote.txt" , "wt" );

    if(         !pf         )
    {
        perror("No se pudo crear archivo\n");
        return;
    }

    for( i = 0; i < ce; i++ )
    {
        fprintf( pf, "%s\n", lote[i] );
    }

    fclose( pf );
}

int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo )
{
    *pf = fopen( nombreArchivo, modo );

    if(         !*pf            )
    {
        perror("No se pudo crear/leer archivo\n");
        return 0;
    }
    return 1;
}


void* _bbinaria( const void* clave, const void* base, size_t ce, size_t tam, int (*comparar)(const void * a, const void * b ) )
{
    int i;

    for( i = 0; i < ce; i++ )
    {
        if(         !comparar( clave, base )           )
        {
            return (void*)base;
        }
        base += tam;
    }

    return NULL;
}

int proximaPalabra( char** cadena, char** palabra )
{
    int cantidadDeCaracteres = 0;

    while(          '\0' != *(*cadena) && !ES_LETRA( *(*cadena) )          )
    {
        (*cadena)++;
    }
    *palabra = *cadena;

    while(          ES_LETRA( *(*cadena) )          )
    {
        cantidadDeCaracteres++;
        (*cadena)++;
    }

    return cantidadDeCaracteres;
}

int _contarPalabras( FILE* pf, tRetorno* retorno )
{
    char buffer[ TAM ];
    char* aRecorrer;
    char* palabra;
    int cantidadDePalabras = 0;
    int tamPalabra;

    while(          fgets( buffer, TAM, pf )          )
    {
        aRecorrer = buffer;
        while(          (tamPalabra = proximaPalabra( &aRecorrer, &palabra ))          )
        {
            if(         tamPalabra > miStrlen( retorno->palabra )           )
            {
                miStrncpy( retorno->palabra, palabra, tamPalabra);
                *( (retorno->palabra) + tamPalabra ) = '\0';
                retorno -> cantidadDeOcurrencias = 0;
            }

            if(         !miStrncmp( palabra, retorno -> palabra, tamPalabra )            )
            {
                (retorno->cantidadDeOcurrencias)++;
            }

            cantidadDePalabras++;
        }
    }

    return cantidadDePalabras;
}

int sumTrianInfEntreDiag( int mat[][MAX_COLUMNAS], int cf, int cc )
{
    int suma = 0;
    int f;
    int c;
    int k = 0;
    int i = 0;

    if(         cf != cc            )
    {
        return 0;
    }

    for( f = cf - 1; f > cf/2; f-- )
    {
        for( c = 1 + k; c < cc - 1 - k; c++ )
        {
            suma += mat[f][c];
            i++;
        }
        k++;
    }

    return suma;
}
int sumTrianDerEntreDiag( int mat[][MAX_COLUMNAS],int cf, int cc )
{
    int suma = 0;
    int f;
    int c;
    int k = 0;

    if(         cf != cc            )
    {
        return -1;
    }

    for( c = cc-1; c > (cc/2); c-- )
    {
        for( f = 1 + k; f <= (cf-2) - k; f++ )
        {
            suma += mat[f][c];
        }
        k++;
    }

    return suma;
}

void elRelojCucu( int mat[][MAX_COLUMNAS],int cf, int cc )
{
    int f;
    int c;
    int mitad = cf/2;
    int a = 0;
    int b = 0;

    if(         cf != cc            )
    {
        return;
    }

    for( f = 0; f < cf; f++ )
    {
        for( c = 0 + a; c < cc - b; c++ )
        {
            printf(" %d ", mat[f][c]);
            if(         f < mitad            )
            {
                a--;
                b++;
            }
            else
            {
                a--;
                b++;
            }
        }
        printf("\n");
    }

}


void mostrarInt( const void* data )
{
    printf("%d\t", *(int*)data );
}

void mostrarMatriz( const void* data, int tam, int cf, int cc, void (*mostrar)( const void* data ) )
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
    printf("\n");
}

void inicializarMatriz( int mat[][MAX_COLUMNAS] )
{
    int f;
    int c;

    for( f = 0; f < MAX_FILAS; f++ )
    {
        for( c = 0; c < MAX_COLUMNAS; c++ )
        {
            mat[f][c] = f * 10 + c;
        }
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


void miStrncpy( char* destino, const char* origen, int cantACopiar )
{
    int i;

    for( i = 0; i < cantACopiar; i++ )
    {
        *destino = *origen;
        origen++;
        destino++;
    }
}
int miStrncmp( const char* cadena1, const char* cadena2, int cantidadAComparar )
{
    int i;
    for( i = 0; i < cantidadAComparar; i++ )
    {
        if(*cadena1 != *cadena2)
        {
            return *cadena1 - *cadena2;
        }
        cadena1++;
        cadena2++;
    }
    return 0;
}

