#include "UnidadALC.hpp" // Incluimos el fichero UnidadALC.hpp con la declaración de nuestra clase.

UnidadALC::UnidadALC(): // Constructor.
    punteroIP(0) // Inicialmente apuntamos al registro 0.
{}

UnidadALC::~UnidadALC() { // Destructor.

	punteroIP = 0; // Ponemos en el punteroIP en el registro 0.
}

void UnidadALC::realizarOperaciones(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, UnidadSalida *unidadSalida, char nombreFichero[]) { // Método principal de la máquina RAM. 

	string operacionRealizar  = unidadMemoria->getMemoriaPrograma()[0].operacion; // Variable para almacenar la operación a realizar. 
	string argumentoOperacion = unidadMemoria->getMemoriaPrograma()[0].argumento; // Variable para almacenar los argumentos de la operación a realizar.
	int numeroOperaciones     = unidadMemoria->getMemoriaPrograma().size(); // Variable que almacena el número de operaciones de la memoria de programa.
	int instruccionActual = 0; // Variable contador para determinar el registro actual.

	while ((operacionRealizar.compare("halt") != 0) && (operacionRealizar.compare("HALT") != 0) && (this->getPunteroIP() != numeroOperaciones)) { 
		ejecutarInstruccion(unidadEntrada, unidadMemoria, unidadSalida, operacionRealizar, argumentoOperacion, instruccionActual);
		this->setPunteroIP(instruccionActual);
		cout << "OP: " << operacionRealizar << endl;
		operacionRealizar  = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].operacion;
		argumentoOperacion = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].argumento;
	}

	unidadSalida->volcarCintaFichero(nombreFichero); // Volcamos el contenido de la cinta de salida en el fichero.
}

void UnidadALC::ejecutarInstruccion(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, UnidadSalida *unidadSalida, string instruccion, string argumento, int &instruccionActual) { // Método que comprueba la validez de la instruccion y la ejecuta.

	if ((instruccion.compare("LOAD") == 0) || (instruccion.compare("load") == 0)) { // Instrucción LOAD.
		int operando = atoi(argumento.c_str()); // Al no ser una etiqueta, convertimos el argumento en un entero.
		unidadMemoria->insertarDato(operando, ACUMULADOR); // El operando se carga en el registro 0.
		instruccionActual++; // Incrementamos a la siguiente instrucción.
	}
	if ((instruccion.compare("STORE") == 0) || (instruccion.compare("store") == 0)) { // Instrucción STORE.
		int operando = atoi(argumento.c_str());
		unidadMemoria->insertarDato(unidadMemoria->devolverAcumulador(), operando); // El contenido de R0 se almacena en la memoria según el operando.
	    instruccionActual++;
	}
	if ((instruccion.compare("ADD") == 0) || (instruccion.compare("add") == 0)) { // Instrucción ADD.
		int operando = atoi(argumento.c_str());
		int suma     = unidadMemoria->devolverAcumulador() + operando;
		unidadMemoria->insertarDato(suma, ACUMULADOR); // El operando se suma a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("SUB") == 0) || (instruccion.compare("sub") == 0)) { // Instrucción SUB.
		int operando = atoi(argumento.c_str());
		int resta    = unidadMemoria->devolverAcumulador() - operando;
		unidadMemoria->insertarDato(resta, ACUMULADOR); // El operando se resta a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("MUL") == 0) || (instruccion.compare("mul") == 0)) { // Instrucción MUL.
		int operando = atoi(argumento.c_str());
		int producto = unidadMemoria->devolverAcumulador() * operando;
		unidadMemoria->insertarDato(producto, ACUMULADOR); // El operando se multiplica a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("DIV") == 0) || (instruccion.compare("div") == 0)) { // Instrucción DIV.
		int operando = atoi(argumento.c_str());
		int division = unidadMemoria->devolverAcumulador() / operando; // División redondeada a entero.
		unidadMemoria->insertarDato(division, ACUMULADOR); // El operando divide a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("READ") == 0) || (instruccion.compare("read") == 0)) { // Instrucción READ.
		int operando   = atoi(argumento.c_str());
		int valorLeido = unidadEntrada->leerElemento(); // Almacenamos el valor leido de la cinta de entrada.
		unidadMemoria->insertarDato(valorLeido, operando); // Se lee un valor de la cinta de entrada y se almacena en la memoria según el operando.
	    instruccionActual++;
	}
	if ((instruccion.compare("WRITE") == 0) || (instruccion.compare("write") == 0)) { // Instrucción WRITE.
		int operando = atoi(argumento.c_str());
		unidadSalida->escribirElemento(operando); // Se escribe el operando en la cinta.
	    instruccionActual++;
	}
	if ((instruccion.compare("JUMP") == 0) || (instruccion.compare("jump") == 0)) { // Instrucción JUMP.
		instruccionActual = unidadMemoria->devolverRegistroEtiqueta(argumento); // Almacenamos el registro asociado a la etiqueta del jump.
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