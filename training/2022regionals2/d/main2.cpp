#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	Tree* lt = nullptr, *rt = nullptr;
	// {right, index}
	set<pair<ll,ll>> cur;

	Tree() {}
	void populate() {
		if (lt != nullptr) return;
		lt = new Tree();
		rt = new Tree();
	}
	void edit(bool insert, ll ql, ll qr, ll i, ll l, ll r) {
		if (insert) cur.insert({qr, i});
		else cur.erase({qr, i});
		if (l == r) return;
		populate();
		ll mid = (l + r)/2;
		if (ql <= mid) lt->edit(insert,ql,qr,i,l,mid);
		else rt->edit(insert,ql,qr,i,mid + 1, r); 
	};
	pair<ll,ll> query(ll ql, ll qr, ll l, ll r) {
///		pair<ll,ll> res = *cur.lower_bound({ql, -1});
		if (r <= qr) {
			auto it = cur.lower_bound({ql, -1ll});
			if (it != cur.end()) return *it;
			else return {LLONG_MAX, LLONG_MAX};
		}
		
		pair<ll,ll> res = {LLONG_MAX, LLONG_MAX};
		ll mid = (l + r)/2;
		if (lt != nullptr) res = min(res, lt->query(ql,qr,l,mid));
		if (mid + 1 <= qr and rt != nullptr) res = min(res, rt->query(ql,qr,mid + 1, r));
		return res; 
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	// compress
	vector<pair<ll,ll>> uncompressed;
	set<ll> points;
	rep(i,0,n) {
		int a,b; cin >> a >> b;
		uncompressed.pb({a,b});
		points.insert(a);
		points.insert(b);
	}
	int ind = 0;
	map<ll,ll> point_map;
	for(auto p : points) {
		point_map[p] = ind++;
	}

	ll L = 0;
	ll R = ind;

	vector<pair<ll,ll>> intervals;
	Tree tree;

	ind = 0;
	for(auto in : uncompressed) {
		ll l = point_map[in.first], r = point_map[in.sc];
		intervals.pb({l,r});
		tree.edit(true, l,r,ind++, L, R);
	}
	
	vector<int> ans;
	ll l = -1, r = ind + 1;
	while(true) {
		auto res = tree.query(l,r,L,R);
		ll i = res.second;
		if (i == LLONG_MAX) break;
		ans.push_back(i);
		l = intervals[i].first;
		r = intervals[i].second;
		// cout << i + 1 << " " << l << " " << r << endl;
		tree.edit(false,l,r,i,L,R );
	}
	if (ans.size() == n) {
		cout << "YES\n";
		for(auto a : ans) cout << a + 1 << " ";
	} else {
		cout << "NO";
	}
}