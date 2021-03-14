/*Claudio ama tenere in ordine le sue ricette.
Implementare una classe base astratta Ricetta e due sottoclassi di essa RicettaCotta e RicettaNonCotta.
Qualsiasi ricetta ha un titolo ed una descrizione, oltre ad un insieme di coppie ingrediente, quantita'.
Le istanze di RicettaCotta hanno anche un campo per indicare la durata ed il tipo della cottura.
Deve essere possibile aggiungere una ricetta. Ottenere in modo efficiente una ricetta dato il titolo.
Permettere di iterare sulle ricette.*/

#ifndef RECIPE_FACTORY_H
#define RECIPE_FACTORY_H

class RecipeFactory
{
	private:
		typedef  vector<const Recipe*> RecipeVec;
		RecipeVec ricettario;
	public:
		Recipe* Build(const string& line);

		void Insert(const Recipe* recipe_);

		~RecipeFactory();

		class Iterator
		{
			private:
                		RecipeVec::const_iterator iter;
                		const RecipeFactory* ptr_rf;

    		    	public:
                		Iterator(const RecipeFactory& rf_);

                		const Recipe* GetNext();                 //It's possible to scan the vector and check if there

                		bool HasNext() const;            //are present other elements

				const Recipe* GetRecipe(const string& title_);
		};

		friend class Iterator;

};

#endif
