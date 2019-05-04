/*
optimized sieve
you have to consider 2 as prime seperately
checks primes till 10^8
to check prime use condition =>> if(!ifcV(i))
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXV = 10000000;
const int LMIT = 3163;
int flag[MAXV>>6];
#define ifcV(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define iscV(x) (flag[x>>6]|=(1<<((x>>1)&31)))
int counting=0;
void sieve() {
    register int i, j, k;
    for(i = 3; i < LMIT; i+=2)
        if(!ifcV(i))
            for(j=i*i, k=i<<1; j < MAXV; j+=k)
                iscV(j);
    for(int i=3;i<MAXV;i+=2)//check 2 alag se
        if(!ifcV(i))
            cout<<i<<endl;
}

int main()
{
    sieve();
    return 0;
}
