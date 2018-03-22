#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
int maximo(int *vector,int inicio,  int fin);
int maximolineal(int *vector,int inicio,  int fin);
int UMBRAL;

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		cerr << "Formato " << argv[0] << " <num_elem> <umbral" << endl;
		return -1;
	}

	int n = atoi(argv[1]);
	UMBRAL = atoi(argv[2]);
	int *T = new int[n];
	assert(T);

	srandom(time(0));

	for (int i = 0; i < n; i++)
	{
		T[i] = random();
	}
	

	clock_t tini; // Anotamos el tiempo de inicio
	clock_t tfin; // Anotamos el tiempo de finalización

	tini = clock();

	maximo(T,0, n);

	tfin = clock();

	cout << n << "\t" << (double)(tfin - tini) / CLOCKS_PER_SEC << endl;
	delete[] T;

	return 0;
};

int maximo(int *vector,int inicio,  int fin)
{
	int diferencia =  fin - inicio;
	if(diferencia > UMBRAL){
		int mitad = inicio+(diferencia/2);
		int primera_mitad = maximo(vector, inicio,mitad);
		int segunda_mitad = maximo(vector, mitad,fin);
		if(primera_mitad>segunda_mitad)
			return primera_mitad;
		else
			return segunda_mitad;
		
	}else{
		return maximolineal(vector,inicio, fin);
	}
}

int maximolineal(int *vector,int inicio,  int fin)
{
	int pos = inicio;
	int max = vector[pos];
	for (int i = inicio+1; i < fin; i++)
	{
		if (vector[i] > max)
		{
			max = vector[i];
			pos = i;
		}
	}
	return max;
}
