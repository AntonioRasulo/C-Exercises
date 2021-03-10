/*Si deve realizzare un insieme di classi per modellare gli animali di uno zoo:
leone, elefante e gatto. Ogni animale vien definito da un suo nome, peso, numero di zampe e gradi di pericolosità.
Un leone contiene anche il numero di persone mangiate.
Gli animali possono essere controllati attraverso un insieme di operazioni:
- mangia(float peso_cibo): la funzione deve anche aggiornare il peso dell'animale
- emettere_suono(): che ritorna la stringa corrispondente al suono (miao per il gatto, ecc)
Il leone puo' anche mangiare una persona.*/

#ifndef LION_H
#define LION_H

#include "Animal.h"

class Lion: public Animal
{
	protected:
		int eaten_person; 

	public:

                Lion(const string& name_, const float weight_, const int num_leg_, const int dangerous_grade_, const int eaten_person_);

                Lion(const Lion& leo);

		Lion();

                virtual void Sound();

                virtual Animal* Clone() const;

		virtual void EatPerson();

		virtual void setEatenPerson(const int& eaten);
};

#endif 
