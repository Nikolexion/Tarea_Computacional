#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dijkstra();
void generarMatriz();

#define NUM_VERTICES 112



int main(){
    int matrizAdyacencia[112][112];
    generarMatriz(matrizAdyacencia);
    dijkstra(matrizAdyacencia,1,58);
}


void dijkstra(int matrizAdyacencia[112][112],int inicio, int final) {
    //declaracion de variables
    int matrizCaminos[112][2],revisados[112],infinito = 10000,verticeOrigen=inicio-1, verticeOrigenFinal,verticesAnteriores[112],camino[112],
    caminoAux[112];
    bool verticesRevisados = false;

    //inicializar el array revisados con ceros
    for(int i=0;i<112;i++){
        revisados[i]=0;
    }
    //inicializar la matriz de vertices anteriores con vertices nulos
    for(int i=0;i<112;i++){
        verticesAnteriores[i]=-1;
    }

    //Inicializar la matrizCaminos con distancias infinitas y origen nulo
    for(int i=0;i<112;i++){
        matrizCaminos[i][0]=infinito;
        matrizCaminos[i][1]=-1;
    }
    matrizCaminos[verticeOrigen][0]=0;
    matrizCaminos[verticeOrigen][1]=inicio;
    
    //Realizo busqueda de los caminos mientras no se hayan revisado todos los vertices
    while(!verticesRevisados){
        //agrego a la lista de revisados a mi vertice origen
        revisados[verticeOrigen]=1;

        int distanciaMinima=infinito;
        verticesRevisados = true;
        bool verticesAdyacentesRevisados = true;
        for(int i=0;i<112;i++){
            //guardo la distancia desde el vertice origen al vertice i
            int distancia = matrizAdyacencia[verticeOrigen][i];
            //reviso si existe un camino de mi vertice origen al vertice i
            if(distancia!=0){
                //reviso si el camino desde el inicio hasta el vertice i, que pasa por mi vertice origen, tiene menor longitud que el camino anterior que llevaba al vertice i
                if(matrizCaminos[i][0]>matrizCaminos[verticeOrigen][0]+distancia){
                    matrizCaminos[i][0]=matrizCaminos[verticeOrigen][0]+distancia;
                    matrizCaminos[i][1]=verticeOrigen+1;
                    //corrige el camino mas corto para los vertices cercanos al vertice i
                    for(int j=0;j<112;j++){
                        if(matrizCaminos[j][1]==i+1){
                            matrizCaminos[j][0]=matrizCaminos[i][0]+matrizAdyacencia[i][j];
                        }
                    }
                }
                //obtengo el vertice con el camino mas corto y que no esté revisado y lo coloco como prioridad maxima, si existe declaro que hay adyacentes no revisados
                if(matrizCaminos[i][0]<distanciaMinima && revisados[i]!=1){
                    distanciaMinima=matrizCaminos[i][0];
                    verticeOrigenFinal=i;
                    verticesAdyacentesRevisados=false;
                }
            }
        }
        //si todos los vertices adyacentes estan revisados me devuelvo al vertice anterior
        if(verticesAdyacentesRevisados){
            int i=0;
            while(verticesAnteriores[i]!=-1){
            i++;
            }
            verticeOrigen=verticesAnteriores[i-1];
            verticesAnteriores[i-1]=-1;
        }
        
        //agregra el vertice origen a el arreglo de vertices anteriores si no se regreso a un vertice anterior y setea el siguiente vertice de origen
        if(!verticesAdyacentesRevisados){
            int i=0;
            while(verticesAnteriores[i]!=-1){
            i++;
        }
        verticesAnteriores[i]=verticeOrigen;
        verticeOrigen=verticeOrigenFinal;
        }

        //Revisa si se revisaron todos los vertices
        for(int i=0;i<112;i++){
            if(revisados[i]==0){
                verticesRevisados=false;
                break;
            }
        }
    }
    //obtener el camino mas corto desde el vertice final hasta el vertice inicial
    caminoAux[0]=final;
    int aux = matrizCaminos[final-1][1];
    int i=1;
    while(aux!=inicio){
        caminoAux[i]=aux;
        aux=matrizCaminos[aux-1][1];
        i++;
    }
    caminoAux[i]=inicio;
    int largoCamino=i+1;
    //obtener el camino mas corto desde el vertice inicial al vertice final

    for(;i>0;i--){
        camino[largoCamino-1-i]=aux;
        aux=caminoAux[i-1];
    }
    camino[largoCamino-1]=aux;

    //mostrar camino mas largo desde el vertice inicio hasta el vertice final
    for(int i=0; i<largoCamino; i++){
        printf("%d", camino[i]);
        if(i!=largoCamino-1){
            printf(" - ");
        }
    }
}



void generarMatriz(int matriz[112][112]){
    FILE *archivo;
    int numNodos = 112;

    archivo = fopen("C:/Users/Lenovo/Desktop/a/U/C/Clases/Clases profe vicente/Discretas/Tarea_Computacional/MatrizAdyacencia.txt","r");

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
}