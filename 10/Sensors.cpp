/*Design Pattern observer esercizio
Una stazione metereologica ha dei sensori di temperatura e
pressione atmosferica che aggiornano i valori attraverso
un metodo (setter) apposito.
Gli utenti possono registrarsi alla stazione ed ottenere
un aggiornamento se la temperatura o la pressione
cambiano più di un grado rispetto alla precedente lettura
ritornata agli utenti*/

#include "Sensors.h"

int main()
{
	Sensor s1(2.4, 123.0);
	User* u1 =  new User("Billy");
	s1.Attach(u1);
	cout<<"Created investor Billy following Sensor s1\n"<<endl;
	s1.SetPressure(125.0);
	
	User* u2 = new User("Timmy");
	s1.Attach(u2);
	cout<<"\nCreated investor Timmy following Sensor s1\n"<<endl;
	s1.SetTemperature(145.0);
	s1.Detach(u1);
	cout<<"\nInvestor Billy not interested in Sensor s1 anymore\n"<<endl;
	s1.SetPressure(12.0);
	delete u1;
	delete u2;
	return 0;
}