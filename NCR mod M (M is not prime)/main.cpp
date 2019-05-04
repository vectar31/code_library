#include <bits/stdc++.h>
#define ll long long
#define N 100010
#define M 1000000007
#define MOD 1000000007
#define endl '\n'
using namespace std;
ll fact[N];
void cal()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
        fact[i]=(fact[i-1]*i)%M;
}
ll pow(int a, int b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b&1)
        {
            x=(x*y);
            if(x>MOD)x%=MOD;
        }
        y=(y*y);
        if(y>MOD) y%=MOD;
        b>>=1;
    }
    return x;
}
ll InverseEuler(int n)
{
    return pow(n,MOD-2);
}

ll C(int n,int r)
{
    return (fact[n]*((InverseEuler(fact[r]) * InverseEuler(fact[n-r])) % MOD)) % MOD;
}
int main()
{
    cal();
    for(int i=1;i<=1000;i++)
    {
        ll ans=C(100000,50000);
        //cout<<ans<<endl;
    }
    return 0;

}
