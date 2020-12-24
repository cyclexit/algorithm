// Learn from https://github.com/the-tourist/algo/blob/master/data/sparsetable.cpp

#include <bits/stdc++.h>

using namespace std;

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   SparseTable<int, decltype(fun)> st(a, fun);
// or:
//   SparseTable<int> st(a, [&](int i, int j) { return min(i, j); });
template <typename T, typename F = function<T(const T&, const T&)>>
class SparseTable {
  int n;
  vector<vector<T>> table;
  F func;
  inline int bit_len(int num) {
    return sizeof(int) * 8 - __builtin_clz(num);
  }
 public:
  SparseTable(const vector<T>& vec, const F& f) : func(f) {
    n = static_cast<int>(vec.size());
    int max_bit = bit_len(n);
    table.resize(max_bit);
    table[0] = vec;
    for (int j = 1; j < max_bit; ++j) {
      table[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); ++i) {
        table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int l, int r) {
    int lg = bit_len(r - l + 1) - 1;
    return func(table[lg][l], table[lg][r - (1 << lg) + 1]);
  }
};