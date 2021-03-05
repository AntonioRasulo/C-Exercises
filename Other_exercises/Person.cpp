/*Definire una classe Persona che memorizzi nome, cognome, 
indirizzo, data di nascita di una Persona. Realizzare anche gli operator<< e operator>> per tale classe.*/

using namespace std;
#include<string>
#include<iostream>
#include<fstream>
#include "Person.h"

int main()
{
	Person p("Antonio","Rasulo","Maggio","Napoli");
	Person a;
	Person c;
	
	cout<<p;
	
	cin>>a;
	
	cout<<a;
	
	ofstream of("Person.txt");
	if(!of.good())
		cerr <<"Non posso aprire il file\n";
		
	of<<p;
	of.close();
	
	ifstream is("Person.txt");
	if(!is.good())
		cerr <<"Non posso aprire il file\n";
		
	is>>c;
	
	cout<<c;
	
}