/*Un dottore utilizza un meccanismo particolare per decidere il prossimo paziente da visitare:
	--> Per ogni paziente si memorizza nome e data di nascita;
	--> Ogni paziente che entra in ambulatorio viene aggiunto;
	--> Viene visitato il paziente più anziano in attesa
Consigli implementativi:
	--> Opzionale: implementare una classe Date
	--> Realizzare una classe Paziente da fornire come comparatore
	--> Realizzare una classe Ambulatorio (con priority queue usata per composizione)
	--> Scrivere un main che faccia il test della classe*/
	
using namespace std;
#include"Date.h"
#include<string>
#include<queue>
#include<iostream>

class Patient{
	private:
		string name;
		Date d;
	public:
		Patient()
		{
			name = "";
			d.SetDay(0);
			d.SetMonth(0);
			d.SetYear(0);
			//d.Date();
		}
		Patient(const string& name_, const int& year_, const int& month_, const int& day_)
		{
			name = name_;
			d.SetDay(day_);
			d.SetMonth(month_);
			d.SetYear(year_);
		}
		
		Patient(const Patient& p)
		{
			name = p.name;
			//Date n_d(p.d);
			d.SetDay((p.d).GetDay());
			d.SetMonth((p.d).GetMonth());
			d.SetYear((p.d).GetYear());
		//	d.Date(n_d);
		}
		
		int GetYear()
		{
			return d.GetYear();
		}
		
		int GetDay()
		{
			return d.GetDay();
		}
		
		int GetMonth()
		{
			return d.GetMonth();
		}
		
		string GetName()
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
		
};

struct CmpDate{
	bool operator()(Patient& a, Patient& b) const{
		if(a.GetYear() != b.GetYear())
			return a.GetYear() > b.GetYear();
		else if(a.GetMonth() != b.GetMonth())
			return a.GetMonth() > b.GetMonth();
		else
			return a.GetDay() > b.GetDay();
	}
};

class Clinic{
	private:
		priority_queue<Patient, std::vector<Patient>, CmpDate> p_q;	
	public:
	
		Clinic()
		{
			
		}
	
		Clinic(const Patient& p)
		{
			p_q.push(p);
		}
		
		void insertPatient(const Patient& p)
		{
			p_q.push(p);
		}
		
		void visitPatient()
		{
			cout<<"It's the turn of the older patient:"<<endl;
			Patient p(p_q.top());
			cout<<"Name: "<<p.GetName()<<endl;
			cout<<"Birth Date:" << p.GetDay() <<" "<< p.GetMonth()<<" "<<p.GetYear()<<endl;
			p_q.pop(); 
			
		}
		
		
};

int main()
{
	Patient young("Paolo", 1996, 11, 1);
	Patient old_man("Franco", 1930, 12, 5);
	Patient young_girl("Sara", 2000, 17, 3);
	Patient adult("Gianni", 1965, 2, 5);
	Patient adult_girl("Maria", 1965, 3, 4);
	Clinic c;
	c.insertPatient(young);
	c.insertPatient(old_man);
	c.insertPatient(adult_girl);
	c.visitPatient();
	c.insertPatient(adult);
	c.visitPatient();
	c.insertPatient(young_girl);
	c.visitPatient();
	c.visitPatient();
	c.visitPatient();
}
