#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll a,b,k; cin >> a >> b >> k;
		ll g = gcd(a,b);
		a /= g;
		b /= g;
		if (a <= k and b <= k) cout << "1\n";
		else cout << "2\n";
	}
}