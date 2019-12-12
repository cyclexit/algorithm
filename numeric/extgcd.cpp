// Solve the Diophantine equation a * x + b * y = c
// a, b and c are given, and x and y are unknowns
// The equation is solvable if c = gcd(a, b)
void extgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
  } else {
    extgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}