#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll p[60000];
int main()
{
    p[0]=0;p[1]=1;
    ll n=2;
    while(n<60000)
    {
        ll i = 0;
        ll penta = 1;
        while (penta <= n)
        {
            ll sign = (i % 4 > 1) ? -1 : 1;
            p[n] = (p[n]  +  sign * (p[n - penta]));
            p[n]%=M;
            i++;
            ll j = (i % 2 == 0) ? i / 2 + 1 : -(i / 2 + 1);
            penta = j * (3 * j - 1) / 2;
        }
            n++;
    }
    while(1)
    {
        ll t;
        cin>>t;
        ll ans=p[t+1];
        cout<<ans<<endl;
    }
    return 0;
}
