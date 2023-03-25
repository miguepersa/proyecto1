#include "Servicio.h"

Nodo *nodo_init()
{
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    if (!n)
    {
        perror(strerror(errno));
        return NULL;
    }

    n->minuto = 0;
    n->hora = 0;
    n->capacidad = 0;
    n->siguiente = NULL;

    return n;
}

void nodo_destroy(Nodo *n)
{

    free(n);
    
}

Servicio *servicio_init()
{
    Servicio *s = (Servicio*) malloc(sizeof(Servicio));
    if (!s)
    {
        perror(strerror(errno));
        return NULL;
    }
    s->cabeza = NULL;
    s->cola = NULL;
    s->siguiente = NULL;

    return s;
}

void servicio_destroy(Servicio*s)
{
    Nodo *nodoactual = s->cabeza;

    while(nodoactual->siguiente != NULL){
        Nodo *nodoviejo = nodoactual;
        nodoactual = nodoactual->siguiente;
        nodo_destroy(nodoviejo);
    }

    nodo_destroy(nodoactual);
}

void servicio_add(Servicio* s, int hora,int minuto ,int capacidad){

    Nodo *n = nodo_init();
    n->hora = hora;
    n->minuto = minuto;
    n->capacidad = capacidad;

    if(s->cabeza == NULL){
        s->cabeza = n;
        s->cola = n;
    }else{
        Nodo *cola = s->cola;
        cola->siguiente = n;
        s->cola = n;
    }
    s->nbuses = s->nbuses + 1;
}

void servicio_delete(Servicio* s, Nodo* n){

    Nodo *nodoactual = s-> cabeza;

    if(nodoactual == n){
        Nodo *nuevacabeza = nodoactual->siguiente;
        s->cabeza = nuevacabeza;
        nodo_destroy(nodoactual);

    }else{
        Nodo *nodoanterior = nodoactual;
        nodoactual = nodoactual->siguiente;

        while(nodoactual->siguiente != NULL){
            if(nodoactual == n){
                nodoanterior->siguiente = nodoactual->siguiente;
                nodo_destroy(nodoactual);
                break;
            }

            nodoanterior = nodoactual;
            nodoactual = nodoactual->siguiente;

        }
        if(nodoactual == n){
            nodoanterior->siguiente = nodoactual->siguiente;
            nodo_destroy(nodoactual);
        }else{
           printf("No existe el nodo\n");
        }

    }

}

Lista_Servicio *lista_servicio_init(){
    Lista_Servicio *ls = (Lista_Servicio*) malloc(sizeof(Lista_Servicio));
    if (!ls)
    {
        perror(strerror(errno));
        return NULL;
    }
    ls->cabeza = NULL;
    ls->cola = NULL;

    return ls;   

}


void lista_servicio_destroy(Lista_Servicio* ls){
    Servicio *servicioactual = ls->cabeza;

    while(servicioactual->siguiente != NULL){
        Servicio *servicioviejo = servicioactual;
        servicioactual = servicioactual->siguiente;
        servicio_destroy(servicioviejo);
    }

    servicio_destroy(servicioactual);

}

void lista_servicio_add(Lista_Servicio* ls, Servicio* s){

    if(ls->cabeza == NULL){
        ls->cabeza = s;
        ls->cola = s;
    }else{
        Servicio *cola = ls->cola;
        cola->siguiente = s;
        ls->cola = s;
    }
    ls->cantidad = ls->cantidad + 1;

}

void lista_servicio_print(Lista_Servicio* ls){

    printf("Cantidad de servicios = %d\n", ls->cantidad);
    Servicio* servicioactual = ls->cabeza;
    while(servicioactual->siguiente != NULL){
        printf("----------Servicio de %s:----------\n",servicioactual->codigo);
        Nodo* nodoactual = servicioactual->cabeza;
        while(nodoactual->siguiente!= NULL){
            printf("Horario: %d:%d | Capacidad: %d\n", nodoactual->hora,nodoactual->minuto,nodoactual->capacidad);
            nodoactual = nodoactual->siguiente;
        }
        printf("Horario: %d:%d | Capacidad: %d\n", servicioactual->cola->hora,servicioactual->cola->minuto,servicioactual->cola->capacidad);
        servicioactual = servicioactual->siguiente;
        printf("\n");
    }

    printf("----------Servicio de: %s----------\n",ls->cola->codigo);

    Nodo* nodofinal = ls->cola->cabeza;
    while(nodofinal->siguiente!=NULL){
        printf("Horario: %d:%d | Capacidad: %d\n", nodofinal->hora,nodofinal->minuto,nodofinal->capacidad);
        nodofinal = nodofinal->siguiente;       
    }
    printf("Horario: %d:%d | Capacidad: %d\n", ls->cola->cola->hora,ls->cola->cola->minuto,ls->cola->cola->capacidad);
    printf("------------------------------------\n");

}

int lista_servicio_buscar_nbuses(lista_servicio* ls, char codigo[]){
    servicio_actual = ls->cabeza;

    while(servicio_actual->siguiente!=NULL){

        if(servicio_actual->codigo == codigo){
            int nbus = servicio_actual->nbuses;
            return nbus;
        }
        servicio_actual = servicio_actual->siguiente;
    }

    if(ls->cola->codigo==codigo){
        int nbus = servicio_actual->nbuses;
        return nbus;
    }
    return -1;
}

Servicio* lista_servicio_buscar_nbuses(lista_servicio* ls, char codigo[]){
    servicio_actual = ls->cabeza;

    while(servicio_actual->siguiente!=NULL){

        if(servicio_actual->codigo == codigo){
           
            return servicio_actual;
        }
        servicio_actual = servicio_actual->siguiente;
    }

    if(ls->cola->codigo==codigo){
        
        return servicio_actual;
    }
    return NULL;
}

