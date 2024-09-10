#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./loteEmpleados.h"

#define FIN_DE_ARCHIVO 0
#define HAY_REGISTROS_POR_LEER 1

#define TAM_BUFFER_LECTURA 1000


int leerRegistroArchivoTxtLFCargandoDatoRetornandoCondicion(FILE* pf, void* dato, unsigned tam);
void trozar(void* dato, char* cadena);
int leerRegistroArchivoTxtLVCargandoDatoRetornandoCondicion(FILE* pf, void* dato, unsigned tam);
int leerRegistroArchivoBinarioCargandoDatoRetornandoCondicion(FILE* pf, void* dato, unsigned tam);

void grabarDatoArchivoTxtLF(FILE* pf, const void* dato, unsigned tam);
void grabarDatoArchivoTxtLV(FILE* pf, const void* dato, unsigned tam);
void grabarDatoArchivoBinario(FILE* pf, const void* dato, unsigned tam);



#endif // ARCHIVOEMPLEADOS_H_INCLUDED
