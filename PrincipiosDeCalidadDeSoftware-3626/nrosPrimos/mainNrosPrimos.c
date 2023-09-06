#include <stdio.h>
#include <stdlib.h>

int esPrimo(int x);

int main()
{
    int ingreso;

    printf("Ingrese un numero para verificar si es primo\n");
    scanf("%d",&ingreso);
    if(         !esPrimo(ingreso)          )
    {
        printf("NO es primo.\n");
    }
    else
    {
        printf("Es primo.\n");
    }

    return 0;
}

int esPrimo(int x)
{
    int i;
    int contador = 1;

    if( x <= 1 )
    {
        return 0;
    }

    for( i = x-1; i > 1;i-- )
    {
        if(         0==x%i          )
        {
            contador++;
        }
    }

    if( 1 == contador )
    {
        return contador;    //es primo
    }
    else
    {
        return 0;           //no es primo
    }
}
