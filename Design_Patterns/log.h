/*Singleton example*/

using namespace std;
#include<string>
#include<iostream>
#include<fstream>
#include<string>

class Log{												//Classe che permette di fare registrazione eventi (logging) del sistema in modo consistente.
	private:											//Tutti i logs sono raccolti nello stesso file. 
		ostream* os;									//Non voglio che sia possibile sbagliare e creare più file di log
			
		Log()
		{
			os = new ofstream("logs.txt");
		}
		
		static Log* istanza;
		
		Log(const Log& S){}
		
		Log& operator=(const Log& S){return *this;}
	
	public:
	
		static Log* Get()
		{
			if(istanza == NULL) istanza = new Log();
			return istanza;
		}
		void Write(const string& message){
			(*os)<< message <<endl<<flush;
		}
};

	Log* Log::istanza = NULL;

