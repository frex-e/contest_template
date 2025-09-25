#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	
	ll n,c; cin >> c >> n;
	vector<pair<int,int>> coins(n);

	ll l = 1;

	rep(i,0,n) {
		cin >> coins[i].first >> coins[i].second;
		l = lcm(l, coins[i].second);
	}

	vector<ll> final_coins(n);
	ll goal = c * l;


	rep(i,0,n) {
		final_coins[i] = coins[i].first * (l / coins[i].second);
		// cout << final_coins[i] << " ";
	}
	// cout << endl;



	// cout << goal << endl;
	vector<ll> dp(goal + 1, INT_MAX);
	dp[0] = 0;
	rep(i,1,goal + 1) {
		for(auto coin : final_coins) {
			if (i - coin >= 0 and dp[i - coin] != INT_MAX) 
				dp[i] = min(dp[i],dp[i - coin] + 1);
		}
	}

	if (dp[goal] == INT_MAX)
		cout << -1;
	else
		cout << dp[goal];
}
