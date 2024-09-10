#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Dinamica/pila.h"

#define FIN_DE_ARCHIVO 0
#define HAY_REGISTROS_POR_LEER 1

void ordenarEnDosPilas(tPila* pilaMayores, tPila* pilaMenores, void* buffer, const void* dato, unsigned tam, int (*comparar)(const void* a, const void* b));
void ordenarArchivoConDosPilasGen(
                                    FILE* origen, FILE* destino, unsigned tam,
                                    int (*comparar)(const void* a, const void* b),
                                    int (*leerRegistroArchivoCargandoDatoRetornandoCondicionSegunCaso)(FILE* pf, void* dato, unsigned tam),
                                    void (*grabarSegunCaso)(FILE* pf, const void* dato, unsigned tam)
                                    );





#endif // FUNCIONES_H_INCLUDED

