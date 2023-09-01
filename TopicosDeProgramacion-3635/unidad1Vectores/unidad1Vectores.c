#include "unidad1Vectores.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarVector(const int* vec,int tam)
{
    int i;

    for(            i=0 ; i<tam; i++            )
    {
        printf("%d ",          *(vec+i)           );
    }
    printf("\n");
}
int unoPuntoUno(int* vec, int dato, int tam, int pos)
{
    if(         pos>=tam || pos<0            )
    {
        return 0;
    }

    *(vec+pos)  =   dato;

    return 1;
}

int unoPuntoDos(int* vec, int dato, int tam, int pos)
{
    int i = tam-1;  //POSTERIOR
    int aux;

    if(         pos>=tam || pos<0            )
    {
        return 0;
    }

    while(          pos > i           )
    {
        aux = *(vec+i);
        *(vec+i) = *(vec+i-1);
        *(vec+i+1) = aux;
        i--;
    }

    *(vec+pos) = dato;

    return 1;
}

int unoPuntoTres(int* vec, int dato, int* tam, int pos)
{
    int i;

    if(         pos>=  *tam || pos<0             )
    {
        return 0;
    }

    for(            i = pos; i < (*tam)-1; i++         )   //TODAS LAS ANTERIORES A AL ULTIMA, SI ERA LA ULTIMA, NO ENTRO
    {
        *(vec+i) = *(vec+i+1);
    }

    *tam = (*tam)-1;

    return 1;
}

int unoPuntoCuatro(int* vec,int* tam,int datoAEliminar)
{
    int pos =  0;
    int i;

    //para buscar la coincidencia exceptuando la ultima posicion

    while(          pos<(*tam)-1 && *(vec+pos) != datoAEliminar          )
    {
        pos++;
    }

    //caso de vector de tamaño 0, caso de que la coincidencia está en la ultima posicion

    if(     !(*tam)    ||   (pos == (*tam)-1 && *(vec+pos)!= datoAEliminar)             )
    {
        return -1;   ///NO ELIMINE NADA
    }

    //para todos los demas casos piso con lo que tengo a la derecha

    for(            i = pos; i < (*tam)-1; i++         )
    {
        *(vec+i) = *(vec+i+1);
    }

    *tam = (*tam)-1;

    return pos;
}

int unoPuntoCinco(int* vec,int* tam,int datoAEliminar)
{
    int retorno = -1;

    //como la funcion unoPuntoCuatro elimina 1 ocurrencia, la llamo hasta que no haya ocurrencias que eliminar

    while(          -1 != unoPuntoCuatro(vec,tam,datoAEliminar)            )
    {
        retorno++;
    }

    return retorno;
}


char* buscaFin(char* cadena)
{
    char* fin = cadena;

    while(          '\0'!=  *(fin))
    {
        fin++;
    }

    if(         fin==(char*)cadena         )
    {
        return NULL;
    }

    return --fin;   //IMPORTANTE: HACERLO ASI, PORQUE SINO ME QUEDA EN EL \0
}

int unoPuntoSeis(char* cadena)//palindromo
{
    char* ini = cadena;
    char* fin = buscaFin(cadena);

    while(          '\0'!=*ini && '\0'!=*fin && ini<fin          )
    {
        while(         ' '==*ini            )       //SI EMPEZÓ CON ESPACIO, LO MUEVE HASTA LA PRIMER LETRA O CARACTER
        {
            ini++;
        }

        while(          '\0'!=*fin&&(' '==*fin||'.'==*fin)           )  //SI TERMINÓ CON PUNTO O ESPACIO, LO MUEVE HASTA LA PRIMER LETRA O CARACTER-> IMPORTANTE CONSIDERAR EL '\0' antes porque estoy decrementando
        {
            fin--;
        }

        if(         A_MAYUS(*ini)!=A_MAYUS(*fin)          )     //SI LA COMPARACIÓN NO LLEGARA A SER IGUAL, YA NO ES PALINDROMO Y SALGO
        {
            return 0;
        }
        ini++;
        fin--;
    }
    return 1;
}


int unoPuntoSiete(char* cadena)
{
    char* ini = cadena;
    int retorno = 0;

    while(          '\0' != *ini          )
    {
        retorno +=   A_NUMERO(*ini);
        ini++;
    }

    return retorno;
}

