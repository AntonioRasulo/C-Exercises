/*Creare una gerarchia di classi per gestire le persone che lavorano o studiano all'università
	-->Persone sono studenti o ricercatori o docenti
	-->Tutti hanno nome, luogo di nascita, indirizzo di lavoro
	-->Studenti hanno inoltre facoltà e corso che frequentano
	-->Ricercatori l'argomento di ricerca
	-->Docenti i corsi che insegnano
Realizzare una classe dipartimento per gestire un insieme di persone:
	-->Fornire una modalità per scandire le persone
	-->Suggerimento: usare design pattern Iterator
*/

using namespace std;
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include "../09/People.h"
#include "VectorDepartment.h"

class Department
{
	private:
		typedef VectorDepartment<People*> def;
		def v;
	
	public:
		void Clear()
		{
			def::Iterator iter(v);
			
			while(iter.HasNext())
			{
				iter.Delete();
			}
		}
		
		Department(){
			this->Clear();
		}
		
		Department(People* p){
			v.Set(p);
		}
		
		~Department(){
			this->Clear();
		}
		
		void Insert(People* p)
		{
			v.Set(p);
		}
		
		void Print()
		{
			def::Iterator iter(v);
			
			while(iter.HasNext())
			{
				def::Element e = iter.GetNext();
				(e.value)->PrintScreen();
			}
		}
		
};

int main()
{
	People* p = NULL;
	Department d;
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
