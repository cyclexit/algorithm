typedef vector<complex<double>> vc;

// inv_w is used in IDFT
vc w, inv_w;
void init_w(int n) {
  w.assign(n, 0);
  inv_w.assign(n, 0);
  double pi = acos(-1);
  for (int i = 0; i != n; ++i) {
    w[i] = complex<double>(cos(2.0*pi*i/n), sin(2.0*pi*i/n));
    inv_w[i] = conj(w[i]);
  }
}

// buffer: receive the numbers which need to transform
void fft(int n, vc& buffer) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) swap(buffer[i], buffer[j]);
    for (int l = n >> 1; (j ^= l) < l; l >>= 1);
  }
  for (int i = 2; i <= n; i <<= 1) {
    int m = i >> 1;
    for (int j = 0; j < n; j += i) {
      for (int k = 0; k < m; ++k) {
        complex<double> z = buffer[j+m+k] * w[n/i*k];
        buffer[j+m+k] = buffer[j+k] - z;
        buffer[j+k] += z;
      }
    }
  }
}