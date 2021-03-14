/*Implementare una classe per la gestione della banconote di una banca.
Deve essere possibile aggiungere una banconota, sapere il numero di pezzi
per ogni tipo, conoscere il valore totale delle banconote.*/

#include "BankNote.h"

BankNote::BankNote()
{
	value = 0;
}

BankNote::BankNote(const int& value_)
{
	value = value_;
}

void BankNote::setValue(const int& value_)
{
	value = value_;
}

int BankNote::getValue() const
{
	return value;
}

bool operator==(const BankNote& bn1, const BankNote& bn2)
{
	return (bn1.getValue() == bn2.getValue());
}

bool operator<(const BankNote& bn1, const BankNote& bn2)
{
	return(bn1.getValue() < bn2.getValue());
}
