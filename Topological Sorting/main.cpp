/*
A topological sorting of a directed graph G is a linear ordering of its vertices such that
for every directed edge u->v, u comes before v in the ordering.
A topological sorting is possible if and only if the graph has no directed cycles i.e., it is a Directed Acyclic Graph (DAG).
It is always possible to find a topological order for a DAG and this can be done in linear time.


Topological sorting of a DAG can be found with DFS. During the depth-first traversal of the graph,
just when a vertex finishes expanding (i.e., all its outlinks have been visited), add it to a stack.
The order of vertices in the stack represents the topological order of the DAG.
*/
#include <bits/stdc++.h>
#define N 100010

using namespace std;
vector <int> G[N];
stack <int> topsorted;
bool visited[N];
void reset()
{
    for(int i=0;i<N;i++)
    {
        G[i].clear();
        visited[i]=0;
    }
}
void topological_sort(int u)
{
    visited[u] = true;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if (!visited[v])
            topological_sort(v);
    }
    topsorted.push(u);
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
    }
    for(int i=1;i<=n;i++)
        if(!visited[i])
            topological_sort(i);
    while(!topsorted.empty())
    {
        cout<<topsorted.top()<<" ";
        topsorted.pop();
    }
    cout<<endl;
    return 0;
}
