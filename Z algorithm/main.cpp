#include <iostream>
#define N 1000010
using namespace std;
int z[N];//z[i] = length of the longest substring starting from s[i] which is also a prefix of s
void calculate_z_array(string s)
{
    int n=s.length();
    int L=0,R=0;
    for(int i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n && s[R-L]==s[R])R++;
            z[i]=R-L;
            R--;
        }
        else
        {
            int k=i-L;
            if(z[k] < R-i+1)z[i]=z[k];
            else
            {
                L=i;
                while (R < n && s[R-L] == s[R])R++;
                z[i]=R-L;
                R--;
            }
        }
    }
}
int main()
{
    string s;
    cin>>s;
    calculate_z_array(s);
    return 0;
}
