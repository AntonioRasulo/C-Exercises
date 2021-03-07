/*Creare una classe per la gestione di un dado virtuale: si deve poter tirare il dato ed ottenere un numero, 
e si deve poter stampare le statistiche dei numeri generati in precedenza, oltre che azzerare tali statistiche 
attraverso un metodo opportuno.*/

#include "Dice.h"

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
	//vector<int>::iterator iter;
	int tmp;
	//bool flag = false;

	//do{
		srand(time(NULL));

		tmp = rand() % 6 + 1;

		/*for(iter = num.begin(); iter!=t.end(); iter++)
		{
			if(*iter==tmp)
			{
				*iter=0;
				flag = true;
				break;
			}
		}*/
		
		num[tmp]++;

	//}while(!flag);

	//flag=false;

	/*do{			//Lo eseguo nuovamente sennò dopo estrae lo stesso numero
                srand(time(NULL));

                int tmp1 = rand() % 6 + 1;

                for(iter = num.begin(); iter!=num.end(); iter++)
                {
                        if(*iter==tmp1)
                        {
                                *iter=0;
                                flag = true;
                                break;
                        }
                }

        }while(!flag);*/

	return tmp;

}