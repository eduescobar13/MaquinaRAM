#include "UnidadALC.hpp" // Incluimos el fichero UnidadALC.hpp con la declaración de nuestra clase.

UnidadALC::UnidadALC(): // Constructor.
    punteroIP(0) // Inicialmente apuntamos al registro 0.
{}

UnidadALC::~UnidadALC() { // Destructor.

	punteroIP = 0; // Ponemos en el punteroIP en el registro 0.
}

void UnidadALC::realizarOperaciones(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria) { // Método principal de la máquina RAM. 

	string operacionRealizar  = unidadMemoria->getMemoriaPrograma()[0].operacion; // Variable para almacenar la operación a realizar. 
	string argumentoOperacion = unidadMemoria->getMemoriaPrograma()[0].argumento; // Variable para almacenar los argumentos de la operación a realizar.
	int numeroOperaciones     = unidadMemoria->getMemoriaPrograma().size(); // Variable que almacena el número de operaciones de la memoria de programa.
	int contador = 0; // Variable contador para determinar el registro actual.

	while ((operacionRealizar.compare("halt") != 0) && (operacionRealizar.compare("HALT") != 0) && (this->getPunteroIP() != numeroOperaciones)) { 
		ejecutarInstruccion(operacionRealizar);
		contador++;
		this->setPunteroIP(contador);
		operacionRealizar = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].operacion;
	}

}

void UnidadALC::ejecutarInstruccion(string instruccion) { // Método que comprueba la validez de la instruccion y la ejecuta.

	cout << instruccion << endl;

	if ((instruccion.compare("LOAD") == 0) || (instruccion.compare("load") == 0)) { // Instrucción LOAD.
		cout << "LOAD" << endl;
	}
	if ((instruccion.compare("STORE") == 0) || (instruccion.compare("store") == 0)) { // Instrucción STORE.
		cout << "STORE" << endl;
	}
	if ((instruccion.compare("ADD") == 0) || (instruccion.compare("add") == 0)) { // Instrucción ADD.
		cout << "ADD" << endl;
	}
	if ((instruccion.compare("SUB") == 0) || (instruccion.compare("sub") == 0)) { // Instrucción SUB.
		cout << "SUB" << endl;
	}
	if ((instruccion.compare("MUL") == 0) || (instruccion.compare("mul") == 0)) { // Instrucción MUL.
		cout << "MUL" << endl;
	}
	if ((instruccion.compare("DIV") == 0) || (instruccion.compare("div") == 0)) { // Instrucción DIV.
		cout << "DIV" << endl;
	}
	if ((instruccion.compare("READ") == 0) || (instruccion.compare("read") == 0)) { // Instrucción READ.
		cout << "READ" << endl;
	}
	if ((instruccion.compare("WRITE") == 0) || (instruccion.compare("write") == 0)) { // Instrucción WRITE.
		cout << "WRITE" << endl;
	}
	if ((instruccion.compare("JUMP") == 0) || (instruccion.compare("jump") == 0)) { // Instrucción JUMP.
		cout << "JUMP" << endl;
	}
	if ((instruccion.compare("JZERO") == 0) || (instruccion.compare("jzero") == 0)) { // Instrucción JZERO.
		cout << "JZERO" << endl;
	}
	if ((instruccion.compare("JGTZ") == 0) || (instruccion.compare("jgtz") == 0)) { // Instrucción JGTZ.
		cout << "JGTZ" << endl;
	}

}

//------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

int UnidadALC::getPunteroIP() { // Método getter del atributo punteroIP.

	return punteroIP;
}

void UnidadALC::setPunteroIP(int punteroIP) { // Método setter del atributo punteroIP.

	this->punteroIP = punteroIP;
}