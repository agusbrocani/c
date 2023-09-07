#include <stdio.h>
#define A_MAYUS(X) ( (X >= 'a' && X <= 'z') ? (X - ('a'-'A')) : (X) )

void lote1(int* edad, char* genero);
void lote2(int* edad, char* genero);
void lote3(int* edad, char* genero);
void lote4(int* edad, char* genero);
void lote5(int* edad, char* genero);
void lote6(int* edad, char* genero);
void lote7(int* edad, char* genero);
void lote8(int* edad, char* genero);
void lote9(int* edad, char* genero);
void lote10(int* edad, char* genero);
void lote11(int* edad, char* genero);
void clasificacion(int edad, char genero);

int main()
{
    int edad;
    int n;
    char genero;

    printf("Menu:\n");
    printf("0-Salir\n");
    printf("1-Ingreso por teclado\n");
    printf("2-Probar con lotes de prueba\n");

    do
    {
        printf("\nIngrese opcion:\t");
        scanf("%d",&n);
        fflush(stdin);
    }while( !(n >= 0 && n <= 2) );

    switch(n)
    {
        case 1:
                do
                {
                  printf("\nIngrese edad:\t");
                  scanf("%d",&edad);
                  fflush(stdin);
                }while( !(edad >= 18 && edad <= 120)   );

                do
                {
                    printf("Ingrese genero F o M:\t");
                    scanf("%c",&genero);
                    genero = A_MAYUS(genero);
                    fflush(stdin);
                }while(         !('F' == genero || 'M' == genero)           );

                clasificacion(edad,genero);
        break;
        case 2:
            lote1(&edad,&genero);
            clasificacion(edad,genero);
            lote2(&edad,&genero);
            clasificacion(edad,genero);
            lote3(&edad,&genero);
            clasificacion(edad,genero);
            lote4(&edad,&genero);
            clasificacion(edad,genero);
            lote5(&edad,&genero);
            clasificacion(edad,genero);
            lote6(&edad,&genero);
            clasificacion(edad,genero);
            lote7(&edad,&genero);
            clasificacion(edad,genero);
            lote8(&edad,&genero);
            clasificacion(edad,genero);
            lote9(&edad,&genero);
            clasificacion(edad,genero);
            lote10(&edad,&genero);
            clasificacion(edad,genero);
            lote11(&edad,&genero);
            clasificacion(edad,genero);
        break;
        case 0:
        break;
    }

    return 0;
}

void lote1(int* edad, char* genero)
{
    *edad =61;
    *genero = 'F';
}
void lote2(int* edad, char* genero)
{
    *edad =60;
    *genero = 'F';
}
void lote3(int* edad, char* genero)
{
    *edad =60;
    *genero = 'M';
}
void lote4(int* edad, char* genero)
{
    *edad =65;
    *genero = 'M';
}
void lote5(int* edad, char* genero)
{
    *edad =66;
    *genero = 'M';
}
void lote6(int* edad, char* genero)
{
    *edad =59;
    *genero = 'M';
}
void lote7(int* edad, char* genero)
{
    *edad =59;
    *genero = 'F';
}
void lote8(int* edad, char* genero)
{
    *edad =30;
    *genero = 'F';
}
void lote9(int* edad, char* genero)
{
    *edad =30;
    *genero = 'M';
}
void lote10(int* edad, char* genero)
{
    *edad =31;
    *genero = 'F';
}
void lote11(int* edad, char* genero)
{
    *edad =31;
    *genero = 'M';
}


void clasificacion(int edad, char genero)
{
    printf("\nLa persona de Edad: %d y Genero: %c\n",edad,genero);

    if(         'F' == genero && edad >= 60         )
    {
        printf("Es jubilada.\n");
    }else if(           'M' == genero && edad >= 65          )
        {
            printf("Es jubilado.\n");
        } else if(           edad >= 18 && edad <= 30           )
            {
                printf("Es estudiante.\n");
            }
            else
            {
                printf("Es trabajador.\n");
            }
}
