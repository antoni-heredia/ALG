/**
 * Clase Problema. Clase utilizada para representar un problema del Viajero Comerciante. 
 */
#ifndef _PROBLEMA_
#define _PROBLEMA_

#include "Solucion.h"
#include "Punto.h"
class Problema {
	private:
		int** matriz;/**< Matriz de enteros que guarda la distancias precalculadas entre las distintas ciudades del objeto Problema. */
		int ciudades;/**< Dato miembro que indica el número de ciudades de nuestro objeto Problema. */
		Punto* vector;/**< Array de objetos Punto que almacena las ciudades de nuestro objeto Problema. */
		//!Método Privado Auxiliar.
			/*!
				Calcula la distancia entre dos ciudades.
				* \param c1 Ciudad 1.
				* \param c2 Ciudad 2.
				* \return Retorna la distancia heurística como entero entre la Ciudad 1 y la Ciudad 2.
		   
		    	*/ 
		int distanciaPrivada(int c1, int c2)const ;
		//!Método Privado Auxiliar.
			/*!
				Libera toda la memoria utilizada por los datos miembros dinámicos.
		   
		    	*/ 
		void Liberar();

	
	public:
		//! Constructor por defecto.
		    	/*!
				Construye un objeto Problema por defecto.
		   
		    	*/
		Problema();
		
		//! Método.
		    	/*!
				Recibe el nombre de un fichero y lee una instancia de problema desde el disco. El método devolverá un booleano indicando si la lectura fue correcta.
				* \param nombreFichero Fichero que se utiliza para generar el objeto Problema.
				* \return Retorna un booleano indicando si la lectura fue correcta.
		   
		    	*/
		bool Leer(const char* nombreFichero);
		
		//!Método Get.
			/*!
				Devuelve la distancia entre la Ciudad 1 y la Ciudad 2. Utiliza los datos precalculados de la matriz.
				* \param c1 Ciudad 1.
				* \param c2 Ciudad 2.
				* \return Retorna la distancia heurística como entero entre la Ciudad 1 y la Ciudad 2.
		   
		    	*/ 
		int distancia (int c1, int c2) const ;
		//!Método Get.
			/*!
				Devuelve las coordenadas de la ciudad c1.
				* \param c1 Posición del vector que se va a retornar.
				* \return Retorna la distancia heurística como entero entre la Ciudad 1 y la Ciudad 2.
		   
		    	*/ 
		Punto coordenadas(int c1) const ;
		//!Método Get.
			/*!
				Devuelve el número de ciudades de nuestro objeto Problema.
				* \return Retorna el dato miembro ciudades.
		   
		    	*/ 
		int tamanio() const;
		//!Método Público Auxiliar.
			/*!
				Genera el dato miembro matriz del objeto Problema.
		   
		    	*/ 
		void CreaMatriz();
		//!Método.
			/*!
				Calcula la longitud del recorrido para el orden de las ciudades indicadas en un objeto Solución.
				* \param s Objeto Solución con el orden que hay que seguir para calcular la longitud.
				* \return Retorna la longitud total del recorrido.
		   
		    	*/ 
		int longitudRecorrido(const Solucion & s) const;
		//! Constructor Copia.
		    	/*!
				Construye un objeto Problema a partir de otro objeto del mismo tipo.
				* \param otro Objeto Problema que se utiliza para copiar.
		   
		    	*/	
		Problema(const Problema &otro);
		//!Método Destructor.
			/*!
				Libera la memoria usada por el vector dinámico y la matriz dinámica, además le asigna al dato miembro numeroCiudades el valor 0.
		 
		   	*/
		~Problema();
		Problema& operator=(const Problema &p);
};
//!Sobrecarga del operador <<.
	/*!
		Sobrecarga el operador << de la clase Problema.
		* \param flujo Dato tipo ostream que se utiliza en la función.
		* \param s Objeto Problema que queremos mostrar.
		* \return Retorna la referencia a nuestro objeto (this). Esto permite concatenar varios << (Ej. cout<<problema1<<problema2).


	*/
std::ostream& operator<<(std::ostream& flujo,const Problema& p);
#endif
