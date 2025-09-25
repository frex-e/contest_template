#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector<ll> arr(n);
		REP(i,0,n) {
			cin >> arr[i];
		}
		ll ans = n*(n+1)/2;
		REP(i,1,n) {
			if (arr[i - 1] > arr[i]) ans += i * (n - i);
			// else if (i > 1) ans += (i - 1)*(n - i);
		}
		cout << ans << "\n";
	}
}