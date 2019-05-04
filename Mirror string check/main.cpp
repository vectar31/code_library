#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int n=s.size();
    for(int i=0; i<=n/2; i++)
	if(s[i]!=s[n-i-1])return 0;
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;cin >> s;
        int n=s.size(),flag=0;
        for(int i=0; i<n; i++)
            if(s[i]!='1' && s[i]!='8' && s[i]!='0')flag=1;
        if(flag==1)cout<<"NO"<<endl;
        else if(check(s))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
