#include "tp.h"

int checkEndianness()
{
    unsigned int value = 0x12345678; // Valor conocido
    unsigned char *ptr = (unsigned char *)&value;   ///char* para leer 1 byte

    // Si el primer byte es igual al byte más significativo, es little-endian.
    if (*ptr == 0x78)
    {
        return 1; // Little-endian
    }
    // Si el primer byte es igual al byte menos significativo, es big-endian.
    else if (*ptr == 0x12)
        {
            return 0; // Big-endian
        }
        // Si no es ninguno de los dos, el hardware utiliza un formato inusual.
        else
        {
            return -1; // Formato desconocido
        }
}

int abrirArchivo(FILE** pf,const char* nombreArchivo,const char* modo)
{
    *pf = fopen(nombreArchivo,modo);

    if(!*pf)
    {
        printf("No pude abrir/crear el archivo\n");
        return 0;
    }

    return 1;
}

void mostrarArchivoBinario(FILE* pf,void* dato,unsigned tam, void (*mostrar)(const void* dato))
{
    fread(dato,tam,1,pf);
    while(!feof(pf))
    {
        mostrar(dato);
        printf("\n");
        fread(dato,tam,1,pf);
    }
    rewind(pf);
}
