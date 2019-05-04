#include <bits/stdc++.h>
#define N 100010
#define inf 1e9

using namespace std;
vector <int> G[N];
int disc[N],low[N],parent[N],_time;
bool visited[N],AP[N];//AP[i] is true if it's an articulation point
vector <pair<int,int > >bridges;// contains all the bridges
void reset()
{
    for(int i=0;i<N;i++)
    {
        G[i].clear();
        disc[i]=0;
        low[i]=inf;
        parent[i]=-1;
        visited[i]=0;
        AP[i]=0;
    }
    _time=0;
}
void dfs(int vertex)
{
    visited[vertex]=true;
    disc[vertex]=low[vertex] = ++_time;
    int child=0;
    for(unsigned int i=0;i<G[vertex].size();i++)
    {
        int adj=G[vertex][i];
        if(!visited[adj])
        {
            child=child+1;
            parent[adj]=vertex;
            dfs(adj);
            low[vertex] = min(low[vertex], low[adj]);
            if(parent[vertex]== -1 && child > 1)
                AP[vertex]=true;
            if(parent[vertex]!=-1 && low[adj]>=disc[vertex])
                AP[vertex]=true;
            if( low[adj] > disc[vertex])
            bridges.push_back({vertex,adj});

        }
        else if(parent[vertex]!=adj)
            low[vertex] = min(low[vertex], disc[adj]);
    }
}
int main()
{
    reset();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    return 0;
}
