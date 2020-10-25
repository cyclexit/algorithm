/*
 * author: cyclexit
 * start from: 2020-10-25 14:10
 */
#include <bits/stdc++.h>

using namespace std;

// For the i-th marix(1 <= i <= n), the size is (v[i - 1] * v[i])
class MatrixMult {
 public:
  typedef long long ll;
  
  int n;
  vector<ll> v;

  MatrixMult(int _n) : n(_n) {
    v.resize(n + 1);
  }

  vector<vector<ll>> dp;
  vector<vector<int>> pos;
  int solve() {
    dp.resize(n + 1, vector<ll>(n + 1, 0));
    pos.resize(n + 1, vector<int>(n + 1, 0));
    for (int gap = 1; gap < n; ++gap) {
      for (int i = 1; i <= n; ++i) {
        int end = i + gap;
        if (end > n) break;
        dp[i][end] = -1;
        for (int j = i; j < end; ++j) {
          ll cost = dp[i][j] + dp[j + 1][end] + v[i - 1] * v[j] * v[end];
          if (dp[i][end] == -1 || dp[i][end] > cost) {
            dp[i][end] = cost;
            pos[i][end] = j;
          }
        }
      }
    }
    return dp[1][n];
  }

  string expression(int i, int j) {
    if (i == j) {
      return "M" + to_string(i);
    } else {
      return "(" + expression(i, pos[i][j]) + expression(pos[i][j] + 1, j) + ")";
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  MatrixMult solver(n);
  for (int i = 0; i <= n; ++i) {
    cin >> solver.v[i];
  }
  cout << solver.solve() << '\n';
  cout << solver.expression(1, n) << '\n';
  return 0;
}