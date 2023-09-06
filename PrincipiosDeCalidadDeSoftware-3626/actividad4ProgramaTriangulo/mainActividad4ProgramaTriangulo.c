#include <stdio.h>
#include <stdlib.h>

void clasificacion(unsigned a,unsigned b, unsigned c);
void clasificacionMejorado(unsigned a,unsigned b, unsigned c);

int main()
{
    unsigned a;
    unsigned b;
    unsigned c;

    printf("\nIngrese valor de a:\t");
    scanf("%u",&a);
    printf("\nIngrese valor de b:\t");
    scanf("%u",&b);
    printf("\nIngrese valor de c:\t");
    scanf("%u",&c);

    clasificacion(a,b,c);

    /*
    //2-LOTES DE PRUEBA:
    printf("\nLote 1[a=5,b=5,c=5]\t");
    clasificacion(5,5,5);
    printf("\nLote 2[a=5,b=4,c=4]\t");
    clasificacion(5,4,4);
    printf("\nLote 3[a=5,b=4,c=3]\t");
    clasificacion(5,4,3);
    */

    /*Errores de diseño:
        ->NO validar datos al inicio(NO NEGATIVOS, NO CEROS)
        ->A == B == C no funciona, deberia ser A == B && A == C && B == C
        ->No especificar el tipo de dato de las variables A,B,C porque si utilizo int y no valido, puedo ingresar valores negativos, lo cual no tiene sentido
    */

    return 0;
}

void clasificacion(unsigned a,unsigned b, unsigned c)
{
    printf("\n\nClasificacion:\n");
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
    printf("\n\nClasificacion:\n");

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

    printf("El triangulo es ISOSCELES");    //Si no eran todos iguales o eran todos distintos -> ISOSCELES
}
