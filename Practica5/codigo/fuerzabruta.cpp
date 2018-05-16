#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Jugador{
	int id;
	int puntuacion;
};
void FuerzaBruta(const vector<Jugador> & conjunto, int  posActual,int sumaOtroEquipo, vector<Jugador>  &mejorSolucion, vector<Jugador> solucionActual);
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
	FuerzaBruta(conjunto,0,sumaTotal,solucion,solucionActual);
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

void FuerzaBruta(const vector<Jugador> & conjunto, int  posActual,int sumaOtroEquipo, vector<Jugador> & mejorSolucion, vector<Jugador> solucionActual){

	if(posActual == conjunto.size()){
		//Comprobamos si la solucion es buena y si es asi la añadimos a las soluciones
		int sumaMejor = sumaEquipo(mejorSolucion);
		int sumaActual = sumaEquipo(solucionActual);
		if(abs(sumaOtroEquipo-sumaActual) < abs(sumaOtroEquipo-sumaMejor))
			mejorSolucion = solucionActual;
			
	}else{
		while(posActual < conjunto.size()){
			solucionActual.push_back(conjunto[posActual]);
			int nuevaSuma = sumaOtroEquipo-conjunto[posActual].puntuacion;
			posActual++;
			FuerzaBruta(conjunto,posActual,nuevaSuma,mejorSolucion,solucionActual);
			solucionActual.pop_back();

		}

		int sumaMejor = sumaEquipo(mejorSolucion);
		int sumaActual = sumaEquipo(solucionActual);

		if(abs(sumaOtroEquipo-sumaActual) < abs(sumaOtroEquipo-sumaMejor))
			mejorSolucion = solucionActual;
		
	}
}
