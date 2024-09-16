#include "unidad5.h"

int compararEnteros(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void mostrarEntero(const void* dato)
{
    printf("%d\t", *(int*)dato);
}

int main()
{
    int coleccion[] = {0,1,2,3,4,5,6,7,8,9,10};
    int ce = sizeof(coleccion) / sizeof(coleccion[0]);
    int tam = sizeof(coleccion[0]);

    //calculaPotenciaR
    int base = 2;
    int exponente = 0;

    //calculaProductoDeDosEnterosR
    int productoNumero1 = 5;
    int productoNumero2 = -5;

    //fibonacciR
    int numeroDeTerminoFibonacci = 17;

    //decimalABinarioR
    int numeroDecimalABinario = 8;

    //funcionAckermannR
    int m = 3;
    int n = 2;

    //mBsearch
    int clave = 10;
    void* retorno;

    //esPalindromoR
    char cadena1[] = "Arriba la BIRRA!!!";
    char cadena2[] = "Anita, lava la tina";
    char noEsPalindromo[] = "Hola mundo";

    t_lista lista;
    int i;


    if(ERROR_MATEMATICO == calculaPotenciaR(base, exponente))
    {
        printf("ERROR MATEMATICO en calculaPotenciaR\n");
    }
    else
    {
        printf("BASE: %d\tEXPONENTE: %d\n(%d)^%d = %.3f\n",
                base, exponente,
                base, exponente,
                calculaPotenciaR(base, exponente)
               );
    }

    printf("PRODUCTO DE %d * %d = %d\n", productoNumero1, productoNumero2, calculaProductoDeDosEnterosR(productoNumero1, productoNumero2));

    if(ERROR_MATEMATICO == fibonacciR(numeroDeTerminoFibonacci))
    {
        printf("ERROR MATEMATICO en fibonacciR\n");
    }
    else
    {
        printf("Fibonacci del termino %d: %d\n", numeroDeTerminoFibonacci, fibonacciR(numeroDeTerminoFibonacci));
    }

    printf("DECIMAL %d A BINARIO:\t", numeroDecimalABinario);
    decimalABinarioR(numeroDecimalABinario);
    printf("\n");

    if(ERROR_MATEMATICO == funcionAckermannR(m, n))
    {
        printf("ERROR MATEMATICO en funcionAckermannR\n");
    }
    else
    {
        printf("Funcion de Ackermann(%d, %d) = %d\n", m, n, funcionAckermannR(m, n));
    }


    if(NULL == (retorno = mBsearch(&clave, coleccion, ce, tam, compararEnteros)))
    {
        printf("NO LO ENCONTRE\n");
    }
    else
    {
        printf("ENCONTRE LA CLAVE: %d\n",*(int*)retorno);
    }

    if (esPalindromoR(cadena1))
    {
        printf("La cadena \"%s\" es un palindromo.\n", cadena1);
    }
    else
    {
        printf("La cadena \"%s\" NO es un palindromo.\n", cadena1);
    }

    if (esPalindromoR(cadena2))
    {
        printf("La cadena \"%s\" es un palindromo.\n", cadena2);
    }
    else
    {
        printf("La cadena \"%s\" NO es un palindromo.\n", cadena2);
    }

    if (esPalindromoR(noEsPalindromo))
    {
        printf("La cadena \"%s\" es un palindromo.\n", noEsPalindromo);
    }
    else
    {

        printf("La cadena \"%s\" NO es un palindromo.\n", noEsPalindromo);
    }

    printf("\n");
    system("pause");
    system("cls");

    crearLista(&lista);

    printf("Insertado en lista recursivo:\n");
    for(i = 0; i < ce; i++)
    {
        mostrarEntero(&coleccion[i]);
        insertarAlFinalR(&lista, &coleccion[i], tam);
    }

    printf("\n");
    system("pause");
    system("cls");

    printf("Mostrando lista en orden inverso recursivo:\n");
    mostrarListaEnOrdenInversoR(&lista, mostrarEntero);

    vaciarLista(&lista);

    printf("\n");
    system("pause");
    system("cls");

    return 0;
}
