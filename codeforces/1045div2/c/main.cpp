#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<ll> arr(n);
		rep(i,0,n) cin >> arr[i];

		ll ans = 0;

		for(ll i = 1; i < n - 1; i += 2) {
			// from right
			ll around = arr[i - 1] + arr[i + 1];
			ll above = max(around - arr[i], 0ll);
			ans += above;
			arr[i+1] = max(arr[i + 1] - above, 0ll);
		}

		if (n % 2 == 0) ans += max(0ll, arr[n - 2] - arr[n - 1]);
		cout << ans << '\n';
	}
}