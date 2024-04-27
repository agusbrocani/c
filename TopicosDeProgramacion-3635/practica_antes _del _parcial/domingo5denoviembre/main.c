#include "domingo5denoviembre.h"

int main()
{
    int mat[MAX_FILAS][MAX_COLUMNAS] = {{0}};
    int tam = sizeof(int);

    cargarMatriz( mat, tam, MAX_FILAS, MAX_COLUMNAS );

    mostrarMatriz( mat, tam, MAX_FILAS, MAX_COLUMNAS, mostrarInt );

    return 0;
}
