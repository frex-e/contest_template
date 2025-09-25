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

ll top_hull(point start, point end, vector<point>&rest) {
	rest.push_back(start);
	rest.push_back(end);

	sort(rest.begin(), rest.end(), [&](const point &a, const point &b){
		if (a.x != b.x)
			return a.x < b.x;
		else return  ((a.y < b.y) == (a.x != end.x));
	});

	// for(auto p : rest) {
		// cout << "(" << p.x << "," << p.y << ")" << " ";
	// }

	ll ans = (start.y + end.y) * (end.x - start.x);

	ll n = rest.size();

	vector<deque<pair<point, ll>>> to_this(n);

	rep(i,0,n) {
		auto cur = rest[i];

		if (cur.x == start.x) to_this[i].push_back({point(cur.x, cur.y - 1),0});

		if (cur.x == end.x) {
			for(auto [_,a] : to_this[i]) {
				// cout << a << " " ;
				assert(a >= (start.y + end.y) * (end.x - start.x));
				ans = max(ans, a);
			}
			continue;
		}

		ll best_prev = LLONG_MIN;
		auto least_steep_next = point(cur.x, cur.y + 1);

		rep(j,i + 1,n) {
			auto nxt = rest[j];
			// Not needed?
			if (nxt.x == cur.x) continue;
			if (orient(cur,least_steep_next,nxt) > 0) continue;
			least_steep_next = nxt;

			while(!to_this[i].empty() && orient(to_this[i][0].first,cur,nxt) <= 0) {
				// cout << "A" << endl;
				best_prev = max(best_prev, to_this[i][0].second);
				to_this[i].pop_front();
			}

			if (best_prev == LLONG_MIN) continue;

			ll cur_ans = best_prev + (cur.y + nxt.y)*(nxt.x - cur.x);

			to_this[j].push_back({cur,cur_ans});
		}
	}

	ans -= (start.y + end.y) * (end.x - start.x);
	assert(ans >= 0);
	// cout << ans << endl;
	return ans;
};


ll neg = -1e6 + 5;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	vector<point> points;
	rep(i,0,n) {
		long long a,b; cin >> a >> b;
		points.push_back(point(a,b + 1e7));
	}

	sort(points.begin(), points.end(), [](const point &a, const point &b){return a.x < b.x;});

	ll ans = 0;

	rep(i,0,n) rep(j,i + 1, n) {
		if (points[i].x == points[j].x) continue;

		// sort into above below.
		// determine if there is equal
		vector<point> above;
		vector<point> below;

		bool equal = false;

		rep(k,0,n) {
			if (k == i || k == j) continue;
			auto a = points[i], c = points[j], b = points[k];

			if (b.x < a.x || b.x > c.x) continue;
			if (orient(a,b,c) < 0) above.push_back(b);
			else if (orient(a,b,c) > 0) below.push_back(conj(b));
			else equal = true;
		}

		ll top = top_hull(points[i], points[j], above);
		ll bot = top_hull(conj(points[i]), conj(points[j]), below);
		if (equal) {
			 ans = max({ans,top,bot});
		}
		else{
			ll prev=ans; ans = max(ans, top + bot);
		} 
	}
	cout << ans;
}