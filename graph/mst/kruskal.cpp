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
      return w > e.w;
    }
  };
  long long total = 0;
  vector<Edge> mst;
  void kruskal() {
    priority_queue<Edge> pq;
    for (int i = 0; i < n; ++i) {
      for (auto x : edge[i]) {
        pq.emplace(Edge(i, x.first, x.second));
      }
    }
    Dsu dsu = Dsu(n); 
    while (!pq.empty()) {
      Edge e = pq.top();
      pq.pop();
      if (dsu.unite(e.u, e.v)) {
        total += e.w;
        mst.emplace_back(e);
      }
    }
  }
};