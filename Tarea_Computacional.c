#include <stdio.h>
#include <string.h>

#define NUM_VERTICES 112
#define MAX_CALLE_LEN 50
#define FILENAME "C:/Users/Lenovo/Desktop/a/U/C/Clases/Clases profe vicente/Discretas/Tarea_Computacional/nombreIntersecciones.txt"

// Definición de la matriz de adyacencia
int matrizAdyacencia[NUM_VERTICES][NUM_VERTICES];

typedef struct {
    int vertice;
    char calle[MAX_CALLE_LEN];
} Nodo;

Nodo mapaCalles[NUM_VERTICES];

// Estructura para almacenar la correspondencia entre vértices y calles


int main() {
    char inputString[] = "Orompello 314 Chacabuco 201";

    // Variables para almacenar las palabras separadas
    char calle1[50], numero1[50], calle2[50], numero2[50];

    // Llamar a la función para separar las palabras
    //separarPalabras(inputString, calle1, numero1, calle2, numero2);

    // Mostrar las palabras por separado
    //printf("Palabra 1: %s\n", calle1);
    //printf("Palabra 2: %s\n", numero1);
    //printf("Palabra 3: %s\n", calle1);
    //printf("Palabra 4: %s\n", numero2);

    //const char* input = "Rengo";
    //const char* input2 = "Los_Carrera";

    //char* numeroPalabra = obtenerCalleX(calle1);
    //char* numeroPalabra2 = obtenerCalleX(input2);
    leerVerticesDesdeArchivo(FILENAME);
    for (int i = 0; i < sizeof(mapaCalles->calle); i++)
    {
        printf("%s %d ", mapaCalles[i].calle, mapaCalles[i].vertice);
    }
    
//    if (numeroPalabra != -1)
//    {
//        printf("La calle '%s' es horizontal y su nro es '%d'", calle1,numeroPalabra);
//    } else {
//        numeroPalabra = obtenerCalleY(calle1);
//        printf("La calle '%s' es vertical y su nro es '%d'", calle1,numeroPalabra);
//
//    }
    

    /*if (numeroPalabra != -1) {
        printf("La palabra '%s' tiene el número: %d\n", input, numeroPalabra);
        printf("La palabra '%s' tiene el número: %d\n", input2, numeroPalabra2);
    } else {
        printf("La palabra '%s' no fue encontrada.\n", input);
    }*/

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

