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
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n; cin >> n;
	vector<ll> a(n), b(n);
	REP(i,0,n) cin >> a[i];
	REP(i,0,n) cin >> b[i];

	vector<vector<ll>> graph(n);
	vector<LineContainer*> lines(n, nullptr);

	REP(i,0,n-1) {
		ll a,b; cin >> a >> b;
		a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<ll> ans(n,0);

	auto dfs =[&](const auto& self, ll cur, ll par) -> LineContainer* {
		LineContainer* largest = nullptr;
		vector<LineContainer*> all;

		for(auto child : graph[cur]) {
			if (child == par) continue;
			LineContainer* nxt = self(self, child, cur);
			if (largest == nullptr || largest->size() < nxt->size() ) largest = nxt;
			all.push_back(nxt);
		}

		if (largest == nullptr) {
			largest = new LineContainer();
			ans[cur] = 0;
		} else {
			for(auto other : all) {
				if (other == largest) continue;
				for(auto line : *other) {
					largest->add(line.k,line.m);
				}
			}
			ans[cur] = -largest->query(a[cur]);
		}
		largest->add(-b[cur],-ans[cur]);
		return largest;
	};

	dfs(dfs,0,-1);
	// for (auto line : *dfs(dfs,0,-1)) {
	// 	cout << "A" << endl;
	// 	cout << line.k << " " << line.m << "\n";
	// }
	for(const auto a : ans) cout << a << " ";
}