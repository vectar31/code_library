#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 100010
using namespace std;

ll a[N],presum[N];

ll binarysearch(ll n,ll k)
{
    ll low=1,high=presum[n],ans;
	while(low<=high)
	{
		ll mid=low+((high-low)>>1),index=0,temp=0,j=0;
		ans=presum[n];
		for(ll i=0;i<n;i++)
		{
			temp=presum[i+1]-presum[j];
			if(temp<mid)index+=(i-j+1);
			else
			{
                ans=min(ans,temp);
				j+=1;
				while(j<=i)
				{
					temp=presum[i+1]-presum[j];
					if(temp<mid)
					{
                        index+=(i-j+1);
						break;
					}
					ans=min(ans,temp);
					j++;
				}
			}
		}
		if(index>k-1)high=mid-1;
		else if(index<k-1)low=mid+1;
		else return ans;
	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		presum[i+1]=presum[i]+a[i];
	}
	ll ans=binarysearch(n,k);
	cout<<ans<<endl;
	return 0;
}
