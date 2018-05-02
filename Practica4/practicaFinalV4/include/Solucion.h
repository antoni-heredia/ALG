/**
 * Clase Solucion. Esta clase se utiliza para almacenar una solución válida que nos permita interactuar con nuestra clase principal, Problema. 
 */
#ifndef _SOLUCION_
#define _SOLUCION_

#include <string>
#include <cstring>
#include <iostream>


class Solucion{
	private:
		int * Recorrido;/**< Vector Dinámico de enteros que guarda el recorrido del objeto solución. */
		int numeroCiudades;/**< Entero que guarda el número de ciudades del objeto solución.*/
		
		//!Método Privado Auxiliar.
			/*!
				Libera la memoria del vector dinámico miembro y lo inicializa a 0.		   
		    	*/ 
		void Liberar();
		//!Método Privado Auxiliar.
			/*!
				Reserva la memoria para el vector dińamico miembro indicada por el argumento n.
				* \param n Tamaño que hay que reservar en memoria.
		   
		    	*/ 
		void ReservarMemoria(int n);
		
	public:
		//! Constructor por defecto.
		    	/*!
				Construye una solución a partir del vector y lo inicializa con los valores por defecto.
		    	*/
		Solucion();
		//! Constructor.
		    	/*!
				Construye una solución a partir del vector v.
				* \param v Vector de enteros que se usará para crear el objeto Solución.
				* \param n Entero que permite indicar el número de ciudades de nuestro objeto.
		   
		    	*/
		Solucion(int v[], int n);
		//! Constructor.
		    	/*!
				Construye una solución de manera aleatoria.
				* \param n Entero que indica el número de ciudades que se van a generar aleatoriamente.
		   
		   	 */
		Solucion(int n);
		//! Constructor Copia.
	    		/*!
				Construye una solución como copia de otra.
				* \param otra Objeto Solución que queremos copiar.
		   
	    		*/
		Solucion(const Solucion &otra) ;
		//!Método Set.
			/*!
				Copia un nuevo valor en una posición del vector Recorrido.
				* \param indice Posición del vector que se va a sobreescribir.
				* \param elemento Valor nuevo.
		   
		    */
		void SetIndice(int indice, int elemento);
		//!Método Get.
			/*!
				Devuelve la posición donde se encuentra una determinada ciudad en el vector Recorrido.
				* \param c Ciudad dada para obtener su posición.
				* \return Retorna la posición de la ciudad. -1 si no se encuentra.
		   
		    */
		int posicion(int c) const;
		//!Método Get.
			/*!
				Devuelve la posición de la memoria donde está nuestro vector dinámico Recorrido.
				* \return Retorna la posición de inicio del vector Recorrido.
		   
		    */
		int* GetPuntero()const ;
		//!Método Get.
			/*!
				Devuelve el número de ciudades que tiene nuestro objeto Solución.
				* \return Retorna el dato miembro del objeto, numeroCiudades.
		   
		    */
		int Longitud() const;
		//!Método Destructor.
			/*!
				Libera la memoria usada por el vector dinámico y le asigna al dato miembro numeroCiudades el valor 0.
		   
		    */
		~Solucion(); 
		//!Sobrecarga del operador =.
			/*!
				Sobrecarga el operador = de la clase Solución.
				* \param c Objeto Solucion que usaremos para la Solución.
				* \return Retorna la referencia a nuestro objeto (this). Esto permite concatenar varios = (Ej. sol1=sol2=sol3).

		   
		    */
		Solucion& operator=(const Solucion& c);
		//!Método Get.
			/*!
				Devuelve la ciudad que ocupa la posición dada.
				* \param pos Posición del vector que 
				* \return Retorna el dato miembro del objeto, numeroCiudades.
		   
		    */
		int ciudad(int pos) const ;
		//!Método Público Auxiliar.
			/*!
				Devuelve el recorrido como un string separando los datos por comas.
				* \return Retorna el un string con el resultado.
		   
		    */ 
		std::string To_string() ;
		void CambiarTamanio(int n);
};

//!Función auxiliar de la clase Solución.
	/*!
		Verifica si los valores almacenados representan una permutación.
		* \param vector Puntero al array al que queremos comprobar los datos.
		* \param n Número de ciudades que tiene el vector pasado.
		* \return Retorna true si el vector pasado presenta una permutación y false si no es así.

   
    	*/
bool vectorCorrecto(int* vector, int n);
//!Función auxiliar de la clase Solución.
	/*!
		Intercambia en un array de enteros la posición de dos elementos del mismo.
		* \param vector Puntero al array al que queremos intercambiar los datos.
		* \param n1 Entero que corresponde a la ciudad 1.
		* \param n2 Entero que corresponde a la ciudad 2.

   
    	*/
void IntercambiaComponentes(int* &vector, int n1, int n2);
//!Sobrecarga del operador <<.
	/*!
		Sobrecarga el operador << de la clase Solución.
		* \param flujo Dato tipo ostream que se utiliza en la función.
		* \param s Objeto Solución que queremos mostrar.
		* \return Retorna la referencia a nuestro objeto (this). Esto permite concatenar varios << (Ej. cout<<sol1<<sol2).


	*/
std::ostream& operator<<(std::ostream& flujo,const Solucion& s);
#endif
