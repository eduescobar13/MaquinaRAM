#pragma once // Usado para no crear conflictos entre include similares.

#include <iostream>
#include <string> 

using namespace std;

class UnidadMemoria { // Clase para la implementación de una unidad de memoria de una memoria RAM.

    private: // Atributos privados de la clase.

    	vector<int> memoriaDatos; // Atributo para la implementación de la memoria de datos.
    	vector<string> memoriaPrograma; // Atributo para la implementación de la memoria de programas.

    public: // Métodos privados de la clase.

    	UnidadMemoria(void); // Constructor.
        ~UnidadMemoria(void); // Destructor.
};