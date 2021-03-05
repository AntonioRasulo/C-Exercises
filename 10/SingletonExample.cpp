/*Singleton example*/

#include "log.h"	//Chiunque può usare il log basta includere il file con la definizione

int main()
{										//Per usare il log basta prendere l'istanza e 
	Log::Get()->Write("Salvare Log");	//chiamare l'unico metodo disponibile.
}										//Molto comodo, non serve passare Log come argomento.
										//Garanzia che una sola istanza accede al file di log evitando problemi