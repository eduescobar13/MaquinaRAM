#pragma once // Usado para no crear conflictos entre include similares.

#include <vector>
#include <iostream> 
#include <fstream>

using namespace std;

class UnidadSalida { // Clase para la implementación de una unidad de salida para la memoria RAM.

    private: // Atributos privados de la clase.

        vector<int> cintaSalida; // Vector (posibilidad de ser infinito) que implementa la cinta de salida.
        int cabezaEscritura; // Atributo para implementar el cabezal de escritura de la cinta de salida.
        char ficheroSalida[]; // Atributo para hacer uso de un fichero de salida.

    public: // Métodos privados de la clase.

        UnidadSalida(); // Constructor.
        ~UnidadSalida(); // Destructor.

        void escribirElemento(int elemento); // Método que escribe un elemento en la cinta.
        void mostrarCintaSalida(); // Método para mostrar bajo formato la cinta de salida.
        void volcarCintaFichero(char nombreFichero[]); // Método que vuelca el contenido de la cinta en el fichero.

		vector<int> getCintaSalida(); // Método getter del atributo cintaSalida.
		void setCintaSalida(vector<int> cintaSalida); // Método setter del atributo cintaSalida.
		int getCabezaEscritura(); // Método getter del atributo cabezaEscritura.
		void setCabezaEscritura(int cabezaEscritura); // Método setter del atributo cabezaEscritura.
};