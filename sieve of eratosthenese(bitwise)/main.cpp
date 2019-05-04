/*
optimized sieve
you have to consider 2 as prime seperately
checks primes till 10^8
to check prime use condition =>> if(!ifcV(i))
*/
#include<bits/stdc++.h>
#define K 5000010
using namespace std;
const int MAXV = 100000000;
const int LMIT = 10000;
const int LEN = 5000000;
int flag[MAXV>>6];
int primes[K];
#define ifcV(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define iscV(x) (flag[x>>6]|=(1<<((x>>1)&31)))
int counting=1;
void sieve() {
    register int i, j, k;
    for(i = 3; i < LMIT; i+=2)
        if(!ifcV(i))
            for(j=i*i, k=i<<1; j < MAXV; j+=k)
                iscV(j);
}
int main()
{
    sieve();
    return 0;
}
