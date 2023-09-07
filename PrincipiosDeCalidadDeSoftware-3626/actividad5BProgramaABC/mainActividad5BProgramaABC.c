#include <stdio.h>

void lote1(int* a,int* b, int* c);
void lote2(int* a,int* b, int* c);
void lote3(int* a,int* b, int* c);
void lote4(int* a,int* b, int* c);
void lote5(int* a,int* b, int* c);
void lote6(int* a,int* b, int* c);
void lote7(int* a,int* b, int* c);
void lote8(int* a,int* b, int* c);
void lote9(int* a,int* b, int* c);
void buscarMayor(int a,int b,int c);

int main()
{
    int a;
    int b;
    int c;
    int n;

    printf("0-Salir\n");
    printf("1-Ingresar a,b,c\n");
    printf("2-Probar con los lotes de prueba\n");

    do
    {
        printf("Ingrese opcion:\t");
        scanf("%d",&n);
        fflush(stdin);
    }while( n<0 || n>2 );

    switch( n )
    {
        case 1:
                printf("\nIngrese valor de a:\t");
                scanf("%d",&a);
                fflush(stdin);
                printf("\nIngrese valor de b:\t");
                scanf("%d",&b);
                fflush(stdin);
                printf("\nIngrese valor de c:\t");
                scanf("%d",&c);
                fflush(stdin);
                buscarMayor(a,b,c);
        break;
        case 2:
                lote1(&a,&b,&c);
                buscarMayor(a,b,c);
                lote2(&a,&b,&c);
                buscarMayor(a,b,c);
                lote3(&a,&b,&c);
                buscarMayor(a,b,c);
                lote4(&a,&b,&c);
                buscarMayor(a,b,c);
                lote5(&a,&b,&c);
                buscarMayor(a,b,c);
                lote6(&a,&b,&c);
                buscarMayor(a,b,c);
                lote7(&a,&b,&c);
                buscarMayor(a,b,c);
                lote8(&a,&b,&c);
                buscarMayor(a,b,c);
                lote9(&a,&b,&c);
                buscarMayor(a,b,c);
        break;
        default:
        break;
    }



    return 0;
}

void lote1(int* a,int* b, int* c)
{
    *a = 1;
    *b = 2;
    *c = 3;
}
void lote2(int* a,int* b, int* c)
{
    *a = 2;
    *b = 1;
    *c = 3;
}
void lote3(int* a,int* b, int* c)
{
    *a = 3;
    *b = 2;
    *c = 1;
}
void lote4(int* a,int* b, int* c)
{
    *a = 3;
    *b = 3;
    *c = 3;
}
void lote5(int* a,int* b, int* c)
{
    *a = 1;
    *b = 3;
    *c = 3;
}
void lote6(int* a,int* b, int* c)
{
    *a = 3;
    *b = 1;
    *c = 3;
}
void lote7(int* a,int* b, int* c)
{
    *a = 3;
    *b = 3;
    *c = 1;
}
void lote8(int* a,int* b, int* c)
{
    *a = 0;
    *b = 0;
    *c = 0;
}
void lote9(int* a,int* b, int* c)
{
    *a = -1;
    *b = -2;
    *c = -3;
}

void buscarMayor(int a,int b,int c)
{
    printf("\nCon a = %d b = %d c = %d\n",a,b,c);

    if( a > b && a > c )
    {
        printf("El mayor es a: %d\n",a);
    }
    else if( b > c)
        {
            printf("El mayor es b: %d\n",b);
        }
        else
        {
            printf("El mayor es c: %d\n",c);
        }
}

