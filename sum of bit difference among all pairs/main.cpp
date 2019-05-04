#include <bits/stdc++.h>
#define N 100010
using namespace std;
int a[N];
int sumBitDifferences(int n)
{
    int ans=0;
    // traverse over all bits
    for (int i = 0; i < 32; i++)
    {
        // count number of elements with i'th bit set
        int count=0;
        for (int j = 0; j < n; j++)
            if ( (a[j] & (1 << i)) )
                count++;
        // Add "count * (n - count) * 2" to the answer
        ans += (count * (n - count) * 2);
    }
    return ans;
}
// Driver prorgram
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout << sumBitDifferences(n)<< endl;
    return 0;
}
