// Aho Corasick
//
// Given a set of patterns, it builds the Aho-Corasick trie. This trie allows
// searching all matches in a string in linear time.
//
// To use, first call `node` once to create the root node, then call `insert`
// for every pattern, and finally initialize the trie by calling `init_aho`.
// Note: It is assumed all strings contains uppercase letters only.
//
// Globals:
// - V is the number of vertices in the trie
// - trie[x][c] is the child of node x labeled with letter 'A' + c
// - fn[x] points from node x to it's "failure" node
//
// Time complexity: O(N), where N is the sum of lengths of all patterns
//
// Constants to configure:
// - MAX is the maximum sum of lengths of patterns
// - ALPHA is the size of the alphabet (usually 26)

int V;
int trie[MAX][ALPHA];
int fn[MAX];

int node() {
  REP(i, ALPHA) trie[V][i] = 0;
  fn[V] = 0;
  return V++;
}

int insert(char *s) {
  int t = 0;
  for (; *s; ++s) {
    int c = *s - 'A';
    if (trie[t][c] == 0) trie[t][c] = node();
    t = trie[t][c];
  }
  return t;
}

void init_aho() {
  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int t = Q.front(); Q.pop();
    
    REP(c, ALPHA) {
      int x = trie[t][c];
      if (x) {
        Q.push(x);

        if (t) {
          fn[x] = fn[t];
          while (fn[x] && trie[fn[x]][c] == 0) fn[x] = fn[fn[x]];
          if (trie[fn[x]][c]) fn[x] = trie[fn[x]][c];
        }
      }
    }
  }
}
