#include "UnidadSalida.hpp" // Incluimos el fichero UnidadSalida.hpp con las declaracion de nuestra clase.

UnidadSalida::UnidadSalida(): // Constructor.
    cintaSalida(),
    cabezaEscritura(0) // Inicialmente el cabezal de escritura se encuentra en la posición 0.
{
	cintaSalida.resize(1); // Inicialmente la cinta estará vacía.
}

UnidadSalida::~UnidadSalida() { // Destructor.

	cintaSalida.clear(); // Vaciamos por completo la cinta de entrada.
	cabezaEscritura = 0; // Ponemos a 0 la cabeza de escritura.
}

void UnidadSalida::escribirElemento(int elemento) { // Método que escribe un elemento en la cinta y en el fichero de salida.

	cintaSalida.resize(cintaSalida.size() + 1); // Incrementamos el tamaño de la cinta.
	cintaSalida[getCabezaEscritura()] = elemento; // Insertamos el elemento.
	setCabezaEscritura(cintaSalida.size() - 1); // Ponemos la cabeza de escritura en el último elemento del vector.

}

void UnidadSalida::mostrarCintaSalida() { // Método para mostrar bajo formato la cinta de salida.

	cout << "|";
	for(int i = 0; i < cintaSalida.size(); i++) {
		if (i == cintaSalida.size() - 1) {
			cout << " |";
		}
		else {
			cout << cintaSalida[i] << "|";
		}
	}

	cout << endl;
}

void UnidadSalida::volcarCintaFichero(char nombreFichero[]) { // Método que vuelca el contenido de la cinta en el fichero.

	ofstream fichero;
	fichero.open(nombreFichero); // Apertura del fichero de salida.

	if (fichero.is_open()) { // Comprobamos si se ha abierto el fichero.
		for(int i = 0; i < cintaSalida.size() - 1; i++) { // Suprimimos el valor donde se encuentra situada la cabeza de escritura.
			fichero << cintaSalida[i] << endl;
		}
	}

	fichero.close();
}

//----------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

vector<int> UnidadSalida::getCintaSalida() { // Método getter del atributo cintaSalida.

	return cintaSalida;
}

void UnidadSalida::setCintaSalida(vector<int> cintaSalida) { // Método setter del atributo cintaSalida.

	this->cintaSalida = cintaSalida;
}

int UnidadSalida::getCabezaEscritura() { // Método getter del atributo cabezaEscritura.

	return cabezaEscritura;
}
		
void UnidadSalida::setCabezaEscritura(int cabezaEscritura) { // Método setter del atributo cabezaEscritura.

	this->cabezaEscritura = cabezaEscritura;
}