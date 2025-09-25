#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

struct Update {
	int add = 0, floor = 0;
};

struct LazyUpdateTree {
	using Value = int;
	Value identity = 0;
	Value def = 0;
	Update idUpdate = {0,0};
	Value binop(Value a, Value b) { return max(a, b); }
	Value applyUpdate(Update a, Value u, int l, int r) { return max(a.add + u, a.floor); }
	Update mergeUpdate(Update old, Update nw) { return {old.add + nw.add, max(old.floor + nw.add, nw.floor)}; }
	vector<Value> arr;
	vector<Update> lazy;
	int size;
	LazyUpdateTree(int n) : arr(4 * n + 2, def), lazy(4 * n + 2, idUpdate), size(n) {};
	void push(int cur, int l, int r) {
		if (l != r) {
			int mid = midpoint(l, r);
			update(2 * cur, l, mid,lazy[cur],l,mid);
			update(2 * cur + 1, mid + 1, r, lazy[cur],mid + 1, r);
		}
		lazy[cur] = idUpdate;
	}
	void update(int cur, int ql, int qr, Update u, int l, int r) {
		if (l == ql and r == qr) {
			lazy[cur] = mergeUpdate(lazy[cur], u);
			arr[cur] = applyUpdate(u, arr[cur], l, r);
			return;
		}
		push(cur, l, r);
		int mid = midpoint(l, r);
		if (ql <= mid) update(2 * cur, ql, min(mid, qr), u, l, mid);
		if (qr > mid) update(2 * cur + 1, max(mid + 1, ql), qr, u, mid + 1, r);
		arr[cur] = binop(arr[2 * cur], arr[2 * cur + 1]);
	}
	void update(int ql, int qr, Update u) { update(1, ql, qr, u, 0, size - 1); }
	Value query(int cur, int ql, int qr, int l, int r) {
		if (l == ql and r == qr) return arr[cur];
		push(cur, l, r);
		int mid = midpoint(l, r);
		Value val = identity;
		if (ql <= mid) val = binop(val, query(2 * cur, ql, min(mid, qr), l, mid));
		if (qr > mid) val = binop(val, query(2 * cur + 1, max(mid + 1, ql), qr, mid + 1, r));
		return val;
	}
	Value query(int ql, int qr) { return query(1, ql, qr, 0, size - 1); }
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		set<int> vals;
		vector<pair<int,int>> arr;
		REP(i,0,n) {
			int a,b; cin >> a >> b;
			arr.push_back({a,b});
			vals.insert({a});
			vals.insert({b});
		}	
		map<int,int> mp;
		int sz = 0;
		for(const auto a : vals) {
			mp[a] = sz++;
		}

		LazyUpdateTree tree(sz);
		REP(i,0,n) {
			int a = mp[arr[i].first];
			int b = mp[arr[i].second];
			tree.update(a,b,{1,0});
			if (b + 1 < sz)
				tree.update(b+1,sz - 1,{0,tree.query(a,b)});
			cout << tree.query(0,sz - 1) << " ";
		}
		cout << "\n";
	}
}