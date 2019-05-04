// Heavy-light decomposition (and LCA)
//
// Decomposes a tree into a set of disjoint paths ("chains") so that every
// path from the root to any other node touches at most ceil(log2(N)) chains.
// Every chain is rooted in a node and "hanging" downward.
//
// Also, the algorithm lays out all nodes in a sequence so that all chains in
// it are nicely ordered one by one and non-overlapping.
//
// After initialization, calling lca(a, b) can answer the lowest common
// ancestor of nodes a and b in O(log N) time.
//
// Globals:
// - parent[x] is the parent node of x
// - depth[x] is the depth of node x (depth of the root is 0)
// - size[x] is the number of nodes in the subtree rooted in x
// - chain[x] is the root node of the chain node x belongs to
// - home[x] is the position of node x in the produced sequence
//
// Time complexity: O(N)
//
// Constants to configure:
// - MAX is the maximum number of nodes

int parent[MAX], depth[MAX], size[MAX];
int chain[MAX], home[MAX];

void dfs(int x, int dad) {
  size[x] = 1;
  parent[x] = dad;

  for (int y : adj[x]) {
    if (y == dad) continue;

    depth[y] = depth[x] + 1;
    dfs(y, x);
    size[x] += size[y];
  }
}

void heli(int x, int dad, int c, int h) {
  chain[x] = c;
  home[x] = h++;

  int maks = -1;
  for (int y : adj[x]) {
    if (y == dad) continue;
    if (maks == -1 || size[y] > size[maks]) maks = y;
  }
  if (maks == -1) return;
  
  heli(maks, x, c, h);
  h += size[maks];
  
  for (int y : adj[x]) {
    if (y == dad || y == maks) continue;
    heli(y, x, y, h);
    h += size[y];
  }
}

int lca(int a, int b) {
  while (chain[a] != chain[b]) {
    if (depth[chain[a]] < depth[chain[b]]) swap(a, b);
    a = parent[chain[a]];
  }
  return depth[a] < depth[b] ? a : b;
}

void run() {
  // Assuming the root is 0
  dfs(0, -1);
  heli(0, -1, 0, 0);
}
