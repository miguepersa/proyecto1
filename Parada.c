#include "Parada.h"

Parada *parada_init()
{
    Parada *r = (Parada*) malloc(sizeof(Parada));
    if (!r)
    {
        perror(strerror(errno));
        return NULL;
    }

    r->tiempo_ruta = 0.0;
    return r;
}

void parada_destroy(Parada *r)
{
    int i;
    for (i = 0; i < r->nbuses; i++)
    {
        autobus_destroy(r->autobuses[i]);
    }

    free(r);
    
}