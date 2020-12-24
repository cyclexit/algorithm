#include <bits/stdc++.h>

using namespace std;

template<typename T>
class FenwickTreeR {
  int n;
  vector<T> sdiff, sdiffi;

  inline int low_bit(int x) {
    return x & -x;
  }

  T get(vector<T>& vec, int index) {
    ++index;
    T res{};
    while (index > 0) {
      res += vec[index];
      index -= low_bit(index);
    }
    return res;
  }
 public:
  FenwickTreeR() = default;
  FenwickTreeR(int _n) : n(_n) {
    sdiff.resize(n);
    sdiffi.resize(n);
  }

  // v should be value of the diff array of the input!
  void add(int index, T v) {
    T vi = index * v;
    ++index;
    while (index < n) {
      sdiff[index] += v;
      sdiffi[index] += vi;
      index += low_bit(index);
    }
  }

  void add(int l, int r, T v) {
    add(l, v);
    add(r + 1, -v);
  }

  T get(int l, int r) {
    T p1 = (r + 1) * get(sdiff, r) - l * get(sdiff, l - 1);
    T p2 = get(sdiffi, r) - get(sdiffi, l - 1);
    return p1 - p2;
  }
};