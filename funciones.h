#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstring>
#include <dirent.h>
#include <stdio.h>
#include <map>
#include <sstream>
#define linea "_______________________________________________________________"



//Emulador de gotoxy
using namespace std; 
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   const HWND hDesktop = GetDesktopWindow();
   GetWindowRect(hDesktop, &desktop);
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

void gotoxy(int x, int y) 
{ 
COORD coord; 
coord.X=x; 
coord.Y=y; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void MenuPresentacion(){
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	Sleep(100);
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
		Sleep(30);
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	Sleep(30);
	gotoxy(16,9);cout<<linea;
	
	string s[8];
	s[0] = " UNIVERSIDAD NACIONAL DE INGENIERIA ";
	s[1] = " Facultad de Ingenieria Industrial y de Sistemas ";
	s[2] = "Profesor: Roy Palacios Rezza";
	s[3] = "Integrantes:";
	s[4] = " - Jesus Aguilar Apaza";
	s[5] = " - Angello Picasso Ramirez";
	s[6] = " - Jorge Vasquez";
	s[7] = " - Diego Ucharima Ortiz";
	
	for(int i=0;i<s[0].size();i++){
		gotoxy(30+i,7);cout<<s[0][i];
		Sleep(30);
	}
	for(int i=0;i<s[1].size();i++){
		gotoxy(23+i,8);cout<<s[1][i];
		Sleep(30);
	}
	for(int i=0;i<s[2].size();i++){
		gotoxy(23+i,11);cout<<s[2][i];
		Sleep(30);
	}
	for(int i=0;i<s[3].size();i++){
		gotoxy(23+i,13);cout<<s[3][i];
		Sleep(30);
	}
	for(int i=0;i<s[4].size();i++){
		gotoxy(35+i,14);cout<<s[4][i];
		Sleep(30);
	}
	for(int i=0;i<s[5].size();i++){
		gotoxy(35+i,16);cout<<s[5][i];
		Sleep(30);
	}
	for(int i=0;i<s[6].size();i++){
		gotoxy(35+i,18);cout<<s[6][i];
		Sleep(30);
	}
	for(int i=0;i<s[7].size();i++){
		gotoxy(35+i,20);cout<<s[7][i];
		Sleep(30);
	}
	gotoxy(103,100);cout<<" "<<endl;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

	system("pause");

}
int MenuGeneral(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	Sleep(100);
	gotoxy(16,6);cout<<linea;
	gotoxy(33,5);cout<<"*****  MENU  ******";
	gotoxy(16,4);cout<<linea;
	gotoxy(28,8);cout<<"->";
	
	int menu_item=1, x=8;
	
	while(1)
	{
        gotoxy(30,8);cout<<"[1] Crear ";
		gotoxy(30,10);cout<<"[2] Modificar";
		gotoxy(30,12);cout<<"[3] Algoritmos de Expansion";	
		gotoxy(30,14);cout<<"[4] Visualizacion";
		gotoxy(30,16);cout<<"[0] Salir";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 16) //down button pressed
			{
				gotoxy(28,x); cout << "  ";
				x+=2;
				gotoxy(28,x); cout << "->";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 8) //up button pressed
			{
				gotoxy(28,x); cout << "  ";
				x-=2;
				gotoxy(28,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			if(menu_item==5){
				return 0;
			}else{
				return menu_item;
			}
		}		
	}
}

int MenuCrear(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	gotoxy(16,6);cout<<linea;
	gotoxy(33,5);cout<<"*****  MENU  ******";
	gotoxy(16,4);cout<<linea;
	
	gotoxy(21,8);cout<<"->";
	
	int menu_item=1, x=8;
	while(1){
		
        gotoxy(23,8);cout<<"[1] Matriz de Adyacencia ";
		gotoxy(23,10);cout<<"[2] Matriz de Adyacencia con pesos no dirigida";
		gotoxy(23,12);cout<<"[3] Matriz de Adyacencia con pesos dirigida";
		gotoxy(23,14);cout<<"Nota: Seleccione 2 para Arbol de Expansion Minimo";
		gotoxy(23,16);cout<<"[0] Salir";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 16) //down button pressed
		{
			gotoxy(21,x); cout << "  ";
			x+=2;
			if(menu_item==3){
				x+=2;
			}
			gotoxy(21,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 8) //up button pressed
			{
			gotoxy(21,x); cout << "  ";
			x-=2;
			if(menu_item==4){
				x-=2;
			}
			gotoxy(21,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			if(menu_item==4){
				return 0;
			}else{
				return menu_item;
			}
		}		
	}			
}


int MenuModificar(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";	
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	gotoxy(16,6);cout<<linea;
	gotoxy(25,5);cout<<"*****  MENU DE MODIFICACION  ******";
	gotoxy(16,4);cout<<linea;

  	
  	gotoxy(28,8);cout<<"->";
	
	int menu_item=1, x=8;
	while(1){
		
        gotoxy(30,8);cout<<"[1] Eliminar nodo ";
		gotoxy(30,10);cout<<"[2] Agregar nodo";
		gotoxy(30,12);cout<<"[3] Eliminar relacion";
		gotoxy(30,14);cout<<"[4] Agregar relacion";
		gotoxy(30,16);cout<<"[5] Regresar al Menu Principal";
		gotoxy(30,18);cout<<"[0] Salir";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 18) //down button pressed
		{
			gotoxy(28,x); cout << "  ";
			x+=2;
			gotoxy(28,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 8) //up button pressed
			{
			gotoxy(28,x); cout << "  ";
			x-=2;
			gotoxy(28,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			if(menu_item==6){
				return 0;
			}else{
				return menu_item;
			}
		}		
	}			
}

int MenuVisualizar(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	gotoxy(16,6);cout<<linea;
	gotoxy(25,5);cout<<"*****  MENU DE VISUALIZACION  ******";
	gotoxy(16,4);cout<<linea;
	  	
  	gotoxy(28,8);cout<<"->";
	
	int menu_item=1, x=8;
	while(1){
		
        gotoxy(30,8);cout<<"[1] Ver Matriz";
		gotoxy(30,10);cout<<"[2] Visualizar Grafo";
		gotoxy(30,12);cout<<"[3] Regresar";
		gotoxy(30,14);cout<<"[4] Regresar al Menu Principal";
		gotoxy(30,16);cout<<"[0] Salir";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 16) //down button pressed
		{
			gotoxy(28,x); cout << "  ";
			x+=2;
			gotoxy(28,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 8) //up button pressed
			{
			gotoxy(28,x); cout << "  ";
			x-=2;
			gotoxy(28,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			if(menu_item==5){
				return 0;
			}else{
				return menu_item;
			}
		}		
	}			
}

int MenuSalir(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	gotoxy(16,6);cout<<linea;
	gotoxy(25,5);cout<<"----- SEGURO QUE DESEA SALIR? -----    " ;
	gotoxy(16,4);cout<<linea;
	gotoxy(30,8);cout<<"";  	
	gotoxy(28,10);cout<<"->";
	
	int menu_item=1, x=10;
	while(1){
		
        gotoxy(30,10);cout<<"[1] Salir";
		gotoxy(30,12);cout<<"[2] Regresar";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed
		{
			gotoxy(28,x); cout << "  ";
			x+=2;
			gotoxy(28,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
			{
			gotoxy(28,x); cout << "  ";
			x-=2;
			gotoxy(28,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			return menu_item;
		}		
	}			
}



int MenuFinal(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	gotoxy(16,6);cout<<linea;
	gotoxy(25,5);cout<<"----- DESEA HACER ALGO MAS? -----    " ;
	gotoxy(16,4);cout<<linea;  	
	gotoxy(28,10);cout<<"->";
	
	int menu_item=1, x=10;
	while(1){
		
        gotoxy(30,10);cout<<"[1] Si";
		gotoxy(30,12);cout<<"[2] No";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed
		{
			gotoxy(28,x); cout << "  ";
			x+=2;
			gotoxy(28,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 10) //up button pressed
			{
			gotoxy(28,x); cout << "  ";
			x-=2;
			gotoxy(28,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			return menu_item;
		}		
	}	
}

int MenuAlgoritmosExpansion(){
	system("cls");
	system("color 07");
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15,4);cout<<"*";
	gotoxy(79,4);cout<<"*";
	for(int i=5;i<21;i++){
		gotoxy(15,i);cout<<"|";
		gotoxy(79,i);cout<<"|";
	}
	gotoxy(15,21);cout<<"*";
	gotoxy(79,21);cout<<"*";
	gotoxy(16,6);cout<<linea;
	gotoxy(25,5);cout<<"*****  MENU DE ALGORITMOS DE EXPANSION  ******";
	gotoxy(16,4);cout<<linea;
  	gotoxy(23,8);cout<<"->";
	
	int menu_item=1, x=8;
	while(1){
		
        gotoxy(25,8);cout<<"[1] MST - Arbol de Expansion Minimo";
		gotoxy(25,10);cout<<"[2] Camino mas corto";
		gotoxy(25,12);cout<<"[3] Regresar";
		gotoxy(25,14);cout<<"[0] Salir";;

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 14) //down button pressed
		{
			gotoxy(23,x); cout << "  ";
			x+=2;
			gotoxy(23,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 8) //up button pressed
			{
			gotoxy(23,x); cout << "  ";
			x-=2;
			gotoxy(23,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			if(menu_item==4){
				return 0;
			}else{
				return menu_item;
			}
		}		
	}			
}

void adios(){
	system("cls");
	int i,j,z,k,l;
	for(j=0;j<6;j++){
		for(i=0;i<15;i++){
			gotoxy(3+j,3+i);cout<<"|";
			Sleep(2);
		}
	}
	for(z=j;z<j+6;z++){
		for(i=0;i<4;i++){
			gotoxy(3+z,3+i);cout<<"|";
			Sleep(2);
		}
	}
	for(z=j;z<j+6;z++){
		for(i=0;i<4;i++){
			gotoxy(3+z,10+i);cout<<"|";
			Sleep(2);
		}
	}
	for(j=z;j<z+6;j++){
		for(i=0;i<15;i++){
			gotoxy(3+j,3+i);cout<<"|";
			Sleep(2);
		}
	}
	j=j+3;
	for(z=j;z<j+6;z++){
		for(i=0;i<15;i++){
			gotoxy(3+z,3+i);cout<<"|";
			Sleep(2);
		}
	}
	int cont=-1;
	for(j=z;j<z+6;j++){
		cont++;
		for(i=0;i<4;i++){
			gotoxy(3+j,3+i+cont);cout<<"|";
			gotoxy(3+j,17-i-cont);cout<<"|";
			Sleep(2);			
		}
		for(i=0;i<4;i++){
			gotoxy(4+j,3+i+cont);cout<<"|";
			gotoxy(4+j,17-i-cont);cout<<"|";
			Sleep(2);			
		}
		for(i=0;i<5;i++){
			gotoxy(5+j,3+i+cont);cout<<"|";
			gotoxy(5+j,17-i-cont);cout<<"|";
			Sleep(2);			
		}
	}
	j+=5;
	for(z=j;z<j+6;z++){
		for(i=0;i<15;i++){
			gotoxy(3+z,3+i);cout<<"|";
			Sleep(2);
		}
	}
	z+=2;
	for(j=z;j<z+6;j++){
		for(i=0;i<15;i++){
			gotoxy(3+j,3+i);cout<<"|";
			Sleep(2);
		}
	}
	for(z=j;z<j+6;z++){
		for(i=0;i<4;i++){
			gotoxy(3+z,3+i);cout<<"|";
			Sleep(2);
		}
	}
	for(z=j;z<j+6;z++){
		for(i=0;i<4;i++){
			gotoxy(3+z,14+i);cout<<"|";
			Sleep(2);
		}
	}
	for(j=z;j<z+6;j++){
		for(i=0;i<15;i++){
			gotoxy(3+j,3+i);cout<<"|";
			Sleep(2);
		}
	}
	j+=3;
	for(z=j;z<j+6;z++){
		for(i=0;i<9;i++){
			gotoxy(3+z,3+i);cout<<"|";
			Sleep(2);
		}
	}
	for(z=j;z<j+6;z++){
		for(i=0;i<3;i++){
			gotoxy(3+z,17-i);cout<<"|";
			Sleep(2);
		}
	}
	for(i=0;i<3;i++){
		for(j=z;j<z+11;j++){
			gotoxy(3+j,3+i);cout<<"|";
			gotoxy(3+j,15+i);cout<<"|";
			gotoxy(3+j,9+i);cout<<"|";
			Sleep(2);
		}
	}
	j-=6;
	for(z=j;z<j+6;z++){
		for(i=0;i<5;i++){
			gotoxy(3+z,10+i);cout<<"|";
			Sleep(2);
		}
	}
	gotoxy(0,20);
	system("pause");
}


	map<string,int> nom1;

	vector <string> listar() {
		vector <string> ans;
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir ("Matrices")) != NULL) {
			while ((ent = readdir (dir)) != NULL) {
				//printf ("%s\n", ent->d_name);
				int l = strlen(ent->d_name);
				if (l <= 3) continue;
				
				string name = "";
				for (int i = 0; i < l; i++) {
					name += ent->d_name[i];
				}
				if (name[l-3] == 't' && name[l-2] == 'x' && name[l-1] == 't') {
					ans.push_back(name);
				}
			}
			closedir (dir);
		} else {
			perror ("");
		}
		return ans;
	}

string ArchivoParaModificar(vector <string> xd){
	system("cls");
	cout<<endl;
	cout<<"Elija el Archivo que Modificara"<<endl;
	cout<<endl;
	for (int i=0;i < xd.size();i++) {
		gotoxy(10,4+i);cout<<xd[i];
	}
	cout<<endl;
	gotoxy(8,4); cout << "->";
	int menu_item=0, x=4;
	while(1){
		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != xd.size()+3) //down button pressed
		{
			gotoxy(8,x); cout << "  ";
			x+=1;
			gotoxy(8,x); cout << "->";
			menu_item++;
			continue;
				
		}
			
		if(GetAsyncKeyState(VK_UP) && x != 4) //up button pressed
			{
			gotoxy(8,x); cout << "  ";
			x-=1;
			gotoxy(8,x); cout << "->";
			menu_item--;
			continue;
			}
				
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			return xd[menu_item];
		}		
	}			
}

int CrearMatriz(){
	system("cls");
	int opc;
	opc=MenuCrear();
	if(opc==0) return 0;
	system("cls");
	char s1[100];
	char s2[110] = "Matrices/";
	cout<<"Inserte nombre del fichero"<<endl;
	gets(s1);
	strcat(s1,".txt");
	strcat(s2,s1);
	int n;
	map<string,int> nom1;
	cout<<"Inserte numero de nodos"<<endl;
	cin>>n;
	int C[200][200];
	string nom[n];
	cout<<"Inserte nombre de nodos dejando un espacio"<<endl;
	for (int i=0;i<n;i++){
		cin>>nom[i];
		nom1[nom[i]]=i;
	}
	string s;
	getline(cin,s);
		
	if(opc==0){
		return 0;
	} else if(opc==2 || opc==3){
		int a;
		string s3,s4;
		
		int aristas;
		cout<<"Inserte numero de aristas (relaciones)"<<endl;
		cout<<"Nota: Si esta creando una Matriz no dirigida A B es lo mismo que B A"<<endl;
		cout<<"      Si esta creando una Matriz dirigida A B es diferente a B A"<<endl;
		cin>>aristas;
		
		cout<<"Inserte nombres de los pares relaciones con su respectiva distancia (dejando un espacio)"<<endl;
		cout<<"ejm: A B 150"<<endl<<endl;
		if(opc==2){
			for (int i=0;i<aristas;i++){
			cin>>s3>>s4>>a;
			C[nom1[s3]][nom1[s4]]=a;
			C[nom1[s4]][nom1[s3]]=a;
			}
		}else{
			for (int i=0;i<aristas;i++){
				cin>>s3>>s4>>a;
				C[nom1[s3]][nom1[s4]]=a;
			}		
		}
	} else if(opc==1){
		string aux,aux1;
		int a,b;
		
		for (int i=0;i<n;i++){
			cout<<"Inserte todos los nodos con los que "<<nom[i]<<" esta relacionado (separados por espacio)"<<endl;
			getline(cin,aux);
			stringstream io(aux);
			string abc;
			int k=0;
			while (io >> abc) {
				a=nom1[nom[i]];
				b=nom1[abc];
				C[a][b]=1;
				C[b][a]=1;			
			}
		}
	}
	
	ofstream fich(s2);
		fich<<n<<endl;
		for(int i=0;i<n;i++){
			fich<<nom[i]<<" ";
			for (int j=0;j<n;j++){
				fich<<C[i][j]<<" ";
			}
			fich<<endl;
		}
	
	fich.close();

	return 1;
}

void PRIM(int graph[200][200],int V,string nom[200])
{
	system("cls");
    // Imprimir
    //primMST(graph);
    int horizontal,vertical;
    
    GetDesktopResolution(horizontal,vertical);
    //cout<<horizontal<<" "<<vertical<<endl;
    
    int MatrizPRIM[V][V]={};
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
	
	system("pause");
}





