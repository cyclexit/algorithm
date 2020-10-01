#include <bits/stdc++.h>

using namespace std;

inline void swap(vector<int>& v, int x, int y) {
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

void heapify(vector<int>& v, int index, int heap_size) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int mx = index;
  if (left < heap_size && v[left] > v[mx]) {
    mx = left;
  }
  if (right < heap_size && v[right] > v[mx]) {
    mx = right;
  }
  if (mx != index) {
    swap(v, index, mx);
    heapify(v, mx, heap_size);
  }
}

void heap_sort(vector<int>& v) {
  int heap_size = v.size();
  // build heap
  for (int i = 0; i < heap_size; ++i) {
    heapify(v, i, heap_size);
  }
  while (heap_size > 1) {
    swap(v, 0, --heap_size);
    heapify(v, 0, heap_size);
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
  heap_sort(v);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << '\n';
  }
  return 0;
}