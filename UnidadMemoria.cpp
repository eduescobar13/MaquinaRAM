#include "UnidadMemoria.hpp" // Incluimos el fichero UnidadMemoria.hpp con las declaración de nuestra clase.

UnidadMemoria::UnidadMemoria(void): // Constructor.
    memoriaDato(),
    memoriaPrograma()
{}

UnidadMemoria::UnidadMemoria(char nombreFichero[]): // Constructor.
    memoriaDato(),
    memoriaPrograma()
{
	ifstream fichero; // Variable del tipo ifstream para trabajar con el fichero.
	fichero.open(nombreFichero); // Apertura del fichero.
	char lineaFichero[50]; // Variable para almacenar las lineas del fichero.
	string elementoFichero; // Variable para almacenar las lineas del fichero.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		fichero.getline(lineaFichero, 100); // Leemos las linea del fichero, almacenando el contenido en la variable lineaFichero.
		while (fichero.eof() == false) { // Mientras no se llegue al final del fichero.	
			if(lineaFichero[0] == '#') { // Si el primer carácter es una #, omitimos (comentario).
				fichero.getline(lineaFichero, 100); // Leemos las linea del fichero, almacenando el contenido en la variable lineaFichero.
			}
			else {
				fichero >> elementoFichero;
				cout << elementoFichero.back() << endl;
			}
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

void UnidadMemoria::insertarInstruccion(instruccion instruccion) { // Método que inserta una instrucción en la memoria de programas.

	memoriaPrograma.push_back(instruccion);
}

void UnidadMemoria::mostrarMemoriaDato() { // Método que muestra por pantalla la memoria de datos.

	for(int i = 0; i < memoriaDato.size(); i++) {
		cout << memoriaDato[i] << endl;
		cout << "--------------" << endl;
	}
	cout << endl;
}

void UnidadMemoria::mostrarMemoriaPrograma() { // Método que muestra por pantalla la memoria de programas.

	for(int i = 0; i < memoriaPrograma.size(); i++) {
		cout << memoriaPrograma[i].operacion << " " << memoriaPrograma[i].operando << endl;
		cout << "--------------" << endl;
	}
	cout << endl;
}

//-----------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

vector<int> UnidadMemoria::getMemoriaDato() { // Método getter del atributo memoriaDato.

	return memoriaDato;
}

void UnidadMemoria::setMemoriaDato(vector<int> memoriaDato) { // Método setter del atributo memoriaDato.

	this->memoriaDato = memoriaDato;
}

vector<instruccion> UnidadMemoria::getMemoriaPrograma() { // Método getter del atributo memoriaPrograma.

	return memoriaPrograma;
}

void UnidadMemoria::setMemoriaPrograma(vector<instruccion> memoriaPrograma) { // Método setter del atributo memoriaPrograma.

	this->memoriaPrograma = memoriaPrograma;
}


