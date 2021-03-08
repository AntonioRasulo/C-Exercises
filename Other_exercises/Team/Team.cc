/*Creare una classe Squadra che rappresenti una squadra di calcio
e abbia come attributi il nome della squadra, il numero di partite vinte,
il numero di partite perse e il numero di partite pareggiate.
La classe deve disporre di opportuni metodi per impostare o visualizzare gli attributi,
un metodo che restituisce quanti punti ha in campionato
(ogni partita vinta vale 3 punti, ogni partita pareggiata 1, quelle perse 0)
e un metodo per azzerare il numero di partite vinte, pareggiate e perse.*/

using namespace std;

#include <string>
#include "Team.h"

Team::Team(string name_)
{
	name=name_;
	win=0;
	loose=0;
	draw=0;
}

int Team::getWin()
{
	return win;
}

int Team::getLoose()
{
	return loose;
}

int Team::getDraw()
{
	return draw;
}

int Team::Points()
{
	int tmp = 3*win+1*draw;
	return tmp;
}

void Team::setWin()
{
	win++;
}

void Team::setLoose()
{
	loose++;
}

void Team::setDraw()
{
	draw++;
}

void Team::Reset()
{
	win=0;
	draw=0;
	loose=0;
}
