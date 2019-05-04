// Modular Gaussian elimination
//
// Solves systems of linear modular equations.
//
// To use, build a matrix of coefficients and call run(mat, R, C, mod).
// If there is no solution, -1 will be returned, otherwise the number of free
// variables will be returned.
// If the i-th variable is free, row[i] will be -1, otherwise it's value will
// be ans[i].
//
// Time complexity: O(R * C^2)
//
// Constants to configure:
// - MAXC is the number of columns

namespace Gauss {
  const int MAXC = 1001;

  int row[MAXC];
  llint ans[MAXC];

  llint power(llint a, llint b, llint mod) {
    llint ret = 1;
    for (; b; b /= 2) {
      if (b % 2) ret = ret*a % mod;
      a = a*a % mod;
    }
    return ret;
  }
  llint inv(llint x, llint mod) { return power(x, mod-2, mod); }

  int run(llint mat[][MAXC], int R, int C, llint mod) {
    REP(i, C) row[i] = -1;
    
    int r = 0;
    REP(c, C) {
      int k = r;
      while (k < R && mat[k][c] == 0) ++k;
      if (k == R) continue;

      REP(j, C+1) swap(mat[r][j], mat[k][j]);
      llint div = inv(mat[r][c], mod);

      REP(i, R) if (i != r) {
        llint w = mat[i][c] * (mod - div) % mod;
        REP(j, C+1) mat[i][j] = (mat[i][j] + mat[r][j] * w) % mod;
      }
      row[c] = r++;
    }

    REP(i, C) {
      int r = row[i];
      ans[i] = r == -1 ? 0 : mat[r][C] * inv(mat[r][i], mod) % mod;
    }

    FOR(i, r, R) if (mat[i][C]) return -1;
    return C - r;
  }
}
