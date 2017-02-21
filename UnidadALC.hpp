#pragma once // Usado para no crear conflictos entre include similares.

#include <iostream> 
#include <string>
#include <cctype>

#include "UnidadEntrada.hpp"
#include "UnidadMemoria.hpp"
#include "UnidadSalida.hpp"

#define CONSTANTE 1
#define DIRECCIONAMIENTO_DIRECTO 2
#define DIRECCIONAMIENTO_INDIRECTO 3

typedef struct { // Definición de una estructura para almacenar los operandos y el tipo del mismo.
	int valor; // Valor entero del operando.
	int tipo; // Tipo de operando.
} operando;

using namespace std;

class UnidadALC { // Clase para la implementación de una unidad Aritmética, Lógica y de Control de una memoria RAM.

    private: // Atributos privados de la clase.

        int punteroIP; // Atributo para implementar el puntero IP asociado a la memoria de programas.

    public: // Métodos privados de la clase.

    	UnidadALC(void); // Constructor.
        ~UnidadALC(void); // Destructor.

        void realizarOperaciones(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, UnidadSalida *unidadSalida, char nombreFichero[]); // Método principal de la máquina RAM.
        void ejecutarInstruccion(UnidadEntrada *unidadEntrada, UnidadMemoria *unidadMemoria, UnidadSalida *unidadSalida, string instruccion, string argumento, int &instruccionActual); // Método que comprueba la validez de la instruccion y la ejecuta.
        operando evaluarOperando(string argumento); // Función que evalúa el tipo de operando y devuelve una estructura con la información.

        int getPunteroIP(); // Método getter del atributo punteroIP.
		void setPunteroIP(int punteroIP); // Método setter del atributo punteroIP.
};