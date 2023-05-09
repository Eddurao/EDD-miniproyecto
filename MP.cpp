#include <iostream>
#include <stdlib.h>
#include "ListArr.h"
#include "NodoDato.h"
#include "NodoResumen.h"
#include "ListArr.cpp" //vital para el funcionamiento del programa sino: no encuentra las funciones nose porque.
// el punto es para desreferenciar entonces nose para que es la ->
// aaa nue.b += 10 ;  . para clases y -> para punteros desreferenciacion inmediata 
using namespace std;
//POR LA xxxxxxx PORque xxxxxx SE REPITE 2 VECES LA xxxx CASILLA AAAAAAAAA

//Propiedad de Eduardo Parra y Nicolas Torres


int main(){

	

	ListArr nue(5);   //PROBLEMA: b4 y n2 funciona pero n3 no

	cout<< "presentacion " << endl  ;
 //es la casilla num 1. pero imprimiamos la casilla 2 que aun no exi
 
 
 for(int wa =0 ; wa < 10 ; wa++) {   // generamos 100 datos en orden.
 
 
    nue.insert_right(10*wa + 0);
	nue.insert_right(10*wa + 1);
	nue.insert_right(10*wa + 2);
	nue.insert_right(10*wa + 3);
	nue.insert_right(10*wa + 4);
	nue.insert_right(10*wa + 5);
	nue.insert_right(10*wa + 6);
	nue.insert_right(10*wa + 7);  
	nue.insert_right(10*wa + 8);
	nue.insert_right(10*wa + 9);
   
   
}
     
   nue.maketree();

   
   nue.print(); 

   nue.insert(7777, 24);
	
	nue.print();
	
	
    cout<<endl<< "ESTA EL 666 ?" << nue.find(666);
	
    cout<<endl<< "hay estos datos: " << nue.size() ;
	
	
	
	
	
}
