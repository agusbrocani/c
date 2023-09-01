#ifndef CLASE2H_H_INCLUDED
#define CLASE2H_H_INCLUDED
#define ES_LETRA(X) (   (           (X>='A') && (X<='Z')            ) || (          (X>='a')&& (X<='z')         )         )
#define A_MAYUS(X)  (   ( (X >= 'a') && (X <= 'z') )     ? (X -('a' - 'A'))  : (X)          )
#define A_MINUS(X)  (   ( (X >= 'A') && (X <= 'Z') )     ? (X +('a' - 'A'))  : (X)          )
#define A_NUMERO(X) (           (           (X - '0') >= 0 && (X - '0') <= 9            )          ? (X-'0') : (0))
#define ABS(X)  ((X<0)? (X*(-1)):(X))
#define TAM_BUFFER 100

void mostrarVector(const int* vec,int tam);
int unoPuntoUno(int* vec, int dato, int tam, int pos);
int unoPuntoDos(int* vec, int dato, int tam, int pos);
int unoPuntoTres(int* vec, int dato, int* tam, int pos);
int unoPuntoCuatro(int* vec,int* tam,int datoAEliminar);
int unoPuntoCinco(int* vec,int* tam,int datoAEliminar);
char* buscaFin(char* cadena);   //ME POSICIONA EN LA ULTIMA LETRA
int unoPuntoSeis(char* cadena);
int unoPuntoSiete(char* cadena);
unsigned miStrlen(char* cadena);
int unoPuntoOcho(char* cadena, char* palabra);
void unoPuntoNueve(char* cadena);
void cambiaLetra(char* caracter, int indiceEnCadena);
void unoPuntoDiezDesofuscar(char* cadena);
int miStrcmpi(char* cadena1,char* cadena2);
void unoPuntoOnce();
#endif // CLASE2H_H_INCLUDED
