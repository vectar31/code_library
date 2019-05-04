#include <bits/stdc++.h>
#define N 100000000
using namespace std;
bool sieve[N];

void eratosthenes()
{
    int sqrt_N= sqrt(N);
    sieve[0] = sieve[1] = true;
    for (int i=2; i<=sqrt_N; i++)
        if (!sieve[i])
            for (int k=(N-1)/i, j=i*k; k>=i; k--, j-=i)
                if (!sieve[k])
                    sieve[j] = true;
}
int main()
{
    eratosthenes();
    return 0;
}
