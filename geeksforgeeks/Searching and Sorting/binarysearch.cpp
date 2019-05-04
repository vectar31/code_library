#include <bits/stdc++.h>
#define N 1000001
#define in(n) scanf("%d",&n)
#define in2(a,b) scanf("d",&a,&b)
#define in3(a,b,c) scanf("d%d",&a,&b,&c)
#define out(n) printf("%d\n",n)
#define out2(a,b) printf("%d %d\n",a,b)
#define inll(n) scanf("%lld",&n)
#define inll2(a,b) scanf("lld",&a,&b)
#define inll3(a,b,c) scanf("lld%lld",&a,&b,&c)
#define outll(n) printf("%lld\n",n)
#define outll2(a,b) printf("%lld %lld\n",a,b)

using namespace std;

int binarysearch(int A[],int n, int x)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}
int main()
{
    return 0;
}
