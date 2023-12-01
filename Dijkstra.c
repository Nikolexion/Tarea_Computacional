#include <stdio.h>


void dijkstra(int matrizAdyacencia[112][112], int inicio, int final) {
    int distancias[112], anteriores[112], visto[112], camino[112], actual = inicio;

    for (int i = 0; i < 112; i++) {
        distancias[i] = 9999;           //Dejamos las distancias en un numero alto al inicio, ya que no tenemos un "infinito" 
        anteriores[i] = -1;             //Dejamos el vector de anteriores en -1 para mostrar que se aun no empieza 
        visto[i] = 0;               //Dejamos el vector en 0 ya que ningun vertice ha sido visitado
    }

    visto[actual] = 1;
    distancias[actual] = 0;

    while (!visto[final]) {
        int distanciaMinima = 9999;
        int vertice = 0;

        for (int i = 0; i < 112; i++) {
            int distancia = distancias[actual] + matrizAdyacencia[actual][i];
            if (distancia < distancias[i] && !visto[i]) {
                distancias[i] = distancia;
                anteriores[i] = actual;
            }
            if (distanciaMinima > distancias[i] && !visto[i]) {
                distanciaMinima = distancias[i];
                vertice = i;
            }
        }
      actual = vertice;
        visto[actual] = 1;
    }

    actual = final;

    int longitudCamino = 0;
    while (actual != inicio) {
        camino[longitudCamino++] = actual;
        actual = anteriores[actual];
    }
    camino[longitudCamino++] = actual;

    for (int i = 0; i < longitudCamino / 2; i++) {
        int aux = camino[i];
        camino[i] = camino[longitudCamino - i - 1];
        camino[longitudCamino - i - 1] = aux;
    }

    printf("Camino desde %d hasta %d: ", inicio, final);
    for (int i = 0; i < longitudCamino; i++) {
        if (i == longitudCamino - 1) {
            printf("%d\n", camino[i]);
        } else {
            printf("%d ", camino[i]);
        }
    }

    printf("Distancia desde %s hasta %s: %d\n", inicio, final, distancias[final]);
}