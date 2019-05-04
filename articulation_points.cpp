// Articulation points
//
// Finds the articulation points on an undirected graph.
// A node is an articulation points iff it's removal would split the graph in
// multiple connected components.
//
// To find articulation points on a graph, call init().
//
// Globals:
// - N is the number of vertices in the graph
// - E[x] is the list of nodes adjacent to node x
// - articulation[x] will be true if node x is an articulation point
//
// Time complexity: O(N + E)
//
// Constants to configure:
// - MAX is the maximum number of nodes in the graph

int tick = 1;
int discovery[MAX];
bool articulation[MAX];

int dfs(int x, int dad) {
  discovery[x] = ++tick;
  int low = discovery[x];

  articulation[x] = false;
  int children = 0;

  for (int y : E[x]) {
    if (y == dad) continue;

    if (discovery[y] < 0) {
      ++children;
      int w = dfs(y, x);

      if (w >= discovery[x]) articulation[x] = true;
      low = min(low, w);
    } else {
      low = min(low, discovery[y]);
    }
  }
  if (dad == -1) articulation[x] = children > 1;

  return low;
}

void init() {
  REP(i, N) discovery[i] = -1;
  REP(i, N) if (discovery[i] == -1) dfs(i, -1);
}
