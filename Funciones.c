#include "Funciones.h"

extern pthread_mutex_t lock;

void quitar_espacios(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
int leer_caracterizacion_carga(char* nombre_archivo, Parada lista_paradas[])
{
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return -1;
    }

    int num_paradas = 0;
    char linea[100];
    int index = 0;
    int j;

    while (fgets(linea,100,archivo)!=0) {

        if(index==0){
            index++;
            continue;
        }
        quitar_espacios(linea);
        Parada *p = parada_init();
        char *lin_sin_coma = strtok(linea, ",");
        num_paradas++;
        index = 0;
        while(lin_sin_coma != 0){

            switch(index){
                case 0:
                    int i;
                    for(i=0;i<3;i++){

                        p->codigo[i] = lin_sin_coma[i] ;

                    }
                    break;

                case 1:
                    for(i=0; i<strlen(lin_sin_coma);i++){

                        p->nombre[i] = lin_sin_coma[i];

                    }
                    break;

                case 2:
                    int hora = (lin_sin_coma[0] - '0');
                    char min[2] = {lin_sin_coma[2],lin_sin_coma[3]};
                    int minuto = atoi(min);
                    p->duracion_h = hora;
                    p->duracion_m = minuto;
                    break;

                case 3:
                    p->usuarios[0] = atoi(lin_sin_coma);
                    break;
                
                case 4:
                    p->usuarios[1] = atoi(lin_sin_coma);
                    break;

                case 5:
                    p->usuarios[2] = atoi(lin_sin_coma);
                    break;

                case 6:
                    p->usuarios[3] = atoi(lin_sin_coma);
                    break;

                case 7:
                    p->usuarios[4] = atoi(lin_sin_coma);
                    break;

                case 8:
                    p->usuarios[5] = atoi(lin_sin_coma);
                    break;

                case 9:
                    p->usuarios[6] = atoi(lin_sin_coma);
                    break;

                case 10:
                    p->usuarios[7] = atoi(lin_sin_coma);
                    break;

            }
            index++;
            lin_sin_coma = strtok(0,",");
        }
        lista_paradas[j] = *p;
        j++;
    
        if (num_paradas >= MAX_PARADAS) {
         printf("Demasiadas paradas en el archivo\n");
            break;
        }
    }


    fclose(archivo);
    return num_paradas;
}

void leer_caracterizacion_de_servicio(char* nombre_archivo, Lista_Servicio* ls){

    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombre_archivo);
        return;
    }

    char linea[320];
    
    while (fgets(linea,320,archivo)!=0) {
        Servicio* s = servicio_init();
        char *lin_sin_espacio = strtok(linea, " ");

        int i;
        for(i=0;i<3;i++){
            s->codigo[i] = lin_sin_espacio[i] ;
        }
        
        lin_sin_espacio = strtok(0," ");

        while(lin_sin_espacio != 0){
            char *actual = lin_sin_espacio;
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
            lin_sin_espacio = strtok(0," ");
        }
    lista_servicio_add(ls,s);
    }

    fclose(archivo);
    lista_servicio_print(ls);
}

float buscar_hora_inicio(Lista_Servicio* ls){

    int hora_minima = 12;
    int minuto_minimo = 59;
    float horario_minimo = -1.0;
    Servicio servicio_actual = ls->cabeza;

    while(servicio_actual->siguiente != NULL){

        Nodo horario_actual = servicio_actual->cabeza;

        if(horario_actual->hora < hora_minima){

            hora_minima = horario_actual->hora;
            minuto_minimo = horario_actual->minuto;

        }else if(horario_actual->hora == hora_minima){
            if(horario_actual->minuto< minuto_minimo){
                minuto_minimo = horario_actual->minuto;
            }
        }
    }

    if(ls->cola->hora < hora_minima){
        hora_minima = ls->cola->hora;
        minuto_minimo = ls->cola->minuto;

    }else if(ls->cola->hora == hora_minima){
        minuto_minimo = ls->cola->hora->minuto;

    }

    horario_minimo = minuto_minimo/100;
    horario_minimo = horario_minimo + hora_minima;

    return horario_minimo;

}
