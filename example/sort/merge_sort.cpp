#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, int l, int mid, int r) {
  vector<int> temp(r - l + 1);
  int index = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    temp[index++] = (v[i] <= v[j]) ? v[i++] : v[j++];
  }
  while (i <= mid) {
    temp[index++] = v[i++];
  }
  while (j <= r) {
    temp[index++] = v[j++];
  }
  for (int k = 0; k < temp.size(); ++k) {
    v[l++] = temp[k];
  }
}

void merge_sort(vector<int>& v, int l, int r) {
  if (l >= r) {
    return;
  }
  int mid = (l + r) / 2;
  merge_sort(v, l, mid);
  merge_sort(v, mid + 1, r);
  merge(v, l, mid, r);
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
  merge_sort(v, 0, v.size() - 1);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << '\n';
  }
  return 0;
}