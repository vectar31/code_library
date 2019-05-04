/* O(m*n) Dynamic Programming solution to find length of the longest common substring */
#include <bits/stdc++.h>
//geeks for geeks
using namespace std;

/* Returns length of longest common substring of X[0..m-1] and Y[0..n-1] */
int LCSubStr(string X,string Y, int m,int n)
{
    // Create a table to store lengths of longest common suffixes of
    // substrings.   Notethat LCSuff[i][j] contains length of longest
    // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
    // first column entries have no logical meaning, they are used only
    // for simplicity of program
    int LCSuff[m+1][n+1];
    int res = 0;  // To store length of the longest common substring
    /* Following steps build LCSuff[m+1][n+1] in bottom up fashion. */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                res = max(res, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return res;
}
/* Driver program to test above function */
int main()
{
    string x,y;
    getline(cin,x);
    getline(cin,y);
    int m=x.length(),n=y.length();
    cout << "Length of Longest Common Substring is " << LCSubStr(x,y,m,n);
    return 0;
}
