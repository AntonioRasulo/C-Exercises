/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/
using namespace std;

#include <iostream>
#include <vector>
#include "Dice.h"

int main()
{
	Dice t;

	for(int i = 0; i<5; i++)
	{
		cout<<"Estrai numero: "<<t.Launch()<<endl;
	}
	
	cout <<"Print(): "<<endl;
	t.Print();
	t.Restart();

	 for(int i = 0; i<5; i++)
        {
                cout<<"Estrai numero: "<<t.Launch()<<endl;
        }

	cout<<"Print(): "<<endl;
	t.Print();

}
