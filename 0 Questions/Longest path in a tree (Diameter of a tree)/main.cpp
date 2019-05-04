#include <bits/stdc++.h>
#define ll long long
#define N 2010 // number of nodes
using namespace std;
vector <vector <pair<int,int> > >G(N);
int d[N];
void dfs(int s)
{
    fill(d,d+N,-1);
    queue <int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].first,cost=G[u][i].second;
            if(d[v]==-1)
            {
                d[v]=d[u]+cost;
                q.push(v);
            }
        }
    }
}
int getnodewithmaxd(int n)
{
    int node,maxd=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]>maxd)
        {
            maxd=d[i];
            node=i;
        }
    }
    return node;
}
int main()
{
    int n,m;
    cin>>n;
    m=n-1;// number of edges
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(1);
    int s=getnodewithmaxd(n);
    dfs(s);
    s=getnodewithmaxd(n);
    int ans=d[s];
    cout<<ans<<endl;
    return 0;
}
