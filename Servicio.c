#include Servicio.h

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

void servicio_add(Servicio* s, Nodo* n){
    Nodo cola = s-> cola;
    cola->siguiente = n;
    s-> cola = n;
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
           printf("No existe el nodo");
        }

    }

};
