#include "unidad1VectoresGen.h"

/*
tam = tamaño del tipo de dato del dato
ce = cantidad de elementos del vector
pos = posicion de insercion del elemento en el vector
*/

char validaOpcion(char opcion)
{

    if(         !( 'I' == opcion || 'C' == opcion )        )
    {
       return 0;
    }

    return opcion;
}

size_t miStrlen(const char* cadena)
{
    size_t cantidadCaracteres = 0;

    while(          '\0' != *cadena         )
    {
        cantidadCaracteres++;
        cadena++;
    }

    return cantidadCaracteres;
}

void mostrarDatoEntero(void* vec)
{
    printf( "%d\t",*(int*)vec );
}

void mostrarDatoChar(void* vec)
{
    printf( "%c\t",*(char*)vec );
}

void mostrarVector(void* vec,unsigned tam,unsigned ce,void (*mostrar) (void* vec) )
{
    int i;

    printf("\n");
    for( i = 0; i < ce; i++)
    {
        mostrar(vec+(i*tam));
    }
    printf("\n");
}

int comparaEnteros(const void* a, const void* b)
{
    return  *((int*)a) - *((int*)b) ;
}

void insertarEnPosicion(void* vec,const void* dato,unsigned tam,unsigned ce, unsigned pos)
{
    if(         0 < pos && pos > (ce-1)          )
    {
        printf("\nNo se realizo ninguna insercion, posicion invalida.\n");
        return;
    }

    memcpy( ( vec + pos*tam ) , dato, tam );
}

void insertarOrdenado(void* vec,const void* dato, unsigned tam, unsigned ce, unsigned pos)
{
    void* posterior = vec + (ce-1)*tam;
    void* anterior = vec + (ce-2)*tam;
    char aux;

    if(         0 < pos && pos > (ce-1)          )
    {
        printf("\nNo se realizo ninguna insercion, posicion invalida.\n");
        return;
    }

    while(          (vec+pos*tam) > posterior           )
    {
        aux = *((char*)posterior);
        *((char*)posterior) = *((char*)anterior);
        *((char*)posterior) = aux;
        anterior--;
        posterior--;
    }

    memcpy( ( vec + pos*tam ) , dato, tam );    //ultimo paso
}

int eliminarPosicion(void* vec,void* dato, unsigned tam, unsigned* ce, unsigned pos)
{

    if(         0 < pos && pos > ((*ce)-1)          )
    {
        return 0;
    }

    memcpy(dato, (vec + pos*tam) , tam);  //salvo el dato eliminado
    (*ce) -= 1;

    memmove((vec + pos*tam),(vec + (pos+1)*tam),((*ce) - pos)*tam );

    return 1;
}

int eliminarPrimerAparicion(void* vec,const void* dato, unsigned tam, unsigned* ce,int (*comparar) (const void* a, const void* b) )
{
    void* fin = (vec + ((*ce)-1)*tam);
    void* comparado = vec;

    while(         (*ce) && comparado <= fin && comparar(comparado,dato)          )
    {
        comparado+=tam;
    }

    if( (*ce) && comparado >  fin )
    {
        return 0;
    }
    (*ce) -= 1;

    memmove(comparado,comparado+tam, ABS(fin-comparado) );

    return 1;
}

int eliminarApariciones(void* vec,const void* dato, unsigned tam, unsigned* ce,int (*comparar) (const void* a, const void* b) )
{
    void* fin = (vec + ((*ce)-1)*tam);
    void* comparado = vec;
    int noBorrado = 1;

    while(          (*ce) && comparado <= fin            )
    {
        if(         !comparar(comparado,dato)            )
        {
            (*ce) -= 1;
            noBorrado = 0;
            memmove(comparado,comparado+tam, fin-comparado );
        }
        comparado+=tam;
    }

    if( noBorrado )
    {
        return 0;
    }

    return 1;
}




