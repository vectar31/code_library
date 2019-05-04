#include <bits/stdc++.h>
#define N 30
#define endl '\n'
// path from 0,0 to n-1,n-1
using namespace std;
bool visited[N][N],a[N][N];
int res=0,n;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
void dfs(int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        res++;
        return;
    }
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {

        int tempx=x+dx[i],tempy=y+dy[i];
        if(tempx<0||tempx >= n||tempy<0||tempy>=n)
            continue;
        if(visited[tempx][tempy]||a[tempx][tempy]) continue;
        dfs(tempx,tempy);
        visited[tempx][tempy]=0;// backtrack
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        dfs(0,0);
        cout<<res<<endl;
        memset(visited,0,sizeof visited);
        res=0;
    }
    return 0;
}
