#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		ll ans = 0;
		REP(i,0,n) {
			ll a,b,c,d; cin >> a >> b >> c >> d;

			if (c > a) ans += c - a;
			if (b > d) ans += min(a,c) + (b - d);
		}
		cout << ans << "\n";
	}
}