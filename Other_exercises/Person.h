/*Definire una classe Persona che memorizzi nome, cognome, 
indirizzo, data di nascita di una Persona. Realizzare anche gli operator<< e operator>> per tale classe.*/
#ifndef PERSON_H
#define PERSON_H
class Person{
	private:
		string name;
		string surname;
		string address;
		string bornPlace;
	public:
		Person(const string name_, const string surname_, const string address_, const string bornPlace_)
		{
			name = name_;
			surname = surname_;
			address = address_;
			bornPlace = bornPlace_;
		}
	
		Person()
		{
			
		}
		
		void setName(const string name_)
		{
			name=name_;
		}
		
		void setSurname(const string surname_)
		{
			surname=surname_;
		}
		
		void setAddress(const string address_)
		{
			address=address_;
		}
		
		void setBornPlace(const string bornPlace_)
		{
			bornPlace=bornPlace_;
		}
		
	friend ostream& operator<<(ostream& out, const Person& p);
	friend istream& operator>>(istream& in, Person& p);
		
	friend ifstream& operator>>(ifstream& in,  Person& p);
	friend ofstream& operator<<(ofstream& out, const Person& m);
};


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
	//string str;
	/*float val;
	//in >> str;
	//cout << str <<endl;
	for (int i=0; i<m.N; ++i)
		for(int j=0; j<m.M; ++j)
		{
			//in >> val;
			//cout << str[m.N*i+j]<<endl;
			//val =(double)str[m.N*i+j];
			//cout << val<<endl;
			//m.Set(i,j,str[m.N*i+j]/25);
			in >> val;
			m.data[i][j] = val;
		}*/
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

#endif
