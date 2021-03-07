/*Composite example*/

#include "Composite.h"

int main()
{
	//Creo classificatore composto per calcio
	ClassifierComposite* calcio = new ClassifierComposite;
	// calcio_a_5 owned da calcio
	calcio->AddClassifier(new Classifier(words_calcio_a_5));
	// calcio_a_7 owned da calcio
	calcio->AddClassifier(new Classifier(words_calcio_a_7));
	// calcio_a_11 owned da calcio
	calcio->AddClassifier(new Classifier(words_calcio_a_11)); 
	
	// Creo classificatore composto per sport
	ClassifierComposite sport;
	
	sport.AddClassifier(calcio); // calcio owned da sport
	sport.AddClassifier(new Classifier(words_tennis)); // tennis owned da sport
	
	// Classificatore composto usato da interfaccia di base class: e' un classificatore
	cout << sport.Classify(“Il giocatore effettua una rovesciata”) << endl;
}// qui chiamato distruttore di sport che dealloca le sottoparti