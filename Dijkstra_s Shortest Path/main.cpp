#include <bits/stdc++.h>
#define N 100010
#define ll long long

using namespace std;

vector < pair < int , int > > v [N];   // each vertex has all the connected vertices with the edges weights
int dist [N];
bool vis [N];
int parent [N];
void dijkstra(int src)
{
   for(int i=0;i<N;i++)                                             // set the vertices distances as infinity
    {
        dist[i]=INT_MAX;
        parent[i]=0;
    }
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[src] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue
    s.insert({0 , src});                          // insert the source node with distance = 0
    while(!s.empty())
    {
        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());
        int x = p.second;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
        vis[x] = true;
        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; int w = v[x][i].second;
            if(dist[x] + w < dist[e]  ){// check if the next vertex distance could be minimized
                parent[e] = x;
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
        //cout<<endl;
    }
}
void printpath(int src,int dest)
{
    // prints path from src to dest
    vector<int> path;
    if(parent[dest]!=src)
    {
        path.push_back(dest);
        dest=parent[dest];
    }
    path.push_back(dest);
    path.push_back(src);
    for(int i=path.size()-1;i>=0;i--)
        cout<<path[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    dijkstra(1);

    //print distances
    for(int i=2;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;

    return 0;
}
