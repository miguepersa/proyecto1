#ifndef AUTOBUS_H
#define AUTOBUS_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bus{
    
    int capacidad;
    int pasajeros;
    float tiempo_recorrido;

}Autobus;

Autobus *autobus_init();
void autobus_destroy(Autobus*);

#endif