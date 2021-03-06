/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/

using namespace std;
#include "Table.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Table::Table()
{
	this->Init();
}

void Table::Init()
{
	//int i=1;
	//vector<int>::iterator iter = t.begin();	
	/*t.reserve(99);
	for(; iter!=t.end(); iter++)
	{
		*iter = i;
		i++;
	}*/
	for(int i=1; i<100; i++)
	{
		t.push_back(i);
	}

}

void Table::restart()
{
	t.clear();
	this->Init();
}

void Table::Print()
{
	vector<int>::iterator iter = t.begin();
	for(; iter!=t.end(); iter++)
        {
                cout<<*iter<<endl;
        }
}

int Table::extract()
{
	vector<int>::iterator iter;
	int tmp = 0;
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
