// Euclidean algorithm
//
// Given two integers a and b, solves the Diophantine equation:
//   a * x + b * y = gcd(a, b)
//
// The function will compute the x, y, and g.
// Note: computed value g can be negative.
//
// Given one solution (x_0, y_0), other solutions can be represented as:
//   x_k = x_0 + k * b / g
//   y_k = y_0 - k * a / g
//
// Time complexity: O(log min(a, b))

void euclid(llint a, llint b, llint &x, llint &y, llint &g) {
  if (b == 0) {
    x = 1; y = 0; g = a;
  } else {
    euclid(b, a % b, y, x, g);
    y -= x * (a/b);
  }
}
