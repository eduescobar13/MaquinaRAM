#include "UnidadALC.hpp" // Incluimos el fichero UnidadALC.hpp con la declaración de nuestra clase.

UnidadALC::UnidadALC(): // Constructor.
    punteroIP(ACUMULADOR) // Inicialmente apuntamos al registro 0 (ACC).
{}

UnidadALC::~UnidadALC() { // Destructor.

	punteroIP = 0; // Ponemos el punteroIP a 0.
}

void UnidadALC::realizarOperaciones(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, UnidadSalida *unidadSalida, char nombreFichero[]) { // Método principal de la máquina RAM. 

	string operacionRealizar  = unidadMemoria->getMemoriaPrograma()[0].operacion; // Variable para almacenar la operación a realizar. 
	string argumentoOperacion = unidadMemoria->getMemoriaPrograma()[0].argumento; // Variable para almacenar los argumentos de la operación a realizar.
	int numeroOperaciones     = unidadMemoria->getMemoriaPrograma().size(); // Variable que almacena el número de operaciones de la memoria de programa.
	int instruccionActual     = 0; // Variable contador para determinar el registro actual.

	while ((operacionRealizar.compare("halt") != 0) && (operacionRealizar.compare("HALT") != 0) && (this->getPunteroIP() != numeroOperaciones)) { 
		ejecutarInstruccion(unidadEntrada, unidadMemoria, unidadSalida, operacionRealizar, argumentoOperacion, instruccionActual);
		this->setPunteroIP(instruccionActual); // Establecemos la instrucción a la que apunta el punteroIP.
		cout << "OP: " << operacionRealizar << endl;
		operacionRealizar  = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].operacion;
		argumentoOperacion = unidadMemoria->getMemoriaPrograma()[this->getPunteroIP()].argumento;
	}

	unidadSalida->volcarCintaFichero(nombreFichero); // Volcamos el contenido de la cinta de salida en el fichero.
}

