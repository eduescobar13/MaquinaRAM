#include "UnidadEntrada.hpp" // Incluimos el fichero UnidadEntrada.hpp con las declaracion de nuestra clase.

UnidadEntrada::UnidadEntrada(void): // Constructor por defecto.
    cintaEntrada()
{}

UnidadEntrada::UnidadEntrada(char nombreFichero[]): // Constructor.
    cintaEntrada() 
{
	int elementoFichero; // Variable para ir leyendo los elementos del fichero.
	ifstream fichero; // Variable del tipo ifstream para trabajar con el fichero.
	fichero.open(nombreFichero); // Apertura del fichero.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		while (fichero.eof() == false) { // Mientras no se llegue al final del fichero.	
			fichero >> elementoFichero; // Leemos del fichero.
			insertarElemento(elementoFichero); // Insertamos el elemento en la cinta.
		}
		fichero.close(); // Cierre del fichero.
	}

	cout << cintaEntrada.size() << endl;
	getCintaEntrada().push_back(5);
	cout << cintaEntrada.size() << endl;
}

UnidadEntrada::~UnidadEntrada(void) { // Destructor.

	cintaEntrada.clear(); // Vaciamos por completo la cinta de entrada.
}

void UnidadEntrada::insertarElemento(int elemento) { // Método que inserta un elemento en la cinta.

	cintaEntrada.push_back(elemento);
}

vector<int> UnidadEntrada::getCintaEntrada() { // Método getter del atributo cintaEntrada.

	return cintaEntrada;
}

void UnidadEntrada::setCintaEntrada(vector<int> nuevaCinta) { // Método setter del atributo cintaEntrada.

	cintaEntrada = nuevaCinta;
}

