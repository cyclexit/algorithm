#include <bits/stdc++.h>

using namespace std;

inline void swap(vector<int>& v, int x, int y) {
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

int partition(vector<int>& v, int l, int r) {
  int piv = v[r];
  int i = l - 1;
  for (int j = l; j < r; ++j) {
    if (v[j] <= piv) {
      swap(v, ++i, j);
    }
  }
  swap(v, ++i, r);
  return i;
}

void quick_sort(vector<int>& v, int l, int r) {
  if (l < r) {
    int index = partition(v, l, r);
    quick_sort(v, l, index - 1);
    quick_sort(v, index + 1, r);
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
  quick_sort(v, 0, v.size() - 1);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << '\n';
  }
  return 0;
}