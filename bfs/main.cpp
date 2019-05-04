#include <bits/stdc++.h>
#define ll long long
#define N 10010
using namespace std;
bool visited[N];
int d[N];
vector <vector<int> >G(N);
void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        visited[i]=0;
        d[i]=-1;
        G[i].clear();
    }
}
void bfs(int s)// do a bfs from source s={x,y}
{
    queue<int> q;
    visited[s]=1;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(!visited[v])
            {
                q.push(v);
                visited[v]=1;
                d[v]=d[u]+1;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        reset(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bfs(1);
        cout<<d[n]<<endl;
    }
    return 0;
}
