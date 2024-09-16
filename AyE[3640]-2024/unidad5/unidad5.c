#include "unidad5.h"

float calculaPotenciaR(float base, float exponente)
{
    if(!base && !(exponente >= 0))
    {
        return ERROR_MATEMATICO;
    }

    if(!exponente)
    {
        return 1;
    }

    if(exponente > 0)
    {
        return base * calculaPotenciaR(base, exponente - 1);
    }
    else
    {
        return 1 / calculaPotenciaR(base, -exponente);
    }
}

int calculaProductoDeDosEnterosRC(int numero1, int numero2)
{
    if(!numero2)
    {
        return 0;
    }

    return numero1 + calculaProductoDeDosEnterosRC(numero1, numero2 - 1);
}

int calculaProductoDeDosEnterosR(int numero1, int numero2)
{
    int resultado;

    if(fabs(numero1) > fabs(numero2))   //para hacer menos recursiones
    {
        resultado = calculaProductoDeDosEnterosRC(fabs(numero1), fabs(numero2));
    }
    else
    {
        resultado = calculaProductoDeDosEnterosRC(fabs(numero2), fabs(numero1));
    }

    if(!((numero1 < 0 && numero2 < 0) || (numero1 >= 0 && numero2 >= 0)))
    {
        return (-1) * resultado;
    }

    return resultado;
}

int fibonacciRC(int primerTermino, int segundoTermino, int numeroDeTermino)
{
    if(4 == numeroDeTermino)
    {
        return segundoTermino;
    }

    return fibonacciRC(segundoTermino, primerTermino + segundoTermino, numeroDeTermino - 1);
}

int fibonacciR(int numeroDeTermino)
{
    if(numeroDeTermino < 0)
    {
        return ERROR_MATEMATICO;
    }

    if(!numeroDeTermino)
    {
        return 0;
    }

    if(1 == numeroDeTermino || 2 == numeroDeTermino)
    {
        return 1;
    }

    if(3 == numeroDeTermino)
    {
        return 2;
    }

    return fibonacciRC(2, 3, numeroDeTermino);
}

void decimalABinarioR(unsigned numeroAConvertir)
{
    if(numeroAConvertir >= 2)
    {
        decimalABinarioR(numeroAConvertir / 2);
        printf("%d", numeroAConvertir % 2);
    }
    else
    {
        printf("%d", numeroAConvertir % 2);
    }
}

int funcionAckermannR(int m, int n)
{
    if (0 == m)
    {
        return n + 1;
    }
    else if(m > 0 && 0 == n)
        {
            return funcionAckermannR(m - 1, 1);
        }
        else if(m > 0 && n > 0)
        {
            return funcionAckermannR(m - 1, funcionAckermannR(m, n - 1));
        }
    return ERROR_MATEMATICO;
}

size_t mStrlenR(const char* cadena)
{
    return '\0' != *cadena ? 1 + mStrlenR(cadena + 1) : 0;
}

int esPalindromoRC(const char* ini, const char* fin)
{
    if(ini < fin)
    {
        if(!ES_LETRA(*ini))
        {
            return esPalindromoRC(ini + 1, fin);
        }
        if(!ES_LETRA(*fin))
        {
            return esPalindromoRC(ini, fin - 1);
        }

        if(A_MAYUS(*ini) != A_MAYUS(*fin))
        {
            return NO_ES_PALINDROMO;
        }
    }
    return ES_PALINDROMO;
}

int esPalindromoR(const char* cadena)
{
    return '\0' == *cadena ? NO_ES_PALINDROMO : esPalindromoRC(cadena, cadena + mStrlenR(cadena) - 1);
}

void* mBsearch(const void* clave, const void* base, size_t ce, size_t tam, int (*comparar)(const void* a, const void* b))
{
    void* medio = (void*)base + (ce / 2) * tam;
    int cmp;

    cmp = comparar(medio, clave);

    if(!cmp)
    {
        return medio;
    }

    if(medio == base)
    {
        return NULL;
    }else if(cmp > 0)
        {
            return mBsearch(clave, base, (medio - base) / tam, tam, comparar);
        }
        else
        {
            return mBsearch(clave, medio + tam, (medio - base)/tam, tam, comparar);
        }
}


