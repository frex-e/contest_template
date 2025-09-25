#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll t; cin >> t;
	while(t--) {
		ll n,m,k; cin >> n >> m >> k;
		k--;

		vector<vector<ll>> pref(n + 1, vector<ll>(m + 1,0));
		vector<vector<bool>> free(n + 1, vector<bool>(m + 1, false));

		ll total_g = 0;

		REP(i,0,n) {
			REP(j,0,m) {
				char a; cin >> a;
				if (a == 'g') { 
					pref[i + 1][j + 1] = 1;
					total_g++;
				}
				if (a == '.') free[i + 1][j + 1] = true;
			}
		}

		// cout << "A" << endl;
		REP(i,1,n+1) {
			REP(j,1,m+1) {
				pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			}
		}
		// cout << "B" << endl;

		ll ans = 0;
		REP(i,1,n+1) {
			REP(j,1,m+1) {
				if (!free[i][j]) continue;

				ll bot = min(n, i + k);
				ll right = min(m, j + k);
				ll top = max(0LL, i - k - 1);
				ll left = max(0LL, j - k - 1);
				ll cur = pref[bot][right] - pref[bot][left] - pref[top][right] + pref[top][left];
				ans = max(ans, total_g - cur);
			}
		}
		cout << ans << "\n";
	}
}