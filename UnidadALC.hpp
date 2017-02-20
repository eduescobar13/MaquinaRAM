#pragma once // Usado para no crear conflictos entre include similares.

#include <iostream> 
#include <string>
#include <cctype>

#include "UnidadEntrada.hpp"
#include "UnidadMemoria.hpp"

using namespace std;

class UnidadALC { // Clase para la implementación de una unidad Aritmética, Lógica y de Control de una memoria RAM.

    private: // Atributos privados de la clase.

        int punteroIP; // Atributo para implementar el puntero IP asociado a la memoria de programas.

    public: // Métodos privados de la clase.

    	UnidadALC(void); // Constructor.
        ~UnidadALC(void); // Destructor.

        void realizarOperaciones(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria); // Método principal de la máquina RAM.
        void ejecutarInstruccion(string instruccion); // Método que comprueba la validez de la instruccion y la ejecuta.

        int getPunteroIP(); // Método getter del atributo punteroIP.
		void setPunteroIP(int punteroIP); // Método setter del atributo punteroIP.
};