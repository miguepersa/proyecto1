#include "Ruta.h"

Ruta *ruta_init()
{
    Ruta *r = (Ruta*) malloc(sizeof(Ruta));
    if (!r)
    {
        perror(strerror(errno));
        return NULL;
    }

    r->nbuses = 0;
    r->tiempo_ruta = 0;
    r->pasajeros_esperando = 0;
    return r;
}

void ruta_destroy(Ruta *r)
{
    int i;
    for (i = 0; i < r->nbuses; i++)
    {
        autobus_destroy(r->autobuses[i]);
    }

    free(r);
    
}