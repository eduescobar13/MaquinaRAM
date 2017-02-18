#pragma once // Usado para no crear conflictos entre include similares.

#include <iostream>
#include <string> 
#include <vector>
#include <fstream>

using namespace std;

class UnidadMemoria { // Clase para la implementación de una unidad de memoria de una memoria RAM.

    private: // Atributos privados de la clase.

    	vector<int> memoriaDato; // Atributo para la implementación de la memoria de datos.
    	vector<string> memoriaPrograma; // Atributo para la implementación de la memoria de programas.

    public: // Métodos privados de la clase.

    	UnidadMemoria(void); // Constructor por defecto.
    	UnidadMemoria(char nombreFichero[]); // Constructor.
        ~UnidadMemoria(void); // Destructor.

        void insertarDato(int dato); // Método que inserta un elemento en la memoria de datos.
        void insertarInstruccion(string instruccion); // Método que inserta una instrucción en la memoria de programas.

        vector<int> getMemoriaDato(); // Método getter del atributo memoriaDato.
		void setMemoriaDato(vector<int> memoriaDato); // Método setter del atributo memoriaDato.	
		vector<string> getMemoriaPrograma(); // Método getter del atributo memoriaPrograma.
		void setMemoriaPrograma(vector<string> memoriaPrograma); // Método setter del atributo memoriaPrograma.
};