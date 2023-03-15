#ifndef PARADA_H
#define PARADA_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Autobus.h"
#include "Settings.h"


typedef struct parada{

    Autobus *autobuses[MAX_BUSES];
    char codigo[20];
    char nombre[100];
    char hora_llegada[10];
    float tiempo_ruta;
    int usuarios[8];
    int nbuses;
}Parada;

Parada *ruta_init();
void ruta_destroy(Parada*);

#endif