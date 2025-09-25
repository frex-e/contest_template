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

struct BasicSegmentTree {
	using Value = ll;
	Value identity = INT_MAX;
	Value binop(Value a, Value b) {return min(a, b);}
	vector<Value> arr;
	int size;
	BasicSegmentTree(int n) : arr(4*n + 2,identity), size(n) {};
	void update(int cur, int i, Value v, int l, int r) {
		if (l == r) {arr[cur] = v; return; }
		int mid = midpoint(l, r);
		if (i <= mid) update(2*cur, i, v, l, mid);
		else update(2*cur + 1, i, v, mid + 1, r);
		arr[cur] = binop(arr[2*cur],arr[2*cur + 1]);
	}
	void update(int i, int v) {update(1,i,v,0,size - 1);}
	Value query(int cur, int ql, int qr, int l, int r) {
		if (l == ql and r == qr) return arr[cur];
		int mid = midpoint(l,r);
		Value val = identity;
		if (ql <= mid) val = binop(val, query(2*cur,ql,min(mid,qr),l,mid));
		if (qr > mid) val = binop(val,query(2*cur + 1,max(mid + 1,ql),qr,mid+1,r));
		return val;
	}
	Value query(int ql, int qr) {return query(1,ql,qr,0,size - 1);}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	while(t--) {
		ll k,x;
		cin >> k >> x;
		
		ll b = (1 << (k + 1)) - x;
		ll a = x;

		// if (a == x) {
		// 	cout << 0 << "\n\n";
		// 	continue;
		// }

		vector<int> ans;

		ll cur = a >> (__builtin_ctzll(a) + 1);

		rep(i,0,k - (__builtin_ctzll(a))) {
			ans.pb(cur & 1);
			cur >>=1;
		}

		cout << sz(ans) << '\n';
		for(auto x : ans) cout << (x + 1) << ' ';
		cout << '\n';
	}
}