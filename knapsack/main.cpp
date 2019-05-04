#include <bits/stdc++.h>
#define N 1010
using namespace std;
int knapsack(int items,int weight[],int value[],int max_weight){
	int i,w;
	int dp[items+1][max_weight+1];

	for(i=0;i<=max_weight;i++){
		dp[0][i]=0;
	}
	for(i=0;i<=items;i++){
		dp[i][0]=0;
	}
	for(i=1;i<=items;i++){
		for(w=0;w<=max_weight;w++){
			dp[i][w] = dp[i-1][w];
			if(w-weight[i]>=0){
				dp[i][w] = max(dp[i][w],dp[i-1][w-weight[i]]+value[i]);
			}
		}
	}
	return dp[items][max_weight];
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		int items=0,i=0,max_weight=0;
		cin >> items >> max_weight;
		int weight[items+1],value[items+1];
		for(i=1;i<=items;i++){
			cin >> weight[i];
		}
		for(i=1;i<=items;i++){
			cin >> value[i];
		}
		int ans;
		ans = knapsack(items,weight,value,max_weight);
		cout << ans << endl;
	}
	return 0;
}
