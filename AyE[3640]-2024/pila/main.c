#include "bibliotecaGeneralDePila.h"

#define NOMBRE_ARCHIVO_PRODUCTOS_ORDENADO "loteDeProductosOrdenado.txt"
#define NO_PUDE_ABRIR_ARCHIVO 1

int main()
{
    FILE* loteBinarioDeProductos;
    FILE* loteDeProductosOrdenadoTxt;
    tPila pilaDeProductos;
    tPila testTDAPila;
    tProducto producto;
    unsigned tam = sizeof( tProducto );

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

    printf( "*******INICIO TEST TDA PILA*********\n\n" );
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

    printf("Vaciando pila\n");
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

    printf( "*********FIN TEST TDA PILA**********\n" );
    system( "pause" );
    system( "cls" );
    //    sumarEnterosConDosPilas();

    return 0;
}
