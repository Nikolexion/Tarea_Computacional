#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lecturaArchivo.h"
#include "Dijkstra.h"

#define NUM_VERTICES 112
#define MAX_CALLE_LEN 50
#define FILENAME "C:/Users/rica1/OneDrive/Escritorio/TareaDiscretas/Tarea_Computacional/nombreIntersecciones.txt"

void leerVerticesDesdeArchivo(const char *filename);
char* nombreVertice(int vertice);

// Definición de la matriz de adyacencia
int** matrizAdyacencia;

typedef struct {
    int vertice;
    char calle[MAX_CALLE_LEN];
} Nodo;

Nodo mapaCalles[NUM_VERTICES];

// Estructura para almacenar la correspondencia entre vértices y calles


int main() {
    leerVerticesDesdeArchivo(FILENAME);
    
    int matrizAdyacencia[112][112];
    //matrizAdyacencia = (int**)malloc(NUM_VERTICES * sizeof(int*));
    //for(int i=0;i<NUM_VERTICES;i++){
    //    matrizAdyacencia[i]=(int*)malloc(NUM_VERTICES * sizeof(int));
    //}
    generarMatriz(matrizAdyacencia);

    dijkstra(matrizAdyacencia,1,28);
    return 0;
}


// Función para convertir un vértice a una calle
char* nombreVertice(int vertice) {
    leerVerticesDesdeArchivo(FILENAME);
    // Busca el vértice en el mapa
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (mapaCalles[i].vertice == vertice) {
            return mapaCalles[i].calle;
        }
    }

    // Si el vértice no está en el mapa, devuelve una cadena vacía
    return "";
}

// Función para leer los vértices desde un archivo
void leerVerticesDesdeArchivo(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Lee cada vértice y asigna nombres de calles
    for (int i = 0; i < NUM_VERTICES; i++) {
        fscanf(file, "%d %s", &mapaCalles[i].vertice, mapaCalles[i].calle);
    }

    fclose(file);
}
void generarMatriz(int matriz[112][112]){
    FILE *archivo;
    int numNodos = 112;

    archivo = fopen("/Users/rica1/OneDrive/Escritorio/TareaDiscretas/Tarea_Computacional/MatrizAdyacencia.txt","r");

    if(archivo == NULL){
        perror("Error al abrir el archivo");
        return;
    }

    for(int i=0; i<numNodos; i++){
        for(int j=0; j<numNodos; j++){
            fscanf(archivo, "%d", &matriz[i][j]);
        }
    }
    fclose(archivo);

    for(int i=0; i<numNodos; i++){
        for(int j=0; j<numNodos; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}
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

    printf("Distancia desde %d hasta %d: %d\n", inicio, final, distancias[final]);
}