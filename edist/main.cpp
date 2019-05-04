#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
string a,b;
static int ans[2003][2003];
int editdistance(int m , int n)
{
    for(int i=0;i<=m;i++)
        ans[i][0]=i;
    for(int j=0;j<=n;j++)
        ans[0][j]=j;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                ans[i][j]=ans[i-1][j-1];
            else
                ans[i][j]=min(ans[i-1][j-1],min(ans[i][j-1],ans[i-1][j])) + 1;
        }
    }
    return ans[m][n];
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int m=a.length();
        int n=b.length();
        a=" "+a;
        b=" "+b;
        cout<<editdistance(m,n)<<endl;
    }
    return 0;
}
