/*Creare un software per linguisti che permetta di creare le statistiche			
parola->num_occorrenze di un testo caricato da file
	Suggerimenti:
		--> Creare classe in cui il costruttore legge un testo da file
			e popola una mappa stringa->num_occorrenze
		--> Aggiungere un metodo per stampare gli elementi
Nome testo: Loremipsum.txt
NOTA: in che ordine sono stampati gli elementi?*/

using namespace std;

#include<map>
#include<iostream>
#include<fstream>
#include<string>

class Reader{
	private:
		map<string,int> m;
		string word;
		map<string,int>::const_iterator iter;
	
	public:
	
	//Reader(ifstream& in)
	void Read(ifstream& is)
	{
		while(is>>word)				//Leggo parole dall'input
		{
			m[word]++;
		}
	}
	
	void Print()
	{
		for( iter = m.begin(); iter!=m.end(); ++iter)		
			cout<<iter->first<<"->"<<iter->second<<endl;	
	}
};

int main()
{
	ifstream is("LoremIpsum.txt");
	if(!is.good())
	{
		cerr <<"Non posso aprire il file\n";
		return 0;
	}
	
		//ifstream is("LoremIpsum.txt");
	Reader r;
	r.Read(is);
	r.Print();
}