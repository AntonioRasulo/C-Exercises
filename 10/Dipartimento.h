using namespace std;
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include "../09/People.h"

class Dipartimento{
	private:
		vector<People*> v;
	public:
		
		Dipartimento(){
			this->Clear();
		}
		
		Dipartimento(People* p){
			//People* pointer = new People;
			//pointer = p;
			v.push_back(p);
		}
		
		~Dipartimento(){
			this->Clear();
		}
		
		void Insert(People* p)
		{
			v.push_back(p);
		}
		
		void Clear()
		{
			vector<People*>::iterator iter=this->v.begin();
			for(; iter!=v.end(); iter++)
				if(*iter != NULL)
					delete *iter;
			v.clear();
		}
		
		void Print()
		{
			vector<People*>::iterator iter=this->v.begin();
			for(; iter!=v.end(); iter++)
				if(*iter != NULL)
					(*iter)->Print();
		}
	
		void PrintScreen()
		{
			vector<People*>::iterator iter=this->v.begin();
			for(; iter!=v.end(); iter++)
				if(*iter != NULL)
					(*iter)->PrintScreen();
		}
		
};