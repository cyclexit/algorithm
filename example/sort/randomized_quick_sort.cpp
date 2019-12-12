#include <bits/stdc++.h>

using namespace std;

inline void swap(vector<int>& v, int x, int y) {
  int temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}

int randomized_partition(vector<int>& v, int l, int r) {
  // randomize the pivot element
  int piv_index = rand() % (r - l + 1) + l;
  swap(v, piv_index, r);
  // following code is the same as the non-randomized version
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

void randomized_quick_sort(vector<int>& v, int l, int r) {
  if (l < r) {
    int index = randomized_partition(v, l, r);
    randomized_quick_sort(v, l, index - 1);
    randomized_quick_sort(v, index + 1, r);
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
  // Warning: Calling srand function inside randomized_partition function
  // will make the whole program even slower than the non-randomized version.
  srand((unsigned)time(NULL));
  randomized_quick_sort(v, 0, v.size() - 1);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << '\n';
  }
  return 0;
}