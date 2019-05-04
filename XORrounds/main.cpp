/*
Array A having N numbers. In an XOR round, each etempement of the array A is replaced by
the bitwise XOR (Exclusive OR) of itself, the previous element, and the next element in the array.
All operations take place simultaneously. Can you calculate A after K such XOR rounds ?
*/
#include <bits/stdc++.h>
#define N 510
using namespace std;
int a[N],b[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;k>0;i*=2,k/=2)
        {
            if(k&1)
            {
                int temp=((-i%n+n)% n)+1,temp2=(i%n)+1;
                for (int j=1;j<=n;j++)
                    b[j]=a[j];
                for(int j=1;j<=n;j++)
                {
                    a[j]^=b[temp++]^b[temp2++];
                    if(temp>n)temp=1;
                    if(temp2>n)temp2=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
