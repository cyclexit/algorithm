/*
 * MST-Prim
 * The complexity of the algorithm depends on the implementation of the 
 * priority queue.
 * Binary heap: O(Elog(V) + Vlog(V))
 * Fibonacci heap: O(E + log(V))
 */
class WeightedGraph {
 public:
  typedef long long ll;

  int n;
  // first: adjacent node
  // second: weight
  vector<vector<pair<int, ll>>> edge;

  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }

  void add(int u, int v, ll w) {
    edge[u].emplace_back(make_pair(v, w));
  }
  
  // first: adjacent node
  // second: key(weight)
  vector<pair<int, ll>> mst;
  void prim() {
    mst.resize(n);
    for (int i = 0; i < n; ++i) {
      mst[i] = make_pair(-1, LLONG_MAX);
    }
    // first: key(weight)
    // second: node index
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    // start from node 1
    pq.emplace(make_pair(0, 1));
    mst[1].second = 0;
    vector<bool> vis(n, false);
    while (!pq.empty()) {
      pair<int, ll> cur = pq.top();
      pq.pop();
      vis[cur.second] = true;
      for (auto x : edge[cur.second]) {
        if (!vis[x.first]) {
          if (x.second < mst[x.first].second) {
            pq.emplace(make_pair(x.second, x.first));
            mst[x.first].second = x.second;
            mst[x.first].first = cur.second;
          }
        }
      }
    }
  }
};