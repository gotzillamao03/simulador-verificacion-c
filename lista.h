#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Auto {
    char placa[10];
    struct Auto* sig;
} Auto;

typedef struct {
    Auto* frente;
    Auto* final;
} Cola;

/* Inicializar */
void inicializarCola(Cola* c) {
    c->frente = NULL;
    c->final = NULL;
}

/* Encolar */
void encolar(Cola* c, const char* placa) {
    Auto* nuevo = (Auto*)malloc(sizeof(Auto));
    if (nuevo == NULL) {
        printf("Error de memoria\n");
        exit(1);
    }

    strcpy(nuevo->placa, placa);
    nuevo->sig = NULL;

    if (c->final == NULL) {
        c->frente = c->final = nuevo;
    } else {
        c->final->sig = nuevo;
        c->final = nuevo;
    }
}

/* Desencolar */
Auto* desencolar(Cola* c) {
    if (c->frente == NULL)
        return NULL;

    Auto* temp = c->frente;
    c->frente = c->frente->sig;

    if (c->frente == NULL)
        c->final = NULL;

    return temp;
}

/* Mostrar */
void mostrarCola(Cola* c, const char* nombre) {
    printf("\nContenido de %s:\n", nombre);

    Auto* aux = c->frente;
    while (aux != NULL) {
        printf("Placa: %s\n", aux->placa);
        aux = aux->sig;
    }

    printf("-------------------\n");
}

#endif