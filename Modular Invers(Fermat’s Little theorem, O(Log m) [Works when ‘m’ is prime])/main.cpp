// C++ program to find modular inverse of a under modulo m
// This program works only if m is prime.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// To compute x raised to power y under modulo m
ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m)%m;
    p = (p * p) % m;

    return (y%2==0)?p:(x*p)%m;
}

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m);
    }
}
// Driver Program
int main()
{
    ll a = 3, m = 11;
    modInverse(a, m);
    return 0;
}
