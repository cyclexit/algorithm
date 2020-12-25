/*
 * author: cyclexit
 * start from: 2020-10-12 14:57
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, mx;
  cin >> n >> mx;
  // value; weight
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i].second;
  }
  vector<vector<int>> dp(n, vector<int>(mx + 1, 0));
  if (v[0].second <= mx) {
    dp[0][v[0].second] = v[0].first;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= mx; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j - v[i].second >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].second] + v[i].first);
    }
  }
  // debug(dp);
  int ans = 0;
  for (int i = 0; i <= mx; ++i) {
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << '\n';
  return 0;
}