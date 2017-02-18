//|-----------------------------------------------------------------------|
//| Author   : EDUARDO ESCOBAR ALBERTO                                    |
//| Date     : 21/02/2017                                                 |
//| Comments : Diseño y Análisis de Algoritmos                            |
//|            Escuela Técnica Superior de Ingeniería Informática         |
//|            Universidad de La Laguna                                   |  
//|                                                                       |
//| Compiling:                                                            |                                                         
//|-----------------------------------------------------------------------|

#include <iostream>
#include "UnidadEntrada.hpp"

using namespace std;

int main(int argc, char *argv[]) { // -----> FUNCIÓN PRINCIPAL.

	system ("clear");

	UnidadEntrada *UE;

	cout << endl;
	cout << "  ___|PRÁCTICA 1: DISEÑO Y ANÁLISIS DE ALGORITMOS|___" << endl;
	cout << "---------------------- MÁQUINA RAM ----------------------" << endl;

	UE = new UnidadEntrada(argv[1]); // Creación de un objeto de unidad de entrada pasando el nombre del fichero (línea de comandos).
	cout << UE->mostrarCabezaLectura() << endl;

	return (0); 

}