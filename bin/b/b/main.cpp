#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		k *= -1;
		m *= -1;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return -(l.k * x + l.m);
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n; cin >> n;
	vector<ll> a(n), b(n);
	ll total = 0;
	REP(i,0,n) { 
		cin >> a[i];
		total += a[i];
	}
	REP(i,0,n) cin >> b[i];

	ll final_cost = b[n-1];
	LineContainer lines;
	lines.add(b[0], b[0] - final_cost);

	ll cst;
	REP(i,1,n) {
		cst = lines.query(a[i] - 1);
		lines.add(b[i], cst + b[i] - a[i]*final_cost);
	}

	cout << cst + total * final_cost - final_cost;
}