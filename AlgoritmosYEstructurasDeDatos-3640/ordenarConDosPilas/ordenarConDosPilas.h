#ifndef ORDENARCONDOSPILAS_H_INCLUDED
#define ORDENARCONDOSPILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define minimo(X,Y) (((X)<(Y))? (X) : (Y))

#define TAM_CODIGO 8
#define TAM_DESCRIPCION 16
#define TAM_PROVEEDOR 16

#define CANT_PRODUCTOS 30   //Macro que modifico para que me genere este numero de registros

///MACROS DE FEDE PARA QUE FUNCIONE LO DE LOS LOTES
#define OK 0
#define FILE_ERR -3
#define FILE_OPEN_MODE_ERR -4

#define TAM_BUFFER 1000

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tPila;

typedef struct {
    int dia;
    int mes;
    int anio;
} tFecha;

typedef struct {
    char codigo[TAM_CODIGO];
    char descripcion[TAM_DESCRIPCION];
    char proveedor[TAM_PROVEEDOR];
    tFecha fechaCompra;
    tFecha fechaVencimiento;
    int cantidad;
    float precioCompra;
    float precioVenta;
} tProducto;

void crearPila(tPila* p);
int apilar(tPila* p, const void* d, unsigned tam);
int desapilar(tPila*p, void*d, unsigned tam);
int pilaVacia(const tPila* p);
void vaciarPila(tPila *p);
int verTope(const tPila *p, void* d, unsigned tam);
int pilaLlena(const tPila*p,unsigned tam);


int abrirArchivo( FILE** pf, const char* nombreArchivo, const char* modo );

void mostrarProducto(FILE* destino, const void* p);
void generarProductos(tProducto* vecProductos, int cantidad);
void trozarProducto(char* cadena, void* destino);
int cmpCodigo(const void* a, const void* b);

int generarArchivoProductos(const char* nombre, const char* tipo);  //Solo genera archivo, no crea lote
void ordenarConDosPilasAscendente( tPila* entrada, unsigned tam, int (*comparar)( const void* a, const void* b ) );

#endif // ORDENARCONDOSPILAS_H_INCLUDED