unsigned miStrlen(char* cadena)
{
    char* ini = cadena;
    unsigned cantidadCaracteres = 0;

    while(          '\0' != *ini            )
    {
        cantidadCaracteres++;
        ini++;
    }

    return cantidadCaracteres;
}

int unoPuntoOcho(char* cadena, char* palabra)
{
    char* ini = cadena;
    char* fin = buscaFin(cadena)+1; //me paré en el \0 de cadena
    char* iniPalabra = palabra;
    int moduloPalabra = miStrlen(palabra);
    int cantCaracteres = 0;
    int cantApariciones = 0;

    while(          '\0'!=*ini         )    //recorro toda la cadena
    {
        while(         ' '==*ini            )       //SI EMPEZÓ CON ESPACIO, LO MUEVE HASTA LA PRIMER LETRA O CARACTER
        {
            ini++;
        }

        while(          ini<fin && A_MAYUS(*ini) == A_MAYUS(*iniPalabra)         )  //ESTO EN ALGUN MOMENTO VA A LLEGAR AL '\0' de ini o de iniPalabra y va a salir
        {
            //printf("%c vs %c\t",*ini,*iniPalabra);
            cantCaracteres++;
            ini++;
            iniPalabra++;
        }
        //printf("\nmoduloPalabra = %d, cantCaracteres = %d\n",moduloPalabra,cantCaracteres-1);
        if(         moduloPalabra == (cantCaracteres-1)         )       //cantCaracteres -1 porque pude salir del while con el \0 del fin de cadena de iniPalabra
        {
            cantApariciones++;
        }
        iniPalabra = palabra;
        cantCaracteres = 0;

        if(         ini<fin            )    //Si ya estoy parado en el final de la cadena, no es correcto incrementar, porque me voy de rango
        {
            ini++;
        }
    }

    return cantApariciones;
}

