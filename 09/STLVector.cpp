/*Esempio dell'utilizzo dello Standard Template "Vector"*/

using namespace std;
#include <vector>
#include <iostream>

int main()
{
	vector<int> v;
	v.reserve(3);		//So che la dimensione del vettore sarà 3, per cui dico subito alla classe di allocare 3 elementi
						//Se non c'è l'allocazione della memoria viene fatta dalla classe in modo automatico
	v.push_back(10);
	v.push_back(3);
	v.push_back(5);
	
	for(int i=0; i<v.size(); i++)
		cout << v[i] <<endl;
}
