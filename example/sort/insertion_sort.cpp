/* 
 * author: cyclexit
 * start from: 2019-12-09 22:09:21
 */
#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>& v) {
  for (int i = 1; i < v.size(); ++i) {
    int cur = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] > cur) {
      v[j + 1] = v[j];
      --j;
    }
    v[j + 1] = cur;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const int N = 5;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }
  insertion_sort(v);
  for (int i = 0; i < N; ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';
  return 0;
}