/*Un docente deve gestire i voti assegnati ai suoi studenti.
Creare una classe per la gestione dei voti. Deve essere possibile leggere
da file l'insieme di nomi delle persone che frequentano un corso e relativo
voto associato, permettere la ricerca del voto dato il nome di uno studente.
Permettere la stampa di tutti gli studenti e voti in sequenza.
	Suggerimenti:
		--> Creare una classe che contenga una mappa nome-->voto
		--> Un costruttore prende il nome del file da cui caricare i dati
		--> Fornire un metodo per la ricerca del voto a partire dal nome
Nome file: Studenti.txt
*/
		
using namespace std;
#include<map>
#include<iostream>
#include<fstream>

class Reader{
	private:
		map<string,int> m;
		
		map<string,int>::const_iterator iter;
		std::ifstream is;
		bool flag;
	public:
	Reader(const string& s)
	{
		string word;
		string tmp;
		flag = false;
		
		is.open(s);
		if(!is.good())
		{
			cerr <<"Non posso aprire il file\n";
			//return 0;
		}
		
		while(is>>word)
		{
			if(!flag)
			{	
				tmp = word;
				flag = true;
			}
			else
			{
				flag = false;
				m.insert(make_pair(tmp, stoi(word)));
			}
		}	
		
	}
	
/*	void Mapping()
	{
		string word;
		string tmp;
		flag = false;
		while(is>>word)
		{
			if(!flag)
			{	
				tmp = word;
				flag = true;
			}
			else
			{
				flag = false;
				m.insert(make_pair(tmp, atoi(word)));
			}
		}
	}*/
	
	
	
	
		void Find(const string& nome)
		{
			/*for( iter = freq.begin(); iter!=freq.end(); ++iter)		//Iteratore ritorna pair:
				cout<<iter->first<<"->"<<iter->second<<endl;		//iter->first: chiave */
															//iter->second:valore
			iter = m.find(nome);				//Ricerche su mappa tramite find
			if(iter != m.end())
				cout<< nome <<iter->second<<endl;
		}
		
	
	
};

int main()
{
	Reader r("Studenti.txt");
	r.Find("Antonio");
	
	r.Find("Piero");
}