// This class is used for unweighted graph
// This class can be used for both directed and undirected graph
class WeightedGraph {
 public:
  int n;
  // first: adjacent node
  // second: weight
  vector<vector<pair<int, int>>> edge;
  // constructor
  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }
  // add a weighted edge
  void add(int u, int v, int w) {
    edge[u].emplace_back(make_pair(v, w));
  }
  /*
   * MST-Kruskal:
   * This is my first implementation of the Kruskal algorithm.
   * 
   * Since the cost of the priority queue cannot be ignored,
   * this implementation is less efficient than the other one.
   * 
   * The complexity of this implementation is still O(Elog(E)),
   * but the constant will be large.
   */
  struct Edge {
    int u, v, w;
    // constructor
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    // operator
    inline bool operator<(const Edge& e) const {
      return w > e.w;
    }
  };
  int total = 0;
  vector<Edge> kruskal_mst;
  void kruskal() {
    priority_queue<Edge> pq;
    for (int i = 0; i < n; ++i) {
      for (auto x : edge[i]) {
        pq.emplace(Edge(i, x.first, x.second));
      }
    }
    Dsu dsu = Dsu(n); // need to use Dsu class in data_struct/dsu.cpp
    while (!pq.empty()) {
      Edge e = pq.top();
      pq.pop();
      if (dsu.unite(e.u, e.v)) {
        total += e.w;
        kruskal_mst.emplace_back(e);
      }
    }
  }
};