//https://github.com/kartikkukreja/blog-codes/blob/master/src/BIT%20or%20Fenwick%20Tree%20Data%20Structure.cpp
#include <bits/stdc++.h>
#define ll long long
#define N 100010
#define LSOne(S) (S & (-S))
#define endl '\n'
using namespace std;
class BIT
{
	ll* ft, size;
public:
	BIT(ll n) {
		size = n;
		ft = new ll[n+1];
	}

	~BIT()	{
		delete [] ft;
	}

	ll sum(ll b)
	{
		ll sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}
	ll sum(ll a, ll b) {
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}
	void update(ll k, ll v)
	{
		for (; k <= size; k += LSOne(k))ft[k] += v;
	}
	void reset()
	{
	    for(int i=0;i<N;i++)
            ft[i]=0;
	}
}B1(N),B2(N);
void update(ll a, ll b, ll v)
{
    B1.update( a , v );
    B1.update( b+1 , -v );
    B2.update( a, v * (a-1) );
    B2.update( b+1 , -v * b );

}
ll query(ll b)
{
    ll res = B1.sum(b)*b - B2.sum(b) ;
    return res;
}
ll query(ll a, ll b)
{
    ll res = query(b) - query(a-1) ;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        while(c--)
        {
            ll ch,p,q,v;
            cin>>ch>>p>>q;
            if(!ch)
            {
                cin>>v;
                update(p,q,v);

            }
            else
                cout<<query(p,q)<<endl;
        }
        B1.reset();
        B2.reset();
    }
    return 0;
}
