#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;
int main()
{
    ll n;
    while(cin>>n,n)
    {
        ll i=2;
        int temp,m;
        while(i*i<=n)
        {
            m=0;
            temp=0;
            if(n%i==0)
            {
                m=i;
                while(n%i==0)
                {
                    temp+=1;
                    n/=i;
                }
                cout<<m<<"^"<<temp<<" ";
            }
            if(n==1)break;
            ++i;
        }
        if(n>1)
            cout<<n<<"^1";
        cout<<endl;
    }
return 0;
}
