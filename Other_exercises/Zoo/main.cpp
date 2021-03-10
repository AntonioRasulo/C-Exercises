/*Si deve realizzare un insieme di classi per modellare gli animali di uno zoo:
leone, elefante e gatto. Ogni animale vien definito da un suo nome, peso, numero di zampe e gradi di pericolosità.
Un leone contiene anche il numero di persone mangiate.
Gli animali possono essere controllati attraverso un insieme di operazioni:
- mangia(float peso_cibo): la funzione deve anche aggiornare il peso dell'animale
- emettere_suono(): che ritorna la stringa corrispondente al suono (miao per il gatto, ecc)
Il leone puo' anche mangiare una persona.*/

using namespace std;

#include <string>
#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Lion.h"
#include "Elephant.h"

int main()
{
	Lion l("Leone", 3,4,5,4);
	Cat c("Gatto", 5 ,3,2);
	Elephant e("Elefante", 4,2,3);

	l.Sound();
	c.Sound();
	e.Sound();

}
