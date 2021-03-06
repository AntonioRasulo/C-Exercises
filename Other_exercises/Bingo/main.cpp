/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/
using namespace std;
#include "Table.h"
#include <iostream>

int main()
{
	Table t;
	
	for(int i = 0; i<5; i++)
	{
		cout<<"Estrai numero: "<<t.extract()<<endl;
	}
	
	t.restart();
cout<<"Test :"<<t.extract()<<endl;
cout<<"Stampo la tabell"<<endl;	
t.Print();
	cout<<"Nuova estrazione"<<endl;
	
	for(int j = 0; j<5; j++)
	{
		cout<<"Estrai numero: "<<t.extract()<<endl;
	}

	t.restart();

        cout<<"Nuova estrazione"<<endl;

        for(int j = 0; j<5; j++)
        {
                cout<<"Estrai numero: "<<t.extract()<<endl;
        }

	t.restart();

        cout<<"Nuova estrazione"<<endl;

        for(int j = 0; j<5; j++)
        {
                cout<<"Estrai numero: "<<t.extract()<<endl;
        }

	t.restart();

        cout<<"Nuova estrazione"<<endl;

        for(int j = 0; j<5; j++)
        {
                cout<<"Estrai numero: "<<t.extract()<<endl;
        }




}
