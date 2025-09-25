#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

const int n = 200010;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll p; cin >> p;
	vector<ll> upper(n, INT_MAX), lower(n, INT_MIN);

	ll maxx = 0;

	rep(i,0,p) {
		char c; ll x, y;
		cin >> c >> x >> y;
		if (c == 'U') upper[x] = min(upper[x], (ll) y);
		else lower[x] = max(lower[x], (ll) y);
		maxx = max(maxx, x);
	}

	for(ll i = n - 2; i >= 0; i--) {
		upper[i] = min(upper[i], upper[i + 1] + 1);
		lower[i] = max(lower[i], lower[i + 1] - 1);
	}

	string ans;
	ll cur = 0;
	rep(x,0,maxx + 1) {
		if (cur + 1 < upper[x + 1] and cur + 1 > lower[x + 1]) {
			cur+= 1;
			ans.push_back('+');
		} else if (cur - 1 < upper[x + 1] and cur - 1 > lower[x + 1]) {
			cur -= 1;
			ans.push_back('-');
		} else {
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible\n";
	cout << ans;
}