#include <stdio.h>
#include <stdlib.h>
#include "unidad1Vectores.h"

int main()
{
    int vec[] = {0,1,2,3,4,5,1,1,8,9};
    int dato = 27;
    int pos = 5;
    int TAM = sizeof(vec)/sizeof(int);
    int datoAEliminar = 1;
    int retorno;
    char pruebaPalindromo[] = "  HOLAALOH"; //A luna ese anula , ANA son palindromos
    char pruebaNumerico[] = "a123456789b"; //La suma de los numeros del 1 al 9 da 45, como para usar de caso de prueba
    char pruebaSubcadena[] = "Ahola111HOLAholaA";
    char subcadena[] = "hola";
    char aNormalizar[] = "   hOLA   COMO   ESTAS, todo bieN?  ";
    //char ofuscar[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";


    mostrarVector(vec,TAM);

    if(         !unoPuntoUno(vec,dato,TAM,pos)          )
    {
        printf("NO SE PUDO INSERTAR, pos>= TAM\n");
    }
    else
    {
        mostrarVector(vec,TAM);
    }

    if(         !unoPuntoDos(vec,dato,TAM,pos)          )
    {
        printf("NO SE PUDO INSERTAR, pos>= TAM\n");
    }
    else
    {
        mostrarVector(vec,TAM);
    }

    if(         !unoPuntoTres(vec,dato,&TAM,pos)          )
    {
        printf("NO SE PUDO INSERTAR, pos>= TAM\n");
    }
    else
    {
        mostrarVector(vec,TAM);
    }

    if(         -1 ==(  retorno = unoPuntoCuatro(vec,&TAM, datoAEliminar) )          )
    {
        printf("NO SE ELIMINO NADA\n");
    }
    else
    {
        printf("ELIMINE UNA APARICION DE %d EN LA POSICION %d DEL VECTOR\n",datoAEliminar,retorno);
        mostrarVector(vec,TAM);
    }

    if(         -1 ==(  retorno = unoPuntoCinco(vec,&TAM, datoAEliminar) )          )
    {
        printf("NO SE ELIMINO NADA\n");
    }
    else
    {
        printf("ELIMINARON TODAS LAS APARECIONES DEL %d\n",datoAEliminar);
        mostrarVector(vec,TAM);
    }

    if(         !unoPuntoSeis(pruebaPalindromo)         )
    {
        printf("La cadena: '%s'\nNO es un palindromo\n",pruebaPalindromo);
    }
    else
    {
        printf("La cadena: '%s'\nEs un palindromo\n",pruebaPalindromo);
    }

    if(         !(retorno = unoPuntoSiete(pruebaNumerico))            )
    {
        printf("La cadena no contenia valores numericos\n");
    }
    else
    {
        printf("El valor numerico de la cadena es %d\n",retorno);
    }

    if(         !(retorno = unoPuntoOcho(pruebaSubcadena,subcadena))          )
    {
        printf("No hubo apariciones de la subcadena '%s' en la cadena\n",subcadena);
    }
    else
    {
        printf("Hubo %d apariciones de la subcadena '%s'\n",retorno,subcadena);
    }

    unoPuntoNueve(aNormalizar);
    printf("Normalizada: %s\n",aNormalizar);
/*
    printf("Ofuscada: %s\n",ofuscar);
    unoPuntoDiezDesofuscar(ofuscar);
    printf("\nDesofuscada: %s\n",ofuscar);
*/
    unoPuntoOnce();


    return 0;
}
