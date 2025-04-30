#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007ll;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;

	vector<int> dp(n), dp2(n);

	int ans = 0;

	dp[0] = 1;

	int k = 2;
	// int min_next = 0;

	bool update = true;

	while (true) {
		// if (min_next == INT_MAX) break;
		// int min_next_next = INT_MAX;
		if (!update) break;
		update = false;

		for(int i = 0 ; i < n; i++) {
			if (s[i] == '#') continue;
			if (dp[i] == 0) continue;

			if (i + 1 >= n)  {ans += dp[i]; ans %= MOD;}
			else {dp[i+1] += dp[i]; dp[i+1] %= MOD;}

			int nxt = i + k;

			if (nxt >= n)  {ans += dp[i]; ans %= MOD;}
			else {
				dp2[nxt] += dp[i]; 
				// min_next_next = min(min_next_next, nxt);
				update = true;
				dp2[nxt] %= MOD;
			}
		}

		swap(dp,dp2);
		dp2.resize(n,0);
		// min_next = min_next_next;
		k += 1;
	}

	cout << ans;
}


