#ifndef PERSON_H
#define PERSON_H

#include "Date.h"

class Person{
	private:
		string name;
		string surname;
		string address;
		string bornPlace;
		Date date;
	public:
		Person(const string name_, const string surname_, const string address_, const string bornPlace_, const int day_, const int month_, const int year_);
	
		Person();
		
		void setName(const string name_);
		
		void setSurname(const string surname_);
		
		void setAddress(const string address_);
		
		void setBornPlace(const string bornPlace_);
		
		void setDate(const int day_, const int month_, const int year_);
				
		string GetName();
		
		string GetSurname();
		
		string GetAddress();
		
		string GetBornPlace();
		
		int GetYear();
		
		int GetDay();
		
		int GetMonth();
		
	friend ostream& operator<<(ostream& out, const Person& p);
	friend istream& operator>>(istream& in, Person& p);
		
	friend ifstream& operator>>(ifstream& in,  Person& p);
	friend ofstream& operator<<(ofstream& out, const Person& m);
};

#endif