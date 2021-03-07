/*Template and Singleton*/
#include "singleton.h"

class Log : public Singleton<Log>{	//si usa ereditarietà da Singleton
	friend class Singleton<Log>;
	
	protected:
		ostream* os;
		
		Log()						//costruttore resta protected, solo Singleton lo chiama
		{
			os = new std::ofstream("logs.txt");
		}
		
	public:							//Aggiungo le funzioni specifiche per fare il Logging
		void Write(const string& message)
		{
			(*os) << message <<endl <<flush;
		}
		
};

int main()
{
	Log::Get()->Write("Messaggio");
}