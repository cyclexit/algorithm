/* 
 * author: cyclexit
 * start from: 2019-12-09 22:20:20
 */
#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>& v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    int index = i;
    for (int j = i + 1; j < v.size(); ++j) {
      if (v[j] < v[index]) {
        index = j;
      }
    }
    int temp = v[i];
    v[i] = v[index];
    v[index] = temp;
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
  selection_sort(v);
  for (int i = 0; i < N; ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';
  return 0;
}