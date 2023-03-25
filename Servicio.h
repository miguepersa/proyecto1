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
    int nbuses;
    Nodo *cabeza;
    Nodo *cola;
    struct servicio *siguiente;
}Servicio;

typedef struct lista_servicio{
    int cantidad;
    Servicio *cabeza;
    Servicio *cola;

}Lista_Servicio;


Nodo *nodo_init();
void nodo_destroy(Nodo*);

Servicio *servicio_init();
void servicio_destroy(Servicio*);
void servicio_add(Servicio*,int,int,int);
void servicio_delete(Servicio*,Nodo*);

Lista_Servicio *lista_servicio_init();
void lista_servicio_destroy(Lista_Servicio* ls);
void lista_servicio_add(Lista_Servicio* ls, Servicio* s);
void lista_servicio_print(Lista_Servicio* ls);
int lista_servicio_buscar_nbuses(lista_servicio* ls, char codigo[]);
Servicio* lista_servicio_buscar_servicio(lista_servicio* ls, char codigo[]);


#endif