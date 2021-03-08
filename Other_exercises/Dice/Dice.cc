/*Creare una classe per la gestione di un dado virtuale: si deve poter tirare il dato ed ottenere un numero, 
e si deve poter stampare le statistiche dei numeri generati in precedenza, oltre che azzerare tali statistiche 
attraverso un metodo opportuno.*/
using namespace std;

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include "Dice.h"

#define CYCLES_PER_MS 574
void Wait_ms(unsigned int time_ms)
{
	int i,j;
	for(j=0; j<time_ms; j++)
	{
		for(i=0; i<CYCLES_PER_MS;i++);
	}
}


Dice::Dice()
{
	this->Init();
}

void Dice::Restart()
{
	this->Init();
}

void Dice::Init()
{
	num.clear();
	
	for(int i=0; i<6; i++)
	{
		num.push_back(0);
	}
}

void Dice::Print()
{
	vector<int>::iterator iter = num.begin();
	for(; iter!=num.end(); iter++)
        {
                cout<<*iter<<endl;
        }
}

int Dice::Launch()
{
	int tmp;

	srand(time(NULL));

	tmp = rand() % 6 + 1;

	num[tmp-1]++;

	Wait_ms(1000000);

	return tmp;

}
