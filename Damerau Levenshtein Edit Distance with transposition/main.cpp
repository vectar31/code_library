#include <bits/stdc++.h>
#define NMAX 10010
#define inf INT_MAX
#define endl '\n'

using namespace std;

char s1[NMAX],s2[NMAX];
int dp[NMAX][NMAX];

int edit_distance_leven()//from rosetta code
{
	int n=strlen(s1+1),m=strlen(s2+1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            else
            {
                    dp[i][j]=inf;
                    if(s1[i]==s2[j])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                    for(int k=i-1;k>=1;k--)
                        if(s1[i]==s2[j-1]&&s1[k]==s2[j]&&j>=2)
                            dp[i][j]=min(dp[i][j],dp[k-1][j-2]+1+(i-k-1));
            }
        }
    return dp[n][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        cin>>(s1+1)>>(s2+1);
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        if(s1[1]=='*')
            break;
        cout<<edit_distance_leven()<<endl;
    }
    return 0;
}
