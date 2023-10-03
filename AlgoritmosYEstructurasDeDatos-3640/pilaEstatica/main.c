#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char AyN[50];
    int dni;
    int prom;
}tAlumno;

int main()
{
    tPila pila;
    tAlumno al;

    crearPila(&pila);
    if(!apilar(&pila,al.AyN,strlen(al.AyN)))
    {
        printf("\nNo se pudo apilar!");
        return 1;
    }
    return 0;
}
