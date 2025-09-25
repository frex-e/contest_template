#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

typedef complex<long long> point;
#define x real()
#define y imag()
inline ll dot(point a, point b) { return (conj(a)*b).x; } // (a.x*b.x + a.y*b.y)
inline ll cross(point a, point b) { return (conj(a) * b).y; } // (a.x*b.y - a.y*b.x)
inline ll dist2(point a, point b) { return dot(a - b, a-b); } // squared distance
inline ll orient(point a, point b, point c) { return cross(b - a, c - a); } // Positive = CCW

bool grid[200][200] = {};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k; cin >> n >> k;
	int spaces = n*n - k;

	if (spaces <= 2*(n - 1) and spaces >= n and n >= 2) {
		grid[0][1] = true;
		grid[1][0] = true;
		int extra = spaces - n;

		rep(i,2,n) {
			if (extra > 0) {
				grid[i][0] = true;
				grid[0][i] = true;
				extra--;
			} else {
				grid[i][i] = true;
			}
		}

		cout << "POSSIBLE\n";
		rep(i,0,n) {
			rep(j,0,n) cout << ((grid[i][j]) ? '.' : '#');
			cout << '\n';
		}
	} else if (n == 1 and k == 0) {
		cout << "POSSIBLE\n.";
	} else  {
		cout << "IMPOSSIBLE";
	}
}