/*Definire ed implementare una classe che defisce un generico polinomio di grado 2
y = Ax2 + Bx + C
		La classe deve permettere di inizializzare A,B,C.
		La classe deve permettere di calcolare y dato x.
		La classe deve permettere di calcolare le radici del polinomio (-B +/- v(B2 – 4AC)/2A)*/
		
using namespace std;
#include <iostream>
#include <math.h>

class Polinomio
{
	private:
		float a,b,c;
		float radix1,radix2;
	public:
		Polinomio()
		{
			a = 0;
			b = 0;
			c = 0;
			radix1 = (-b + sqrt(pow(b,2) - 4 * a* c)) /(2*a);
			radix2 = (-b - sqrt(pow(b,2) - 4 * a* c)) /(2*a);
		};
		
		Polinomio (float a_, float b_, float c_)
		{
			a = a_;
			b = b_;
			c = c_;
			radix1 = (-b + sqrt(pow(b,2) - 4 * a* c)) /(2*a);
			radix2 = (-b - sqrt(pow(b,2) - 4 * a* c)) /(2*a);
			
		};
		
		void setA(float a_)
		{
			a = a_;
			radix1 = (-b + sqrt(pow(b,2) - 4 * a* c)) /(2*a);
			radix2 = (-b - sqrt(pow(b,2) - 4 * a* c)) /(2*a);
		}
		
		void setB(float b_)
		{
			b = b_;
			radix1 = (-b + sqrt(pow(b,2) - 4 * a* c)) /(2*a);
			radix2 = (-b - sqrt(pow(b,2) - 4 * a* c)) /(2*a);
		}
		
		void setC(float c_)
		{
			c = c_;
			radix1 = (-b + sqrt(pow(b,2) - 4 * a* c)) /(2*a);
			radix2 = (-b - sqrt(pow(b,2) - 4 * a* c)) /(2*a);
		}
		
		float getY(float x)
		{
			return (a*pow(x,2) + b*x +c);
		}
		
		float getRadix1()
		{
			return radix1;
		}
		
		float getRadix2()
		{
			return radix2;
		}
		
		void Stampa()
		{
			cout << "y=" << a << "x^2+" << b << "x" << c << endl;  
			cout << "Radici: x1 = " << radix1 << "x2 =" << radix2 <<endl;
		}
		
};

int main()
{
	Polinomio pol;
	float in;
	float y;
	cout << "Inserisci A,B,C del polinomio" << endl;

	cout << "A: " <<endl;
	cin >> in;
	pol.setA(in);

	cout << "B: " <<endl;
	cin >> in ;
	pol.setB(in);

	cout << "C: " <<endl;
	cin >> in;
	pol.setC(in);
	
	pol.Stampa();
	
	cout <<"Inserisci valore x" << endl;
	cin >> in;
	y = pol.getY(in);
	cout << "x = " << y << endl;
	
	
}
