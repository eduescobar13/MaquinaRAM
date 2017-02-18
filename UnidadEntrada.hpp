#pragma once // Usado para no crear conflictos entre include similares.

#include <vector>
#include <iostream> 
#include <fstream>

using namespace std;

class UnidadEntrada { // Clase para la implementación de una unidad de entrada para la memoria RAM.

    private: // Atributos privados de la clase.

        vector<int> cintaEntrada; // Vector (posibilidad de ser infinito) que implementa la cinta de entrada.
        int cabezaLectura; // Atributo para implementar el cabezal de lectura de la cinta de entrada.

    public: // Métodos privados de la clase.

    	UnidadEntrada(void); // Constructor por defecto.
        UnidadEntrada(char nombreFichero[]); // Constructor.
        ~UnidadEntrada(void); // Destructor.

        void insertarElemento(int elemento); // Método que inserta un elemento en la cinta.
        void mostrarCinta(); // Método para mostrar bajo formato la cinta de entrada.
        int mostrarCabezaLectura(); // Función que devuelve el elemento situado en la cabeza de lectura.

		vector<int> getCintaEntrada(); // Método getter del atributo cintaEntrada.
		void setCintaEntrada(vector<int> cintaEntrada); // Método setter del atributo cintaEntrada.
		int getCabezaLectura(); // Método getter del atributo cabezaLectura.
		void setCabezaLectura(int cabezaLectura); // Método setter del atributo cabezaLectura.
};
