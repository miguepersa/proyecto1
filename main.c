#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>

/*#include "Parada.h"
#include "Autobus.h"*/
#include "Funciones.h"
int horario_llegada[8] = {6,7,8,9,10,11,12,13};
extern char* optarg;
float hora_inicial;

int tic_toc(){
    int ms = 0;
    int frame = 10;
    clock_t antes = clock();

    do {
        sleep(10);

        clock_t diferencia = clock() - antes;
        ms = diferencia * 1000 / CLOCKS_PER_SEC;

    }while ( ms < frame );

    return ms;
}


int main(int argc, char *argv[])
{
    int opt;
    char *a_serv = NULL;
    char *a_carg = NULL;

    float dtiempo = 0.25;

    /* Parsing de argumentos del programa */
    while ((opt = getopt(argc, argv, "s:c:t:")) != -1)
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
            dtiempo = atof(optarg);
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
    }

    Lista_Servicio* ls = lista_servicio_init();
    leer_caracterizacion_de_servicio("servicio2007.txt",ls);

    Parada * arreglo_paradas = malloc((MAX_PARADAS+1) * sizeof(Parada));
    int numero_paradas = leer_caracterizacion_carga("carga.csv", arreglo_paradas);
    
    int j;
    for(j = 0; j< numero_paradas; j++){

        char* codigo_actual = arreglo_paradas[j].codigo;
        arreglo_paradas[j].nbuses = lista_servicio_buscar_nbuses(ls, codigo_actual);
          
    }

    hora_inicial = buscar_hora_inicio(ls);

    int i;
    int fd_array[numero_paradas][2];
    int pid;
    int indice_parada;
    for(i=0; i<numero_paradas;i++){
        
        if (pipe(fd_array[i]) != 0){

            perror("Error en la creacion del pipe\n");
            exit(1);
        }

        pid = fork();
        if (pid == -1)
        {
            perror("Error en la creacion del hijo\n");
            exit(1);
        }

        if(pid != 0){

            
            close(fd_array[i][1]);
            read(fd_array[i][0],&i,sizeof(int));
            close(fd_array[i][0]);
        
        }else{
            indice_parada = i;
            close(fd_array[i][0]);
            write(fd_array[i][1], &i ,sizeof(int));
            close(fd_array[i][1]);
            break;   
        }

    }

    if(pid == 0){

        Servicio* s = lista_servicio_buscar_servicio(ls,arreglo_paradas[indice_parada].codigo);

        float hora_actual = hora_inicial;
        int dt = 0;
        float siguiente_autobus_h = (s->cabeza->minuto/100) + (s->cabeza->hora);
        int capacidad_bus = s->cabeza->capacidad;

        pthread_t* bus_actual;
   
        while(0){
            if(hora_actual==siguiente_autobus_h){
                Autobus* bus = autobus_init();
                bus->capacidad = capacidad_bus;
                bus_actual = parada_crear_buses(&arreglo_paradas[indice_parada], bus);
            }

            dt =  dt + tic_toc();
            if(dt >= 250){
                hora_actual = hora_actual + 0.01;
                dt = 0;
            }
        }

    }else if(pid > 0){
        sleep(1000);
    }


    return 0;
}
