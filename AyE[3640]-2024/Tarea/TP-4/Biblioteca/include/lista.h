#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define NO_PUDE_INSERTAR 0
#define NO_HAY_ELEMENTOS 0
#define OK 1

#define MENOR(X,Y) (((X)>(Y))? (Y):(X))

typedef struct s_nodo
{
    struct s_nodo* sig;
    void* dato;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_lista;

#endif // LISTA_H_INCLUDED
