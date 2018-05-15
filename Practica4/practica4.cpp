#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <stdlib.h>
using namespace std;
struct punto{
  double x;
  double y;
};
struct ciudad{
  int nombre;
  punto coordenadas;
};

double distancia(punto a,punto b){
	return round(sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)));
}
vector<vector<double> > CreaMatriz(const vector<ciudad> &ciudades){
	int j,i;
  vector<vector<double> > matriz(ciudades.size(), vector<double> (ciudades.size()));

	for(i=0; i< ciudades.size(); i++)
		for(j=0;j< ciudades.size();j++)
			matriz[i][j]=distancia(ciudades[i].coordenadas,ciudades[j].coordenadas);
  return matriz;
}

vector<ciudad> leerFichero(){
  int numCiudades;
	double z;
	string cabecera;

	cin >> cabecera;
	cin >> numCiudades;

  vector<ciudad> ciudades(numCiudades);

	for(int i = 0; i < numCiudades; i++){
		cin >> ciudades[i].nombre;
		cin >> ciudades[i].coordenadas.x;
		cin >> ciudades[i].coordenadas.y;
	}

  return ciudades;
}

pair<vector<int>,double>VecinoMasCercano(int ciudad_inicio, const vector<ciudad> &ciudades, const vector<vector<double> > &matriz){
	int n=ciudades.size();
  double longi;
  double minimo = 0;
	int j,pos_minimo=0,contador=1,i=ciudad_inicio;
  vector<bool> aux(ciudades.size(),false);
  vector<int> solu(ciudades.size());


	aux[ciudad_inicio]=true;
	solu[0]=ciudad_inicio;
	while(contador<n){
		minimo=INT_MAX;

		for(j=0;j<n;j++){
			if(!aux[j] && (matriz[i][j]<minimo) && j!=i) {
				minimo=matriz[i][j];
				pos_minimo=j;
			}
		}
		i=pos_minimo;
		aux[i]=true;
		solu[contador]=i;
		contador++;
	}

	for(int i=0;i<ciudades.size()-1;i++){
		longi+=matriz[solu[i]][solu[i+1]];
	}
  longi += matriz[solu[solu.size()-1]][solu[0]];

  return pair<vector<int>,double>(solu, longi);;
}

double coste( const vector<int> Solucion,const vector<vector<double> > &matriz){
  double coste = 0;
  for(unsigned int i = 0; i < Solucion.size()-1; ++i)
    coste += matriz[Solucion[i]][Solucion[i+1]];

  coste += matriz[Solucion.front()][Solucion.back()];

  return coste;
}

