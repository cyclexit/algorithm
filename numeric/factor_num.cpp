// Calculate the number of factors for number n
// This function can also be used to tell the prime number
int factor_num(int n) {
  int res = 0;
  for (int i = 1; i <= n / i; ++i) {
    if (n % i == 0) {
      res += 1 + (n / i != i);
    }
  }
  return res;
}