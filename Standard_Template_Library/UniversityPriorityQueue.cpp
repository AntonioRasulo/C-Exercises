/*Realizzare una classe per la gestione degli studenti in un ateneo
	--> Per ogni studente si memorizza nome e data di uscita;
	--> Deve essere possibile ottenere le date di tutti gli studenti in modo crescente e decrescente
Consigli implementativi:
	-->	Implementare una classe Date, con overloading operator< che confronta due date
	-->	Realizzare una classe Student
	-->	Realizzare una classe University, contenente un vettore di studenti.
		La classe fornisce un metodo per aggiungere uno studente, e fornisce
		due metodi per ottenere le date degli studenti iscritti ordinate
		usando una coda con priorità
			Nota: vedremo metodi alternativi (e migliori in questo caso) per ordinare insiemi di oggetti
	-->	Scrivere un main che faccia il test della classe*/
using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include"Date.h"

class Student{
	private:
		string name;
		Date d;
	public:
		Student()
		{
			name = "";
			d.SetDay(0);
			d.SetMonth(0);
			d.SetYear(0);
		}
		
		Student(const string& name_, const int& year_, const int& month_, const int& day_)
		{
			name = name_;
			d.SetDay(day_);
			d.SetMonth(month_);
			d.SetYear(year_);
		}
		
		Student(const Student& s)
		{
			name = s.name;
			d.SetDay((s.d).GetDay());
			d.SetMonth((s.d).GetMonth());
			d.SetYear((s.d).GetYear());
		}
		
		int GetYear() const
		{
			return d.GetYear();
		}
		
		int GetDay() const
		{
			return d.GetDay();
		}
		
		int GetMonth() const
		{
			return d.GetMonth();
		}
		
		string GetName() const
		{
			return this->name;
		}
		
		void SetName(const string& name_)
		{
			this->name = name_;
		}
		
		void SetDate(const int& day_, const int& month_, const int& year_)
		{
			d.SetDay(day_);
			d.SetMonth(month_);
			d.SetYear(year_);
		}
		
		Date GetDate() const
		{
			return this->d;
		}
		
		//friend struct CmpDateStud;
		friend bool operator<(const Student& a, const Student& b);
		
		void Print() const
		{
			cout<<"Print Name: "<<this->name<<endl;
			cout<<"Print Day: "<<this->GetDay()<<endl;
			cout<<"Print Month: "<<this->GetMonth()<<endl;
			cout<<"Print Year: "<<this->GetYear()<<endl;
		}
		
};

bool operator<(const Student& a, const Student& b)
{
	//cout<<(a.GetDate()).GetYear()<<"<"<<(b.GetDate()).GetYear()<<endl;
	//cout<<"Print all'interno di operator<"<<endl;
	//a.Print();
	return a.GetDate() < b.GetDate();
}

/*struct CmpDateStud{
	bool operator<(const Student& a, const Student& b)
	{
		return a.GetDate() < b.GetDate();
	}
};*/

class University{
	private:
		priority_queue<Student> student_queue;
		vector<Student> student_vector;
	public:
		University(){
		}
		
		void insertStudent(const Student& el)
		{
			student_queue.push(el);
			student_vector.push_back(el);
		}
		
		void decPrint()
		{
			for(int i=0; i<student_vector.size(); ++i)
			{
				cout<<"Student:"<<endl;
				Student p(student_queue.top());
				cout<<"Name: "<<p.GetName()<<endl;
				cout<<"Degree Year:" << p.GetDay() <<" "<< p.GetMonth()<<" "<<p.GetYear()<<endl;
				student_queue.pop();
			}
			for(int j=0; j<student_vector.size(); ++j)
				student_queue.push(student_vector[j]);
		}
		
		void crescPrint()
		{
			//student_vector.clear();
			//student_vector.reserve(student_queue.size());
			for(int i=0; i<student_queue.size(); ++i)
			{
				//student_vector.push_back(student_queue.top());
				student_vector[i] = student_queue.top();
				student_queue.pop();
			}
			for(int j=student_vector.size()-1; j>=0; --j)
			{
				cout<<"Student: "<<endl;
				Student p(student_vector[j]);
				cout<<"Name: "<<p.GetName()<<endl;
				cout<<"Degree Year:" << p.GetDay() <<" "<< p.GetMonth()<<" "<<p.GetYear()<<endl;
			}
			for(int k=0; k<student_vector.size(); ++k)
				student_queue.push(student_vector[k]);
		}
	
/*		void crescPrint()
		{
			vector<Student> s;
			s.reserve(student_queue.size());
			
		}
		for(int i=0; i<s.size(); ++i)
		{
			s.push_back(student_queue.top());
			student_queue.pop();
		}
		for(int j=s.size()-1; j>=0; --j)
		{
			cout<<"Student: "<<endl;
			Student p(student_vector[j]);
			cout<<"Name: "<<p.GetName()<<endl;
			cout<<"Degree Year:" << p.GetDay() <<" "<< p.GetMonth()<<" "<<p.GetYear()<<endl;
		}
		for(int k=0; k<student_vector.size(); ++k)
			student_queue.push(student_vector[k]);
		}*/
};

int main()
{
	Student Antonio("Antonio", 2017, 10, 4);
	Student Marco("Marco", 2018, 16, 2);
	Student Giuseppe("Giuseppe", 2017, 5, 4);
	/*Date data1(11,1,1996);
	Date data2(12,4,1980);
	if(data1<data2)
		cout<<"sbagliato"<<endl;
	else
		cout<<"corretto"<<endl;*/
	
	University u;
	//cout<<"Inserisco Antonio"<<endl;
	u.insertStudent(Antonio);
	u.insertStudent(Marco);
	u.insertStudent(Giuseppe);
	u.crescPrint();
	u.decPrint();
}
