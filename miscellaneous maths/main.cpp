#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a=13456;
    int num_of_digits=(int)floor(1 + log10((double)a));  // calculates the number of digits in base 10
    cout<<num_of_digits<<endl;
    return 0;
}
