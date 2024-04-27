#include "parcial2.h"
///13:08
///13:23 PUNTO 3
///13:50 PUNTO 1
///14:15 REVISAR PUNTO 2

int main()
{
    int mat[MAX_FILAS][MAX_COLUMNAS] =
    {
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
    };

    int tam = sizeof(int);
    int cf = MAX_FILAS;
    int cc = MAX_COLUMNAS;


    mostrarMatriz( mat, tam, cf, cc, mostrarInt );

    printf("Cantidad de celulas : %d\n", _contarCelulasVivasEnVecindario( mat, cf, cc, 1, 1, comparaInt ) );

    return 0;
}
