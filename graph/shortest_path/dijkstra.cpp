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
      ll w = pq.top().first;
      int cur = pq.top().second;
      pq.pop();
      if (w > dist[cur]) {
        continue; // reduce useless calculation
      }
      for (auto x : edge[cur]) {
        int nxt = x.first;
        ll ww = x.second;
        if (dist[nxt] == -1) {
          dist[nxt] = dist[cur] + ww;
          pq.emplace(dist[nxt], nxt);
        } else if (dist[nxt] > dist[cur] + ww) {
          dist[nxt] = dist[cur] + ww;
          pq.emplace(dist[nxt], nxt);
        }
      }
    }
  }
};