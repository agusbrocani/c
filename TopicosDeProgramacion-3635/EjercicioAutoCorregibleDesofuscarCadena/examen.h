#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED

#define ES_LETRA(X)     (           (X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z')           )

size_t quieroUnaLineaDeTextoOfuscadaV1(char* linea);

int miProximaPalabra(char** cadena,char** palabra);
void verificaYCambiaGrupo(char* palabra, int pos);
void cambiaLetra(char* palabra, int tamPalabra);
char* desofuscar(char* linea);

#endif // OFUSCADO_INCLUDED
