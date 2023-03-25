#include "Parada.h"

extern pthread_mutex_t lock;

Parada *parada_init()
{
    Parada *p = (Parada*) malloc(sizeof(Parada));
    if (!p)
    {
        perror(strerror(errno));
        return NULL;
    }

    p->duracion_h = 0;
    p->duracion_m = 0;
    p->nbuses = 0;
    
    return p;
}

void parada_destroy(Parada *p)
{
    int i;
    for (i = 0; i < p->nbuses; i++)
    {
        autobus_destroy(p->autobuses[i]);
    }

    free(p);
    
}

void parada_impresion(Parada *p, int numero_p)
{
    int i;

    while(i<numero_p)
    {
        printf("Informacion de parada %s:\n",p[i].codigo);
        printf("--------------------------\n");

        printf("Nombre: %s. Duracion H: %d. Duracion M: %d. Usuarios0: %d. Usuarios1: %d. Usuarios2: %d. Usuarios3: %d. Usuarios4: %d. Usuarios5: %d. Usuarios6: %d. Usuarios7: %d. Numero de autobuses: %d\n",p[i].nombre,p[i].duracion_h, p[i].duracion_m, p[i].usuarios[0], p[i].usuarios[1], p[i].usuarios[2],p[i].usuarios[3],p[i].usuarios[4],p[i].usuarios[5],p[i].usuarios[6],p[i].usuarios[7], p[i].nbuses);

        printf("\n");
        i++;
    }

}


pthread_t* parada_crear_buses(Parada* p, Autobus* bus)
{

    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("Error en mutex lock\n");
        exit(EXIT_FAILURE);
    }

    pthread_t hilo;
    int th = pthread_create(&hilo, NULL, autobus_runner, bus);
    if (th != 0) 
    {
        perror("Error al crear hilo de autobús");
        exit(EXIT_FAILURE);
    }
    return &hilo;
    
}