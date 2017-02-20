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
		ejecutarInstruccion(unidadEntrada, unidadMemoria, operacionRealizar, argumentoOperacion);
		contador++;
		this->setPunteroIP(contador);
		operacionRealizar  = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].operacion;
		argumentoOperacion = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].argumento;
	}

}

void UnidadALC::ejecutarInstruccion(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, string instruccion, string argumento) { // Método que comprueba la validez de la instruccion y la ejecuta.

	if ((instruccion.compare("LOAD") == 0) || (instruccion.compare("load") == 0)) { // Instrucción LOAD.
		int operando = atoi(argumento.c_str()); // Al no ser una etiqueta, convertimos el argumento en un entero.
		unidadMemoria->insertarDato(operando, 0); // El operando se carga en el registro 0.
	}
	if ((instruccion.compare("STORE") == 0) || (instruccion.compare("store") == 0)) { // Instrucción STORE.
		int operando = atoi(argumento.c_str());
		unidadMemoria->insertarDato(unidadMemoria->devolverAcumulador(), operando); // El contenido de R0 se almacena en la memoria según el operando.
	}
	if ((instruccion.compare("ADD") == 0) || (instruccion.compare("add") == 0)) { // Instrucción ADD.
		int operando = atoi(argumento.c_str());
		int suma     = unidadMemoria->devolverAcumulador() + operando;
		unidadMemoria->insertarDato(suma, 0); // El operando se suma a R0 y el resultado se almacena en R0.
	}
	if ((instruccion.compare("SUB") == 0) || (instruccion.compare("sub") == 0)) { // Instrucción SUB.
		int operando = atoi(argumento.c_str());
		int resta    = unidadMemoria->devolverAcumulador() - operando;
		unidadMemoria->insertarDato(resta, 0); // El operando se resta a R0 y el resultado se almacena en R0.
	}
	if ((instruccion.compare("MUL") == 0) || (instruccion.compare("mul") == 0)) { // Instrucción MUL.
		int operando = atoi(argumento.c_str());
		int producto = unidadMemoria->devolverAcumulador() * operando;
		unidadMemoria->insertarDato(producto, 0); // El operando se multiplica a R0 y el resultado se almacena en R0.
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