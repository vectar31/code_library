#include <bits/stdc++.h>
#define inf 1e8 // be careful with this
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int g[n][n];
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            g[i][j]=inf;
            g[i][i]=0;
        }
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=w;
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i][j]!=inf)
                cout<<"Shortest Path from "<<i   <<" to "<<j<<" is "<<g[i][j]<<endl;
        }
    }
    return 0;
}
