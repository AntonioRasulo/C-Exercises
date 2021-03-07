/*Utilizzo di un iteratore su STL Vector*/

using namespace std;

#include<iostream>
#include<vector>

int main()
{
	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	
	vector<int>::iterator iter=v.begin();		//v.begin() restituisce un iteratore che punta al primo elemento
	for(; iter!=v.end(); iter++)				//Vai all'elemento successivo finchè non si punta alla fine
		cout << *iter << endl;
}
