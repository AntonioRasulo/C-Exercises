/*Rendere la classe Vector un template per la gestione di oggetti generici*/

using namespace std;
#include <iostream>

template<typename T>
class Vector
{
	public:
		
		Vector(int size);
	//	Vector();
		
		inline const T& Get(int i)const
		{
			return vec[i]; 
		}
	
		inline void Set(int i, const T& el)
		{
			vec[i] = el; 
		}
	  
		~Vector()
		{
	   		if(vec != NULL) 
	   			delete[] vec;
		}
	
	private:
		T* vec;
};

template<typename T>
Vector<T>::Vector(int size) 
{
	if (size <= 0)
	{
		std::cerr << "Wrong parameter"; 
		exit(0);
	}
	
	vec = new T[size];
};

/*template<typename T>
Vector<T>::Vector() 
{	
	vec = new T[size];
};*/


int main()
{
	int size;
	cout << "Inserisci la dimensione del vettore" << endl;
	cin >> size;
	Vector<int> v(size);
}
