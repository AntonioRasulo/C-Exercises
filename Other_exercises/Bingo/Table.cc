/*Creare una classe per la gestione del tabellone di una tombola.
Si deve poter costruire il tabellone, cancellare tutti i numeri estratti od estrarre un nuovo numero.*/

using namespace std;
#include "Table.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

/*#define CYCLES_PER_MS 574

void Wait_ms(unsigned int time_ms)
{
	int i,j;
	for(j=0; j<time_ms; j++)
	{
		for(i=0; i<CYCLES_PER_MS;i++);
	}
}*/

Table::Table()
{
	this->Init();
}

void Table::Init()
{
	t.clear();

	for(int i=1; i<100; i++)
	{
		t.push_back(i);
	}
	
}

void Table::restart()
{
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
				break;
			}
		}

	}while(!flag);

	flag=false;

	do{				//Lo eseguo nuovamente sennò dopo estrae lo stesso numero
                srand(time(NULL));

                int tmp1 = rand() % 99 + 1;

                for(iter = t.begin(); iter!=t.end(); iter++)
                {
                        if(*iter==tmp1)
			{
                                flag = true;
                                break;
                        }
                }

        }while(!flag);

	return tmp;

}
