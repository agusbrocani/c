#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lista.h"

void crearListaCircular(t_lista* pl);
void vaciarListaCircular(t_lista *pl);
int listaCircularVacia(const t_lista *pl);

#endif // LISTACIRCULAR_H_INCLUDED
