/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/

#include "Table.h"

int main()
{
	Table t;
	
	for(int i = 0; i<10; i++)
	{
		cout<<"Estrai numero: "<<t.extract()<<endl;
	}
	
	t.restart();
	
	for(int j = 0; j<20; j++)
	{
		cout<<"Estrai numero: "<<t.extract()<<endl;
	}
}