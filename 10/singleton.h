/*Template and Singleton*/
/*Usando templates si evita di ridefinire la struttura del Singleton ad ogni uso.
Tale template va in singleton.h*/
using namespace std;
#include<fstream>

template<typename T>
class Singleton{
	protected:
		Singleton(){}
		Singleton(const Singleton<T>& S){}								//protected, non copiabile
		Singleton<T>& operator=(const Singleton<T>& S){return *this;}	//protected
		static T* istanza;
	public:
		static T* Get()
		{
			if(istanza == NULL)
				istanza = new T();
			return istanza;
		}
};

template<typename T> T* Singleton<T>::istanza = NULL;