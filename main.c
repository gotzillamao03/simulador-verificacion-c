#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

int obtenerLineaPorPlaca(const char* placa) {
    int len = strlen(placa);
    if (len == 0) return -1;

    char ultima = placa[len - 1];

    switch (ultima) {
        case '0': case '1': return 1;
        case '2': case '3': return 2;
        case '4': case '5': return 3;
        case '6': case '7': return 4;
        case '8': case '9': return 5;
        default: return -1;
    }
}

int main() {
    Cola unifila, linea1, linea2, linea3, linea4, linea5;

    inicializarCola(&unifila);
    inicializarCola(&linea1);
    inicializarCola(&linea2);
    inicializarCola(&linea3);
    inicializarCola(&linea4);
    inicializarCola(&linea5);

    srand(time(NULL));

    int opc;
    char placa[10];

    do {
        printf("\n1. Agregar auto\n");
        printf("2. Pasar auto a línea\n");
        printf("3. Atender línea aleatoria\n");
        printf("4. Mostrar colas\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opc);

        switch (opc) {

        case 1:
            printf("Ingrese placa: ");
            scanf("%9s", placa);
            encolar(&unifila, placa);
            break;

        case 2: {
            Auto* autoProcesado = desencolar(&unifila);
            if (autoProcesado == NULL) {
                printf("Unifila vacía\n");
            } else {
                int linea = obtenerLineaPorPlaca(autoProcesado->placa);

                switch (linea) {
                    case 1: encolar(&linea1, autoProcesado->placa); break;
                    case 2: encolar(&linea2, autoProcesado->placa); break;
                    case 3: encolar(&linea3, autoProcesado->placa); break;
                    case 4: encolar(&linea4, autoProcesado->placa); break;
                    case 5: encolar(&linea5, autoProcesado->placa); break;
                    default: printf("Placa inválida\n");
                }

                free(autoProcesado);
            }
            break;
        }

        case 3: {
            int linea = (rand() % 5) + 1;
            Cola* objetivo;

            switch (linea) {
                case 1: objetivo = &linea1; break;
                case 2: objetivo = &linea2; break;
                case 3: objetivo = &linea3; break;
                case 4: objetivo = &linea4; break;
                case 5: objetivo = &linea5; break;
            }

            Auto* atendido = desencolar(objetivo);

            if (atendido == NULL)
                printf("Línea %d vacía\n", linea);
            else {
                printf("Atendiendo %s en línea %d\n", atendido->placa, linea);
                free(atendido);
            }

            break;
        }

        case 4:
            mostrarCola(&unifila, "Unifila");
            mostrarCola(&linea1, "Línea 1");
            mostrarCola(&linea2, "Línea 2");
            mostrarCola(&linea3, "Línea 3");
            mostrarCola(&linea4, "Línea 4");
            mostrarCola(&linea5, "Línea 5");
            break;

        case 0:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción inválida\n");
        }

    } while (opc != 0);

    return 0;
}