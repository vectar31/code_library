#include <bits/stdc++.h>
#define endl '\n'
#define N 310
#define inf 1e9+10
#define ll long long

using namespace std;

ll a[N],dp[N][N];
bool visited[N][N];
ll n;
ll solve(ll i, ll M)
{
    if(M<0)
        return 0;
    if(M==0)
        return 1;
    if(i>=n)
        return 0;
    if(visited[i][M])
        return dp[i][M];
    dp[i][M]=solve(i,M-a[i])+solve(i+1,M);
    visited[i][M]=1;
    return dp[i][M];
}
int main()
{
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll P;
    cin>>P>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(0,P)<<endl;
    return 0;
}
