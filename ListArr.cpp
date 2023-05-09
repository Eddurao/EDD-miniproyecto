#include "ListArr.h"
#include "NodoResumen.h"
#include "NodoDato.h"
#include <iostream>

//Propiedad de Eduardo Parra y Nicolas Torres

using namespace std; //permite usar el NULL.   
/*
	NodoDato *nextarr;        //NODO DATO
	int n;
	int b;
	int *arr;
	
	*di;  //nodo Dato Izquierdo     //NODO RESUMEN
	*dd;
	*ri; 
	*rd;  //nodo Resumen Derecho



*/



ListArr::ListArr(int pab)

{          
	b = pab;
	n = 0;
	NodoDato *ROOT = new NodoDato();
	
	ROOT->b = pab;
	ROOT->n = 0;
	*ROOT->arr = new int[b];
	root = ROOT;
	last = ROOT;
	last->nextarr = NULL;
	
	
	
}
	


ListArr::~ListArr()
{
}

int ListArr::size() //de hecho ya hay una variable que guarda eso. es n en el ListArr
{
  return n;
}

void ListArr::insert_left(int pavalor) //ya te digo que esto maximo sera b
{
	if(root->n < b){ 
		int slot;
		for(int w =0 ; w< root->n ; w++){  //yo me invente este algoritmo que soy bacan >:3
			slot = *((*root->arr)+w+1);  //corre todos un lugar a la derecha para poner el valor en el 0
			*((*root->arr)+w+1) = *((*root->arr)+w);
			**root->arr = slot;  // !! 	          
		}
		**root->arr = pavalor;
		n++;
		root->n ++;
		
	}
	else{
		NodoDato *NWROOT = new NodoDato;      //si esta lleno, crea un nodo a la derecha y le mete el valor en el 0
			*NWROOT->arr = new int[b];
			
			**NWROOT->arr = pavalor;
			NWROOT->n ++;
			n ++;
		NWROOT->nextarr = root;
		root = NWROOT;
		
		
		
		
	}
	
}

void ListArr::insert_right(int pavalor)   //!!!!!!!! mm parece que variables saltan int y arreglos salta el puntero
{
	if(last->n < b ){       //ANTES n = 0
		*(*last->arr+last->n ) = pavalor ;
		n++; 
	    last->n  ++; 
	}
	else{         //  cout<< endl <<  "-- SE HA CREADO UN NUEVO NODO --" << endl << endl ; 
		add_node();  
		*( (*last->arr)) = pavalor;     // !!!! FALSOOO: NADIE QUIERE QUE SEPAS ESTO: para desreferenciar la posicion 0 del arr. el puntero tiene que tener un +2 
		n++;
		last->n++;   
	}   //DESPUES n = 1     . 0-1-2-3-4-5-6-7-8
	
	//cout<< "SE INSERTO A LA DERECHA: " << *((*last->arr)+last->n-1 )<<endl;//LA xxxxxxxxxxxxxx ESTA ES LA xxx MAS REBUSCADA QUE HE LOGRADO EN MI VIDA 23:11

	   
}

