#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        int f1=-1,f2;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]<s[i+1])
                f1=i;
        }
        if(f1==-1)
            cout<<"no answer"<<endl;
        else
        {
            for(int j=n-1;j>f1;j--)
            {
                if(s[j]>s[f1])
                {
                    f2=j;
                    break;
                }
            }
            char c=s[f1];
            s[f1]=s[f2];
            s[f2]=c;
            string temp="";
            for(int i=f1+1;i<s.length();i++)
                temp=s[i]+temp;
            s=s.substr(0,f1+1)+temp;
            cout<<s<<endl;
        }
    }
    return 0;
}
