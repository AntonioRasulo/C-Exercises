/*Creare una classe Squadra che rappresenti una squadra di calcio
e abbia come attributi il nome della squadra, il numero di partite vinte,
il numero di partite perse e il numero di partite pareggiate.
La classe deve disporre di opportuni metodi per impostare o visualizzare gli attributi,
un metodo che restituisce quanti punti ha in campionato
(ogni partita vinta vale 3 punti, ogni partita pareggiata 1, quelle perse 0)
e un metodo per azzerare il numero di partite vinte, pareggiate e perse.*/

using namespace std;

#include <iostream>
#include "Team.h"

int main()
{
	Team j("Juventus");

	for(int i =0; i<3; i++)
		j.setWin();
	for(int u =0; u<2; u++)
		j.setDraw();
	for(int k=0; k<4; k++)
		j.setLoose();
	cout<<"Win: "<<j.getWin()<<endl;
	cout<<"Draw: "<<j.getDraw()<<endl;
	cout<<"Loose: "<<j.getLoose()<<endl;
	cout<<"Points: "<<j.Points()<<endl;
	
	j.Reset();

	cout<<"Restart"<<endl;

	cout<<"Win: "<<j.getWin()<<endl;
        cout<<"Draw: "<<j.getDraw()<<endl;
        cout<<"Loose: "<<j.getLoose()<<endl;
        cout<<"Points: "<<j.Points()<<endl;

}
