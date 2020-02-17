class WeightedGraph {
 public:
  int n;
  // first: adjacent node
  // second: weight
  vector<vector<pair<int, long long>>> edge;
  // constructor
  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }
  // add a weighted edge
  void add(int u, int v, long long w) {
    edge[u].emplace_back(make_pair(v, w));
  }
  /*
   * MST-Kruskal:
   * This is the implementation shown in Introduction To Algorithm(3rd)
   * This implementation is more efficient in C++.
   * The complexity of this implementation is O(Elog(E)) after neglecting
   * the cost of dsu operations.
   */
  struct Edge {
    int u, v;
    long long w;
    // constructor
    Edge(int _u, int _v, long long _w) : u(_u), v(_v), w(_w) {}
    // operator
    inline bool operator<(const Edge& e) const {
      return w < e.w;
    }
  };
  long long total = 0;
  vector<Edge> mst;
  void kruskal() {
    vector<Edge> ev;
    for (int i = 0; i < n; ++i) {
      for (auto x : edge[i]) {
        ev.emplace_back(Edge(i, x.first, x.second));
      }
    }
    sort(ev.begin(), ev.end());
    Dsu dsu = Dsu(n); // need to use Dsu class in data_struct/dsu.cpp
    for (int i = 0; i < ev.size(); ++i) {
      if (dsu.unite(ev[i].u, ev[i].v)) {
        total += ev[i].w;
        mst.emplace_back(ev[i]);
      }
    }
  }
};