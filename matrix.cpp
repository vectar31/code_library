// Matrix multiplication and exponentiation
//
// An implementation of fast matrix multiplication and exponentiation.
// Modular arithmetic is used.
//
// Time complexities:
// - operator *: O(N^3)
// - operator %: O(N^3 * log b)
//
// Constants to configure:
// - mod is the modulus
// - DIM is the dimension of matrices

const int mod = int(1e9) + 7;
const int DIM = 52;

struct Matrix {
  int a[DIM][DIM];
  int *operator [] (int r) { return a[r]; };

  Matrix(int x = 0) {
    memset(a, 0, sizeof a);
    if (x) REP(i, DIM) a[i][i] = x;
  }
} const I(1);

Matrix operator * (Matrix A, Matrix B) {
  const llint mod2 = llint(mod) * mod;
  Matrix C;
  REP(i, DIM) REP(j, DIM) {
    llint w = 0;
    REP(k, DIM) {
      w += llint(A[i][k]) * B[k][j];
      if (w >= mod2) w -= mod2;
    }
    C[i][j] = w % mod;
  }
  return C;
}

Matrix operator ^ (Matrix A, llint b) {
  Matrix R = I;
  for (; b > 0; b /= 2) {
    if (b % 2) R = R*A;
    A = A*A;
  }
  return R;
}
