/*Creare una classe per la gestione dei treni.
Un treno è associato ad un codice, una stazione di partenza ed arrivo,
e la sua posizione attuale (latitudine, longitudine). Creare una 
classe per la gestione dei treni che permetta di:
	--> aggiungere un treno;
	--> stampare la posizione dei treni per codice crescente;
	--> fornire la classe di un iteratore per iterare sui treni.*/

using namespace std;
#include<string>
#include<iostream>
#include<map>

class Train
{
	private:
		string stationdeparture;
		string stationarrive;
		float positionx;
		float positiony;
		int code;
	public:
		Train()
		{
		
		}
		
		Train(const string stationdeparture_, const string stationarrive_, const float positionx_, const float positiony_, const int code_)
		{
			stationdeparture = stationdeparture_;
			stationarrive = stationarrive_;
			positionx = positionx_;
			positiony = positiony_;
			code = code_;
		}
		
		void Print()
		{
			cout <<"Code: " <<code<<endl;
			cout <<"Station departure: " <<stationdeparture<<endl;
			cout <<"Station arrive: " <<stationarrive<<endl;
			cout <<"Positionx: " <<positionx<<endl;
			cout <<"Positiony: " <<positiony<<endl;
		}
		
		int getCode()
		{
			return code;
		}
		
};

class TrainHandler
{
	private:
		//int code;
				
		typedef std::map<int,Train> DataContainer;
		DataContainer data;
		
	public:
		
		void Set(Train value) {data[value.getCode()] = value;}
		
		struct Element
		{
			int i;
			Train value;
		};
		
		class Iterator
		{
			private:
				
				typename DataContainer::const_iterator iter;
				const TrainHandler* handler;
				
			public:
			
				Iterator(const TrainHandler& handler_)			//A SparseVector is initialized
				{
					handler = &handler_;
					iter = handler->data.begin();
				}
				
				inline Element GetNext()							//It's possible to scan the vector and check if there
				{												
					Element e;
					e.i = iter->first;
					e.value = iter->second;
					++iter;
					return e;
				}
				
				inline bool HasNext() const
				{
					return ( iter != handler->data.end());		//are present other elements
				}
		};
		
		friend class Iterator;									//Friend of the class, to access to private data

		
		

};