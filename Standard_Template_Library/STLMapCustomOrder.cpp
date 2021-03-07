/*Esempio, ordinare in modo decrescente*/
using namespace std;
#include<map>
#include<iostream>

struct Cmp{
	bool operator()(const int& a, const int& b){	//Dichiarazione di classe comparatore
		return b<a;									//Con b<a, ordino in modo decrescente, con a<b ordino in modo crescente (default)
	}
};


int main()
{
	map< int, string, Cmp> mappa;
	mappa[3] = "ciao";
	mappa[5] = "ciacai";
	mappa[2] = "ciaociao";
	map<int, string, Cmp>::const_iterator iter = mappa.begin();
	for(; iter!=mappa.end(); ++iter)
		cout<< iter->first<< "->" <<iter->second<<endl;
}