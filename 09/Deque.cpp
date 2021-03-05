/*Esempio STL Deque*/

using namespace std;
#include<iostream>
#include<deque>

int main()
{
	deque<int> d;
	d.push_back(4);
	d.push_back(8);
	
	for(int i=0; i<d.size(); i++)
		cout << d[i] << endl;
}