void unoPuntoNueve(char* cadena)    //normalizacion: Sin espacios iniciales-finales, 1 solo espacio intermedio entre palabra, primera letra mayuscula, todo el resto minuscula
{
    char* caracter;
    char* primerBlanco;
    char* primerCaracter;

    ///BLANCOS DEL FINAL
    caracter = cadena;
    primerBlanco = buscaFin(cadena);
    while(          caracter>primerBlanco && ' '==*primerBlanco)
    {
            primerBlanco--;
    }
    *primerBlanco = '\0';

    primerBlanco = caracter;
    while(         ' '==*caracter            )   //encuentra el primer caracter
    {
            caracter++;
    }

    while(          '\0' != *caracter         )  //mueve toda la cadena
    {
        *primerBlanco = *caracter;
        primerBlanco++;
        caracter++;
    }
    *primerBlanco = '\0';

    ///BLANCOS INTERMEDIOS
    caracter = cadena;

    while(          '\0'!= *caracter        )
    {
        while(          '\0'!=*caracter && ' ' !=*caracter           )
        {
            caracter++;
        }
        caracter++;
        primerBlanco= caracter;
        primerCaracter = caracter;

        while(          ' ' == *caracter           )
        {
            caracter++;
        }
        //ME PARO EN UNA LETRA O EN EL BARRA CERO
        while(          '\0' != *caracter           )
        {
            *primerBlanco = * caracter;
            caracter++;
            primerBlanco++;
        }
        *primerBlanco = '\0';
        caracter = primerCaracter;
    }

    caracter = cadena;
    ///NORMALIZACION DE LA CADENA
    while(          '\0'!=*caracter         )
    {
        //Primer letra
        if(         ES_LETRA(*caracter)         )
        {
            *caracter = A_MAYUS(*caracter);
            caracter++;
        }
        while(          '\0'!= *caracter && ' ' != *caracter          )
        {
            if(         ES_LETRA(*caracter)          )
            {
                *caracter = A_MINUS(*caracter);
            }
            caracter++;
        }

        if(         '\0'!=  *caracter        )
        {
            caracter++;
        }

    }
}
/*
void reemplazaLetra(char* caracter,int indiceEnCadena,char* grupo,int indiceEnGrupo)
{
    // indiceEnCadena e indiceEnGrupo llegan como posiciones de UN VECTOR, tengo que hacer las correcciones pertinentes
    int tamGrupo = miStrlen(grupo); //cantCaracteres sin el'\0' =14     grupo+tamCadena-1 = ultima posicion valida
    int lugaresAMover;
    lugaresAMover = indiceEnGrupo+indiceEnCadena; *(caracter) = *(grupo+indiceEnGrupo+IndiceEnCadena) ->indiceEnGrupo+IndiceEnCadena > tamCadena-1

    while(          lugaresAMover>tamGrupo-1     )
    {
        lugaresAMover = lugaresAMover-(tamGrupo-1);
    }
    printf("LMact= %d\n",lugaresAMover);

    //lugaresAMover=lugaresAMover-(grupo+tamGrupo-1)-(grupo+indiceEnGrupo);//MIENTRAS SEA

    *caracter=*(grupo+lugaresAMover);
}

void cambiaLetra(char* caracter, int indiceEnCadena)
{
    char* grupo = "abcdghijkoqtuv";
    char* recorroGrupo = grupo;

    while(          '\0' != *recorroGrupo && A_MINUS(*caracter)!=*recorroGrupo           )
    {
        recorroGrupo++;
    }
    if(         '\0' != *recorroGrupo && A_MINUS(*caracter) == *recorroGrupo          )
    {
        printf("%c - INDICE GRUPO: %d INDICE EN CADENA: %d\n%s\n",*caracter,recorroGrupo-grupo,indiceEnCadena,grupo);///r-g VERIFICADO,
        reemplazaLetra(caracter,indiceEnCadena,grupo,recorroGrupo-grupo);       //letra a cambiar, cuando debo moverme en el grupo, el grupo , posicion de la letra en el grupo
    }
}

void unoPuntoDiezDesofuscar(char* cadena)   ///COMPLETAMENTE PROBADA
{
    char* caracter = cadena;

    while(          '\0' != *caracter           )
    {
        //printf("%c",A_MINUS(*caracter));
        if(         ES_LETRA(*caracter)         )
        {
            cambiaLetra(caracter,caracter-cadena);    //letra a cambiar - posicion en la cadena
        }
        caracter++;
    }
}
*/
int miStrcmpi(char* cadena1,char* cadena2)
{
    while(          '\n' != *cadena1 && '\n' != *cadena2 && A_MAYUS(*cadena1) == A_MAYUS(*cadena2)            )
    {
        cadena1++;
        cadena2++;
    }

    if(         A_MAYUS(*cadena1) > A_MAYUS(*cadena2)            )
    {
            return 1;
    }

    if(         A_MAYUS(*cadena1) < A_MAYUS(*cadena2)            )
    {
            return -1;
    }

    return 0;
}

void unoPuntoOnce()
{
    char buffer[2][TAM_BUFFER];
    char* cadena1 = buffer[0];
    char* cadena2 = buffer[1];
    char aux;

    do
    {
        printf("\nIngrese 2 cadenas hasta que sean tengan la misma cantidad de caracteres\n");
        printf("Ingrese la primer cadena: \t");
        fgets(buffer[0],TAM_BUFFER,stdin);      ///RECORDAR: fgets me inserta un salto de linea al final, por lo que si ingreso la palabra "hola" el modulo sera 5, porque en realidad esta almacenado hola\n\0
        printf("\n");
        printf("Ingrese la segunda cadena: \t");
        fgets((buffer[1]),TAM_BUFFER,stdin);
        printf("\n");
    }while(         miStrlen(buffer[0]) != miStrlen(buffer[1])          );

    if(         1 == miStrcmpi( buffer[0],buffer[1] )        )   //si la cadena1 era más grande que la cadena 2
    {
        while(          '\0' != *cadena1 && '\0' != *cadena2       )    //es valido hacer esto porque tienen el mismo tamaño las 2 cadenas[podria hacerlo hasta el \n inclusive]
        {
            aux = *cadena1;
            *cadena1 = *cadena2;
            *cadena2 = aux;
            cadena1++;
            cadena2++;
        }
    }

    printf("Cadena 1: %s",buffer[0]);
    printf("Cadena 2: %s",buffer[1]);
}

