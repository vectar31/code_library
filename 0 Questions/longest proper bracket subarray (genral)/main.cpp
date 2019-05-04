/*
1,2,3,4 - different type of opening brackets
-1,-2,-3,-4 - corresponding closing brackets
Find longest subarray iof proper brackets
Eg 1 2 -2 -1 is proper
*/



#include<bits/stdc++.h>
using namespace std;
int b[200005];
int main()
{
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>b[i];
	stack<int>s;
	int result=0;
	s.push(0);
	for(int i=1;i<=n;i++)
	{
		if(b[i]>0)// if its an opening bracket
            s.push(i);
		else
		{
			int index=s.top();
			s.pop();
			if(b[index]==-b[i])// if its the relevant closing bracket
			{
				if(!s.empty())
					result=max(result,i-s.top());// take the best option
				else
					s.push(i);
			}
			else s.push(i);
		}
	}
	cout<<result<<"\n";
	return 0;
}
