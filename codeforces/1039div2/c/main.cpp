#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		bool ans = true;
		ll mn = INT_MAX;
		REP(i,0,n) {
			ll a; cin >> a;
			if (a > mn + mn - 1) ans = false;
			mn = min(mn,a);
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}