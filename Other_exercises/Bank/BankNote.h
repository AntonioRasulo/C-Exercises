/*Implementare una classe per la gestione della banconote di una banca.
Deve essere possibile aggiungere una banconota, sapere il numero di pezzi
per ogni tipo, conoscere il valore totale delle banconote.*/

#ifndef BANK_NOTE_H
#define BANK_NOTE_H

class BankNote
{
	private:
		int value;
	public:
		BankNote();
		BankNote(const int& value_);

		void setValue(const int& value_);

		int getValue() const;

		friend bool operator==(const BankNote& bn1, const BankNote& bn2);
		friend bool operator<(const BankNote& bn1, const BankNote& bn2);
};

#endif
