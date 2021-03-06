//|-----------------------------------------------------------------------|
//| Autor       : EDUARDO ESCOBAR ALBERTO                                 |
//| Versión     : 21/02/2017                                              |
//| Comentarios : Diseño y Análisis de Algoritmos                         |
//|               Escuela Superior de Ingeniería y Tecnología             |
//|               Universidad de La Laguna                                |  
//|                                                                       |
//| Compilación : g++ -g main.cpp UnidadEntrada.cpp UnidadSalida.cpp      |
//|               UnidadMemoria.cpp UnidadALC.cpp -o RAM                  |                                                         
//|-----------------------------------------------------------------------|

#include <iostream>
#include "UnidadEntrada.hpp"
#include "UnidadMemoria.hpp"
#include "UnidadALC.hpp"
#include "UnidadSalida.hpp"

using namespace std;

int main(int argc, char *argv[]) { // -----> FUNCIÓN PRINCIPAL.

	system ("clear");

	//----------> CREACIÓN DE LOS OBJETOS.
	UnidadEntrada *unidadEntrada;
	UnidadMemoria *unidadMemoria;
	UnidadALC	  *unidadALC;
	UnidadSalida  *unidadSalida;

	char debugChar = *argv[4]; // Obtenemos el valor del debug.
	int debug = debugChar - '0'; // Convertimos dicho valor a un entero.

	cout << "  ___|PRÁCTICA 1: DISEÑO Y ANÁLISIS DE ALGORITMOS|___" << endl;
	cout << "-------------------- MÁQUINA RAM --------------------" << endl;

	unidadEntrada = new UnidadEntrada(argv[2]); // Creación de un objeto de unidad de entrada pasando el nombre del fichero (línea de comandos).
	unidadMemoria = new UnidadMemoria(argv[1]); // Creación de un objeto de unidad de memoria pasando el nombre del fichero (línea de comandos).
	unidadALC     = new UnidadALC();            // Creación de un objeto de unidad de algoritmía, lógica y control.
	unidadSalida  = new UnidadSalida();         // Creación de un objeto de unidad de salida.

	unidadALC->realizarOperaciones(unidadEntrada, unidadMemoria, unidadSalida, argv[3], debug);

	return(0); 
}