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
   * MST-Prim
   * The complexity of the algorithm depends on the implementation of the 
   * priority queue.
   * Binary heap: O(Elog(V) + Vlog(V))
   * Fibonacci heap: O(E + log(V))
   */
  // first: adjacent node
  // second: key(weight)
  vector<pair<int, int>> prim_mst;
  void prim() {
    const int INF = (int) 2e9;
    prim_mst.resize(n);
    for (int i = 0; i < n; ++i) {
      prim_mst[i] = make_pair(-1, INF);
    }
    // first: key(weight)
    // second: node index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // start from node 1
    pq.emplace(make_pair(0, 1));
    prim_mst[1].second = 0;
    vector<bool> vis(n, false);
    while (!pq.empty()) {
      pair<int, int> cur = pq.top();
      pq.pop();
      vis[cur.second] = true;
      for (auto x : edge[cur.second]) {
        if (!vis[x.first]) {
          pq.emplace(make_pair(x.second, x.first));
          if (x.second < prim_mst[x.first].second) {
            prim_mst[x.first].second = x.second;
            prim_mst[x.first].first = cur.second;
          }
        }
      }
    }
  }
  // MST-Kruskal
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
    Dsu dsu = Dsu(n);
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