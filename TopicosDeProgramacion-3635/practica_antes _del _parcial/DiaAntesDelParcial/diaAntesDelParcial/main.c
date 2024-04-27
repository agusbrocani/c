#include "diaAntesDelParcial.h"
#define TAM 10

int main()
{
    int vec[TAM] = {0,1,2,3,4,6,7,8,9};
//    int vec[TAM] = {9,8,7,6,4,3,2,1,0};
//    int vec[TAM] = {0,1,2,3,4,5,6,7,8,9};
//    int vec[TAM];
//    int vec[TAM] = {1};
    int dato = 5;
    int ce = 9;
    int maxCe = sizeof(vec)/sizeof(int);
    int tam = sizeof(int);

    mostrarVector( vec, tam, ce, mostrarInt );
    insertarOrdenado( vec, &dato,tam, &ce, maxCe, comparaIntAB );
    mostrarVector( vec, tam, ce, mostrarInt );


    return 0;
}
