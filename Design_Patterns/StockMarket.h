/*Observer Design Pattern example: stock market*/

using namespace std;
#include<iostream>
#include<string>
#include<list>

class Stock;	//The observated, for the moment we need only to declare it 

class InvestorBase{	//Prototype of the observer

	public:
		virtual void Update(Stock* stock) = 0;

};

class Stock{
	public:
		Stock(const string& symbol, double price):symbol_(symbol),price_(price){}
		void Attach(InvestorBase* investor){investors_.push_back(investor);}	//+osservatore
		void Detach(InvestorBase* investor){investors_.remove(investor);}	//-osservatore
		void Notify()	//Notifica gli osservatori passandogli l'oggetto osservato
		{	
			list<InvestorBase*>::iterator it = investors_.begin();
			while(it != investors_.end()) {(*it)->Update(this); ++it;}
		}
		double GetPrice()const{ return price_;}
		void SetPrice(double price){price_=price; Notify();}	//Cambio stato, chiamo Notify()
		const string& GetSymbol() const { return symbol_; }
		
	private:
		string symbol_;
		double price_;
		list<InvestorBase*> investors_;	//lista di osservanti

};

//L'osservatore
class Investor:public InvestorBase
{
	public:
		Investor(const string& name) : name_(name){}
		void Update(Stock* stock){		//riceve la notifica
		cout << "Notifica a " << name_ << " => " << stock->GetSymbol() << "" << stock->GetPrice() << endl;
		}
	private:
		string name_;
};

