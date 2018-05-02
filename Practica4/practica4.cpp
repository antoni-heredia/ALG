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
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
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

int VecinoMasCercano(int ciudad_inicio, vector<ciudad> &ciudades,vector<vector<double> > &matriz){
	int n=ciudades.size(),longi;
	int minimo=0,j,pos_minimo=0,contador=1,i=ciudad_inicio;
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

  int sumatoria=0;
	for(int i=0;i<ciudades.size()-1;i++){
		longi+=matriz[solu[i]][solu[i+1]];
	}
  matriz[solu[solu.size()-1]][solu[0]];
  return longi;
}
double metodoInserccion(int ciudad_inicio, vector<ciudad> &ciudades,vector<vector<double> > &matriz){
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
  for(int i = 0; i < ciudades.size()-3; i++){

	mejorCoste = INT_MAX;
    for(int j = 0; j < ciudades.size(); j++){

      if(!visitados[ciudades[j].nombre]){

        for (int k = 0; k < solu.size(); k++){

			if( k+1 == solu.size() ){
				distanciaAux = distancia - matriz[solu.front()][solu.back()] + matriz[solu.front()][ciudades[j].nombre] + matriz[solu.back()][ciudades[j].nombre];
			}
			else{
				distanciaAux = distancia - matriz[solu[k]][solu[k+1]] + matriz[solu[k]][ciudades[j].nombre] + matriz[solu[k+1]][ciudades[j].nombre];		
			}

		  	if (distanciaAux < mejorCoste){
				mejorCoste = distanciaAux;
				mejorCiudad = ciudades[j].nombre;
				mejorPos = k+1;
			}
        }
      }
    }

    solu.insert(solu.begin()+mejorPos,mejorCiudad-1);
    visitados[mejorCiudad] = true;
    distancia = mejorCoste;
  }
  return distancia;
}
int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Error en el numero de parametros pasados"<<endl;
    return -1;
  }

  vector<ciudad> ciudades = leerFichero();
  vector<vector<double> > matriz = CreaMatriz(ciudades);

  int longitud = 0, opcion;
  opcion = atoi(argv[1]);
  if(opcion == 1)
    longitud = VecinoMasCercano(1, ciudades,matriz);
  if(opcion == 2)
    longitud = metodoInserccion(1, ciudades,matriz);

  cout<<longitud<<endl;
  return 0;
}
