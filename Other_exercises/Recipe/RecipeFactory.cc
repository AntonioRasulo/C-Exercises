/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/
using namespace std;

#include <iostream>
#include <map>
#include <vector>
#include "Recipe.h"
#include "RecipeFactory.h"
#include "RicettaCotta.h"
#include "RicettaCruda.h"

Recipe* RecipeFactory::Build(const string& line)
{
	 if(line=="RicettaCotta")        return new RicettaCotta();
         else if (line=="RicettaCruda")  return new RicettaCruda();
         else    return NULL;
}

void RecipeFactory::Insert(const Recipe* recipe_)
{
	ricettario.push_back(recipe_);
}

RecipeFactory::Iterator::Iterator(const RecipeFactory& rf_)
{
	ptr_rf = &rf_;
        iter = ptr_rf->ricettario.begin();
}

RecipeFactory::~RecipeFactory()
{
	vector<const Recipe*>::iterator iter = ricettario.begin();
        for(;iter!=ricettario.end(); iter++)
                delete *iter;

	ricettario.clear();
}

inline const Recipe* RecipeFactory::Iterator::GetNext()
{
	const Recipe* tmp;
	tmp = *iter;
        ++iter;
	return tmp;
}


inline bool RecipeFactory::Iterator::HasNext() const
{
        return ( iter != ptr_rf->ricettario.end());               //are present other elements
}

inline const Recipe* RecipeFactory::Iterator::GetRecipe(const string& title_)
{
	for(iter = ptr_rf->ricettario.begin(); iter != ptr_rf->ricettario.end(); iter++)
	{
		if((*iter)->getTitle() == title_)
			return *iter;
	}
		cout<<"Recipe don't found"<<endl;
		return NULL;
}
