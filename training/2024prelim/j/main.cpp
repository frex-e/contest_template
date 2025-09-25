#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

typedef complex<long long> point;
#define x real()
#define y imag()


inline ll dot(point a, point b) { return (conj(a) * b).x; }        // (a.x*b.x + a.y*b.y)
inline ll cross(point a, point b) { return (conj(a) * b).y; }      // (a.x*b.y - a.y*b.x)
inline ll dist2(point a, point b) { return dot(a - b, a-b); }          // squared distance
inline ll orient(point a, point b, point c) {
    return cross(b - a, c - a); // Positive = CCW 
}

vector<point> hull(const vector<point>& points) {
	vector<point> res;
	rep(i,0,points.size()) {
		while (res.size() >= 2 and orient(res[res.size() - 2], res.back(), points[i]) <= 0)
			res.pop_back();

		res.push_back(points[i]);
	}

	return res;
};

ll polygon(const vector<point>& points) {
	int n = points.size();
	ll ans = 0;
	rep(i,0,n) {
		point a = points[i];
		point b = points[(i + 1) % n];
		ans += (b.x - a.x) * (a.y + b.y);
	}
	return abs(ans);
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	vector<point> points(n);
	rep(i,0,n) {
		ll a,b; cin >> a >> b;
		points[i] = point(a,b);
	}


	sort(points.begin(),points.end(), [](const point& a, const point& b){ return make_pair(a.x,a.y) < make_pair(b.x,b.y); });
	auto upper = hull(points);
	reverse(points.begin(), points.end());
	auto lower = hull(points);

	// for(auto p : upper) {
	// 	cout << "(" << p.x << "," << p.y << ") ";
	// }
	// cout << endl;
	// for(auto p : lower) {
	// 	cout << "(" << p.x << "," << p.y << ") ";
	// }
	// cout << endl;


	upper.pop_back();
	lower.pop_back();


	auto final_hull = upper;
	for(auto p : lower) final_hull.push_back(p);

	// for(auto p : final_hull) {
	// 	cout << "(" << p.x << "," << p.y << ") ";
	// }
	// cout << endl;

	// cout << final_hull.size() << endl;


	if (final_hull.size() <= 4) {
		cout << 0;
		return 0;
	}

	n = final_hull.size();

	ll starting_size = polygon(final_hull);
	ll ans = starting_size;
	int opposite = 2;

	// cout << starting_size << endl;

	rep(i,0,n) {
		point cur = final_hull[i], curl = final_hull[(i - 1 + n)%n], curr = final_hull[(i + 1) % n];

		while(polygon({curl,curr,final_hull[opposite]}) <= polygon({curl,curr,final_hull[(opposite + 1) % n]})) {
			opposite = (opposite + 1) % n;
		}

		ans = min(ans, starting_size - polygon({curl,curr,cur}) - polygon({curl, curr, final_hull[opposite]}));
	}
	cout << ans;
}