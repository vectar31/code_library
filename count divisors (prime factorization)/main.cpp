#include <bits/stdc++.h>
#define N 1000010
using namespace std;
bool prime[N];
int primes[80000];
int divisors[N];
void sieve()
{
    for(int i=0;i<N;i++)
        prime[i]=1;
    prime [0]=0;prime[1]=0;
    for(int i=2;i*i<=N;i++)
        if(prime[i])
            for(int j=2;i*j<=N;j++)
                prime[i*j]=0;
    primes[0]=2;
    int c=1;
    for(int i=3;i<N;i+=2)
        if(prime[i])
            primes[c++]=i;
}
int countdiv(int n)
{
    if(n==1)
        return 1;
    int res=1;
    for(int i=0;primes[i]*primes[i]<=n;i++)
    {
        int temp=0;
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
                n/=primes[i],temp++;
            res=res*(temp+1);
        }
    }
    if(n>1)
        res=res*2;
    return res;
}
void filldivisors()
{
    for(int i=1;i<N;i++)
        divisors[i]=countdiv(i);
}
int main()
{
    sieve();
    filldivisors();
    int n;
    cin>>n;
    cout<<divisors[n]<<endl;
    return 0;
}
