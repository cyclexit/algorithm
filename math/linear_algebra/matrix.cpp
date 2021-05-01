template<typename T>
struct Matrix {
  int n;
  vector<vector<T>> m;

  Matrix<T>() = default;
  Matrix<T>(int _n, T val = 0) : n(_n) {
    m.assign(n, vector<T>(n, val));
  }

  vector<T>& operator[](size_t i) {
    return m[i];
  }

  Matrix<T> operator*(Matrix<T> other) {
    Matrix<T> res(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          res[i][j] += m[i][k] * other[k][j];
        }
      }
    }
    return res;
  }

  void set_diagnal(T val) {
    for (int i = 0; i < n; ++i) {
      m[i][i] = val;
    }
  }
};

template<typename T>
Matrix<T> fast_pow(Matrix<T> matrix, int pow) {
  Matrix<T> res(matrix.n);
  res.set_diagnal(1);
  while (pow) {
    if (pow % 2) res = res * matrix;
    matrix = matrix * matrix;
    pow >>= 1;
  }
  return res;
}

template<typename T>
T fast_fib(int n) {
  Matrix<T> base(2);
  base[0][1] = base[1][0] = base[1][1] = 1;
  Matrix<T> ans(2);
  ans[0][1] = 1;
  ans = ans * fast_pow(base, n);
  return ans[0][0];
}