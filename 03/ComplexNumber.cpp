/*Realizzare del software che permetta di effettuare calcoli basati su addizioni e moltiplicazioni di numeri complessi.
	-Classe numero complesso
		Stabilire dati membri e metodi da realizzare
		Implementare i costruttori che ritenete necessari
		Implementare i metodi
		Stabilire la loro visibilità
	-Nota (a+ib)*(c+id) = (ac-bd) + i(bc+ad) */

using namespace std;
#include <iostream>
#include <math.h>

class Complex{
	private:
		float real, imm;

		
	public:
	
		Complex()
		{
			real = 0.0;
			imm = 0.0;	
		};		
		
		Complex(float real_, float imm_)
		{
			real = real_;
			imm = imm_;
		};
		
		
		void setReal(float real_)
		{
			real = real_;
		}
		
		void setImm(float imm_)
		{
			imm = imm_;
		}
		
		float getReal()
		{
			return real;
		}
		
		float getImm()
		{
			return imm;
		}
		
		Complex sum(Complex c)
		{
			Complex csum;
			csum.real = real + c.real;
			csum.imm = imm + c.imm;
			
			return csum;
		} 
	
		Complex prod(Complex c)
		{
			Complex cprod;
			cprod.real = real*c.real - imm*c.imm;
			cprod.imm = real*c.imm + imm*c.real;
			
			return cprod;
		}
};

int main()
{
	Complex c1;
	Complex c2;
	Complex csum;
	Complex cprod;
	float in;
	
	cout << "Inserisci parte reale primo numero complesso" << endl;
	cin >> in;
	c1.setReal(in);
	cout << "Inserisci parte immaginaria primo numero complesso" << endl;
	cin >> in;
	c1.setImm(in);
	
	cout << "Inserisci parte reale secondo numero complesso" << endl;
	cin >> in;
	c2.setReal(in);
	cout << "Inserisci parte immaginaria secondo numero complesso" << endl;
	cin >> in;
	c2.setImm(in);
	
	csum = c1.sum(c2);
	cprod = c1.prod(c2);
	
	cout << "c1: " << c1.getReal()<< "+ i" << c1.getImm() <<endl;
	cout << "c2: " << c2.getReal()<< "+ i" << c2.getImm() <<endl;
	
	cout << "csum: " << csum.getReal()<< "+ i" << csum.getImm() <<endl;
	cout << "cprod: " << cprod.getReal()<< "+ i" << cprod.getImm() <<endl;
}
