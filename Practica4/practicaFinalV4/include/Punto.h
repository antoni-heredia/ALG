/**
 * Clase Punto. Clase utilizada para representar puntos en 2D. 
 */
#ifndef _PUNTO_
#define _PUNTO_

#include <string>
#include <cstring>
class Punto{
	private:
		double x;/**< Dato miembro que indica la coordenada x del objeto Punto. */
		double y;/**< Dato miembro que indica la coordenada y del objeto Punto. */
	public:
		//! Constructor.
		    	/*!
				Construye un objeto Punto y lo inicializa con los valores por defecto.
		   
		    	*/
		Punto();
		//! Constructor.
		    	/*!
				Construye un objeto Punto y lo inicializa con los valores pasados.
				* \param x Coordenada x del objeto Punto a crear.
				* \param y Coordenada y del objeto Punto a crear.
		   
		    	*/
		Punto(double x,double y);
		//!Método Get.
			/*!
				Devuelve la coordenada x del objeto Punto.
				* \return Retorna el dato miembro que representa a la coordenada x.
		   
		    */
		double getX();
		//!Método Get.
			/*!
				Devuelve la coordenada y del objeto Punto.
				* \return Retorna el dato miembro que representa a la coordenada y.
		   
		    	*/
		double getY();
		//!Método Set.
			/*!
				Copia un nuevo valor al dato miembro x.
				* \param x Valor nuevo que queremos dar a la coordenada x del objeto Punto.
		   
		   	 */
		void setX(double x);
		//!Método Set.
			/*!
				Copia un nuevo valor al dato miembro y.
				* \param x Valor nuevo que queremos dar a la coordenada y del objeto Punto.
		   
		    	*/
		void setY(double y);
		//!Método Público Auxiliar.
			/*!
				Devuelve el objeto Punto como un string separando los datos por comas.
				* \return Retorna el un string con el resultado.
		   
		    */ 
		std::string ToString();
		//!Método Público Auxiliar.
			/*!
				Devuelve la distancia entre dos objetos Punto.
				* \return Retorna la distancia heurística entre dos objetos Punto.
		   
		    	*/ 
		double Distancia(Punto b);
};

#endif
