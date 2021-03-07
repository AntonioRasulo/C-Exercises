/*Creare una classe per la gestione di un dado virtuale: si deve poter tirare il dato ed ottenere un numero, 
e si deve poter stampare le statistiche dei numeri generati in precedenza, oltre che azzerare tali statistiche 
attraverso un metodo opportuno.*/

#ifndef DICE_H
#define DICE_H

class Dice{
	private:
		vector<int> num;
	public:
		Dice();
		
		void Restart();
		
		void Init();
		
		void Dice();
		
		int Launch();

}

#endif