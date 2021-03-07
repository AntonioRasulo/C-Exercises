/*Creare una gerarchia di classi per gestire le persone che lavorano o studiano all'università
	-->Persone sono studenti o ricercatori o docenti
	-->Tutti hanno nome, luogo di nascita, indirizzo di lavoro
	-->Studenti hanno inoltre facoltà e corso che frequentano
	-->Ricercatori l'argomento di ricerca
	-->Docenti i corsi che insegnano
	-->Tutte le persone implementano il metodo ToString()
Realizzare una classe Dipartimento per gestire un insieme di persone
	-->Deve essere possibile scrivere/leggere le persone da file
	-->Suggerimento: la lettura farla con il design pattern Factory*/

#include "Dipartimento.h"
#include<bits/stdc++.h> 

class PersonFactory{
	public:
		
		People* Build(const string& line)
		{
			string word, nome, luogonascita, indirizzolavoro, corso, facolta;
			string field;
			string course;
			string tipo;
			int cnt = 0;
			People* p = NULL;
			stringstream iss(line);
			while(iss>>word)
			{
				if(!cnt)
				{
					if(word == "Student:")
					{
						p = new Student();
						tipo = word;
					}
					else if(word == "Researcher:")
					{
						p = new Researcher();
						tipo = word;
					}
					else if(word == "Teacher:")
					{
						p = new Teacher();
						tipo = word;
					}
					cnt++;
				}
				else
				{
					switch(cnt)
					{
						case 1:
							p->setNome(word);
							cnt++;
							break;
						case 2:
							p->setBornPlace(word);
							cnt++;
							break;
						case 3:
							p->setWorkPlace(word);
							cnt++;
							break;
						case 4:
							if(tipo == "Teacher")
								p->setCourse(word);
							else
								p->setCorso(word);
							cnt++;
							break;
						case 5:
							p->setFacolta(word);
							cnt++;
							break;
						case 6:
							p->setField(word);
							cnt++;
							break;
						default:
							cout<<"Qualcosa non va, cnt: "<<cnt<<endl;
					}
				}
			}
			
			return p;
			
		}
};

int main()
{
	string line;
	Dipartimento d;
	PersonFactory pf;
	ifstream is("../09/People.txt");
	if(!is.good())
		cerr<<"File non trovato\n";
	while(getline(is,line))
	{//cout<<"hey"<<endl;
		d.Insert(pf.Build(line));
		cout<<"Viene inserito nel dipartimento: ";
		(pf.Build(line))->PrintScreen();
	}
	d.PrintScreen();
	
}