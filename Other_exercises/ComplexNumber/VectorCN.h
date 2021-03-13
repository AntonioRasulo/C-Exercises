/*Si realizzi un vettore di NumeroComplessi che permetta di sommare,
moltiplicare per uno scalare e stampare il vettore usando operator overloading.
Permettere di ottenere il numero complesso che ha parte immaginaria pari alla
mediana dei valori delle parti complesse. Permettere di scandire i numeri dall'esterno.*/

#ifndef VECTOR_CN_H
#define VECTOR_CN_H

class VectorCN
{
	private:
		typedef vector<ComplexNumber> ComplexNumberVec;
		ComplexNumberVec vcn;
	public:
		VectorCN();

		~VectorCN();

		VectorCN operator+(const VectorCN& vcn_);

		VectorCN operator*(const float& num_);

		void Insert(const ComplexNumber& cn_);

		void Print();

		friend ostream& operator<<(ostream& out, const VectorCN& v);

		class Iterator
		{
        		private:
                		ComplexNumberVec::const_iterator iter;
                		const VectorCN* ptr_cn;

    		    	public:
                		Iterator(const VectorCN& cn_);

                		ComplexNumber GetNext();                 //It's possible to scan the vector and check if there

                		bool HasNext() const;            //are present other elements

		};


		friend class Iterator;

		ComplexNumber Median();
};

#endif
