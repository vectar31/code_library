#include <bits/stdc++.h>
#define N 1001
using namespace std;
int price[N],n;
int cutRod()
{
    int val[n+1];
    val[0] = 0;
    int i, j;
// Build the table val[] in bottom up manner and return the last entry
// from the table
    for (i = 1; i<=n; i++)
    {
        int max_val = INT_MIN;
        for (j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i-j-1]);
        val[i] = max_val;
    }
    return val[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>price[i];
    cout<<cutRod()<<endl;
    return 0;
}
