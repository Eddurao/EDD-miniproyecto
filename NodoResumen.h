#ifndef NODORESUMEN_H
#define NODORESUMEN_H
#include "NodoDato.h"


//Propiedad de Eduardo Parra y Nicolas Torres

class NodoResumen{
	
	
	public:
	
	
	~NodoResumen();
	
	int usado;
	int total;
	
	NodoDato *di;  //nodo Dato Izquierdo
	NodoDato *dd;
	NodoResumen *ri; 
	NodoResumen *rd;  //nodo Resumen Derecho
	
	
	
};

#endif
