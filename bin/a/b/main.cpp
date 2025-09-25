#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

typedef ll F;
typedef complex<F> P;
F dot(P a, P b) {
	return (conj(a) * b).real();
}
F cross(P a, P b) {
	return (conj(a) * b).imag();
}
struct Cht {
	deque<P> hull, vecs;
	// Ascending gradient
	void add_line_back(F k, F b) {
		P nw = {k, b};
		while(!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0) 
			{ hull.pop_back(); vecs.pop_back(); }
		if(!hull.empty()) 
			vecs.push_back(P(0,1) * (nw - hull.back()));
		hull.push_back(nw);
	}
	// Descending gradient
	void add_line_front(F k, F b) {
		P nw = {k, b};
		while(!vecs.empty() && dot(vecs.front(),nw - hull.front()) < 0) 
			{ hull.pop_front(); vecs.pop_front(); }
		if(!hull.empty()) 
			vecs.push_front(P(0,1) * (hull.front() - nw));
		hull.push_front(nw);
	}
	F get(F x) {
		P query = {x, 1};
		auto it = lower_bound(vecs.begin(), vecs.end(), query, 
			[](P a, P b) { return cross(a, b) > 0; }
		);
		return dot(query, hull[it - vecs.begin()]);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	vector<pair<ll,ll>> points;

	REP(i,0,n) {
		ll a, b; cin >> a >> b;
		points.push_back({a,b});
	}
	sort(points.begin(), points.end());
	vector<pair<ll,ll>> fin;

	REP(i,0,n) {
		while (!fin.empty() and fin.back().second <= points[i].second) 
			fin.pop_back();
		fin.push_back(points[i]);
	}

	Cht cht;
	// Better sol
	ll ans = 0;
	REP(i,0,fin.size()) {
		cht.add_line_front(fin[i].second, ans);
		ans = cht.get(fin[i].first);
	}
	cout << ans;
}