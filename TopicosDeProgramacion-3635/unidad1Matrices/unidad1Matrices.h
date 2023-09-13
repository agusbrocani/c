#ifndef UNIDAD1MATRICES_H_INCLUDED
#define UNIDAD1MATRICES_H_INCLUDED
#define N 5
#define ORDEN 3
#define TAM_FILA 2
#define ABS(X)  (   ((X) < 0) ? ((X) * (-1)) : (X)  )

//DS-> DIAGONAL SECUNDARIA - DP-> DIAGONAL PRINCIPAL

void cargaLoteMatriz(float matriz[][N],int cf,int cc, int opcion);
void mostrarMatriz(float matriz[][N],int cf,int cc);
void mostrarMatrizEnteros(int matriz[][N],int cf,int cc);


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

void unoPuntoDieciochoDarTraspuesta(float matriz[][N],int cf,int cc);
void unoPuntoDiecinueveProducto(int matriz1[][N], int matriz2[][N],int cf1,int cc1, int cf2,int cc2);

int valido(int superior,int inferior);
int unoPuntoVeinteEquipos(int matriz[][N], int n);
void puntosPorEquipo(int matriz[][N]);


#endif // UNIDAD1MATRICES_H_INCLUDED

