#include <bits/stdc++.h>

using namespace std;
string str;
// Returns the length of the longest palindromic subsequence in seq
int lps()
{
    int n = str.length();
    int i, j, cl;
    int L[n][n]; // Create a table to store results of subproblems
    // Strings of length 1 are palindrome of lentgh 1
    for (i = 0; i < n; i++)
        L[i][i] = 1;
// Build the table. Note that the lower diagonal values of table are
// useless and not filled in the process. The values are filled in a
//cl is length ofsubstring
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i+1][j-1] + 2;
            else
                L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    return L[0][n-1];
}
int main()
{
    cin>>str;
    cout<<lps()<<endl;
    return 0;
}