void ListArr::insert(int pavalor, int paindice)
{   maketree();
	if(paindice > n){cout<<"No se PaSE de LiStO, Ese Numero Se esCapa Del Rango del ListArr ! -->ingrese un indice menor, que no sobrepase n" ;}
	int indi = paindice;
	NodoResumen *lupa = NULL;
	lupa = treeroot;
	int varo = 0;
	while(lupa->dd == NULL || lupa->di == NULL){
		
		varo = lupa->ri->usado;
		if(indi < lupa->ri->usado && lupa->ri != NULL ){ lupa = lupa->ri;
		}
		else{ if(lupa->rd != NULL){lupa = lupa->rd; indi -= varo; varo=0; } }
		
	}
	
	if(indi < lupa->di->n){  NodoDato *NI = lupa->di; 
	
		
		if(lupa->di->n < b){ //caso aray no lleno: se corren los demas elementos para despejar la posicion indice
			int slot;
			
			for(int w =indi ; w< NI->n ; w++){  //yo me invente este algoritmo que soy bacan >:3
				slot = *((*NI->arr)+w+1);  //corre todos un lugar a la derecha para poner el valor en el 0
				*((*NI->arr)+w+1) = *((*NI->arr)+w);
				*((*NI->arr)+indi) = slot;  // !! 	          
			}
			
			*((*NI->arr)+indi) = pavalor;
			NI->n ++; // AAAY >:( NO QUIERO ACTUALIZAR EL ARBOL POR ESTA PEQUEÑES pero importa mas que funcione bien a que esté optimizado :(
			maketree();
		}
		else{ //caso array lleno: Crea uno nuevo nodo sin novedad al frente y pone el valor en su array.
			if(NI == last){ insert_right(pavalor) ; return; }
			NodoDato *NODO = new NodoDato;
			NODO->nextarr = NI->nextarr;
			NI->nextarr = NODO;
			*NODO->arr = new int[b];
			NODO->b= b;
			NODO->n = 1;
			
			**NODO->arr = pavalor;
			cout<< "\n !!! SE HA CREADO UN NUEVO NODO PARA AQUEL DATO PORQUE EL ARREGLO EN DONDE INTENTA INSERTAR ESTA LLENO !!!! \n" ; 
			maketree();
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
	}
	else{indi -= lupa->di->n;   //aqui abajo sera lo mismo pero con indi disminuido.
	
			NodoDato *NI = lupa->dd;
	
			if(lupa->dd->n < b){ //caso aray no lleno: se corren los demas elementos para despejar la posicion indice
			int slot;
			
			for(int w =indi ; w< NI->n ; w++){  //yo me invente este algoritmo que soy bacan >:3
				slot = *((*NI->arr)+w+1);  //corre todos un lugar a la derecha para poner el valor en el 0
				*((*NI->arr)+w+1) = *((*NI->arr)+w);
				*((*NI->arr)+indi) = slot;  // !! 	          
			}
			
			*((*NI->arr)+indi) = pavalor;
			NI->n ++;
			maketree();
		}
		else{ //caso array lleno: Crea uno nuevo nodo sin novedad al frente y pone el valor en su array.
			
			if(NI == last){ insert_right(pavalor) ; return; }
			NodoDato *NODO = new NodoDato;
			NODO->nextarr = NI->nextarr;
			NI->nextarr = NODO;
			*NODO->arr = new int[b];
			NODO->b= b;
			NODO->n = 1;
			
			**NODO->arr = pavalor;
			cout<< "\n !!! SE HA CREADO UN NUEVO NODO PARA AQUEL DATO PORQUE EL ARREGLO EN DONDE INTENTA INSERTAR ESTA LLENO !!!! \n" ; 
			maketree();
			
		}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 }
	
	
	
	
	
	
}

void ListArr::print()
{
	
	cout<< "INVOCADO PRINT"  << endl ;
	int w = 0;
	int CO = 3;
	int NoCo = 1;
	NodoDato *act = root;
	do{
		
			cout<< "Nodo#" << NoCo <<" --> ";
		for(int w = 0; w < b; w++){
			
		
			cout<< ":" ;
			cout<< *((*act->arr)+w) << " - " ;  // !!!! xxxxxxxxxxxxx COOOMOOOO xxxxxxxxxxxxxxx ESSS ASIIIxxxxxx ar+w
		
		
			
			
		}
	
		cout<<endl;
		if(CO < 3){break;}    //vamos xxx sin miedo que esta xxx va a funcionar
		
		act = act->nextarr;
		if(act -> nextarr == NULL){CO = 2;}
		NoCo++;
		
		
	}while(1);
	
	
	
	
	
	
	
	
}

bool ListArr::find(int pavalor)
{
	NodoDato *ojito_hermoso = root;  //mi perrito tiene unos ojitos muy lindos <:3  :_) es tipo caniche color beige <3 me gusta cuando me APUNTA con su mirada <:_)
	while(1){
		for(int la=0; la<= ojito_hermoso->n ; la++){
			if(*((*ojito_hermoso->arr)+la) == pavalor) {return true;}	
		}
	ojito_hermoso = ojito_hermoso->nextarr ;
	if(ojito_hermoso == NULL){return false;}
		
		
		
	}
	
	return false;
	
}

void ListArr::maketree()    //crea el arbolito de boric
{
	
	
	int nodos = 0;
	NodoDato *sniper = root; //Los sniper son armas que basicamente APUNTAN.
	NodoResumen *actually = NULL;
	NodoResumen **mcc = new NodoResumen*[200];
	
	
	do{
	
		if(sniper != NULL){ actually = generarNR() ; actually->usado += sniper->n ; actually->total += b ; actually->di = sniper ;}
		sniper = sniper->nextarr ; if(sniper == NULL) break;
		if(sniper != NULL){ actually->usado += sniper->n ; actually->total += b ; actually->dd = sniper ;} 
		*(mcc+nodos) = actually; actually = NULL; 
		
		sniper = sniper->nextarr ; //aaaa ahi esta no se puede ejecutar esto en null
		nodos ++;
		
	}while(sniper != NULL); 
	int bacan = 0; //DEBE HABER UN VALOR nulo en el arreglo
	int stage = 1;
	int h;
	int vez = 0;
	
	
	do{
	 
		
		for(h = 0 ; h<nodos - nodos%2 ; h += 2 ){ 
			actually = generarNR(); actually->ri = *(mcc+h); actually->rd = *(mcc+h+1) ; actually->usado = actually->ri->usado + actually->rd->usado; actually->total = actually->ri->total + actually->rd->total;
			*(mcc+h/2) = actually; 
			actually = NULL;
		}
		
	 
	
		if(nodos%2){ 
		actually = generarNR();
		actually->ri = *(mcc+h); 
		actually->usado = actually->ri->usado;
	    actually->total = actually->ri->total; 
		*(mcc+h/2) = actually;
		actually = NULL; 
	
		}
		
		nodos = nodos / 2 + nodos%2; 			
		stage++;
		
		
		vez++;
		
	}while(nodos > 1); 
	treeroot = *mcc;
	
	
	
}

void ListArr::add_node()
{
	NodoDato *NODO = new NodoDato;
	last->nextarr = NODO;
	last = NODO;
	*NODO->arr = new int[b];
	NODO->b= b;
	NODO->n = 0;
	NODO->nextarr == NULL;
	
		
}

NodoResumen* ListArr::generarNR(){
	NodoResumen *esto = new NodoResumen; 
	
	esto->dd = NULL;
	esto->di = NULL;
	esto->rd = NULL;
	esto->ri = NULL;
	
	esto->total = 0;
	esto->usado = 0;
	
	return esto;
	
}



