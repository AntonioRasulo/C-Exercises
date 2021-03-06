/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/

#ifndef TABLE_H
#define TABLE_H

class Table{
	private:
		vector<int> t;
	public:
		Table();
		
		void Init();
		
		void restart();

		int extract();
};

#endif