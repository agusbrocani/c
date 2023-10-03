#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int compararEnt(const void* a, const void* b);
void mostrarEnt(const void*a);

int main()
{
    int vector[]={100,50,25,65,150},i;
    tArbol arbolNumeros;
    crearArbol(&arbolNumeros);

    for(i = 0; i<sizeof(vector)/sizeof(vector[0]);i++)
    {
        insertarEnArbol(&arbolNumeros,&(vector[i]),sizeof(int),compararEnt);
    }

    printf("\nPreorden\n");
    recorrerPreOrden(&arbolNumeros,mostrarEnt);
    printf("\nInorden\n");
    recorrerOrden(&arbolNumeros,mostrarEnt);
    printf("\nPostOrden\n");
    recorrerPostOrden(&arbolNumeros,mostrarEnt);
    printf("\n\n");
    printf("\nMostrando el arbol:\n");
    mostrarArbol(&arbolNumeros,mostrarEnt);
    printf("\n\n");
    system("pause");
    return 0;
}

int compararEnt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void mostrarEnt(const void*a)
{
    printf("%d ",*(int*)a);
}



