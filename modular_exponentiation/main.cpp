#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll mulmod(ll a,ll b,ll c)
{
	return ((((a>>20)*b%c)<<20)+(a&((1<<(20))-1))*b)%c;
}
ll moddexp(ll a, ll b)//This function calculates a to the power b mod M
{
    ll res=1,y=a;
    while(b>0)
    {
        if(b&1)
            res=mulmod(res,y,M);
        y=mulmod(y,y,M);
        b/=2;
    }
    return res;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
