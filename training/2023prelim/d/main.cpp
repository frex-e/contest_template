#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

ll MOD = 1e9 + 7;

unordered_map<int,ll> dp[27][27];
int grid[27][27];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m,k,s,f;
	cin >> n >> m >> k >> s >> f;

	rep(i,0,n) rep(j,0,m) {
		string s; cin >> s;
		if (s[0] == '-') continue;

		int cur_mask = 0;
		for(auto c : s) {
			cur_mask += 1 << (c - 'A');
		}

		grid[i][j] = cur_mask;
	}

	dp[0][s - 1][grid[0][s - 1]] = 1;
	dp[n-1][f-1][grid[n-1][f-1]] = 1;

	vector<int> deltas = {-1,0,1};

	int mid = n/2 - 1;

	rep(i,0,mid) rep(j,0,m) {
		for(auto [cur_mask, cnt] : dp[i][j]) {
			for(auto dj : deltas) {
				int nj = j + dj;
				if (nj < 0 | nj >= m) continue;
				if (cur_mask & grid[i + 1][nj]) continue;
				auto &nxt = dp[i+1][nj][cur_mask | grid[i + 1][nj]];
				nxt += cnt;
				nxt %= MOD;
			}
		}
	}

	for(int i = n - 1; i > mid + 1; i--) rep(j,0,m) {
		for(auto [cur_mask, cnt] : dp[i][j]) {
			for(auto dj : deltas) {
				int nj = j + dj;
				if (nj < 0 | nj >= m) continue;
				if (cur_mask & grid[i - 1][nj]) continue;
				auto &nxt = dp[i-1][nj][cur_mask | grid[i - 1][nj]];
				nxt += cnt;
				nxt %= MOD;
			}
		}
	}
	
	ll ans = 0;

	rep(j,0,m) {
		for(auto [cur_mask, cnt] : dp[mid][j]) {
			for(auto dj : deltas) {
				int nj = j + dj;
				if (nj < 0 | nj >= m) continue;
				// if (cur_mask & grid[mid + 1][nj]) continue;
				ans += cnt * dp[mid + 1][nj][((1 << k) - 1) ^ cur_mask];
				ans %= MOD;
			}
		}
	}
	cout << ans;
}