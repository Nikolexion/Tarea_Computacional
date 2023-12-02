#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lecturaArchivo.h"
#include "Dijkstra.h"

#define NUM_VERTICES 112
#define MAX_CALLE_LEN 50
#define FILENAME "C:/Users/Lenovo/Desktop/a/U/C/Clases/Clases profe vicente/Discretas/Tarea_Computacional/nombreIntersecciones.txt"
//#define FILENAME "nombreIntersecciones.txt"

void leerVerticesDesdeArchivo(const char *filename);
char* nombreVertice(int vertice);
int obtenerCalle(const char* palabra, int *vertical);
int matrizGrafo[8][14] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14},{15,16,17,18,19,20,21,22,23,24,25,26,27,28},{29,30,31,32,33,34,35,36,37,38,39,40,41,42},
                          {42,43,44,45,46,47,48,49,50,51,52,53,54,55,56},{57,58,59,60,61,62,63,64,65,66,67,68,69,70},{71,72,73,74,75,76,77,78,79,80,81,82,83,84},
                          {85,86,87,88,89,90,91,92,93,94,95,96,97,98},{99,100,101,102,103,104,105,106,107,108,109,110,111,112}};

typedef struct {
    int vertice;
    char calle[MAX_CALLE_LEN];
} Nodo;

Nodo mapaCalles[NUM_VERTICES];

// Estructura para almacenar la correspondencia entre vértices y calles


int main() {
    char input[50];
    fgets(input, sizeof(input), stdin);                    //Guarda el input en la string llamada input
    size_t length = strlen(input);                      // Elimina el carácter de nueva línea ('\n') al final, si está presente
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    leerVerticesDesdeArchivo(FILENAME); 
    int matrizAdyacencia[NUM_VERTICES][NUM_VERTICES];
    generarMatriz(matrizAdyacencia);
    int nroPalabras = contarPalabras(&input);
    char calle1[MAX_CALLE_LEN], numero1[MAX_CALLE_LEN], calle2[MAX_CALLE_LEN], numero2[MAX_CALLE_LEN], calle3[MAX_CALLE_LEN], numero3[MAX_CALLE_LEN];
    if (nroPalabras = 4)
    {
        separarPalabras(input, calle1, numero1, calle2, numero2);      //Se separa el input en la direccion de partida, su numero
                                                                             //Y la direccion de llegada y su numero
        int nroCalle1, nroCalle2,vertical1, vertical2, inicio, final;
        nroCalle1 = obtenerCalle(calle1,vertical1);
        nroCalle2 = obtenerCalle(calle2,vertical2);
        if (vertical1 = 0)
        {
            inicio = matrizGrafo[numeroACalle(numero1,vertical1)][nroCalle1];
            if (vertical2 = 0)
            {
                final = matrizGrafo[numeroACalle(numero2,vertical2)][nroCalle2];
            } else{
                final = matrizGrafo[nroCalle2][numeroACalle(numero2,vertical2)];
            }
        } else{
            inicio = matrizGrafo[nroCalle1][numeroACalle(numero1,vertical1)];
            if (vertical2 = 1)
            {
                final = matrizGrafo[nroCalle2][numeroACalle(numero2,vertical2)];
            } else{
                final = matrizGrafo[numeroACalle(numero2,vertical2)][nroCalle2];
            }
            
        }
        printf("inicio: %d, final: %d",inicio,final);
        

        
        dijkstra(matrizAdyacencia,inicio, final);
    } else if (nroPalabras = 6){
        separar6Palabras(input,calle1,numero1,calle2,numero2,calle3,numero3);

    } else{
        printf("Numero de palabras no coincide con el formato");
    }
    
    return 0;
}


int contarPalabras(const char *cadena) {
    int contador = 0;
    int enPalabra = 0; // Bandera para indicar si estamos dentro de una palabra

    // Iterar a través de la cadena
    while (*cadena) {
        // Si el caracter actual es un espacio en blanco o un carácter de nueva linea, marca el final de una palabra
        if (*cadena == ' ' || *cadena == '\n' || *cadena == '\t') {
            enPalabra = 0;
        }
        // Si el caracter actual no es un espacio en blanco y estamos fuera de una palabra, el contador aumenta 1
        else if (!enPalabra) {
            enPalabra = 1;
            contador++;
        }

        cadena++; // Avanzar al siguiente carácter
    }

    return contador;
}

void separarPalabras(const char* inputString, char* calle1, char* numero1, char* calle2, char* numero2) {
    char copiaInput[100]; // Asumiendo un tamaño máximo para la cadena de entrada

    // Copiar la cadena de entrada para evitar modificar la original
    strcpy(copiaInput, inputString);

    char* token = strtok(copiaInput, " "); // Dividir la cadena en palabras usando el espacio como delimitador

    // Copiar cada palabra en las variables correspondientes
    strcpy(calle1, token);
    token = strtok(NULL, " ");
    strcpy(numero1, token);
    token = strtok(NULL, " ");
    strcpy(calle2, token);
    token = strtok(NULL, " ");
    strcpy(numero2, token);
}

