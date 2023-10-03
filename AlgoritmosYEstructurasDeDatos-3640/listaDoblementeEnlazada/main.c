#include <stdio.h>
#include <stdlib.h>
#include  "lista.h"

void mostrarNumero(const void* d);
int compararNumeros(const void* a, const void* b);
int busquedaEnt(const void* a, const void* b);

int main()
{
    tListad listaNumeros,listaRepetidos,listaRepetidosTotales;
    crearLista(&listaNumeros);
    int vector[] = {1,2,3,4,5},vector2[]={43,4,5,5,1,5,2,1,1,1},vector3[]={1,2,2,2,2,3,2,2,2,1,2},i;
    for(i = 0; i<sizeof(vector)/sizeof(int);i++)
    {
        insertar(&listaNumeros,&(vector[i]),sizeof(int));
    }
    printf("mostramos la lista de izquierda a derecha:\n");
    mostrarIzqDer(&listaNumeros,mostrarNumero);
    printf("\nmostramos la lista de derecha a izquierda:\n");
    mostrarDerIzq(&listaNumeros,mostrarNumero);

    printf("\nQue numero desea insertar de forma ordenada en la lista?: "); scanf("%d",&i);
    insertarEnOrden(&listaNumeros,&i,sizeof(int),compararNumeros);

    printf("mostramos la lista de izquierda a derecha:\n");
    mostrarIzqDer(&listaNumeros,mostrarNumero);

    while(eliminarElemento(&listaNumeros,&i,sizeof(int)))
    {
        printf("\nEliminando %d",i);
    }

    crearLista(&listaRepetidos);
    for(i = 0; i<sizeof(vector2)/sizeof(int);i++)
    {
        insertar(&listaRepetidos,&(vector2[i]),sizeof(int));
    }
    printf("\nmostramos la lista antes de eliminar la aparicion del 1:\n");
    mostrarIzqDer(&listaRepetidos,mostrarNumero);

    i = 1;

    elimDuplicadosDesordenados(&listaRepetidos,&i,busquedaEnt);

    printf("mostramos la lista despues de eliminar la aparicion del 1:\n");
    mostrarIzqDer(&listaRepetidos,mostrarNumero);


    printf("\nVaciando la lista:\n");
    while(eliminarElemento(&listaRepetidos,&i,sizeof(int)))
    {
        printf("\nEliminando %d",i);
    }

    crearLista(&listaRepetidosTotales);

    for(i = 0; i<sizeof(vector3)/sizeof(int);i++)
    {
        insertar(&listaRepetidosTotales,&(vector3[i]),sizeof(int));
    }
    printf("\n\nmostramos la lista antes de la eliminacion de repetidos:\n");
    mostrarIzqDer(&listaRepetidosTotales,mostrarNumero);

    eliminarDuplicadosDesordenadosTodosValores(&listaRepetidosTotales,busquedaEnt);

    printf("\n\nmostramos la lista despues de la eliminacion de repetidos:\n");
    mostrarIzqDer(&listaRepetidosTotales,mostrarNumero);

    printf("\nVaciando la lista:\n");
    while(eliminarElemento(&listaRepetidosTotales,&i,sizeof(int)))
    {
        printf("\nEliminando %d",i);
    }



    printf("\n\n");

    system("pause");
    return 0;
}

void mostrarNumero(const void* d)
{
    printf("%d ",*(int*)d);
    return;
}

int compararNumeros(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

/**
int strlen_recursiva(char* s) //es un puntero a la cadena hola
{
    if(*s)
    {
        return 1+strlen_recursiva(s+1); //caso recursivo
    }
    else // ultimo llamamiento
    {
        return 0; //caso base 1+1+1+1+0
    }
}

int sumar(int a, int b)
{
    if(a)
    {
        return 1+sumar(a-1,b);
    }
    else{
        return b;
    }

}
**/
int busquedaEnt(const void* a, const void* b)
{
    return *(int*)a == *(int*)b;
}
