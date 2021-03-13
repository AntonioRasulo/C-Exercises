/*Si realizzi un vettore di NumeroComplessi che permetta di sommare,
moltiplicare per uno scalare e stampare il vettore usando operator overloading.
Permettere di ottenere il numero complesso che ha parte immaginaria pari alla
mediana dei valori delle parti complesse. Permettere di scandire i numeri dall'esterno.*/

using namespace std;

#include <algorithm>
#include <vector>
#include <iostream>
#include "ComplexNumber.h"
#include "VectorCN.h"

struct Cmp
{
        inline bool operator()(const ComplexNumber cn1, const ComplexNumber cn2)
        {
                return cn1.imm < cn2.imm;
        }
};


VectorCN::VectorCN()
{
	vcn.clear();
}

VectorCN::~VectorCN()
{
	vcn.clear();
}

void VectorCN::Insert(const ComplexNumber& cn_)
{
	vcn.push_back(cn_);
	sort(vcn.begin(), vcn.end(), Cmp());
}

void VectorCN::Print()
{
	vector<ComplexNumber>::const_iterator iter=this->vcn.begin();
	for(; iter<vcn.end(); iter++)
		(*iter).Print();
}

VectorCN VectorCN::operator*(const float& num_)
{
	VectorCN vout;
	vector<ComplexNumber>::iterator iter=this->vcn.begin();

	for(;iter != this->vcn.end(); iter++)
	{
		(vout.vcn).push_back((*iter)*num_);
	}

	return vout;
}

VectorCN VectorCN::operator+(const VectorCN& vcn_)
{
	VectorCN vout;
	vector<ComplexNumber>::iterator iter=this->vcn.begin();
	vector<ComplexNumber>::const_iterator iter1=(vcn_.vcn).begin();

	if(this->vcn.size() > (vcn_.vcn).size())
	{
		for(;iter1!=(vcn_.vcn).end(); iter1++)
		{
			(vout.vcn).push_back((*iter)+(*iter1));
			iter++;
		}
		for(;iter!=(this->vcn.end()); iter++)
			(vout.vcn).push_back(*iter);
	}
	else
	{
		for(;iter!=this->vcn.end(); iter++)
                {
                        (vout.vcn).push_back((*iter)+(*iter1));
                        iter1++;
                }
                for(;iter1!=(vcn_.vcn).end(); iter1++)
                        (vout.vcn).push_back(*iter1);

	}

	return vout;
}

ostream& operator<<(ostream& out, const VectorCN& v)
{
	vector<ComplexNumber>::const_iterator iter=(v.vcn).begin();

	for(; iter<(v.vcn).end(); iter++)
	{
		out<<"CN: "<<(*iter).getReal()<<"+j"<<(*iter).getImm()<<"\n";
	}

	return out;
}

VectorCN::Iterator::Iterator(const VectorCN& cn_)
{
        ptr_cn = &cn_;
        iter = ptr_cn->vcn.begin();
}

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

ComplexNumber VectorCN::Median()
{
	int size = (this->vcn.size());
	ComplexNumber cn1;
	ComplexNumber cn2;
	if(!(size%2))
	{
		ComplexNumber cn1(this->vcn[size/2-1]);
		ComplexNumber cn2(this->vcn[size/2]);
		ComplexNumber cn3(0,(cn1.getImm() + cn2.getImm())/2);
		return cn3;
	}
	else
		return (this->vcn[(size+1)/2]);
}
