/*Ordinare in modo decrescente STL Map usando std::greater<T>*/
using namespace std;
#include<iostream>
#include<map>

template<typename T> struct greater{					//In questo caso conviene utilizzare il comparatore templetizzato std::greater.
		bool operator()(const T& a, const T& b) const	//Attenzione: greater necessita che operator> sia definito
		{
			return b>a;	
		}
};
	
int main()
{
	
	
	map<int, string, std::greater<int> > mappa;
	mappa[3] = "ciao";
	mappa[5] = "ciacai";
	mappa[2] = "ciaociao";
	map<int, string, std::greater<int>>::const_iterator iter = mappa.begin();
	for(; iter!=mappa.end(); ++iter)
		cout<< iter->first<< "->" <<iter->second<<endl;
	
}