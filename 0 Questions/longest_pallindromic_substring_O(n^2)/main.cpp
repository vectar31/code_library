#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int calculateodd()
{
    int ans=1;
    for(int i=1;i<n-1;i++)
    {
        int temp=1;
        for(int j=1; ;j++)
        {
            if(i-j<0||i+j>=n)
            break;
            if(s[i-j]==s[i+j])
                temp+=2;
            else
                break;
        }
        if(temp>ans)
            ans=temp;
    }
    return ans;
}
int main()
{
    //string s;
    cin>>s;
    n=s.length();
    cout<<calculateodd()<<endl;
    return 0;
}
