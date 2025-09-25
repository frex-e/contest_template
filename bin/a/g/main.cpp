#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll t; cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;

		vector<ll> arr(n);

		REP(i,0,n) cin >> arr[i];

		ll l = 0, r = 1e9;
		while (l != r) {
			ll above = (l + r)/2;
			ll below = above - k;
			ll sum_above = 0, sum_below = 0;

			for(const auto a : arr) {
				sum_above += max(0LL, a - above);
				sum_below += max(0LL, below - a);
			}
			if (sum_above <= sum_below) r = above;
			else l = above + 1;
		}
		// cout << l << "\n";

		ll above = l;
		ll below1 = above - k;
		ll sum_above = 0, at_above = 0, sum_below = 0, at_below = 0;
		ll ans = 0;
		ll moves = 0;
		for(const auto a : arr) {
			moves += max(0LL, below1 - a);
			sum_above += max(0LL, a - above);
			sum_below += max(0LL, below1 - a);
			at_above += a >= above;
			at_below += a <= below1;
			ll b = min(max(a, below1), above - 1);
			ans += (b*(b+1))/2;
		}

		// cout << sum_above << " " << at_above <<  " " << sum_below << " " << at_below << " " << moves << " " << ans << "\n";

		// Test case
		if (sum_above >= sum_below) {
			// cout << "AAA" << endl;
			ll delta = sum_above - sum_below;
			moves += delta;
			ans += above * at_above;
			ans += (below1 + 1)*delta;
		} else {
			ans += (at_above - (sum_below - sum_above)) * above;
		}
		cout << ans + k * moves << "\n";
	}
}