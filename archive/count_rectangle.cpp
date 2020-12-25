/*
 * author: cyclexit
 * start from: 2020-10-07 12:59
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> point(n);
  for (int i = 0; i < n; ++i) {
    cin >> point[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> point[i].second;
  }
  map<pair<int, int>, int> y_map;
  int ans = 0;
  for (auto p : point) {
    for (auto p_above : point) {
      if (p.first == p_above.first && p.second < p_above.second) {
        auto y_pair = make_pair(p.second, p_above.second);
        ans += y_map[y_pair];
        ++y_map[y_pair];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}