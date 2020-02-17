// This class is used for unweighted graph
// This class can be used for both directed and undirected graph
class WeightedGraph {
 public:
  typedef long long ll;
  
  int n;
  // first: adjacent node
  // second: weight
  vector<vector<pair<int, ll>>> edge;
  // constructor
  WeightedGraph(int _n) : n(_n) {
    edge.resize(n);
  }
  // add a weighted edge
  void add(int u, int v, ll w) {
    edge[u].emplace_back(make_pair(v, w));
  }
  /*
   * Bellman-Ford algorithm.
   * Time complexity: O(VE)
   * Return true if the shortest path exists, false otherwise.
   */
  // first: previous node
  // second: accumulated weight of the shortest path from the node 'start'
  vector<pair<int, ll>> sp;
  bool bellman_ford(int start) {
    // initialize
    sp.resize(n);
    for (int i = 0; i < n; ++i) {
      sp[i].first = -1;
      sp[i].second = LLONG_MAX;
    }
    sp[start].second = 0;
    // cout << start << " " << sp[start].second << '\n'; // test
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        for (auto x : edge[j]) {
          // relax
          if (sp[j].second == LLONG_MAX) {
            continue; // detect overflow
          }
          if (sp[x.first].second > sp[j].second + x.second) {
            sp[x.first].second = sp[j].second + x.second;
            sp[x.first].first = j;
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (auto x : edge[i]) {
        // check
        if (sp[x.first].second > sp[i].second + x.second) {
          return false;
        }
      }
    }
    return true;
  }
};