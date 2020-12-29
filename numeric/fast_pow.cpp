typedef long long ll;

ll fast_pow(ll base, ll pow) {
  ll res = 1;
  while (pow) {
    if (pow & 1) res = res * base;
    base = base * base;
    pow >>= 1;
  }
  return res;
}

ll fast_pow(ll base, ll pow, ll mod) {
  ll res = 1;
  while (pow) {
    if (pow & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    pow >>= 1;
  }
  return res;
}