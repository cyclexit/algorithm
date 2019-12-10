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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  selection_sort(v);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';
  return 0;
}