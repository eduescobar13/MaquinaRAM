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

using namespace std;

int main(int argc, char *argv[]) { // -----> FUNCIÓN PRINCIPAL.

	system ("clear");

	UnidadEntrada *unidadEntrada;
	UnidadMemoria *unidadMemoria;

	cout << "  ___|PRÁCTICA 1: DISEÑO Y ANÁLISIS DE ALGORITMOS|___" << endl;
	cout << "-------------------- MÁQUINA RAM --------------------" << endl;

	unidadMemoria = new UnidadMemoria(argv[1]); // Creación de un objeto de unidad de memoria pasando el nombre del fichero (línea de comandos).
	unidadEntrada = new UnidadEntrada(argv[2]); // Creación de un objeto de unidad de entrada pasando el nombre del fichero (línea de comandos).
	unidadMemoria->mostrarMemoriaPrograma();

	return (0); 

}