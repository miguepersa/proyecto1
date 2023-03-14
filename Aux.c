#include "Aux.h"


int leer_c_carga(char* nombre_archivo, Ruta lista_paradas[])
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
}

