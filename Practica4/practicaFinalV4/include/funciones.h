/**
 * Funciones externas.
 */
#ifndef _FUNCIONES_
#define _FUNCIONES_
#include <climits>
#include <iostream>
#include <assert.h>
#include <Solucion.h>
#include <Problema.h>
using namespace std;

//!Función Auxiliar 
	/*!
		Calcula el menor entre dos enteros.
		* \param a Entero 1.
		* \param b Entero 2.
		* \return Retorna Entero 1 si es menor a Entero 2 o Entero 2 si es menor a Entero 1.

	*/ 
int menor(int a,int b);
//!Función Auxiliar
	/*!
		Crea un vector de booleanos e inicializa todos sus valores a false.
		* \param v Puntero al vector que vamos a inicializar.
		* \param n Tamaño del vector v.

	*/ 
void crearVectorAux(bool* v,int n);
//!Función Vecino Más Cercano
	/*!
		Dada un objeto Solución vacía y una posición de inicio se obtiene la "solución" de distancia menor del objeto Problema.
		* \param p Objeto Problema que contiene el problema que queremos calcular.
		* \param inicio Posición del vector por cual vamos a empezar.
		* \param sol Objeto Solucion que vamos a sobreescribir con la solución más óptima.
		* \param longi Entero que contendrá la longitud menor calculada.

	*/ 
void VecinoMasCercano(const Problema & p, int inicio, Solucion & sol, int & longi);
//!Función Guardar Solución
	/*!
		La función guardará en el fichero nombre, la solución s al problema p correspondiente a la instancia leída desde el fichero cxx.
		Devolverá true si se ha guardado con éxito o false si ha habido algún error.
		* \param nombre Fichero donde se va a guardar el resultado.
		* \param cxx Instancia que va a ser leída.
		* \param p Objeto Problema correspondiente a la instancia leída.
		* \param s Objeto Solución correspondiente a la mejor solución del problema.
		* \return Devolverá true si se ha guardado con éxito o false si ha habido algún error.

	*/ 
bool guardarSolucion(const char * nombre, const char * cxx, const Problema & p, const Solucion & s);
void obtenerMejorSolucion(Problema &problema,Solucion &solucionBase,Solucion &mejorSol,int &longitudBase, int &mejorLongitud);
#endif


