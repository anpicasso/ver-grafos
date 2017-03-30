#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#define INF 9999999
#define GRAPHSIZE 200
#define MAX(a, b) ((a > b) ? (a) : (b))

using namespace std;

long d[GRAPHSIZE]; /* d[i] is the length of the shortest path between the source (s) and node i */
int prev[GRAPHSIZE]; /* prev[i] is the node that comes right before i in the shortest path from the source to i*/

void djikestra(int dist[200][200], int dij[200][200], string nom[200],int inicio,int fin,int n) {
	int i, j;
	int u, v, w;
	

	int k, mini;
	int visited[GRAPHSIZE];

	for (i = 0; i <n; ++i) {
		d[i] = INF;
		prev[i] = -1; /* no path has yet been found to i */
		visited[i] = 0; /* the i-th element has not yet been visited */
	}

	d[inicio] = 0;

	for (k = 0; k <n; ++k) {
		mini = -1;
		for (i = 0; i <n; ++i)
			if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
				mini = i;

		visited[mini] = 1;

		for (i = 0; i < n; ++i)
			if (dist[mini][i])
				if (d[mini] + dist[mini][i] < d[i]) {
					d[i] = d[mini] + dist[mini][i];
					prev[i] = mini;
				}
	}
	
	if(d[fin]==9999999){
		cout<<"ERROR, no se puede ir del nodo "<<inicio<<" al nodo "<<fin<<endl;
	}
	i = 0;
	int path[200];
	path[i]=fin;
	int aux=fin;
	while(prev[fin]!=inicio){
			//cout<<prev[fin]<<" ";
			fin=prev[fin];
			path[i]=fin;
			i++;
	}
	path[i]=inicio;
	for(j=0;j<i;j++){
		dij[path[j+1]][path[j]]=dist[path[j+1]][path[j]];
	}
	dij[prev[aux]][aux]=dist[prev[aux]][aux];
	for(j=0;j<=i;j++){
		cout<<nom[path[i-j]]<<" ("<<d[path[i-j]]<<") "<<" -> ";
		if((j+1)%3==0) cout<<endl;
	}
	cout<<nom[aux]<<" ("<<d[aux]<<") "<<endl;
	cout<<endl;
	system("pause");
}
