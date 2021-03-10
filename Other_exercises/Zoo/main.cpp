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
#include <vector>
#include "Animal.h"
#include "Cat.h"
#include "Lion.h"
#include "Elephant.h"
#include "Zoo.h"

int main()
{
	Animal* p = NULL;
	Zoo z;
	string in;
	int tmp;
	bool h;

	while(1)
	{
		cout<<"Cosa vuoi generare"<<endl;
		cin >>in;


		if(in == "Lion")
		{
			p = new Lion();
			cout << "Inserisci nome" <<endl;
			cin >> in;
			p->setName(in);
			cout << "Inserisci Peso" <<endl;
			cin >> tmp;
			p->setWeight(tmp);
			cout<<"Inserisci numero di persone mangiate"<<endl;
			cin>>tmp;
			p->setEatenPerson(tmp);
			//p->EatPerson();
			h= true;
		}
		else if(in == "Cat")
		{
			p = new Cat();
			cout << "Inserisci nome" <<endl;
			cin >> in;
			p->setName(in);
			cout << "Inserisci peso" <<endl;
			cin >> tmp;
			p->setWeight(tmp);
			h= true;
		}
		else if(in == "Elephant")
		{
			p = new Elephant();
                        cout << "Inserisci nome" <<endl;
                        cin >> in;
                        p->setName(in);
                        cout << "Inserisci peso" <<endl;
                        cin >> tmp;
                        p->setWeight(tmp);
                        h= true;
		}
		else
		{
			h = false;
			cout<<"Invalid expression"<<endl;
		}

		if(h)
		{
		/*	cout << "Inserisci nome" <<endl;
			cin >> in;
			p->setNome(in);
			cout << "Inserisci luogo di nascita" <<endl;
			cin >> in;
			p->setBornPlace(in);
			cout << "Inserisci indirizzo di lavoro" <<endl;
			cin >> in;
			p->setWorkPlace(in);*/
			z.Insert(p);
		//	d.Print();
		}

	}
}
