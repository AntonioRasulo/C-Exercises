/*Definire una classe per la gestione di un gruppo di N Persone (modellate con la classe descritta al punto 1). 
Deve essere possibile accedere o modificare i dati delle singole persone e ritornare chi sia la persona piu' giovane e vecchia del gruppo.*/

#include "Person.h"

Person::Person(const string name_, const string surname_, const string address_, const string bornPlace_, const int day_, const int month_, const int year_)
{
	name = name_;
	surname = surname_;
	address = address_;
	bornPlace = bornPlace_;
	date.SetDay(day_);
	date.SetMonth(month_);
	date.SetYear(year_);
}

Person::Person()
{
	name = " ";
	surname = " ";
	address = " ";
	bornPlace = " ";
	date.SetDay(0);
	date.SetMonth(0);
	date.SetYear(0);
}

void Person::setName(const string name_)
{
	name=name_;
}

void Person::setSurname(const string surname_)
{
	surname=surname_;
}

void Person::setAddress(const string address_)
{
	address=address_;
}

void Person::setBornPlace(const string bornPlace_)
{
	bornPlace=bornPlace_;
}

void Person::setDate(const int day_, const int month_, const int year_)
{
	date.SetDay(day_);
	date.SetMonth(month_);
	date.SetYear(year_);
}

string Person::GetName()
{
	return name;
}

string Person::GetSurname()
{
	return surname;
}

string Person::GetAddress()
{
	return address;
}

string Person::GetBornPlace()
{
	return bornPlace;
}

int Person::GetYear()
{
	return date.GetYear();
}

int Person::GetDay()
{
	return date.GetDay();
}

int Person::GetMonth()
{
	return date.GetMonth();
}

ostream& operator<<(ostream& out, const Person& p)
{
	
	out<<"Nome: "<<p.name<<endl;
	out<<"Surname: "<<p.surname<<endl;
	out<<"Address: "<<p.address<<endl;
	out<<"BornPlace: "<<p.bornPlace<<endl;
		
	return out;
}

istream& operator>>(istream& in, Person& p){
	string tmp;
	
	cout<<"Name: ";	in >> tmp;
	p.setName(tmp);
	
	cout<<"Surname: ";	in >> tmp;
	p.setSurname(tmp);
	
	cout<<"Address: ";	in >> tmp;
	p.setAddress(tmp);
	
	cout<<"BornPlace: ";	in >> tmp;
	p.setBornPlace(tmp);
	
	return in;
}

ofstream& operator<<(ofstream& out, const Person& p){
	out<<p.name<<" ";
	out<<p.surname<<" ";
	out<<p.address<<" ";
	out<<p.bornPlace<<endl;	
	return out;
}

ifstream& operator>>(ifstream& in, Person& p){
	
	string tmp;

	in >> tmp;
	p.setName(tmp);
	
	in >> tmp;
	p.setSurname(tmp);
	
	in>>tmp;
	p.setAddress(tmp);
	
	in>>tmp;
	p.setBornPlace(tmp);
	
	return in;
}

struct CmpDate{
	bool operator()(Person& a, Person& b) const{
		if(a.GetYear() != b.GetYear())
			return a.GetYear() > b.GetYear();
		else if(a.GetMonth() != b.GetMonth())
			return a.GetMonth() > b.GetMonth();
		else
			return a.GetDay() > b.GetDay();
	}
};
