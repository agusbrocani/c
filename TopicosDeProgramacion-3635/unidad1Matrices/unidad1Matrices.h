#ifndef UNIDAD1MATRICES_H_INCLUDED
#define UNIDAD1MATRICES_H_INCLUDED
#define N 5
#define TAM_FILA 2


//DS-> DIAGONAL SECUNDARIA - DP-> DIAGONAL PRINCIPAL

void cargaLoteMatriz(float matriz[][N],int cf,int cc, int opcion);
void mostrarMatriz(float matriz[][N],int cf,int cc);

double unoPuntoDoceSumaTrianguloSuperiorSinDP(float matriz[][N]);
double unoPuntoDoceSumaTrianguloInferiorSinDP(float matriz[][N]);
double unoPuntoDoceSumaTrianguloSuperiorDP(float matriz[][N]);
double unoPuntoDoceSumaTrianguloInferiorDP(float matriz[][N]);

double unoPuntoDoceSumaTrianguloSuperiorSinDS(float matriz[][N]);
double unoPuntoDoceSumaTrianguloInferiorSinDS(float matriz[][N]);
double unoPuntoDoceSumaTrianguloSuperiorDS(float matriz[][N]);
double unoPuntoDoceSumaTrianguloInferiorDS(float matriz[][N]);

double unoPuntoTreceTrazaDP(float matriz[][N]);
double unoPuntoTreceTrazaDS(float matriz[][N]);

int unoPuntoCatorceEsDiagonal(float matriz[][N]);
int unoPuntoQuinceEsDiagonal(float matriz[][N]);
int unoPuntoDieciseisEsSimetrica(float matriz[][N]);
void unoPuntoDiecisieteTrasponer(float matriz[][N]);

void unoPuntoDieciochoDarTraspuesta(float matriz[][N],int cf,int cc);   ///SOLUCIONAR mostrarMatriz, en el ambito de la funcion muestra correctamente la respuesta pero al usar mostrarMatriz no funciona

#endif // UNIDAD1MATRICES_H_INCLUDED
