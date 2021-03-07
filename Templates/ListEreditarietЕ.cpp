/*Esempio realizzare una libreria che crea contenitore pila ed una coda generici (con template)
	-->Entrambe si basano su una lista: creo lista con template
	-->Uso ereditarietà per definire una coda ed una pila
*/

using namespace std;
#include <iostream>

template<typename T>
class List{
	private:
		class Elem{
			public:
				T el;
				Elem* prec;
				Elem* succ;
				Elem() : prec(NULL), succ(NULL){}
		};
		Elem* testa;
		Elem* coda;
	protected:	
		List() : testa(NULL), coda(NULL){}
		void PushCoda(const T& el){
			Elem* elem = new Elem;
			elem->el = el;
			elem->succ = coda;
			if(coda != NULL)
				coda->prec = elem;
			coda = elem;
		}
		void PushTesta(const T& el)
		{
			Elem* elem = new Elem;
			elem->el = el;
			elem->prec = testa;
			if(testa != NULL)
				testa->succ = elem;
			testa = elem;
		}
		
		T PopCoda()
		{
			if(coda == NULL)
			{
				std::cerr<<"Pop from empty";
				return T();
			}
			const T el = coda->el;
			
			Elem* succ= coda->succ;
			
			delete coda;
			
			coda = succ;
			
			if(coda!=NULL)
				coda->prec=NULL;
			return el;
		}
		
		T PopTesta()
		{
			if(testa == NULL)
			{
				std::cerr<<"Pop from empty";
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
};


template<typename T>
class Stack: public List<T>{		//Template con ereditarietà. Si richiama solo i metodi lista,
	public:							// nessuna implementazione aggiuntiva
		Stack(){}
		void Push(const T& el){
			this->PushTesta(el);
		}
		T Pop(){
			this->PopTesta();
		}
		
};

template<typename T>
class Queue: public List<T>{		//Template con ereditarietà. Si richiama solo i metodi lista,
	public:							// nessuna implementazione aggiuntiva
		Queue(){}
		void Enqueue(const T& el){
			this->PushCoda(el);
		}
		T Dequeue(){
			this->PopTesta();
		}
		
};

int main()
{
	
}
