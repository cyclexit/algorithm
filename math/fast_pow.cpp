#include <bits/stdc++.h>

using namespace std;

template<typename T>
T fast_pow(T base, T pow) {
  T res = 1;
  while (pow) {
    if (pow & 1) res = res * base;
    base = base * base;
    pow >>= 1;
  }
  return res;
}

template<typename T>
T fast_pow(T base, T pow, T mod) {
  T res = 1;
  while (pow) {
    if (pow & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    pow >>= 1;
  }
  return res;
}