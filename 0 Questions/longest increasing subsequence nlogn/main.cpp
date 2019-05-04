#include <bits/stdc++.h>
#define N 100010
using namespace std;

// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller
int A[N],tailTable[N];
int CeilIndex(int l,int r,int key)
{
    while (r-l>1)
    {
        int m=l+(r-l)/2;
        if (tailTable[m]>=key)r=m;
        else l=m;
    }
    return r;
}

int LongestIncreasingSubsequenceLength(int A[], int size)
{
    // Add boundary case, when array size is one

    int len; // always points empty slot
    memset(tailTable,0,sizeof(tailTable[0])*size);
    tailTable[0]=A[0];
    len = 1;
    for (int i=1;i<size;i++)
    {
        if (A[i] < tailTable[0])
            // new smallest value
            tailTable[0] = A[i];
        else if (A[i] > tailTable[len-1])
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing
            // subsequence. It will replace ceil value in tailTable
            tailTable[CeilIndex( -1, len-1, A[i])] = A[i];
    }
    return len;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    printf("Length of Longest Increasing Subsequence is %d\n",LongestIncreasingSubsequenceLength(A, n));
    return 0;
}
