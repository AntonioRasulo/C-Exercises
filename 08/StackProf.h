using namespace std;
#include<cstddef>
#include<iostream>

template<typename T>
class Stack
{
	private:
	class Elem{
		public:
			T el;
			Elem* prec;
			Elem* succ;
			Elem() : prec(NULL), succ(NULL){}		
	};
	Elem* testa;
	public:
		Stack();
		void Push(const T& el);	//Aggiunge elemento
		T Pop();				//Ritorna ultimo elemento
		bool Empty() const;
		~Stack();
};


template<typename T>
Stack<T>::Stack(){testa = NULL;}

template<typename T>
void Stack<T>::Push(const T& el)
{
	Elem* elem = new Elem;
	elem->el = el;
	elem->prec = testa;
	if(testa != NULL)
		testa->succ = elem;
	testa = elem;
}

template<typename T>
T Stack<T>::Pop()
{
	if(testa == NULL)
	{
		std::cerr<<"Pop from empty stack";
		return T();
	}
	const T el = testa->el;
	
	Elem* prec=testa->prec;
	
	delete testa;
	
	testa = prec;
	
	if(testa!=NULL) 
		testa->succ=NULL;
	return el;
	
}

template<typename T>
bool Stack<T>::Empty() const{
	return testa == NULL;
}

template<typename T>
Stack<T>::~Stack(){
	while(!this->Empty()){
		this->Pop();
	}
}
