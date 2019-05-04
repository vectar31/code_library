#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1010000];
int ng[1001000], pg[1001000];
int main(){
	int n; cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];

	stack<int> s;
	s.push(1);
	for(int i=2; i<=n; i++){
		while(s.size() and a[s.top()] < a[i]){
			ng[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		ng[s.top()] = -1;
		s.pop();
	}
	s.push(n);
	for(int i=n-1; i>=1; i--){
		while(s.size() and a[s.top()] < a[i]){
			pg[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		pg[s.top()] = -1;
		s.pop();
	}
	for(int i=1; i<=n; i++)cout<<pg[i]<<" "<<ng[i]<<" ";cout<<endl;
	return 0;
}
