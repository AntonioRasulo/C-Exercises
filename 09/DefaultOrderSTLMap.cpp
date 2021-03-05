/*Example Ordinamento di defualt STL Map*/
using namespace std;
#include<map>
#include<iostream>

int main()
{
	map<string,int> m;
	m["ciao"] =4;
	m["hey"] = 1;
	m["oi"]	= 2;
	m["egrgr"] = 3;
	for(map<string,int>::iterator i= m.begin(); i!=m.end(); i++)	//Stampa le pair del map ordinati in ordine alfabetico della chiave
		cout<<i->first<<" "<<i->second<<endl;
}