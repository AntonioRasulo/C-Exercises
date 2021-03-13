/*Si realizzi un vettore di NumeroComplessi che permetta di sommare,
moltiplicare per uno scalare e stampare il vettore usando operator overloading.
Permettere di ottenere il numero complesso che ha parte immaginaria pari alla
mediana dei valori delle parti complesse. Permettere di scandire i numeri dall'esterno.*/

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

class ComplexNumber{
	private:
		float real;
		float imm;
	public:
		ComplexNumber();

		ComplexNumber(const float& real_, const float& imm_);

		ComplexNumber(const ComplexNumber& cn_);

		float getReal() const;

		float getImm() const;

		void Print() const;

		ComplexNumber operator+(const ComplexNumber& cn_);

		ComplexNumber operator*(const float& num_);

		friend struct Cmp;
};

#endif 
