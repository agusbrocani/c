#include "examen.h"
#define MAXLINE 1024

//#define RENDIREXAMEN
//#ifdef RENDIREXAMEN
//    #define desofuscar _desofuscar
//#endif // EXAMEN

int main()
{
    /*
    Ejercicio Cadenas
    ----------------------
    Mediante el metodo quieroUnaLineaDeTextoOfuscadaV1 adquiera una cita en texto
    ofuscada que impide su lectura. Cada palabra de las citas se ha ofuscado tomando
    cada letra y si la misma se encuentra en el grupo "abcdghijkoqtuv" se remplaza
    por la letra que esta hacia la izquierda tantos lugares como posicion en la palabra
    ocupa. Una palabra es un conjunto contiguo de caracteres considerados por la funcion isalpha.
    Ejemplo:
    Si la palabra es hola
    "h":un lugar atras porque es la primera letra de la palabra, queda "g"
    "o":dos lugares atras, queda "j"
    "l":No figura en grupo, no se modifica, queda "l"
    "a":cuatro lugares hacia atras, queda "q".
    Resultado esperado: hola => gjlq
    Sabiendo como se ha ofuscado implemente un algoritmo que le muestre la frase desofuscada.

    Algunos consejos:
    .Antes de codificar piense una estrategia de solucion
    .Separe el problema en partes y prueba individualmente cada una si es necesario.

    .
    Nota:
    .Las frases estan en espanol (excepto probablemente una) y son varias, en cada ejecucion puede obtener cualquiera
    aleatoriamente.

    Disclaimer: Las citas no representan las opiniones de quien formulo el ejercicio :)
    */

    char linea[MAXLINE];

    quieroUnaLineaDeTextoOfuscadaV1(linea);
    printf("Linea original: %s\n", linea);

    desofuscar(linea);
    printf("Linea desofuscada:%s\n", linea);


    return 0;
}

