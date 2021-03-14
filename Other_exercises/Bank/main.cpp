/*Implementare una classe per la gestione della banconote di una banca.
Deve essere possibile aggiungere una banconota, sapere il numero di pezzi
per ogni tipo, conoscere il valore totale delle banconote.*/

using namespace std;

#include <map>
#include "BankNote.h"
#include "Bank.h"

int main()
{
	BankNote bn1(5);
	BankNote bn2(10);
	BankNote bn3(20);
	BankNote bn4(50);
	BankNote bn5(100);
	BankNote bn6(200);
	BankNote bn7(500);

	Bank b;

	b.Insert(bn1, 100);
	b.Insert(bn2,50);
	b.Insert(bn3, 50);
	b.Insert(bn4,50);
	b.Insert(bn1,100);
	b.Insert(bn5, 10);
	b.Insert(bn6, 4);
	b.Insert(bn7);

	b.Print();
}