void separar6Palabras(const char* inputString, char* calle1, char* numero1, char* calle2, char* numero2, char* calle3, char* numero3) {
    char copiaInput[100]; // Asumiendo un tamaño máximo para la cadena de entrada

    // Copiar la cadena de entrada para evitar modificar la original
    strcpy(copiaInput, inputString);

    char* token = strtok(copiaInput, " "); // Dividir la cadena en palabras usando el espacio como delimitador

    // Copiar cada palabra en las variables correspondientes
    strcpy(calle1, token);
    token = strtok(NULL, " ");
    strcpy(numero1, token);
    token = strtok(NULL, " ");
    strcpy(calle2, token);
    token = strtok(NULL, " ");
    strcpy(numero2, token);
    token = strtok(NULL, " ");
    strcpy(calle3, token);
    token = strtok(NULL, " ");
    strcpy(numero3, token);
}


int obtenerCalle(const char* palabra, int *vertical){
    if (obtenerCalleX(palabra) != -1){
        vertical = 1;
        return obtenerCalleX(palabra);
    } else{
        vertical = 0;
        return obtenerCalleY(palabra);
    }
}

int obtenerCalleX(const char* palabra) {
    // Array de palabras
    const char* palabras[] = {
        "Chacabuco", "Cochrane", "San_Martin", "OHiggins", "Barros_Arana", "Freire", "Maipu",
    "Los_Carrera"
    };

    // Iterar sobre el array de palabras
    for (int i = 0; i < sizeof(palabras) / sizeof(palabras[0]); ++i) {
        // Comparar la entrada con cada palabra
        if (strcmp(palabra, palabras[i]) == 0) {
            return i;  // Devolver el índice si hay una coincidencia
        }
    }

    // Si no se encuentra la palabra, devolver -1 o algún valor que indique que no se encontró
    return -1;
}
int numeroACalle(const char* nroCalle, int vertical){
    int calle = atoi(nroCalle);
    if (vertical = 0)
    {
        if (calle < 100){
            return 0;
    } else if (calle < 200){
        return 1;
    } else if (calle < 300){
        return 2;
    } else if (calle < 400){
        return 3;
    } else if (calle < 500){
        return 4;
    } else if (calle < 600){
        return 5;
    } else if (calle < 700){
        return 6;
    } else if (calle < 800){
        return 7;
    } else if (calle < 900){
        return 8;
    } else if (calle < 1000){
        return 9;
    } else if (calle < 1100){
        return 10;
    } else if (calle < 1200){
        return 11;
    } else if (calle < 1300){
        return 12;
    } else if (calle < 1400){
        return 13;
    } else {
        return -1;
    }
    } else if (vertical = 1) {
        if (calle < 100){
            return 7;
    } else if (calle < 200){
        return 6;
    } else if (calle < 300){
        return 5;
    } else if (calle < 400){
        return 4;
    } else if (calle < 500){
        return 3;
    } else if (calle < 600){
        return 2;
    } else if (calle < 700){
        return 1;
    } else if (calle < 800){
        return 0;
    } else {
        return -1;
    }
    } else {
        return -1;
    }
}

int obtenerCalleY(const char* palabra) {
    // Array de palabras
    const char* palabras[] = {
        "Arturo_Prat", "Serrano", "Salas", "Angol", "Lincoyán",
        "Rengo", "Caupolicán", "Aníbal_Pinto", "Colo_Colo", "Castellón",
        "Tucapel", "Orompello", "Ongolmo", "Paicaví", "Pedro_Aguirre_Cerda"
    };

    // Iterar sobre el array de palabras
    for (int i = 0; i < sizeof(palabras) / sizeof(palabras[0]); ++i) {
        // Comparar la entrada con cada palabra
        if (strcmp(palabra, palabras[i]) == 0) {
            return i;  // Devolver el índice si hay una coincidencia
        }
    }

    // Si no se encuentra la palabra, devolver -1 o algún valor que indique que no se encontró
    return -1;
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

    archivo = fopen("C:/Users/Lenovo/Desktop/a/U/C/Clases/Clases profe vicente/Discretas/Tarea_Computacional/MatrizAdyacencia.txt","r");
    //archivo = fopen("MatrizAdyacencia.txt","r");

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
            //printf("%d", matriz[i][j]);
        }
        //printf("\n");
    }
}
void dijkstra(int matrizAdyacencia[112][112], int inicio, int final) {
    int distancias[112], anteriores[112], visto[112], camino[112], actual = inicio;

    for (int i = 0; i < 112; i++) {
        distancias[i] = 9999;  // Dejamos las distancias en un número alto al inicio, ya que no tenemos un "infinito"
        anteriores[i] = -1;    // Dejamos el vector de anteriores en -1 para mostrar que aún no ha comenzado
        visto[i] = 0;          // Dejamos el vector en 0 ya que ningún vértice ha sido visitado
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

    // Reconstruir el camino
    actual = final;
    int longitudCamino = 0;
    while (actual != -1) {
        camino[longitudCamino++] = actual;
        actual = anteriores[actual];
    }

    // Imprimir la ruta en formato de lista de intersecciones
    printf("Ruta desde %s hasta %s:\n", nombreVertice(inicio), nombreVertice(final));
    printf("Intersecciones: ");
    for (int i = longitudCamino - 1; i >= 0; i--) {
        printf("%s", nombreVertice(camino[i]));
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf("\nDistancias: ");
    for (int i = longitudCamino - 1; i > 0; i--) {
        printf("%d m, ", matrizAdyacencia[camino[i]][camino[i - 1]]);
    }
    printf("%d m\n", distancias[final]);
}

