#include "Autobus.h"

Autobus *autobus_init(){
    Autobus *b = (Autobus*) malloc(sizeof(Autobus));
    if (!b)
    {
        perror(strerror(errno));
        return NULL;
    }

    b->capacidad = 0;
    b->pasajeros = 0;
    b->tiempo_recorrido = 0.0;
    return b;
}

void autobus_destroy(Autobus*){

}