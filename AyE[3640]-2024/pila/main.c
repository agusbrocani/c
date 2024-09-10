#include "bibliotecaGeneralDePila.h"

#define NO_PUDE_ABRIR_ARCHIVO 1

int main()
{
    FILE* loteBinarioDeProductos;
    tPila pilaDeProductos;
    tPila testTDAPila;
    tProducto producto;
    unsigned tam = sizeof( tProducto );

    crearLoteProductosBinario();

    if(!abrirArchivo( &loteBinarioDeProductos, NOMBRE_ARCHIVO_PRODUCTOS, "rb" ))
    {
        return NO_PUDE_ABRIR_ARCHIVO;
    }

    printf( "\t\t--------INICIO TEST TDA PILA--------\n\n" );
    crearPila(&pilaDeProductos);
    crearPila(&testTDAPila);

    printf("Apilando productos:\n\n");

    fread(&producto, tam, 1, loteBinarioDeProductos);
    while(!feof( loteBinarioDeProductos ))
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

    printf( "Vaciando pila\n");
    vaciarPila( &testTDAPila );
    vaciarPila( &pilaDeProductos );
    fclose( loteBinarioDeProductos );

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

    printf( "\t\t---------FIN TEST TDA PILA---------\n" );
    system( "pause" );
    system( "cls" );

    return 0;
}
