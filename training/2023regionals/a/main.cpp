#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll n,k; cin >> n >> k;

	vector<ll> arr(n);
	rep(i,0,n) {
		cin >> arr[i];
	}
	reverse(arr.begin(),arr.end());
	// false = "A"
	bool turn = false;
	rep(i,0,n) {
		if (i % 2 == 0) {
			if (arr[i] % (k + 1) == 0) {
				continue;
			} else if (arr[i] % (k + 1) == 1) {
				turn = !turn;
			} else {
				if (turn) cout << "Bertha";
				else cout << "Aaron";
				return 0;
			}
		} else {
			continue;
		}
	}
	if (turn) cout << "Aaron";
	else cout << "Bertha";
}