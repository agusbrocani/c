#include "./unidad1.h"

#define PUNTO_1 1
#define PUNTO_2 2
#define PUNTO_3 3
#define PUNTO_4 4
#define PUNTO_5 5

void switchMenuUnidad1(int opcion, void* parametroAdicional)
{
    switch(opcion)
    {
        case PUNTO_1:
            printf("\n*****************************PUNTO1*****************************\n");
            ejercicio1();
        break;
        case PUNTO_2:
            printf("\n*****************************PUNTO2*****************************\n");
            ejercicio2();
        break;
        case PUNTO_3:
            printf("\n*****************************PUNTO3*****************************\n");
            ejercicio3();
        break;
        case PUNTO_4:
            printf("\n*****************************PUNTO4*****************************\n");
            ejercicio4();
        break;
        case PUNTO_5:
            printf("\n*****************************PUNTO5*****************************\n");
            ejercicio5();
        break;
    }
}

int main()
{
    char textoMenu[][MAX_TAM_TEXTO] =
    {
      "Menu:",
      "[0]-SALIDA",
      "[1]-PUNTO 1: sugerencia TDAs.",
      "[2]-PUNTO 2: TDAs con estructura recursiva.",
      "[3]-PUNTO 3: grafico de Nodo.",
      "[4]-PUNTO 4: listaSimplementeEnlazada.",
      "[5]-PUNTO 5: arbol binario de busqueda.",
    };
    unsigned cantRegistros = sizeof(textoMenu) / MAX_TAM_TEXTO;

    menu(textoMenu, cantRegistros, switchMenuUnidad1, NULL, DESACTIVAR_AYUDA_AL_USUARIO);//ARGUMENTO AL MAIN, PARA QUE CUANDO CORRA DESDE EL .EXE, por consola pueda enviarle el parametro

    return 0;
}
