/*Definire una classe per la gestione di un gruppo di N Persone (modellate con la classe descritta al punto 1). 
Deve essere possibile accedere o modificare i dati delle singole persone e ritornare chi sia la persona piu' giovane e vecchia del gruppo.*/

#include "Handler.h"
#include "CmpDate.h"

Handler::Handler()
{

}

Handler::Handler(const Person& p)
{
	p_q.push(p);
}

void Handler::insertPerson(const Person& p)
{
	p_q.push(p);
}

void Handler::seeOlderPerson()
{
	cout<<"Person:"<<endl;
	Person p(p_q.top());
	cout<<"Name: "<<p.GetName()<<endl;
	cout<<"Birth Date:" << p.GetDay() <<" "<< p.GetMonth()<<" "<<p.GetYear()<<endl;
	p_q.pop(); 
			
}
