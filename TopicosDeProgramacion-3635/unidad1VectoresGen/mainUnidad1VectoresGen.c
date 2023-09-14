#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unidad1VectoresGen.h"


int main()
{
    int vecEntero[CEInt] = {0,1,2,3,4,5,6,7,8,9};
    char vecChar[CEChar] = {"Hola mundo"};
    int dato;
    int posicion;
    char letra;
    char opcion;
    unsigned cantElementos;

    printf("MENU:\n");
    printf("i - Insertar entero\n");
    printf("c - Insertar char\n");

    do
    {
        printf("\nIngrese opcion:\t");
        scanf("%c",&opcion);
        opcion = A_MAYUS(opcion);
        fflush(stdin);

    }while(         !validaOpcion(opcion)            );


    switch( opcion )
    {
        case 'I':
                    dato = 0;
                    posicion = -1;
                    cantElementos = sizeof(vecEntero)/sizeof(int);
                    mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    insertarEnPosicion(vecEntero, &dato, sizeof(int), cantElementos, posicion);
                    mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    insertarOrdenado(vecEntero,&dato,sizeof(int),cantElementos,posicion);
                    mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    cantElementos = sizeof(vecEntero)/sizeof(int);
                    printf("CANTIDAD DE ELEMENTOS:\t%u\n",cantElementos);
                    if( !eliminarPosicion(vecEntero,&dato,sizeof(int),&cantElementos,posicion)  )
                    {
                        printf("\nNo se pudo eliminar nada, posicion invalida.\n");
                    }
                    else
                    {
                        printf("\nCANTIDAD DE ELEMENTOS:\t%u\n",cantElementos);
                        printf("DATO ELIMINADO: %d", dato);
                        mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    }

                    mostrarVector(vecEntero,sizeof(int),sizeof(vecEntero)/sizeof(int), mostrarDatoEntero);
                    cantElementos = sizeof(vecEntero)/sizeof(int);
                    printf("\nCANTIDAD DE ELEMENTOS:\t%u\n",cantElementos);
                    if( !eliminarPrimerAparicion(vecEntero,&dato,sizeof(int),&cantElementos,comparaEnteros) )
                    {
                        printf("\nNo habia apariciones de ese dato.\n");
                    }
                    else
                    {
                        printf("\nCANTIDAD DE ELEMENTOS:\t%u\n",cantElementos);
                        printf("DATO ELIMINADO: %d\n",dato);
                        mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    }

                    mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    cantElementos = sizeof(vecEntero)/sizeof(int);
                    printf("\nCANTIDAD DE ELEMENTOS:\t%u\n",cantElementos);
                    if( !eliminarApariciones(vecEntero,&dato,sizeof(int),&cantElementos,comparaEnteros) )
                    {
                        printf("\nNo habia apariciones de ese dato.\n");
                    }
                    else
                    {
                        printf("\nCANTIDAD DE ELEMENTOS:\t%u\n",cantElementos);
                        printf("DATO ELIMINADO: %d\n",dato);
                        mostrarVector(vecEntero,sizeof(int),cantElementos, mostrarDatoEntero);
                    }

        break;

        case 'C':
                    letra = 'X';
                    posicion = 1;

                    mostrarVector(vecChar,sizeof(char),miStrlen(vecChar),mostrarDatoChar);
                    insertarEnPosicion(vecChar, &letra, sizeof(char), miStrlen(vecChar), posicion);
                    mostrarVector(vecChar,sizeof(char),miStrlen(vecChar),mostrarDatoChar);
        break;

    };

    return 0;
}
