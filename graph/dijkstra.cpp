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
  // Dijkstra algorithm
  vector<ll> dist;
  void dijkstra(int start) {
    dist.assign(n, -1);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(dist[start], start);
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      for (auto x : edge[cur.second]) {
        if (dist[x.first] == -1) {
          dist[x.first] = dist[cur.second] + x.second;
          pq.emplace(x.second, x.first);
        } else if (dist[x.first] > dist[cur.second] + x.second) {
          dist[x.first] = dist[cur.second] + x.second;
          pq.emplace(x.second, x.first);
        }
      }
    }
  }
};