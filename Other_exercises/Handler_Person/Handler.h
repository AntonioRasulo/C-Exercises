
#ifndef HANDLER_PERSON_H
#define HANDLER_PERSON_H

#include "Person.h"



class Handler{
	private:
		priority_queue<Person, std::vector<Person>, CmpDate> p_q;	
	public:
	
		Handler();
	
		Handler(const Person& p);
		
		void insertPerson(const Person& p);
		
		void seeOlderPerson();
		
		
};

endif