/*Implementare una classe per la gestione della banconote di una banca.
Deve essere possibile aggiungere una banconota, sapere il numero di pezzi
per ogni tipo, conoscere il valore totale delle banconote.*/

using namespace std;

#include <map>
#include <iostream>
#include "BankNote.h"
#include "Bank.h"

Bank::Bank()
{

}

void Bank::Insert(const BankNote& bn_, const int& quantity_)
{
	/*map<BankNote,int>::iterator iter= m.begin();
	for(; iter!=m.end(); iter++)
		if((*iter)->first == bn_)
		{
			((*iter)->second)+=quantity_;
			return;
		}*/
	map<BankNote,int>::iterator iter = m.find(bn_);
	if(iter!=m.end())
	{
		(iter->second)+=quantity_;
                return;
	}
	m.insert(make_pair(bn_,quantity_));
}

void Bank::Insert(const BankNote& bn_)
{
	//map<BankNote,int>::iterator iter = m.begin();
	//for(; iter!=m.end(); iter++)
	map<BankNote,int>::iterator iter = m.find(bn_);
		//if((*iter)->first == bn_)
	if(iter!=m.end())	{
			(iter->second)++;
			return;
		}
	m.insert(make_pair(bn_,1));
}

void Bank::Print() const
{
	int total = 0;
	map<BankNote,int>::const_iterator iter = m.begin();
	for(; iter!=m.end(); iter++)
	{
		cout<<"Valore banconota: "<<(iter->first).getValue()<<" Totale: "<<(iter->first).getValue()*(iter->second)<<endl;
		total += (iter->first).getValue()*(iter->second);
	}
	cout<<"Totale soldi in banca: "<<total<<endl;
}
