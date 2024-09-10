#include "../../include/pila/ordenarCon2Pilas.h"

void ordenarArchivoConDosPilasGen(
                                    FILE* origen, FILE* destino, unsigned tam,
                                    int (*comparar)(const void* a, const void* b),
                                    int (*leerRegistroArchivoCargandoDatoRetornandoCondicionSegunCaso)(FILE* pf, void* dato, unsigned tam),
                                    void (*grabarSegunCaso)(FILE* pf, const void* dato, unsigned tam)
                                    )
{
    tPila pilaMayores;
    tPila pilaMenores;
    void* buffer;
    void* iniBuffer;
    void* dato;
    void* iniDato;

    buffer = malloc(tam);
    if(NULL == buffer)
    {
        perror("No pude reservar memoria para buffer");
        return;
    }
    iniBuffer = buffer;

    dato = malloc(tam);
    if(NULL == dato)
    {
        perror("No pude reservar memoria para dato");
        free(buffer);
        return;
    }
    iniDato = dato;

    crearPila(&pilaMayores);
    crearPila(&pilaMenores);

    while(FIN_DE_ARCHIVO != leerRegistroArchivoCargandoDatoRetornandoCondicionSegunCaso(origen, dato, tam))
    {
        while(verTope(&pilaMayores, buffer, tam) && (comparar(dato, buffer) > 0))
        {
            desapilar(&pilaMayores, buffer, tam);
            apilar(&pilaMenores, buffer, tam);
        }

        while(verTope(&pilaMenores, buffer, tam) && (comparar(dato, buffer) < 0))
        {
            desapilar(&pilaMenores, buffer, tam);
            apilar(&pilaMayores, buffer, tam);
        }
        apilar(&pilaMayores, dato, tam);
    }

    while(desapilar(&pilaMenores, dato, tam))
    {
        apilar(&pilaMayores, dato, tam);
    }

    while(desapilar(&pilaMayores, dato, tam))
    {
        grabarSegunCaso(destino, dato, tam);
    }

    rewind(origen);//dejo punteros al inicio como buena practica
    rewind(destino);
    free(iniBuffer);
    free(iniDato);
    vaciarPila(&pilaMayores);
    vaciarPila(&pilaMenores);
}


