#include <bits/stdc++.h>
#define N 100000001
using namespace std;
bool prime[N];
void sieve()
{
    for(int i=0;i<N;i++)
        prime[i]=1;
    prime [0]=0;prime[1]=0;
    for(int i=2;i*i<=N;i++)
        if(prime[i])
            for(int j=2;i*j<=N;j++)
                prime[i*j]=0;
}
int main()
{
    sieve();
    return 0;
}
