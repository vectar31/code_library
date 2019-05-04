#include <bits/stdc++.h>
#define N 1000010

using namespace std;
int primefactors[N]={0};
void sieve()
{
    for(int i=2;i<N;i+=2)primefactors[i]++;
    for(int i=3;i<N;i+=2)
        if(primefactors[i]==0)
            for(int j=i;j<N;j+=i)
                primefactors[j]++;
}
int main()
{
    sieve();
    return 0;
}
