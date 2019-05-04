#include <bits/stdc++.h>
#define ll long long
using namespace std;
int phi[100010];
void euler_sieve()
{
    phi[1] = 1;
    for(int i=2; i<100000; i++)
    {
        if(!phi[i])
        {
            phi[i] = i-1;
            for(int j=(i<<1); j<=100000; j+=i)
            {
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}
int main()
{
    euler_sieve();
    for(int i=1;i<=20;i++)
        cout<<i<<" "<<phi[i]<<endl;
    return 0;
}
