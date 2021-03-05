/*Example STL List*/

using namespace std;
#include<list>
#include<iostream>

int main()
{
	list<int> l;
	
	l.push_back(4);
	l.push_back(6);
	l.push_back(2);
	
	//Non ammette accesso random, si deve usare iteratori
	list<int>::iterator iter=l.begin();
	for(; iter!=l.end(); iter++)
		cout<<*iter<<endl;
}
