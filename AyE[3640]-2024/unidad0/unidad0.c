#include "unidad0.h"

double sumar( double operando1, double operando2 )
{
    return operando1 + operando2;
}

double restar( double operando1, double operando2 )
{
    return operando1 - operando2;
}

double multiplicar( double operando1, double operando2 )
{
    return operando1 * operando2;
}

double dividir( double operando1, double operando2 )
{
    if(         0 == operando2          )
    {
        printf( "\t\t****************No puedo dividir por cero****************\n" );
        return NO_PUEDO_DIVIDIR_POR_CERO;
    }

    return operando1 / operando2;
}

double calcular( double operando1, double operando2, double (*operacion)( double operando1, double operando2 ) )
{
    return operacion( operando1, operando2 );
}

void ejercicio2()
{
    double operando1 = 2;
    double operando2 = 0;

    printf( "OPERANDO 1: %.2f\nOPERANDO 2: %.2f\n\n", operando1, operando2 );

    printf( "Resultado[suma] \t\t= %.2f\n", calcular( operando1, operando2, sumar ) );
    printf( "Resultado[resta] \t\t= %.2f\n", calcular( operando1, operando2, restar ) );
    printf( "Resultado[multiplicacion] \t= %.2f\n", calcular( operando1, operando2, multiplicar ) );
    printf( "Resultado[division] \t\t= %.2f\n", calcular( operando1, operando2, dividir ) );
}

void grabarEntero( FILE* pf, const void* dato )
{
    fprintf( pf, "%d\n", *(int*)dato );
}
void grabarPersona( FILE* pf, const void* dato )
{
    fprintf( pf, "%d-%s-%c-%.2f\n",
                                ((tPersona*)dato)->id,
                                ((tPersona*)dato)->nya,
                                ((tPersona*)dato)->sexo,
                                ((tPersona*)dato)->salario
            );
}

void crearLoteTxtGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* pf;
    int i;

    if(         !abrirArchivo( &pf, nombreArchivo, "wt" )         )
    {
        return;
    }

    fprintf( pf, "%u\n", ce );

    for( i = 0; i < ce; i++ )
    {
        grabar( pf, coleccion );
        coleccion += tam;
    }

    fclose( pf );
}

int comparaEnteros( const void* a, const void* b )
{
    return *(int*)a - *(int*)b;
}

void ejercicio3()
{
    tVector vec;
    FILE* LoteNumerosEnArchivoDeTexto;
    char nombreArchivo[] = "LoteNumerosEnArchivoDeTexto.txt";

    int coleccion[] = {23,13,18};
    int ce = sizeof( coleccion ) / sizeof( coleccion[0] );
    int tam = sizeof( coleccion[0] );

    char buffer[ TAM_BUFFER ];
    int cantidadDeRegistros;
    int dato;
    unsigned ceInsertados = 0;

    crearLoteTxtGenFormatoCRegColeccion( nombreArchivo, coleccion, tam, ce, grabarEntero );

    if(         !abrirArchivo( &LoteNumerosEnArchivoDeTexto, nombreArchivo, "rt" )         )
    {
        return;
    }

    crearVector( &vec, sizeof( coleccion[0] ) );

    if(         fgets( buffer, TAM_BUFFER, LoteNumerosEnArchivoDeTexto )            )
    {
        cantidadDeRegistros = atoi( buffer );
        printf( "Cantidad de registros del lote: %d\n", cantidadDeRegistros );
    }

    while(          fgets( buffer, TAM_BUFFER, LoteNumerosEnArchivoDeTexto )            )
    {
        dato = atoi( buffer );
        insertarOrdenado( &vec, &dato, &ceInsertados, comparaEnteros );
    }

    while(          ceInsertados           )
    {
        eliminarElementoEnPosicion( &vec, &dato, ceInsertados - 1, &ceInsertados );
        printf( "Eliminando elementos del vector : %d\n", dato );
    }

    destruirVector( &vec );
    fclose( LoteNumerosEnArchivoDeTexto );
}

int comparaPersonasPorID( const void* a, const void* b )
{
    return ((tPersona*)a)->id - ((tPersona*)b)->id;
}

