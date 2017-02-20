#include "UnidadMemoria.hpp" // Incluimos el fichero UnidadMemoria.hpp con las declaración de nuestra clase.

UnidadMemoria::UnidadMemoria(void): // Constructor por defecto..
    memoriaDato(),
    memoriaPrograma(),
    vectorEtiqueta()
{}

UnidadMemoria::UnidadMemoria(char nombreFichero[]): // Constructor.
    memoriaDato(),
    memoriaPrograma(),
    vectorEtiqueta()
{
	ifstream fichero; // Variable del tipo ifstream para trabajar con el fichero.
	fichero.open(nombreFichero); // Apertura del fichero.
	char lineaFichero[50]; // Variable para almacenar las lineas del fichero.
	string elementoFichero, auxiliar; // Variables para almacenar las lineas del fichero.
	int registro = 0; // Contador para obtener el registro al que se asocia una etiqueta. Inicializada en el registro 0.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		fichero.getline(lineaFichero, 100); // Leemos las linea del fichero, almacenando el contenido en la variable lineaFichero.
		while (fichero.eof() == false) { // Mientras no se llegue al final del fichero.	
			if(lineaFichero[0] == '#') { // Si el primer carácter es una #, omitimos (comentario).
				fichero.getline(lineaFichero, 100); // Leemos las linea del fichero, almacenando el contenido en la variable lineaFichero.
			}
			else {
				fichero >> elementoFichero;
				if (elementoFichero.back() == ':') { // Si se lee una etiqueta (palabra terminada en :).
					elementoFichero.pop_back(); // Eliminamos ':' antes de insertar.
					insertarEtiqueta(elementoFichero, registro);
				}
				else {
					auxiliar = elementoFichero; // Almacenamos el valor de elementoFichero para no perderlo.
					if ((auxiliar.compare("halt") == 0) || (auxiliar.compare("HALT") == 0)) {
						elementoFichero = ' '; // Si es un halt, no existe operando, insertamos un espacio.
					}
					else {
						fichero >> elementoFichero; // Si no es halt, leemos el operando.
					}
					insertarInstruccion(auxiliar, elementoFichero);
					registro++; // Aumentamos el contador de registro.
				}
				elementoFichero.clear();
			}
		}
		registro = 0; // Reiniciamos el contador de registro.
		fichero.close(); // Cierre del fichero.
	}
}

UnidadMemoria::~UnidadMemoria(void) { // Destructor.

	memoriaDato.clear(); // Vaciamos por completo la memoria de datos.
	memoriaPrograma.clear(); // Vaciamos por completo la memoria de programas.
	vectorEtiqueta.clear(); // Vaciamos las etiquetas asociadas al programa ejecutado.
}

void UnidadMemoria::insertarDato(int dato, int posicion) { // Método que inserta un dato en la memoria de datos en el registro dado.

	memoriaDato.resize(posicion + 1); // Redimensionamos la memoria de datos para que pueda almacenar cualquier posición de registro pasada.
	memoriaDato[posicion] = dato;
}

void UnidadMemoria::insertarInstruccion(string operacion, string argumento) { // Método que inserta una instrucción en la memoria de programas.

	instruccion nuevaInstruccion; // Creamos una variable del tipo instrucción para insertarla en la memoria de programa.
	nuevaInstruccion.operacion        = operacion;
	nuevaInstruccion.argumento        = argumento;

	memoriaPrograma.push_back(nuevaInstruccion); // Insertamos en la memoria programa la nueva instrucción.
}

void UnidadMemoria::insertarEtiqueta(string nombre, int registro) { // Método que inserta una etiqueta en el vector de etiquetas.

	etiqueta nuevaEtiqueta; // Creamos una variable del tipo etiqueta para insertarlo en nuestro vector.
	nuevaEtiqueta.nombre   = nombre;
	nuevaEtiqueta.registro = registro;

	vectorEtiqueta.push_back(nuevaEtiqueta); // Insertamos en el vector la nueva etiqueta.
}

void UnidadMemoria::mostrarMemoriaDato() { // Método que muestra por pantalla la memoria de datos.

	for(int i = 0; i < memoriaDato.size(); i++) {
		if(i == 0) {
			cout << "R" << i << " (ACC): " << memoriaDato[i] << endl;
			cout << "--------------" << endl;
		}
		else {
			cout << "R" << i << ": " << memoriaDato[i] << endl;
			cout << "--------------" << endl;
		}
	}
	cout << endl;
}

void UnidadMemoria::mostrarMemoriaPrograma() { // Método que muestra por pantalla la memoria de programas.

	for(int i = 0; i < memoriaPrograma.size(); i++) {
		cout << "P" << i << ": " << memoriaPrograma[i].operacion << " " << memoriaPrograma[i].argumento << endl;
		cout << "--------------" << endl;
	}
	cout << endl;
}

int UnidadMemoria::devolverAcumulador() { // Método que devuelve el valor del acumulador (R0).

	return memoriaDato[0];
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

vector<etiqueta> UnidadMemoria::getVectorEtiqueta() { // Método getter del atributo vectorEtiqueta.

	return vectorEtiqueta;
}

void UnidadMemoria::setVectorEtiqueta(vector<etiqueta> vectorEtiqueta) { // Método setter del atributo vectorEtiqueta.

	this->vectorEtiqueta = vectorEtiqueta;
}


