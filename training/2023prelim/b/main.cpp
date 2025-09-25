#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

ll remove_cost_is[3001];
ll remove_cost_js[3001];
ll dp[3001][3001] = {};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll s,c,t; cin >> s >> c >> t;
	fill(remove_cost_is + 1, remove_cost_is + 3001, LLONG_MAX);
	fill(remove_cost_js + 1, remove_cost_js + 3001, LLONG_MAX);
	string a,b; cin >> a >> b;

	int n = a.size(), m = b.size();

	rep(i,0, n + 1) rep(j,0,m + 1) {
		if (i == 0 and j == 0) continue;
		ll cur = LLONG_MAX;

		// Transition
		if (i != 0 & j != 0) {
			cur = min(cur, dp[i - 1][j - 1] + t * (a[i - 1] != b[j - 1]));
		}
		// Cuts
		if (j != 0)
			cur = min(cur, s + remove_cost_is[i] + c * j);
		if (i != 0)
			cur = min(cur, s + remove_cost_js[j] + c * i);

		dp[i][j] = cur;
		remove_cost_is[i] = min(remove_cost_is[i], cur - j * c);
		remove_cost_js[j] = min(remove_cost_js[j], cur - i * c);
	}
	cout << dp[n][m];
}