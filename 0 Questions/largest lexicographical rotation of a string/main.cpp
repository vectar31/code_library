#include <bits/stdc++.h>
#define ll long long

using namespace std;
int rotation(string &s, int n)
{
    int res=0,l=0,i=1;
    while(res+l+1<n && i<n)
    {
        int c=s[res+l]-s[(i+l)%n];
        if(!c)
            l++;
        else if(c<0)
        {
            i+=l+1;
            l=0;
        }
        else
        {
            res=max(res+l+1,i);
            i=res+1;
            l=0;
        }
    }
    return res;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
        s[i]=25-s[i]+'a'*2;
    int temp = rotation(s,n);
    for(int i=0;i<n;i++)
        s[i] = 25-s[i]+'a'*2;
    for(int i=0;i<n;i++)
    {
        cout << s[temp];
        temp = ( temp + 1 ) % n ;
    }
    cout << endl;
    return 0;
}
