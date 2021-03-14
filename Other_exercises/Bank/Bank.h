/*Implementare una classe per la gestione della banconote di una banca.
Deve essere possibile aggiungere una banconota, sapere il numero di pezzi
per ogni tipo, conoscere il valore totale delle banconote.*/

#ifndef BANK_H
#define BANK_H

class Bank{
	private:
		map<BankNote,int> m;
	public:
		Bank();

		void Insert(const BankNote& bn_, const int& quantity_);

		void Insert(const BankNote& bn_);

		void Print() const;
};

#endif
