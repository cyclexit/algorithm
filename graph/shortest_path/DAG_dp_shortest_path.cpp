// This method only applied to DAG with positive edge weights.
// This method can only calculate the shortest paths from the topological start point.

class WeightedDAG {
 public:
  typedef long long ll;
  
  int n;
  vector<vector<pair<int, ll>>> out_edge;
  vector<vector<pair<int, ll>>> in_edge;
  // constructor
  WeightedDAG(int _n) : n(_n) {
    out_edge.resize(n);
    in_edge.resize(n);
  }
  // add a weighted edge
  void add(int u, int v, ll w) {
    out_edge[u].emplace_back(make_pair(v, w));
    in_edge[v].emplace_back(make_pair(u, w));
  }
  // topo-sort
  vector<int> topo;
  bool topo_sort() {
    topo.clear();
    vector<int> in_deg(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      in_deg[i] = in_edge[i].size();
      if (in_deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      topo.push_back(cur);
      for (pair<int, ll> p : out_edge[cur]) {
        --in_deg[p.first];
        if (in_deg[p.first] == 0) q.push(p.first);
      }
    }
    return topo.size() == n;
  }
  // use dp methodology to compute shorted path from start to end
  vector<ll> dp;
  bool dp_shorted_path() {
    // make sure the graph is a DAG
    if (!topo_sort()) return false;
    dp.resize(n, LLONG_MAX);
    dp[topo[0]] = 0;
    for (int i = 1; i < topo.size(); ++i) {
      int cur = topo[i];
      for (pair<int, ll> p : in_edge[cur]) {
        dp[cur] = min(dp[cur], dp[p.first] + p.second);
      }
    }
    return true;
  }
};

// test data
// 4 5
// 1 4 3
// 3 4 3
// 2 1 2
// 2 3 3
// 2 4 4
// 
// 3 2
// 2 1 3
// 1 3 2
// 
// 3 2
// 1 2 3
// 2 3 2
