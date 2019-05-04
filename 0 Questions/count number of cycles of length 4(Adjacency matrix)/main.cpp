#include <bits/stdc++.h>
#define N 2010
#define ll long long

using namespace std;
bitset <N> G[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++ )
        for(int j=1;j<=n;j++)
        {
            int temp;
            cin>>temp;
            G[i][j]=temp;
        }
        ll ans=0,temp=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            temp=(G[i]&G[j]).count(),
            ans+=(temp*(temp-1) /2);
    ans/=2;
    cout<<ans<<endl;
    return 0;
}
