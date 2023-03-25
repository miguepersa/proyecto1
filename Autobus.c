#include "Autobus.h"

pthread_mutex_t lock;

Autobus *autobus_init()
{
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

void autobus_destroy(Autobus *bus)
{
    free(bus);
}

void* autobus_runner(void* arg)
{
    float tiempo = 0;
    Autobus *bus = (Autobus*)arg;
    while (tiempo < bus->tiempo_recorrido)
    {
        sleep(bus->dt);
        pthread_mutex_lock(&lock);
        tiempo = tiempo + bus->dt;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
