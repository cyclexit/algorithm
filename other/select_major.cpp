/*
 * author: cyclexit
 * start from: 2020-10-22 10:51
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int cnt = 1, cand = v[0];
  for (int i = 1; i < n; ++i) {
    if (cnt == 0) {
      cand = v[i];
      cnt = 1;
    } else if (cnt && cand == v[i]) {
      ++cnt;
    } else if (cnt && cand != v[i]) {
      --cnt;
    }
  }
  cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (cand == v[i]) {
      ++cnt;
    }
  }
  if (cnt > n / 2) {
    cout << cand << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}