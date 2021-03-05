/*Esercizio: creare una gerarchia di classi per gestire le persone che lavorano o studiano all'università
	--> Persone sono studenti o ricercatori o docenti o ammistratori
	--> Tutti hanno nome, luogo di nascita, indirizzo di lavoro
	--> Studenti hanno inoltre facoltà e corso che frequentano
	--> Ricercatori l'argomento di ricerca
	--> Docenti i corsi che insegnano
Deve essere possibile salvare o rileggere ogni persona su/da una stringa che ne codifica le sue caratteristiche.
Definire una classe che definisce un Dipartimento come un insieme di persone (usa std::vector)
	--> Deve essere possibile stampare su file la stringa 
		descrittiva di tutte le persone del Dipartimento*/
		
using namespace std;
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include "People.h"

class Dipartimento{
	private:
		vector<People*> v;
	public:
		
		Dipartimento(){
			this->Clear();
		}
		
		Dipartimento(People* p){
			//People* pointer = new People;
			//pointer = p;
			v.push_back(p);
		}
		
		~Dipartimento(){
			this->Clear();
		}
		
		void Insert(People* p)
		{
			v.push_back(p);
		}
		
		void Clear()
		{
			vector<People*>::iterator iter=this->v.begin();
			for(; iter!=v.end(); iter++)
				if(*iter != NULL)
					delete *iter;
			v.clear();
		}
		
		void Print()
		{
			vector<People*>::iterator iter=this->v.begin();
			for(; iter!=v.end(); iter++)
				if(*iter != NULL)
					(*iter)->Print();
		}
		
};

int main()
{
	People* p = NULL;
	Dipartimento d;
	string in;
	bool h;
	
	while(1)
	{
			cout<<"Cosa vuoi generare"<<endl;
			cin >>in;


			if(in == "Student")
			{
				p = new Student();
				cout << "Inserisci facolta" <<endl;
				cin >> in;
				p->setFacolta(in);
				cout << "Inserisci corso" <<endl;
				cin >> in;
				p->setCorso(in);	h= true;
			}
			else if(in == "Researcher")
			{
				p = new Researcher();
				cout << "Inserisci campo di ricerca" <<endl;
				cin >> in;
				p->setField(in);
				cout << "Inserisci facolta" <<endl;
				cin >> in;
				p->setFacolta(in);
				cout << "Inserisci corso" <<endl;
				cin >> in;
				p->setCorso(in);	h= true;
			}
			else if(in == "Teacher")
			{
				p = new Teacher;
				cout << "Inserisci corso di insegnamento" <<endl;
				cin >> in;
				p->setCourse(in);	h=true;
			}
			else
			{
				h = false;
				cout<<"Invalid expression"<<endl;
			}

			if(h)
			{
				cout << "Inserisci nome" <<endl;
				cin >> in;
				p->setNome(in);
				cout << "Inserisci luogo di nascita" <<endl;
				cin >> in;
				p->setBornPlace(in);
				cout << "Inserisci indirizzo di lavoro" <<endl;
				cin >> in;
				p->setWorkPlace(in);
				d.Insert(p);
				d.Print();
			}
	
	}
	
}
