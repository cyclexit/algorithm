// Learn from https://github.com/the-tourist/algo/blob/master/data/dsu.cpp

#include <bits/stdc++.h>

using namespace std;

class Dsu {
 public:
  int n;
  vector<int> p;

  Dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    return (x == p[x]) ? x : (p[x] = find(p[x]));
  }
  
  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};