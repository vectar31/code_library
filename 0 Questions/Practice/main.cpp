#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int i=0;
    while(i<s.length())
    {

        char ch=s[i];
        //cout<<ch<<endl;
        int c=0;
        while(s[i]==ch)
            c++,i++;
        cout<<ch<<c;

    }
    cout<<endl;
    return 0;
}
