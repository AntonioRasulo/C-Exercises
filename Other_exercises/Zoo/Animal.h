/*Si deve realizzare un insieme di classi per modellare gli animali di uno zoo:
leone, elefante e gatto. Ogni animale vien definito da un suo nome, peso, numero di zampe e gradi di pericolosità.
Un leone contiene anche il numero di persone mangiate.
Gli animali possono essere controllati attraverso un insieme di operazioni:
- mangia(float peso_cibo): la funzione deve anche aggiornare il peso dell'animale
- emettere_suono(): che ritorna la stringa corrispondente al suono (miao per il gatto, ecc)
Il leone puo' anche mangiare una persona.*/

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
	protected:
		string name;
		float weight;
		int num_leg;
		int dangerous_grade;
	public:
		Animal();
		Animal(const string& name_,const float weight_,const int num_leg_,const int dangerous_grade_);
		~Animal();

		string getName();
		float getWeight();
		int getGrade();
		int getLeg();

		void setName(const string& name_);
		void setWeight(const float weight_);
		void setGrade(const int grade_);
		void setLeg(const int leg_);

		void Eat(const float food);

		virtual void Sound() = 0;
		virtual Animal* Clone() const = 0;
};

#endif
