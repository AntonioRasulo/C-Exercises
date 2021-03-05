/*Esercizio Composite
Realizzare un software per il plotting grafico vettoriale che usi
il design pattern composite
	--> Ogni oggetto implementa il metodo Print()
	--> Implementare gli oggetti Segmento e Cerchio
	--> Implementare un oggetto Rettangolo come un insieme di segmenti
	--> Oggetto composto Plot contiene vari oggetti Segmento o Cerchio
		e li stampa nel Print()
	--> Possibile creare librerie di oggetti via via più complessi. Per
		esempio, oggetto UomoStilizzato come insieme di oggetti semplici:
		cerchio(testa)+segmento(collo)+rettangolo(torso)+4 segmenti
		(braccia e gambe)
Implementare i metodi Print per gli oggetti:
	--> Assumendo che lo schermo sia una matrice NxM, realizzare
		la stampa degli oggetti stampando la matrice riga a riga

