/*Example of using SparseVector*/

using namespace std;
#include "SparseVector.h"
#include<iostream>

int main()
{
	SparseVector<float> vec;
	
	vec.Set(2, 5.0);
	
	vec.Set(20, 2.0);

	vec.Set(5, 6.0);
	
	SparseVector<float>::Iterator iter(vec);
	
	while(iter.HasNext())
	{
		SparseVector<float>::Element e = iter.GetNext();	//Possibile iterare senza avere accesso diretto agli elementi del vettore
		std::cout << e.i << "::" << e.value <<std::endl;
	}
}