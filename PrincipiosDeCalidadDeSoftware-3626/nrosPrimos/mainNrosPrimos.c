#include <stdio.h>

int esPrimo(int x);
void clasifica(int ingreso);

int main()
{
    int ingreso;
    int i;
    unsigned n;
    int lote[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,-1,0,1,4,6,9};

    printf("Menu:\n");
    printf("0-Salir\n");
    printf("1-Ingreso por teclado\n");
    printf("2-Probar con lote de pruebas\n");

    do
    {
        printf("Ingrese opcion:\t");
        scanf("%u",&n);
        fflush(stdin);
    }while( !( n >= 0 && n <= 2) );

    switch( n )
    {
        case 1:
                printf("\nIngrese un numero para verificar si es primo:\t");
                scanf("%d",&ingreso);
                fflush(stdin);
                clasifica(ingreso);
        break;
        case 2:
                for( i = 0; i < sizeof(lote)/sizeof(int); i++ )
                {
                    clasifica(lote[i]);
                }
        break;
        case 0:
        break;
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

void clasifica(int ingreso)
{
    printf("\nEl numero %d ",ingreso);
    if(         !esPrimo(ingreso)          )
    {
        printf("NO es primo.\n");
    }
    else
    {
        printf("es primo.\n");
    }
}
