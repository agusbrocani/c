#ifndef HEADER31A_H_INCLUDED
#define HEADER31A_H_INCLUDED
#define ES_LETRA(X)     (           (X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z')           )

unsigned miStrlen(const char *cadena);
char* miStrcpy(char *destino, const char *origen);
char* miStrcat(char*cadena1, const char *cadena2);
char* miStrchr(char *cadena, int caracterBuscado);
char* miStrrchr(char *cadena, int caracterBuscado);
char* miStrstr(const char *cadena, const char *cadenaABuscar);
char* miStrncpy(char *destino, const char *origen, unsigned cantidadACopiar);
int proximaPalabra(char** cadena,char** palabra);


#endif // HEADER31A_H_INCLUDED
