#include <bits/stdc++.h>
#define ll long long
#define N 10000
using namespace std;
ifstream fin("input.txt");
    ofstream fout("output.txt");

int ans[N+2]={0};
int main()
{
    int n;
    fin>>n;
    int a[n+1];
    int b[3];
    if(fin.fail()||n<0)
    {
        fout<<"Wrong Order"<<endl;
        return 0;
    }
    for(int i=0;i<=n;i++)fin>>a[i];
    int r1,r2;
    fin>>r1>>r2;
    b[0]=r1*r2;b[1]=-(r1+r2);b[2]=1;

    for(int i=0;i<=n;i++)
    {
        ans[i]+=(a[i]*b[0]);
        ans[i+1]+=(a[i]*b[1]);
        ans[i+2]+=(a[i]*b[2]);
    }
    for(int i=0;i<=n+2;i++)
        fout<<ans[0]<<" ";
    fout<<endl;
    return 0;
}
