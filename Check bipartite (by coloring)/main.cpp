#include <bits/stdc++.h>
#define N 2010
#define endl '\n'

using namespace std;
vector <vector <int> >G(N);
int color[N];
bool checkbipartite(int s)
{
    queue <int>q;
    q.push(s);
    color[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        //cout<<u<<" "<<color[u]<<endl;
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else
            {
                if(color[u]==color[v])
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int n;//number of nodes
        int m;//number of edges
        cin>>n>>m;
        int s;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            s=u;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        color[i]=-1;

        bool f=1;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                f=f*checkbipartite(i);
            }
        }
      //  for(int i=1;i<=n;i++)
        //    cout<<color[i]<<" ";
      //  cout<<endl;
        cout<<"Scenario #"<<(tt++)<<":"<<endl;
        if(f)
            cout<<"No suspicious bugs found!"<<endl;
        else
            cout<<"Suspicious bugs found!"<<endl;


        //cout<<checkbipartite(s)<<endl;
        for(int i=0;i<N;i++)G[i].clear();
    }
    return 0;
}

