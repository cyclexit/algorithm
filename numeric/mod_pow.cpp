int mod_pow(int base, int pow, int p) {
  vector<int> bits; 
  while (pow) {
    bits.push_back(pow & 1);
    pow >>= 1;
  }
  reverse(bits.begin(), bits.end());
  int res;
  for (int i = 0; i < bits.size(); ++i) {
    if (i) {
      res = (res * res) % p;
      if (bits[i]) {
        res = (res * base) % p;
      }
    } else {
      res = base % p;
    }
  }
  return res;
}