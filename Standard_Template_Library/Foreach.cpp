/*Foreach example*/

using namespace std;
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<iostream>

void function(int i){cout<<" "<<i;}

struct FunctionClass{
	void operator()(int i){
		cout<<" "<<i;
	}
}function_class;

int main()
{
	vector<int> vec;
	for(int i=0; i<100; ++i)
		vec.push_back(rand());
	for_each(vec.begin(), vec.end(), function);			//Modo 1: applica function ad ogni elemento. function passata tramite puntatore alla funzione!
	cout<<"\n";
	for_each(vec.begin()+4, vec.end(), function_class);	//Modo 2: applica operator() ad ogni elemento. Si passa una classe che fa overloading di operator()
														//E' possibile applicare l'operator() solo ad una parte del vettore
}