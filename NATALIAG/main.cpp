#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct pos
{
    int x,y;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>m;
        int a[n][m];
        bool visited[n][m];
        int d[n][m];
        pos s,dest;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                char c;cin>>c;
                if(c=='O')
                {
                    //cout<<i<<" "<<j<<endl;
                    a[i][j]=1;
                }
                else if(c=='$')
                {
                    a[i][j]=1;
                    s={i,j};
                }
                else if(c=='#')
                {
                    a[i][j]=1;
                    dest={i,j};
                }
                else
                    a[i][j]=0;
                visited[i][j]=false;
                d[i][j]=-1;
            }

        visited[s.x][s.y]=true;
        d[s.x][s.y]=0;
        queue <pos> q;
        q.push(s);
        bool f=0;
        while(!q.empty())
        {
            pos t=q.front();
            //cout<<t.x<<" "<<t.y<<endl;
            q.pop();
            for(int i=0;i<4;i++)
            {
                pos temp={t.x+dx[i],t.y+dy[i]};
                //cout<<temp.x<<" "<<temp.y<<" "<<a[1][0]<<endl;
                if(temp.x>=0&&temp.y>=0 && temp.x<n && temp.y<m && a[temp.x][temp.y]==1 && !visited[temp.x][temp.y]) // whatever condition you want
                {
                    q.push(temp);
                    visited[temp.x][temp.y]=1;
                    d[temp.x][temp.y]=d[t.x][t.y]+1;
                    /*
                    if(temp.x==dest.x && temp.y==dest.y)
                    {
                        f=1;
                        break;
                    }
                    */
                }
            }
//            if(f)
  //              break;
        }
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<d[i][j];
            cout<<endl;
        }
        */
     //   if(f)
            cout<<d[dest.x][dest.y]<<endl;
      //  else
        //    cout<<-1<<endl;

    }
    return 0;
}
