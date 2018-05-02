#include "Problema.h"
#include "Solucion.h"
#include "funciones.h"
#include <iostream>
#include <fstream>
int menor(int a,int b){
	return (a>b)? b:a;
}
void crearVectorAux(bool* v,int n){
	for(int i=0;i<n;i++)
		v[i]=false;
	
}

void VecinoMasCercano(const Problema & p, int inicio, Solucion & sol, int & longi){
	int n=p.tamanio();
	int minimo=0,j,pos_minimo=0,contador=1,i=inicio;
	assert(n>0);
	bool* aux;
	aux=new bool[n];

	crearVectorAux(aux,n);
	int* solu;
	solu=new int[n];
	
	aux[inicio]=true;
	solu[0]=inicio;
	while(contador<n){
		minimo=INT_MAX;
		
		for(j=0;j<n;j++){
			//cout <<i<< " "<<j<<"\n";
			if(!aux[j] && (p.distancia(i,j)<minimo) && j!=i) {			
				minimo=p.distancia(i,j);
				pos_minimo=j;		
			}			
		}
		i=pos_minimo;
		aux[i]=true;
		solu[contador]=i;
		contador++;
	}		
	for(int h=0;h<n;h++)
		sol.SetIndice(h,solu[h]);
	longi=p.longitudRecorrido(sol);
	
	delete [] solu;
	delete [] aux;
}
bool guardarSolucion(const char * nombre, const char * cxx, const Problema & p, const Solucion & s){
	int n=p.tamanio(),i;
	int longitud=p.longitudRecorrido(s);
	ofstream fs;
	string instancia(cxx);
	fs.open(nombre);
	if (!fs) {
		cerr << "No se pudo abrir el archivo " << nombre<<".\n";
			return false;
	}
	fs << "NOMBRE DE LA INSTANCIA: "<<instancia.substr(0,instancia.length()-4)<<endl;
	fs << "TAMANIO: "<<n<<endl;
	fs << "LONGITUD: "<<longitud<<endl;
	fs << "ORDEN: "<<endl;
	fs << s<<endl;
	fs <<  "COORDENADAS: "<<endl;
	for(i=0;i<n;i++){
		fs << p.coordenadas(s.ciudad(i)).getX()<<", "<<p.coordenadas(s.ciudad(i)).getY()<<endl;
	}	
	fs.close();

	return true;
}
void obtenerMejorSolucion(Problema &problema,Solucion &solucionBase,Solucion &mejorSol,int &longitudBase, int &mejorLongitud){
	int n=problema.tamanio();
	solucionBase.CambiarTamanio(n);
	mejorSol.CambiarTamanio(n);

	VecinoMasCercano(problema,0, solucionBase, longitudBase);
	mejorLongitud=longitudBase;
	mejorSol=solucionBase;

	for(i=1;i<n;i++){
		VecinoMasCercano(problema,i, solucionBase, longitudBase);
		if(longitudBase<mejorLongitud){
			mejorLongitud=longitudBase;
			mejorSol=solucionBase;
		}
	}
}
