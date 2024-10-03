#include <stdio.h>
#include <stdlib.h>
#include "pilaCircular.h"


int main()
{
    tPila pilaDeNumeros;
    int i;

    crearPila(&pilaDeNumeros);
    for(i = 0;i<9;i++)
    {
        apilar(&pilaDeNumeros,&i,sizeof(int));
    }

    while(desapilar(&pilaDeNumeros,&i,sizeof(int)))
    {
        printf("%d ",i);
    }

    return 0;
}
