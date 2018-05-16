#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct Jugador{
	int id;
	int puntuacion;
};
void FuerzaBruta(const vector<Jugador> & conjunto, int  posActual,int sumaEquipo2, vector<Jugador> & mejorSolucion, vector<Jugador> solucionActual, int sumaEquipo1, int & mejorDiferencia);
int sumaEquipo(vector<Jugador> equipo);
int main(int argc, char* argv[]){

	if(argc != 2){
		cout << "numero de parametros incorrecto" << endl;
		cout << "./fuerzabruta cantidadJugadoress" << endl;
		exit(1);
	}
	vector<Jugador> conjunto;
	int  tamanio;

	tamanio = atoi(argv[1]);



	for(int i = 0; i < tamanio; i++){
		Jugador jug;
		jug.id = i;
		jug.puntuacion = i;

		conjunto.push_back(jug);		
	}
	vector<Jugador> solucion;
	vector<Jugador> solucionActual;
	int sumaTotal = sumaEquipo(conjunto);

	clock_t tini; // Anotamos el tiempo de inicio
	clock_t tfin; // Anotamos el tiempo de finalización
	tini = clock();
	int mejorDiferencia = INT_MAX;
	FuerzaBruta(conjunto,0,sumaTotal,solucion,solucionActual,0,mejorDiferencia);
	tfin = clock();

	//cout << "\t" << (double)(tfin - tini)  << endl;

	int sumaEquipo1 = sumaEquipo(solucion);
	cout << "[";
	cout << solucion[0].id;
	for(int c = 1; c < solucion.size(); c++){
		cout << "," << solucion[c].id ;
	}
	cout << "]" << " Suma equipo 1: " << sumaEquipo1 << endl;

	int sumaEquipo2 = sumaTotal - sumaEquipo1;
	cout << "Suma equipo 2: " << sumaEquipo2 << endl;
	
	return 0;
}
int sumaEquipo(vector<Jugador> equipo){
	int sumaTotal = 0;
	for(int i = 0; i < equipo.size(); i++){
		sumaTotal += equipo[i].puntuacion;		
	}
	return sumaTotal;
}

void FuerzaBruta(const vector<Jugador> & conjunto, int  posActual,int sumaEquipo2, vector<Jugador> & mejorSolucion, vector<Jugador> solucionActual, int sumaEquipo1, int & mejorDiferencia){

	if(posActual == conjunto.size()){
		//Comprobamos si la solucion es buena y si es asi la añadimos a las soluciones
		
		int diferenciaActual = abs(sumaEquipo2-sumaEquipo1);

		if( diferenciaActual < mejorDiferencia){
			cout << "tenemos una buena" << endl;
			mejorSolucion = solucionActual;
			mejorDiferencia = diferenciaActual;
		}
			
	}else{
		int diferenciaActual = abs(sumaEquipo2-sumaEquipo1);

		//while(posActual < conjunto.size() && mejorDiferencia != 0 && diferenciaActual <= mejorDiferencia){
		while(posActual < conjunto.size() && diferenciaActual != 0 ){
		
			
			solucionActual.push_back(conjunto[posActual]);

			int nuevaSumaEquipo2 = sumaEquipo2-conjunto[posActual].puntuacion;
			int nuevaSumaEquipo1 = sumaEquipo1 + conjunto[posActual].puntuacion;
			
			diferenciaActual = abs(nuevaSumaEquipo2-nuevaSumaEquipo1);
			
			
			if(diferenciaActual == 0){
				//cout << "diferencia 0" << endl;
				mejorDiferencia = diferenciaActual;
				mejorSolucion = solucionActual;
			}else{

				posActual++;
				/*
				if(diferenciaActual < mejorDiferencia)
					mejorDiferencia = diferenciaActual;
					
				int mej = mejorDiferencia;
				*/
				FuerzaBruta(conjunto,posActual,nuevaSumaEquipo2,mejorSolucion,solucionActual, nuevaSumaEquipo1, mejorDiferencia);
				//mejorDiferencia = mej;


				if(!solucionActual.empty())
					solucionActual.pop_back();
			}

		}


		diferenciaActual = abs(sumaEquipo2-sumaEquipo1);
		if(diferenciaActual < mejorDiferencia){
			mejorSolucion = solucionActual;
			mejorDiferencia = diferenciaActual;
		}
		
	}
}
