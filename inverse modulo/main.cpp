#include <iostream>

using namespace std;
int extendedgcd(int a,int b,int &x,int &y)
{
    if(a==0)
    {
        x=0;y=1;return b;
    }
    int x1,y1;
    int gcd=extendedgcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return gcd;
}
int inversemod(int a , int m)
{
    int x,y;
    int g=extendedgcd(a,m,x,y);
    if(g==1)//inverse mod exists only if gcd(a,m)=1
    {
        int res=((x%m)+m)%m;
        return res;
    }
    else
    {
        //not found
        return -1;
    }


}
int main()
{
    int a,m;
    cin>>a>>m;
    int ans=inversemod(a,m);
    cout<<ans<<endl;
    return 0;
}
