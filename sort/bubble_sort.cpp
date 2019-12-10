/* 
 * author: cyclexit
 * start from: 2019-12-09 21:51:06
 */
#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int>& v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    for (int j = 0; j < v.size() - 1 - i; ++j) {
      if (v[j] > v[j + 1]) {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
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
  bubble_sort(v);
  for (int i = 0; i < N; ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';
  return 0;
}