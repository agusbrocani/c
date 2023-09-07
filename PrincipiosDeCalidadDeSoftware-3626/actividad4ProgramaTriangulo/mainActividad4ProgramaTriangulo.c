#include <stdio.h>

void lote1(unsigned* a, unsigned* b, unsigned* c);
void lote2(unsigned* a, unsigned* b, unsigned* c);
void lote3(unsigned* a, unsigned* b, unsigned* c);
void lote4(unsigned* a, unsigned* b, unsigned* c);

void clasificacion(unsigned a,unsigned b, unsigned c);
void clasificacionMejorado(unsigned a,unsigned b, unsigned c);

int main()
{
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned n;

    printf("Menu:\n");
    printf("0-Salir\n");
    printf("1-Ingreso por teclado\n");
    printf("2-Probar con lotes de prueba\n");
    printf("3-Probar mejora con lotes de prueba\n");

    do
    {
        printf("Ingrese opcion:\t");
        scanf("%u",&n);
        fflush(stdin);
    }while( !(n >= 0 && n <= 3) );

    switch(n)
    {
        case 1:
                printf("\nIngrese valor de a:\t");
                scanf("%u",&a);
                fflush(stdin);
                printf("\nIngrese valor de b:\t");
                scanf("%u",&b);
                fflush(stdin);
                printf("\nIngrese valor de c:\t");
                scanf("%u",&c);
                fflush(stdin);

                clasificacion(a,b,c);
        break;
        case 2:
                lote1(&a,&b,&c);
                clasificacion(a,b,c);
                lote2(&a,&b,&c);
                clasificacion(a,b,c);
                lote3(&a,&b,&c);
                clasificacion(a,b,c);
                lote4(&a,&b,&c);    //caso falla
                clasificacion(a,b,c);
        break;
        case 3:
                lote1(&a,&b,&c);
                clasificacionMejorado(a,b,c);
                lote2(&a,&b,&c);
                clasificacionMejorado(a,b,c);
                lote3(&a,&b,&c);
                clasificacionMejorado(a,b,c);
                lote4(&a,&b,&c);
                clasificacionMejorado(a,b,c);
        break;
        case 0:
        break;
    }

    /*Errores de dise�o:
        ->NO validar datos al inicio(NO NEGATIVOS, NO CEROS)
        ->A == B == C no funciona, deberia ser A == B && A == C && B == C
        ->No especificar el tipo de dato de las variables A,B,C porque si utilizo int y no valido, puedo ingresar valores negativos, lo cual no tiene sentido
    */

    return 0;
}
void lote1(unsigned* a, unsigned* b, unsigned* c)
{
    *a = 5;
    *b = 5;
    *c = 5;
}
void lote2(unsigned* a, unsigned* b, unsigned* c)
{
    *a = 5;
    *b = 5;
    *c = 4;
}
void lote3(unsigned* a, unsigned* b, unsigned* c)
{
    *a =5;
    *b =4;
    *c =3;
}

void lote4(unsigned* a, unsigned* b, unsigned* c)
{
    *a = 0;
    *b = 0;
    *c = 0;
}


void clasificacion(unsigned a,unsigned b, unsigned c)
{
    printf("\nClasificacion[a = %d b = %d c = %d]:\n",a,b,c);
    if(         a == b && a == c && b == c          )
    {
        printf("El triangulo es EQUILATERO\n");
    }else if(         a == b || a == c || b == c          )
        {
            printf("El triangulo es ISOSCELES\n");
        }
        else
        {
            printf("El triangulo es ESCALENO\n");
        }
}

void clasificacionMejorado(unsigned a,unsigned b, unsigned c)   //Mejoras propuestas: uso de una logica mas clara en el codigo, pregunto por los casos limites(son todos iguales, ninguno es igual) y validar ingreso en el main [a>0, b>0 y c>0]
{
    if(         a <= 0 || b <= 0 || c <= 0          )
    {
        printf("\nEso NO es un triangulo\n");
        return;
    }

    printf("\nClasificacion[a = %d b = %d c = %d]:\n",a,b,c);

    if(         a != b && a != c && b != c          )   //si son todos distintos -> ESCALENO
    {
        printf("El triangulo es ESCALENO\n");
        return ;
    }

    if(         a == b && a == c && b == c          )   //si son todos iguales -> EQUILATERO
    {
        printf("El triangulo es EQUILATERO\n");
        return;
    }

    printf("El triangulo es ISOSCELES\n");    //Si no eran todos iguales o eran todos distintos -> ISOSCELES
}
