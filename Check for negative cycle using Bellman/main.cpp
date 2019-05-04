#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

set< pair<int,pii> > edges;
vector<int> bellman(int start,int ver)
{

    vector<int> vec(ver+2,100000000);
    vec[start]=0;
    for(int i=1;i<=ver;i++)
    {
        for(set<pair<int,pii> >::iterator it = edges.begin();it != edges.end();++it)
        {
            int x=(*it).first;
            int d=(*it).second.first;
            int y=(*it).second.second;
            if(vec[x]!=100000000)
                vec[y]=min(vec[y],vec[x]+d);
        }
    }
    return vec;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        edges.clear();
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.insert(make_pair(u,make_pair(w,v)));
        }

        int src=1;
        vector<int> vec=bellman(src,n);
        bool isnegcycle=false;
        for(int i=1;i<=n;i++)
        {

            for(set<pair<int,pii> >::iterator it = edges.begin();it != edges.end();++it)
            {
                int u=(*it).first;
                int w=(*it).second.first;
                int v=(*it).second.second;
                if(vec[u]!=100000000)
                    if(vec[v]>vec[u]+w)
                        isnegcycle=1;
            }
        }
        if(isnegcycle==1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }


}
