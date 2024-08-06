#include "funciones.h"

int main()
{
    while(          SIGUE_EN_EJECUCION          )
    {
        opciones();
        switch(         ingresaOpcion()         )
        {
            case PUNTO_1:
                ejercicio1();
            break;
            case PUNTO_2:
                ejercicio2();
            break;
            case PUNTO_3:
                ejercicio3();
            break;
            case PUNTO_4:
                ejercicio4();
            break;
            case PUNTO_5:
                ejercicio5();
            break;
            case PUNTO_6:
                ejercicio6();
            break;
            case PUNTO_7:
                ejercicio7();
            break;
            case PUNTO_8:
                ejercicio8();
            break;
            case PUNTO_9:
                ejercicio9();
            break;
            case PUNTO_10:
                ejercicio10();
            break;
            case PUNTO_11:
                ejercicio11();
            break;
            case PUNTO_12:
                ejercicio12();
            break;
            case PUNTO_13:
                ejercicio13();
            break;
            case PUNTO_14:
                ejercicio14();
            break;
            case SALIR:
                printf( "\n***********SALIENDO***********\n" );
                system( "pause" );
                return 0;
        }
    }
}
