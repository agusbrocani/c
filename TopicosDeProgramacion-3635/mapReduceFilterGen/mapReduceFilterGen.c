#include "mapReduceFilterGen.h"

void mostrarEntero(const void* dato)
{
    printf("%d ", *(int*)dato);
}

void mostrarFloat(const void* dato)
{
    printf("%.2f ", *(float*)dato);
}

void recorrerVector(const void* vec, size_t tam, size_t ce, void (*mostrar) (const void* dato))
{
    int i;

    if( ce < 1 )
    {
        return;
    }

    for( i = 0; i < ce; i++)
    {
        mostrar(vec);

        vec += tam;
    }
    printf("\n");
}
int comparaEntero(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)b);
}
void* buscarMenor(const void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b))
{
    void* menor =(void*) vec;
    void* sig =(void*) vec+tam;
    int i;

    if( ce < 1 )
    {
        return NULL;
    }

    for( i = 0; i < ce - 1; i++ )   //ce - 1 porque utilizo el siguiente, cuando esté parado en el anteultimo, el ultimo elemento esta siendo comparado
    {
        if(         comparar(menor,sig) > 0        )
        {
            menor = sig;
        }

        sig += tam;
    }

    return menor;
}

void* buscarMayor(const void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b))
{
    void* mayor =(void*) vec;
    void* sig =(void*) vec + tam;
    int i;

    if( ce < 1 )
    {
        return NULL;
    }

    for( i = 0; i < ce - 1; i++)
    {
        if(         comparar(mayor,sig) < 0          )
        {
            mayor = sig;
        }

        sig += tam;
    }

    return mayor;
}

void intercambio(void* a, void* b, size_t tam)
{
    int i;
    char aux;

    for( i = 0; i < tam; i++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }

}
void ordenarSeleccionAscendente(void* vec, size_t tam ,size_t ce, int (*comparar)(const void* a, const void* b))
{
    void* elementoRecorrido = vec;
    void* menor;
    int i;

    if( ce <= 1 )   //esta linea es muy importante, si la omito, buscarMenor puede devolver NULL y rompo todo con comparar
    {
        return;
    }

    ///Explicacion teorica de porque es importante el if de arriba en ordenar por seleccion
    //printf("0 < ce-1 = %s -> ce-1 = %I64u",(0 < ce-1)? "TRUE": "FALSE", ce-1);
    ///size_t es un tipo de dato sin signo, que varia su capacidad dependiendo si se trata de un sistema operativo de 32 o 64 bits
    /// 18,446,744,073,709,551,616 es el rango maximo de representacion de size_t en 64 bits -> desde 0 a 18,446,744,073,709,551,615
    /// cuando hago (0[en size_t] - 1) realmente hago 0x0000 0000 + 0xFFFF FFFF(-1 en complemento signo y modulo) = 0xFFFF FFFF que representa el numero 18,446,744,073,709,551,615 en decimal
    /// ENTRE AL FOR 0 < 18,446,744,073,709,551,615 -> VERDADERO
    /// menor = buscarMenor(elementoRecorrido, sizeof(int), (0 - 0) ,comparar ) -> RETORNO de buscarMenor -> menor = NULL   (me saco el if(ce < 1) de buscarMenor)
    /// comparar(NULL, elementoRecorrido) ->    comparar(en el caso de compararEntero) hace return *(int*) NULL - *(int*) elementoRecorrido PROVOCANDO QUE SE ROMPA


    for( i = 0; i < ce - 1; i++ )   //Cuidado si hago i = 1 -> uso la i para hacer ce
    {
        menor = buscarMenor(elementoRecorrido,tam,ce - i,comparar);   //ce - i para no volver a buscar entre los que ya fueron recorridos(porque ya estan ordenados)

        if(         comparar( menor, elementoRecorrido) < 0          ) //Uso comparar para que menor NO SEA IGUAL al elementoRecorrido, SI SON IGUALES, voy a permutar el mismo valor, haciendo que no sea eficiente
        {
            intercambio(menor,elementoRecorrido,tam);
        }

        elementoRecorrido += tam;
    }

}

void ordenarSeleccionDescendente(void* vec,size_t tam, size_t ce, int (*comparar)(const void* a, const void* b))
{
    void* elementoRecorrido = vec;
    void* mayor;
    int i;

    if( ce <= 1 )
    {
        return;
    }

    for( i = 0; i < ce - 1; i++)
    {
        mayor = buscarMayor(elementoRecorrido,tam,ce - i,comparar);

        if(         comparar(mayor,elementoRecorrido)  > 0        ) //mayor NO SEA IGUAL al elementoRecorrido
        {
            intercambio(mayor,elementoRecorrido,tam);
        }

        elementoRecorrido += tam;
    }
}

void acc(void* resultado,const void* dato)
{
    int d = (*(int*)dato) + 1;

    memcpy(resultado,&d,sizeof(int));

}

void fMap(const void* vec, size_t tam, size_t ce, void (*accion) (void* resultado,const void* dato),void (*mostrar)(const void* resultado))
{
    void* vResultado;
    void* iniVResultado;
    int i;

    if(         ce < 1          )
    {
        return;
    }

    vResultado = malloc(tam*ce);
    iniVResultado = vResultado;

    if(         NULL == vResultado         )
    {
        return;
    }


    for( i = 0; i < ce; i++)
    {
        accion(vResultado,vec);

        vec += tam;
        vResultado += tam;
    }

    vResultado = iniVResultado;

    for( i = 0; i < ce; i++ )
    {
        mostrar(vResultado);
        vResultado += tam;
    }

    free(iniVResultado);
}

void filter(const void* vec,const void* filtro, size_t tam, size_t ce, int (*comparar) (const void* a,const void* b),void (*mostrar)(const void* resultado))
{
    while(          ce          )
    {
        if(         comparar(vec,filtro)         )
        {
            mostrar(vec);
        }

        ce--;
        vec += tam;
    }

}
void promedio(void* a,const void* b)
{
    float resultado;

    resultado = ((*(float*)a + *(float*)b)/2);

    printf("\nResultado = %.2f\n",resultado);

    memcpy(a,(void*)&resultado,sizeof(float));
}
/*
void reduce(const void* vec, size_t tam, size_t ce, void (*accion) (void* a,const void* b),void (*mostrar)(const void* resultado))
{
    void* provisorio;
    int i;

    if(         ce < 1          )
    {
        return;
    }
    else if( ce == 1 )
    {
        mostrar(vec);
    }

    provisorio = malloc(tam);

    if(         NULL == provisorio           )
    {
        return;
    }


    for( i = 0; i < ce; i++ )
    {
        memcpy(provisorio,vec,tam);
        accion(provisorio,vec+tam);
        vec += tam;
    }

    printf("\n\n");
    mostrar(provisorio);
    printf("\n");
    free(provisorio);
}*/
