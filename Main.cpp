#include <iostream>
#include <map>
#include "wtypes.h"
#include <graphics.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <sstream>
#include <cstring>
#include <conio.h>
#include <math.h>
#include <cmath>
#define linea "_______________________________________________________________"
#include "funciones.h"
#include "djikestra.h"
#define MAX_SIZE 200

int horizontal = 0;
int vertical = 0;

map<string,int> nom2;

bool ad = true;
bool dir = false;
bool dijk = false;
int dij[MAX_SIZE][MAX_SIZE] = {};

using namespace std;
int i,j;
string archmod;
int main(){
	MenuPresentacion();
	while (1){
		system("cls");
		int opc1;
		opc1 = MenuGeneral();
		if (opc1==0){
			int opc2=MenuSalir();
			if(opc2==1){
				adios();
	        	return 0;
			} else{
				continue;
			}
	    }
		if (opc1==1){
			int opcx;
			opcx = CrearMatriz ();
			if(opcx==0){
				continue;
			}
			goto end;			
		}
		if (opc1>1||opc1<5){
			
				//-----------------------------OBTENER MATRIZ INICIO------------------------------
						int n;
						int D[MAX_SIZE][MAX_SIZE];
						string nom[MAX_SIZE];
						system("cls");
						string arch="Matrices/";
						string arch1=arch + ArchivoParaModificar(listar());
						archmod=arch1;
						system("cls");
						ifstream fich1(arch1.c_str());
						fich1>>n;
						string aux;
						int j=0;
						string xd[MAX_SIZE];
						while(1){
							getline(fich1,aux);
							if(!fich1) break;
							stringstream io(aux);
							string abc;
							int k=0;
							while (io >> abc) {
								xd[k]=abc;
								k++;
							}
							cout<<endl;
							if (j>0){
								nom[j-1]=xd[0];
								nom2[xd[0]]=j-1;
								for (int t=0;t<n;t++){
									D[j-1][t]=atoi(xd[t+1].c_str());
								}
							}
							j++;
						}
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								if (D[i][j]>1){
									ad = false;
								}
								if(D[i][j]!=D[j][i]){
									dir = true;
									ad = false;
								}
							}
						}
						fich1.close();
				//--------------------------------OBTENER MATRIZ FIN--------------------------------
			if (opc1==2){
				// ------------------------------- Modificar Inicio -------------------------
				modificar:
				system("cls");
				int opc2;
				opc2=MenuModificar();
				if(opc2==0){
					int opc2=MenuSalir();
					if(opc2==1){
						adios();
	        			return 0;
					} else{
						goto modificar;
					}
				} else if(opc2==5){
					continue;
				}				
				if(opc2==1){
					//------------------------------ELIMINAR NODO INICIO ------------------------------------
					system("cls");
					cout<<endl;
					cout<<"Estos son todos los nodos:"<<endl<<endl;
					for(int t=0;t<n;t++){
						cout<<nom[t]<<endl;
					}
					cout<<endl<<endl;
					cout<<"Cuantos nodos desea eliminar?"<<endl;
					int el;
					cin>>el;
					int n1=n-el;
					int D1[n1][n1];
					cout<<"Inserte los nodos que eliminara (uno por linea)"<<endl;
					string s;
					getline(cin,s);
					string eli[MAX_SIZE];
					for(int q=0;q<el;q++){
						getline(cin,eli[q]);			
					}
					string aux=archmod+"aux.txt";
					ofstream fich(aux.c_str());
					fich<<n-el<<endl;
					for(int q=0;q<n;q++){
						check1:
						for(int w=0;w<el;w++){
							if(nom[q]==eli[w]){
								q++;
								goto check1;
							}				
						}
						fich<<nom[q]<<" ";
						for(int t=0;t<n;t++){
							check2:
							for(int w=0;w<el;w++){
								if(nom[t]==eli[w]){
									t++;
									goto check2;
								}				
							}
							fich<<D[q][t]<<" ";
						}
						fich<<endl;
					}
					fich.close();
					remove(archmod.c_str());
					rename(aux.c_str(),archmod.c_str());
					cout<<endl<<endl;
					system("pause");
					goto end;					
					//--------------------------------------ELIMINAR NODO FIN-----------------------------
								
				} else if(opc2==2){
					//----------------------------------AGREGAR NODO INICIO----------------------------------
					if(ad){
						system("cls");
						cout<<endl;
						cout<<"Estos son todos los nodos:"<<endl<<endl;
						for(int t=0;t<n;t++){
							cout<<nom[t]<<endl;
						}
						cout<<endl<<endl;
						cout<<"Cuantos nodos desea agregar?"<<endl;
						int el,stack;
						cin>>el;
						stack=n;
						cout<<"Inserte los nombres de los nodos dejando un espacio "<<endl;
						string s[MAX_SIZE],inv[MAX_SIZE],aux3[MAX_SIZE];
						for(int ii=n;ii<n+el;ii++)
						{
							cin>>nom[ii];
						}
						
						ifstream fich1(arch1.c_str());
						int rrr=n+el;
						fich1>>rrr;
						string aux4[MAX_SIZE];
						j=0;
						
						while(1){
							if(!fich1) break;
							getline(fich1,aux4[j]);
							j++;
						}
						fich1.close();
						
						int k;
						getline(cin,aux3[0]);
						
						for(int yy=0;yy<el;yy++)
						{
							cout<<"Inserte los nodos con los que el nodo "<<nom[yy+stack]<<" esta relacionado "<<endl;
							getline(cin,aux3[yy]);
								
						}
						string man[MAX_SIZE],afa;
						
						for(int ii=0;ii<el;ii++)
						{
							k=0;
							stringstream io(aux3[ii]);
							while (io >> afa) {
								inv[k]=afa;
							//	cout<<inv[k];
								k++;
							}
						
							for(int ee=0;ee<k;ee++)
							{
								if(nom[0]==inv[ee] )
								{
									man[ii]='1';
									man[ii]=man[ii]+' ';
									break;
								}
								else
								{
									man[ii]='0';
									man[ii]=man[ii]+' ';
								
								}
							}
							for(int uu=1;uu<n+el;uu++)
							{
								for(int yy=0;yy<k;yy++)
								{
									if(uu<n+el-1)
									{
										if(nom[uu]==inv[yy])
										{
											man[ii]=man[ii]+'1';
											man[ii]=man[ii]+' ';
											break;
										}
										else if(yy==k-1)
										{
											man[ii]=man[ii]+'0';
											man[ii]=man[ii]+ ' ';
										}
									}
									else
									{
										if(nom[uu]==inv[yy])
										{
											man[ii]=man[ii]+'1';
											
											break;
										}
										else if(yy==k-1)
										{
											man[ii]=man[ii]+'0';
										
										}
									}
								}
							}
							
						}
						
						ofstream fich2(arch1.c_str());
						fich2<<stack+el<<endl;
						for(int ww=1;ww<stack+1;ww++)
						{
							fich2<<aux4[ww]<<" ";
						
							for(int we=0;we<el;we++)
							{
								if(we<el-1)
								{
									fich2<<man[we][2*(ww-1)]<<" ";
								}
								else
								{
									fich2<<man[we][2*(ww-1)];
								}
							}
							
							fich2<<endl;
							
						}
						for(int ert=0;ert<el;ert++)
						{
							fich2<<nom[stack+ert]<<" "<<man[ert]<<endl;
						}
						
						fich2.close();
					
						cout<<endl<<endl;
						system("pause");
						goto end;
					}else if(dir && !ad)//DIRIGIDO CON PESOS..........................................
						{
						system("cls");
						cout<<endl;
						cout<<"Estos son todos los nodos:"<<endl<<endl;
						for(int t=0;t<n;t++){
							cout<<nom[t]<<endl;
						}
						cout<<endl<<endl;
						cout<<"Cuantos nodos desea agregar?"<<endl;
						int el,stack;
						cin>>el;
						stack=n;
						cout<<"Inserte los nombres de los nodos dejando un espacio "<<endl;
						string s[MAX_SIZE],inv[MAX_SIZE],aux3[MAX_SIZE];
						for(int ii=n;ii<n+el;ii++)
						{
							cin>>nom[ii];
						}
						
						ifstream fich1(arch1.c_str());
						int rrr=n+el;
						fich1>>rrr;
						string aux4[MAX_SIZE];
						j=0;
						
						while(1){
							if(!fich1) break;
							getline(fich1,aux4[j]);
							j++;
						}
						fich1.close();
						
						int k;
						getline(cin,aux3[0]);
						
						for(int yyy=0;yyy<el;yyy++)
						{
							cout<<"Inserte los nodos con los que el nodo "<<nom[yyy+stack]<<" esta relacionado seguido de su peso: "<<endl;
							cout<<"EJM: A 300"<<endl;
							getline(cin,aux3[yyy]);
								
						}
						string man[MAX_SIZE],afa,lop[MAX_SIZE];
						
						for(int ii=0;ii<el;ii++)
						{
							k=0;
							stringstream io(aux3[ii]);
							while (io >> afa) {
								if(k%2==0)
								{
								inv[k/2]=afa;
								}
								else
								{
									lop[(k-1)/2]=afa;
								}
							//	cout<<inv[k];
								k++;
							}
							k=(k)/2;
						
							for(int ee=0;ee<k;ee++)
							{
								if(nom[0]==inv[ee] )
								{
									man[ii]=lop[ee];
									man[ii]=man[ii]+' ';
									break;
								}
								else
								{
									man[ii]='0';
									man[ii]=man[ii]+' ';
								
								}
							}
							for(int uu=1;uu<n+el;uu++)
							{
								for(int yy=0;yy<k;yy++)
								{
									if(uu<n+el-1)
									{
										if(nom[uu]==inv[yy])
										{
											man[ii]=man[ii]+lop[yy];
											man[ii]=man[ii]+' ';
											break;
										}
										else if(yy==k-1)
										{
											man[ii]=man[ii]+'0';
											man[ii]=man[ii]+ ' ';
										}
									}
									else
									{
										if(nom[uu]==inv[yy])
										{
											man[ii]=man[ii]+lop[yy];
											
											break;
										}
										else if(yy==k-1)
										{
											man[ii]=man[ii]+'0';
										
										}
									}
								}
							}
							
						}
						
						ofstream fich2(arch1.c_str());
						cout<<endl;
						cout<<"Eston son los nodos que se agregaran"<<endl;
						for(int op=n;op<n+el;op++)
						{
							cout<<nom[op]<<endl;
						}
						cout<<endl;
						string help[MAX_SIZE],mmr[MAX_SIZE],asa;
						for(int asd=0;asd<n;asd++)
						{
							cout<<"Ingrese si el nodo "<<nom[asd]<<" esta relacionado con alguno de los nodos agregados, seguido por el peso: "<<endl;
							cout<<"EJM: A 200"<<endl;
							getline(cin,aux3[asd]);
							k=0;
							stringstream io2(aux3[asd]);
							while (io2 >> asa) {
								if(k%2==0)
								{
								inv[k/2]=asa;
								}
								else
								{
									mmr[(k-1)/2]=asa;
								}
							//	cout<<inv[k];
								k++;
							}
							k=(k)/2;
							for(int ee=0;ee<k;ee++)
							{
								if(nom[n]==inv[ee] )
								{
									help[asd]=mmr[ee];
									help[asd]=help[asd]+' ';
									break;
								}
								else
								{
									help[asd]='0';
									help[asd]=help[asd]+' ';
								
								}
							}
							for(int uu=n+1;uu<n+el;uu++)
							{
								for(int yy=0;yy<k;yy++)
								{
									if(uu<n+el-1)
									{
										if(nom[uu]==inv[yy])
										{
											help[asd]=help[asd]+mmr[yy];
											help[asd]=help[asd]+' ';
											break;
										}
										else if(yy==k-1)
										{
											help[asd]=help[asd]+'0';
											help[asd]=help[asd]+ ' ';
										}
									}
									else
									{
										if(nom[uu]==inv[yy])
										{
											help[asd]=help[asd]+mmr[yy];
											
											break;
										}
										else if(yy==k-1)
										{
											help[asd]=help[asd]+'0';
										
										}
									}
								}
							}		
						}
						fich2<<stack+el<<endl;
						for(int ww=1;ww<stack+1;ww++)
						{
							fich2<<aux4[ww]<<" ";
						
							for(int we=0;we<el;we++)
							{
								fich2<<help[we]<<endl;	
							}
							
							fich2<<endl;
							
						}
						for(int ert=0;ert<el;ert++)
						{
							fich2<<nom[stack+ert]<<" "<<man[ert]<<endl;
						}
						
						fich2.close();
					
						cout<<endl<<endl;
						system("pause");
						goto end;
					}else if(!dir && !ad)//NO DIRIGIDO CON PESOS
					{
						system("cls");
						cout<<endl;
						cout<<"Estos son todos los nodos:"<<endl<<endl;
						for(int t=0;t<n;t++){
							cout<<nom[t]<<endl;
						}
						cout<<endl<<endl;
						cout<<"Cuantos nodos desea agregar?"<<endl;
						int el,stack;
						cin>>el;
						stack=n;
						cout<<"Inserte los nombres de los nodos dejando un espacio "<<endl;
						string s[MAX_SIZE],inv[MAX_SIZE],aux3[MAX_SIZE];
						for(int ii=n;ii<n+el;ii++)
						{
							cin>>nom[ii];
						}
						
						ifstream fich1(arch1.c_str());
						int rrr=n+el;
						fich1>>rrr;
						string aux4[MAX_SIZE];
						j=0;
						
						while(1){
							if(!fich1) break;
							getline(fich1,aux4[j]);
							j++;
						}
						fich1.close();
						
						int k;
						getline(cin,aux3[0]);
						
						for(int yy=0;yy<el;yy++)
						{
							cout<<"Inserte los nodos con los que el nodo "<<nom[yy+stack]<<" esta relacionado seguido de su peso: "<<endl;
							cout<<"EJM: B 30:"<<endl;
							getline(cin,aux3[yy]);
								
						}
						string man[MAX_SIZE],afa,logica[MAX_SIZE];
						
						for(int ii=0;ii<el;ii++)
						{
							k=0;
							stringstream io(aux3[ii]);
							while (io >> afa) {
								if(k%2==0)
								{
								inv[k/2]=afa;
								}
								else
								{
									logica[(k-1)/2]=afa;
								}
							//	cout<<inv[k];
								k++;
							}
							k=(k)/2;
						
							for(int ee=0;ee<k;ee++)
							{
								if(nom[0]==inv[ee] )
								{
									man[ii]=logica[ee];
									man[ii]=man[ii]+' ';
									break;
								}
								else
								{
									man[ii]='0';
									man[ii]=man[ii]+' ';
								
								}
							}
							for(int uu=1;uu<n+el;uu++)
							{
								for(int yy=0;yy<k;yy++)
								{
									if(uu<n+el-1)
									{
										if(nom[uu]==inv[yy])
										{
											man[ii]=man[ii]+logica[yy];
											man[ii]=man[ii]+' ';
											break;
										}
										else if(yy==k-1)
										{
											man[ii]=man[ii]+'0';
											man[ii]=man[ii]+ ' ';
										}
									}
									else
									{
										if(nom[uu]==inv[yy])
										{
											man[ii]=man[ii]+logica[yy];
											
											break;
										}
										else if(yy==k-1)
										{
											man[ii]=man[ii]+'0';
										
										}
									}
								}
							}
							
						}
						
						ofstream fich2(arch1.c_str());
						fich2<<stack+el<<endl;
						int posicion[MAX_SIZE],t=0;
						for(int ww=1;ww<stack+1;ww++)
						{
							fich2<<aux4[ww]<<" ";
						
							for(int we=0;we<el;we++)
							{
								if(we<el-1)
								{
									if(ww==1)
									{
										t=0;
									}
									else
									{
										t=posicion[we];
									}
									while(man[we][t]!=' ')
									{
									
									fich2<<man[we][t];
									t++;
									}
									fich2<<' ';
									posicion[we]=t+1;
								}
								else
								{
									if(ww==1)
									{
										t=0;
									}
									else
									{
										t=posicion[we];
									}
									while(man[we][t]!=' ')
									{
									
									fich2<<man[we][t];
									t++;
									}
									posicion[we]=t+1;
								}
							}
							
							fich2<<endl;
							
						}
						for(int ert=0;ert<el;ert++)
						{
							fich2<<nom[stack+ert]<<" "<<man[ert]<<endl;
						}
						
						fich2.close();
					
						cout<<endl<<endl;
						system("pause");
						goto end;
					}				
					//----------------------------------AGREGAR NODO FIN----------------------------------
				// ------------------------------- Modificar FIN -------------------------
				} else if(opc2==3){
					// -------------------------------ELIMINAR RELACION INICIO----------------------------
					system("cls");
					cout<<endl;
					cout<<"Estos son los nodos existentes y relacionados:"<<endl<<endl;
					for(int t=0;t<n;t++){
						for(int z=t+1;z<n;z++){
							if (D[t][z]>1){
								cout<<nom[t]<<" - "<<nom[z]<<endl;
							}	
						}
					}
					cout<<endl<<endl;
					bool w=1;
					string a, b, fake;
					getline(cin,fake);
					while(w){
						cout<<"Inserte el par que desea eliminar (un elemento por linea)"<<endl;
						getline(cin,a);
						getline(cin,b);
						cout<<nom2[a]<<" "<<nom2[b]<<endl;
						D[nom2[a]][nom2[b]]=0;
						if(ad) D[nom2[b]][nom2[a]]=0;
						cout<<endl;
						cout<<"Desea eliminar otra relacion?(1/0)"<<endl;
						cin>>w;
					}
					string aux=archmod+"aux.txt";
					ofstream fich(aux.c_str());
					fich<<n<<endl;
					for(int i=0;i<n;i++){
						fich<<nom[i]<<" ";
						for (int j=0;j<n;j++){
							fich<<D[i][j]<<" ";
						}
						fich<<endl;
					}				
					fich.close();
					remove(archmod.c_str());
					rename(aux.c_str(),archmod.c_str());
					cout<<endl<<endl;
					system("pause");
					// -------------------------------ELIMINAR RELACION FIN----------------------------
				} else if(opc2==4){
					// -------------------------------AGREGAR RELACION INICIO----------------------------
					system("cls");
					cout<<endl;
					cout<<"Estos son los nodos existentes y NO relacionados:"<<endl<<endl;
					for(int t=0;t<n;t++){
						for(int z=t+1;z<n;z++){
							if (D[t][z]==0){
								cout<<nom[t]<<" - "<<nom[z]<<endl;
							}	
						}
					}
					cout<<endl<<endl;
					bool w=1;
					string a, b, fake;
					getline(cin,fake);
					while(w){
						cout<<"Inserte el par que desea agregar (un elemento por linea)"<<endl;
						getline(cin,a);
						getline(cin,b);
						cout<<nom2[a]<<" "<<nom2[b]<<endl;
						D[nom2[a]][nom2[b]]=1;
						D[nom2[b]][nom2[a]]=1;
						cout<<"Desea agregar otra relacion?(1/0)"<<endl;
						cin>>w;
					}
					string aux=archmod+"aux.txt";
					ofstream fich(aux.c_str());
					fich<<n<<endl;
					for(int i=0;i<n;i++){
						fich<<nom[i]<<" ";
						for (int j=0;j<n;j++){
							fich<<D[i][j]<<" ";
						}
						fich<<endl;
					}				
					fich.close();
					remove(archmod.c_str());
					rename(aux.c_str(),archmod.c_str());
					cout<<endl<<endl;
					system("pause");
					// -------------------------------ELIMINAR RELACION FIN----------------------------
				} else{
					system("cls");
					cout<<"Opcion invalida, ingrese nuevamente"<<endl;
					system("pause");
					goto modificar;
				}
			} else if(opc1==3){
				// ------------------------------- Algoritmos de Modificación Inicio-------------------
				expansion:
				int opc3=MenuAlgoritmosExpansion();
				if(opc3==3){
					continue;
				}else if(opc3==0){
					int opc2=MenuSalir();
					if(opc2==1){
						adios();
	        			return 0;
					} else{
						goto expansion;
					}
				}else if(opc3==1){
					// -------------------------------PRIM INICIO----------------------------
					if(ad || dir){
						system("cls");
						cout<<endl;
						cout<<"ERROR, esta no es una matriz de adyacencia con pesos no dirigida, elija nuevamente"<<endl<<endl;
						system("pause");
						system("cls");
						continue;
					}else if(!dir){
						PRIM( D,n,nom);
						system("cls");
						char s1[100];
						char s2[110] = "Matrices/";
						cout<<"Inserte nombre del fichero"<<endl;
						gets(s1);
						strcat(s1,".txt");
						strcat(s2,s1);
						ofstream fich(s2);
						fich<<n<<endl;
						for(int i=0;i<n;i++){
							fich<<nom[i]<<" ";
							for (int j=0;j<n;j++){
								fich<<D[i][j]<<" ";
							}
							fich<<endl;
						}
					
						fich.close();
						goto visualizar;
						// ------------------------------PRIM FIN----------------------------
					}
				}else if(opc3==2){
					// ------------------------------DJIKESTRA INICIO----------------------------
					if(ad){
						system("cls");
						cout<<endl;
						cout<<"ERROR, esta es una matriz de adyacencia, no se puede ejecutar el programa"<<endl<<endl;
						system("pause");
						system("cls");
						continue;
					}else{
						system("cls");
						cout<<"Estos son los nodos:"<<endl<<endl;
						for(i=0;i<n;i++){
							cout<<nom[i]<<endl;
						}
						string inicio, fin;
						cout<<"Inserte el nombre del nodo inicial: ";getline(cin,inicio);
						cout<<"Inserte el nombre del nodo final: ";getline(cin,fin);
						system("cls");
						djikestra(D,dij,nom,nom2[inicio],nom2[fin],n);
						dijk = true;
						goto visualizar;
						// ------------------------------DJIKESTRA FIN----------------------------
					}
				}
				// ------------------------------- Algoritmos de Modificación Fin-------------------
			} else if (opc1==4){
				// ------------------------------- Visualizar Inicio -------------------------
				visualizar:
				int opc2;
				opc2=MenuVisualizar();
				if(opc2==1){
					system("cls");
					if(dijk){
						for(i=0;i<n;i++){
							for(j=0;j<n;j++){
								cout<<dij[i][j]<<" ";
							}
							cout<<"  "<<nom[i]<<endl;
						}
					}
					else{
						char a = 'A';
						for(int z=0;z<n;z++){
							int b = a;
							b = b + z;
							cout<<"        "<<(char)b<<" -> "<<nom[z]<<endl;
						}
						cout<<endl;
						a = 'A';
						cout<<"      ";
						for(int z=0;z<n;z++){
							int b = a;
							b = b + z;
							char x = b;
							gotoxy(7+4*z,1+n);cout<< x;
						}
						cout<<endl;
						for(i=0;i<n;i++){
							int b = a;
							b = b + i;
							char x = b;
							gotoxy(3,2+n+i);cout<< x;
							for(j=0;j<n;j++){
								gotoxy(7+4*j,2+n+i);cout<<D[i][j]<<" ";
							}
							cout<<endl;
						}	
					}
					cout<<endl<<endl<<endl;
					system("pause");
					goto visualizar;
				}else if(opc2==3){
					goto modificar;
				}else if(opc2==4){
					continue;
				} else if(opc2==0){
					int opc2=MenuSalir();
					if(opc2==1){
						adios();
	        			return 0;
					} else{
						goto visualizar;
					}	
				}
				GetDesktopResolution(horizontal, vertical);
				system("cls");			    
			    //if(radio <= 0) break;
				initwindow(horizontal, vertical-50, "Grafico");
			//	bar(0,0,getmaxx(),getmaxy());
			    long double x[n], y[n];
			    long double x_center = getmaxx() / 2, y_center = getmaxy() / 2;
			    setlinestyle(0,0,2);
			    setcolor(RED);
			    for(i = 0; i < n; i++ ) {
			    	x[i] =cos((360*1.0/n)*i*3.14159/180);
			        y[i] =sin((360*1.0/n)*i*3.14159/180);
			    }
			    setcolor(RED);
			    for(int it=0; it<10000; it++) {
					double dx[MAX_SIZE]={};
					double dy[MAX_SIZE]={};
					for(int i=0; i<n; i++) {
						for(int j=i+1; j<n; j++) {
							double f = 0.001 / hypot(x[i] - x[j], y[i] - y[j]);
							double theta = atan2(y[j] - y[i], x[j] - x[i]);
							dx[i] -= f*cos(theta);
							dy[i] -= f*sin(theta);
							dx[j] += f*cos(theta);
							dy[j] += f*sin(theta);
						}
					}
					for(int i=0; i<n; i++) {
						for(int j=i+1; j<n; j++) {
							if(D[i][j] || D[j][i]) {
								double f = 0.001 * hypot(x[i] - x[j], y[i] - y[j]) * hypot(x[i] - x[j], y[i] - y[j]);
								double theta = atan2(y[j] - y[i], x[j] - x[i]);
								dx[i] += f*cos(theta);
								dy[i] += f*sin(theta);
								dx[j] -= f*cos(theta);
								dy[j] -= f*sin(theta);
							}
						}
					}
					for(int i=0; i<n; i++){
						x[i] += dx[i], y[i] += dy[i];
						if(x[i]*70+x_center<100
						){
							x[i]+=1;
						}else if(x[i]*70>x_center-100){
							x[i]-=1;
						}
						if(y[i]*70+y_center-75<100){
							y[i]+=1;
						}else if(y[i]*70-75>y_center-100){
							y[i]-=1;
						}
					}
					if(it%5==0){
						cleardevice();
						for( i = 0; i < n; i++){
					        for( j =0 ; j < n; j++){
					            if(D[i][j]>=1)
								{	
									setcolor(RED);
									if(D[i][j]==D[j][i]){
										line(x[i]*70+x_center,y[i]*70+y_center-75,x[j]*70+x_center,y[j]*70+y_center-75);
									}
									if(D[i][j]!=D[j][i]){
										double xi=x[i]*70+x_center;
										double xj=x[j]*70+x_center;
										double yi=y[i]*70+y_center-75;
										double yj=y[j]*70+y_center-75;
										int r = 20;
										double m = (yj-yi)/(xj-xi);
										double distxy = sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
										double e = xj + r*(xi-xj)/distxy;
										double f = yj + r*(yi-yj)/distxy;
										line(xi,yi,xj,yj);
										setcolor(YELLOW);
										setlinestyle(0,0,1);
										fillellipse(e,f,4,4);	
									}									
					       		}
					       	}
						}
					    for( i = 0; i < n; i++ ) {
					    	fillellipse(x[i]*70+x_center,y[i]*70+y_center-75,15,15);
					    }
					}
				}
				
				for( i = 0; i < n; i++){
					        for( j =0 ; j < n; j++){
					            if(D[i][j]>=1)
								{	
									setcolor(RED);
									if(D[i][j]==D[j][i]){
										line(x[i]*70+x_center,y[i]*70+y_center-75,x[j]*70+x_center,y[j]*70+y_center-75);
									}
									if(D[i][j]!=D[j][i]){
										double xi=x[i]*70+x_center;
										double xj=x[j]*70+x_center;
										double yi=y[i]*70+y_center-75;
										double yj=y[j]*70+y_center-75;
										int r = 20;
										double m = (yj-yi)/(xj-xi);
										double distxy = sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
										double e = xj + r*(xi-xj)/distxy;
										double f = yj + r*(yi-yj)/distxy;
										line(xi,yi,xj,yj);
										setcolor(YELLOW);
										setlinestyle(0,0,1);
										fillellipse(e,f,4,4);	
									}									
					       		}
					       	}
						}
						
				settextstyle(SMALL_FONT, 0, 5 );
				
				
				j=0;
				for(i=0;i<n;i++){
					char *cstr = new char[MAX_SIZE];
					char *wa = new char[2];
					strcpy(cstr, nom[i].c_str());
					char w = 'A' + i;
					wa[0]=w;
					wa[1]='\0';
					setbkcolor(WHITE);
					outtextxy(x[i]*70+x_center-5,y[i]*70+y_center-75-5,wa);
					setbkcolor(BLACK);
					outtextxy(5,i*17+5,wa);
					outtextxy(25,i*17+5,cstr);
					delete [] cstr;
					delete [] wa;
				}
				
				
				if(dijk){
					for(i=0;i<n;i++){
						for(j=0;j<n;j++){
							if(dij[i][j]){
								double xi=x[i]*70+x_center;
								double xj=x[j]*70+x_center;
								double yi=y[i]*70+y_center-75;
								double yj=y[j]*70+y_center-75;
								int r = 20;
								double m = (yj-yi)/(xj-xi);
								double distxy = sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
								double e = xj + r*(xi-xj)/distxy;
								double f = yj + r*(yi-yj)/distxy;
								setcolor(YELLOW);
								setlinestyle(0,0,1);
								fillellipse(e,f,4,4);
								setcolor(BLUE);
								setlinestyle(0,0,2);
								line(x[i]*70+x_center,y[i]*70+y_center-75,x[j]*70+x_center,y[j]*70+y_center-75);
								settextstyle(SMALL_FONT, 0, 5 );
								setbkcolor(BLACK);
								char str[100];
								itoa(dij[i][j],str,10);
								outtextxy(x[i]*35+x[j]*35 + x_center ,y[i]*35+y[j]*35 + y_center - 75,str);
								dijk = false;
							}	
						}
					}
				}
				getch();
				cleardevice();
			    closegraph();
			    goto end;
			    // ------------------------------- Visualizar Fin -------------------------
			}
		}else{
			system("cls");
			cout<<"Opcion invalida, ingrese nuevamente"<<endl;
			system("pause");
			continue;
		}
		end:
		int opc2;
		opc2=MenuFinal();
		if(opc2==2){
			adios();
	    	return 0;
		}
		
	}
}


