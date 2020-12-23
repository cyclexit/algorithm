#include <bits/stdc++.h>

using namespace std;

template<typename T>
class FenwickTree {
  int n;
  vector<T> sum;
  inline int low_bit(int x) {
    return x & -x;
  };
 public:
  FenwickTree() = default;
  FenwickTree(int _n) : n(_n) {
    sum.resize(n);
  }

  void add(int index, T v) {
    ++index;
    while (index < n) {
      sum[index] += v;
      index += low_bit(index);
    }
  }

  T get(int index) {
    ++index;
    T res{};
    while (index > 0) {
      res += sum[index];
      index -= low_bit(index);
    }
    return res;
  }

  T get(int l, int r) {
    return get(r) - get(l - 1);
  }
};