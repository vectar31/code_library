/*
The following program calculate the minimum cost path in going from
top left to bottom right moving only bottom or right or diagonal (right down) using DP
For example, in the following figure, what is the minimum cost path to (2, 2)?
    1 2 3
    4 8 2
    1 5 3
The path with minimum cost is
(0, 0) –> (0, 1) –> (1, 2) –> (2, 2).
The cost of the path is 8 (1 + 2 + 2 + 3).
*/
#include <bits/stdc++.h>
#define N 1001

using namespace std;
int cost[N][N];
int tc[N][N];
int mincostpath(int m , int n)
{
    int i,j;
    tc[0][0]=cost[0][0];
    for (i = 1; i < m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
/* Initialize first row of tc array */
    for (j = 1; j < n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];
/* Construct rest of the tc array */
    for (i = 1; i <m; i++)
        for (j = 1; j <n; j++)
            tc[i][j] = min(tc[i-1][j-1], min(tc[i-1][j], tc[i][j-1])) + cost[i][j];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<tc[i][j]<<" ";
        cout<<endl;
    }
    return tc[m-1][n-1];
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    cout<<mincostpath(m,n)<<endl;
    return 0;
}
