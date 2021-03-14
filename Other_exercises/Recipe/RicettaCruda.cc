/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

using namespace std;

#include <string>
#include <map>
#include <iostream>
#include "RicettaCruda.h"

RicettaCruda::RicettaCruda(const string& title_, const string& description_,const string& ingredient_,const float& quantity_)
{
        title = title_;
        description = description_;
        ingredients.insert(make_pair(ingredient_,quantity_));
}

RicettaCruda::RicettaCruda()
{
        title = "";
        description = "";
        ingredients.insert(make_pair("",0.0));
}

RicettaCruda::RicettaCruda(const string& title_, const string& description_)
{
        title = title_;
        description = description_;
}

void RicettaCruda::Print() const
{
        map<string,float>::const_iterator iter = ingredients.begin();
        cout<<"Title: "<<title<<endl;
        cout<<"Description: "<<description<<endl;

        for(; iter!=ingredients.end(); iter++)
                cout<<"Ingredient: "<<iter->first<<" Quantity: "<<iter->second<<endl;
}

void RicettaCruda::setType(const string& type_)
{

}

void RicettaCruda::setDurata(const float& durata_)
{

}
