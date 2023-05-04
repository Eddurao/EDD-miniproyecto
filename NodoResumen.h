#ifndef NODORESUMEN_H
#define NODORESUMEN_H
#include <stdlib.h>


class NodoResumen{
	
	
	public:
	NodoResumen(){
		izq = 0;
		der = 0;
		izqn = 0;
		dern = 0;
		
	};
	
	~NodoResumen();
	setlai(ListArr *izi){
		izq = izi;
	}	
		
	setlad(ListArr *ded){
		der = ded;
	}		
	
	setnri(NodoResumen *iz){
		izqn = iz;
	}	
	setnrd(NodoResumen *de){
		dern = de;
	}	
	
	private:
	ListArr *izq;
	ListArr *der;
	NodoResumen *izqn;
	NodoResumen *dern;
	
	
	
};

#endif
