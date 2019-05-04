#include <bits/stdc++.h>
#define ll long long
#define N 1010
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct pos
{
    int x,y;
};
int a[N][N];
bool visited[N][N];
int d[N][N];
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
    visited[s.x][s.y]=true;
    d[s.x][s.y]=0;
    queue <pos> q;
    q.push(s);
    while(!q.empty())
    {
        pos t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            pos temp={t.x+dx[i],t.y+dy[i]};
            if(temp.x>=0 && temp.y>=0 && temp.x<n && temp.y<m  && a[temp.x][temp.y]==1 && !visited[temp.x][temp.y]) // whatever condition you want
            {
                q.push(temp);
                visited[temp.x][temp.y]=1;
                d[temp.x][temp.y]=d[t.x][t.y]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }
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
        bfsgrid({0,0},n,m);
    }
    return 0;
}
