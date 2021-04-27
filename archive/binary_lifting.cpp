// Problem:
// Given a ring with the length n and a constant k, the rabbit will jump from
// i-th point to ((i + k) mod n + 1)-th point. The rabbit jumps m times in
// total. There n points in the ring, and each point has a weight ai. Please
// calculate the sum of the weights of the points during m jumps mod 10^9 + 7.
// 
// Input:
// n k m (1 <= n <= 10^6, 1 <= k <= n, 1 <= m <= 10^18)
// a1, a2, ..., an (0 <= ai <= 10^9)

/*
 * author: cyclexit
 * start from: 2021-04-26 16:58
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const ll kMOD = 1e9 + 7;
  ll n, k, m;
  cin >> n >> k >> m;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ll logm = sizeof(ll) * 8 - __builtin_clz(m);
  vector<vector<ll>> nxt(logm + 2, vector<ll>(n, 0));
  vector<vector<ll>> sum(logm + 2, vector<ll>(n, 0));
  for (int i = 1; i <= n; ++i) {
    nxt[0][i] = (i + k) % n + 1;
    sum[0][i] = a[i];
  }
  for (int i = 1; i <= logm; ++i) {
    for (int j = 1; j <= n; ++j) {
      nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
      sum[i][j] = (sum[i - 1][j] + sum[i - 1][nxt[i - 1][j]]) % kMOD;
    }
  }
  ll ans = 0, cur = 1;
  for (int i = 0; m > 0; ++i) {
    if (m & (1 << i)) {
      ans = ans + sum[i][cur];
      cur = nxt[i][cur];
      m ^= (1ll << i);
    }
  }
  cout << ans << '\n';
  return 0;
}