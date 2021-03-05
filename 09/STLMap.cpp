/*Bag of words. Example of STL Map*/

using namespace std;
#include<map>
#include<string>
#include<iostream>
#include<fstream>

int main()
{
	map<string,int> freq;		//dizionario parole->frequenza
	ifstream is("bagofwords.txt");
	if(!is.good())
	{
		cerr<<"File non trovato";
		return 0;
	}
	string word;
	while(is>>word)				//Leggo parole dall'input
	{
		freq[word]++;
	}
	map<string,int>::const_iterator iter;
	for( iter = freq.begin(); iter!=freq.end(); ++iter)		//Iteratore ritorna pair:
		cout<<iter->first<<"->"<<iter->second<<endl;		//iter->first: chiave 
															//iter->second:valore
	iter = freq.find("pippo");				//Ricerche su mappa tramite find
	if(iter != freq.end())
		cout<<"pippo "<<iter->second<<endl;
	return 0;
		
}															