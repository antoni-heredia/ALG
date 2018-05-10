#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;


void BackTraking(const vector<int> & conjunto, int sumaObjetivo, int suma, int  posActual, vector<int>  solucion, vector<vector<int>> &soluciones);

int main(int argc, char* argv[]){

	if(argc != 3){
		cout << "numero de parametros incorrecto" << endl;
		cout << "./fuerzabruta sumaObjetivo tamañoConjuntoInicial" << endl;
		exit(1);
	}
	vector<int> conjunto;
	int sumaObjetivo, tamanio;

	sumaObjetivo = atoi(argv[1]);
	tamanio = atoi(argv[2]);

	

	for(int i = 0; i < tamanio; i++)
		conjunto.push_back(i+1);
	
	vector<vector<int>> soluciones;
	vector<int> solucion;
	
	clock_t tini; // Anotamos el tiempo de inicio
	clock_t tfin; // Anotamos el tiempo de finalización
	tini = clock();
	BackTraking(conjunto,sumaObjetivo,0,0,solucion,soluciones);
	tfin = clock();
	cout << sumaObjetivo << "\t" << (double)(tfin - tini)  << endl;
	
	
	//Descomentar para ver la lista de resultados
	
	for(int f=0; f < soluciones.size(); f++){
		cout << "[";
		cout << soluciones[f][0];
		for(int c = 1; c < soluciones[f].size(); c++){
			cout << "," << soluciones[f][c] ;
		}
		cout << "]" << endl;
	}
	return 0;
}

void BackTraking(const vector<int> & conjunto, int sumaObjetivo, int suma, int  posActual, vector<int>  solucion, vector<vector<int>> &soluciones){

	if(posActual == conjunto.size()){
		//Comprobamos si la solucion es buena y si es asi la añadimos a las soluciones
		if(suma == sumaObjetivo)
			soluciones.push_back(solucion);
			
	}else{
		while(posActual < conjunto.size() && conjunto[posActual] <= sumaObjetivo){

			solucion.push_back(conjunto[posActual]);
			//hacemos la suma parcial
            suma+=conjunto[posActual];

			posActual++;
			BackTraking(conjunto,sumaObjetivo,suma,posActual,solucion,soluciones);

			//Vuelta atras
			suma-=conjunto[posActual-1];
			solucion.pop_back();

		}

		//Comprobamos si para el ultimo nodo de esta rama la solucion es buena
		if(suma == sumaObjetivo)
			soluciones.push_back(solucion);
		
	}
}
