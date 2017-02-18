#pragma once // Usado para no crear conflictos entre include similares.

#include <iostream> 

using namespace std;

class UnidadALC { // Clase para la implementación de una unidad Aritmética, Lógica y de Control de una memoria RAM.

    private: // Atributos privados de la clase.

        int punteroIP; // Atributo para implementar el puntero IP asociado a la memoria de programas.

    public: // Métodos privados de la clase.

    	UnidadALC(void); // Constructor.
        ~UnidadALC(void); // Destructor.
};