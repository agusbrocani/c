#include "bibliotecaGeneralDePila.h"

#define NOMBRE_ARCHIVO_PRODUCTOS_ORDENADO "loteDeProductosOrdenado.txt"
#define NO_PUDE_ABRIR_ARCHIVO 1

#define NOMBRE_ARCHIVO_NUMERO1 "numero1.txt"
#define NOMBRE_ARCHIVO_NUMERO2 "numero2.txt"
#define NOMBRE_ARCHIVO_RESULTADO "resultado.txt"

#define ES_NUMERO( X ) ( ( ( X ) >= '0' ) && ( ( X ) <= '9' ) )
#define A_NUMERO( X ) ( ( X ) - '0' )

void crearLoteNumero( const char* nombreArchivo, const char* numero )
{
    FILE* pf;

    if(         !abrirArchivo( &pf, nombreArchivo, "wt" )         )
    {
        return;
    }

    fprintf( pf, "%s\n", numero );

    fclose( pf );
}

void grabarEntero( FILE* pf, const void* dato )
{
    fprintf( pf, "%d", *(int*)dato );

    if(         stdout == pf            )
    {
        printf("\n");
    }
}

int main()
{
    FILE* loteBinarioDeProductos;
    FILE* loteDeProductosOrdenadoTxt;
    tPila pilaDeProductos;
    tPila testTDAPila;
    tProducto producto;
    unsigned tam = sizeof( tProducto );

    FILE* aNumero1;
    FILE* aNumero2;
    FILE* aResultado;
    tPila pNumero1;
    tPila pNumero2;
    tPila resultado;
    int numero;
    int tamEntero = sizeof( int );
    char numeroLeidoComoCaracter;

    char numero1[] = "444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444";
    char numero2[] = "12";

    crearLoteProductos();

    if(         !abrirArchivo( &loteBinarioDeProductos, NOMBRE_ARCHIVO_PRODUCTOS, "rb" )         )
    {
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    if(         !abrirArchivo( &loteDeProductosOrdenadoTxt, NOMBRE_ARCHIVO_PRODUCTOS_ORDENADO, "wt" )         )
    {
        fclose( loteBinarioDeProductos );
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    printf( "\t\t--------INICIO TEST TDA PILA--------\n\n" );
    crearPila( &pilaDeProductos );
    crearPila( &testTDAPila );

    printf( "Apilando productos:\n\n" );
    fread( &producto, tam, 1, loteBinarioDeProductos );

    while(         !feof( loteBinarioDeProductos )         )
    {
        mostrarProducto( &producto );
        apilar( &pilaDeProductos, &producto, tam );
        apilar( &testTDAPila, &producto, tam );
        fread( &producto, tam, 1, loteBinarioDeProductos );
    }

    system( "pause" );
    system( "cls" );

    printf( "Viendo tope:\n\n" );
    if(         verTope( &testTDAPila, &producto, tam )           )
    {
        mostrarProducto( &producto );
    }

    system( "pause" );
    system( "cls" );

    printf( "Desapilando productos:\n\n" );
    while(          desapilar( &testTDAPila, &producto, tam )          )
    {
        mostrarProducto( &producto );
    }

    system( "pause" );
    system( "cls" );

    printf( "**********INICIO TEST DE ORDENAR CON 2 PILAS************\n" );
    ordenarConDosPilas( loteDeProductosOrdenadoTxt, &pilaDeProductos, tam, comparaProductosPorCodProd, grabarProductos );

    printf( "\n\t\tPILA DE PRODUCTOS ORDENADA\n" );

    printf( "\n*********TEST DE ORDENAR CON 2 PILAS TERMINADO**********\n" );
    system( "pause" );
    system( "cls" );

    printf( "Vaciando pila\n");
    vaciarPila( &testTDAPila );
    vaciarPila( &pilaDeProductos );
    fclose( loteBinarioDeProductos );
    fclose( loteDeProductosOrdenadoTxt );

    if(         pilaVacia( &testTDAPila )          )
    {
        printf( "PilaVacia\n" );
    }

    if(         !pilaLlena( &testTDAPila, tam )          )
    {
        printf( "Pila NO Llena: hay lugar\n" );
    }

    system( "pause" );
    system( "cls" );

    printf( "**********INICIO TEST SUMAR ENTEROS CON 2 PILAS************\n" );
    crearLoteNumero( NOMBRE_ARCHIVO_NUMERO1, numero1 );
    crearLoteNumero( NOMBRE_ARCHIVO_NUMERO2, numero2 );

    if(         !abrirArchivo( &aNumero1, NOMBRE_ARCHIVO_NUMERO1, "rt" )         )
    {
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    if(         !abrirArchivo( &aNumero2, NOMBRE_ARCHIVO_NUMERO2, "rt" )         )
    {
        fclose( aNumero1 );
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    if(         !abrirArchivo( &aResultado, NOMBRE_ARCHIVO_RESULTADO, "wt" )          )
    {
        fclose( aNumero1 );
        fclose( aNumero2 );
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    crearPila( &pNumero1 );
    crearPila( &pNumero2 );
    crearPila( &resultado );

    while(          EOF != ( numeroLeidoComoCaracter = fgetc( aNumero1 ) )           )
    {
        if(         ES_NUMERO( numeroLeidoComoCaracter )         )
        {
            numero = A_NUMERO( numeroLeidoComoCaracter );
            apilar( &pNumero1, &numero, tamEntero );
        }
    }

    while(          EOF != ( numeroLeidoComoCaracter = fgetc( aNumero2 ) )           )
    {
        if(         ES_NUMERO( numeroLeidoComoCaracter )         )
        {
            numero = A_NUMERO( numeroLeidoComoCaracter );
            apilar( &pNumero2, &numero, tamEntero );
        }
    }

    printf( "Numero 1:\n" );
    printf( "%s\n", numero1 );
    printf( "Numero 2:\n" );
    printf( "%s\n", numero2 );
    sumarEnterosConDosPilas( &resultado, &pNumero1, &pNumero2, aResultado, grabarEntero );

    while(          desapilar( &resultado, &numero, tamEntero )         )
    {
        grabar( stdout, &numero, grabarEntero );
        grabar( aResultado, &numero, grabarEntero );
    }

    vaciarPila( &pNumero1 );
    vaciarPila( &pNumero2 );
    vaciarPila( &resultado );
    fclose( aNumero1 );
    fclose( aNumero2 );
    fclose( aResultado );

    printf( "\n************FIN TEST SUMAR ENTEROS CON 2 PILAS*************\n" );
    system( "pause" );
    system( "cls" );

    printf( "\t\t---------FIN TEST TDA PILA---------\n" );
    system( "pause" );
    system( "cls" );

    return 0;
}
