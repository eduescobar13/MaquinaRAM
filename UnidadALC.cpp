#include "UnidadALC.hpp" // Incluimos el fichero UnidadALC.hpp con la declaración de nuestra clase.

UnidadALC::UnidadALC(): // Constructor.
    punteroIP(0) // Inicialmente apuntamos al registro 0.
{}

UnidadALC::~UnidadALC() { // Destructor.

	punteroIP = 0; // Ponemos en el punteroIP en el registro 0.
}

void UnidadALC::realizarOperaciones(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria) { // Método principal de la máquina RAM. 

	unidadMemoria->mostrarMemoriaPrograma();
}

//------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

int UnidadALC::getPunteroIP() { // Método getter del atributo punteroIP.

	return punteroIP;
}

void UnidadALC::setPunteroIP(int punteroIP) { // Método setter del atributo punteroIP.

	this->punteroIP = punteroIP;
}