#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

bool check[100000+10]={0};
ll prime[100000+10],p = 0 ;
int flag[10000000+10] ;
void sieve()
{
    for(int i=2;i<=100000;i++)
        if(!check[i])
        {
            prime[p++] = i ;
            for(int j=i+i;j<=100000;j+=i)check[j]=1;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        ll l,u;;
        cin>>l>>u;
        for(int i=0;i<p;i++)
        {
            ll M=l%prime[i];
            ll k=prime[i]-M ;
            if(M==0)k=0;
            for(int j=k;j<=u-l;j+=prime[i])
                if(l+j!=prime[i])flag[j]=tt ;
        }
        for(int i=0;i<=u-l;i++)
            if(flag[i]!=tt)cout<<(i+l)<<endl;
    }
    return 0;
}
