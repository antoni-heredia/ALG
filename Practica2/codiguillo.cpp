#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
long double calcularPotencia(long double base, int exponente ){
	if ( exponente == 0)
		return 1;
	long double resultado = calcularPotencia(base, exponente/2);
	if (exponente & 1)
		return resultado * resultado * base;
	else
		return resultado * resultado ;

}
int main(int argc, char * argv[])
{

  if (argc != 2){
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
  }

	long double base = 0.9999999999999999999999999999999;
	long double resultado;
	double exponente = atoi(argv[1]);

  clock_t tini;    // Anotamos el tiempo de inicio
	clock_t tfin;    // Anotamos el tiempo de finalización

	tini=clock();

  resultado = calcularPotencia(base, exponente);
  tfin=clock();
  cout << exponente << "\t" << (double)( tfin-tini )<< endl;
	cout << resultado<< endl;
  return 0;
};
