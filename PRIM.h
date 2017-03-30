#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <windows.h>
#include <graphics.h>
#include <cmath>
#include <string>
#include "menu.h"
// Numero de vértices


using namespace std;


void PRIM(int graph[200][200],int V)
{
    // Imprimir
    //primMST(graph);
    int horizontal,vertical;
    
    GetDesktopResolution(horizontal,vertical);
    //cout<<horizontal<<" "<<vertical<<endl;
    
    int MatrizPRIM[200][200]={};
    //CONSTRUIR MATRIZ
    int padre[V]; // Arreglo para guarda el árbol
    int llave[V];   // pesos para elegir el menor
    bool mstSet[V];  // arreglo con vértices que aún no se incluyen
 
      // Initialize all llaves as INFINITE
    for (int i = 0; i < V; i++){
		llave[i] = INT_MAX, mstSet[i] = false;
	}
        
 
    llave[0] = 0;     // Hacemos que llave sea 0 para que el primero siempre sea tomado.
    padre[0] = -1; // First node is always root of MST 
 
    // el árbol tendrá V vértices
    for (int count = 0; count < V-1; count++){
        // elegir el menor valor de llave que aun no estan en el árbol 
        // Agregar al árbol
        
        int min = INT_MAX, min_ind;
 
  		 for (int v = 0; v < V; v++){
    		if (mstSet[v] == false && llave[v] < min){
        		min = llave[v], min_ind = v;
			}
 		}
   		int u = min_ind;
 		mstSet[u] = true;
        // Actualizar
        for (int v = 0; v < V; v++){
        	if (graph[u][v] && mstSet[v] == false && graph[u][v] <  llave[v])
            padre[v]  = u, llave[v] = graph[u][v];
		}
    }
     // Imprimir
     system("cls");
    gotoxy(4,2);
    cout<<"Arista"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    gotoxy(40,2);
    cout<<" | Pesos"<<endl;
    //printf("Arista   Pesos\n");
	for (int i = 1; i < V; i++){
		gotoxy(4,i+3);
		cout<<nom[padre[i]]<<" - "<<nom[i]<<endl;
		gotoxy(40,i+3);
		cout<<" | "<<graph[i][padre[i]]<<endl;
		//printf("%d - %d    %d \n", padre[i], i, graph[i][padre[i]]);
		MatrizPRIM[padre[i]][i]=graph[i][padre[i]];
		MatrizPRIM[i][padre[i]]=graph[i][padre[i]];
	}
	cout<<endl;
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			graph[i][j]=MatrizPRIM[i][j];
		}
	}
}
