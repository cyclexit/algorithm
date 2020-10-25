/*
 * author: cyclexit
 * start from: 2020-10-25 14:10
 */
#include <bits/stdc++.h>

using namespace std;

class MatrixMult {
 public:
  typedef long long ll;
  
  int n;
  vector<pair<ll, ll>> matrix;

  MatrixMult(int _n) : n(_n) {
    matrix.resize(n);
  }

  vector<vector<ll>> dp;
  vector<vector<int>> pos;
  int solve() {
    dp.resize(n, vector<ll>(n, 0));
    pos.resize(n, vector<int>(n, 0));
    for (int gap = 1; gap < n; ++gap) {
      for (int i = 0; i < n; ++i) {
        int end = i + gap;
        if (end >= n) break;
        dp[i][end] = -1;
        for (int j = i; j < end; ++j) {
          int cost = dp[i][j] + dp[j + 1][end] + matrix[i].first * matrix[j].second * matrix[end].second;
          if (dp[i][end] == -1 || dp[i][end] > cost) {
            dp[i][end] = cost;
            pos[i][end] = j;
          }
        }
      }
    }
    return dp[0][n - 1];
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
  for (int i = 0; i < n; ++i) {
    cin >> solver.matrix[i].first >> solver.matrix[i].second;
  }
  cout << solver.solve() << '\n';
  cout << solver.expression(0, n - 1) << '\n';
  return 0;
}