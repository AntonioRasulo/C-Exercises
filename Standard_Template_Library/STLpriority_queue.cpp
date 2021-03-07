/*Example STL priority_queue*/

using namespace std;

#include<iostream>
#include<queue>

int main()
{
	priority_queue<int> mypq;
	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);
	
	while(!mypq.empty())
	{
		cout<<mypq.top()<<" ";
		mypq.pop();
	}
	
	cout<<endl;
	return 0;
	
}
