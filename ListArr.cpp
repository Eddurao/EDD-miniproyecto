#include "ListArr.h"
#include "NodoResumen.h"
#include <iostream>

using namespace std; //permite usar el NULL. 

// 1: definir tamaño con deta(). 2: empezar a crear nodos dato.  3: hacer el arbol a traves de maketree().



ListArr *dataroot;
NodoResumen *resumenroot;
int ta = -1;
bool first = true;


NodoResumen maketree(ListArr *inicio)   //crea el arbol y retorna la raiz root
{
	
	
}

int contarla() //le tenemos que dar el putero raiz de los nodos de datos NOS DA en INICIO 1-2-3-4-5
{
	int nu = 0;
	ListArr *pt = dataroot;
	while(pt != NULL)
	{
		nu++;
		pt = pt->nextarr;
		
	}
	return nu;
	
	
}




void deta(int tam)  //define el tamaño  HAY QUE USARLA PRIMERO ANTES DE CREAR INSTANCIAS
{
	ta = tam;
}


ListArr::ListArr() :
{

	if(ta == -1){ cout<<"ERROR: no ha definido el tamaño"; ta = 10; };
	if(first){dataroot = this ; first = false;}
	
	b = ta;
	n = 0;
	arr = new int[b];
	nextarr = NULL;
	int posi = contarla();
	
	if(posi > 1){
		ListArr *pan;
		pan = dataroot;
		for(int i = 0; i < posi-1 ; i++){  //avanza atraves de los nodos dato hasta llegar a la posicion antecesora para definir su puntero
			pan = pan->nextarr;
		}
		pan->nextarr = this;        //define el puntero del anterio a este
		
	}
	
}
	


ListArr::~ListArr()
{
}

ListArr::size() //va recorriendo la lista por Puntero del L.A y sumando la cantidad n de cada nodo del L.A a un contador total OK!
{
	int nu = 0;
	ListArr* pala = dataroot;
	while(pala != NULL)
	{
		nu += pala->n;
		pala = pala->nextarr;

	}
	return nu;
	
	
}

void ListArr::insert_left(int veeme)
{
}

void ListArr::insert_right(int veeme)
{
}

void ListArr::insert(int veeme, int indice)
{
}

void ListArr::print()
{
}

bool ListArr::find(int veeme)
{
}