void trozar( char* buffer, tPersona* dato )
{
    char* iniBuffer = buffer;

    buffer = strrchr( iniBuffer,'\n');

    if(         buffer         )
    {
        *buffer = '\0';
    }

    buffer = strrchr( iniBuffer,'-');

    if(         buffer         )
    {
        *buffer = '\0';
    }
    buffer++;
    dato->salario = atof(buffer);

    buffer = strrchr( iniBuffer,'-');

    if(         buffer         )
    {
        *buffer = '\0';
    }
    buffer++;
    dato->sexo = *buffer;

    buffer = strrchr( iniBuffer,'-');

    if(         buffer         )
    {
        *buffer = '\0';
    }
    buffer++;
    strcpy( dato->nya, buffer );

    dato->id = atoi( iniBuffer );
}

void ejercicio4()
{
    tVector vec;
    FILE* LotePersonasEnArchivoDeTexto;
    char nombreArchivo[] = "LotePersonasEnArchivoDeTexto.txt";

    tPersona coleccion[] =
    {
        {5,"Pablo M",'M',5000},
        {4,"Karen B",'F',7500},
        {1,"Agustin Brocani",'M',8900},
        {3,"Franco Ruggieri",'M',6000},
        {2,"Federico Martucci",'M',8900}
    }
    ;
    int ce = sizeof( coleccion ) / sizeof( coleccion[0] );
    int tam = sizeof( coleccion[0] );

    char buffer[ TAM_BUFFER ];
    int cantidadDeRegistros;
    tPersona dato;
    unsigned ceInsertados = 0;

    crearLoteTxtGenFormatoCRegColeccion( nombreArchivo, coleccion, tam, ce, grabarPersona );

    if(         !abrirArchivo( &LotePersonasEnArchivoDeTexto, nombreArchivo, "rt" )         )
    {
        return;
    }

    crearVector( &vec, sizeof( coleccion[0] ) );

    if(         fgets( buffer, TAM_BUFFER, LotePersonasEnArchivoDeTexto )            )
    {
        cantidadDeRegistros = atoi( buffer );
        printf( "Cantidad de registros del lote: %d\n", cantidadDeRegistros );
    }

    while(          fgets( buffer, TAM_BUFFER, LotePersonasEnArchivoDeTexto )            )
    {
        trozar( buffer, &dato );
        insertarOrdenado( &vec, &dato, &ceInsertados, comparaPersonasPorID );
    }

    printf( "Eliminando elementos del vector :\n");
    while(          ceInsertados           )
    {
        eliminarElementoEnPosicion( &vec, &dato, 0, &ceInsertados );//importante usarlo desde el inicio o ceInsertados-1 si lo coloco dentro de un while
        grabarPersona( stdout, &dato );
    }

    destruirVector( &vec );
    fclose( LotePersonasEnArchivoDeTexto );
}

void ejercicio5( const void* nombreArchivo, void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* LoteEnArchivoDeTexto;
    void* dato;
    tVector vec;

    char buffer[ TAM_BUFFER ];
    int cantidadDeRegistros;
    unsigned ceInsertados = 0;

    crearLoteTxtGenFormatoCRegColeccion( nombreArchivo, coleccion, tam, ce, grabar );

    if(         !abrirArchivo( &LoteEnArchivoDeTexto, nombreArchivo, "rt" )         )
    {
        return;
    }

    crearVector( &vec, tam );

    if(         fgets( buffer, TAM_BUFFER, LoteEnArchivoDeTexto )            )
    {
        cantidadDeRegistros = atoi( buffer );
        printf( "Cantidad de registros del lote: %d\n", cantidadDeRegistros );
    }

    dato = malloc( tam );

    if(         !dato           )
    {
        printf("No pude reservar memoria para dato\n");
        destruirVector( &vec );
        fclose( LoteEnArchivoDeTexto );
        return;
    }

    while(          fgets( buffer, TAM_BUFFER, LoteEnArchivoDeTexto )            )
    {
        trozar( buffer, dato );
        insertarOrdenado( &vec, dato, &ceInsertados, comparar );
    }

    printf( "Eliminando elementos del vector :\n");
    while(          ceInsertados           )
    {
        eliminarElementoEnPosicion( &vec, dato, 0, &ceInsertados );//importante usarlo desde el inicio o ceInsertados-1 si lo coloco dentro de un while
        grabar( stdout, dato );
    }

    destruirVector( &vec );
    free( dato );
    fclose( LoteEnArchivoDeTexto );
}

void crearLoteBinGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* pf;

    if(         !abrirArchivo( &pf, nombreArchivo, "wb" )         )
    {
        return;
    }

    fwrite( &ce, sizeof( unsigned ), 1, pf );
    fwrite( coleccion, ce * tam, 1, pf);

    fclose( pf );
}

void ejercicio6( const void* nombreArchivo, void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* LoteEnArchivoBinario;
    void* dato;
    tVector vec;

    int cantidadDeRegistros;
    unsigned ceInsertados = 0;

    crearLoteBinGenFormatoCRegColeccion( nombreArchivo, coleccion, tam, ce, grabar );

    if(         !abrirArchivo( &LoteEnArchivoBinario, nombreArchivo, "rb" )         )
    {
        return;
    }

    crearVector( &vec, tam );

    fread( &cantidadDeRegistros, sizeof( unsigned ), 1, LoteEnArchivoBinario );
    if(         !feof( LoteEnArchivoBinario )           )
    {
        printf( "Cantidad de registros del lote: %d\n", cantidadDeRegistros );
    }

    dato = malloc( tam );

    if(         !dato           )
    {
        printf("No pude reservar memoria para dato\n");
        destruirVector( &vec );
        fclose( LoteEnArchivoBinario );
        return;
    }

    fread( dato, tam, 1, LoteEnArchivoBinario );
    while(          !feof( LoteEnArchivoBinario )           )
    {
        insertarOrdenado( &vec, dato, &ceInsertados, comparar );
        fread( dato, tam, 1, LoteEnArchivoBinario );
    }

    printf( "Eliminando elementos del vector :\n");
    while(          ceInsertados           )
    {
        eliminarElementoEnPosicion( &vec, dato, 0, &ceInsertados );//importante usarlo desde el inicio o ceInsertados-1 si lo coloco dentro de un while
        grabar( stdout, dato );
    }

    destruirVector( &vec );
    free( dato );
    fclose( LoteEnArchivoBinario );
}

size_t mStrlenR( const char* cadena )
{
    return '\0' == *cadena ? 0 : 1 + mStrlenR( cadena + 1 );
}

char* mStrchrR( char* s, int c )
{
    if(         *s && c != *s           )
    {
        return strchr( s + 1, c );
    }

    if(         c == *s          )
    {
        return s;
    }

    return NULL;
}

char* mStrrchrRC( char* ini, char* fin, int c )
{
    if(         ini <= fin           )
    {
        if(         c == *fin           )
        {
            return fin;
        }
        return mStrrchrRC( ini, fin - 1, c );
    }

    return NULL;
}

char* mStrrchrR( char* s, int c )
{
    return mStrrchrRC( s, mStrchrR( s, '\0' ), c );
}

int factorial( int n )
{
    return n < 0 ? NO_PUEDO_CALCULAR_EL_FACTORIAL_DE_NEGATIVOS : ( n < 2 ? 1 : n * factorial( n - 1 ) );
}

void mostrarEnOrdenR( const char* cadena )
{
    if(         *cadena         )
    {
        printf( "'%c'\t", *cadena );
        mostrarEnOrdenR( cadena + 1 );
    }
}

void mostrarEnOrdenInversoR( const char* cadena )
{
    if(         *cadena         )
    {
        mostrarEnOrdenInversoR( cadena + 1 );
        printf( "'%c'\t", *cadena );
    }
}

void mostrarConFormatoEspecialMueveInicioR( const char* cadena )
{
    if(         *cadena         )
    {
        printf( "%s\n", cadena );
        mostrarConFormatoEspecialMueveInicioR( cadena + 1 );
    }
}

void mostrarConFormatoEspecialMueveInicioOrdenInversoR( const char* cadena )
{
    if(         *cadena         )
    {
        mostrarConFormatoEspecialMueveInicioOrdenInversoR( cadena + 1 );
        printf( "%s\n", cadena );
    }
}

void mostrarConFormatoEspecialMueveFinRC( const char* ini, const char* fin )
{

}

void mostrarConFormatoEspecialMueveFinR( const char* cadena )
{
    const char* fin = cadena + mStrlenR( cadena );

    if(         cadena < fin            )
    {
        mostrarConFormatoEspecialMueveFinRC( cadena, fin - 1 );
    }
}

void mostrarConFormatoEspecialMueveFinOrdenInversoRC( const char* ini, const char* fin )
{

}

