#include <bits/stdc++.h>

using namespace std;

// Floyd-Warshall Algorithm
// Time Complexity: O(|V|^3)
// Spcace Complexity: O(|V|^3)
class WeightedGraph {
 public:
  typedef long long ll;

  const ll kMAX_WEIGHT = 1e18;

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

  vector<vector<vector<ll>>> dp;
  void floyd_warshall() {
    dp.resize(n + 1, vector<vector<ll>>(n, vector<ll>(n, kMAX_WEIGHT)));
    for (int i = 0; i < n; ++i) {
      dp[0][i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      for (auto p : edge[i]) {
        dp[0][i][p.first] = p.second;
      }
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[k][i][j] = min(dp[k - 1][i][j], dp[k - 1][i][k - 1] + dp[k - 1][k - 1][j]);
        }
      }
    }
    // the final answer is kept in dp[n]
  }
};