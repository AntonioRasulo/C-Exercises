/*StackProf*/

using namespace std;
#include <iostream>
#include "StackProf.h"

int main()
{
	Stack<int> pila;
	int in;
	for(int i=0; i<10; ++i){
		cout<<"inserisci un numero intero"<<endl;
		cin >> in;
		//std::cout<<"Add"<< in << std::endl;
		pila.Push(in);
	}
	
	while(!pila.Empty()){
		std::cout<<"Pop"<<pila.Pop()<<std::endl;
	}
	
	return 0;
	
}
