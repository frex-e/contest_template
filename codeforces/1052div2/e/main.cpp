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

struct Update {
	bool reset; int add;

	
};

struct LazyUpdateTree {
	using Value = int;
	Value identity = INT_MIN;
	Value def = 0;
	Update idUpdate = {false,0};
	Value binop(Value a, Value b) { return max(a, b); }
	Value applyUpdate(Update u, Value v, int l, int r) { return (v * !u.reset) + u.add; }
	Update mergeUpdate(Update old, Update nw) { 
		if (nw.reset) return nw;
		else return {old.reset, old.add + nw.add};
	}
	vector<Value> arr;
	vector<Update> lazy;
	int size;
	LazyUpdateTree(int n) : arr(4 * n + 2, def), lazy(4 * n + 2, idUpdate), size(n) {};
    inline void updateNode(int cur, int l, int r, Update u) {
        lazy[cur] = mergeUpdate(lazy[cur], u);
        arr[cur] = applyUpdate(u, arr[cur], l, r);
    }
	void push(int cur, int l, int r) {
		if (l != r) {
			int mid = midpoint(l, r);
            updateNode(2*cur,l,mid,lazy[cur]);
            updateNode(2*cur+1,mid+1,r,lazy[cur]);
		}
		lazy[cur] = idUpdate;
	}
	void update(int cur, int ql, int qr, Update u, int l, int r) {
		if (l == ql and r == qr) {
            updateNode(cur,l,r,u);
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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		LazyUpdateTree tree(n + 1);

		rep(i,0,n) {
			int a; cin >> a;
			tree.update(0,a,{false,1});
			tree.update(a,a,{true,0});
			cout << tree.query(0,n) << " ";
		}
		cout << "\n";
	}
}