void UnidadALC::ejecutarInstruccion(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, UnidadSalida *unidadSalida, string instruccion, string argumento, int &instruccionActual) { // Método que comprueba la validez de la instruccion y la ejecuta.

	int valorOperando = evaluarOperando(argumento).valor;
	int tipoOperando  = evaluarOperando(argumento).tipo;
	int valorRegistro; // Variable para los operandos de direccionamiento indirecto.

	if ((instruccion.compare("LOAD") == 0) || (instruccion.compare("load") == 0)) { // Instrucción LOAD.
		if (tipoOperando == CONSTANTE) {
			unidadMemoria->insertarDato(valorOperando, ACUMULADOR); // El valor del operando se carga en R0.
		}
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			unidadMemoria->insertarDato(unidadMemoria->devolverDato(valorOperando), ACUMULADOR); // El registro asociado al operando se carga en R0.
		}
		if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
			valorRegistro = unidadMemoria->devolverDato(valorOperando);
			unidadMemoria->insertarDato(unidadMemoria->devolverDato(valorRegistro), ACUMULADOR); // El registro asociado al operando se carga en R0.
		}
		instruccionActual++; // Incrementamos a la siguiente instrucción.
	}
	if ((instruccion.compare("STORE") == 0) || (instruccion.compare("store") == 0)) { // Instrucción STORE.
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			unidadMemoria->insertarDato(unidadMemoria->devolverAcumulador(), valorOperando); // El contenido de R0 se almacena en la memoria según el operando.
	    }
	    if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
	    	valorRegistro = unidadMemoria->devolverDato(valorOperando);
	    	unidadMemoria->insertarDato(unidadMemoria->devolverAcumulador(), valorRegistro); // El contenido de R0 se almacena en la memoria según el operando.
	    }
	    instruccionActual++;
	}
	if ((instruccion.compare("ADD") == 0) || (instruccion.compare("add") == 0)) { // Instrucción ADD.
		int suma; // Variable para almacenar el resultado de la suma.
		if (tipoOperando == CONSTANTE) {
			suma = unidadMemoria->devolverAcumulador() + valorOperando; 
		}
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			suma = unidadMemoria->devolverAcumulador() + unidadMemoria->devolverDato(valorOperando); 
		}
		if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
			valorRegistro = unidadMemoria->devolverDato(valorOperando);
			suma          = unidadMemoria->devolverAcumulador() + unidadMemoria->devolverDato(valorRegistro);
		}
		unidadMemoria->insertarDato(suma, ACUMULADOR); // El operando se suma a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("SUB") == 0) || (instruccion.compare("sub") == 0)) { // Instrucción SUB.
		int resta; // Variable para almacenar el resultado de la resta.
		if (tipoOperando == CONSTANTE) {
			resta = unidadMemoria->devolverAcumulador() - valorOperando; 
		}
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			resta = unidadMemoria->devolverAcumulador() - unidadMemoria->devolverDato(valorOperando); 
		}
		if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
			valorRegistro = unidadMemoria->devolverDato(valorOperando);
			resta         = unidadMemoria->devolverAcumulador() - unidadMemoria->devolverDato(valorRegistro);
		}
		unidadMemoria->insertarDato(resta, ACUMULADOR); // El operando se resta a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("MUL") == 0) || (instruccion.compare("mul") == 0)) { // Instrucción MUL.
		int producto; // Variable para almacenar el resultado del producto.
		if (tipoOperando == CONSTANTE) {
			producto = unidadMemoria->devolverAcumulador() * valorOperando; 
		}
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			producto = unidadMemoria->devolverAcumulador() * unidadMemoria->devolverDato(valorOperando); 
		}
		if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
			valorRegistro = unidadMemoria->devolverDato(valorOperando);
			producto      = unidadMemoria->devolverAcumulador() * unidadMemoria->devolverDato(valorRegistro);
		}
		unidadMemoria->insertarDato(producto, ACUMULADOR); // El operando se suma a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("DIV") == 0) || (instruccion.compare("div") == 0)) { // Instrucción DIV.
		int division; // Variable para almacenar el resultado de la division.
		if (tipoOperando == CONSTANTE) {
			division = unidadMemoria->devolverAcumulador() / valorOperando; 
		}
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			division = unidadMemoria->devolverAcumulador() / unidadMemoria->devolverDato(valorOperando); 
		}
		if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
			valorRegistro = unidadMemoria->devolverDato(valorOperando);
			division      = unidadMemoria->devolverAcumulador() / unidadMemoria->devolverDato(valorRegistro);
		}
		unidadMemoria->insertarDato(suma, ACUMULADOR); // El operando se suma a R0 y el resultado se almacena en R0.
	    instruccionActual++;
	}
	if ((instruccion.compare("READ") == 0) || (instruccion.compare("read") == 0)) { // Instrucción READ.
		int valorLeido = unidadEntrada->leerElemento(); // Almacenamos el valor leido de la cinta de entrada.
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			unidadMemoria->insertarDato(valorLeido, valorOperando); // Se lee un valor de la cinta de entrada y se almacena en la memoria según el operando.
	    }
	    if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
	    	valorRegistro = unidadMemoria->devolverDato(valorOperando);
	    	unidadMemoria->insertarDato(valorLeido, valorRegistro);
	    }
	    instruccionActual++;
	}
	if ((instruccion.compare("WRITE") == 0) || (instruccion.compare("write") == 0)) { // Instrucción WRITE.
		if (tipoOperando == CONSTANTE) {
			unidadSalida->escribirElemento(valorOperando); // Se escribe operando en la cinta.
		}
		if (tipoOperando == DIRECCIONAMIENTO_DIRECTO) {
			unidadSalida->escribirElemento(unidadMemoria->devolverDato(operando)); // Se escribe el registro asociado al operando en la cinta.
		}
		if (tipoOperando == DIRECCIONAMIENTO_INDIRECTO) {
			valorRegistro = unidadMemoria->devolverDato(valorOperando);
			unidadSalida->escribirElemento(unidadMemoria->devolverDato(valorRegistro));
		}
	    instruccionActual++;
	}
	if ((instruccion.compare("JUMP") == 0) || (instruccion.compare("jump") == 0)) { // Instrucción JUMP.
		instruccionActual = unidadMemoria->devolverRegistroEtiqueta(argumento); // Almacenamos el registro asociado a la etiqueta del jump.
	}
	if ((instruccion.compare("JZERO") == 0) || (instruccion.compare("jzero") == 0)) { // Instrucción JZERO.
		if (unidadMemoria->devolverAcumulador() == 0) { // Si el R0 es igual 0.
			instruccionActual = unidadMemoria->devolverRegistroEtiqueta(argumento); // Almacenamos el registro asociado a la etiqueta del jzero.
		}
		else {
			instruccionActual++;
		}
	}
	if ((instruccion.compare("JGTZ") == 0) || (instruccion.compare("jgtz") == 0)) { // Instrucción JGTZ.
		if (unidadMemoria->devolverAcumulador() > 0) { // Si el R0 es mayor 0.
			instruccionActual = unidadMemoria->devolverRegistroEtiqueta(argumento); // Almacenamos el registro asociado a la etiqueta del jzero.
		}
		else {
			instruccionActual++;
		}
	}

}

operando UnidadALC::evaluarOperando(string argumento) { // Función que evalúa el tipo de operando y devuelve una estructura con la información.

	operando valorRetorno; // Variable para almacenenar los valores a retornar.
	char caracterTipo = argumento[0]; // Almacenamos el primer carácter del argumento que determinará el tipo.
	string operandoString; // Variable usada para conversiones.
	int operando; // Variable usada para conversiones.

	switch(caracterTipo) {
		case '=': // Operando de tipo constante.
			operandoString = argumento.substr(1, argumento.size() - 1); // Eliminamos el = del argumento.
			operando = atoi(operandoString.c_str()); // Convertimos el valor en un entero.
			valorRetorno.valor = operando;
			valorRetorno.tipo  = CONSTANTE;
		break;
		case '*': // Direccionamiento indirecto.
			operandoString = argumento.substr(1, argumento.size() - 1); // Eliminamos el * del argumento.
			operando = atoi(operandoString.c_str()); // Convertimos el valor en un entero.
			valorRetorno.valor = operando;
			valorRetorno.tipo  = DIRECCIONAMIENTO_INDIRECTO;
		break;
		default: // Direccionamiento directo.
			operando = atoi(argumento.c_str()); // Al no tener caracteres de tipo, convertimos el argumento en un entero.
			valorRetorno.valor = operando;
			valorRetorno.tipo  = DIRECCIONAMIENTO_DIRECTO;
	}

	return valorRetorno;
}

//------------> MÉTODOS GETTER Y SETTER DE LA CLASE.

int UnidadALC::getPunteroIP() { // Método getter del atributo punteroIP.

	return punteroIP;
}

void UnidadALC::setPunteroIP(int punteroIP) { // Método setter del atributo punteroIP.

	this->punteroIP = punteroIP;
}