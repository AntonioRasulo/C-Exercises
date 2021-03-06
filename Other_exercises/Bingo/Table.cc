/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/

#include "Table.h"
#include <stdlib.h>
#include <time.h>

Table::Table()
{
	this->Init();
}

void Table::Init()
{
	int i = 1;
	t.reserve(99);
	vector<int>::iterator iter = t.begin();
	
	for(; iter!=t.end(); iter++)
	{
		(*iter).push_back(i);
		i++;
	}
}

void Table::restart()
{
	t.clear();
	this->Init();
}

int Table::extract()
{
	vector<int>::iterator iter;
	int tmp;
	bool flag = false;
		
	do{
		
		srand(time(NULL));
	
		tmp = rand() % 99 + 1;
	
		for(iter = t.begin(); iter!=t.end(); iter++)
		{
			if(*iter==tmp)
			{
				*iter=0;
				flag = true;
			}
		}
	
	}while(!flag);
	
	return tmp;
	
}