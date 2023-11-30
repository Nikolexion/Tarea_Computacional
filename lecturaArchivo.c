#include <stdio.h>
#include <stdlib.h>

#include "lecturaArchivo.h"

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