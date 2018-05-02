/**
@file
@brief Práctica Final Metodología de la Programación. Curso 2016/2017
@date 30/05/2017
@autor Hinojosa Castro, Miguel Ángel
@autor Luque Callejas, David
*/
#include <iostream>
#include <fstream>
#include "Punto.h"
#include "Problema.h"
#include "Solucion.h"
#include "funciones.h"

using namespace std;
int main(int argc,char* argv[]){
	srand(time(NULL));	

	string nombreInstancia,nombreSalida;
	Problema problema;
	int longitudBase,mejorLongitud;
	Solucion solucionBase;
	Solucion mejorSol;
	ifstream lectura;
	switch(argc){
		case 2: 
			lectura.open(argv[1]);
			if (!lectura) {
				cerr << "No se pudo abrir el archivo " << argv[1]<<".\n";
				return false;
			}
			
			//1. supongamos que la primera instancia se llama cxx.tsp. Crear un objeto de la clase Problema
			//a partir del fichero cxx.tsp. Si el fichero no existe, se ignora (saltar al paso 4).
			while(lectura &&!lectura.eof()){
				lectura >> nombreInstancia;
				if(problema.Leer(nombreInstancia.c_str())){
					//2. Obtener la mejor solución posible utilizando la heurística del vecino más cercano para ese problema.
					obtenerMejorSolucion(Problema &problema,Solucion &solucionBase,Solucion &mejorSol,int &longitudBase, int &mejorLongitud);
					//3. Guardar dicha solución en el fichero cxx.sol.
					nombreSalida=nombreInstancia.substr(0,nombreInstancia.length()-4)+".sol";
					guardarSolucion(nombreSalida.c_str(),nombreInstancia.c_str(),problema,mejorSol);
					//4. Volver al paso 1 y repetir para el resto de las instancias indicadas en el fichero de entrada.
				}
			}
			lectura.close();
			
			
		break;
		case 3:
			//1. Crear un objeto de la clase Problema a partir del fichero cxx.tsp. Si el fichero no existe, se muestra un mensaje de error y se analiza la ejecucion.	
			if(problema.Leer(argv[1])){
				obtenerMejorSolucion(Problema &problema,Solucion &solucionBase,Solucion &mejorSol,int &longitudBase, int &mejorLongitud);
			//3. Guardar dicha solución en un fichero cuyo nombre sería el indicado en el segundo argumento.
				guardarSolucion(argv[2],argv[1],problema,mejorSol);
			}else
				cout<<"Error al abrir el fichero "<<argv[1]<<"."<<endl;
			
		break;
		default: cout<<"Error. Número de argumentos no válido."<<endl<<"La sintaxis correcta es: tspFinal listado o bien tspFinal instancia salida."<<endl;
 	}	
}
