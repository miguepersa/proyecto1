#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

/*#include "Ruta.h"
#include "Autobus.h"*/
#include "Funciones.h"

extern char* optarg;

int main(int argc, char* const* argv)
{
   /* int opt;
    char *a_serv = NULL;
    char *a_carg = NULL;
    float tiempo = 0.25;*/

    /* Parsing de argumentos del programa */
    /*while ((opt = getopt(argc, argv, "s:c:t:")) != -1)
    {
        switch (opt)
        {
        case 's':
            a_serv = (char*)malloc(sizeof(char) * strlen(optarg));
            strcpy(a_serv, optarg);
            break;
        case 'c':
            a_carg = (char*)malloc(sizeof(char) * strlen(optarg));
            strcpy(a_carg, optarg);
            break;
        case 't':
            tiempo = atof(optarg);
            break;
        default: 
            perror("Uso: ./simutransusb -s <archivo> [-c <archivo>] [-t <num>]");
            exit(1);
            break;
        }

    }
    
    
    if (!a_serv)
    {
        perror("Debe especificar un archivo de caracterizacion.\nUso: ./simutransusb -s <archivo> [-c <archivo>] [-t <num>]");
        exit(1);
    }*/
    Servicio *s = servicio_init();
    leer_caracterizacion_de_servicio("servicio2007.txt", s);

    return 0;
}
