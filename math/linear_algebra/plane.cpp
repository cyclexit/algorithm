#include <bits/stdc++.h>

using namespace std;

// TODO: 1. add rotate for any angles about the origin
//       2. add rotate for any angles about any point
//       3. shift about a direction vector

template<typename T>
struct Point {
  T x, y;
};

template<typename T>
struct Plane {
  array<T, 3> unitx{1, 0, 0};
  array<T, 3> unity{0, 1, 0};
};

template<typename T>
inline Plane<T> rotate90(Plane<T> p) {
  swap(p.unitx, p.unity);
  for (int i = 0; i < 3; ++i) {
    p.unity[i] *= -1;
  }
  return p;
}

template<typename T>
inline Plane<T> rotate270(Plane<T> p) {
  swap(p.unitx, p.unity);
  for (int i = 0; i < 3; ++i) {
    p.unitx[i] *= -1;
  }
  return p;
}

template<typename T>
inline Plane<T> symmetric_x(Plane<T> p, T x) {
  for (int i = 0; i < 3; ++i) {
    p.unitx[i] *= -1;
  }
  p.unitx[2] += 2 * x;
  return p;
}

template<typename T>
inline Plane<T> symmetric_y(Plane<T> p, T y) {
  for (int i = 0; i < 3; ++i) {
    p.unity[i] *= -1;
  }
  p.unity[2] += 2 * y;
  return p;
}