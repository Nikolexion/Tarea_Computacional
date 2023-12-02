#include <stdio.h>
#include <stdbool.h>

void dijkstra();
void generarMatriz();

#define NUM_VERTICES 112



int main(){
    int** matrizAdyacencia;
    matrizAdyacencia = (int**)malloc(NUM_VERTICES * sizeof(int*));
    for(int i=0;i<NUM_VERTICES;i++){
        matrizAdyacencia[i]=(int*)malloc(NUM_VERTICES * sizeof(int));
    }
    generarMatriz(matrizAdyacencia);
    dijkstra(matrizAdyacencia,1,1);
}



void dijkstra(int matrizAdyacencia[112][112], int inicio, int final) {
    int matrizCaminos[112][2],revisados[112],infinito = 10000,verticeOrigen=inicio-1;
    bool verticesRevisados = false;

    //inicializar el array revisados con ceros
    for(int i=0;i<112;i++){
        revisados[i]=0;
    }

    //Inicializar la matrizCaminos con distancias infinitas y origen nulo
    for(int i=0;i<112;i++){
        matrizCaminos[i][0]=infinito;
        matrizCaminos[i][1]=-1;
    }
    matrizCaminos[inicio-1][0]=0;
    matrizCaminos[inicio-1][1]=inicio;
    
    //Realizo busqueda de los caminos mientras no se hayan revisado todos los vertices
    while(!verticesRevisados){
        int candidatoOrigen;
        int distanciaMinima=infinito;
        revisados[verticeOrigen]=1;
        verticesRevisados = true;
        for(int i=0;i<112;i++){
            //guardo la distancia desde el vertice origen al vertice i
            int distancia = matrizAdyacencia[verticeOrigen][i];
            //reviso si existe un camino de mi vertice origen al vertice i
            if(distancia!=0){
                //reviso si el camino desde el inicio hasta el vertice i, que pasa por mi vertice origen, tiene menor longitud que el camino anterior que llevaba al vertice i
                if(matrizCaminos[i][0]>matrizCaminos[verticeOrigen][0]+distancia){
                    matrizCaminos[i][0]=matrizCaminos[verticeOrigen][0]+distancia;
                    matrizCaminos[i][1]=verticeOrigen+1;
                    //obtengo el vertice con el camino mas corto que no se haya revisado
                    if(matrizCaminos[i][0]<distanciaMinima && revisados[i]==0){
                        distanciaMinima=matrizCaminos[i][0];
                        candidatoOrigen=i;
                    }
                }
            }
        }
        //Revisa si se revisaron todos los vertices
        for(int i=0;i<112;i++){
            if(revisados[i]==0){
                verticesRevisados=false;
            }
        }
        //declaro mi vertice origen como el vertice i tal que su camino tiene la menor distancia, y no ha sido revisado
        verticeOrigen=candidatoOrigen;

    }




    //mostrar matriz caminos
    for(int i=0; i<112; i++){
        printf("%d", matrizCaminos[i][0]);
        printf("\n");
    }
}



void generarMatriz(int** matriz){
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
}