#include <stdio.h>
#include <string.h>

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