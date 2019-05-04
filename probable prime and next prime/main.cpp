#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll mulmod(ll a,ll b,ll c)
{
	return ((((a>>20)*b%c)<<20)+(a&((1<<(20))-1))*b)%c;
}
ll moddexp(ll a, ll b, ll MOD)//This function calculates a to the power b mod M
{
    ll res=1,y=a;
    while(b>0)
    {
        if(b&1)
            res=mulmod(res,y,MOD);
        y=mulmod(y,y,MOD);
        b>>=1;
    }
    return res;
}
bool check(ll a,ll n)
{
	ll m,x,y;
	for(m=n-1;m%2==0;m>>=1);
	x=moddexp(a,m,n);
	for(;m<n-1;m<<=1)
	{
		y=mulmod(x,x,n);
		if(y==1 && 1<x && x<n-1) return 0;
		x=y;
	}
	return x==1;
}

bool probableprime(ll n)
{
    int a[5]={2,3,5,7,11};
    for(int i=0;i<5;i++)
        if(n%a[i]==0)
            return n==a[i];
    for(int i=0;i<5;i++)
    {
        ll temp=a[i];
        if(!check(temp,n))return 0;
	}
	return 1;
}

int main()
{
    for(int i=1;i<20;i++)
        if(probableprime(i))
            cout<<i<<endl;
	return 0;
}
