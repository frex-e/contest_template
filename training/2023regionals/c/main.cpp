#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)


typedef complex<double> point;
#define x real()
#define y imag()
inline double dot(point a, point b) { return (conj(a)*b).x; } // (a.x*b.x + a.y*b.y)
inline double cross(point a, point b) { return (conj(a) * b).y; } // (a.x*b.y - a.y*b.x)
inline double dist(point a, point b) { return sqrt(dot(a - b, a-b)) ; } // squared distance
inline double orient(point a, point b, point c) { return cross(b - a, c - a); } // Positive = CCW

double ans[200][200] = {};

bool intersect(point a, point b, point c, point d) {

	return orient(a,b,c) * orient(a,b,d) <= 0 and orient(d,c,a) * orient(d,c,b) < 0;
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	// memset(ans, 1./0., sizeof(ans));

	cout << fixed << setprecision(10);

	int n; cin >> n;
	vector<point> points;

	rep(i,0,n) {
		double a,b; cin >> a >> b;
		ans[i][i] = 0.;
		points.push_back({a,b});
	}

	rep(i,0,n) rep(j,0,n) ans[i][j] = dist(points[i],points[j]);

	rep(i,0,n) {
		point cur = points[i];
		point prv = points[(i - 1 + n) % n];
		point nxt = points[(i + 1) % n];

		rep(j,0,n) {
			point other = points[j];
			if (other == cur || other == prv || other == nxt) continue;
			if (!(
				orient(other,cur,nxt) >= 0 and orient(prv,cur,nxt) <= 0 or
				orient(other,cur,nxt) * orient(prv,cur,nxt) >= 0 and orient(prv,cur,other) >= 0
			)) {
				ans[i][j] = 1./0.;
				ans[j][i] = 1./0.;
			}
		}
	}

	rep(i,0,n) rep(j,i + 1,n) {
		auto a = points[i], b = points[j];
		rep(k,0,n) {
			auto c = points[k], d = points[(k + 1) % n];
			if (c == a || c == b || d == a || d == b) continue;
			if (intersect(a,b,c,d)) {
				ans[i][j] = 1./0.;
				ans[j][i] = 1./0.;
			}
		}
	}
	
	// rep(i,0,n) {
	// 	rep(j,0,n) {
	// 		cout << ans[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	// cout << endl;

	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);

	rep(i,0,n) {
		rep(j,0,n) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}