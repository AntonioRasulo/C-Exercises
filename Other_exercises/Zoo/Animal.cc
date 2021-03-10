/*Si deve realizzare un insieme di classi per modellare gli animali di uno zoo:
leone, elefante e gatto. Ogni animale vien definito da un suo nome, peso, numero di zampe e gradi di pericolosità.
Un leone contiene anche il numero di persone mangiate.
Gli animali possono essere controllati attraverso un insieme di operazioni:
- mangia(float peso_cibo): la funzione deve anche aggiornare il peso dell'anima>
- emettere_suono(): che ritorna la stringa corrispondente al suono (miao per il>
Il leone puo' anche mangiare una persona.*/

using namespace std;

#include <string>
#include "Animal.h"

Animal::Animal()
{
	name.empty();
	weight = 0;
	num_leg = 0;
	dangerous_grade = 0;
}

Animal::Animal(const string& name_,const float weight_,const int num_leg_,const int dangerous_grade_)
{
	name = name_;
	weight = weight_;
	num_leg = num_leg_;
	dangerous_grade = dangerous_grade_;
}

Animal::~Animal()
{
	name.empty();
	weight = 0;
	num_leg = 0;
	dangerous_grade = 0;
}

string Animal::getName()
{
	return name;
}

float Animal::getWeight()
{
	return weight;
}

int Animal::getLeg()
{
	return num_leg;
}

int Animal::getGrade()
{
	return dangerous_grade;
}

void Animal::setName(const string& name_)
{
	name = name_;
}

void Animal::setWeight(const float weight_)
{
	weight = weight_;
}

void Animal::setLeg(const int leg_)
{
	num_leg = leg_;
}

void Animal::setGrade(const int grade_)
{
	dangerous_grade = grade_;
}

void Animal::Eat(const float food)
{
	weight+=food;
}
