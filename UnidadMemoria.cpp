#include "UnidadMemoria.hpp" // Incluimos el fichero UnidadMemoria.hpp con las declaración de nuestra clase.

UnidadMemoria::UnidadMemoria(void): // Constructor.
    memoriaDato(),
    memoriaPrograma()
{}

UnidadMemoria::UnidadMemoria(char nombreFichero[]): // Constructor.
    memoriaDato(),
    memoriaPrograma()
{
	string elementoFichero; // Variable para ir leyendo los elementos del fichero.
	ifstream fichero; // Variable del tipo ifstream para trabajar con el fichero.
	fichero.open(nombreFichero); // Apertura del fichero.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		while (fichero.eof() == false) { // Mientras no se llegue al final del fichero.	
			fichero >> elementoFichero; // Leemos del fichero.
			insertarInstruccion(elementoFichero); // Insertamos el elemento en la cinta.
		}
		fichero.close(); // Cierre del fichero.
	}
}

UnidadMemoria::~UnidadMemoria(void) { // Destructor.

	memoriaDato.clear(); // Vaciamos por completo la memoria de datos.
	memoriaPrograma.clear(); // Vaciamos por completo la memoria de programas.
}

void UnidadMemoria::insertarDato(int dato) { // Método que inserta un dato en la memoria de datos.

	memoriaDato.push_back(dato);
}

void UnidadMemoria::insertarInstruccion(string instruccion) { // Método que inserta una instrucción en la memoria de programas.

	memoriaPrograma.push_back(instruccion);
}

//-----------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

vector<int> UnidadMemoria::getMemoriaDato() { // Método getter del atributo memoriaDato.

	return memoriaDato;
}

void UnidadMemoria::setMemoriaDato(vector<int> memoriaDato) { // Método setter del atributo memoriaDato.

	this->memoriaDato = memoriaDato;
}

vector<string> UnidadMemoria::getMemoriaPrograma() { // Método getter del atributo memoriaPrograma.

	return memoriaPrograma;
}

void UnidadMemoria::setMemoriaPrograma(vector<string> memoriaPrograma) { // Método setter del atributo memoriaPrograma.

	this->memoriaPrograma = memoriaPrograma;
}


