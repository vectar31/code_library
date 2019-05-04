#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

	string a,b;
	cin>>a>>b;
	vector<string> res;
	for(;;){
		int dx=b[0]-a[0],dy=b[1]-a[1];
		dx=(dx>0)-(dx<0);
		dy=(dy>0)-(dy<0);
		string s;
		if(dx>0)s+='R';
		if(dx<0)s+='L';
		if(dy>0)s+='U';
		if(dy<0)s+='D';
		if(s.size()==0) break;
		res.push_back(s);
		a[0]+=dx;
		a[1]+=dy;
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)cout<<res[i]<<endl;
	return 0;
}
