#ifndef PARADA_H
#define PARADA_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Autobus.h"

typedef struct parada
{

    Autobus *autobuses[MAX_BUSES];
    char codigo[20];
    char nombre[100];
    int duracion_h;
    int duracion_m;
    int usuarios[8];
    int nbuses;
}Parada;

Parada *parada_init();
void parada_destroy(Parada*);
void parada_impresion(Parada *, int);
void parada_crear_buses(Parada*, pthread_t[]);

#endif