#include <bits/stdc++.h>

using namespace std;

// Return n-th and (n+1)-th fibonacci numbers
// Time Complexity: O(log n)
template<typename T>
pair<T, T> fast_fib(int n) {
  if (n == 0) return {0, 1};
  pair<T, T> res = fast_fib<T>(n >> 1);
  T x = 2 * res.first * res.second - res.first * res.first;
  T y = res.second * res.second + res.first * res.first;
  if (n % 2) {
    return {y, x + y};
  } else {
    return {x, y};
  }
}