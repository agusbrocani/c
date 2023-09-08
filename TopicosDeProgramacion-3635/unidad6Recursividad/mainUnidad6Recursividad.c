#include <stdio.h>
#include <stdlib.h>
#include "unidad6Recursividad.h"

int main()
{
    int n;
    int k;
    int i;
    int suma;
    char letra = 'a';
    char cadena[] = "123";
    char cadena2[] = "Gracias";
    char cadena3[] = "Hola mundo!";
    char cadena4[] = "___aa_ArribA__lA____\t_bIrRaaA___";
    int vec[TAM] = {1, 2, 3, 4, 5};

    for(i = 0; i < 5; i++)
    {
        printf("Factorial de %d: %I64u\n", i, rFactorial(i));
    }
    mostrarContenidoArray(cadena);
    printf("\n");
    mostrarContenidoArrayInverso(cadena);
    printf("\n");

    printf("Contenido inverso y suma:\n");
    mostrarContenidoArrayInversoYSumaNumeros(cadena, &suma);
    printf("\n");
    contenidoArrayYSuma(vec, &suma, TAM);
    printf("\nLa suma da: %d\n", suma);
    contenidoArrayYSumaPares(vec, &suma, TAM);
    printf("\nLa suma da: %d\n", suma);
    contenidoArrayYSumaPosPares(vec, &suma, TAM);
    printf("\nLa suma da: %d\n\n", suma);
    printf("Longitud cadena: %I64u\n", rStrlen(cadena));
    printf("Posicion de la %c: %I64u\n", letra, rStrchr(cadena2, letra) - cadena2);
    printf("Posicion de la %c: %I64u\n", letra, rStrrchr(cadena2, letra) - cadena2);
    printf("Cadena sin copiar: %s\n", cadena3);
    printf("Cadena copiada: %s\n", rStrcpy(cadena3, cadena2));

    if(!esPalindromo(cadena4))
    {
        printf("La cadena NO es un palindromo.\n");
    }
    else
    {
        printf("La cadena es un palindromo.\n");
    }

    for (n = 0; n <= 18; n++)
    {
        printf("Potencia %d: ", n);

        for (k = 0; k <= n; k++)
        {
            printf("%d ", rCalcularCoeficienteTrianguloTartaglia(n, k));
        }
        printf("\n");
    }

    return 0;
}
