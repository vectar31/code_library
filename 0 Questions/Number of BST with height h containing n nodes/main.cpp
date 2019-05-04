#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[40][40] = {0};
// ans[n][h] contains number of BST with n nodes(1 to n) and height h
int main()
{
    int n, h;
	cin >> n >> h;
	for (int i = 0; i <= n; i++)
        ans[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k < i; ++k)
				ans[i][j] += ans[k][j-1] * ans[i - k - 1][j-1];
	cout << ans[n][h]<<endl;
	return 0;
}
