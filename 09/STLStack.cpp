/*Example STL Stack*/

using namespace std;
#include<stack>
#include<iostream>
#include<string>

int main()
{
	stack<string> allwords;	//stack di parole
	allwords.push("hey");	//aggiungo parole
	allwords.push("ciao");
	allwords.push("treno");
	allwords.push("mannaia");
	while(allwords.size() > 0)
	{
		cout<<allwords.top()<<endl;	//Scrivo la parola in cima
		allwords.pop();			//Rimuovo la parola in cima
	}
	return 0;
}
