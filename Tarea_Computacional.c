#include<stdio.h>

int Djikstra();

int main(){



    return 0;
}

int Djikstra(int inicio, int final, int mAdyacencia[][], int calles){
    int visitados[calles];          //Matriz que guarda los nodos ya visitados
    int distancia[calles];          //Matriz que guarda la distancia entre el nodo inicial y todos los demas
    int anterior[calles];           //
    for(int i = 0; i < calles; i++){
        visitados[i] = 0;           //iniciamos la matriz de visitados en 0(que seria false)
        distancia[i] = 99999;        //Como no tenemos un infinito, dejaremos la distancia default en un numero muy grande
    }
    
}


