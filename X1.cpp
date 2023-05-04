#include <iostream>

using namespace std;




	class motor 
	{  
	
	public:
	int volvo = 700;
	
	
	};
	

class Auto
{
	public:
		
	int ruedas = 4;
	

	
	motor* toyota = new motor;
	
	
	int desacelerar(){
		
		toyota->volvo -= 200;
		
		return toyota->volvo - 400;
		
	}
	
	
	motor* reparar(){
		
		
		return new motor;
		
		
		
	}
	
	
	
	
};












	

Auto makuin;


int main(){
	
Auto* makuin = new Auto;

makuin->desacelerar();
	
	
	cout<< makuin-> toyota -> volvo <<endl  ;


makuin->desacelerar();

	cout<< makuin-> toyota -> volvo <<endl  ;

	motor *fiat = new motor;
	
	
	
	
	
	
}
