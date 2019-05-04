#include <bits/stdc++.h>
#define ll long long
#define N 1010
#define pos pair<int,int>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
/* This has been replaced by a pair
struct pos
{
    int x,y;
};
*/

int a[N][N];
bool visited[N][N];
int d[N][N];
vector <pair<int,vector<pos> > >connected_components;
//connected componenets is a vector of pos that are connected and also contains the size of the connected
//component so that you can sort and do other stuff
void reset(int n,int m)
{
    for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
                d[i][j]=-1;
            }
}
void bfsgrid(pos s,int n,int m)// do a bfs from source s={x,y}
{
    vector <pos> temp;
    visited[s.first][s.second]=true;
    d[s.first][s.second]=0;
    queue <pos> q;
    q.push(s);
    while(!q.empty())
    {
        pos t=q.front();
        temp.push_back(t);
        q.pop();
        for(int i=0;i<4;i++)
        {
            pos temp={t.first+dx[i],t.second+dy[i]};
            if(temp.first>=0 && temp.second>=0 && temp.first<n && temp.second<m  && a[temp.first][temp.second]==1 && !visited[temp.first][temp.second]) // whatever condition you want
            {
                q.push(temp);
                visited[temp.first][temp.second]=1;
                d[temp.first][temp.second]=d[t.first][t.second]+1;
            }
        }
    }
    connected_components.push_back({temp.size(),temp});

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        reset(n,m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j])
                    if(!visited[i][j])
                        bfsgrid({i,j},n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<d[i][j]<<" ";
                    cout<<endl;
        }
        for(int i=0;i<connected_components.size();i++)
        {
            int nn=connected_components[i].first;
            vector <pos>temp=connected_components[i].second;
            for(int j=0;j<nn;j++)
                cout<<temp[j].first<<" "<<temp[j].second<<endl;
            cout<<endl;
        }
    }
    return 0;
}
