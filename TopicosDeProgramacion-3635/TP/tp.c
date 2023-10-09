#include "tp.h"

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

void swapRegister(void* registro, size_t tam)
{
    void* ini = registro;
    void* fin = registro + tam - 1;
    char aux;

    while(          ini < fin           )   ///PUEDO HACER ESTO YA QUE ES LITTLE ENDIAN
    {
        aux = *(char*)ini;
        *(char*)ini = *(char*)fin;
        *(char*)fin = aux;

        ini++;
        fin--;
    }
}

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


