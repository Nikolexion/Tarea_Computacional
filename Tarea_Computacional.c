#include <stdio.h>
#include <string.h>

#define NUM_VERTICES 112
#define MAX_CALLE_LEN 50
#define FILENAME "nombreIntersecciones.txt"

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
    for (int i = 0; i < 6; i++)
    {
        printf("%s", mapaCalles[i].calle);
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

