#include "examen.h"

int comparaCadenas(const void* cadena1, const void* cadena2)
{
    unsigned tamC1 = strlen((char*)cadena1);
    unsigned tamC2 = strlen((char*)cadena2);

    return tamC1 - tamC2;
}

void top5Frases(char mat[][MAX_C],unsigned* cantFrases, int (*comparar)(const void* a,const void* b))
{
    char frase[MAX_C];

    while(          NULL != obtenerFrase(frase)        )
    {
        miInsertarOrdenado(mat,cantFrases,frase,comparaCadenas);
    }
}

void miInsertarOrdenado(char mat[][MAX_C],unsigned* cantFrases,const char* frase, int (*comparar)(const void* a, const void* b))
{
    int f = 0;
    int i;

    while(          f < MENOR(MAX_F,*cantFrases)  && comparar(&mat[f][0],frase) >= 0       )
    {
        f++;
    }

    if(         !*cantFrases || comparar(&mat[f][0],frase) < 0         )
    {
        for( i = MENOR(MAX_F,*cantFrases)-2; i >= f; i-- )
        {
            memcpy(&mat[i+1][0],&mat[i][0],strlen(&mat[i][0])+1);
        }
        memcpy(&mat[f][0],frase,strlen(frase)+1);
        *cantFrases < MAX_F ? (*cantFrases)++ : ((*cantFrases) = MAX_F);
    }
}

void mostrarFrases(char mat[][MAX_C],unsigned cantFrases)
{
    int frase;

    printf("TOP 5:\n");
    for( frase = 0; frase < cantFrases; frase++ )
    {
        printf("Strlen:%I64u - Frase: %s\n",strlen(&mat[frase][0]),&mat[frase][0]);
    }
}
