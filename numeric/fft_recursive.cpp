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

// buffer: store the numbers which need to transform
void fft(int n, vc& buffer, int idx, int step) {
  if (n == 1) return;
  int m = n >> 1;
  fft(m, buffer, idx, step<<1);
  fft(m, buffer, idx+step, step<<1);
  vc temp(n);
  for (int i = 0; i < m; ++i) {
    int pos = 2 * step * i;
    temp[i] = buffer[pos+idx] + w[i*step] * buffer[pos+idx+step];
    temp[i+m] = buffer[pos+idx] - w[i*step] * buffer[pos+idx+step];
  }
  for (int i = 0; i < n; ++i) {
    buffer[i*step+idx] = temp[i];
  }
}