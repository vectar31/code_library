// O(ElogV)
// hacker earth blog
#include <bits/stdc++.h>
#define N 100010
#define ll long long

using namespace std;

int id[N], nodes, edges;

pair <ll, pair<int, int> > p[N];

void initialize()
{
    for(int i=0;i<N;++i)id[i]=i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}

ll kruskal(pair<ll, pair<int, int> > p[])
{
    int x, y;
    ll cost, minimumCost=0;
    for(int i=0;i<edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    initialize();
    cin >> nodes >> edges;
    for(int i=0;i<edges;++i)
    {
        int x,y;
        ll weight;
        cin >> x >> y >> weight;
        p[i]=make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    ll minimumCost=kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
