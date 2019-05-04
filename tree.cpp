// Common algorithms on trees
//
// To initialize, call dfs(root, -1).
//
// Globals:
// - N is the number of nodes
// - length[x] is the cost of the edge between x and it's parent
// - adj[x] is a list of nodes adjacent to x
// - jump[x][i] is the 2^i-th ancestor of x, or -1 if it doesn't exist
// - depth[x] is the depth of node x (depth of the root is 0)
// - dist[x] is the cost of the path from root to x
// - discovery[x] is the discovery time in DFS order of the tree
// - finish[x] is the finish time in DFS order of the tree
//
// Functions:
// - dfs(root, -1) is used to initialize the globals
// - is_ancestor(x, y) return true if x is an ancestor of y
// - lca(x, y) returns the lowest common ancestor of x and y
// - distance(x, y) returns the cost of the path between x and y
// - num_edges(x, y) returns the number of edges on the path between x and y
// - relative_child(x, y) returns the child of x on the path from x to it's descendant y
// - kth(x, y, k) returns the k-th node on the path from x to y
//
// Time complexities:
// - dfs: O(N)
// - is_ancestor: O(1)
// - lca: O(log N)
// - distance: O(1)
// - num_edges: O(1)
// - relative_child: O(log N)
// - kth: O(log N)
//
// Constants to configure:
// - MAX is the maximum number of nodes
// - LG is ceil(log2(MAX))

int N;
llint length[MAX];
vector<int> adj[MAX];

int jump[MAX][LG];
int depth[MAX];
llint dist[MAX];

int tick;
int discovery[MAX];
int finish[MAX];

void dfs(int x, int dad) {
  jump[x][0] = dad == -1 ? x : dad;
  FOR(i, 1, LG) jump[x][i] = jump[ jump[x][i-1] ][i-1];

  discovery[x] = tick++;
  for (int y : adj[x]) {
    if (y == dad) continue;

    depth[y] = depth[x] + 1;
    dist[y] = dist[x] + length[y];
    dfs(y, x);
  }
  finish[x] = tick++;
}

bool is_ancestor(int x, int y) {
  return discovery[x] <= discovery[y] && finish[y] <= finish[x];
}

int lca(int x, int y) {
  if (is_ancestor(x, y)) return x;
  for (int i = LG-1; i >= 0; --i)
    if (!is_ancestor(jump[x][i], y))
      x = jump[x][i];
  return jump[x][0];
}

llint distance(int x, int y) {
  return dist[x] + dist[y] - 2 * dist[lca(x, y)];
}

int num_edges(int x, int y) {
  return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int relative_child(int x, int y) {
  assert(x != y);
  if (!is_ancestor(x, y)) return jump[x][0];

  for (int i = LG-1; i >= 0; --i)
    if (depth[y] - (1<<i) > depth[x])
      y = jump[y][i];
  return y;
}

int kth(int x, int y, int k) {
  int p = lca(x, y);
  int d = num_edges(x, y);

  for (int i = LG-1; i >= 0; --i) {
    if (depth[x] - (1<<i) >= depth[p] && k - (1<<i) >= 0) {
      d -= 1<<i;
      k -= 1<<i;
      x = jump[x][i];
    }
    if (depth[y] - (1<<i) >= depth[p] && d - (1<<i) >= k) {
      d -= 1<<i;
      y = jump[y][i];
    }
  }
  return k == 0 ? x : y;
}
