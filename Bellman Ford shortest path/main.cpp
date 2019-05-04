#include <bits/stdc++.h>
#define N 1000010
#define ll long long
//also keeps in mind the negative cycle in graph if any
using namespace std;
// 0 based indexing
vector < int > v [N];   // each vertex has all the connected vertices with the edges weights
int dis [N];

void reset()
{
    for(int i = 0; i < N; i++)
    {
        dis[i] = INT_MAX;
        v[i].clear();
    }

}
void bellman(int n)
{

    dis[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int j = 0;
        while(v[j].size() != 0)
        {
            if(dis[ v[j][0]  ] + v[j][2] < dis[ v[j][1] ] )
                dis[ v[j][1] ] = dis[ v[j][0]  ] + v[j][2];
            j++;
        }
    }
}
int main()
{
    reset();
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int from,next,weight;
        scanf("%d%d%d", &from , &next , &weight);
        from--;
        next--;
        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
    }
    bellman(n);
    //print distances
    for(int i=1;i<n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;

    return 0;
}
