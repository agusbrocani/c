#include "mapReduceFilterGen.h"

int main()
{

    int vec[] = {0,1,2,3,4,5,6,7,8,9} /* {}*/ /*{1}*/;
    int vecAOrdenar[] = {8,0,5,4,2,3,1,9,6,7}  /*{}*/ /*{1}*/;
    float vecF[] = {0,1,2,3,4,5,6,7,8,9};

    printf("vec:\n");
    recorrerVector(vec,sizeof(int),sizeof(vec)/sizeof(int),mostrarEntero);
    printf("vecAOrdenar:\n");
    recorrerVector(vecAOrdenar,sizeof(int),sizeof(vecAOrdenar)/sizeof(int),mostrarEntero);

    printf("\n");
    if(         NULL != buscarMenor(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEntero)            )
    {
        printf("Menor de vec:\t %d\n",  *(int*) ( buscarMenor(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEntero) )     );
    }
    else
    {
        printf("No hay elementos en vec\n");
    }

    if(         NULL != buscarMayor(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEntero)            )
    {
        printf("Mayor de vec:\t %d\n",  *(int*) ( buscarMayor(vec,sizeof(int),sizeof(vec)/sizeof(int),comparaEntero) )     );
    }
    else
    {
        printf("No hay elementos en vec\n");
    }

    printf("\n");
    ordenarSeleccionAscendente(vecAOrdenar,sizeof(int),sizeof(vecAOrdenar)/sizeof(int),comparaEntero);
    printf("vecAOrdenar luego de ordenarSeleccionAscendente:\n");
    recorrerVector(vecAOrdenar,sizeof(int),sizeof(vecAOrdenar)/sizeof(int),mostrarEntero);

    ordenarSeleccionDescendente(vecAOrdenar,sizeof(int),sizeof(vecAOrdenar)/sizeof(int),comparaEntero);
    printf("vecAOrdenar luego de ordenarSeleccionDescendente:\n");
    recorrerVector(vecAOrdenar,sizeof(int),sizeof(vecAOrdenar)/sizeof(int),mostrarEntero);

    fMap(vec,sizeof(int),sizeof(vec)/sizeof(int),acc,mostrarEntero);

    //reduce(vecF,sizeof(float),sizeof(vecF)/sizeof(float),promedio,mostrarFloat);


    return 0;
}
