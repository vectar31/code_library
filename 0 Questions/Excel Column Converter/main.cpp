//converts one form to another
#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
ll lettertocolumn(string s)
{
    ll n=s.length();
    ll i=0;
    ll res=0;
    while(i<n)
    {
        res=res*26+(s[i]-'A'+1);
        i++;
    }
    return res;

}
string columntoletter(ll c)
{
    string res="";
    while(c)
    {
        ll temp=(c-1)%26;
        res=char('A'+temp)+res;
        c=(c-temp)/26;
    }
    return res;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=s.length();
        ll i=0;
        string str="";
        while(s[i]>='A' && s[i]<='Z')
        {
            str+=s[i];
            i++;
        }
        ll num=0;
        while(s[i]>='0' && s[i]<='9')
            num=num*10+(s[i]-'0'),i++;
        if(i==n)
        {
            //cout<<str<<endl;
            ll temp=lettertocolumn(str);

            cout<<"R"<<num<<"C"<<temp<<endl;

        }
        else
        {
            i++;
            ll num2=0;
            while(s[i]>='0' && s[i]<='9')
            num2=num2*10+(s[i]-'0'),i++;
            string temp=columntoletter(num2);
            cout<<temp<<num<<endl;

        }
    }
    return 0;
}
