#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)


const ll k = 1e9;
// const ll k = 5;
signed main() {
	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		vector<pair<ll,ll>> arr;

		ll max_up_line = LLONG_MIN;
		ll max_down_line = LLONG_MIN;

		rep(i,0,n) {
			ll x,y; cin >> x >> y;
			arr.push_back({x,y});
			max_down_line = max(x + y, max_down_line);
			max_up_line = max(y - x, max_up_line);
		}

		ll res;
		cout << "? R " << k << endl;
		cin >> res;
		cout << "? R " << k << endl;
		cin >> res;
		cout << "? U " << k << endl;
		cin >> res;
		cout << "? U " << k << endl;
		cin >> res;

		ll down_line = res + max_down_line - 4*k;

		rep(i,0,4) {
			cout << "? L " << k << endl;
			cin >> res;
		}

		ll up_line = res + max_up_line - 4*k;

		ll a = up_line;
		ll b = down_line;
		assert((a + b) % 2 == 0);
		ll y = (a+b)/2;
		ll x = (b - a)/2;
		cout << "! " << x << " " << y << endl;
	}
}