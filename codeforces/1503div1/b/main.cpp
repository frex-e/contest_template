#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n = 7;

const ll MOD = 998244353;

ll euclid(ll a, ll b, ll &x, ll &y) {
if (!b) return x = 1, y = 0, a;
ll d = euclid(b, a % b, y, x);
return y -= a/b * x, d;
}


ll invert(ll a) {
ll x, y, g = euclid(a, MOD, x, y);
assert(g == 1); return ((x + MOD) % MOD);
}

const ll MAXN = 2e5 + 20;
vector<ll> factorials;

ll choose(ll n, ll c) {
	return (factorials[n] * invert((factorials[n - c] * factorials[c]) % MOD) ) % MOD;
}


signed main() {
	factorials.assign(MAXN,0);
	factorials[0] = 1;

	rep(i,1,MAXN) factorials[i] = (i * factorials[i - 1]) % MOD;

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		bool failed = true;
		vector<ll> arr(n);
		ll total = 0;
		ll ans = 1;

		rep(i,0,n) {
			cin >> arr[i];
			total += arr[i];
			if (i >= (n+1)/2 and arr[i] != 0) ans = 0;
		}
		if (total != n) ans = 0;

		int cur = (n + 1)/2  - 1;
		ll available;
		if (n % 2 == 0) available = 2;
		else available = 1;

		while(cur >= 0) {
			if (arr[cur] > available) ans = 0;
			else {
				ans *= choose(available, arr[cur]);
				ans %= MOD;
				available -= arr[cur];
			}

			available += 2;
			cur--;
		}
		cout << ans << "\n";
	}
}
