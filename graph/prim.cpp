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
  vector<pair<int, int>> mst;
  void prim() {
    const int INF = (int) 2e9;
    mst.resize(n);
    for (int i = 0; i < n; ++i) {
      mst[i] = make_pair(-1, INF);
    }
    // first: key(weight)
    // second: node index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // start from node 1
    pq.emplace(make_pair(0, 1));
    mst[1].second = 0;
    vector<bool> vis(n, false);
    while (!pq.empty()) {
      pair<int, int> cur = pq.top();
      pq.pop();
      vis[cur.second] = true;
      for (auto x : edge[cur.second]) {
        if (!vis[x.first]) {
          pq.emplace(make_pair(x.second, x.first));
          if (x.second < mst[x.first].second) {
            mst[x.first].second = x.second;
            mst[x.first].first = cur.second;
          }
        }
      }
    }
  }
};