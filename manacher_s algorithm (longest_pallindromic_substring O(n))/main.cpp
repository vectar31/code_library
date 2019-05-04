#include <iostream>

using namespace std;
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
//We store intermediate result in an array P, where P[ i ] equals to the length of the palindrome centers at Ti.
//The longest palindromic substring would then be the maximum element in P.
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
        cout<<P[i]<<" ";
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  cout<<endl;
  delete[] P;

  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
int main()
{
    cout<<longestPalindrome("abccba")<<endl;
    return 0;
}
