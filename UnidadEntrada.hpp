#pragma once // Usado para no crear conflictos entre include similares.

#include <vector>
#include <iostream> 
#include <fstream>

using namespace std;

class UnidadEntrada { // Clase para la implementación de una unidad de entrada para la memoria RAM.

    private: // Atributos privados de la clase.

        vector<int> cintaEntrada; // Vector (posibilidad de ser infinito) que implementa la cinta de entrada.

    public: // Métodos privados de la clase.

    	UnidadEntrada(void); // Constructor por defecto.
        UnidadEntrada(char nombreFichero[]); // Constructor.
        ~UnidadEntrada(void); // Destructor.

        void insertarElemento(int elemento); // Método que inserta un elemento en la cinta.

		vector<int> getCintaEntrada(); // Método getter del atributo cintaEntrada.
		void setCintaEntrada(vector<int> nuevaCinta); // Método setter del atributo cintaEntrada.
};
