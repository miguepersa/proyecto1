#ifndef SERVICIO_H
#define SERVICIO_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int hora;
    int minuto;
    int capacidad;
    struct nodo *siguiente;
}Nodo;

typedef struct servicio{
    char codigo[20];
    nodo *cabeza;
    nodo *cola;
}Servicio;

Nodo *nodo_init();
void nodo_destroy(Nodo*);

Servicio *servicio_init();
void servicio_destroy(Servicio*);
void servicio_add(Servicio*,Nodo*);
void servicio_delete(Servicio*,Nodo*);


#endif