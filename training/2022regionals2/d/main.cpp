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
	map<ll,ll> point_inverse;
struct Tree {
	vector<pair<int,int>> intervals;
	vector<bool> used;
	static const int L = 0, R = 1e6 + 2;
	vector<vector<pair<int,int>>> arr;
	vector<pair<int,int>> best;
	Tree() {
		arr.assign((R - L + 1) * 4 + 2, {});
		best.assign((R - L + 1) * 4 + 2, {INT_MAX, INT_MAX});
	}
	
	void insertTree(int cur, int ql, int qr, int i, int l = L, int r = R) {
		if (ql <= l and qr >= r) {
			arr[cur].push_back({qr,i });
			return;
		}
		int mid = (l + r)/2;
		if (ql <= mid) insertTree(2*cur, ql, qr,i,l,mid);
		if (qr >= mid + 1) insertTree(2*cur + 1, ql, qr, i,mid + 1, r);
	}
	void insert(int l, int r) {
		insertTree(1, l, r, sz(used));
		used.pb(false);
		intervals.push_back({l,r});
	}
	void update(int cur, int l, int r) {
		best[cur] = {INT_MAX, INT_MAX};
		if (!arr[cur].empty()) 
			best[cur] = arr[cur].back();
		if (l != r)
			best[cur] = min({best[cur], best[cur*2], best[cur*2 + 1]});
	}
	void build(int cur = 1, int l = L, int r = R) {
		sort(all(arr[cur]));
		reverse(all(arr[cur]));
		if (!arr[cur].empty()) best[cur] = arr[cur].back();
		if (l == r) return;
		int mid = (l + r)/2;
		build(2*cur, l, mid);
		build(2*cur+ 1,mid + 1, r);
		update(cur, l, r);
	}
	void useTree(int cur, int ql, int qr, int l = L, int r = R) {
		if (ql == l and qr == r) {
			while(!arr[cur].empty() and used[arr[cur].back().second]) arr[cur].pop_back();
			update(cur,l,r);
			return;
		}
		int mid = (l + r)/2;
		if (ql <= mid) useTree(2*cur, ql, min(mid, qr),l,mid);
		if (qr >= mid + 1) useTree(2*cur + 1, max(mid + 1, ql), qr,mid + 1, r);
		update(cur,l,r);
		return;
	}
	void use(int i) {
		used[i] = true;
		useTree(1, intervals[i].first, intervals[i].second);
	}
	pair<int,int> query(int cur, int ql, int qr, int l = L, int r = R) {
		if (ql <= l and qr >= r) {
			return best[cur];
		}
		int mid = (l + r)/2;
		pii res = {INT_MAX, INT_MAX};
		if (!arr[cur].empty()) res = arr[cur].back();
		if (ql <= mid) res = min(res, query(2*cur, ql, qr, l, mid));
		if (qr >= mid + 1) res = min(res, query(2*cur + 1, ql, qr, mid + 1, r));
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
		point_inverse[ind - 1] = p;
	}

	vector<pair<ll,ll>> intervals;
	Tree tree;

	ind = 0;
	for(auto in : uncompressed) {
		ll l = point_map[in.first], r = point_map[in.sc];
		intervals.pb({l,r});
		tree.insert(l,r);
	}

	tree.build();
	//cout << tree.best[1].second + 1 << endl;
	vector<int> ans;
	ll l = -1, r = INT_MAX;
	while(true) {
		auto res = tree.query(1,l,r);
		ll i = res.second;
		if (i == INT_MAX) break;
		ans.push_back(i);
		l = intervals[i].first;
		r = intervals[i].second;
		// cout << i + 1 << " " << point_inverse[l] << " " << point_inverse[r] << endl;
		tree.use(i);
	}
	if (ans.size() == n) {
		cout << "YES\n";
		for(auto a : ans) cout << a + 1 << " ";
	} else {
		cout << "NO";
	}
}