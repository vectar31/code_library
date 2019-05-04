// This contains total area of union of rectangles. Rectangles need not be parallel to the axis
// O(n^2 * logn)
#include <bits/stdc++.h>

#define y0 y63475625
#define y1 y28435
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define re return

#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <ii> vii;

template <class T> T abs(const T & a) {
    return a > 0 ? a : -a;
}

template <class T> int sgn(const T & a) {
    return a > 0 ? 1 : (a < 0 ? -1 : 0);
}

const double PI = 2.0 * acos(1.0);

struct point {
    double x, y;
};

point operator - (point a, point b) {
    a.x -= b.x;
    a.y -= b.y;
    re a;
}

point operator + (point a, point b) {
    a.x += b.x;
    a.y += b.y;
    re a;
}

double operator * (point a, point b) {
    re a.x * b.x + a.y * b.y;
}

double operator ^ (point a, point b) {
    re a.x * b.y - a.y * b.x;
}

point operator * (point a, double b) {
    a.x *= b;
    a.y *= b;
    re a;
}

int n;
point p[500][4];

bool inside(point a, int k) {
    for (int i = 0; i < 4; i++) {
        point A = p[k][i];
        point B = p[k][(i + 1) % 4];
        if (abs((A - a) ^ (B - a)) < 1e-9) {
            re ((A - a) * (B - a) <= 0.0);
        }
        if (((A - a) ^ (B - a)) < 0.0) re false;
    }
    re true;
}

int main()
{
    cin >> n;
    double S = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cin >> p[i][j].x >>  p[i][j].y;
        if (((p[i][1] - p[i][0]) ^ (p[i][3] - p[i][0])) < 0) {
            reverse(p[i], p[i] + 4);
        }
        S += (p[i][1] - p[i][0]) ^ (p[i][3] - p[i][0]);
    }
    double SS = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            point A = p[i][j], B = p[i][(j + 1) % 4];
            vector <pair <double, int> > t;
            t.pb(mp(1.0, -1.0));

            for (int k = 0; k < n; k++) if (k != i) {
                vector <pair <double, int> > q;
                bool onborder = false;
                for (int l = 0; l < 4; l++) {
                    point C = p[k][l], D = p[k][(l + 1) % 4];
                    if (abs((A - B) ^ (C - D)) < 1e-9) {
                        if (abs((C - A) ^ (B - A)) > 1e-9) continue;
                        if ((B - A) * (D - C) < 0) continue;
                        /*(if (i == 0 && B.x == 2 && B.y == 2 && k == 2) {
                            cerr << "sdfjkg\n";
                            cerr << C.x << ' ' << C.y << ' ' << D.x << ' ' << D.y << endl;
                        }*/
                        onborder = true;
                        if (i < k) continue;
                        point v = (B - A);
                        double ta = (A - A) * v;
                        double tb = (B - A) * v;
                        double tc = (C - A) * v;
                        double td = (D - A) * v;
                        double l = max(ta, tc);
                        double r = min(tb, td);
                        if (l >= r) continue;
                        q.clear();
                        q.pb(mp(l / sqr(v), 1));
                        q.pb(mp(r / sqr(v), -1));
                        break;
                    }
                    double t = ((C - A) ^ (D - C)) / ((B - A) ^ (D - C));
                    double s = ((A - C) ^ (B - A)) / ((D - C) ^ (B - A));
                    if (0 < t && t < 1 && 0 < s && s < 1) {
                        point N = D - C;
                        swap(N.x, N.y);
                        N.x = -N.x;
                        q.pb(mp(t, sgn((B - A) * N)));
                    }
                }
                if (q.size() == 1) {
                    if (q[0].se < 0) q.pb(mp(0, 1)); else q.pb(mp(1.0, -1));
                }
                if (q.size() == 0 && !onborder) {
                    if (inside(A, k) && inside(B, k)) {
                        q.pb(mp(0.0, 1.0));
                        q.pb(mp(1.0, -1.0));
                    }
                }
                if (q.size() > 2) {
                    while (1);
                }

                /*if (i == 0 && B.x == 2 && B.y == 2 && k == 2) {
                    cerr << A.x << ' ' << A.y << ' ' << onborder << endl;
                    cerr << q.size() << endl;
                }*/

                while (q.size()) {
                    t.pb(q.back());
                    q.pop_back();
                }

            }
            sort(t.begin(), t.end());
            point last = A;
            int c = 0;
            for (int k = 0; k < (int)t.size(); k++) {
                point cur = A + (B - A) * t[k].fi;
                if (c <= 0) {
                    //cerr << last.x << ' ' << last.y << ' ' << cur.x << ' ' << cur.y << endl;
                    SS += last ^ cur;
                }
                c += t[k].se;
                last = cur;
            }
        }
    }
    SS = abs(SS / 2.0);
    //cout<<S<<endl;
    cout<<SS<<endl;// SS is the total area of union of rectangles;
    return 0;
}
