/*Classe Vector con copy constructor*/
			
using namespace std;
#include <iostream>

class Vector{
	private:
		typedef int Element;
		Element* data;
		int N; //Dimensione del vettore
	public:
		
		explicit Vector(int N_){
			N = N_;
			data = new Element[N];	
		};
		
		explicit Vector(const Vector& vec){	//Copy constructor va definito altrimenti di vec viene copiato il puntatore,
				N = vec.N;					// ed i due vettori punterebbero allo stesso data
				data = new Element[N];
				for(int i = 0; i<N; i++)
					data[i] = vec.data[i];
		};
		
		~Vector() { delete[] data; }	// Distruttore va definito per deallocare quello che era stato allocato dinamicamente
		
		Element Get(int i) const{
			return data[i];
		}
		
		void Set(int i, const Element& el){
			data[i] = el;
		}
		
		
};


int main()
{
	
}