/*
 N red and M blue points on the plane in such a way that no three points lie on the same line.
 Find number of distinct triangles with vertices in red points which do not contain any blue point inside.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

struct point
{
	int x, y;
}a[512], b[512];

bool operator < (const point &a, const point &b) { return a.x < b.x; }

int n, m, f[512][512];

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i].x >> a[i].y;
	for(int i=0;i<m;i++)cin >> b[i].x >> b[i].y;
	sort (b, b + m);
	b[m].x = -1u/2;
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (pii(a[i].x, i) < pii(a[j].x, j))
            {
                ll A = a[i].y - a[j].y;
                ll B = a[j].x - a[i].x;
                ll C = A * a[i].x + B * a[i].y;
                if (B < 0) A *= -1, B *= -1, C *= -1;
                int t = 0, R = a[j].x;
                point *k = lower_bound(b, b + m, (point){a[i].x, 0});
                for (; k->x < R; ++k)
                    t += A * k->x + B * k->y < C;
                f[i][j] = t;
            }
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (f[i][j] == 0)
                    f[i][j] = -f[j][i];
	int res = 0;
	for(int k=0;k<n;k++)
        for(int j=0;j<k;j++)
            for(int i=0;i<j;i++)
                res += f[i][j] + f[j][k] + f[k][i] == 0;
	cout << res << endl;
	return 0;
}
