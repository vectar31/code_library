#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
int table_td[100][100]={0};
ll table_bu[2000][2000]={0};
int partitionstopdown(int n,int largestnum)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(largestnum==0)
        return 0;
    if(table_td[n][largestnum]!=0)
        return table_td[n][largestnum];
    table_td[n][largestnum]=partitionstopdown(n,largestnum-1)+partitionstopdown(n-largestnum,largestnum);
    return table_td[n][largestnum];
}
ll partitionsbottomup(int sum, int largestNumber){

    int i,j;
    for (i=0;i<=sum;i++)
        table_bu[i][0]=0;
    for (i=1;i<=largestNumber;i++)
        table_bu[0][i]=1;
    for (i=1;i<=sum;i++){
        for (j=1;j<=largestNumber;j++){
            if (i-j<0){
                table_bu[i][j]=table_bu[i][j-1];
                continue;
            }
            table_bu[i][j]=(table_bu[i][j-1]%M+table_bu[i-j][j]%M)%M;
        }
    }

    return table_bu[sum][largestNumber]%M;
}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        ll ans=partitionsbottomup(n,n-1) + 1;
        cout<<ans<<endl;
    }
    return 0;
}
