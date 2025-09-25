#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	vector<double> skill(n);
	vector<double> chance(n);
	vector<int> skip(n);

	rep(i,0,n) cin >> skill[i];
	rep(i,0,n) cin >> chance[i];
	rep(i,0,n) cin >> skip[i];

	vector<double> dp(n);

	for(int i = n - 1; i >= 0; i--) {
		dp[i] = chance[i] * skill[i] + ((i + skip[i] + 1 < n) ? (1 - chance[i])*dp[i + skip[i] + 1] : 0.);
		if (i != n - 1) dp[i] = max(dp[i], dp[i + 1]);
	}
	cout << fixed << setprecision(10) << dp[0];
}