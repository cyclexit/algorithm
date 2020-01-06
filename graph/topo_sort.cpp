// This class is used for unweighted graph
// This class can be used for both directed and undirected graph
class Graph {
 public:
  int n;
  vector<vector<int>> edge;
  // constructor
  Graph(int _n) : n(_n) {
    edge.resize(n);
  }
  // add an edge
  void add(int u, int v) {
    edge[u].push_back(v);
  }
  /*
   * Topological sort can only be used for DAG(Directed Acyclic Graph)!
   * Return true if the topological order exists, false otherwise.
   */
  vector<int> topo;
  bool topo_sort() {
    topo.clear();
    vector<int> in_deg(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int x : edge[i]) {
        ++in_deg[x];
      }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in_deg[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      ++cnt;
      topo.push_back(cur);
      for (int x : edge[cur]) {
        --in_deg[x];
        if (in_deg[x] == 0) {
          q.push(x);
        }
      }
    }
    if (cnt < n) {
      // The graph is not a DAG
      return false;
    } else {
      return true;
    }
  }
};