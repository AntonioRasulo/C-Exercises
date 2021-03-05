/*Composizione con templates: dati membri possono a loro volta
essere istanziate di classe templetizzata
Esempio: realizzare una libreria che crea contenitore pila 
ed una coda generici (con template)
	--> Entrambe si basano su una lista: creo lista con template
	--> Uso composizione per definire la lista come dato membro in coda e pila
	--> Metodi di classi composte chiamano i metodi di lista
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
class Stack{						//Template con composizione (migliore scelta in questo caso) rispetto a ereditarietà
	private:
		List<T> list;
	public:
		void Push(const T& el)
		{
			list.PushTesta(el);		//Dato membro ha instanziatione rispetto a T
		}							//Chiamo metodi su dato membro
		
		T Pop()
		{
			return list.PopTesta();
		}
};

template<typename T>
class Queue{						//Template con composizione (migliore scelta in questo caso) rispetto a ereditarietà
	private:
		List<T> list;
	public:
		void Enqueue(const T& el)
		{
			list.PushCoda(el);		//Dato membro ha instanziatione rispetto a T
		}							//Chiamo metodi su dato membro
		
		T Dequeue()
		{
			return list.PopTesta();
		}
};

int main()
{
	
}
