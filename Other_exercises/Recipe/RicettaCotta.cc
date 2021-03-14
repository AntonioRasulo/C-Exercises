/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

using namespace std;

#include <map>
#include <string>
#include <iostream>
#include "RicettaCotta.h"

RicettaCotta::RicettaCotta(const string& title_, const string& description_,const string& ingredient_,
				const float& quantity_,const float& durata_, const string& type_)
{
	title = title_;
	description = description_;
	ingredients.insert(make_pair(ingredient_,quantity_));
	durata = durata_;
	type = type_;
}

RicettaCotta::RicettaCotta()
{
	title = "";
	description = "";
	ingredients.insert(make_pair("",0.0));
	durata = 0.0;
	type = "";
}

RicettaCotta::RicettaCotta(const string& title_, const string& description_, const float& durata_, const string& type_)
{
	title = title_;
	description = description_;
	durata = durata_;
	type = type_;
}

void RicettaCotta::Print() const
{
	map<string,float>::const_iterator iter = ingredients.begin();
	cout<<"Title: "<<title<<endl;
	cout<<"Description: "<<description<<endl;
	cout<<"Durata: "<<durata<<endl;
	cout<<"Type: "<<type<<endl;
	for(; iter!=ingredients.end(); iter++)
		cout<<"Ingredient: "<<iter->first<<" Quantity: "<<iter->second<<endl;
}

void RicettaCotta::setDurata(const float& durata_)
{
	durata = durata_;
}

void RicettaCotta::setType(const string& type_)
{
	type = type_;
}
