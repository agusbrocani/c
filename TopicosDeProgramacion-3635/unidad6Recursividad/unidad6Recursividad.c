#include "unidad6Recursividad.h"

size_t rFactorial(int numero)
{
    return numero == 0 ? 1 : numero * rFactorial(numero - 1);
}

void mostrarContenidoArray(const char* vec)
{
    if(*vec != '\0')
    {
        printf("%c ", *vec);
        mostrarContenidoArray(++vec);
    }
}

void mostrarContenidoArrayInverso(const char* vec)
{
    if(*vec != '\0')
    {
        mostrarContenidoArrayInverso(vec + 1);
        printf("%c ", *(vec));
    }
}

void mostrarContenidoArrayInversoYSumaNumeros(const char* vec, int* suma)
{
    *suma = 0;

    if(*vec != '\0')
    {
        mostrarContenidoArrayInversoYSumaNumeros(++vec, suma);
        printf("%c ", *(--vec));
        *suma += ES_NUMERO(*vec) ? A_NUMERO(*vec) : (0);
    }
}

void contenidoArrayYSuma(const int* vec, int* suma, int tamVec)
{
    *suma = 0;

    if(tamVec != 0)
    {
        contenidoArrayYSuma(++vec, suma, --tamVec);
        printf("%d ", *(--vec));
        *suma += *vec;
    }
}

void contenidoArrayYSumaPares(const int* vec, int* suma, int tamVec){

    *suma = 0;

    if(tamVec != 0)
    {
        contenidoArrayYSumaPares(++vec, suma, --tamVec);
        printf("%d ", *(--vec));
        *suma += (ES_PAR(*vec)? *vec : 0);
    }
}

void contenidoArrayYSumaPosPares(const int* vec, int* suma, int tamVec)
{
    *suma = 0;

    if(tamVec != 0)
    {
        contenidoArrayYSumaPosPares(++vec, suma, --tamVec);
        printf("%d ", *(--vec));
        *suma += ES_PAR(tamVec)? *vec : 0;
    }
}

size_t rStrlen(const char* cadena)
{
    return *cadena? rStrlen(cadena+1) + 1 : 0;
}

char* rStrchr(char* cadena, int caracterBuscado)
{
    if(*cadena == '\0')
    {
        return NULL;
    }
    if(*cadena == caracterBuscado)
    {
        return cadena;
    }
    return rStrchr(cadena + 1, caracterBuscado);
}

char* rStrrchr(char* cadena, int caracterBuscado)
{
    char* direccionCaracter;

    if(*cadena != '\0')
    {
        direccionCaracter = rStrrchr(cadena + 1, caracterBuscado);
    }
    else
    {
        return NULL;
    }

    if(*cadena == caracterBuscado && (direccionCaracter == NULL || *direccionCaracter != caracterBuscado))
    {
        return cadena;
    }
    return direccionCaracter;
}

char* rStrcpy(char* cadena, const char* cadenaACopiar)
{
    if(*cadenaACopiar != '\0')
    {
        *cadena = *cadenaACopiar;
        rStrcpy(cadena + 1, cadenaACopiar + 1);
    }

    if(*cadenaACopiar == '\0')
    {
        *cadena = '\0';
    }
//    *(cadena + rStrlen(cadenaACopiar)) = '\0';
    return cadena;
}

int esPalindromo(const char *cadena)
{
    const char *inicioCadena;
    const char *finCadena;

    inicioCadena = cadena;
    finCadena = cadena + rStrlen(cadena)-1;
    return rEsPalindromo(cadena, inicioCadena, finCadena);
}

int rEsPalindromo(const char* cadena, const char *inicioCadena, const char *finCadena)
{
    if(inicioCadena < finCadena)
    {
        if(         !ES_LETRA(*inicioCadena)            )
        {                                                           //sin el return, solamente hago lo que hace la funcion hasta ahi y si sumo o resto lo hago 1 vez
            return rEsPalindromo(cadena,inicioCadena+1,finCadena);  //con el return + funcionRecursiva -> itero la cantidad de veces que necesito para incrementar o sumar
        }

        if(         !ES_LETRA(*finCadena)               )
        {
            return rEsPalindromo(cadena,inicioCadena,finCadena-1);
        }

       return A_MAYUS(*inicioCadena) != A_MAYUS(*finCadena) ? 0 : rEsPalindromo(cadena,inicioCadena+1,finCadena-1) ;
    }
    else
    {
        return 1;
    }

}

unsigned short rCalcularCoeficienteTrianguloTartaglia(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return rCalcularCoeficienteTrianguloTartaglia(n - 1, k - 1) + rCalcularCoeficienteTrianguloTartaglia(n - 1, k);
    }
}
