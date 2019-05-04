#include <bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

vector <vector <int> >G(n);
bool visited[N];
int d[N];
int time=0;
void reset(int n)
{
    for(int i=0;i<=n;i++)
        visited[i]=0,
        d[i]=-1;

}
void dfs(int s)
{
    visited[s]=1;
    d[s]=time++;
    for(int i=0;i<G[s].size();i++)
    {
        int v=G[s][i];
        if(!visited[v])
            dfs(v);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    return 0;
}
