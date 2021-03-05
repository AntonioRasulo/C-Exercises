/*Creare una classe per la gestione dei treni.
Un treno è associato ad un codice, una stazione di partenza ed arrivo,
e la sua posizione attuale (latitudine, longitudine). Creare una 
classe per la gestione dei treni che permetta di:
	--> aggiungere un treno;
	--> stampare la posizione dei treni per codice crescente;
	--> fornire la classe di un iteratore per iterare sui treni.*/
#include "TrainHandler.h"
#include<iostream>

int main()
{
	Train t1("Bucine", "Montevarchi", 3.4, 2.5, 4567);
	Train t2("Arezzo","San Giovanni Valdarno",2.4,1.2, 3456);
	Train t3("Firenze","Pisa",3.4,5.2, 1234);
	Train t4("Prato","Livorno",3.4,1.2, 2345);
	
	TrainHandler th;
	
	th.Set(t1);
	th.Set(t2);
	th.Set(t3);
	th.Set(t4);
	
	TrainHandler::Iterator iter(th);
	
	while(iter.HasNext())
	{
		TrainHandler::Element e = iter.GetNext();	//Possibile iterare senza avere accesso diretto agli elementi del vettore
		std::cout << e.i << "::"; (e.value).Print();
	}
}