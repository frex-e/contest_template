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
	Value identity = -1;
	Value binop(Value a, Value b) {return max(a, b);}
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
		int n,q; cin >> n >> q;
		vector<int> arr(n);

		rep(i,0,n) { 
			cin >> arr[i];
			arr[i]--;
		}

		BasicSegmentTree one(n), two(n), three(n);

		vector<int> bests(n);
		rep(i,0,n) {	
			three.update(arr[i],two.query(arr[i], n - 1));
			two.update(arr[i],one.query(arr[i], n - 1));
			one.update(arr[i],i);

			// cout << three.query(0,n - 1) << " ";
			bests[i] = three.query(0,n-1);
		}

		// cout << endl;

		rep(i,0,q) {
			int a,b; cin >> a >> b;
			a--;b--;
			if (bests[b] >= a) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}