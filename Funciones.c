#include "Funciones.h"


/*int leer_caracterizacion_carga(char* nombre_archivo, Parada lista_paradas[])
{
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return -1;
    }

    int num_paradas = 0;
    while (fscanf(archivo, "%[^,],%[^,],%[^,],%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                    lista_paradas[num_paradas].codigo,
                    lista_paradas[num_paradas].nombre,
                    lista_paradas[num_paradas].hora_llegada,
                    &lista_paradas[num_paradas].duracion_h,
                    &lista_paradas[num_paradas].duracion_m,
                    &lista_paradas[num_paradas].usuarios[0],
                    &lista_paradas[num_paradas].usuarios[1],
                    &lista_paradas[num_paradas].usuarios[2],
                    &lista_paradas[num_paradas].usuarios[3],
                    &lista_paradas[num_paradas].usuarios[4],
                    &lista_paradas[num_paradas].usuarios[5],
                    &lista_paradas[num_paradas].usuarios[6],
                    &lista_paradas[num_paradas].usuarios[7]) != 0) {
        num_paradas++;
        if (num_paradas >= MAX_PARADAS) {
            printf("Demasiadas paradas en el archivo\n");
            break;
        }
    }

    fclose(archivo);
    return num_paradas;
}*/

void leer_caracterizacion_de_servicio(char* nombre_archivo, Lista_Servicio* ls){

    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return;
    }

    char linea[320];
    
    while (fgets(linea,320,archivo)!=0) {
        Servicio* s = servicio_init();
        char *linsinespacio = strtok(linea, " ");

        int i;
        for(i=0;i<3;i++){
            s->codigo[i] = linsinespacio[i] ;
        }
        
        linsinespacio = strtok(0," ");

        while(linsinespacio != 0){
            char *actual = linsinespacio;
            char h1 = ' ';
            char h2 = ' ';
            int j = 0;
        
            while (actual[j] != '\0'){

                if(actual[j] != ':'){
                    if(h1 != ' '){
                        h2 = actual[j];
                    }else{
                        h1 = actual[j];
                    }
                    j++;
                }else{
                    int hora = 0;
                    if(h2 != ' '){
                        int hora1 = (h1-'0')*10;
                        int hora2 = (h2-'0');
                        hora = hora1 + hora2;

                    }else{
                        hora = (h1-'0');
                    }
                    h1 = ' ';
                    h2 = ' ';
                    j++;

                    int minuto = 0;
                    int minuto1 = (actual[j] -'0')*10;
                    int minuto2 = (actual[j+1] -'0');
                    minuto = minuto1 + minuto2;

                    j = j+3;

                    char capacidad[2];
                    capacidad[0] = actual[j];
                    capacidad[1] = actual[j+1];
                    fflush(stdout);
                    j = j+3;

                servicio_add(s,hora,minuto,atoi(capacidad));
                }
            }
            linsinespacio = strtok(0," ");
        }
    lista_servicio_add(ls,s);
    }

    fclose(archivo);
    lista_servicio_print(ls);
}