void mostrarConFormatoEspecialMueveFinOrdenInversoR( const char* cadena )
{
    const char* fin = cadena + mStrlenR( cadena );

    if(         cadena < fin            )
    {
        mostrarConFormatoEspecialMueveFinOrdenInversoRC( cadena, fin - 1 );
    }
}

void mostrarEnteroDescompuestoR( int entero )
{
    if(         entero / 10         )
    {
        printf( "%d\n", entero % 10  );
        mostrarEnteroDescompuestoR( entero / 10 );
        return;
    }

    printf( "%d\n", entero % 10 );
}

void mostrarEnteroDescompuestoOrdenInversoR( int entero )
{
    if(         entero / 10         )
    {
        mostrarEnteroDescompuestoOrdenInversoR( entero / 10 );
    }
    printf( "%d\n", entero % 10  );
}

void mostrarEnteroDisminuyendoR( int entero )
{
    if(         entero          )
    {
        printf( "%d\n", entero );
        mostrarEnteroDisminuyendoR( entero / 10 );
    }
}

void mostrarEnteroDisminuyendoOrdenInversoR( int entero )
{
    if(         entero          )
    {
        mostrarEnteroDisminuyendoOrdenInversoR( entero / 10 );
        printf( "%d\n", entero );
    }
}

void mostrarEnteroCreciendoR( int entero )
{

}

void mostrarEnteroCreciendoOrdenInversoR( int entero )
{

}

void ejercicio7()
{
    int n = 5;
    char cadena[] = "HolaH";
    int entero = 1234;
    char* retornoMStrchrR;
    char* retornoMStrrchrR;
    char caracterBuscado = '\0';

    printf("Valor del factorial de %d: %d\n", n, factorial( n ) );

    printf("\nMostrar en orden:\n");
    mostrarEnOrdenR( cadena );

    printf("\nMostrar en orden inverso:\n");
    mostrarEnOrdenInversoR( cadena );

    printf("\nMostrar con formato especial Mueve Inicio:\n");
    mostrarConFormatoEspecialMueveInicioR( cadena );

    printf("\nMostrar con formato especial Mueve Inicio orden inverso:\n");
    mostrarConFormatoEspecialMueveInicioOrdenInversoR( cadena );

//    printf("\nMostrar con formato especial Mueve Fin:\n");
//    mostrarConFormatoEspecialMueveFinR( cadena );
//
//    printf("\nMostrar con formato especial Mueve Fin orden inverso:\n");
//    mostrarConFormatoEspecialMueveFinOrdenInversoR( cadena );

    printf("\nMostrando entero descompuesto:\n");
    mostrarEnteroDescompuestoR( entero );

    printf("\nMostrando entero descompuesto orden inverso:\n");
    mostrarEnteroDescompuestoOrdenInversoR( entero );

    printf("\nMostrando entero disminuyendo:\n");
    mostrarEnteroDisminuyendoR( entero );

    printf("\nMostrando entero disminuyendo orden inverso:\n");
    mostrarEnteroDisminuyendoOrdenInversoR( entero );

//    printf("\nMostrando entero creciendo:\n");
//    mostrarEnteroCreciendoR( entero );
//
//    printf("\nMostrando entero creciendo orden inverso:\n");
//    mostrarEnteroCreciendoOrdenInversoR( entero );

    /**
        Dado un número entero, retorne la suma de sus dígitos.

        Dada una cadena que solo contiene dígitos, retorne la suma de los caracteres que
        representan dígitos.

        Muestre el contenido de un array de enteros en orden inverso, devolviendo la suma de todos
        los elementos.

        Ídem anterior, devolviendo la suma de los pares.
        Ídem anterior, devolviendo la suma de los que están en posiciones pares.
    */

    caracterBuscado = 'a';
    retornoMStrchrR = mStrchrR( cadena, caracterBuscado );
    retornoMStrrchrR = mStrrchrR( cadena, caracterBuscado );

    if(         mStrlenR( cadena ) == strlen( cadena ) && retornoMStrchrR == strchr( cadena, caracterBuscado ) && retornoMStrrchrR == strrchr( cadena, caracterBuscado )           )
    {
        printf("\nLas funciones mStrlenR, mStrchrR y mStrrchrR estan bien programadas\n");
    }

}
