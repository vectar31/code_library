#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=601;
const int M=2500001;
int a[N],b[N],d[M];
int c[M];
int main()
{
	int i,j,n,m,e,f,g,h,k;
	cin>>m>>n;
	for(i=1;i<=n;i++)
		cin>>b[i]>>a[i];
	k=1;
	d[k]=0;
	for(i=1;i<=n;i++)
	{
		sort(d+1,d+k+1);
		for(j=k;j>=1;j--)
		{
			if(d[j]+a[i]<=m)
			{
				if(c[d[j]+a[i]]==0)
				{
					k++;
					d[k]=d[j]+a[i];

				}
				c[d[j]+a[i]]=max(c[d[j]+a[i]],c[d[j]]+b[i]);
			}
		}
	}
	int ans=0;
	for(i=1;i<=m;i++)
		ans=max(ans,c[i]);
	cout<<ans<<endl;
	return 0;
}


