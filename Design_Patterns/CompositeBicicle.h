/*Una bicicletta si compone di componenti più semplici:
	-Che a loro volta sono composti da altri componenti più
	 semplici, ad esempio: ruote composte da ruota anteriore
	 e posteriore, cambio composto da cambio anteriore e 
	 posteriore, telaio, ecc..

Ogni componente ha un prezzo e la classe bicicletta ha un
costo pari alla somma dei singoli componenti.

Realizzare una bicicletta attraverso il design pattern Composite:
	-Deve essere possibile sapere il prezzo della bici composta*/
	
#include<vector>

class ComponentBase{	//classe padre comune a foglia e composite
	public:
		virtual int Price() const = 0;
};

class Component : public ComponentBase{	//classe foglia
	public:
		Component(const int price_):price(price_){}
		virtual int Price() const{
			return price;
		}
	
	private:
		//Prezzo del componente
		int price;
	
};

class BicicleComposite : public ComponentBase{	//composite
	private:
		std::vector<ComponentBase*>	sottoclassificatori;	//lista di foglie
	
	public:
		void AddComponent(ComponentBase* c){
			sottoclassificatori.push_back(c);
		}
		
		virtual int Price() const{			//lista di foglie chiamate in sequenza per realizzare il comportamento composto:
			int cnt = 0;
			for(int i = 0; i < sottoclassificatori.size(); ++i)		//OR tra le classificazioni. La logica è specifica del problema da risolvere.
				 cnt += (sottoclassificatori[i]->Price());
			return cnt;		
		}
		
		~BicicleComposite(){				
				for(int i = 0; i < sottoclassificatori.size(); ++i)		//Se ownership delle sottoparti è interna, il composite dealloca le sue sottoparti.
					delete sottoclassificatori[i];						//Se Composite non ha ownership, il distruttore va tolto.
		}

		

};