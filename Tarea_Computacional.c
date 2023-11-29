#include <stdio.h>
#include <string.h>


int main() {
    char inputString[] = "Orompello 314 Chacabuco 201";

    // Variables para almacenar las palabras separadas
    char palabra1[50], palabra2[50], palabra3[50], palabra4[50];

    // Llamar a la función para separar las palabras
    separarPalabras(inputString, palabra1, palabra2, palabra3, palabra4);

    // Mostrar las palabras por separado
    //printf("Palabra 1: %s\n", palabra1);
    //printf("Palabra 2: %s\n", palabra2);
    //printf("Palabra 3: %s\n", palabra3);
    //printf("Palabra 4: %s\n", palabra4);

        const char* input = "Rengo";
        const char* input2 = "Los_Carrera";
    int numeroPalabra = obtenerCalleX(palabra1);
    //int numeroPalabra2 = obtenerCalleX(input2);
    if (numeroPalabra != -1)
    {
        printf("La palabra '%s' es horizontal y su nro es '%d'", palabra1,numeroPalabra);
    } else {
        numeroPalabra = obtenerCalleY(input);
        printf("La palabra '%s' es vertical y su nro es '%d'", palabra1,numeroPalabra);

    }
    

    /*if (numeroPalabra != -1) {
        printf("La palabra '%s' tiene el número: %d\n", input, numeroPalabra);
        printf("La palabra '%s' tiene el número: %d\n", input2, numeroPalabra2);
    } else {
        printf("La palabra '%s' no fue encontrada.\n", input);
    }*/

    return 0;
}



void separarPalabras(const char* inputString, char* palabra1, char* palabra2, char* palabra3, char* palabra4) {
    char copiaInput[100]; // Asumiendo un tamaño máximo para la cadena de entrada

    // Copiar la cadena de entrada para evitar modificar la original
    strcpy(copiaInput, inputString);

    char* token = strtok(copiaInput, " "); // Dividir la cadena en palabras usando el espacio como delimitador

    // Copiar cada palabra en las variables correspondientes
    strcpy(palabra1, token);
    token = strtok(NULL, " ");
    strcpy(palabra2, token);
    token = strtok(NULL, " ");
    strcpy(palabra3, token);
    token = strtok(NULL, " ");
    strcpy(palabra4, token);
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
