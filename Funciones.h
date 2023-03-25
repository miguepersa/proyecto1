#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

#include "Parada.h"
#include "Servicio.h"

int leer_caracterizacion_carga(char*, Parada*);
void leer_caracterizacion_de_servicio(char*, Lista_Servicio*);
float buscar_hora_inicio(Lista_Servicio*);
Servicio* buscar_servicio(Lista_Servicio*);

#endif