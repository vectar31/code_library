#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int a[N];
int lis[N];
int lds[N];
void lislength(int n)
{
    for(int i=0;i<n;i++)
        lis[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
}
void ldslength(int n)
{
    for(int i=0;i<n;i++)
        lds[i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]<a[j] && lds[i]<lds[j]+1)
                lds[i]=lds[j]+1;
}
int longestbitoniclength(int n)
{
    int ans=1;
    for(int i=0;i<n;i++)
        ans=max(ans,lis[i]+lds[i]-1);
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
        lislength(n);
        ldslength(n);
        cout<<longestbitoniclength(n)<<endl;
    }
    return 0;
}
