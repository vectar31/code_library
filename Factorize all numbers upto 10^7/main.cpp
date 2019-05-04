#include <bits/stdc++.h>

using namespace std;
const int N = 10000000;
int lpf[N+1];//lpf[i] contains the least prime factor that divides the number i
int primes[670000];//primes contain all the prime numbers
void sieve()
{
    int c=0;// counter for primes array
    for (int i=2; i<=N; ++i)
    {
        if (lpf[i]==0)
            lpf[i]=i,primes[c++]=i;
        for (int j=0;j<c&&primes[j]<=lpf[i]&&i*primes[j]<=N; ++j)
            lpf[i * primes[j]] = primes[j];
    }
}
void factorize(int n)
{
    int a=lpf[n];
    while(n!=1)
    {
        while(n%a==0)
        {
            cout<<a<<" ";
            n/=a;
        }
        a=lpf[n];
    }
}
int main()
{
    sieve();
    factorize(109876);
    return 0;
}
