#include <bits/stdc++.h>
#define ll long long
using namespace std;
void permute(string p,string s )
{
    int n=s.length();
    if(!n)
        cout<<p<<endl;
    else
        for(int i=0;i<n;i++)
            permute(p+s[i],s.substr(0,i)+s.substr(i+1));
}
int main()
{
    string s;
    cin>>s;
    permute("",s);
    return 0;
}
