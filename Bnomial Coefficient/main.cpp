#include <iostream>
#include <cmath>
#define in unsigned long long int
#define un unsigned int
using namespace std;
in iterbc(un n,un k)
{
    in res=1;
    if(k>n)
        return 0;
    if(k>n-k)
        k=n-k;
    for(un i=0;i<k;++i)
    {
        res=res*(n-i)/(i+1);
        //res/=(i+1);
    }
    return res;
}
in naiverecurbc(un n, un k)
{
    if(k>n)return  0;
    if(k==n)return 1;
    return naiverecurbc(n-1,k)+naiverecurbc(n-1,k-1);
}
void dpbc( un n , un k )
{
    in bc[n+1][k+1];
    for(un i=0;i<=n;i++)
    {
        for(un j=0;j<=min(i,k);j++)
        {
            if(j==0||j==i)
                bc[i][j]=1;
            else
                bc[i][j]=bc[i-1][j-1]+bc[i-1][j];
        }
    }
    for(un i=0;i<=n;i++)
    {
        for(un j=0;j<=min(i,k);j++)
            cout<<bc[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    un t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        //in ans;
        //ans=iterbc(n,k);
        //cout<<ans<<endl;
        dpbc(n,k);
    }

    return 0;
}
