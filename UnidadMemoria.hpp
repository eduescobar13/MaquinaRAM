#pragma once // Usado para no crear conflictos entre include similares.

#include <iostream>
#include <string> 
#include <vector>
#include <fstream>

#define ACUMULADOR 0 // Constante de ubicación del registro 0 (acumulador).

using namespace std;

typedef struct { // Definición de una estructura que constituyen una instruccion de la RAM.
	string operacion;  // Variable que guarda la operacion a realizar.
	string argumento;  // Variable que almacena los argumentos de la instrucción.
} instruccion;

typedef struct { // Definición de una estructura para almacenar las etiquetas y el registro asociado.
	string nombre; // Nombre de la etiqueta.
	int registro; // Registro al que esta asociado la etiqueta.
} etiqueta;

class UnidadMemoria { // Clase para la implementación de una unidad de memoria de una memoria RAM.

    private: // Atributos privados de la clase.

    	vector<int> memoriaDato;             // Atributo para la implementación de la memoria de datos.
    	vector<instruccion> memoriaPrograma; // Atributo para la implementación de la memoria de programas.
    	vector<etiqueta> vectorEtiqueta;     // Atributo para almacenar las etiquetas y el registro que tienen asociado.

    public: // Métodos privados de la clase.

    	UnidadMemoria(void); // Constructor por defecto.
    	UnidadMemoria(char nombreFichero[]); // Constructor.
        ~UnidadMemoria(void); // Destructor.

        void insertarDato(int dato, int posicion); // Método que inserta un elemento en la memoria de datos en el registro dado.
        void insertarInstruccion(string operacion, string argumento); // Método que inserta una instrucción en la memoria de programas.
        void insertarEtiqueta(string nombre, int registro); // Método que inserta una etiqueta en el vector de etiquetas.
        void mostrarMemoriaDato(); // Método que muestra por pantalla la memoria de datos.
		void mostrarMemoriaPrograma(); // Método que muestra por pantalla la memoria de programas.
		int devolverAcumulador(); // Funció que devuelve el valor del acumulador (R0).
		int devolverRegistroEtiqueta(string etiqueta); // Función que devuelve el registro asociado a una etiqueta.

        vector<int> getMemoriaDato(); // Método getter del atributo memoriaDato.
		void setMemoriaDato(vector<int> memoriaDato); // Método setter del atributo memoriaDato.	
		vector<instruccion> getMemoriaPrograma(); // Método getter del atributo memoriaPrograma.
		void setMemoriaPrograma(vector<instruccion> memoriaPrograma); // Método setter del atributo memoriaPrograma.
		vector<etiqueta> getVectorEtiqueta(); // Método getter del atributo vectorEtiqueta.
		void setVectorEtiqueta(vector<etiqueta> vectorEtiqueta); // Método setter del atributo vectorEtiqueta.
};
