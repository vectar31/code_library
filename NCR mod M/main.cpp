#include <bits/stdc++.h>
#define ll long long
#define N 100010
#define MOD 1000000007
#define endl '\n'
using namespace std;
ll fact[N],invmod[N];
ll modexp(ll base,ll power,ll M)
{
    ll res=1;
    while(power)
    {
        if(power&1)
            res=(res*base)%M;
        base=(base*base)%M;
        power>>=1;
    }
    return res;
}
void factcal()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
        fact[i]=(fact[i-1]*i)%MOD;
}
void calinvmod()
{
    invmod[N-1]=modexp(fact[N-1],MOD-2,MOD)%MOD;
    for(int i=N-2;i>=0;i--)
        invmod[i]=((i+1)*invmod[i+1])%MOD;
}
ll C(ll n,ll r)
{
    if(r>n)
        return 0;
    if(n==r||r==0)
        return 1;
    ll res=(fact[n]*invmod[n-r])%MOD;
    res=(res*invmod[r]);
    res%=MOD;
    return res;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    factcal();
    calinvmod();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        cout<<C(n,k)<<endl;
    }
    return 0;
}
