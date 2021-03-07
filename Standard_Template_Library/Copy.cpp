/*Copy*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

void function(int i){cout<<" "<<i;}

int main()
{
	vector<int> vec;
	list<int>	l;
	for(int i=0; i<100; ++i)
		vec.push_back(rand());
	
	copy(vec.begin(), vec.end(), l.begin());			//Copia il vettore nella lista
	copy(vec.begin()+5, vec.end()+30, l.begin());	//Per copiare solo una parte 
}