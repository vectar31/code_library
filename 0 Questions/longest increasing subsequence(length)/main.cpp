#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int a[N];
int lis[N];
int lislength(int n)
{
    for(int i=0;i<n;i++)
        lis[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    int ans=1;
    for(int i=0;i<n;i++)
        ans=max(ans,lis[i]);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<lislength(n);
    }
    return 0;
}
