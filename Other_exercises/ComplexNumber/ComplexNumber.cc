/*Si realizzi un vettore di NumeroComplessi che permetta di sommare,
moltiplicare per uno scalare e stampare il vettore usando operator overloading.
Permettere di ottenere il numero complesso che ha parte immaginaria pari alla
mediana dei valori delle parti complesse. Permettere di scandire i numeri dall'esterno.*/

using namespace std;

#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
	real = 0;
	imm = 0;
}

ComplexNumber::ComplexNumber(const float& real_, const float& imm_)
{
	real = real_;
	imm = imm_;
}

ComplexNumber::ComplexNumber(const ComplexNumber& cn_)
{
	real = cn_.getReal();
	imm = cn_.getImm();
}

float ComplexNumber::getReal() const
{
	return real;
}

float ComplexNumber::getImm() const
{
	return imm;
}

void ComplexNumber::Print() const
{
	cout<<"Complex Number: "<< real<<"+j" <<imm<<endl;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& cn_)
{
	ComplexNumber cn((this->real)+cn_.real,(this->imm)+cn_.imm);
	return cn;
}

ComplexNumber ComplexNumber::operator*(const float& num_)
{
	ComplexNumber cn((this->real)*num_, (this->imm)*num_);
	return cn;
}

/*struct Cmp
{
	inline bool operator()(const ComplexNumber cn1, const ComplexNumber cn2)
	{
		return cn1.imm < cn2.imm;
	}
};*/
