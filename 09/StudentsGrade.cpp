/*Exsercise with STL multimap
	A teacher want to organize his student grades.
	Create a class to handle the grades.
	Read the file that contain the name of the students and the
	associated grades. Print the student in grade-order.
	Suggestion: consider the exsercize "Bagofwords.cpp" ed insert
	a method where: the map is copied into a multimap with key and value
	inverted and print with an iterator on the multimap.
File name: "Studenti.txt"
THIS PROGRAM IT'S NOT WORKING
Instead of using multimap you can use map<int, vector<string>>*/

using namespace std;
#include<map>
//#include<multimap>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>


class Reader{
	private:
		multimap<int,string> m;
		ifstream is;
	public:
		Reader()
		{
			map<string,int> maptmp;
			vector<string> vtmp;
			vector<string>::const_iterator viter;
			map<int, vector<string>> mappa;
			map<int, vector<string>>::const_iterator mappaiter;
			bool flag = false;
			string word,tmp;
			
			is.open("Studenti.txt");
			if(!is.good())
				cerr<<"File non aperto\n";
			
			while(is>>word)								//Si inserisce una parola del file di testo in word finchè non si arriva in fondo
			{
				if(!flag)								//Se flag=0, cioè viene letto il nome dello studente
				{	
					tmp = word;							//Il nome dello studente si mette in tmp
					flag = true;						//flag si pone a true
				}
				else									//Se flag = true
				{
					flag = false;									//Si mette flag a false
					maptmp.insert(make_pair(tmp, stoi(word)));		//Si inserisce in maptmp nome-->voto
				}
			}	
			
			
			map<string,int>::const_iterator iter = maptmp.begin();		//Iteratore di maptmp
			int max = iter->second;										//max conterrà il voto massimo, iniziamo mettendo il voto del primo studente all'interno di maptmp
			do{															//Esegui
				if((iter->second) > max)								//	se il voto dello studente puntato da iter è maggiore di max
					max = iter->second;									//		cambia il valore di max con questo valore
				++iter;													//	incrementa iter
			}while(iter!=maptmp.end());									//	esegui questi passaggi (if ed incremento) finchè non si arriva alla fine di maptmp
			
			
			for(int i = max; i != 0; --i)								//Ciclo for in cui i va da max fino a 1
			{
				for( iter = maptmp.begin(); iter!=maptmp.end(); ++iter)	//Si scorre ancora una volta maptmp
					if((iter->second) == i)								//Se il voto dello studente puntato è uguale ad i 
						vtmp.push_back(iter->first);		//	inserisci il nome dello studente in un vettore di stringhe vtmp
				mappa.insert(make_pair(i,vtmp));						//Una volta scorsa tutta la mappa maptmp, inserisci la coppia (i, vtmp) in "mappa "
				vtmp.clear();											//Pulisci vtmp
			}
			
			for(mappaiter=mappa.begin(); mappaiter!=mappa.end(); ++mappaiter)	//Si scorre "mappa", che è un map<int, vector<string>>
			{	
				for(viter=((mappaiter->second).begin()); viter!=((mappaiter->second).begin()); ++viter)	//Si scorre il vettore di stringhe all'interno di "mappa"
				{	
					m.insert(pair<int,string>(mappaiter->first, *viter));	//Inserisci voto->studenti in m (che è il multimap)
					//cout<<mappaiter->first<<" "<<*viter<<endl;
				}
			}
		}
	
	void Print()
	{
		multimap<int,string>::const_iterator mmiter;
		vector<string>::const_iterator viter;
		for(mmiter=m.begin(); mmiter!=m.end(); ++mmiter)
		{	cout<<"ciao"<<endl;
			cout<<mmiter->first<<": "<<mmiter->second;
			//for(viter = ((mmiter->second).begin()); viter != ((mmiter->second).end()); ++mmiter)
			//	cout<<*viter<<" ";
			cout<<endl;
		}
	}
	
};

int main()
{
	Reader r;
	r.Print();
}