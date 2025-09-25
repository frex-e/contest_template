#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)


const pair<int,int> id = {INT_MAX, INT_MAX};
const pair<int,int> def = {0,0};
const pair<int,int> idUpdate = {0,0};

int midpoint(int l, int r) {
	return (l + r)/2;
}

struct LazyUpdateTree {
	using V = pair<int,int>;
	using U = pair<int,int>;
	V binop(V a, V b) {return min(a,b); }
	V applyUpdate(U u, V v, int l, int r) {return {v.first + u.first, v.second + u.second}; }
	U mergeUpdate(U old, U nw) {return {old.first + nw.first, old.second + nw.second};}
	vector<V> arr;
	vector<U> lazy;
	int size;
	LazyUpdateTree(int n) : arr(4*n + 2, def), lazy(4 * n + 2, idUpdate), size(n) {
		rep(i,0,n) {
			update(i,i,{0,i});
		}
	};
	void updateNode(int cur, int l, int r, U u) {
		lazy[cur] = mergeUpdate(lazy[cur], u);
		arr[cur] = applyUpdate(u, arr[cur], l, r);
	}
	void push(int cur, int l, int r) {
		if (l != r and lazy[cur] != idUpdate) {
			int mid = midpoint(l,r);
			updateNode(2*cur,l,mid,lazy[cur]);
			updateNode(2*cur+1,mid+1,r,lazy[cur]);
		}
		lazy[cur] = idUpdate;
	}
	void update(int cur, int ql, int qr, U u, int l, int r) {
		if (l == ql and r == qr) {
			updateNode(cur,l,r,u);
			return;
		}
		push(cur,l,r);
		int mid = midpoint(l,r);
		if (ql <= mid) update(2*cur, ql, min(mid,qr),u,l,mid);
		if (qr > mid) update(2*cur+1, max(mid+1,ql),qr,u,mid+1,r);
		arr[cur] = binop(arr[2*cur], arr[2*cur+1]);
	}
	void update(int ql, int qr, U u) { update(1,ql,qr,u,0,size-1); }
	V query(int cur, int ql, int qr, int l, int r) {
		if (l == ql and r == qr) return arr[cur];
		push(cur,l,r);
		int mid = midpoint(l,r);
		V val = id;
		if (ql <= mid) val = binop(val, query(2*cur, ql, min(mid,qr), l, mid));
		if (qr > mid) val = binop(val, query(2*cur + 1, max(mid+1,ql),qr,mid+1,r));
		return val;
	}
	V query(int ql, int qr) {return query(1,ql,qr,0,size-1);}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	vector<pair<int,int>> arr(n);

	LazyUpdateTree tree(n);

	rep(i,0,n) {
		int a,b; cin >> a >> b;
		a--;b--;
		arr[i] = {a,b};
	}

	bool works = true;
	pair<int,int> not_working_pair;

	// <-right, left, i>
	priority_queue<tuple<int,int,int>> q;

	rep(i,0,n) {
		while (!q.empty() and -get<0>(q.top()) < i) {
			auto [r,l,mid] = q.top();
			r *= -1; q.pop();
			tree.update(l,mid,{-1,0});
		}
		auto [l,r] = arr[i];
		tree.update(l,i,{1,0});
		auto temp = tree.query(0,i);
		// cout << l << " " << r << endl;
		// cout << temp.first << " " << temp.second << endl;
		if (temp.first <= 0) {
			works = false;
			not_working_pair = {tree.query(0,i).second, i};
		}
		q.push({-r,l,i});
		// for(auto a : tree.arr) {
			// cout << a.first << "," << a.second << " ";
		// }
		// cout << endl;
	}

	if (works) cout << "Yes";
	else {
		cout << "No " << not_working_pair.first + 1 << " " << not_working_pair.second + 1;
	}
}