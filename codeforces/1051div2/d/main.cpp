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

const ll MOD = 1e9 + 7;
struct Tree {
	using V = ll;
	V identity = 0;
	V binop(V a, V b){ return (a + b) % MOD;}
	vector<V> arr;
	int size;
	Tree(int n) : arr(4*n + 2, identity), size(n) { }
	void update(int cur, int i, V v, int l, int r) {
		if (l == r) {arr[cur] = (arr[cur] + v) % MOD; return; }
		int mid = (l+r)/2;
		if (i <= mid) update(2*cur,i,v,l,mid);
		else update(2*cur + 1, i,v,mid + 1, r);
		arr[cur] = binop(arr[2*cur],arr[2*cur+1]);
	}
	ll query(int cur, int ql, int qr, int l, int r) {
		if (ql == l and qr == r) return arr[cur];
		int mid = (l + r)/2;
		V v = identity;
		if (ql <= mid) v = binop(v, query(2*cur,ql,min(mid,qr),l,mid));
		if (qr > mid) v = binop(v, query(2*cur+1,max(mid + 1, ql),qr,mid+1,r));
		return v;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		vector<ll> arr(n);

		rep(i,0,n) { cin >> arr[i]; }
		vector<Tree> dp(n + 1, Tree(n + 1));


		// Index, highest
		vector<Tree> sums(n + 1, Tree(n+1));

		dp[0].update(1,0,1ll,0,n);
		sums[0].update(1,0,1ll,0,n);

		// Index
		rep(i,0,n) {
			ll cur = arr[i];

			//  c
			rep(highest, cur + 1, n + 1) {
				ll inc = dp[highest].query(1,0,cur,0,n);
				dp[highest].update(1,cur,inc,0,n);
				sums[cur].update(1,highest,inc,0,n);
			}

			rep(j,0,cur) {
				ll inc = sums[j].query(1,0,cur,0,n);
				dp[cur].update(1,j,inc,0,n);
				sums[j].update(1,cur,inc,0,n);
			}

			// Highest
			// cout << "i - " << i << endl;
			// rep(j,0,n + 1) {
			// 	cout << "Highest " << j << " - ";
			// 	rep(k,0,n + 1) cout << dp[j].query(1,k,k,0,n) << " ";
			// 	cout << endl;
			// }
		}

		ll ans = 0;
		rep(i,0,n + 1) {
			ans += dp[i].query(1,0,n,0,n);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}