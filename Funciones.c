#include "Funciones.h"


/*int leer_caracterizacion_carga(char* nombre_archivo, Ruta lista_paradas[])
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

void leer_caracterizacion_de_servicio(char* nombre_archivo, Servicio* s){

    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return;
    }

    char linea[320];
    while (fgets(linea,320,archivo)!=0) {
        char *linsinespacio = strtok(linea, " ");
        int i ;
        for(i= 0;i<3;i++){
            s->codigo[i] = linsinespacio[i]  ;
        }

        char h1 = ' ';
        char h2 = ' ';
        int j = 3;
        while(j < 320){
            Nodo *n = nodo_init();
            if(linsinespacio[j] != ':'){
                if(h1 != ' '){
                    h2 = linsinespacio[j];
                }else{
                    h1 = linsinespacio[j];
                }
            }else{
                if(h2 != ' '){
                    int hora1 = (int)(h1)*10;
                    int hora2 = (int)(h2);
                    hora1 = hora1 + hora2;
                    n->hora = hora1;

                }else{
                    n->hora = (int)(h1);
                }
                h1 = ' ';
                h2 = ' ';

                char minuto[2];
                j = j + 1;
                minuto[0] = linsinespacio[j];
                minuto[1] = linsinespacio[j+1];
                n->minuto = atoi(minuto);

                j = j+3;

                char capacidad[2];
                capacidad[0] = linsinespacio[j];
                capacidad[1] = linsinespacio[j+1];
                n->capacidad = atoi(capacidad);

                j = j+3;

               servicio_add(s,n);
            }
        }

    }

    fclose(archivo);
}