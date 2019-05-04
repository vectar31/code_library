// This is fast multiplication using fast fourier transform , you can use karatsuba as well
#include <bits/stdc++.h>
using namespace std;
#define group     5
#define radix   100000
typedef complex<long double> Complex;
long double pival = 2 * acos(0.0L);
unsigned revtab[65536];
void init() {
    for (int x = 0; x < 65536; x++)
    {
        int y = 0;
        for (int i = 0; i < 16; i++)
            y |= ((x >> i) & 1) << (15 - i);
        revtab[x] = y;
    }
}
void FFT(Complex *a, int N, int dir)
{
    int lgN;
    for (lgN = 1; (1 << lgN) < N; lgN++);
    assert((1 << lgN) == N);
    for (unsigned i = 0; i < N; i++)
    {
        unsigned j = ((revtab[i & 65535] << 16) | revtab[i >> 16]) >> (32 - lgN);
        if (i < j) swap(a[i], a[j]);
    }
    for (int s = 1; s <= lgN; s++)
    {
        int m = 1 << s, h = m/2;
        Complex w, w_m = exp(Complex(0, dir*2*pival/m));
        for (int k = 0; k < N; k += m) {
            w = 1;
            for (int j = 0; j < h; j++) {
                Complex t = w * a[k+h+j];
                a[k+h+j] = a[k+j] - t;
                a[k+j] += t;
                w *= w_m;
            }
        }
    }
}
void parse(vector<Complex> &v, const char *s)
{
    int n = strlen(s);
    int m = (n + group-1) / group;
    v.resize(m);
    for (int i = 0; i < m; i++) {
        int b = n - group * i, x = 0;
        for (int a = max(0, b - group); a < b; a++)
            x = x * 10 + s[a] - '0';
        v[i] = x;
    }
}

void print(const vector<Complex> &v)
{
    int i, N = v.size();
    vector<long long> digits(N + 1, 0);
    long double err = 0;

    for (i = 0; i < N; i++) {
        long long x = (long long)(v[i].real() + 0.5);
        err = max(err, abs(x - v[i].real()));
        err = max(err, abs(v[i].imag()));
        digits[i] = x;
    }
    long long c = 0;
    for (i = 0; i < N; i++) {
        c += digits[i];
        digits[i] = c % radix;
        c /= radix;
    }
    assert(c == 0);
    for (i = N-1; i > 0 && digits[i] == 0; i--);
    printf("%lld", digits[i]);
    for (i--; i >= 0; i--)
        printf("%.*lld", group, digits[i]);
    printf("\n");
}

int main()
{
    static char a_str[310000], b_str[310000];
    int t;
    init();
    scanf("%d", &t);
    while (t--) {
        assert(scanf(" %s %s", a_str, b_str) == 2);
        vector<Complex> A, B;
        parse(A, a_str);
        parse(B, b_str);

        int N = 1;
        while (N < max(A.size(), B.size())) N *= 2;
        N *= 2;
        A.resize(N);
        B.resize(N);
        clock_t t1 = clock(), t2;

        FFT(&A[0], N, +1);
        FFT(&B[0], N, +1);
        for (int i = 0; i < N; i++) A[i] *= B[i];
        FFT(&A[0], N, -1);
        for (int i = 0; i < N; i++) A[i] /= N;

        t2 = clock();
        print(A);
    }
}
