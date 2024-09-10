#include "../../include/pila/sumarEnterosConDosPilas.h"

void sumarEnterosConDosPilas(tPila* pila1, tPila* pila2, tPila* pilaResultado)
{
    int buffer1;
    int buffer2;
    int resultado;
    int carry = 0;
    int tam = sizeof(int);
    int retorno1 = desapilar(pila1, &buffer1, tam);
    int retorno2 = desapilar(pila2, &buffer2, tam);

    while(retorno1 && retorno2)
    {
        resultado = (buffer1 + buffer2 + carry) % 10;
        carry = (buffer1 + buffer2 + carry) / 10;

        apilar(pilaResultado, &resultado, tam);

        retorno1 = desapilar(pila1, &buffer1, tam);
        retorno2 = desapilar(pila2, &buffer2, tam);
    }

    while(retorno1)
    {
        resultado = (buffer1 + carry) % 10;
        carry = (buffer1 + carry) / 10;
        apilar(pilaResultado, &resultado, tam);
        retorno1 = desapilar( pila1, &buffer1, tam);
    }

    while(retorno2)
    {
        resultado = (buffer2 + carry) % 10;
        carry = (buffer2 + carry) / 10;
        apilar(pilaResultado, &resultado, tam);
        retorno2 = desapilar(pila2, &buffer2, tam);
    }

    if (carry)
    {
        apilar(pilaResultado, &carry, tam);
    }
}
