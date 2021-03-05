/*Una bicicletta si compone di componenti più semplici:
	-Che a loro volta sono composti da altri componenti più
	 semplici, ad esempio: ruote composte da ruota anteriore
	 e posteriore, cambio composto da cambio anteriore e 
	 posteriore, telaio, ecc..

Ogni componente ha un prezzo e la classe bicicletta ha un
costo pari alla somma dei singoli componenti.

Realizzare una bicicletta attraverso il design pattern Composite:
	-Deve essere possibile sapere il prezzo della bici composta*/
	
using namespace std;

#include "CompositeBicicle.h"
#include<iostream>

int main()
{
	//Creo classificatore composto per ruota
	BicicleComposite* ruota = new BicicleComposite;
	
	// raggio owned da ruota
	ruota->AddComponent(new Component(5));
	// gomma owned da ruota
	ruota->AddComponent(new Component(7));
	// dinamo owned da ruota
	ruota->AddComponent(new Component(11)); 
	
	// Creo bici composta per mountain_bike
	BicicleComposite mountain_bike;
	
	mountain_bike.AddComponent(ruota); // ruota owned da mountain_bike
	mountain_bike.AddComponent(new Component(10)); // sella owned da mountain_bike
	
	// Bicicle composto usato da interfaccia di base class
	cout << mountain_bike.Price()<< endl;

}