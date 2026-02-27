#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char dato[4];
    int vmenor;
    struct Nodo *siguiente;
} Nodo;

/* Crear nodo */
Nodo *crearNodo(char d[], int v) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error de memoria\n");
        exit(1);
    }
    strcpy(nuevo->dato, d);
    nuevo->vmenor = v;
    nuevo->siguiente = NULL;
    return nuevo;
}

/* Apilar */
Nodo *apilar(Nodo *cima, char d[], int v) {
    Nodo *nuevo = crearNodo(d, v);
    nuevo->siguiente = cima;
    return nuevo;
}

/* Desapilar */
Nodo *quitar(Nodo *cima) {
    if (cima == NULL)
        return NULL;

    Nodo *aux = cima;
    cima = cima->siguiente;
    free(aux);
    return cima;
}

/* Mostrar pila */
void verPila(Nodo *cima) {
    if (cima == NULL) {
        printf("Pila vacía\n");
        return;
    }

    while (cima != NULL) {
        printf("Dato: %s\t%d\n", cima->dato, cima->vmenor);
        cima = cima->siguiente;
    }
}

/* Invertir pila */
Nodo *invertirPila(Nodo *cima) {
    Nodo *nueva = NULL;
    while (cima != NULL) {
        nueva = apilar(nueva, cima->dato, cima->vmenor);
        cima = cima->siguiente;
    }
    return nueva;
}

#endif