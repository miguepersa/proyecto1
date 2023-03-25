#ifndef AUTOBUS_H
#define AUTOBUS_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


typedef struct bus{
    
    int capacidad;
    int pasajeros;
    float tiempo_recorrido;
    float dt;
    int pasajeros_por_horario[8];
}Autobus;

Autobus *autobus_init();
void autobus_destroy(Autobus*);
void* autobus_runner(void*);

#endif