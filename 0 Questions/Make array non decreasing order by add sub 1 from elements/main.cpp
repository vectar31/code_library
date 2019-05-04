/*
Question:http://codeforces.com/contest/13/problem/C
Given a sequence of N integer numbers.
At each step it is allowed to increase the value of any number by 1 or to decrease it by 1.
Find smallest number of steps to make the sequence non-decreasing.

Solution:
Note, that there exists a non-decreasing sequence,
which can be obtained from the given sequence using minimal number of moves
and in which all elements are equal to some element from the initial sequence
(i.e. which consists only from the numbers from the initial sequence).

Suppose {ai} is the initial sequence, {bi} is the same sequence,
but in which all elements are distinct and they are sorted from smallest to greatest.

Let f(i,j) be the minimal number of moves required to obtain the sequence in which:
the first i elements are non-decreasing and i-th element is at most bj.
In that case the answer to the problem will be equals to f(n,k), where n is the length of {ai} and k is the length of {bi}.
We will compute f(i,j) using the following recurrences:

f(1,1)=|a1-b1|
f(1,j)=min{|a1-bj|,f(1,j-1)},  j>1
f(i,1)=|ai-b1|+f(i-1,1),  i>1
f(i,j)=min{f(i,j-1),f(i-1,j)+|ai-bj|},  i>1, j>1

The complexity is O(N2). To avoid memory limit one should note that to compute f(i,*) you only need to know f(i-1,*) and the part of i-th row which is already computed.
*/
#include <bits/stdc++.h>
#define N 5010
#define ll long long
#define endl '\n'

using namespace std;
int a[N],vals[N];
ll d[2][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		vals[i]=a[i];
	}
	sort(vals,vals+n);
	int current=0,new_=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			d[new_][j]=d[current][j]+abs(a[i]-vals[j]);
			if (j>0)d[new_][j]=min(d[new_][j],d[new_][j-1]);
		}
		swap(current,new_);
	}
	ll res = d[current][0];
	for(int i=0;i<n;i++)
		res=min(res,d[current][i]);
	cout<<res<<endl;
	return 0;
}
