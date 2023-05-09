#ifndef LISTARR_H
#define LISTARR_H

#include "NodoDato.h"
#include "NodoResumen.h"

//Propiedad de Eduardo Parra y Nicolas Torres
class ListArr
{
	
	
	
	
	public:
		ListArr(int);
		~ListArr();
	    int size();
		void insert_left(int);
		void insert_right(int);
		void insert(int, int);
		void print();
		bool find(int);
		void add_node();
		void maketree();
		NodoResumen* generarNR();
		
		
		int i;
		int n;
	    NodoDato *root;
	    NodoDato *last;
	    NodoResumen *treeroot;	
		int b;
			
		
		
		
		
		
		
};

#endif
