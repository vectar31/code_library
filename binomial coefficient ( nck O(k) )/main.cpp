#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ncr(int n,int k)
{
    ll res=1;
    if(k>n-k)
        k=n-k;
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<ncr(n,k)<<endl;
    return 0;
}
