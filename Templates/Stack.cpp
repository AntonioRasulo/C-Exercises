/*	--Implementare la classe pila (Stack) per generici oggetti con tutti i suoi metodi
	--Implementare un main che chiama la classe, la riempie con 10 oggetti e poi li svuota
*/

using namespace std;
#include <iostream>

template<typename T>
class Stack{
	private:
		int size;
		
		T* stack;
		
		void Clear()			//Svuota e dealloca la pila
		{
			//if(stack != NULL)
			//	delete[] stack;
			size = 0;
			
			cout<<"ciao"<<endl;
			stack = NULL;
		}	
		
		/*bool Init(const T& el)	//Inizializza la pila
		{
			this -> Clear();
		}*/
	
	public:
		Stack()
		{
			size = 0;
			stack = NULL;
			//this->Clear();
		}
		
	/*	Stack(const T& el)
		{
			this->Clear();
			
			size++;
			
			stack = new T[size];
			stack[size] = el;
		}*/
		
		Stack(const Stack& s)	//Copia la pila
		{
			this->Clear();
			this->size=s.size;
			for(int i=0; i<size; i++)
				this->stack[i] = s.stack[i];
		}
		
		~Stack()
		{
			this->Clear();
		}
		
		//Getters
		inline int getSize()const{
			return size;
		}
		
		//Operazioni
		void Insert(const T& el)
		{
			Stack tmp(*this);
			this->Clear();
			this->size = tmp.size++;
			for(int i=0; i<tmp.size; i++)
				this->stack[i] = tmp.stack[i];
			this->stack[size] = el;
			
		}
		
		const T& Get()
		{
			return stack[size];
		}
		
		void Print()
		{
			for(int i=0; i<size; i++)
				cout<<"Elemento pila:"<<stack[i]<<endl;
		}
		
};

int main()
{
	Stack<int> s;
	int el;
	cout<<"Inserisci un numero intero da inserire nella pila"<<endl;
	cin >> el;
	s.Insert(el);
	cout<<"Inserisci un numero intero da inserire nella pila"<<endl;
	cin >> el;
	s.Insert(el);
	cout<<"Inserisci un numero intero da inserire nella pila"<<endl;
	cin >> el;
	s.Insert(el);
	cout<<"Inserisci un numero intero da inserire nella pila"<<endl;
	cin >> el;
	s.Insert(el);
	s.Print();
	
}
