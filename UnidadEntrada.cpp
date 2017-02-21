#include "UnidadEntrada.hpp" // Incluimos el fichero UnidadEntrada.hpp con las declaracion de nuestra clase.

UnidadEntrada::UnidadEntrada(void): // Constructor por defecto.
    cintaEntrada(),
    cabezaLectura(0)
{}

UnidadEntrada::UnidadEntrada(char nombreFichero[]): // Constructor.
    cintaEntrada(),
    cabezaLectura(0) // Inicializamos a 0.
{
	int elementoFichero; // Variable para ir leyendo los elementos del fichero.
	ifstream fichero; // Variable del tipo ifstream para trabajar con el fichero.
	fichero.open(nombreFichero); // Apertura del fichero.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		while (fichero.eof() == false) { // Mientras no se llegue al final del fichero.	
			fichero >> elementoFichero; // Leemos del fichero.
			escribirElemento(elementoFichero); // Insertamos el elemento en la cinta.
		}
		fichero.close(); // Cierre del fichero.
	}

}

UnidadEntrada::~UnidadEntrada(void) { // Destructor.

	cintaEntrada.clear(); // Vaciamos por completo la cinta de entrada.
	cabezaLectura = 0; // Ponemos a 0 la cabeza de lectura.
}

void UnidadEntrada::escribirElemento(int elemento) { // Método que escribe un elemento en la cinta.

	cintaEntrada.push_back(elemento);
	setCabezaLectura(cintaEntrada.size() - 1); // Ponemos la cabeza de lectura en el último elemento del vector.
}

int UnidadEntrada::leerElemento() { // Método para la lectura de elementos de la cinta.

	int elementoRetorno = mostrarCabezaLectura(); // Almacenamos el elemento situado en la cabeza de lectura. 

	cintaEntrada.pop_back(); // Eliminamos dicho elemento de la cinta.
	setCabezaLectura(cabezaLectura - 1); // Disminuimos la cabeza de lectura.

	return elementoRetorno;
}

void UnidadEntrada::mostrarCintaEntrada() { // Método para mostrar bajo formato la cinta de entrada.

	cout << "|";
	for(int i = 0; i < cintaEntrada.size(); i++) {
		cout << cintaEntrada[i] << "|";
	}

	cout << endl;
}

int UnidadEntrada::mostrarCabezaLectura() { // Función que devuelve el elemento situado en la cabeza de lectura.

	return cintaEntrada[getCabezaLectura()];
}

//----------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

vector<int> UnidadEntrada::getCintaEntrada() { // Método getter del atributo cintaEntrada.

	return cintaEntrada;
}

void UnidadEntrada::setCintaEntrada(vector<int> cintaEntrada) { // Método setter del atributo cintaEntrada.

	this->cintaEntrada = cintaEntrada;
}

int UnidadEntrada::getCabezaLectura() { // Método getter del atributo cabezaLectura.

	return cabezaLectura;
}
		
void UnidadEntrada::setCabezaLectura(int cabezaLectura) { // Método setter del atributo cabezaLectura.

	this->cabezaLectura = cabezaLectura;
}

