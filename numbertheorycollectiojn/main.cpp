#include <bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;

int gcd (int a ,int b)
{
    while(b)
        b^=a^=b^=a%=b;
    return a;
}

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}


int phi ( int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            res-=(res/i);
        }
    }
    if(n>1)
        res-=(res/n);
    return res;
}

ll modexp( int a , int b ,int m)
{
    ll res=1,y=a;
    while(b>0)
    {
        if(b&1)
            res=((res%m)*(y%m))%m;
        y=((y%m)*(y%m))%m;
        b/=2;
    }
    return res;
}

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

bool checkprime(int n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0)
            return false;
    return true;
}
int main()
{

    return 0;
}
