/*Decorator Example Design Pattern*/

using namespace std;
#include<fstream>
#include<string>
#include "Decorator.h"
int main()
{
	//Per scrivere plain
	WriterPlain writer;
	writer.Write("ciao", "./a");
	
	//Per scrivere complesso
	WriteZipped zwriter(&writer);
	zwriter.Write("ciao", "./a");
	
	//Per scrivere codificato
	WriteEncoded ewriter(&writer);
	ewriter.Write("ciao", "./a");
	
	//Per scrivere codificato e compresso
	WriteEncoded ezwrite(&zwriter);
	ezwriter.Write(“ciao”, “./a”);
	
	//ecc....A run-time si può comporre come si preferisce le opzioni!
}