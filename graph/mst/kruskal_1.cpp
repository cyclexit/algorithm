/*
 * MST-Kruskal:
 * This is the implementation shown in Introduction To Algorithm(3rd)
 * This implementation is more efficient in C++.
 * The complexity of this implementation is O(Elog(E)) after neglecting
 * the cost of dsu operations.
 */
class Dsu {
 public:
  int n;
  vector<int> p;

  Dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    return (x == p[x]) ? x : (p[x] = find(p[x]));
  }
  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

class WeightedGraph {
 public:
  int n;
  // first: adjacent node
  // second: weight
  vector<vector<pair<int, long long>>> edge;
  
  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }

  void add(int u, int v, long long w) {
    edge[u].emplace_back(make_pair(v, w));
  }
  
  struct Edge {
    int u, v;
    long long w;

    Edge(int _u, int _v, long long _w) : u(_u), v(_v), w(_w) {}

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
    Dsu dsu = Dsu(n); 
    for (int i = 0; i < ev.size(); ++i) {
      if (dsu.unite(ev[i].u, ev[i].v)) {
        total += ev[i].w;
        mst.emplace_back(ev[i]);
      }
    }
  }
};