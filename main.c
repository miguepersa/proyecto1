#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

/*#include "Parada.h"
#include "Autobus.h"*/
#include "Funciones.h"

extern char* optarg;

int main()
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

    /*Lista_Servicio* ls = lista_servicio_init();
    leer_caracterizacion_de_servicio("servicio2007.txt",ls);
    lista_servicio_destroy(ls);*/

    /*Aqui debemos colocar la cantidad de paradas que tomamos de los archivos de entrada*/
    /*4 debe reemplazarse por el numero de paradas*/
    int i;
    int fd_array[4][2];
    int pid;
    for(i=0; i<4;i++){
        pid = fork();
        if (pid == -1)
        {
            perror("Error en la creacion del hijo\n");
            exit(1);
        }


        if(pid != 0){
            if (pipe(fd_array[i]) != 0)
            {
                perror("Error en la creacion del pipe\n");
                exit(1);
            }
            int y;
            close(fd_array[i][1]);
            read(fd_array[i][0],&y,sizeof(int));
            close(fd_array[i][0]);
            printf("Este es un mensaje de mi hijo %d",y);


        
        }else{
            write(fd_array[i][1], &i ,sizeof(int));
            close(fd_array[i][1]);
            break;   
        }

    }

    /*Parada arreglo_paradas[MAX_PARADAS];
    int numero_paradas = leer_caracterizacion_carga("carga.csv", arreglo_paradas);
    parada_impresion(arreglo_paradas, numero_paradas);*/

    /*Servicio le pasa a Parada nbuses*/

    return 0;
}
