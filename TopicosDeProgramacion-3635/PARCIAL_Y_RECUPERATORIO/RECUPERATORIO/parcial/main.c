#include "parcial.h"
#define CF 3
///40931870 AGUSTIN BROCANI

int main()
{
    int mat1[CF][MAX_COLUMNA] = {{ 1,2,3},{4,5,6},{7,8,9}};
    int mat2[CF][MAX_COLUMNA] = {{ 1,2},{4,5},{7,8}};
    int mat3[][MAX_COLUMNA] = {{1}};
    int vecImpar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    int vecPar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int tam = sizeof(int);
    int ceImpar = sizeof(vecImpar)/sizeof(int);
    int cePar = sizeof(vecPar)/sizeof(int);
    int claveCasoFavorable = 0;
    int claveCasoDesfavorable = -1;
    void* retorno;

    printf("EJERCICIO 1:\n");

    qsort( vecImpar, ceImpar, tam, comparaEnteros );
    qsort( vecPar, cePar, tam, comparaEnteros );  ///por si me cambian los lotes y no vienen ordenados

///CASO IMPAR
    printf("\nColeccion impar:\n");
    mostrarVector( vecImpar, tam, ceImpar, mostrarEntero );
    printf("\nCaso favorable en vector de ce impar [clave = %d]:\n", claveCasoFavorable );
    if(         NULL == ( retorno = miBsearch( &claveCasoFavorable, vecImpar, ceImpar, tam, comparaEnteros ) )            )
    {
        printf("No se encontro la clave en la coleccion impar\n");
    }
    else
    {
        printf("Se encontro la clave en la coleccion impar: %d\n", *(int*)retorno );
    }

    printf("\nCaso desfavorable en vector de ce impar [clave = %d]:\n", claveCasoDesfavorable );
    if(         NULL == ( retorno = miBsearch( &claveCasoDesfavorable, vecImpar, ceImpar, tam, comparaEnteros ) )            )
    {
        printf("No se encontro la clave en la coleccion impar\n");
    }
    else
    {
        printf("Se encontro la clave en la coleccion impar: %d\n", *(int*)retorno );
    }

///CASO PAR
    printf("\nColeccion par:\n");
    mostrarVector( vecPar, tam, cePar, mostrarEntero );
    printf("\nCaso favorable en vector de ce par [clave = %d]:\n", claveCasoFavorable );
    if(         NULL == ( retorno = miBsearch( &claveCasoFavorable, vecPar, cePar, tam, comparaEnteros ) )            )
    {
        printf("No se encontro la clave en la coleccion par\n");
    }
    else
    {
        printf("Se encontro la clave en la coleccion par: %d\n", *(int*)retorno );
    }

    printf("\nCaso desfavorable en vector de ce par [clave = %d]:\n", claveCasoDesfavorable );
    if(         NULL == ( retorno = miBsearch( &claveCasoDesfavorable, vecPar, cePar, tam, comparaEnteros ) )            )
    {
        printf("No se encontro la clave en la coleccion par\n");
    }
    else
    {
        printf("Se encontro la clave en la coleccion par: %d\n", *(int*)retorno );
    }


    printf("\nEJERCICIO 2:\n");

    printf("Matriz original 1:\n");
    mostrarMatriz( mat1, CF, 3 );
    trasponerMatriz( mat1, CF, 3);

    printf("Matriz original 2:\n");
    mostrarMatriz( mat2, CF, 2 );
    trasponerMatriz( mat2, CF, 2);

    printf("Matriz original 3:\n");
    mostrarMatriz( mat3, 1, 1 );
    trasponerMatriz( mat3, 1, 1);

    return 0;
}
