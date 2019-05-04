#include <bits/stdc++.h>
#define ll long long
#define N 100
using namespace std;
ll pf[N];
ll maxi=((1LL<<63)-1);
int c=0;
void primefactors(ll k)
{
    for(ll i=2;i*i<=k;i++)
        if(k%i==0)
            while(k%i==0)
                k/=i,pf[c++]=i;
    if(k>1)
        pf[c++]=k;
}
ll solve(ll n)
{
    ll res=maxi;
    for(int i=0;i<c;)
    {
        ll cnt=0;
        ll p=pf[i],kcount=0;
        while(pf[i]==p&&i<c)
            kcount++,i++;
        ll temp=p;
        while(n/temp!=0)
        {
            cnt=cnt+(n/temp);
            if(temp<(maxi/p))
            temp=temp*p;
            else
                break;
        }
        res=min(res,(cnt/kcount));
    }
    return res;
}
int main()
{
   // cout<<maxi<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        c=0;
        primefactors(k);
        cout<<solve(n)<<endl;
    }
    return 0;
}
