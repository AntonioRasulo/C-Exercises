/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

using namespace std;

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Recipe.h"
#include "RicettaCotta.h"
#include "RicettaCruda.h"
#include "RecipeFactory.h"

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


int main()
{
	RecipeFactory rf;
	Recipe* rcotta;
	Recipe* rcruda;
	const Recipe* rsearch;

	RecipeFactory::Iterator iter(rf);

	rcruda = rf.Build("RicettaCruda");
	rcotta = rf.Build("RicettaCotta");

	rcotta->setTitle("Pasta al pesto");
	rcotta->setDescription("La pasta al pesto è un piatto tipico ligure");
	rcotta->setDurata(10.0);
	rcotta->setType("Cottura Pasta");
	rcotta->Insert("Pasta",150.0);
	rcotta->Insert("Pesto", 40.0);

	rcruda->setTitle("Prosciutto e popone");
	rcruda->setDescription("Prosciutto crudo arrotolato intorno ad una fetta di popone");
	rcruda->Insert("Prosciutto crudo", 80.0);
	rcruda->Insert("Popone", 400.0);

	rf.Insert(rcotta);
	rf.Insert(rcruda);

	rsearch = iter.GetRecipe("Pasta al pesto");
	rsearch->Print();
}
