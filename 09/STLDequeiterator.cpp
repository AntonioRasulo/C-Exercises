/*Esempio STL Deque con iteratori*/

using namespace std;
#include<deque>
#include<iostream>

int main()
{
	deque<int> d;
	d.push_back(2);
	d.push_back(6);
	deque<int>::iterator iter = d.begin();
	for(; iter != d.end(); iter++)
		cout<<*iter<<endl;
}
