#include <iostream>

using namespace std;
#include <bits/stdc++.h>
#define N 100010
#define endl '\n'
using namespace std;
set < pair <int,int> > ds;
int sz[N],parent[N];
int findset(int a)
{
	if(parent[a]==0)
        return a;
	return parent[a]=findset(parent[a]);
}
void merge (int a,int b)
{
	int x=findset(a),y=findset(b);
	if(x==y)
        return;
	parent[x]=y;
	ds.erase({sz[y],y});
	ds.erase({sz[x],x});
	sz[y]+=sz[x];
	ds.insert({sz[y],y});
}
int main()
{

    return 0;
}
