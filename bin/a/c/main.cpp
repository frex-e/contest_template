#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

ll dp[5001][5001] = {};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n,m; cin >> n >> m;
		ll ans = 0;

		// i is the token to be removed
		vector<ll> dp0(n);
		REP(i,0,n) {
			dp0[i] = (i + 1)*(n - i) % m;
			ans += dp0[i];
			ans %= m;
			// cout << dp0[i] << " ";
		}
		// cout << endl;
		vector<ll> dp1(n);

		REP(i,1,n) {
			ll cumsum = 0;
			for(ll j = n - 1 - i + 1; j >= 0; j--) {
				dp1[j] = (j + 1)*max(n - j - i,0LL)*cumsum % m;
				ans += dp1[j];
				ans %= m;
				cumsum += dp0[j];
				cumsum %= m;
				// cout << dp1[j] << " ";
			}
			// cout << endl;
			swap(dp0,dp1);
		}
		cout << (ans + 1 + m) % m << '\n';
	}
}