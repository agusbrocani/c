#include "unidad3PasajeParametros.h"

int opcionValida(int opcion)
{
    return opcion >= LI && opcion <= LS ;
}
void ingresaOpcion(int* opcion)
{
    printf("\n");

    do
    {
        printf("Ingrese opcion:\t");
        scanf("%d",opcion);
        fflush(stdin);
    }while(         !opcionValida(   (*opcion) )           );

    printf("\n");
}
int menu(const void* vec)
{
    int opcion;

    printf("Menu:\n");
    printf("1-Buscar el minimo elemento\n");
    printf("2-Calcular el promedio de los valores de las posiciones pares\n");
    printf("3-Mostrarlo en orden inverso\n");
    printf("4-Salir\n");

    ingresaOpcion(&opcion);

    //LI = 1 , LS = 4
    switch(opcion)
    {
        case LI:
            opcionUno(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEnteros);
        break;
        case 2:
            opcionDos(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEnteros);
        break;
        case 3:
            opcionTres(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEnteros);
        break;
        case LS:
            printf("Saliendo del Menu...\n");
            system("pause");
            system("cls");
        return 0;
    }

    return 1;
}

void opcionUno(const void* vec,unsigned tam,unsigned ce,int (*comparar)(const void* a, const void* b))
{
    int menor;

    if(         !buscarMenor(vec,&menor,sizeof(int),sizeof(vec)/sizeof(int),comparaEnteros)            )
    {
        printf("No hay menor\n");
    }
    else
    {
        printf("El menor elemento es: %d\n",*((int*)buscarMenor(vec,&menor,sizeof(int),sizeof(vec)/sizeof(int),comparaEnteros))    );
    }

    printf("\n");
}
void opcionDos(const void* vec,unsigned tam,unsigned ce,int (*comparar)(const void* a, const void* b))
{
    float promedio = 0;
    int cant = 0;
    int i;

    for(i = 0; i < ce; i+=2 )
    {
        promedio += *(int*)(vec+i*sizeof(int));
        cant++;
    }

    /*
    for( i = 0; i < ce; i ++ )
    {
        if(         0 == i % 2            )
        {
            promedio += *(int*)vec;
            cant++;
            vec += tam;
        }
    }
    */
    promedio = promedio/cant;

    printf("Promedio de las posiciones pares = %.2f\n",promedio);
    printf("\n");
}
void opcionTres(const void* vec,unsigned tam,unsigned ce,int (*comparar)(const void* a, const void* b))
{

}

int comparaEnteros(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

void* buscarMenor(const void* vec,void* menor,unsigned tam, unsigned ce, int (*comparar)(const void* a, const void* b))
{
    int i;

    if(         ce < 1         )
    {
        return NULL;
    }

    memcpy(menor,vec,tam);

    for( i = 1; i < ce; i++)
    {
        vec += tam;
        if(         comparar(menor,vec) > 0          )
        {
            memcpy(menor,vec,tam);
        }
    }

    return menor;
}
