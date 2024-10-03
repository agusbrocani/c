#include <stdio.h>
#include <stdlib.h>
#include"cola.h"

int main()
{
    tCola colaNumeros;
    int vector[] ={1,2,3,4,5,6,7,8,9},i;
    crearCola(&colaNumeros);

    for(i = 0;i<sizeof(vector)/sizeof(int);i++)
    {
        if(!acolar(&colaNumeros,&(vector[i]),sizeof(int)))
        {
            printf("No hay espacio en memoria");
            exit(1);
        }
    }

    printf("Imprimiendo la cola: ");
    while(desacolar(&colaNumeros,&i,sizeof(int)))
    {
        printf("%d ",i);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
