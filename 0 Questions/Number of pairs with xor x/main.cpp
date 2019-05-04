#include <bits/stdc++.h>
#define N 100010
#define ll long long

using namespace std;
int a[N];
map<int, int> M;
int main()
{
    int n,x;
    cin>>n>>x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        M[a[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int y = x ^ a[i];
        if(y == a[i])
            ans += M[a[i]] - 1;
        else
            ans += M[y];
    }
    cout << ans / 2 << endl;
}
