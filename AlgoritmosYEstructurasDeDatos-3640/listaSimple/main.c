#include <stdio.h>
#include <stdlib.h>
#include"lista.h"

int compararEnt2(const void* dato1, const void* dato2);
int compararEnt(void* dato1, void* dato2);
int main()
{

    int vec[] ={10,123,153,20,66,3,2123,2,2,2,2},n,i;


    tProducto productos[]={
    {1,10,1111.11},
    {2,60,22.20},
    {3,30,30.20},
    {3,50,30.20},
    {3,50,30.20},
    {3,30,30.20},
    {4,40,24.40},
    {5,50,555.00},
    {6,60,62.20},
    {9,270,9.99},
    {11,110,11011.10},
    {12,120,12.12}
    };

    tProducto aniadido = {7,100,10};
    tProducto acumulador = {2,40,22.20};

    tLista listaNumeros, listaProductos;
    crearLista(&listaNumeros);
    if(!cargarListaVector(&listaNumeros,vec,sizeof(int),sizeof(vec)/sizeof(vec[0]),insertarAlFinal))
    {
        printf("\nHubo un error, cerrando el programa\n\n");
        system("pause");
    }
    printf("\nMostrando la lista:\n");
    mostrarListaGen(&listaNumeros,mostrarNumero);

    sacarUltimo(&listaNumeros,&n,sizeof(int));

    printf("\nMostrando el ultimo elemento: %d",n);
    sacarPrimero(&listaNumeros,&n,sizeof(int));
    printf("\nMostrando el primer elemento: %d",n);
    printf("\n");
    mostrarListaGen(&listaNumeros,mostrarNumero);
    printf("\nIngrese n: "); scanf("%d",&n);
    insertarOrdenado(&listaNumeros,&n,sizeof(n),compararEnt);
    printf("\nMostrar lista ordenada: \n");
    mostrarListaGen(&listaNumeros,mostrarNumero);

    eliminarApariciones(&listaNumeros,compararEnt2);
    printf("\nMostrar lista ordenada: \n");
    mostrarListaGen(&listaNumeros,mostrarNumero);

    printf("\n\nMostrando lista ordenada de verdad!!!!!!\n");
    ordenarLista(&listaNumeros,compararEnt2);
    mostrarListaGen(&listaNumeros,mostrarNumero);


    // es memoria dinamica hay que liberarla de alguna forma, vaciarLista o sacarPri o sacarUlt y meterlo en un bucle
    vaciarLista(&listaNumeros);

    if(listaVacia(&listaNumeros))
        printf("\nLa lista esta vacia!");


    crearLista(&listaProductos);

    for(i = 0; i<11;i++)
    {
        insertarAlFinal(&listaProductos,&productos[i],sizeof(tProducto));
    }

    actualizarEnLista(&listaProductos,&aniadido,sizeof(aniadido),actualizarProductos,compararProductos);
    actualizarEnLista(&listaProductos,&acumulador,sizeof(acumulador),actualizarProductos,compararProductos);
    acumularApariciones(&listaProductos,compararProductos,acumularProductos);
    printf("\nMostrando lista de productos: ");
    mostrarListaGen(&listaProductos,mostrarProducto);
    printf("\n\nMostrando lista al reves:\n");
    mostrarListaAlRevesRecursiva(&listaProductos,mostrarProducto);

    vaciarLista(&listaNumeros);
    if(listaVacia(&listaProductos))
        printf("\nLa lista esta vacia!");

    printf("\n\n");
    system("pause");
    return 0;
}

int compararEnt(void* dato1, void* dato2)
{
    return (*(int*)dato1) - (*(int*)dato2);
}

int compararEnt2(const void* dato1, const void* dato2)
{
    return (*(int*)dato1) - (*(int*)dato2);
}

