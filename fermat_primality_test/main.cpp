#include <bits/stdc++.h>

using namespace std;
bool fermat_primality_test(int n)
{
    if(n<2)return 0;
    if(n==2)return 1;
    int a = rand() % (n-2) + 2;
    int x = 1;
    for (int i=1; i<n; ++i)
        x = x * a % n;
    return x == 1;
}
int main()
{
    int n;
    while(cin>>n)
        cout<<fermat_primality_test(n)<<endl;
    return 0;
}
