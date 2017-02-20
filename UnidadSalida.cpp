#include "UnidadSalida.hpp" // Incluimos el fichero UnidadSalida.hpp con las declaracion de nuestra clase.

UnidadSalida::UnidadSalida(void): // Constructor por defecto.
    cintaSalida(),
    cabezaEscritura(0),
    ficheroSalida()
{}

UnidadSalida::UnidadSalida(char nombreFichero[]): // Constructor.
    cintaSalida(),
    cabezaEscritura(0), // Inicialmente el cabezal de escritura se encuentra en la posición 0.
    ficheroSalida()
{
	ficheroSalida.open(nombreFichero); // Apertura del fichero de salida.

	if (ficheroSalida.is_open() == false) { // Comprobamos si se ha abierto el fichero.
		cout << "Error: No se ha podido abrir el fichero de salida " << nombreFichero << endl;
	}

	cintaSalida.resize(1); // Inicialmente la cinta estará vacía.
}

UnidadSalida::~UnidadSalida(void) { // Destructor.

	cintaSalida.clear(); // Vaciamos por completo la cinta de entrada.
	cabezaEscritura = 0; // Ponemos a 0 la cabeza de escritura.
	ficheroSalida.close(); // Cerramos el fichero de salida.
}

void UnidadSalida::escribirElemento(int elemento) { // Método que escribe un elemento en la cinta y en el fichero de salida.

	cintaSalida.resize(cintaSalida.size() + 1); // Incrementamos la posición de la cinta.
	cintaSalida[getCabezaEscritura()] = elemento; // Insertamos el elemento.
	setCabezaEscritura(cintaSalida.size() - 1); // Ponemos la cabeza de escritura en el último elemento del vector.

	//ficheroSalida << elemento; // Escribimos el valor en el fichero de salida.

}

void UnidadSalida::mostrarCintaSalida() { // Método para mostrar bajo formato la cinta de salida.

	for(int i = 0; i < cintaSalida.size(); i++) {
		cout << cintaSalida[i] << "|";
	}

	cout << endl;
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