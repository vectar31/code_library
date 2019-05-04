#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll inv_mod(ll x)
{
    ll a = 1 , p = x , n = M-2;
    while(n)
    {
        if(n&1)
            a = (a*p)%M;
        p = (p * p )%M;
        n>>=1;
    }
    return a;
}
int main()
{
    int n;
    while(cin>>n)
        cout<<inv_mod(n)<<endl;
    return 0;
}
