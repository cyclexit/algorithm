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
};