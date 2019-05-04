#include <bits/stdc++.h>
#define ll long long

using namespace std;
int partitions(int n,int largestnum)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(largestnum==0)
        return 0;
    return partitions(n,largestnum-1)+partitions(n-largestnum,largestnum);
}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        cout<<partitions(n,n-1)<<endl;
    }
    return 0;
}
