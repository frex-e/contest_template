#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

ll pref[102][102];
ll dp[102][102];

signed main() {
	ll n; cin >> n;
	REP(i,0,n) REP(j,0,n) {
		cin >> pref[i + 1][j + 1];
	}
	REP(i,0,n) REP(j,0,n) {
		pref[i+1][j+1] += pref[i+1][j] + pref[i][j+1] - pref[i][j];
	}

	for(ll i = n; i >= 1; i--) for(ll j = n; j >= 1; j--) {
			if (i == n and j == n) continue;
			ll cur = __LONG_LONG_MAX__;
			
			if (j != n) {
				cur = dp[i][j+1] + pref[n][j] - pref[i][j];
			}
			if (i != n) {
				cur = min(cur,
					dp[i+1][j] + pref[i][n] - pref[i][j]
				);
			}

			dp[i][j] = cur;
		}

	cout << dp[1][1];
}