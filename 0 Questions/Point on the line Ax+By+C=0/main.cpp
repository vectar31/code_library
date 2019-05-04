#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll A, B, C;

int main()
{
	cin >> A >> B >> C;
	ll Ax=1,Bx=0,Ay=0,By=1;
	for(;B;swap(A,B),swap(Ax,Bx),swap(Ay,By)){
		ll k=A/B;
		A-=B*k;
		Ax-=Bx*k;
		Ay-=By*k;
	}
	if (C % A) puts("-1");
	else {
		Ax*=-C/A,Ay*=-C/A;
		if(abs(Ax)<=5000000000000000000ll && abs(Ay)<=5000000000000000000ll)
			cout<<Ax<< ' '<<Ay<<endl;
		else puts("-1");
	}
	return 0;
}
