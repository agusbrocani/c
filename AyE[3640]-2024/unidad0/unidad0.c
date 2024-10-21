#include "unidad0.h"

/********************PUNTO 2*********************/
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

void ejercicio2( double operando1, double operando2 )
{
    printf( "OPERANDO 1: %.2f\nOPERANDO 2: %.2f\n\n", operando1, operando2 );

    printf( "Resultado[suma] \t\t= %.2f\n", calcular( operando1, operando2, sumar ) );
    printf( "Resultado[resta] \t\t= %.2f\n", calcular( operando1, operando2, restar ) );
    printf( "Resultado[multiplicacion] \t= %.2f\n", calcular( operando1, operando2, multiplicar ) );
    printf( "Resultado[division] \t\t= %.2f\n", calcular( operando1, operando2, dividir ) );
}
/******************FIN PUNTO 2*******************/

/********************PUNTO 3*********************/
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
/******************FIN PUNTO 3*******************/

/********************PUNTO 4*********************/
int comparaPersonasPorID( const void* a, const void* b )
{
    return ((tPersona*)a)->id - ((tPersona*)b)->id;
}

void trozar( char* buffer, tPersona* dato )
{
    char* iniBuffer = buffer;

    buffer = strrchr( iniBuffer,'\n' );

    if(         buffer         )
    {
        *buffer = '\0';
    }

    buffer = strrchr( iniBuffer,'-' );

    if(         buffer         )
    {
        *buffer = '\0';
    }
    buffer++;
    dato->salario = atof(buffer);

    buffer = strrchr( iniBuffer,'-' );

    if(         buffer         )
    {
        *buffer = '\0';
    }
    buffer++;
    dato->sexo = *buffer;

    buffer = strrchr( iniBuffer,'-' );

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
    };//Este codigo esta asi porque era el primero, en las versiones siguientes recibio mejoras

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

    printf( "Eliminando elementos del vector :\n" );
    while(          ceInsertados           )
    {
        eliminarElementoEnPosicion( &vec, &dato, 0, &ceInsertados );//importante usarlo desde el inicio o ceInsertados-1 si lo coloco dentro de un while
        grabarPersona( stdout, &dato );
    }

    destruirVector( &vec );
    fclose( LotePersonasEnArchivoDeTexto );
}
/******************FIN PUNTO 4*******************/

