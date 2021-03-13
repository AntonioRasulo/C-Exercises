/*Si realizzi un vettore di NumeroComplessi che permetta di sommare,
moltiplicare per uno scalare e stampare il vettore usando operator overloading.
Permettere di ottenere il numero complesso che ha parte immaginaria pari alla
mediana dei valori delle parti complesse. Permettere di scandire i numeri dall'esterno.*/

using namespace std;

#include <vector>
#include <iostream>
#include "ComplexNumber.h"
#include "VectorCN.h"

inline ComplexNumber VectorCN::Iterator::GetNext()                  //It's possible to scan the vector and check if there
{
        ComplexNumber tmp(*iter);
        ++iter;
        return tmp;
}

inline bool VectorCN::Iterator::HasNext() const
{
        return ( iter != ptr_cn->vcn.end());               //are present other elements
}



int main()
{
	ComplexNumber c1(35,17);
	ComplexNumber c2(22,34);
	ComplexNumber c3(11,2);
	VectorCN v1;
	VectorCN v2;
	VectorCN v3;

	v1.Insert(c2);
        v1.Insert(c1);
	//v1.Insert(c3);

	VectorCN::Iterator iter(v1);

	/*while(iter.HasNext())
	{
		ComplexNumber tmp(iter.GetNext());
		tmp.Print();
	}*/
	//cout<<v1<<endl;

	ComplexNumber c4;
	c4=v1.Median();

	c4.Print();
}
