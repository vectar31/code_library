// Palindromic tree
//
// Given a string, consider all its palindromic substrings.
// Denote every palindrome by its radius inside out. For example, denote the
// palindrome 'abcba' by 'cba'.
// This algorithm constructs a trie of all such radiuses.
//
// The algorithm is very similar to Aho-Corasick.
// More information:
// - http://adilet.org/blog/25-09-14/
// - http://codeforces.com/blog/entry/13959
//
// To run, set N and s, then call paltree().
// Note: It is assumed the string contains uppercase letters only.
//
// Globals:
// - N is the length of the string
// - s is the string
// - V is the number of vertices in the trie
// - trie[x][c] is the child of node x labeled with letter 'A' + c
// - fn[x] points from node x to it's "failure" node
// - len[x] is the depth of node x
//
// The root of even palindromes is node 0.
// The root of odd palindromes is node 1.
//
// Time complexity: O(N)
//
// Constants to configure:
// - MAX is the maximum length of the string
// - ALPHA is the size of the alphabet (usually 26)

int N;
char s[MAX];

int V;
int trie[MAX][ALPHA];
int fn[MAX], len[MAX];

int node() {
  REP(i, ALPHA) trie[V][i] = 0;
  fn[V] = len[V] = 0;
  return V++;
}

int suffix(int t, int i) {
  while (i-len[t]-1 < 0 || s[i-len[t]-1] != s[i]) t = fn[t];
  return t;
}

void paltree() {
  V = 0; node(); node();
  len[0] =  0; fn[0] = 1;
  len[1] = -1; fn[1] = 0;

  int t = 0;
  REP(i, N) {
    int c = s[i] - 'A';
    t = suffix(t, i);

    int &x = trie[t][c];
    if (!x) {
      x = node();
      len[x] = len[t] + 2;
      fn[x] = t == 1 ? 0 : trie[suffix(fn[t], i)][c];
    }
    t = x;
  }
}
