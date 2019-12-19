// This class is used for unweighted graph
// This class can be used for both directed and undirected graph
class WeightedGraph {
 public:
  int n; // number of nodes
  // first element of the pair: the connected node
  // second element of the pair: the weight of the edge
  vector<vector<pair<int, int>>> edge; // weighted edges
  // constructor
  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }
  // function
  void add(int u, int v, int w) {
    edge[u].emplace_back(make_pair(v, w));
  }
};