pair<vector<int>,double> metodoInserccion(const vector<ciudad> &ciudades, const vector<vector<double> > &matriz){
  double norte=0,sur=INT_MAX,este = 0;
  int ciudadNorte=0,ciudadEste=0,ciudadSur=0;

  vector<bool> visitados(ciudades.size()+1,false);

  for (int i = 0;i < ciudades.size(); i++){
    if (ciudades[i].coordenadas.y > norte && !visitados[i]){
      norte = ciudades[i].coordenadas.y;
      visitados[ciudadNorte] = false;
      ciudadNorte = i;
      visitados[ciudadNorte] = true;
    }
    if (ciudades[i].coordenadas.y < sur && !visitados[i]){
      sur = ciudades[i].coordenadas.y;
      visitados[ciudadSur] = false;
      ciudadSur = i;
      visitados[ciudadSur] = true;
    }
    if (ciudades[i].coordenadas.x > este && !visitados[i]){
      este = ciudades[i].coordenadas.x;
      visitados[ciudadEste] = false;
      ciudadEste = i;
      visitados[ciudadEste] = true;
    }

  }

  vector<int> solu;
  solu.push_back(ciudadSur);
  solu.push_back(ciudadNorte);
  solu.push_back(ciudadEste);

  double distancia = matriz[ciudadSur][ciudadNorte] + matriz[ciudadNorte][ciudadEste] + matriz[ciudadEste][ciudadSur];
  double distanciaAux = 0;
  double mejorCoste = INT_MAX;
  int mejorCiudad;
  int mejorPos;
  //Numero de pasadas que se necesitan para meter el resto de ciudades que quedan(al tener ya tres para el triangulo)
  for(int i = 0; i < ciudades.size()-3; i++){

	   mejorCoste = INT_MAX;
     //Vamos visitaqndo todas las ciudades
    for(int j = 0; j < ciudades.size(); j++){
      //Se mira si ya esta visitada
      if(!visitados[j]){
        //Se recorren las soluciones para ver entre que dos puntos es menor la distancia al introducirlo.
        for (int k = 0; k < solu.size(); k++){
            //En el caso de que sea entre el primero del vector y el ultimo
      			if( k+1 == solu.size() ){
      				distanciaAux = distancia - matriz[solu.front()][solu.back()] + matriz[solu.front()][j] + matriz[solu.back()][j];
            //Si no es entre la primera y la ultima
      			}else{
      				distanciaAux = distancia - matriz[solu[k]][solu[k+1]] + matriz[solu[k]][j] + matriz[solu[k+1]][j];
      			}
            //Se mira si el coste de esta ciudad es menor que el de la anteriro y si es asi se pone como la mejor opcion hasta el momento
    		  	if (distanciaAux < mejorCoste){
    				mejorCoste = distanciaAux;
    				mejorCiudad = j;
    				mejorPos = k+1;
    			}
        }
      }
    }
    //Se inserta la que obtiene una mejor distancia en la posicion en la que se obtuvo
    solu.insert(solu.begin()+mejorPos,mejorCiudad);
    //Se marca la ciudad como leida para no utilizarla en la siguientes pasadas
    visitados[mejorCiudad] = true;
    distancia = mejorCoste;
  }
  return pair<vector<int>,double>(solu, distancia);;
}


//Método para calcular un recorrido para el viajante de comercio basado en el intercambio de aristas 2-opt:
pair<vector<int>,double> ViajanteDeComercioIntercambio(const vector<ciudad> & candidatos, const vector<vector<double> > &matriz){

  int aux;
  unsigned int pos;
  vector<int> S_aux, S;
  double coste_aux;
  bool mejor_enc, cambio_realizado = true;

  //Considerar una solución inicial:
  //En este caso utilizaremos el método del vecino más cercano:
  auto SolInicio = metodoInserccion(candidatos, matriz);
  S = SolInicio.first;
  double mejor_coste = SolInicio.second;

  while(cambio_realizado){
    cambio_realizado = false;
    for(unsigned int i = 0; i < S.size()-1; ++i){
      mejor_enc = false;
      //Examinar los movimientos 2-opt que incluyan la arista de i a su sucesor en el ciclo:
      for(unsigned int j = i + 1; j < S.size(); ++j){
        S_aux = S;
        //Intercambiar
        aux = S_aux[i];
        S_aux[i] = S_aux[j];
        S_aux[j] = aux;
        //Calcular el coste de la nueva solución:
        coste_aux = coste(S_aux, matriz);
        //Si es mejor guardo:
        if(coste_aux < mejor_coste){
          mejor_enc = true;
          pos = j;
          mejor_coste = coste_aux;
        }
      }
      //Si se ha encontrado algo mejor, intercamio:
      if(mejor_enc){
        cambio_realizado = true;
        aux = S[i];
        S[i] = S[pos];
        S[pos] = aux;
      }
    }
  }
  return pair<vector<int>, double>(S, mejor_coste);
}


int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Error en el numero de parametros pasados"<<endl;
    return -1;
  }

  vector<ciudad> ciudades = leerFichero();
  vector<vector<double> > matriz = CreaMatriz(ciudades);

  int opcion;
  opcion = atoi(argv[1]);

  pair<vector<int>,double> resultado;

  if(opcion == 1)
    resultado = VecinoMasCercano(1, ciudades,matriz);
  if(opcion == 2)
    resultado = metodoInserccion(ciudades,matriz);
  if(opcion == 3)
    resultado =  ViajanteDeComercioIntercambio(ciudades,matriz);


  cout << "Dimension: " << ciudades.size() << endl;
  for(int i = 0; i < resultado.first.size(); i++){
    cout << resultado.first[i]+1 << "\n";
  }



  return 0;
}
