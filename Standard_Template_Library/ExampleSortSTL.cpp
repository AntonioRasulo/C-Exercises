/*Example of using Sorting with STL*/

using namespace std;
#include<algorithm>
#include<vector>
#include<iostream>
#include<stdlib.h>

int main()
{
	vector<int> vec;
	for(int i=0; i<100; ++i)
	{
		vec.push_back(rand());	
	}
	sort(vec.begin(),vec.end());		//Ordina il vettore in modo crescente (per tipi noti)
	for(int i=0; i<vec.size(); ++i)
		cout<<vec[i]<<endl;
	
}