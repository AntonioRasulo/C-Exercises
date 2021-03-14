/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

using namespace std;

#include <string>
#include <map>
#include "Recipe.h"

Recipe::Recipe()
{
	title = "";
	description = "";
	ingredients.insert(make_pair("",0.0));
}

Recipe::Recipe(const string& title_, const string& description_, const string& ingredient_,const float& quantity_ )
{
	title = title_;
	description = description_;
	ingredients.insert(make_pair(ingredient_,quantity_));
}

Recipe::Recipe(const string& title_, const string& description_)
{
	title = title_;
	description = description_;
	ingredients.insert(make_pair("",0.0));
}

string Recipe::getTitle() const
{
	return title;
}

void Recipe::setTitle(const string& title_)
{
	title = title_;
}

void Recipe::setDescription(const string& description_)
{
	description = description_;
}

void Recipe::Insert(const string& ingredient_, const float& quantity_)
{
	ingredients.insert(make_pair(ingredient_,quantity_));
}
