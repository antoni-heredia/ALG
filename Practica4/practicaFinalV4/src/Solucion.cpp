#include "Solucion.h"
#include <stdlib.h>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;
Solucion::Solucion(){
	numeroCiudades=0;
	Recorrido=0;
}
Solucion::Solucion(int v[], int n){
	ReservarMemoria(n);
	bool escorrecto=vectorCorrecto(v,n);	
	for(int i=0;i<n && escorrecto;i++){
		Recorrido[i]=v[i];	
	}
	numeroCiudades=n;
}
void Solucion::ReservarMemoria(int n){
	Recorrido=new int[n];
}
void Solucion::Liberar(){
	if(Recorrido!=0){
		delete [] Recorrido;
		Recorrido=0;
	}
}

int Solucion::Longitud() const {
	return numeroCiudades;
}

int* Solucion:: GetPuntero() const{
	return Recorrido;
}

int Solucion::ciudad(int pos) const {
	return Recorrido[pos];
}
int Solucion::posicion(int c) const{
	int resultado=-1;
	bool encontrado=false;
	for (int i=0; i< Longitud() && !encontrado; i++){
		if (ciudad(i) == c){
			encontrado=true;
			resultado=i;
		}
	}
	return resultado;
}	
void Solucion::SetIndice(int indice, int elemento){
	Recorrido[indice]=elemento;
}
void Solucion::CambiarTamanio(int n){
	Liberar();
	ReservarMemoria(n);
	numeroCiudades=n;
}
bool vectorCorrecto(int* vector, int n){
	int i=0, j;
	int apariciones_temp=1;
	bool escorrecto=true;
	for (i=0; i<n && apariciones_temp==1;i++){
		apariciones_temp = 0;
		for(j=0; j< n ; j++){
			if (vector[j] == i)
				apariciones_temp++;
			
		}
	}
	if (apariciones_temp != 1){
		escorrecto=false;
	}
	return escorrecto;
}

void IntercambiaComponentes(int* & vector , int n1, int n2){
	int aux=vector[n1];
	vector[n1]=vector[n2];
	vector[n2]=aux;
}

Solucion& Solucion::operator=(const Solucion &c){
	Liberar();
	ReservarMemoria(c.Longitud());
	numeroCiudades = c.Longitud();
	for (int i=0; i<numeroCiudades; i++){
		SetIndice(i, c.ciudad(i));
	} 
	return *this;
}


Solucion::Solucion(int n){
	
	int intercambios=n/2,pos1,pos2;
	ReservarMemoria(n);
	for(int i=0;i<n;i++)
		Recorrido[i]=i;
	for(int j=0;j<intercambios;j++){
		pos1=rand()%n;
		pos2=rand()%n;

		IntercambiaComponentes(Recorrido,pos1,pos2);
	}
	numeroCiudades=n;
}
Solucion::Solucion(const Solucion &otra){	
	ReservarMemoria(numeroCiudades);
	numeroCiudades=otra.Longitud();
	for (int i=0; i<numeroCiudades; i++){
		SetIndice(i, otra.ciudad(i));
	}
}

Solucion::~Solucion(){
	Liberar();
	numeroCiudades=0;
}

std::string Solucion::To_string(){ // devuelve el recorrido como un string separando los datos por comas
	std::string Resultado= "(";
	for (int i=0; i<Longitud(); i++){
		Resultado+= std::to_string(ciudad(i));
		if (i != Longitud()-1){
			Resultado+= ",";
		}
	}
	Resultado+= ")";
	return Resultado;
}
ostream& operator<<(ostream &flujo, const Solucion &s){
	for(int i=0;i<s.Longitud();i++){
		flujo<<s.ciudad(i)<<", ";	
	}
	flujo<<endl;
	return flujo;
}
