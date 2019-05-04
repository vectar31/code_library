// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
// Very short code -- > Advantage
#include <bits/stdc++.h>

using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

/*
Input: a list P of points in the plane.

Sort the points of P by x-coordinate (in case of a tie, sort by y-coordinate).

Initialize U and L as empty lists.
The lists will hold the vertices of upper and lower hulls respectively.

for i = 1, 2, ..., n:
    while L contains at least two points and the sequence of last two points
            of L and the point P[i] does not make a counter-clockwise turn:
        remove the last point from L
    append P[i] to L

for i = n, n-1, ..., 1:
    while U contains at least two points and the sequence of last two points
            of U and the point P[i] does not make a counter-clockwise turn:
        remove the last point from U
    append P[i] to U

Remove the last point of each list (it's the same as the first point of the other list).
Concatenate L and U to obtain the convex hull of P.
Points in the result will be listed in counter-clockwise order.

*/
