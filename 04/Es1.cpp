/*Scrivere e testare il codice per analizzare un file di testo in input 
e determinare se la parola “computer” è contenuta nel testo*/
using namespace std;
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	ifstream is("Es1.txt");
	bool test = false;
	string str;
	if(!is.good()){	//Controllo tutto OK (file trovato ed apribile)
		cerr <<"Non posso aprire il file\n";
		return 0;
	}
	while(is >> str){
		if (str == "computer")
			test = true;
	}
	
	if(test == true)
		cout << "Nel testo c'e' la parola computer" << endl;
	else
		cout << "Nel testo non c'e' la parola computer" << endl;
	
}
