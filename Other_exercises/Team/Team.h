/*Creare una classe Squadra che rappresenti una squadra di calcio
e abbia come attributi il nome della squadra, il numero di partite vinte,
il numero di partite perse e il numero di partite pareggiate.
La classe deve disporre di opportuni metodi per impostare o visualizzare gli attributi,
un metodo che restituisce quanti punti ha in campionato
(ogni partita vinta vale 3 punti, ogni partita pareggiata 1, quelle perse 0)
e un metodo per azzerare il numero di partite vinte, pareggiate e perse.*/

#ifndef TEAM_H
#define TEAM_H

class Team{
	private:
		string name;
		int win;
		int loose;
		int draw;
	public:

	Team(string name_);

	int getWin();
	int getLoose();
	int getDraw();
	void setWin();
	void setLoose();
	void setDraw();
	int Points();
	void Reset();
};

#endif
