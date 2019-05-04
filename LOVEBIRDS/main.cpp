#include <bits/stdc++.h>
#define N 1010
#define M 1908
using namespace std;
int a[N]={0};
void cal()
{
    a[0]=a[1]=1;
    for(int i=2;i<N;i++)
        for(int j=1;j<=i;j++)
            a[i]=(a[i]+(a[i-j]*a[j-1]))%M;
}
int main()
{
    cal();
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
