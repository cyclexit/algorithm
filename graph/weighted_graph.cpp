// This class is used for unweighted graph
// This class can be used for both directed and undirected graph
class WeightedGraph {
 private:
  // only used in the kruskal algorithm
  struct Edge {
    int u, v, w;
    // constructor
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    // operator
    inline bool operator<(const Edge& e) const {
      return w > e.w;
    }
  };

 public:
  int n;
  vector<vector<pair<int, int>>> edge;
  // constructor
  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }
  // add a weighted edge
  void add(int u, int v, int w) {
    edge[u].emplace_back(make_pair(v, w));
  }
  // MST
  int total = 0;
  vector<pair<int, int>> mst;
  void kruskal() {
    priority_queue<Edge> pq;
    for (int i = 0; i < n; ++i) {
      for (auto x : edge[i]) {
        pq.emplace(Edge(i, x.first, x.second));
      }
    }
    // need to the Dsu class in data_struct/dsu.cpp
    Dsu dsu = Dsu(n);
    while (!pq.empty()) {
      Edge e = pq.top();
      pq.pop();
      if (dsu.unite(e.u, e.v)) {
        total += e.w;
        mst.emplace_back(make_pair(e.u, e.v));
      }
    }
  }
};