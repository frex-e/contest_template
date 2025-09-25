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

const ll MOD = 998244353ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		ll ans = 2ll;
		vector<int> a(n),b(n);

		rep(i,0,n) cin >> a[i];
		rep(i,0,n) cin >> b[i];

		rep(i,1,n) {
			if ( max(a[i-1],b[i-1]) <= min(a[i],b[i])) {
				ans = (ans * 2) % MOD;
			}
		}
		cout << ans << '\n';
	}
}