/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

#ifndef RICETTA_COTTA_H
#define RICETTA_COTTA_H

#include "Recipe.h"

class RicettaCotta: public Recipe
{
	protected:
		float durata;
		string type;
	public:
		RicettaCotta(const string& title_, const string& description_,const string& ingredient_,
				const float& quantity_,const float& durata_, const string& type_);
		RicettaCotta();
		RicettaCotta(const string& title_, const string& description_, const float& durata_, const string& type_);

		virtual void Print() const;

		virtual void setDurata(const float& durata_);
		virtual void setType(const string& type_);
};

#endif
