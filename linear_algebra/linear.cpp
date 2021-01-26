#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Linear {
  T k, b;
  
  Linear() = default;
  Linear(T _k, T _b) : k(_k), b(_b) {}

  Linear<T> operator+(const Linear& other) {
    return Linear(k + other.k, b + other.b);
  }
  Linear<T> operator-(const Linear& other) {
    return Linear(k - other.k, b - other.b);
  }
  Linear<T> operator/(const T& val) {
    return Linear(k / val, b / val);
  }
  T operator()(T x) {
    return k * x + b;
  }
};