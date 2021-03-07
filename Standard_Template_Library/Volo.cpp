/*Esercizio:
	--> Realizzare una classe per la gestione dei voli di una compagnia aerea
	--> Si deve caricare le persone che viaggieranno su ogni volo da file
	--> Permettere alla polizia di cercare se una certa persona viaggia
		su un certo volo
	Suggerimento:
		usare map<string,set<string>>
		inteso come map<codice volo, set<persone su un volo>>
Nome file: "volo.txt"*/
		
using namespace std;
#include<map>
#include<set>
#include<string>
#include<fstream>
#include<iostream>

class Read
{
	private:
		ifstream is;
		map<string, set<string>> mappa;
		
	public:
		
		Read(const string& s)
		{
			string word, tmp;
			bool flag = false;
			set<string> insieme;
			int cnt = 0;
			is.open(s);
			if(!is.good())
				cerr<<"File non trovato\n";
			while(is>>word)
			{
				if(!flag)
				{
					tmp = word;
					flag = true;
				}
				else if(cnt!=3)
				{
					insieme.insert(word);
					cnt++;
				}
				
				if(cnt==3)
				{
					cnt = 0;
					mappa.insert(make_pair(tmp, insieme));
					insieme.clear();
					flag = false;
				}
				
			}
		}
	
		void Find(const string& volo, const string& nome)
		{
			
			map<string,set<string>>::const_iterator iter;
			set<string>::const_iterator iterset;
			
			iter = mappa.find(volo);
			
			if(iter != mappa.end())
			{
				iterset = ((iter->second).find(nome));
				if(iterset != ((iter->second).end()))
					cout<<"Trovato sul volo"<<endl;
				else
					cout<<"Non presente sul volo"<<endl;
			}
		}
};

int main()
{
	Read r("volo.txt");
	r.Find("3424","Luis");
}