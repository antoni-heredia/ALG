#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

int maximo(int *vector, int tam)
{
	int pos = 0;
	int max = vector[pos];
	for (int i = 1; i < tam; i++)
	{
		if (vector[i] > max)
		{
			max = vector[i];
			pos = i;
		}
	}
	return max;
}

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		cerr << "Formato " << argv[0] << " <num_elem>" << endl;
		return -1;
	}

	int n = atoi(argv[1]);

	int *T = new int[n];
	assert(T);

	srandom(time(0));

	for (int i = 0; i < n; i++)
	{
		T[i] = random();
	}
	
	int pos;	  //Declaro fuera para no afectar a la medicion de tiempo

	clock_t tini; // Anotamos el tiempo de inicio
	clock_t tfin; // Anotamos el tiempo de finalización

	tini = clock();

	maximo(T, n);

	tfin = clock();

	cout << n << "\t" << (double)(tfin - tini) / CLOCKS_PER_SEC << endl;
	delete[] T;

	return 0;
};
