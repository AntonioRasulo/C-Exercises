/*Design Pattern observer esercizio
Una stazione metereologica ha dei sensori di temperatura e
pressione atmosferica che aggiornano i valori attraverso
un metodo (setter) apposito.
Gli utenti possono registrarsi alla stazione ed ottenere
un aggiornamento se la temperatura o la pressione
cambiano più di un grado rispetto alla precedente lettura
ritornata agli utenti*/

using namespace std;
#include<iostream>
#include<string>
#include<list>

class Sensor;	//La classe osservata

class UserBase{	//Prototipo dell'osservatore

	public:
		virtual void Update(Sensor* sensor) = 0;

};

class Sensor
{
	public:
		Sensor(double temperature_, double pressure_):temperature(temperature_),pressure(pressure_){}
		void Attach(UserBase* user_){users.push_back(user_);}	//+osservatore
		void Detach(UserBase* user_){users.remove(user_);}	//-osservatore
		void Notify()	//Notifica gli osservatori passandogli l'oggetto osservato
		{	
			list<UserBase*>::iterator it = users.begin();
			while(it != users.end()) {(*it)->Update(this); ++it;}
		}
		double GetTemperature()const{ return temperature;}
		void SetTemperature(double temperature_){temperature=temperature_; Notify();}	//Cambio stato, chiamo Notify()
		double GetPressure()const{ return pressure;}
		void SetPressure(double pressure_){pressure=pressure_; Notify();}	//Cambio stato, chiamo Notify()
		
	private:
		double temperature;
		double pressure;
		list<UserBase*> users;	//lista di osservanti

};

//L'osservatore
class User:public UserBase
{
	public:
		User(const string& name_) : name(name_){}
		void Update(Sensor* sensor){		//riceve la notifica
		cout << "Notifica a " << name << " => " << sensor->GetTemperature() << "" << sensor->GetPressure() << endl;
		}
	private:
		string name;
};