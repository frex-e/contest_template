#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007ll;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;

	int root_n = 1;
	while ((root_n * (root_n - 1))/2 < n) root_n++;
	root_n += 10;

	// dp[n][k]
	vector<vector<int> > dp(n, vector<int>(root_n + 1,0));

	dp[0][0] = 1;
	int ans = 0;

	for(int i = 0; i < n; i++) for(int k = 0; k < root_n; k++) {
		if (s[i] == '#') continue;

		int cur = dp[i][k];
		if (i + 1 >= n) {ans += cur; ans %= MOD;}
		else {dp[i+1][k] += cur; dp[i+1][k] %= MOD;}

		int nxt = i + k + 2;
		if (nxt >= n) {ans += cur; ans %= MOD;}
		else {dp[nxt][k+1] += cur; dp[nxt][k+1] %= MOD; }
	}

	cout << ans;
}