/********************PUNTO 5*********************/
void ejercicio5( void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* LoteEnArchivoDeTexto;
    void* dato;
    tVector vec;
    char nombreArchivo[] = "LoteEnArchivoDeTexto.txt";

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
        printf( "No pude reservar memoria para dato\n" );
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
/******************FIN PUNTO 5*******************/

/********************PUNTO 6*********************/
void crearLoteBinGenFormatoCRegColeccion( const char* nombreArchivo, const void* coleccion, unsigned tam, unsigned ce, void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* pf;

    if(         !abrirArchivo( &pf, nombreArchivo, "wb" )         )
    {
        return;
    }

    fwrite( &ce, sizeof( unsigned ), 1, pf );
    fwrite( coleccion, ce * tam, 1, pf );

    fclose( pf );
}

void ejercicio6( void* coleccion, unsigned tam, unsigned ce, int (*comparar)( const void* a, const void* b), void (*grabar)( FILE* pf, const void* dato ) )
{
    FILE* LoteEnArchivoBinario;
    void* dato;
    tVector vec;
    char nombreArchivo[] = "LoteEnArchivoBinario.bin";

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
        printf( "No pude reservar memoria para dato\n" );
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

    printf( "Eliminando elementos del vector :\n" );
    while(          ceInsertados           )
    {
        eliminarElementoEnPosicion( &vec, dato, 0, &ceInsertados );//importante usarlo desde el inicio o ceInsertados-1 si lo coloco dentro de un while
        grabar( stdout, dato );
    }

    destruirVector( &vec );
    free( dato );
    fclose( LoteEnArchivoBinario );
}
/******************FIN PUNTO 6*******************/

/********************PUNTO 7*********************/
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

void mostrarConFormatoEspecialMueveFinRC2( const char* ini, const char* fin )
{
    if(         '\0' != *ini && ini <= fin           )
    {
        printf( "%c", *ini );
        mostrarConFormatoEspecialMueveFinRC2( ini + 1, fin );
    }
}

void mostrarConFormatoEspecialMueveFinRC( const char* ini, const char* fin,unsigned cantidadDeCaracteresExtraAMostrar )
{
    if(         ini + cantidadDeCaracteresExtraAMostrar < fin          )
    {
        mostrarConFormatoEspecialMueveFinRC2( ini, ini + cantidadDeCaracteresExtraAMostrar );
        printf( "\n" );
        mostrarConFormatoEspecialMueveFinRC( ini, fin, cantidadDeCaracteresExtraAMostrar + 1 );
    }
}

void mostrarConFormatoEspecialMueveFinR( const char* cadena )
{
    char* fin = mStrchrR( (char*)cadena, '\0' );
    unsigned cantidadDeCaracteresExtraAMostrar = 0;

    mostrarConFormatoEspecialMueveFinRC( cadena, fin, cantidadDeCaracteresExtraAMostrar );
}

void mostrarConFormatoEspecialMueveFinOrdenInversoRC2(const char* ini, const char* fin)
{
    if('\0' != *ini && ini <= fin)
    {
        printf("%c", *ini);
        mostrarConFormatoEspecialMueveFinOrdenInversoRC2(ini + 1, fin);
    }
}

void mostrarConFormatoEspecialMueveFinOrdenInversoRC(const char* ini, const char* fin, unsigned cantidadDeCaracteresExtraAMostrar)
{
    if(ini + cantidadDeCaracteresExtraAMostrar < fin)
    {
        mostrarConFormatoEspecialMueveFinOrdenInversoRC(ini, fin, cantidadDeCaracteresExtraAMostrar + 1);
        mostrarConFormatoEspecialMueveFinOrdenInversoRC2(ini, ini + cantidadDeCaracteresExtraAMostrar);
        printf("\n");
    }
}

void mostrarConFormatoEspecialMueveFinOrdenInversoR(const char* cadena)
{
    char* fin = mStrchrR((char*)cadena, '\0');
    unsigned cantidadDeCaracteresExtraAMostrar = 0;

    mostrarConFormatoEspecialMueveFinOrdenInversoRC(cadena, fin, cantidadDeCaracteresExtraAMostrar);
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

void mostrarEnteroCreciendoRC( int entero, int divisor )
{
    if(         divisor <= entero * 10            )
    {
        printf( "%d\n", entero % divisor );
        mostrarEnteroCreciendoRC( entero, divisor * 10 );
    }
}
void mostrarEnteroCreciendoR( int entero )
{
    mostrarEnteroCreciendoRC( entero, 10 );
}

void mostrarEnteroCreciendoOrdenInversoRC( int entero, int divisor )
{
    if(         divisor <= entero * 10            )
    {
        mostrarEnteroCreciendoOrdenInversoRC( entero, divisor * 10 );
        printf( "%d\n", entero % divisor );
    }
}

void mostrarEnteroCreciendoOrdenInversoR( int entero )
{
    mostrarEnteroCreciendoOrdenInversoRC( entero, 10 );
}

void mostrandoSumaDigitosEnteroRC( int entero, int divisor, int* suma )
{
    if(         divisor < entero            )
    {
        *suma += ( ( entero % ( 10* divisor ) )/ divisor );
        mostrandoSumaDigitosEnteroRC( entero, divisor * 10, suma );
    }
}

void mostrandoSumaDigitosEnteroR( int entero )
{
    int suma = entero % 10;

    mostrandoSumaDigitosEnteroRC( entero, 10, &suma );
    printf( "\nEntero: %d\n", entero );
    printf( "Suma= %d\n", suma );
}

void mostrandoSumaCaracteresDigitosEnteroRC( const char* cadena, int* suma )
{
    if(         *cadena         )
    {
        if(         ES_NUMERO( *cadena )           )
        {
            *suma += A_NUMERO( *cadena );
        }
        mostrandoSumaCaracteresDigitosEnteroRC( cadena + 1, suma );
    }
}
void mostrandoSumaCaracteresDigitosEnteroR( const char* cadena )
{
    int suma = 0;

    mostrandoSumaCaracteresDigitosEnteroRC( cadena, &suma );
    printf( "\nCadena: %s\n", cadena );
    printf( "Suma= %d\n", suma );
}

void mostrarArrayEnterosYSuSumaIRC( int* vectorDeEnteros, unsigned ce, int* suma )
{
    if(         ce          )
    {
        *suma += *vectorDeEnteros;
        mostrarArrayEnterosYSuSumaIRC( vectorDeEnteros + 1, ce - 1, suma );
        printf( "%d\t", *vectorDeEnteros );
    }
}

void mostrarArrayEnterosYSuSumaIR( int* vectorDeEnteros, unsigned ce )
{
    int suma = 0;

    mostrarArrayEnterosYSuSumaIRC( vectorDeEnteros, ce, &suma );

    printf( "\nSuma= %d\n", suma );
}

void mostrarArrayEnterosYSuSumaDigitosParesIRC( int* vectorDeEnteros, unsigned ce, int* suma )
{
    if(         ce          )
    {
        if(         0 == ( *vectorDeEnteros % 2 )            )
        {
           *suma += *vectorDeEnteros;
        }

        mostrarArrayEnterosYSuSumaDigitosParesIRC( vectorDeEnteros + 1, ce - 1, suma );
        printf( "%d\t", *vectorDeEnteros );
    }
}

void mostrarArrayEnterosYSuSumaDigitosParesIR( int* vectorDeEnteros, unsigned ce )
{
    int suma = 0;

    mostrarArrayEnterosYSuSumaDigitosParesIRC( vectorDeEnteros, ce, &suma );

    printf( "\nSuma= %d\n", suma );
}

void mostrarArrayEnterosYSuSumaDigitosEnPosParesIRC( int* vectorDeEnteros, unsigned ce, int* suma, unsigned pos )
{
    if(            ce > 0          )
    {
        if(            0 == pos % 2            )
        {
            *suma += *vectorDeEnteros;
        }
        printf( "%d\t", *vectorDeEnteros );
        mostrarArrayEnterosYSuSumaDigitosEnPosParesIRC( vectorDeEnteros + 1, ce - 1, suma, pos + 1 );
    }
}

void mostrarArrayEnterosYSuSumaDigitosEnPosParesIR( int* vectorDeEnteros, unsigned ce )
{
    int suma = 0;

    mostrarArrayEnterosYSuSumaDigitosEnPosParesIRC( vectorDeEnteros, ce, &suma, 0 );

    printf( "\nSuma = %d\n", suma );
}

void ejercicio7()
{
    int n = 5;
    char cadena[] = "Hola";
    int entero = 1234;//suma = 10
    char* retornoMStrchrR;
    char* retornoMStrrchrR;
    char caracterBuscado = '\0';
    char cadenaConNumeros[] = "  a1aa2e3c@4";//suma = 10
    int vectorDeEnteros[] = {10,2,2,3,4,5,6,7,8,9};//suma = 56 - sumaPares = 32 - sumaPosPares = 30
    int ce = sizeof( vectorDeEnteros ) / sizeof( vectorDeEnteros[0] );

    printf( "Valor del factorial de %d: %d\n", n, factorial( n ) );

    printf( "\nMostrar en orden:\n" );
    mostrarEnOrdenR( cadena );

    printf( "\nMostrar en orden inverso:\n" );
    mostrarEnOrdenInversoR( cadena );

    printf( "\nMostrar con formato especial Mueve Inicio:\n" );
    mostrarConFormatoEspecialMueveInicioR( cadena );

    printf( "\nMostrar con formato especial Mueve Inicio orden inverso:\n" );
    mostrarConFormatoEspecialMueveInicioOrdenInversoR( cadena );

    printf( "\nMostrar con formato especial Mueve Fin:\n" );
    mostrarConFormatoEspecialMueveFinR( cadena );

    printf( "\nMostrar con formato especial Mueve Fin orden inverso:\n" );
    mostrarConFormatoEspecialMueveFinOrdenInversoR( cadena );

    printf( "\nMostrando entero descompuesto:\n" );
    mostrarEnteroDescompuestoR( entero );

    printf( "\nMostrando entero descompuesto orden inverso:\n" );
    mostrarEnteroDescompuestoOrdenInversoR( entero );

    printf( "\nMostrando entero disminuyendo:\n" );
    mostrarEnteroDisminuyendoR( entero );

    printf( "\nMostrando entero disminuyendo orden inverso:\n" );
    mostrarEnteroDisminuyendoOrdenInversoR( entero );

    printf( "\nMostrando entero creciendo:\n" );
    mostrarEnteroCreciendoR( entero );

    printf( "\nMostrando entero creciendo orden inverso:\n" );
    mostrarEnteroCreciendoOrdenInversoR( entero );

    printf( "\nMostrando suma de digitos de entero:\n" );
    mostrandoSumaDigitosEnteroR( entero );

    printf( "\nMostrando suma de los caracteres que representan digitos:\n" );
    mostrandoSumaCaracteresDigitosEnteroR( cadenaConNumeros );

    printf( "\nMostrando array de enteros en orden inverso y la suma de sus digitos:\n" );
    mostrarArrayEnterosYSuSumaIR( vectorDeEnteros, ce );

    printf( "\nMostrando array de enteros en orden inverso y la suma de sus digitos pares:\n" );
    mostrarArrayEnterosYSuSumaDigitosParesIR( vectorDeEnteros, ce );

    printf( "\nMostrando array de enteros en orden inverso y la suma de sus digitos en posiciones pares:\n" );
    mostrarArrayEnterosYSuSumaDigitosEnPosParesIR( vectorDeEnteros, ce );

    caracterBuscado = 'a';
    retornoMStrchrR = mStrchrR( cadena, caracterBuscado );
    retornoMStrrchrR = mStrrchrR( cadena, caracterBuscado );

    if(         mStrlenR( cadena ) == strlen( cadena ) && retornoMStrchrR == strchr( cadena, caracterBuscado ) && retornoMStrrchrR == strrchr( cadena, caracterBuscado )           )
    {
        printf( "\nLas funciones mStrlenR, mStrchrR y mStrrchrR estan bien programadas\n" );
    }
}
/******************FIN PUNTO 7*******************/
