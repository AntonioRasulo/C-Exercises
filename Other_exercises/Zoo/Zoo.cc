using namespace std;

#include <string>
#include <vector>
#include "Zoo.h"

Zoo::Zoo()
{
	this->Clear();
}

Zoo::Zoo(Animal* a)
{
	v.push_back(a);
}

Zoo::~Zoo()
{
	this->Clear();
}

void Zoo::Insert(Animal* a)
{
	v.push_back(a);
}

void Zoo::Clear()
{
	vector<Animal*>::iterator iter=this->v.begin();
	for(; iter!=v.end(); iter++)
		if(*iter != NULL)
			delete *iter;
	v.clear();
}
