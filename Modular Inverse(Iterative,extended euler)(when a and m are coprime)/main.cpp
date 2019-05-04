#include <bits/stdc++.h>
#define ll long long
//geeks for geeks
// Returns modulo inverse of a with respect to m using
// extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1
ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0=0,x1 = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        q=a/m;t=m;
        m=a%m;a=t;t=x0;
        x0=x1-q*x0;x1=t;
    }
    if (x1 < 0)x1+=m0;
    return x1;
}
// Driver program to test above function
int main()
{
    ll a = 3, m = 11;

    printf("Modular multiplicative inverse is %lld\n",modInverse(a, m));
    return 0;
}
