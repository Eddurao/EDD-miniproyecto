#include <iostream>
#include <stdlib.h>
#include "ListArr.h"
#include "NodoDato.h"
#include "NodoResumen.h"
#include "ListArr.cpp"
#include <ctime>


 //vital para el funcionamiento del programa sino: no encuentra las funciones nose porque.
// el punto es para desreferenciar entonces nose para que es la ->
// aaa nue.b += 10 ;  . para clases y -> para punteros desreferenciacion inmediata 
using namespace std;
//POR LA xxxxxxx PORque xxxxxx SE REPITE 2 VECES LA xxxx CASILLA AAAAAAAAA

//Propiedad de Eduardo Parra y Nicolas Torres


int main(){

	

  //PROBLEMA: b4 y n2 funciona pero n3 no


 //es la casilla num 1. pero imprimiamos la casilla 2 que aun no exi
 
    clock_t start = clock();
 
	for(int wa =0 ; wa < 20 ; wa++) {  
       	ListArr nue(1024); 
 		for(int wi = 0 ; wi < 100000000 ; wi++){
 			
			nue.insert_right(wi); 	
 	
 	
 	
		 }
	
	
	}
	

	 
	 
	 
	 clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
      cout << "Tiempo transcurrido: " << duration << "ms" << endl;

	
	
	
	
	
	
	
}
	
	
	
	
	
	
	
	
	
	
	
	
