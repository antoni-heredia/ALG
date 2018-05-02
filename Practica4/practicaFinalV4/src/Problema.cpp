#include "Punto.h"
#include "Problema.h"
#include <fstream>
#include <cmath>
#include <string>
#include <cctype>
#include "Solucion.h"
using namespace std;
Problema::Problema(){
		matriz=0;
		ciudades=0;
		vector=0;
}
bool Problema::Leer(const char* nombreFichero){
	Liberar();
	int numCiudades;
	double x,y;
	string cabecera;

	ifstream archi;
	// Abrir archivo
	archi.open(nombreFichero);
	if (!archi) {
		cerr << "No se pudo abrir el archivo " << nombreFichero<<".\n";
		return false;
	}
	// Leer la palabra DIMENSION:
	archi >> cabecera;
	// Leer numero de ciudades
	archi >> numCiudades;
	
	if(archi.fail()){
		cerr << "Formato de archivo de lectura no válido.\n";
		return false;
	}
	ciudades=numCiudades;
	vector=new Punto[ciudades];
	
	// Leer coordenadas con un bucle.
	// Son 2 valores en cada fila
	for(int i = 0; i < numCiudades; i++){
		archi >> x;
		archi >> y;
		vector[i].setX(x);
		vector[i].setY(y);
	}
	CreaMatriz();
	archi.close();
	return true;
}

int Problema::distanciaPrivada(int c1, int c2) const{
	return round(coordenadas(c1).Distancia(coordenadas(c2)));
}
int Problema::distancia(int c1, int c2)const {
	return matriz[c1][c2];
}

Punto Problema::coordenadas(int c1) const {
	return vector[c1];
}

int Problema::tamanio() const{
	return ciudades;
}


int Problema::longitudRecorrido(const Solucion &s) const{
	int sumatoria=0;
	for(int i=0;i<s.Longitud()-1;i++){
		sumatoria+=distancia(s.ciudad(i),s.ciudad(i+1));
	}
	sumatoria+=distancia(s.ciudad(s.Longitud()-1),s.ciudad(0));
	return sumatoria;
}


void Problema::CreaMatriz(){
	int j,i;
	matriz=new int* [ciudades];
	for (i=0; i< ciudades; i++)
		matriz[i] = new int [ciudades];

	for(i=0; i< ciudades; i++){
		for(j=0;j<ciudades;j++){
			matriz[i][j]=distanciaPrivada(i,j);
		}
	}
}
void Problema::Liberar(){
	if(ciudades!=0){	
		delete [] vector;
		vector=0;

		for (int i=0; i< ciudades; i++){
			delete[] matriz[i];
			matriz[i]=0;
		}
		delete[] matriz;
		matriz=0;
		ciudades=0;
	}
}
Problema::~Problema(){	
	Liberar();
}	
ostream& operator<<(ostream &flujo, const Problema &p){
	for(int i=0;i<p.tamanio();i++){
		flujo<<"Ciudad "<<i<<": "<<"\t";
		flujo<<"Coordenada X: "<< p.coordenadas(i).getX()<<"\t";
		flujo<<"Coordenada Y: "<< p.coordenadas(i).getY()<<endl;	
	}
	flujo<<endl;
	return flujo;
}
Problema::Problema(const Problema &otra){		
	ciudades=otra.tamanio();
	vector=new Punto[ciudades];
	for (int i=0; i<ciudades; i++){
		vector[i]=otra.coordenadas(i);
	}
	CreaMatriz();
}

Problema& Problema::operator=(const Problema &p){
	Liberar();
	ciudades=p.tamanio();
	vector=new Punto[ciudades];
	for (int i=0; i<ciudades; i++){
		vector[i]=p.coordenadas(i);
	}
	CreaMatriz(); 
	return *this;
}
