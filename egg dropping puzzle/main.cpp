#include <bits/stdc++.h>
#define NMAX 60
#define KMAX 1010
#define endl '\n'
int a[NMAX][KMAX];
using namespace std;
void solve(int n,int k)
{
    int res;
    for (int i=1;i<=n;i++)
        a[i][1]=1,a[i][0] = 0;
    for (int j=1;j<=k;j++)
        a[1][j]=j;
    for (int i=2;i<=n;i++)
        for (int j=2;j<=k;j++)
        {
            a[i][j]=INT_MAX;
            for (int l=1;l<=j;l++)
            {
                res=1+max(a[i-1][l-1],a[i][j-l]);
                if (res<a[i][j])a[i][j] = res;
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=55,k=1005;
    solve(n, k);
    int t;
    cin>>t;
    while(t--)
    {
        int tt,m,b;
        cin>>tt>>b>>m;
        cout<<tt<<" "<<a[b][m]<<endl;
    }
    return 0;
}
