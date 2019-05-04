/*
Given an array of elements
Find the sum of divisors of divisors of product of the array.
For eg. Array = 2,3,3,3
Product = 54, divisors: 1,2,3,6,9,18,27,54
Now find sum of divisors of the above divisors: Ans here: 1+3+4+12+13+39+40+120 = 232
*/
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
		int n;
        cin>>n;
		map<ll,ll> m;
		for(int i=1; i<=n; i++)
        {
			ll temp;
            cin>>temp;
			for(int j=2; j<=sqrt(temp); j++)
            {
				ll cnt = 0;
				while(temp%j == 0)
				{
					temp/=j;
					cnt++;
				}
				if(cnt)m[j]+=cnt;
			}
			if(temp != 1)
				m[temp]++;
		}
		ll ans = 1;
		for(auto it:m)
        {
			long long pw = 1;
			int sum = 0;
			for(int i=it.second+1; i>=1; i--)
			{
				sum = (sum + ((long long)i*(long long)pw)%MOD)%MOD;
				pw = ((long long)pw*(long long)it.first)%MOD;
			}
			ans = (ans*sum)%MOD;
		}
		cout<<ans<<endl;
	}
}
