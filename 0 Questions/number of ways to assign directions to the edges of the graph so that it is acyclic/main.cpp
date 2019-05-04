/*
graph can consist of several connected components,
where each component is either a path or a cycle with some paths connected to some of the vertices.
We'll solve the problem for each component and multiply the result for each component.
If the component is a path, then however we orient the edges we won't form a cycle.
So, if there are x edges in the component, there are 2x ways to orient the edges.
Next, if the component has a cycle,
then we can orient the remaining edges in any way (it will not affect the existence of cycles),
then for the x edges on the cycle, we have 2x-2 ways to orient them.
This is because there are a total of 2x ways to orient the edges, but only 2 ways gives a directed cycle.
(fix the direction of one of the edges, then the directions of the other edges are uniquely determined to form a directed cycle)
Thus, if there are t edges not on the cycle and x edges on the cycle, the total number of ways for this component is 2t(2x-2).
Finally, to compute the final answer we multiply the answers for each component.
Computing the powers of 2 can be done by a simple precomputation or using binary exponentiation.
Finding the cycles can be easily done with a dfs.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 1e6 + 3;

int a[N];
int visited[N];
ll ans;
vector<int> cycles;
ll dp[N];
int cyclecnt;

void dfs2(int u)
{
	cycles[cyclecnt]++;
	visited[u] = 3;
	if(visited[a[u]] == 3) return ;
	dfs2(a[u]);
}

void dfs(int u)
{
	visited[u] = 2;
	if(visited[a[u]] == 0)
	{
		dfs(a[u]);
	}
	else if(visited[a[u]] == 1)
	{
		visited[u] = 1;
		return ;
	}
	else
	{
		cycles.pb(0);
		dfs2(u);
		cyclecnt++;
	}
	visited[u] = 1;
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = (dp[i-1]*2LL)%MOD;
	}
	ans = 1;
	memset(visited, 0, sizeof(visited));
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
		{
			dfs(i);
		}
	}
	ll cnt = n;
	for(int i = 0; i < cycles.size(); i++)
	{
		cnt -= cycles[i];
		ans = (ans*(dp[cycles[i]]-2+MOD))%MOD;
	}
	ans = (ans*dp[cnt])%MOD;
	if(ans < 0) ans += MOD;
	int ans2 = ans;
	printf("%d\n", ans2);
	return 0;
}
