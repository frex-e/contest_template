#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	ll val = 0;
	Node* lt = nullptr, *rt = nullptr;

	Node(int l, int r) {
		if (l == r) return;
		int mid = (l + r)/2;
		lt = new Node(l,mid);
		rt = new Node(mid + 1,r);
	};
	ll query(int ql, int qr, int l, int r) {
		if (ql == l and qr == r) return val;
		ll res = 0;
		int mid = (l + r)/2;
		if (ql <= mid) res = max(res, lt->query(ql, min(mid, qr),l, mid));
		if (qr > mid) res = max(res, rt->query(max(mid + 1, ql), qr, mid + 1, r));
		return res;
	}
	void update(int i, ll v, int l, int r) {
		if (l == r) { val = max(val, v); return; }
		int mid = (l + r)/2;
		if (i <= mid) lt->update(i,v,l,mid);
		else rt->update(i,v,mid+1,r);
		val = max(lt->val, rt->val);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	vector<ll> intervals;
	set<pair<ll,ll>> lefts;

	rep(size,0,n) {
		int l,r;
		cin >> l >> r;
		intervals.pb(l);
		lefts.insert({l,r});
	}

	int size = 0;
	map<ll,int> ltoi;
	vector<ll> sizes;
	for(auto [l, r] : lefts) {
		ltoi[l] = size++;
		sizes.pb(r - l + 1);
	}

	vector<ll> arr;
	for(auto l : intervals) arr.pb(ltoi[l]);
	// for(auto l : arr) cout << l << ' ' << sizes[l] << '\n';

	Node tree(0, size - 1);
	for(auto l : arr) {
		if (l == 0) tree.update(0,sizes[0],0,size - 1);
		else tree.update(l,tree.query(0,l-1,0,size-1) + sizes[l],0,size - 1);
	}
	cout << tree.query(0, size - 1,0,size - 1);
}