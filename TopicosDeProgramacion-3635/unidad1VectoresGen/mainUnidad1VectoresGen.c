#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unidad1VectoresGen.h"


int main()
{
    int vecEntero[CEInt] = {0,1,2,3,4,5,6,7,8,9};
    char vecChar[CEChar] = {"Hola mundo"};
    int dato;
    int posicionInsercion;
    char letra;
    char opcion;

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
                    dato = -1;
                    posicionInsercion = 9;

                    mostrarVector(&vecEntero,sizeof(int),sizeof(vecEntero)/sizeof(int), mostrarDatoEntero);
                    insertarEnPosicion(&vecEntero, &dato, sizeof(int), sizeof(vecEntero)/sizeof(int), posicionInsercion);
                    mostrarVector(&vecEntero,sizeof(int),sizeof(vecEntero)/sizeof(int), mostrarDatoEntero);
        break;

        case 'C':
                    letra = 'X';
                    posicionInsercion = 1;

                    mostrarVector(&vecChar,sizeof(char),miStrlen(vecChar),mostrarDatoChar);
                    insertarEnPosicion(&vecChar, &letra, sizeof(char), miStrlen(vecChar), posicionInsercion);
                    mostrarVector(&vecChar,sizeof(char),miStrlen(vecChar),mostrarDatoChar);
        break;

    };

    return 0;
}
