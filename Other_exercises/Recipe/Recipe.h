/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

#ifndef RECIPE_H
#define RECIPE_H

class Recipe{
	protected:
		string title;
		string description;
		map<string,float> ingredients;
	public:
		Recipe();
		Recipe(const string& title_, const string& description_, const string& ingredient_,const float& quantity_ );
		Recipe(const string& title_, const string& description_);

		void setTitle(const string& title_);
		void setDescription(const string& description_);

		string getTitle() const;

		void Insert(const string& ingredient_, const float& quantity_);

		virtual void Print() const= 0;

		virtual void setDurata(const float& durata_) = 0;
		virtual void setType(const string& type_) = 0;
};

#endif
