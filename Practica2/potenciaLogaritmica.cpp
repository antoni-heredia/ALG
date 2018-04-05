#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
long double calcularPotencia(double base, int exponente ){
  if (exponente==0) return 1;
  if ((exponente & 1) != 0)//  odd
    return base * calcularPotencia(base*base, exponente>>1);
  else
    return calcularPotencia(base*base, exponente>>1);

}
int main(int argc, char * argv[])
{

  if (argc != 2){
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
  }

  double base = 1.0000001; long double resultado;
  double exponente = atoi(argv[1]);

  clock_t tini;    // Anotamos el tiempo de inicio
	clock_t tfin;    // Anotamos el tiempo de finalización

	tini=clock();

  resultado = calcularPotencia(base, exponente);
  tfin=clock();
  cout << exponente << "\t" << (double)( tfin-tini ) / CLOCKS_PER_SEC << endl;


  return 0;
};
