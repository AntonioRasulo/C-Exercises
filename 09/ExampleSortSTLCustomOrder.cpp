/*Example of using Sorting with STL, custo order
IT'S NOT FUNCTION*/

using namespace std;
#include<algorithm>
#include<vector>
#include<iostream>
#include<stdlib.h>

struct Cmp{
	inline bool operator()(const int i, const int j){return i<j;}
};

int main()
{
	vector<int> vec;
	for(int i=0; i<100; ++i)
	{
		vec.push_back(rand());	
	}
	sort(vec.begin(),vec.end(),Cmp);		//Ordina il vettore in modo decrescente (per tipi noti)
	for(int i=0; i<vec.size(); ++i)
		cout<<vec[i]<<endl;
	
}