#ifndef RUTA_H
#define RUTA_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Autobus.h"
#include "Settings.h"


typedef struct ruta{

    Autobus *autobuses[MAX_BUSES];
    char codigo[20];
    char nombre[100];
    char hora_llegada[10];
    float duracion_h;
    int duracion_m;
    int usuarios[8];
}Ruta;

Ruta *ruta_init();
void ruta_destroy(Ruta*);

#endif